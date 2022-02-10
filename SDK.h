//GetModuleA Import
#include "Module/ModuleGrab.h"

//Defines
#include "Defines.h"

//Vector3 Import
#include "Vector3.h"

//LI_FN khash Import
#include "HandleKhash/[Importer].h"

//skCrypt Import
#include "Protection/[CustomXor].h"

//Imgui Imports
#include "Imgui/imgui.h"
#include "Imgui/imgui_impl_dx11.h"
#include "Imgui/imgui_internal.h"

//DirectX11 Import
#include <D3D11.h>

//std::vector Import
#include <vector>

//std::search Import
#include <algorithm>

#define RelativeAddress(addr, size) ((uintptr_t)((UINT_PTR)(addr) + *(PINT)((UINT_PTR)(addr) + ((size) - sizeof(INT))) + (size)))
#define M_PI	3.14159265358979323846264338327950288419716939937510
#define _CRT_SECURE_NO_WARNINGS

float FOVAngle;

uintptr_t UWorld;
uintptr_t Gobject;
uintptr_t BoneMatrix;
uintptr_t FreeFn;
uintptr_t ProjectWorldToScreen;
uintptr_t LineOfSight;
uintptr_t GetNameByIndex;
uintptr_t ModuleBaseW;

Vector3 CamLoc;
Vector3 CamRot;

//namespace signatures {
//	const char* Gobject_Sig = "48 8B 05 ? ? ? ? 48 8B 0C C8 48 8B 04 D1";
//}

//GObjects* objects = nullptr;
//
//template<class T>
//struct TArray
//{
//	friend class FString;
//
//public:
//	inline TArray()
//	{
//		Data = NULL;
//		Count = Max = 0;
//	};
//
//	inline INT Num() const
//	{
//		return Count;
//	};
//
//	inline T& operator[](int i)
//	{
//		return Data[i];
//	};
//
//	inline T& operator[](int i) const
//	{
//		return Data[i];
//	};
//
//	inline BOOL IsValidIndex(int i) const
//	{
//		return i < Num();
//	}
//
//private:
//	T* Data;
//	INT32 Count;
//	INT32 Max;
//};

//class FString : private TArray<wchar_t>
//{
//public:
//	inline FString() {
//
//	};
//
//	inline int Count() {
//		return Num();
//	}
//
//	inline bool IsValid() {
//		return Data != NULL;
//	}
//
//	inline const wchar_t* data() const {
//		return Data;
//	}
//
//	inline const char* c_str() const {
//		return std::string(Data, &Data[wcslen(Data)]).c_str();
//	}
//};

namespace detail
{
	extern "C" void* _spoofer_stub();

	template <typename Ret, typename... Args>
	static inline auto shellcode_stub_helper(
		const void* shell,
		Args... args
	) -> Ret
	{
		auto fn = (Ret(*)(Args...))(shell);
		return fn(args...);
	}

	template <std::size_t Argc, typename>
	struct argument_remapper
	{
		template<
			typename Ret,
			typename First,
			typename Second,
			typename Third,
			typename Fourth,
			typename... Pack
		>
			static auto do_call(const void* shell, void* shell_param, First first, Second second,
				Third third, Fourth fourth, Pack... pack) -> Ret
		{
			return shellcode_stub_helper< Ret, First, Second, Third, Fourth, void*, void*, Pack... >(shell, first, second, third, fourth, shell_param, nullptr, pack...);
		}
	};

	template <std::size_t Argc>
	struct argument_remapper<Argc, std::enable_if_t<Argc <= 4>>
	{
		template<
			typename Ret,
			typename First = void*,
			typename Second = void*,
			typename Third = void*,
			typename Fourth = void*
		>
			static auto do_call(
				const void* shell,
				void* shell_param,
				First first = First{},
				Second second = Second{},
				Third third = Third{},
				Fourth fourth = Fourth{}
			) -> Ret
		{
			return shellcode_stub_helper<
				Ret,
				First,
				Second,
				Third,
				Fourth,
				void*,
				void*
			>(
				shell,
				first,
				second,
				third,
				fourth,
				shell_param,
				nullptr
				);
		}
	};
}

template <typename Ret, typename... Args>
static inline auto SpoofCall(Ret(*fn)(Args...), Args... args) -> Ret
{
	wchar_t* moduleName = NULL;
	static const void* jmprbx = nullptr;
	if (!jmprbx) {
		const auto ntdll = reinterpret_cast<const unsigned char*>(::GetModuleW(moduleName));
		const auto dos = reinterpret_cast<const IMAGE_DOS_HEADER*>(ntdll);
		const auto nt = reinterpret_cast<const IMAGE_NT_HEADERS*>(ntdll + dos->e_lfanew);
		const auto sections = IMAGE_FIRST_SECTION(nt);
		const auto num_sections = nt->FileHeader.NumberOfSections;

		constexpr char section_name[5]{ '.', 't', 'e', 'x', 't' };
		const auto     section = std::find_if(sections, sections + num_sections, [&](const auto& s) {
			return std::equal(s.Name, s.Name + 5, section_name);
			});

		constexpr unsigned char instr_bytes[2]{ 0xFF, 0x26 };
		const auto              va = ntdll + section->VirtualAddress;
		jmprbx = std::search(va, va + section->Misc.VirtualSize, instr_bytes, instr_bytes + 2);
	}

	struct shell_params
	{
		const void* trampoline;
		void* function;
		void* rdx;
	};

	shell_params p
	{
		jmprbx,
		reinterpret_cast<void*>(fn)
	};

	using mapper = detail::argument_remapper<sizeof...(Args), void>;
	return mapper::template do_call<Ret, Args...>((const void*)&detail::_spoofer_stub, &p, args...);
}

template <typename Ret, typename... Args>
static inline auto spoof_call(
	const void* trampoline,
	Ret(*fn)(Args...),
	Args... args
) -> Ret
{
	struct shell_params
	{
		const void* trampoline;
		void* function;
		void* rdx;
	};

	shell_params p{ trampoline, reinterpret_cast<void*>(fn) };
	using mapper = detail::argument_remapper<sizeof...(Args), void>;
	return mapper::template do_call<Ret, Args...>((const void*)&detail::_spoofer_stub, &p, args...);
}

/*
inline const void* ModuleSpoof(wchar_t* moduleName)
{
	static const void* jmprbx = nullptr;
	if (!jmprbx) {
		const auto ntdll = reinterpret_cast<const unsigned char*>(::GetModuleW(moduleName));
		const auto dos = reinterpret_cast<const IMAGE_DOS_HEADER*>(ntdll);
		const auto nt = reinterpret_cast<const IMAGE_NT_HEADERS*>(ntdll + dos->e_lfanew);
		const auto sections = IMAGE_FIRST_SECTION(nt);
		const auto num_sections = nt->FileHeader.NumberOfSections;
		constexpr char section_name[5]{ '.', 't', 'e', 'x', 't' };
		const auto     section = std::find_if(sections, sections + num_sections, [&](const auto& s) {
			return std::equal(s.Name, s.Name + 5, section_name);
			});

		constexpr unsigned char instr_bytes[2]{ 0xFF, 0x26 };
		const auto              va = ntdll + section->VirtualAddress;
		jmprbx = std::search(va, va + section->Misc.VirtualSize, instr_bytes, instr_bytes + 2);
	}
	return jmprbx;
}*/

int strlenf_(const char* string)
{
	int cnt = 0;
	if (string)
	{
		for (; *string != 0; ++string) ++cnt;
	}
	return cnt;
}

uintptr_t PatternScan_Module(uintptr_t moduleAdress, const char* signature)
{
	static auto patternToByte = [](const char* pattern)
	{
		auto bytes = std::vector<int>{};
		const auto start = const_cast<char*>(pattern);
		const auto end = const_cast<char*>(pattern) + strlenf_(pattern);

		for (auto current = start; current < end; ++current)
		{
			if (*current == '?')
			{
				++current;
				if (*current == '?')
					++current;
				bytes.push_back(-1);
			}
			else { bytes.push_back(strtoul(current, &current, 16)); }
		}
		return bytes;
	};

	const auto dosHeader = (PIMAGE_DOS_HEADER)moduleAdress;
	const auto ntHeaders = (PIMAGE_NT_HEADERS)((std::uint8_t*)moduleAdress + dosHeader->e_lfanew);

	const auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
	auto       patternBytes = patternToByte(signature);
	const auto scanBytes = reinterpret_cast<std::uint8_t*>(moduleAdress);

	const auto s = patternBytes.size();
	const auto d = patternBytes.data();

	for (auto i = 0ul; i < sizeOfImage - s; ++i)
	{
		bool found = true;
		for (auto j = 0ul; j < s; ++j)
		{
			if (scanBytes[i + j] != d[j] && d[j] != -1)
			{
				found = false;
				break;
			}
		}
		if (found) { return reinterpret_cast<uintptr_t>(&scanBytes[i]); }
	}
	return NULL;
}

namespace SpoofRuntime {

	float sqrt_(float _X) {
		return (LI_FN(_mm_cvtss_f32).safe_cached()(LI_FN(_mm_sqrt_ss).safe_cached()(LI_FN(_mm_set_ss).safe_cached()(_X))));
	}

	inline float sqrtf_(float number)
	{
		float temp, mysqrt;
		mysqrt = number / 2;
		temp = 0;
		while (mysqrt != temp) {
			temp = mysqrt;
			mysqrt = (number / temp + temp) / 2;
		}
		return mysqrt;
	}

	float expf_(float _X) {
		return (LI_FN(_mm_cvtss_f32).safe_cached()(LI_FN(_mm_exp_ps).safe_cached()(LI_FN(_mm_set_ss).safe_cached()(_X))));
	}

	float sinf_(float _X) {
		return (LI_FN(_mm_cvtss_f32).safe_cached()(LI_FN(_mm_sin_ps).safe_cached()(LI_FN(_mm_set_ss).safe_cached()(_X))));
	}

	float cosf_(float _X) {
		return (LI_FN(_mm_cvtss_f32).safe_cached()(LI_FN(_mm_cos_ps).safe_cached()(LI_FN(_mm_set_ss).safe_cached()(_X))));
	}

	float tanf_(float _X) {
		return (LI_FN(_mm_cvtss_f32).safe_cached()(LI_FN(_mm_tan_ps).safe_cached()(LI_FN(_mm_set_ss).safe_cached()(_X))));
	}

	float asinf_(float _X) {
		return (LI_FN(_mm_cvtss_f32).safe_cached()(LI_FN(_mm_asin_ps).safe_cached()(LI_FN(_mm_set_ss).safe_cached()(_X))));
	}

	float atan2f_(float _X, float _Y) {
		return (LI_FN(_mm_cvtss_f32).safe_cached()(LI_FN(_mm_atan2_ps).safe_cached()(LI_FN(_mm_set_ss).safe_cached()(_X), LI_FN(_mm_set_ss).safe_cached()(_Y))));
	}

	float acosf_(float _X) {
		return (LI_FN(_mm_cvtss_f32).safe_cached()(LI_FN(_mm_acos_ps).safe_cached()(LI_FN(_mm_set_ss).safe_cached()(_X))));
	}

	double powf_(double x, int y)
	{
		double temp;
		if (y == 0)
			return 1;
		temp = powf_(x, y / 2);
		if ((y % 2) == 0) {
			return temp * temp;
		}
		else {
			if (y > 0)
				return x * temp * temp;
			else
				return (temp * temp) / x;
		}
	}
}

BOOL valid_pointer(DWORD64 address)
{
	if (!SpoofCall(IsBadWritePtr, (LPVOID)address, (UINT_PTR)8))
		return TRUE;
	else
		return FALSE;
}

bool valid_Vector3(Vector3 vec3)
{
	return !(vec3.x == 0 && vec3.y == 0 && vec3.z == 0);
}

template<typename ReadT>
ReadT read(DWORD_PTR address, const ReadT& def = ReadT())
{
	if (valid_pointer(address)) {
		return *(ReadT*)(address);
	}
}

template<typename WriteT>
bool write(DWORD_PTR address, WriteT value, const WriteT& def = WriteT())
{
	if (valid_pointer(address)) {
		*(WriteT*)(address) = value;
		return true;
	}
	return false;
}

uintptr_t PlayerController;
uintptr_t LocalPawn;

#define get_array_size(array)    (sizeof(array) / sizeof(array[0]))
int random_int(int min, int max)
{
	int range = max - min;
	static bool seed = false;
	if (!seed)
	{
		srand((unsigned int)time(0));
		seed = true;
	}
	return rand() % range + min;
}

float distance(int x1, int y1, int x2, int y2)
{
	return (int)SpoofRuntime::sqrtf_((int)SpoofRuntime::powf_(x2 - x1, 2) +
		(int)SpoofRuntime::powf_(y2 - y1, 2) * 1.0);
}

class UClassA {
public:
	BYTE _padding_0[0x40];
	UClassA* SuperClass;
};

class UObjectA {
public:
	PVOID VTableObject;
	DWORD ObjectFlags;
	DWORD InternalIndex;
	UClassA* Class;
	BYTE _padding_0[0x8];
	UObjectA* Outer;
	/*
	inline void ProcessEvent(void* fn, void* parms)
	{
		auto vtable = *reinterpret_cast<void***>(this);
		auto processEventFn = static_cast<void(*)(void*, void*, void*)>(vtable[0x44]);
		processEventFn(this, fn, parms);
	}
	*/
	inline BOOLEAN IsA(PVOID parentClass) {
		for (auto super = this->Class; super; super = super->SuperClass) {
			if (super == parentClass) {
				return TRUE;
			}
		}

		return FALSE;
	}
};

namespace SDK
{
	namespace Structs
	{
		struct FMatrix
		{
			float M[4][4];
		};
		static FMatrix* myMatrix = new FMatrix();

		struct FVector
		{
			float                                              X;                                                        // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
			float                                              Y;                                                        // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
			float                                              Z;                                                        // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)

			inline FVector()
				: X(0), Y(0), Z(0)
			{ }

			inline FVector(float x, float y, float z)
				: X(x),
				Y(y),
				Z(z)
			{ }

			__forceinline FVector operator-(const FVector& V) {
				return FVector(X - V.X, Y - V.Y, Z - V.Z);
			}

			__forceinline FVector operator+(const FVector& V) {
				return FVector(X + V.X, Y + V.Y, Z + V.Z);
			}

			__forceinline FVector operator*(float Scale) const {
				return FVector(X * Scale, Y * Scale, Z * Scale);
			}

			__forceinline FVector operator/(float Scale) const {
				const float RScale = 1.f / Scale;
				return FVector(X * RScale, Y * RScale, Z * RScale);
			}

			__forceinline FVector operator+(float A) const {
				return FVector(X + A, Y + A, Z + A);
			}

			__forceinline FVector operator-(float A) const {
				return FVector(X - A, Y - A, Z - A);
			}

			__forceinline FVector operator*(const FVector& V) const {
				return FVector(X * V.X, Y * V.Y, Z * V.Z);
			}

			__forceinline FVector operator/(const FVector& V) const {
				return FVector(X / V.X, Y / V.Y, Z / V.Z);
			}

			__forceinline float operator|(const FVector& V) const {
				return X * V.X + Y * V.Y + Z * V.Z;
			}

			__forceinline float operator^(const FVector& V) const {
				return X * V.Y - Y * V.X - Z * V.Z;
			}

			__forceinline FVector& operator+=(const FVector& v) {
				(*this);
				(v);
				X += v.X;
				Y += v.Y;
				Z += v.Z;
				return *this;
			}

			__forceinline FVector& operator-=(const FVector& v) {
				(*this);
				(v);
				X -= v.X;
				Y -= v.Y;
				Z -= v.Z;
				return *this;
			}

			__forceinline FVector& operator*=(const FVector& v) {
				(*this);
				(v);
				X *= v.X;
				Y *= v.Y;
				Z *= v.Z;
				return *this;
			}

			__forceinline FVector& operator/=(const FVector& v) {
				(*this);
				(v);
				X /= v.X;
				Y /= v.Y;
				Z /= v.Z;
				return *this;
			}

			__forceinline bool operator==(const FVector& src) const {
				(src);
				(*this);
				return (src.X == X) && (src.Y == Y) && (src.Z == Z);
			}

			__forceinline bool operator!=(const FVector& src) const {
				(src);
				(*this);
				return (src.X != X) || (src.Y != Y) || (src.Z != Z);
			}

			__forceinline float Size() const {
				return SpoofRuntime::sqrtf_(X * X + Y * Y + Z * Z);
			}

			__forceinline float Size2D() const {
				return SpoofRuntime::sqrtf_(X * X + Y * Y);
			}

			__forceinline float SizeSquared() const {
				return X * X + Y * Y + Z * Z;
			}

			__forceinline float SizeSquared2D() const {
				return X * X + Y * Y;
			}

			__forceinline float Dot(const FVector& vOther) const {
				const FVector& a = *this;

				return (a.X * vOther.X + a.Y * vOther.Y + a.Z * vOther.Z);
			}

			__forceinline float DistanceFrom(const FVector& Other) const {
				const FVector& a = *this;
				float dx = (a.X - Other.X);
				float dy = (a.Y - Other.Y);
				float dz = (a.Z - Other.Z);

				return (SpoofRuntime::sqrtf_((dx * dx) + (dy * dy) + (dz * dz)));
			}

			__forceinline FVector Normalize() {
				FVector vector;
				float length = this->Size();

				if (length != 0) {
					vector.X = X / length;
					vector.Y = Y / length;
					vector.Z = Z / length;
				}
				else
					vector.X = vector.Y = 0.0f;
				vector.Z = 1.0f;

				return vector;
			}

		};

		struct FVector2D
		{
			FVector2D() : x(0.f), y(0.f)
			{

			}

			FVector2D(float _x, float _y) : x(_x), y(_y)
			{

			}
			~FVector2D()
			{

			}
			float x, y;
		};

		template<class T>
		struct TArray
		{
			friend struct FString;

		public:
			inline TArray()
			{
				Data = nullptr;
				Count = Max = 0;
			};

			inline int Num() const
			{
				return Count;
			};

			inline T& operator[](int i)
			{
				return Data[i];
			};

			inline const T& operator[](int i) const
			{
				return Data[i];
			};

			inline bool IsValidIndex(int i) const
			{
				return i < Num();
			}

		private:
			T* Data;
			int32_t Count;
			int32_t Max;
		};

		class FText {
		private:
			char _padding_[0x28];
			PWCHAR Name;
			DWORD Length;
		public:


			inline PWCHAR c_wstr() {
				return Name;
			}

			inline char* c_str()
			{

				char sBuff[255];
				wcstombs((char*)sBuff, (const wchar_t*)this->Name, sizeof(sBuff));
				return sBuff;
			}
		};

		struct FString : private TArray<wchar_t>
		{
			inline FString()
			{
			};

			FString(const wchar_t* other)
			{
				Max = Count = *other ? std::wcslen(other) + 1 : 0;

				if (Count)
				{
					Data = const_cast<wchar_t*>(other);
				}
			};

			inline bool IsValid() const
			{
				return Data != nullptr;
			}

			inline const wchar_t* c_str() const
			{
				return Data;
			}

			std::string ToString() const
			{
				auto length = std::wcslen(Data);

				std::string str(length, '\0');

				std::use_facet<std::ctype<wchar_t>>(std::locale()).narrow(Data, Data + length, '?', &str[0]);

				return str;
			}
		};
	}

	//Functions
	//typedef bool(__fastcall* WorldToScreen_t)(std::uint64_t PlayerController, Vector3 vWorldPos, Vector3* vScreenPos, char);
	//WorldToScreen_t fnWorldToScreen;


	class FUObjectItem {
	public:
		UObjectA* Object;
		DWORD Flags;
		DWORD ClusterIndex;
		DWORD SerialNumber;
		DWORD SerialNumber2;
	};

	class TUObjectArray {
	public:
		FUObjectItem* Objects[9];
	};

	class GObjects {
	public:
		TUObjectArray* ObjectArray;
		BYTE _padding_0[0xC];
		DWORD ObjectCount;
	};

	GObjects* objects = nullptr;

	namespace Classes
	{
		class APlayerCameraManager
		{
		public:
			static float GetFOVAngle(uintptr_t PlayerCameraManager)
			{
				auto GetFOVAngle = reinterpret_cast<float(*)(UINT64, char*)>(*(ULONG_PTR*)(*(ULONG_PTR*)PlayerCameraManager + 0x740));
				return SpoofCall(GetFOVAngle, (ULONG_PTR)PlayerCameraManager, (char*)0);
			}

			static Vector3 GetCameraLocation(uintptr_t PlayerCameraManager)
			{
				auto GetCameraLocation = reinterpret_cast<Vector3(*)(UINT64, char*)>(*(ULONG_PTR*)(*(ULONG_PTR*)PlayerCameraManager + 0x788));
				return SpoofCall(GetCameraLocation, (ULONG_PTR)PlayerCameraManager, (char*)0);
			}

			static Vector3 GetCameraRotation(uintptr_t PlayerCameraManager)
			{
				auto GetCameraRotation = reinterpret_cast<Vector3(*)(UINT64, char*)>(*(ULONG_PTR*)(*(ULONG_PTR*)PlayerCameraManager + 0x780));
				return SpoofCall(GetCameraRotation, (ULONG_PTR)PlayerCameraManager, (char*)0);
			}


			static BOOLEAN LineOfSightTo(PVOID PlayerController, PVOID Actor, Vector3* ViewPoint) {
				auto LOSTo = reinterpret_cast<bool(__fastcall*)(PVOID PlayerController, PVOID Actor, Vector3 * ViewPoint)>(LineOfSight);
				return SpoofCall(LOSTo, PlayerController, Actor, ViewPoint);
			}

			//static void FirstPerson(int h) {

			//	auto ClientSetCameraMode = (*(void(__fastcall**)(uintptr_t Controller, int h))(*(uintptr_t*)PlayerController + 0x9B0));
			//	return SpoofCall(ClientSetCameraMode, (uintptr_t)PlayerController, h);
			//}

			static bool GetPlayerViewPoint(uintptr_t PlayerController, Vector3* vCameraPos, Vector3* vCameraRot)
			{
				if (!PlayerController) return false;

				static uintptr_t pGetPlayerViewPoint = 0;
				if (!pGetPlayerViewPoint)
				{
					uintptr_t VTable = *(uintptr_t*)PlayerController;
					if (!VTable)  return false;

					pGetPlayerViewPoint = *(uintptr_t*)(VTable + 0x788);
					if (!pGetPlayerViewPoint)  return false;
				}

				auto GetPlayerViewPoint = reinterpret_cast<void(__fastcall*)(uintptr_t, Vector3*, Vector3*)>(pGetPlayerViewPoint);

				SpoofCall(GetPlayerViewPoint, (uintptr_t)PlayerController, vCameraPos, vCameraRot);

				return true;
			}

			static void FreeObjectName(__int64 address) {
				auto func = reinterpret_cast<__int64(__fastcall*)(__int64 a1)>(FreeFn);
				SpoofCall(func, address);
			}

			static const char* GetUintObjectName(uintptr_t Object)
			{
				if (Object == NULL) return "";

				auto fGetObjName = reinterpret_cast<Structs::FString * (__fastcall*)(int* index, Structs::FString * res)>(GetNameByIndex);

				int index = *(int*)(Object + 0x18);

				Structs::FString result;
				SpoofCall(fGetObjName, &index, &result);

				if (result.c_str() == NULL) return "";

				auto result_str = result.ToString();

				if (result.c_str() != NULL)
					FreeObjectName((__int64)result.c_str());

				return result_str.c_str();
			}

			static const char* GetUObjectName(uintptr_t* Object)
			{
				if (Object == NULL) return "";

				auto fGetObjName = reinterpret_cast<Structs::FString * (__fastcall*)(int* index, Structs::FString * res)>(GetNameByIndex);

				int index = *(int*)(reinterpret_cast<uint64_t>(Object) + 0x18);

				Structs::FString result;
				SpoofCall(fGetObjName, &index, &result);

				if (result.c_str() == NULL) return "";

				auto result_str = result.ToString();

				if (result.c_str() != NULL)
					FreeObjectName((__int64)result.c_str());

				return result_str.c_str();
			}


			static const char* GetUObjectNameLoop(UObjectA* Object) {
				std::string name("");
				for (auto i = 0; Object; Object = Object->Outer, ++i) {

					auto fGetObjName = reinterpret_cast<Structs::FString * (__fastcall*)(int* index, Structs::FString * res)>(GetNameByIndex);
					int index = *(int*)(reinterpret_cast<uint64_t>(Object) + 0x18);

					Structs::FString fObjectName;
					SpoofCall(fGetObjName, &index, &fObjectName);

					if (!fObjectName.IsValid()) {
						break;
					}

					auto objectName = fObjectName.ToString();

					name = objectName + std::string(i > 0 ? "." : "") + name;
					FreeObjectName((uintptr_t)fObjectName.c_str());
				}

				return name.c_str();
			}
		};

		class USkeletalMeshComponent
		{
		public:
			static bool GetBoneLocation(uintptr_t CurrentActor, int id, Vector3* out)
			{
				uintptr_t mesh = read<uintptr_t>(CurrentActor + Offsets::Mesh);
				if (!mesh) return false;

				auto fGetBoneMatrix = ((Structs::FMatrix * (__fastcall*)(uintptr_t, Structs::FMatrix*, int))(BoneMatrix));
				SpoofCall(fGetBoneMatrix, mesh, Structs::myMatrix, id);

				out->x = Structs::myMatrix->M[3][0];
				out->y = Structs::myMatrix->M[3][1];
				out->z = Structs::myMatrix->M[3][2];

				return true;
			}

			static Vector3 GetBoneDebug(uintptr_t CurrentActor, int id)
			{
				uintptr_t mesh = read<uintptr_t>(CurrentActor + Offsets::Mesh);
				if (!mesh) return Vector3(0, 0, 0);

				auto fGetBoneMatrix = ((Structs::FMatrix * (__fastcall*)(uintptr_t, Structs::FMatrix*, int))(BoneMatrix));
				SpoofCall(fGetBoneMatrix, mesh, Structs::myMatrix, id);

				Vector3 out;

				out.x = Structs::myMatrix->M[3][0];
				out.y = Structs::myMatrix->M[3][1];
				out.z = Structs::myMatrix->M[3][2];

				return out;
			}

		};



		class AController
		{
		public:
			static bool WorldToScreen(Vector3 WorldLocation, Vector3* out)
			{
				auto WorldToScreen = reinterpret_cast<bool(__fastcall*)(uintptr_t pPlayerController, Vector3 vWorldPos, Vector3 * vScreenPosOut, char)>(ProjectWorldToScreen);
				SpoofCall(WorldToScreen, (uintptr_t)PlayerController, WorldLocation, out, (char)0);
				return true;
			}

			static bool WorldToScreenA(SDK::Structs::FVector WorldLocation, SDK::Structs::FVector* out)
			{
				auto WorldToScreen = reinterpret_cast<bool(__fastcall*)(uintptr_t pPlayerController, SDK::Structs::FVector vWorldPos, SDK::Structs::FVector * vScreenPosOut, char)>(ProjectWorldToScreen);
				SpoofCall(WorldToScreen, (uintptr_t)PlayerController, WorldLocation, out, (char)0);
				return true;
			}

			static void SetControlRotation(Vector3 NewRotation, bool bResetCamera = false)
			{
				auto SetControlRotation_ = (*(void(__fastcall**)(uintptr_t Controller, Vector3 NewRotation, bool bResetCamera))(*(uintptr_t*)PlayerController + 0x6F8));
				SpoofCall(SetControlRotation_, PlayerController, NewRotation, bResetCamera);
			}
		};
	}

	namespace Utils
	{
		double GetCrossDistance(double x1, double y1, double x2, double y2)
		{
			return SpoofRuntime::sqrtf_(SpoofRuntime::powf_((float)(x1 - x2), (float)2) + SpoofRuntime::powf_((float)(y1 - y2), (float)2));
		}

		inline float GetDistLength(Vector3 from, Vector3 to)
		{
			return float(SpoofRuntime::sqrtf_(SpoofRuntime::powf_(to.x - from.x, 2.0) + SpoofRuntime::powf_(to.y - from.y, 2.0) + SpoofRuntime::powf_(to.z - from.z, 2.0)));
		}

		Vector3 AimbotPrediction(float bulletVelocity, float bulletGravity, float targetDistance, Vector3 targetPosition, Vector3 targetVelocity) {
			Vector3 recalculated = targetPosition;
			float gravity = fabs(bulletGravity);
			float time = targetDistance / fabs(bulletVelocity);
			float bulletDrop = (gravity / 250) * time * time;
			recalculated.z += bulletDrop * 120;
			recalculated.x += time * (targetVelocity.x);
			recalculated.y += time * (targetVelocity.y);
			recalculated.z += time * (targetVelocity.z);
			return recalculated;
		}

		bool CheckInScreen(uintptr_t CurrentActor, int Width, int Height) {
			Vector3 Pos;
			Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 98, &Pos);
			Classes::AController::WorldToScreen(Pos, &Pos);
			if (CurrentActor)
			{
				if (((Pos.x <= 0 or Pos.x > Width) and (Pos.y <= 0 or Pos.y > Height)) or ((Pos.x <= 0 or Pos.x > Width) or (Pos.y <= 0 or Pos.y > Height))) {
					return false;
				}
				else {
					return true;
				}

			}
		}

		bool CheckItemInScreen(uintptr_t CurrentActor, int Width, int Height) {
			Vector3 Pos;
			uintptr_t RootComponent = read<uintptr_t>(CurrentActor + Offsets::RootComponent);
			Vector3 RelativeLocation = read<Vector3>(RootComponent + Offsets::RelativeLocation);
			Classes::AController::WorldToScreen(RelativeLocation, &Pos);
			if (CurrentActor)
			{
				if (((Pos.x <= 0 or Pos.x > Width) and (Pos.y <= 0 or Pos.y > Height)) or ((Pos.x <= 0 or Pos.x > Width) or (Pos.y <= 0 or Pos.y > Height))) {
					return false;
				}
				else {
					return true;
				}

			}
		}

		bool CheckIfInFOV(uintptr_t CurrentActor, float& max)
		{
			Vector3 Pos;
			Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, Settings::aimbone, &Pos);
			Classes::AController::WorldToScreen(Pos, &Pos);
			if (CurrentActor)
			{
				float Dist = GetCrossDistance(Pos.x, Pos.y, (Renderer_Defines::Width / 2), (Renderer_Defines::Height / 2));

				if (Dist < max)
				{
					float Radius = (Settings::FovCircle_Value * Renderer_Defines::Width / FOVAngle) / 2;

					if (Pos.x <= ((Renderer_Defines::Width / 2) + Radius) &&
						Pos.x >= ((Renderer_Defines::Width / 2) - Radius) &&
						Pos.y <= ((Renderer_Defines::Height / 2) + Radius) &&
						Pos.y >= ((Renderer_Defines::Height / 2) - Radius))
					{
						max = Dist;
						return true;
					}
					return false;
				}
			}

			return false;
		}

		Vector3 CalculateNewRotation(uintptr_t CurrentActor, Vector3 LocalRelativeLocation, bool prediction)
		{
			Vector3 RetVector = { 0,0,0 };

			Vector3 rootHead;
			Vector3 Headbox;
			Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, Settings::aimbone, &rootHead);
			Classes::AController::WorldToScreen(Vector3(rootHead.x, rootHead.y, rootHead.z + 20), &Headbox);

			Vector3 calculated;
			if (prediction) {
				float distance = Utils::GetDistLength(LocalRelativeLocation, Headbox) / 250;
				uint64_t CurrentActorRootComponent = read<uint64_t>(CurrentActor + 0x130);
				Vector3 vellocity = read<Vector3>(CurrentActorRootComponent + 0x140);
				Vector3 Predicted = Utils::AimbotPrediction(30000, -504, distance, rootHead, vellocity);

				calculated = Predicted;
			}
			else {
				calculated = rootHead;
			}

			if (calculated.x == 0 && calculated.y == 0) return Vector3(0, 0, 0);

			Vector3 VectorPos = calculated - CamLoc;

			float distance = VectorPos.Length();

			RetVector.x = -((SpoofRuntime::acosf_(VectorPos.z / distance) * (float)(180.0f / M_PI)) - 90.f);
			RetVector.y = SpoofRuntime::atan2f_(VectorPos.y, VectorPos.x) * (float)(180.0f / M_PI);

			return RetVector;
		}

		Vector3 SmoothAngles(Vector3 rot1, Vector3 rot2)
		{
			Vector3 ret;
			auto currentRotation = rot1;

			ret.x = (rot2.x - rot1.x) / Settings::smooth + rot1.x;
			ret.y = (rot2.y - rot1.y) / Settings::smooth + rot1.y;

			return ret;
		}
	}
}



bool GetPlayerViewPoint(uintptr_t PlayerController, Vector3* vCameraPos, Vector3* vCameraRot)
{
	if (!PlayerController) return false;

	static uintptr_t pGetPlayerViewPoint = 0;
	if (!pGetPlayerViewPoint)
	{
		uintptr_t VTable = *(uintptr_t*)PlayerController;
		if (!VTable)  return false;

		pGetPlayerViewPoint = *(uintptr_t*)(VTable + 0x788);
		if (!pGetPlayerViewPoint)  return false;
	}

	auto GetPlayerViewPoint = reinterpret_cast<void(__fastcall*)(uintptr_t, Vector3*, Vector3*)>(pGetPlayerViewPoint);

	SpoofCall(GetPlayerViewPoint, (uintptr_t)PlayerController, vCameraPos, vCameraRot);

	return true;
}

uintptr_t GetCurrentState(uintptr_t base)
{
	static uintptr_t returnval = 0;

	returnval = read<uintptr_t>(base + 0x238);//state

	return returnval;
}

bool GetClosestPlayerToCrossHair(Vector3 Pos, float& max, float aimfov)
{
	float Dist = SDK::Utils::GetCrossDistance(Pos.x, Pos.y, (Renderer_Defines::Width / 2), (Renderer_Defines::Height / 2));
	if (Dist < max)
	{
		max = Dist;
		Settings::FovCircle_Value = aimfov;
		return true;
	}
	return false;
}

bool SpinbotInFov(uintptr_t CurrentPawn, int FovValue) {
	Vector3 HeadPos; SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentPawn, Settings::aimbone, &HeadPos); SDK::Classes::AController::WorldToScreen(HeadPos, &HeadPos);
	auto dx = HeadPos.x - (Renderer_Defines::Width / 2);
	auto dy = HeadPos.y - (Renderer_Defines::Height / 2);
	auto dz = HeadPos.z - (Renderer_Defines::Length / 2);
	auto dist = SpoofRuntime::sqrtf_(dx * dx + dy * dy + dz * dz);

	if (dist < FovValue) {
		return true;
	}
	else {
		return false;
	}
}

bool InFov(uintptr_t CurrentPawn, int FovValue) {
	Vector3 HeadPos; SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentPawn, Settings::aimbone, &HeadPos); SDK::Classes::AController::WorldToScreen(HeadPos, &HeadPos);
	auto dx = HeadPos.x - (Renderer_Defines::Width / 2);
	auto dy = HeadPos.y - (Renderer_Defines::Height / 2);
	auto dist = SpoofRuntime::sqrtf_(dx * dx + dy * dy);

	if (dist < FovValue) {
		return true;
	}
	else {
		return false;
	}
}

namespace HookHelper {

	void* memcpy_(void* _Dst, void const* _Src, size_t _Size)
	{
		auto csrc = (char*)_Src;
		auto cdest = (char*)_Dst;

		for (int i = 0; i < _Size; i++)
		{
			cdest[i] = csrc[i];
		}
		return _Dst;
	}

	uintptr_t DiscordModule = (uintptr_t)GetModuleA(skCrypt("DiscordHook64.dll"));
	std::vector<uintptr_t> pCreatedHooksArray;
	bool CreateHook(uintptr_t pOriginal, uintptr_t pHookedFunction, uintptr_t pOriginalCall)
	{
		static uintptr_t addrCreateHook = NULL;

		if (!addrCreateHook)
			addrCreateHook = PatternScan_Module(DiscordModule, skCrypt("41 57 41 56 56 57 55 53 48 83 EC 68 4D 89 C6 49 89 D7"));

		if (!addrCreateHook)
			return false;

		using CreateHook_t = uint64_t(__fastcall*)(LPVOID, LPVOID, LPVOID*);
		auto fnCreateHook = (CreateHook_t)addrCreateHook;

		return SpoofCall(fnCreateHook, (void*)pOriginal, (void*)pHookedFunction, (void**)pOriginalCall) == 0 ? true : false;
	}

	bool EnableHookQue()
	{
		static uintptr_t addrEnableHookQueu = NULL;

		if (!addrEnableHookQueu)
			addrEnableHookQueu = PatternScan_Module(DiscordModule, skCrypt("41 57 41 56 41 55 41 54 56 57 55 53 48 83 EC 38 48 ? ? ? ? ? ? 48 31 E0 48 89 44 24 30 BE 01 00 00 00 31 C0 F0 ? ? ? ? ? ? ? 74 2B"));

		if (!addrEnableHookQueu)
			return false;

		using EnableHookQueu_t = uint64_t(__stdcall*)(VOID);
		auto fnEnableHookQueu = (EnableHookQueu_t)addrEnableHookQueu;

		return SpoofCall(fnEnableHookQueu) == 0 ? true : false;
	}


	bool EnableHook(uintptr_t pTarget, bool bIsEnabled)
	{
		static uintptr_t addrEnableHook = NULL;

		if (!addrEnableHook)
			addrEnableHook = PatternScan_Module(DiscordModule, skCrypt("41 56 56 57 53 48 83 EC 28 49 89 CE BF 01 00 00 00 31 C0 F0 ? ? ? ? ? ? ? 74"));

		if (!addrEnableHook)
			return false;

		using EnableHook_t = uint64_t(__fastcall*)(LPVOID, bool);
		auto fnEnableHook = (EnableHook_t)addrEnableHook;

		return SpoofCall(fnEnableHook, (void*)pTarget, bIsEnabled) == 0 ? true : false;
	}

	bool InsertHook(uintptr_t pOriginal, uintptr_t pHookedFunction, uintptr_t pOriginalCall)
	{
		bool bAlreadyCreated = false;
		for (auto _Hook : pCreatedHooksArray)
		{
			if (_Hook == pOriginal)
			{
				bAlreadyCreated = true;
				break;
			}
		}

		if (!bAlreadyCreated)
			bAlreadyCreated = CreateHook(pOriginal, pHookedFunction, pOriginalCall);

		if (bAlreadyCreated)
			if (EnableHook(pOriginal, true))
				if (EnableHookQue())
					return true;

		return false;
	}


}

char* wchar_to_char(const wchar_t* pwchar)
{
	int currentCharIndex = 0;
	char currentChar = pwchar[currentCharIndex];

	while (currentChar != '\0')
	{
		currentCharIndex++;
		currentChar = pwchar[currentCharIndex];
	}

	const int charCount = currentCharIndex + 1;

	char* filePathC = (char*)malloc(sizeof(char) * charCount);

	for (int i = 0; i < charCount; i++)
	{
		char character = pwchar[i];

		*filePathC = character;

		filePathC += sizeof(char);

	}
	filePathC += '\0';

	filePathC -= (sizeof(char) * charCount);

	return filePathC;
}

ImDrawList* Overlay = ImGui::GetOverlayDrawList();

void draw2dboundingbox(Vector3 StartBoxLoc, float flWidth, float Height, ImColor color)
{

	StartBoxLoc.x = StartBoxLoc.x - (flWidth / 2);

	//black outlines
	Overlay->AddLine(ImVec2(StartBoxLoc.x, StartBoxLoc.y), ImVec2(StartBoxLoc.x + flWidth, StartBoxLoc.y), ImColor(0, 0, 0, 255), 3); //bottom
	Overlay->AddLine(ImVec2(StartBoxLoc.x, StartBoxLoc.y), ImVec2(StartBoxLoc.x, StartBoxLoc.y + Height), ImColor(0, 0, 0, 255), 3); //left
	Overlay->AddLine(ImVec2(StartBoxLoc.x + flWidth, StartBoxLoc.y), ImVec2(StartBoxLoc.x + flWidth, StartBoxLoc.y + Height), ImColor(0, 0, 0, 255), 3); //right
	Overlay->AddLine(ImVec2(StartBoxLoc.x, StartBoxLoc.y + Height), ImVec2(StartBoxLoc.x + flWidth, StartBoxLoc.y + Height), ImColor(0, 0, 0, 255), 3); //up

	//2d boxes
	Overlay->AddLine(ImVec2(StartBoxLoc.x, StartBoxLoc.y), ImVec2(StartBoxLoc.x + flWidth, StartBoxLoc.y), color, 1); //bottom
	Overlay->AddLine(ImVec2(StartBoxLoc.x, StartBoxLoc.y), ImVec2(StartBoxLoc.x, StartBoxLoc.y + Height), color, 1); //left
	Overlay->AddLine(ImVec2(StartBoxLoc.x + flWidth, StartBoxLoc.y), ImVec2(StartBoxLoc.x + flWidth, StartBoxLoc.y + Height), color, 1); //right
	Overlay->AddLine(ImVec2(StartBoxLoc.x, StartBoxLoc.y + Height), ImVec2(StartBoxLoc.x + flWidth, StartBoxLoc.y + Height), color, 1); //up
}

void drawcornerboxESP(int X, int Y, int W, int H, ImColor color, int thickness) {

	float lineW = (W / 2.9);
	float lineH = (H / 3.3);

	//corners
	Overlay->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImColor(color), thickness);
	Overlay->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImColor(color), thickness);
	Overlay->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImColor(color), thickness);
	Overlay->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImColor(color), thickness);
	Overlay->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImColor(color), thickness);
	Overlay->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImColor(color), thickness);
	Overlay->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImColor(color), thickness);
	Overlay->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImColor(color), thickness);
}

//right fingers
//Vector3 hand_r, index_metacarpal_r, index_01_r, index_02_r, index_03_r, middle_metacarpal_r, middle_01_r, middle_02_r, middle_03_r, pinky_metacarpal_r, pinky_01_r, pinky_02_r, pinky_03_r, ring_metacarpal_r, ring_01_r, ring_02_r, ring_03_r, thumb_01_r, thumb_02_r, thumb_03_r;
//left fingers
//Vector3 hand_l, index_metacarpal_l, index_01_l, index_02_l, index_03_l, middle_metacarpal_l, middle_01_l, middle_02_l, middle_03_l, pinky_metacarpal_l, pinky_01_l, pinky_02_l, pinky_03_l, ring_metacarpal_l, ring_01_l, ring_02_l, ring_03_l, thumb_01_l, thumb_02_l, thumb_03_l;
//bones
Vector3 head2, fuckbattleeyenigger, pelvis, fuckbattleeye, leftShoulder, rightShoulder, leftElbow, rightElbow, leftHand, rightHand, leftLeg, rightLeg, leftThigh, rightThigh, leftFoot, rightFoot, leftFeet, rightFeet, leftFeetFinger, rightFeetFinger;

bool fgytfrytdrfyddsbgfiubsdfibgusfdbu(uintptr_t CurrentActor)
{ //getbonesofLowre
	Vector3 chesti, chestatright;

	//bones
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 98, &head2);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 66, &fuckbattleeyenigger);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 2, &pelvis);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 37, &chesti);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 8, &chestatright);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 93, &leftShoulder);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 9, &rightShoulder);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 94, &leftElbow);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 10, &rightElbow);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 100, &leftHand);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 99, &rightHand);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 76, &leftLeg);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 69, &rightLeg);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 82, &leftThigh);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 75, &rightThigh);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 78, &leftFoot);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 71, &rightFoot);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 85, &leftFeet);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 84, &rightFeet);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 81, &leftFeetFinger);
	SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 74, &rightFeetFinger);

	//bones w2s
	SDK::Classes::AController::WorldToScreen(head2, &head2);
	SDK::Classes::AController::WorldToScreen(fuckbattleeyenigger, &fuckbattleeyenigger);
	SDK::Classes::AController::WorldToScreen(pelvis, &pelvis);
	SDK::Classes::AController::WorldToScreen(chesti, &chesti);
	SDK::Classes::AController::WorldToScreen(chestatright, &chestatright);
	SDK::Classes::AController::WorldToScreen(leftShoulder, &leftShoulder);
	SDK::Classes::AController::WorldToScreen(rightShoulder, &rightShoulder);
	SDK::Classes::AController::WorldToScreen(leftElbow, &leftElbow);
	SDK::Classes::AController::WorldToScreen(rightElbow, &rightElbow);
	SDK::Classes::AController::WorldToScreen(leftHand, &leftHand);
	SDK::Classes::AController::WorldToScreen(rightHand, &rightHand);
	SDK::Classes::AController::WorldToScreen(leftLeg, &leftLeg);
	SDK::Classes::AController::WorldToScreen(rightLeg, &rightLeg);
	SDK::Classes::AController::WorldToScreen(leftThigh, &leftThigh);
	SDK::Classes::AController::WorldToScreen(rightThigh, &rightThigh);
	SDK::Classes::AController::WorldToScreen(leftFoot, &leftFoot);
	SDK::Classes::AController::WorldToScreen(rightFoot, &rightFoot);
	SDK::Classes::AController::WorldToScreen(leftFeet, &leftFeet);
	SDK::Classes::AController::WorldToScreen(rightFeet, &rightFeet);
	SDK::Classes::AController::WorldToScreen(leftFeetFinger, &leftFeetFinger);
	SDK::Classes::AController::WorldToScreen(rightFeetFinger, &rightFeetFinger);

	fuckbattleeye.x = chesti.x + ((chestatright.x - chesti.x) / 2);
	fuckbattleeye.y = chesti.y;

	return true;
}

const char* strcpyf_(char* buffer, const char* string) {
	char* ret = buffer;
	while (*string) *buffer++ = *string++;
	*buffer = 0;
	return ret;
}


#define ReadBYTE(base, offset) (*(((PBYTE)base + offset)))

PVOID(*GetWeaponStats)(PVOID) = nullptr;

float ScreenCenterX;
float ScreenCenterY;

class UClass {
public:
	BYTE _padding_0[0x40];
	UClass* SuperClass;
};

class UObject {
public:
	PVOID VTableObject;
	DWORD ObjectFlags;
	DWORD InternalIndex;
	UClass* Class;
	BYTE _padding_0[0x8];
	UObject* Outer;

	inline BOOLEAN IsA(PVOID parentClass) {
		for (auto super = this->Class; super; super = super->SuperClass) {
			if (super == parentClass) {
				return TRUE;
			}
		}

		return FALSE;
	}
};

class FUObjectItem {
public:
	UObject* Object;
	DWORD Flags;
	DWORD ClusterIndex;
	DWORD SerialNumber;
	DWORD SerialNumber2;
};

class FText {
private:
	char _padding_[0x28];
	PWCHAR Name;
	DWORD Length;

public:
	inline PWCHAR c_str() {
		return Name;
	}
};

typedef struct {
	float X, Y, Z;
} FVector;

typedef struct {
	float X, Y;
} FVector2D;

typedef struct {
	float Pitch;
	float Yaw;
	float Roll;
} FRotator;


PVOID TargetPawn = nullptr;
bool ShowMenu = true;

namespace GetFOV {
	bool InitA(bool FOV);
	bool FOVInitialized = false;
}

namespace GetVehicle {
	bool InitB(bool GetVehicle, bool K2_TPT);
	bool GetVehicleInitialized = false;
	bool K2_TeleportToInitialized = false;
}

namespace SetPawnVis {
	bool InitC(bool SetPawnVisA);
	bool SetPawnVisInitialized = false;
}

//namespace GFetPlayerNames {
//	bool InitD(bool GetPlayerNamesA);
//	bool PlayerNamesInitialized = false;
//}
//
namespace HookFunctions {
	bool Init(bool NoSpread, bool CalcShot);
	bool NoSpreadInitialized = false;
	bool CalcShotInitialized = false;
}

ImColor GetColByTier(BYTE tier)
{
	switch (tier)
	{
	case 1:
		return ImColor(255, 255, 255);
	case 2:
		return ImColor(0, 255, 0);
	case 3:
		return ImColor(0, 0, 255);
	case 4:
		return ImColor(200, 66, 245);
	case 5:
		return ImColor(255, 153, 0);
	case 6:
	case 7:
		return ImColor(255, 234, 0);
	case 8:
	case 9:
		return ImColor(200, 0, 0);
	case 10:
		return ImColor(255, 255, 255);
	default:
		return ImColor(255, 255, 255);
	}
}