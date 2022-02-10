//#include "stdafx.h"
/*
#include <Windows.h>
#include <psapi.h>
//#include "xor.h"
//#include "Spoof.h"
#include "[CustomXor].h"
#include <rpcndr.h>
//#include "Basic.h"
#include <string>
#include <locale>
#define E(str) xorstr_(str)
#include "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\include\vector"
#pragma once
#//include "stdafx.h"
#include <xlocale>
//#include "[Vector3].h"

//
//struct UPrimitiveComponent_SetActorEnableCollision_Params
//{
//	bool                                               bNewActorEnableCollision;                                          // (Parm, ZeroConstructor, IsPlainOldData)
//};
//
//void SetActorEnableCollision(uint64_t pawn, bool bNewActorEnableCollision) {
//	static PVOID fn = nullptr;
//
//	if (!fn)
//		fn = SpoofCall(FN::FindObject2, (const char*)xorstr_("PrimitiveComponent"), (const char*)xorstr_("SetActorEnableCollision"));
//
//	UPrimitiveComponent_SetActorEnableCollision_Params params;
//
//	params.bNewActorEnableCollision = bNewActorEnableCollision;
//
//	FN::ProcessEvent(pawn, fn, &params);
//}
//
//struct UPrimitiveComponent_SetEnableGravity_Params
//{
//	bool                                               bGravityEnabled;                                          // (Parm, ZeroConstructor, IsPlainOldData)
//};
//void SetEnableGravity(uint64_t primitive_component, bool bEnable)
//{
//	static PVOID fn = nullptr;
//
//	if (!fn)
//		fn = SpoofCall(FN::FindObject2, (const char*)xorstr_("PrimitiveComponent"), (const char*)xorstr_("SetEnableGravity"));
//
//	UPrimitiveComponent_SetEnableGravity_Params params;
//
//	params.bGravityEnabled = bEnable;
//
//	FN::ProcessEvent(primitive_component, fn, &params);
//}
//
////GetDistanceMeters = cameralocation.distance(localpawn) / 100
//struct UPrimitiveComponent_SetAllPhysicsLinearVelocity_Params
//{
//	FVector                                            NewVel;                                                   // (Parm, IsPlainOldData)
//	bool                                               bAddToCurrent;                                            // (Parm, ZeroConstructor, IsPlainOldData)
//};
//
//void SetAllPhysicsAngularVelocity(uint64_t primitive_component, const FVector& NewVel, bool bAddToCurrent)
//{
//	static PVOID fn = nullptr;
//
//	if (!fn)
//		fn = SpoofCall(FN::FindObject2, (const char*)xorstr_("PrimitiveComponent"), (const char*)xorstr_("SetPhysicsAngularVelocity"));
//
//	if (!fn) return;
//
//	UPrimitiveComponent_SetAllPhysicsLinearVelocity_Params params;
//	params.NewVel = NewVel;
//	params.bAddToCurrent = bAddToCurrent;
//
//	FN::ProcessEvent(primitive_component, fn, &params);
//}
//
//void SetAllPhysicsLinearVelocity(uint64_t primitive_component, const FVector& NewVel, bool bAddToCurrent)
//{
//	static PVOID fn = nullptr;
//
//	if (!fn)
//		fn = SpoofCall(FN::FindObject2, (const char*)xorstr_("PrimitiveComponent"), (const char*)xorstr_("SetPhysicsLinearVelocity"));
//
//	UPrimitiveComponent_SetAllPhysicsLinearVelocity_Params params;
//	params.NewVel = NewVel;
//	params.bAddToCurrent = bAddToCurrent;
//
//	FN::ProcessEvent(primitive_component, fn, &params);
//}
//
//void ProcessVehicle(uintptr_t pawn)
//{
//	auto rc = read<uintptr_t>(pawn + Offsets::RootComponent);//root component
//
//	if (!rc)
//		return;
//
//	auto loc = read<Vector3>(rc + Offsets::RelativeLocation);
//
//	auto veh_mesh = *(uintptr_t*)(pawn + 0x480); if (!veh_mesh) return; //0xAD8
//
//	if (veh_mesh)
//	{
//		SetActorEnableCollision(pawn, false);
//
//		float coeff = (60.0f * 60);
//
//		if (A1337GetAsyncKeyState(VK_SHIFT))
//		{
//			coeff *= 2;
//		}
//
//		SetAllPhysicsAngularVelocity(veh_mesh, { 0, 0, 0 }, false);
//		SetAllPhysicsLinearVelocity(veh_mesh, { 0, 0, 0 }, false);
//		SetEnableGravity(veh_mesh, false);
//		bool bKp = false;
//
//		if (A1337GetAsyncKeyState('Q') & 0x8000)
//		{
//			SetAllPhysicsLinearVelocity(veh_mesh, { 0.f, 0.f, coeff / 2 }, true);
//			bKp = true;
//		}
//
//		if (A1337GetAsyncKeyState('E') & 0x8000)
//		{
//			SetAllPhysicsLinearVelocity(veh_mesh, { 0.f, 0.f, -(coeff / 2) }, true);
//			bKp = true;
//		}
//
//		if (A1337GetAsyncKeyState(0x57))
//		{
//			FVector vel;
//			auto yaw = CamRot.y;
//			float theta = 2.f * M_PI * (yaw / 360.f);
//
//			vel.X = (coeff * SpoofRuntime::cosf_(theta));
//			vel.Y = (coeff * SpoofRuntime::sinf_(theta));
//			vel.Z = 0.f;
//
//			SetAllPhysicsLinearVelocity(veh_mesh, vel, true);
//			bKp = true;
//		}
//		if (A1337GetAsyncKeyState(0x53))
//		{
//			FVector vel;
//			auto yaw = CamRot.y;
//			float theta = 2.f * M_PI * (yaw / 360.f);
//
//			vel.X = -(coeff * SpoofRuntime::cosf_(theta));
//			vel.Y = -(coeff * SpoofRuntime::sinf_(theta));
//
//			SetAllPhysicsLinearVelocity(veh_mesh, vel, true); //{ -80.f, 0.f, 0.f }
//			bKp = true;
//		}
//		if (A1337GetAsyncKeyState(0x41)) // A
//		{
//			FVector vel;
//			auto yaw = CamRot.y;
//			float theta = 2.f * M_PI * (yaw / 360.f);
//
//			vel.X = (coeff * SpoofRuntime::sinf_(theta));
//			vel.Y = -(coeff * SpoofRuntime::cosf_(theta));
//
//			SetAllPhysicsLinearVelocity(veh_mesh, vel, true); //{ -80.f, 0.f, 0.f }
//			bKp = true;
//		}
//		if (A1337GetAsyncKeyState(0x44)) // D
//		{
//			FVector vel;
//			auto yaw = CamRot.y;
//			float theta = 2.f * M_PI * (yaw / 360.f);
//
//			vel.X = -(coeff * SpoofRuntime::sinf_(theta));
//			vel.Y = (coeff * SpoofRuntime::cosf_(theta));
//
//			SetAllPhysicsLinearVelocity(veh_mesh, vel, true); //{ -80.f, 0.f, 0.f }
//			bKp = true;
//		}
//
//		if (!bKp || A1337GetAsyncKeyState(VK_SPACE))
//		{
//			SetAllPhysicsLinearVelocity(veh_mesh, { 0.0, 0.0, 0.0 }, false);
//		}
//	}
//	else
//	{
//		SetEnableGravity(veh_mesh, true);
//		SetActorEnableCollision(pawn, true);
//	}
//}

/*
namespace UtilK
{
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
		int Count;
		int Max;
	};

	struct FString : private TArray<wchar_t>
	{
		inline FString()
		{
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


	typedef struct
	{
		FVector Location;
		FRotator Rotation;
		float FOV;
		float OrthoWidth;
		float OrthoNearClipPlane;
		float OrthoFarClipPlane;
		float AspectRatio;
	} FMinimalViewInfo;


	typedef struct {
		float M[4][4];
	} FMatrix;

	typedef struct {
		FVector ViewOrigin;
		char _padding_0[4];
		FMatrix ViewRotationMatrix;
		FMatrix ProjectionMatrix;
	} FSceneViewProjectionData;

	typedef struct {
		FVector Origin;
		FVector BoxExtent;
		float SphereRadius;
	} FBoxSphereBounds;
}

unsigned char* g_pSpoofGadget = 0;

#define SPOOFER_MODULE E("ntdll.dll")

#define GLOBAL_DEBUG_FLAG
#define GLOBAL_UNLOAD_FLAG

#ifdef GLOBAL_DEBUG_FLAG
#define DEBUG_ENABLE true
#else
#define NODPRINTF
#define DEBUG_ENABLE false
#endif

struct FHitResult
{
	char memes[0x1000];
};

#define COLLINMENU_COLOR_1 Colors::Black

ULONGLONG tStarted = 0;
ULONGLONG tEnded = 0;

bool HOOKED = true;

float AimbotKey = VK_RBUTTON;
float WeakSpotAimbotKey = VK_CAPITAL;

#define s c_str()

//#define null 0
#define DEBUG_USE_MBOX false
#define DEBUG_USE_LOGFILE true
#define DEBUG_USE_CONSOLE false
#define DEBUG_LOG_PROCESSEVENT_CALLS false
#define PROCESSEVENT_INDEX 68
#define POSTRENDER_INDEX 100

#define MESH_BONE_ARRAY 0x4a8
#define MESH_COMPONENT_TO_WORLD 0x1C0
#define DGOffset_OGI 0x180
#define DGOffset_LocalPlayers 0x38
#define DGOffset_PlayerController 0x30
#define DGOffset_MyHUD 0x02B0
#define DGOffset_Canvas 0x0270
#define DGOffset_Font 0x90
#define DGOffset_Levels 0x138//0x160 0x138
#define DGOffset_Actors 0x98
#define DGOffset_RootComponent 0x130
#define DGOffset_ComponentLocation 0x011C
#define DGOffset_Pawn 0x2A0
#define DGOffset_Mesh 0x280
#define DGOffset_PlayerState 0x240
#define DGOffset_WeaponData 0x378
#define DGOffset_Weapon 0x5F0
#define DGOffset_DisplayName 0x88
#define DGOffset_ViewportClient 0x70
#define DGOffset_ItemDefinition 0x18
#define DGOffset_PrimaryPickupItemEntry 0x02A8
#define DGOffset_Tier 0x6C
#define DGOffset_BlockingHit 0x0
#define DGOffset_PlayerCameraManager 0x02B8
#define DGOffset_TeamIndex 0x0ED0
#define DGOffset_ComponentVelocity 0x0140
#define DGOffset_MovementComponent 0x0288
#define DGOffset_Acceleration 0x024C
#define DGOffset_GravityScale 0x0150
#define DGOffset_Searched 0x0D49
#define DGOffset_bHit 0x0250
#define DGOffset_VehicleSkeletalMesh 0xAD8
#define DGOffset_pGEngine 0x5778AD0
#define DGOffset_GObjects 0x9683EE8
#define DGOffset_GetNameById 0x9683EF6
#define DGOffset_GWorld 0x9864730
#define DGOffset_TraceVisibility 0x28BB1A0
#define RVA(addr, size) ((PBYTE)(addr + *(DWORD*)(addr + ((size) - 4)) + size))

#define _ZeroMemory(x, y) (memset(x, 0, y));
//gg
#ifdef NODPRINTF
#define dprintf(x)
#else
#define dprintf printf
#endif

uintptr_t GOffset_OGI = 0;
uintptr_t GOffset_LocalPlayers = 0;
uintptr_t GOffset_PlayerController = 0;
uintptr_t GOffset_MyHUD = 0;
uintptr_t GOffset_Canvas = 0;
uintptr_t GOffset_Font = 0;

#define M_PI		3.14159265358979323846264338327950288419716939937510582f


uintptr_t GPawn;

int g_MX = 0;
int g_MY = 0;

int g_ScreenWidth = 0;
int g_ScreenHeight = 0;

bool bAimbotActivated = false;




#define INRANGE(x,a,b)    (x >= a && x <= b)
#define getBits( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xA) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define getByte( x )    (getBits(x[0]) << 4 | getBits(x[1]))
uintptr_t GFnBase, GFnSize = 0;

uintptr_t FindPattern(const char* pattern)
{
	char* pat = const_cast<char*>(pattern);
	uintptr_t firstMatch = 0;
	auto b = GFnBase;
	uintptr_t rangeEnd = b + GFnSize;

	for (auto pCur = b; pCur < rangeEnd; pCur++)
	{
		if (!*pat)
			return firstMatch;

		if (*(BYTE*)pat == '\?' || *(BYTE*)pCur == getByte(pat))
		{
			if (!firstMatch)
				firstMatch = pCur;

			if (!pat[2])
				return firstMatch;

			if (*(BYTE*)pat == '\?')
				pat += 2;
			else
				pat += 3;
		}
		else
		{
			pat = const_cast<char*>(pattern);
			firstMatch = 0;
		}
	}

	return 0;
}

struct keys
{
	bool mouse[4] = {};
	bool key[256] = {};
	float mouse_wheel = 0.f;
	int16_t mouseX = 0;
	int16_t mouseY = 0;
};

keys* k;

template<class T>
struct TArray
{


public:

	friend struct FString;

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

	inline bool IsValid() const
	{
		return Data != nullptr;
	}

	inline bool IsValidIndex(int i) const
	{
		return i < Num();
	}

	void Clear()
	{
		Data = nullptr;
		Count = Max = 0;
	};

	inline void Add(T InputData)
	{
		Data = (T*)realloc(Data, sizeof(T) * (Count + 1));
		Data[Count++] = InputData;
		Max = Count;
	};

	T* Data;
	int32_t Count;
	int32_t Max;
};

struct FString : private TArray<wchar_t>
{
public:

	inline FString()
	{
	};

	FString(const wchar_t* other)
	{
		Max = Count = *other ? (int32_t)std::wcslen(other) + 1 : 0;

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

using tGetPathName = void(__fastcall*)(void* _this, FString* fs, uint64_t zeroarg);
tGetPathName GGetPathName = 0;
void* GGetObjectClass = 0;

std::string WideToAnsi(const wchar_t* inWide)
{
	static char outAnsi[0x1000];

	int i = 0;
	for (; inWide[i / 2] != L'\0'; i += 2)
		outAnsi[i / 2] = ((const char*)inWide)[i];
	outAnsi[i / 2] = '\0';

	return outAnsi;
}

void __forceinline WideToAnsi(wchar_t* inWide, char* outAnsi)
{
	int i = 0;
	for (; inWide[i / 2] != L'\0'; i += 2)
		outAnsi[i / 2] = ((const char*)inWide)[i];
	outAnsi[i / 2] = '\0';
}

void __forceinline AnsiToWide(char* inAnsi, wchar_t* outWide)
{
	int i = 0;
	for (; inAnsi[i] != '\0'; i++)
		outWide[i] = (wchar_t)(inAnsi)[i];
	outWide[i] = L'\0';
}

std::wstring AnsiToWide(const char* inAnsi)
{
	static wchar_t outWide[0x1000];

	int i = 0;
	for (; inAnsi[i] != '\0'; i++)
		outWide[i] = (wchar_t)(inAnsi)[i];
	outWide[i] = L'\0';

	return outWide;
}

struct FVector2D
{
	float                                              X;                                                        // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	float                                              Y;                                                        // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)

	inline FVector2D()
		: X(0), Y(0)
	{ }

	inline FVector2D(float x, float y)
		: X(x),
		Y(y)
	{ }

	__forceinline FVector2D operator-(const FVector2D& V) {
		return FVector2D(X - V.X, Y - V.Y);
	}

	__forceinline FVector2D operator+(const FVector2D& V) {
		return FVector2D(X + V.X, Y + V.Y);
	}

	__forceinline FVector2D operator*(float Scale) const {
		return FVector2D(X * Scale, Y * Scale);
	}

	__forceinline FVector2D operator/(float Scale) const {
		const float RScale = 1.f / Scale;
		return FVector2D(X * RScale, Y * RScale);
	}

	__forceinline FVector2D operator+(float A) const {
		return FVector2D(X + A, Y + A);
	}

	__forceinline FVector2D operator-(float A) const {
		return FVector2D(X - A, Y - A);
	}

	__forceinline FVector2D operator*(const FVector2D& V) const {
		return FVector2D(X * V.X, Y * V.Y);
	}

	__forceinline FVector2D operator/(const FVector2D& V) const {
		return FVector2D(X / V.X, Y / V.Y);
	}

	__forceinline float operator|(const FVector2D& V) const {
		return X * V.X + Y * V.Y;
	}

	__forceinline float operator^(const FVector2D& V) const {
		return X * V.Y - Y * V.X;
	}

	__forceinline FVector2D& operator+=(const FVector2D& v) {
		(*this);
		(v);
		X += v.X;
		Y += v.Y;
		return *this;
	}

	__forceinline FVector2D& operator-=(const FVector2D& v) {
		(*this);
		(v);
		X -= v.X;
		Y -= v.Y;
		return *this;
	}

	__forceinline FVector2D& operator*=(const FVector2D& v) {
		(*this);
		(v);
		X *= v.X;
		Y *= v.Y;
		return *this;
	}

	__forceinline FVector2D& operator/=(const FVector2D& v) {
		(*this);
		(v);
		X /= v.X;
		Y /= v.Y;
		return *this;
	}

	__forceinline bool operator==(const FVector2D& src) const {
		(src);
		(*this);
		return (src.X == X) && (src.Y == Y);
	}

	__forceinline bool operator!=(const FVector2D& src) const {
		(src);
		(*this);
		return (src.X != X) || (src.Y != Y);
	}

	__forceinline float Size() const {
		return sqrt(X * X + Y * Y);
	}

	__forceinline float SizeSquared() const {
		return X * X + Y * Y;
	}

	__forceinline float Dot(const FVector2D& vOther) const {
		const FVector2D& a = *this;

		return (a.X * vOther.X + a.Y * vOther.Y);
	}

	__forceinline FVector2D Normalize() {
		FVector2D vector;
		float length = this->Size();

		if (length != 0) {
			vector.X = X / length;
			vector.Y = Y / length;
		}
		else
			vector.X = vector.Y = 0.0f;

		return vector;
	}

	__forceinline float DistanceFrom(const FVector2D& Other) const {
		const FVector2D& a = *this;
		float dx = (a.X - Other.X);
		float dy = (a.Y - Other.Y);

		return sqrt((dx * dx) + (dy * dy));
	}

};

uintptr_t GPlayerCameraManager = 0;
uintptr_t GController = 0;
uintptr_t GWorld = 0;



void cFixName(char* Name)
{
	for (int i = 0; Name[i] != '\0'; i++)
	{
		if (Name[i] == '_')
		{
			if (Name[i + 1] == '0' ||
				Name[i + 1] == '1' ||
				Name[i + 1] == '2' ||
				Name[i + 1] == '3' ||
				Name[i + 1] == '4' ||
				Name[i + 1] == '5' ||
				Name[i + 1] == '6' ||
				Name[i + 1] == '7' ||
				Name[i + 1] == '8' ||
				Name[i + 1] == '9')
				Name[i] = '\0';
		}
	}

	return;
}

void FreeObjName(__int64 address)
{
	static uintptr_t addr = 0;

	if (!addr) {
		addr = FindPattern(E("48 85 C9 0F 84 ? ? ? ? 53 48 83 EC 20 48 89 7C 24 30 48 8B D9 48 8B 3D ? ? ? ? 48 85 FF 0F 84 ? ? ? ? 48 8B 07 4C 8B 40 30 48 8D 05 ? ? ? ? 4C 3B C0"));;

		if (!addr) {
			exit(0);
		}
	}

	auto func = reinterpret_cast<__int64(__fastcall*)(__int64 a1)>(addr);

	func(address);
}


std::string fGetNameByIndex(int Index)
{
	static uintptr_t addr = 0;

	if (!addr) {
		addr = FindPattern(E("48 89 5C 24 ? 48 89 74 24 ? 55 57 41 56 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 45 33 F6 48 8B F2 44 39 71 04 0F 85 ? ? ? ? 8B 19 0F B7 FB E8 ? ? ? ? 8B CB 48 8D 54 24"));
		if (!addr) {
			exit(0);
		}
	}

	auto fGetNameByIdx = reinterpret_cast<FString * (__fastcall*)(int*, FString*)>(addr);

	FString result;
	fGetNameByIdx(&Index, &result);

	if (result.c_str() == NULL) return (char*)"";

	auto tmp = result.ToString();

	char return_string[1024] = {};
	for (size_t i = 0; i < tmp.size(); i++)
	{
		return_string[i] += tmp[i];
	}

	FreeObjName((uintptr_t)result.c_str());

	cFixName(return_string);

	return std::string(return_string);
}






std::string GetById(int id)
{

	return fGetNameByIndex(id);
}


struct FName
{
	union
	{
		struct
		{
			int32_t ComparisonIndex;
			int32_t Number;
		};

		uint64_t CompositeComparisonValue;
	};

	inline FName()
		: ComparisonIndex(0),
		Number(0)
	{
	};

	inline FName(int32_t i)
		: ComparisonIndex(i),
		Number(0)
	{
	};

	inline std::string GetName() const
	{
		return GetById(ComparisonIndex);
	};

	inline bool operator==(const FName& other) const
	{
		return ComparisonIndex == other.ComparisonIndex;
	};
};

// Enum Engine.EFontCacheType
enum class EFontCacheType : uint8_t
{
	Offline = 0,
	Runtime = 1,
	EFontCacheType_MAX = 2
};
// Enum Engine.EFontImportCharacterSet
enum class EFontImportCharacterSet : uint8_t
{
	FontICS_Default = 0,
	FontICS_Ansi = 1,
	FontICS_Symbol = 2,
	FontICS_MAX = 3
};
// Enum SlateCore.EFontHinting
enum class EFontHinting : uint8_t
{
	Default = 0,
	Auto = 1,
	AutoLight = 2,
	Monochrome = 3,
	None = 4,
	EFontHinting_MAX = 5
};
// Enum SlateCore.EFontLoadingPolicy
enum class EFontLoadingPolicy : uint8_t
{
	LazyLoad = 0,
	Stream = 1,
	Inline = 2,
	EFontLoadingPolicy_MAX = 3
};

class UObject
{
public:
	void** Vtable;                                                   // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	int32_t                                            ObjectFlags;                                              // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	int32_t                                            InternalIndex;                                            // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	class UClass* Class;                                                    // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	FName                                              Name;                                                     // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	class UObject* Outer;                                                    // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY

	static inline UtilK::TUObjectArray GetGlobalObjects()
	{
		static FUObjectArray* GObjects = NULL;

		if (!GObjects)
			GObjects = (FUObjectArray*)((DWORD64)GetModuleHandleW(NULL) + 0x968c240);

		return GObjects->ObjObjects;
	}

	std::string GetName() const;

	std::string GetFullName() const;

	template<typename T>
	static T* FindObject(const std::string& name)
	{
		/*for (int i = 0; i < GetGlobalObjects().Num(); ++i)
		{
			auto object = GetGlobalObjects().GetByIndex(i);

			if (object == nullptr)
			{
				continue;
			}

			if (object->GetFullName() == name)
			{
				return static_cast<T*>(object);
			}
		}
		return nullptr;
	}

	static UClass* FindClass(const std::string& name)
	{
		return FindObject<UClass>(name);
	}

	template<typename T>
	static T* GetObjectCasted(std::size_t index)
	{
		return static_cast<T*>(GetGlobalObjects().GetByIndex(index));
	}


	static UClass* StaticClass()
	{
		static UClass* ptr = NULL;
		if (!ptr)
			ptr = UObject::FindClass(xorstr_("Class CoreUObject.Object"));

		return ptr;
	}

};


template<class TEnum>
class TEnumAsByte
{
public:
	inline TEnumAsByte()
	{
	}

	inline TEnumAsByte(TEnum _value)
		: value(static_cast<uint8_t>(_value))
	{
	}

	explicit inline TEnumAsByte(int32_t _value)
		: value(static_cast<uint8_t>(_value))
	{
	}

	explicit inline TEnumAsByte(uint8_t _value)
		: value(_value)
	{
	}

	inline operator TEnum() const
	{
		return (TEnum)value;
	}

	inline TEnum GetValue() const
	{
		return (TEnum)value;
	}

private:
	uint8_t value;
};

// ScriptStruct CoreUObject.LinearColor
// 0x0010
struct FLinearColor
{
	float                                              R;                                                        // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	float                                              G;                                                        // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	float                                              B;                                                        // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	float                                              A;                                                        // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)

	inline FLinearColor()
		: R(0), G(0), B(0), A(0)
	{ }

	inline FLinearColor(float r, float g, float b, float a)
		: R(r),
		G(g),
		B(b),
		A(a)
	{ }

};

// ScriptStruct Engine.FontImportOptionsData
// 0x00B0
struct FFontImportOptionsData
{
	struct FString                                     FontName;                                                 // 0x0000(0x0010) (Edit, ZeroConstructor)
	float                                              Height;                                                   // 0x0010(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      bEnableAntialiasing : 1;                                  // 0x0014(0x0001) (Edit)
	unsigned char                                      bEnableBold : 1;                                          // 0x0014(0x0001) (Edit)
	unsigned char                                      bEnableItalic : 1;                                        // 0x0014(0x0001) (Edit)
	unsigned char                                      bEnableUnderline : 1;                                     // 0x0014(0x0001) (Edit)
	unsigned char                                      bAlphaOnly : 1;                                           // 0x0014(0x0001) (Edit)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0015(0x0003) MISSED OFFSET
	TEnumAsByte<EFontImportCharacterSet>               CharacterSet;                                             // 0x0018(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0019(0x0007) MISSED OFFSET
	struct FString                                     Chars;                                                    // 0x0020(0x0010) (Edit, ZeroConstructor)
	struct FString                                     UnicodeRange;                                             // 0x0030(0x0010) (Edit, ZeroConstructor)
	struct FString                                     CharsFilePath;                                            // 0x0040(0x0010) (Edit, ZeroConstructor)
	struct FString                                     CharsFileWildcard;                                        // 0x0050(0x0010) (Edit, ZeroConstructor)
	unsigned char                                      bCreatePrintableOnly : 1;                                 // 0x0060(0x0001) (Edit)
	unsigned char                                      bIncludeASCIIRange : 1;                                   // 0x0060(0x0001) (Edit)
	unsigned char                                      UnknownData02[0x3];                                       // 0x0061(0x0003) MISSED OFFSET
	struct FLinearColor                                ForegroundColor;                                          // 0x0064(0x0010) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      bEnableDropShadow : 1;                                    // 0x0074(0x0001) (Edit)
	unsigned char                                      UnknownData03[0x3];                                       // 0x0075(0x0003) MISSED OFFSET
	int                                                TexturePageWidth;                                         // 0x0078(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	int                                                TexturePageMaxHeight;                                     // 0x007C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	int                                                XPadding;                                                 // 0x0080(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	int                                                YPadding;                                                 // 0x0084(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	int                                                ExtendBoxTop;                                             // 0x0088(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	int                                                ExtendBoxBottom;                                          // 0x008C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	int                                                ExtendBoxRight;                                           // 0x0090(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	int                                                ExtendBoxLeft;                                            // 0x0094(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      bEnableLegacyMode : 1;                                    // 0x0098(0x0001) (Edit)
	unsigned char                                      UnknownData04[0x3];                                       // 0x0099(0x0003) MISSED OFFSET
	int                                                Kerning;                                                  // 0x009C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      bUseDistanceFieldAlpha : 1;                               // 0x00A0(0x0001) (Edit)
	unsigned char                                      UnknownData05[0x3];                                       // 0x00A1(0x0003) MISSED OFFSET
	int                                                DistanceFieldScaleFactor;                                 // 0x00A4(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              DistanceFieldScanRadiusScale;                             // 0x00A8(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData06[0x4];                                       // 0x00AC(0x0004) MISSED OFFSET
};


// ScriptStruct SlateCore.FontData
// 0x0020
struct FFontData
{
	struct FString                                     FontFilename;                                             // 0x0000(0x0010) (ZeroConstructor)
	EFontHinting                                       Hinting;                                                  // 0x0010(0x0001) (ZeroConstructor, IsPlainOldData)
	EFontLoadingPolicy                                 LoadingPolicy;                                            // 0x0011(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0012(0x0002) MISSED OFFSET
	int                                                SubFaceIndex;                                             // 0x0014(0x0004) (ZeroConstructor, IsPlainOldData)
	class UObject* FontFaceAsset;                                            // 0x0018(0x0008) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct SlateCore.TypefaceEntry
// 0x0028
struct FTypefaceEntry
{
	struct FName                                       Name;                                                     // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FFontData                                   Font;                                                     // 0x0008(0x0020)
};

// ScriptStruct SlateCore.Typeface
// 0x0010
struct FTypeface
{
	TArray<struct FTypefaceEntry>                      Fonts;                                                    // 0x0000(0x0010) (ZeroConstructor)
};
// ScriptStruct SlateCore.CompositeFallbackFont
// 0x0018
struct FCompositeFallbackFont
{
	struct FTypeface                                   Typeface;                                                 // 0x0000(0x0010)
	float                                              ScalingFactor;                                            // 0x0010(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
};

// ScriptStruct SlateCore.CompositeFont
// 0x0038
struct FCompositeFont
{
	struct FTypeface                                   DefaultTypeface;                                          // 0x0000(0x0010)
	struct FCompositeFallbackFont                      FallbackTypeface;                                         // 0x0010(0x0018)
	TArray<struct FCompositeSubFont>                   SubTypefaces;                                             // 0x0028(0x0010) (ZeroConstructor)
};


class UFont : public UObject
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0028(0x0008) MISSED OFFSET
	EFontCacheType                                     FontCacheType;                                            // 0x0030(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0031(0x0007) MISSED OFFSET
	TArray<struct FFontCharacter>                      Characters;                                               // 0x0038(0x0010) (Edit, ZeroConstructor)
	TArray<class UTexture2D*>                          Textures;                                                 // 0x0048(0x0010) (ZeroConstructor)
	int                                                IsRemapped;                                               // 0x0058(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              EmScale;                                                  // 0x005C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              Ascent;                                                   // 0x0060(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              Descent;                                                  // 0x0064(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              Leading;                                                  // 0x0068(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	int                                                Kerning;                                                  // 0x006C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	struct FFontImportOptionsData                      ImportOptions;                                            // 0x0070(0x00B0) (Edit)
	int                                                NumCharacters;                                            // 0x0120(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x0124(0x0004) MISSED OFFSET
	TArray<int>                                        MaxCharHeight;                                            // 0x0128(0x0010) (ZeroConstructor, Transient)
	float                                              ScalingFactor;                                            // 0x0138(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	int                                                LegacyFontSize;                                           // 0x013C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	struct FName                                       LegacyFontName;                                           // 0x0140(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	struct FCompositeFont                              CompositeFont;                                            // 0x0148(0x0038)
	unsigned char                                      UnknownData03[0x50];                                      // 0x0180(0x0050) MISSED OFFSET

	static UClass* StaticClass()
	{
		static UClass* ptr = NULL;
		if (!ptr)
			ptr = UObject::FindClass(xorstr_("Class Engine.Font"));

		return ptr;
	}

};

class UField : public UObject
{
public:
	class UField* Next;                                                     // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY

	static UClass* StaticClass()
	{
		static UClass* ptr = NULL;
		if (!ptr)
			ptr = UObject::FindClass(xorstr_("Class CoreUObject.Field"));

		return ptr;
	}

};

class UProperty : public UField
{
public:
	unsigned char                                      UnknownData00[0x40];                                      // 0x0030(0x0040) MISSED OFFSET
	int32_t Offset; //0x0044

	static UClass* StaticClass()
	{
		static UClass* ptr = NULL;
		if (!ptr)
			ptr = UObject::FindClass(xorstr_("Class CoreUObject.Property"));

		return ptr;
	}

};;

class UStruct : public UField
{
public:
	char                                               pad_0030[0x10];                                           // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	class UStruct* SuperField;                                               // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	class UField* Children;                                                 // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	void* ChildProperties;                                          // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	int32_t                                            PropertySize;                                             // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	int32_t                                            MinAlignment;                                             // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	char                                               pad_0060[0x50];                                           // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY

	static UClass* StaticClass()
	{
		static UClass* ptr = NULL;
		if (!ptr)
			ptr = UObject::FindClass(xorstr_("Class CoreUObject.Struct"));

		return ptr;
	}

};

class UClass : public UStruct
{
public:
	unsigned char                                      UnknownData00[0x188];                                     // 0x00B0(0x0188) MISSED OFFSET

	static UClass* StaticClass()
	{
		static UClass* ptr = NULL;
		if (!ptr)
			ptr = UObject::FindClass(xorstr_("Class CoreUObject.Class"));

		return ptr;
	}

};

std::string UObject::GetName() const
{
	std::string name(Name.GetName());
	if (Name.Number > 0)
	{
		name += '_' + std::to_string(Name.Number);
	}

	auto pos = name.rfind('/');
	if (pos == std::string::npos)
	{
		return name;
	}

	return name.substr(pos + 1);
}

std::string UObject::GetFullName() const
{
	std::string name;

	if (Class != nullptr)
	{
		std::string temp;
		for (auto p = Outer; p; p = p->Outer)
		{
			temp = p->GetName() + "." + temp;
		}

		name = Class->GetName();
		name += " ";
		name += temp;
		name += GetName();
	}

	return name;
}

std::string GetById(int id);



template<typename ElementType, int32_t MaxTotalElements, int32_t ElementsPerChunk> class GObjsTStaticIndirectArrayThreadSafeRead
{
public:

	static int32_t Num()
	{
		return 65535;
	}

	bool IsValidIndex(int32_t index) const
	{
		return index >= 0 && index < Num() && GetById(index) != nullptr;
	}

	ElementType* const GetById(int32_t index) const
	{
		return GetItemPtr(index);
	}

private:

	ElementType* const GetItemPtr(int32_t Index) const
	{
		int32_t ChunkIndex = Index / ElementsPerChunk;
		int32_t SubIndex = Index % ElementsPerChunk;
		auto pGObjects = (uintptr_t*)*Chunks;
		if (IsBadReadPtr(pGObjects, 0x8))
			return nullptr;
		auto chunk = pGObjects[ChunkIndex];
		if (IsBadReadPtr((void*)chunk, 0x8))
			return nullptr;
		return &((ElementType*)chunk)[SubIndex];
	}

	enum
	{
		ChunkTableSize = (MaxTotalElements + ElementsPerChunk - 1) / ElementsPerChunk
	};

	ElementType*** Chunks[ChunkTableSize];
};

using TObjectEntryArray = GObjsTStaticIndirectArrayThreadSafeRead<UtilK::FUObjectItem, 2 * 1024 * 1024, 0x10400>;

TObjectEntryArray* GObjects;

uintptr_t FindSpooferFromModuleBase(const char* mod)
{
	auto spooferMod = (uintptr_t)GetModuleHandleA(mod);
	spooferMod += 0x1000;
	while (true)
	{
		if (*(UINT8*)(spooferMod) == 0xFF && *(UINT8*)(spooferMod + 1) == 0x23)
			return spooferMod;
		spooferMod++;
	}
	return 0;
}

uintptr_t FindSpooferFromModule(void* mod)
{
	auto spooferMod = (uintptr_t)mod;
	spooferMod += 0x1000;
	while (true)
	{
		if (*(UINT8*)(spooferMod) == 0xFF && *(UINT8*)(spooferMod + 1) == 0x23)
			return spooferMod;
		spooferMod++;
	}
	return 0;
}

uintptr_t GOffset_bHit = 0;

bool MemoryBlocksEqual(void* b1, void* b2, UINT32 size)
{
	uintptr_t p1 = (uintptr_t)b1;
	uintptr_t p2 = (uintptr_t)b2;
	UINT32 off = 0;

	while (off != size)
	{
		if (*(UINT8*)(p1 + off) != *(UINT8*)(p2 + off))
			return false;
		off++;
	}

	return true;
}

uintptr_t TraceToModuleBaseAndGetSpoofGadget(void* func)
{
	auto ptr = (uintptr_t)func;
	auto hdrSig = E("This program cannot be run in DOS mode");

	while (true)
	{
		if (MemoryBlocksEqual((void*)ptr, hdrSig, sizeof(hdrSig) - 1))
			break;
		ptr--;
	}

	char mz[] = { 0x4D, 0x5A };

	while (true)
	{
		if (MemoryBlocksEqual((void*)ptr, mz, sizeof(mz)))
			break;
		ptr--;
	}

	// we're at module base now.

	ptr += 0x1000;

	while (true)
	{
		if (*(UINT8*)(ptr) == 0xFF && *(UINT8*)(ptr + 1) == 0x23)
			return ptr;
		ptr++;
	}

	return 0;
}


#define CHECK_VALID(x)

double mytan(double x)
{
	return (sin(x) / cos(x));
}

struct FRotator {
	float                                              Pitch;                                                    // 0x0000(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
	float                                              Yaw;                                                      // 0x0004(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
	float                                              Roll;                                                     // 0x0008(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)

	inline FRotator()
		: Pitch(0), Yaw(0), Roll(0) {
	}

	inline FRotator(float x, float y, float z)
		: Pitch(x),
		Yaw(y),
		Roll(z) {
	}

	__forceinline FRotator operator+(const FRotator& V) {
		return FRotator(Pitch + V.Pitch, Yaw + V.Yaw, Roll + V.Roll);
	}

	__forceinline FRotator operator-(const FRotator& V) {
		return FRotator(Pitch - V.Pitch, Yaw - V.Yaw, Roll - V.Roll);
	}

	__forceinline FRotator operator*(float Scale) const {
		return FRotator(Pitch * Scale, Yaw * Scale, Roll * Scale);
	}

	__forceinline FRotator operator/(float Scale) const {
		const float RScale = 1.f / Scale;
		return FRotator(Pitch * RScale, Yaw * RScale, Roll * RScale);
	}

	__forceinline FRotator operator+(float A) const {
		return FRotator(Pitch + A, Yaw + A, Roll + A);
	}

	__forceinline FRotator operator-(float A) const {
		return FRotator(Pitch - A, Yaw - A, Roll - A);
	}

	__forceinline FRotator operator*(const FRotator& V) const {
		return FRotator(Pitch * V.Pitch, Yaw * V.Yaw, Roll * V.Roll);
	}

	__forceinline FRotator operator/(const FRotator& V) const {
		return FRotator(Pitch / V.Pitch, Yaw / V.Yaw, Roll / V.Roll);
	}

	__forceinline float operator|(const FRotator& V) const {
		return Pitch * V.Pitch + Yaw * V.Yaw + Roll * V.Roll;
	}

	__forceinline FRotator& operator+=(const FRotator& v) {
		CHECK_VALID(*this);
		CHECK_VALID(v);
		Pitch += v.Pitch;
		Yaw += v.Yaw;
		Roll += v.Roll;
		return *this;
	}

	__forceinline FRotator& operator-=(const FRotator& v) {
		CHECK_VALID(*this);
		CHECK_VALID(v);
		Pitch -= v.Pitch;
		Yaw -= v.Yaw;
		Roll -= v.Roll;
		return *this;
	}

	__forceinline FRotator& operator*=(const FRotator& v) {
		CHECK_VALID(*this);
		CHECK_VALID(v);
		Pitch *= v.Pitch;
		Yaw *= v.Yaw;
		Roll *= v.Roll;
		return *this;
	}

	__forceinline FRotator& operator/=(const FRotator& v) {
		CHECK_VALID(*this);
		CHECK_VALID(v);
		Pitch /= v.Pitch;
		Yaw /= v.Yaw;
		Roll /= v.Roll;
		return *this;
	}

	__forceinline float operator^(const FRotator& V) const {
		return Pitch * V.Yaw - Yaw * V.Pitch - Roll * V.Roll;
	}

	__forceinline bool operator==(const FRotator& src) const {
		CHECK_VALID(src);
		CHECK_VALID(*this);
		return (src.Pitch == Pitch) && (src.Yaw == Yaw) && (src.Roll == Roll);
	}

	__forceinline bool operator!=(const FRotator& src) const {
		CHECK_VALID(src);
		CHECK_VALID(*this);
		return (src.Pitch != Pitch) || (src.Yaw != Yaw) || (src.Roll != Roll);
	}

	__forceinline float Size() const {
		return sqrt(Pitch * Pitch + Yaw * Yaw + Roll * Roll);
	}


	__forceinline float SizeSquared() const {
		return Pitch * Pitch + Yaw * Yaw + Roll * Roll;
	}

	__forceinline float Dot(const FRotator& vOther) const {
		const FRotator& a = *this;

		return (a.Pitch * vOther.Pitch + a.Yaw * vOther.Yaw + a.Roll * vOther.Roll);
	}

	__forceinline float ClampAxis(float Angle) {
		// returns Angle in the range (-360,360)
		Angle = fmod(Angle, 360.f);

		if (Angle < 0.f) {
			// shift to [0,360) range
			Angle += 360.f;
		}

		return Angle;
	}

	__forceinline float NormalizeAxis(float Angle) {
		// returns Angle in the range [0,360)
		Angle = ClampAxis(Angle);

		if (Angle > 180.f) {
			// shift to (-180,180]
			Angle -= 360.f;
		}

		return Angle;
	}

	__forceinline void Normalize() {
		Pitch = NormalizeAxis(Pitch);
		Yaw = NormalizeAxis(Yaw);
		Roll = NormalizeAxis(Roll);
	}

	__forceinline FRotator GetNormalized() const {
		FRotator Rot = *this;
		Rot.Normalize();
		return Rot;
	}
};

typedef struct _D3DMATRIX {
	union {
		struct {
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;

		};
		float m[4][4];
	};
} D3DMATRIX;

// ScriptStruct CoreUObject.Vector
// 0x000C
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
		return sqrt(X * X + Y * Y + Z * Z);
	}

	__forceinline float Size2D() const {
		return sqrt(X * X + Y * Y);
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

		return (sqrt((dx * dx) + (dy * dy) + (dz * dz)));
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

D3DMATRIX _inline MatrixMultiplication(D3DMATRIX pM1, D3DMATRIX pM2);


float GetWeaponBulletSpeed(uint64_t cwep);
FVector get_velocity(uint64_t root_comp);
FVector get_acceleration(uint64_t target);

struct FCameraCacheEntry {
	FVector Location;
	FRotator Rotation;
	float FOV;
	//0xEB0
};

static inline void _out_buffer(char character, void* buffer, size_t idx, size_t maxlen)
{
	if (idx < maxlen)
	{
		((char*)buffer)[idx] = character;
	}
}



// ScriptStruct CoreUObject.Plane
// 0x0004 (0x0010 - 0x000C)
struct alignas(16) FPlane : public FVector
{
	float                                              W;                                                        // 0x000C(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
};


// ScriptStruct CoreUObject.Matrix
// 0x0040
struct FMatrix
{
	struct FPlane                                      XPlane;                                                   // 0x0000(0x0010) (CPF_Edit, CPF_BlueprintVisible, CPF_SaveGame, CPF_IsPlainOldData)
	struct FPlane                                      YPlane;                                                   // 0x0010(0x0010) (CPF_Edit, CPF_BlueprintVisible, CPF_SaveGame, CPF_IsPlainOldData)
	struct FPlane                                      ZPlane;                                                   // 0x0020(0x0010) (CPF_Edit, CPF_BlueprintVisible, CPF_SaveGame, CPF_IsPlainOldData)
	struct FPlane                                      WPlane;                                                   // 0x0030(0x0010) (CPF_Edit, CPF_BlueprintVisible, CPF_SaveGame, CPF_IsPlainOldData)
};

typedef FMatrix* (*tGetBoneMatrix)(UObject*, FMatrix*, int);
tGetBoneMatrix GetBoneMatrix;

using tTraceVisibility = bool(__fastcall*)(UObject*, FVector&, FVector&, bool, bool, FVector*, FVector*, FName*, FHitResult*);

tTraceVisibility GTraceVisibilityFn = 0;

bool VisibilityCheck(UObject* mesh, FVector& TraceStart, FVector& TraceEnd, bool bTraceComplex, bool bShowTrace, FVector* HitLocation, FVector* HitNormal, FName* BoneName, FHitResult* OutHit)
{
	return GTraceVisibilityFn(mesh, TraceStart, TraceEnd, bTraceComplex, bShowTrace, HitLocation, HitNormal, BoneName, OutHit);
}

enum Bones : uint8_t
{
	Root = 0,
	attach = 1,
	pelvis = 2,
	spine_01 = 3,
	spine_02 = 4,
	Spine_03 = 5,
	spine_04 = 6,
	spine_05 = 7,
	clavicle_l = 8,
	upperarm_l = 9,
	lowerarm_l = 10,
	Hand_L = 11,
	index_metacarpal_l = 12,
	index_01_l = 13,
	index_02_l = 14,
	index_03_l = 15,
	middle_metacarpal_l = 16,
	middle_01_l = 17,
	middle_02_l = 18,
	middle_03_l = 19,
	pinky_metacarpal_l = 20,
	pinky_01_l = 21,
	pinky_02_l = 22,
	pinky_03_l = 23,
	ring_metacarpal_l = 24,
	ring_01_l = 25,
	ring_02_l = 26,
	ring_03_l = 27,
	thumb_01_l = 28,
	thumb_02_l = 29,
	thumb_03_l = 30,
	weapon_l = 31,
	lowerarm_twist_01_l = 32,
	lowerarm_twist_02_l = 33,
	upperarm_twist_01_l = 34,
	upperarm_twist_02_l = 35,
	clavicle_r = 36,
	upperarm_r = 37,
	lowerarm_r = 38,
	hand_r = 39,
	index_metacarpal_r = 40,
	index_01_r = 41,
	index_02_r = 42,
	index_03_r = 43,
	middle_metacarpal_r = 44,
	middle_01_r = 45,
	middle_02_r = 46,
	middle_03_r = 47,
	pinky_metacarpal_r = 48,
	pinky_01_r = 49,
	pinky_02_r = 50,
	pinky_03_r = 51,
	ring_metacarpal_r = 52,
	ring_01_r = 53,
	ring_02_r = 54,
	ring_03_r = 55,
	thumb_01_r = 56,
	thumb_02_r = 57,
	thumb_03_r = 58,
	weapon_r = 59,
	lowerarm_twist_01_r = 60,
	lowerarm_twist_02_r = 61,
	upperarm_twist_01_r = 62,
	upperarm_twist_02_r = 63,
	neck_01 = 64,
	neck_02 = 65,
	HEAD = 66,
	thigh_l = 67,
	calf_l = 68,
	calf_twist_01_l = 69,
	calf_twist_02_l = 70,
	foot_l = 71,
	ball_l = 72,
	thigh_twist_01_l = 73,
	thigh_r = 74,
	calf_r = 75,
	calf_twist_01_r = 76,
	calf_twist_02_r = 77,
	foot_r = 78,
	ball_r = 79,
	thigh_twist_01_r = 80,
	ik_foot_root = 81,
	ik_foot_l = 82,
	ik_foot_r = 83,
	ik_hand_root = 84,
	ik_hand_gun = 85,
	ik_hand_l = 86,
	ik_hand_r = 87,
	spine_05_weapon_r = 88,
	spine_05_weapon_r_ik_hand_gun = 89,
	spine_05_weapon_r_ik_hand_l = 90,
	spine_05_upperarm_r = 91,
	spine_05_upperarm_r_lowerarm_r = 92,
	spine_05_upperarm_r_lowerarm_r_hand_r = 93
};

float bestFOV = 0.f;
FRotator idealAngDelta;

float AimbotFOV = 90;

void AimbotBeginFrame()
{
	bestFOV = AimbotFOV;
	idealAngDelta = { 0,0,0 };
}

//bool W2S(FVector inWorldLocation, FVector2D& outScreenLocation);

bool g_Menu = 1;

bool readA(void* data, uint64_t address, DWORD size)
{
	if (address <= 0x10000 || address >= 0x7FFFFFFFFFF) // 0x7FFFFFFFFFF //|| address >= 0x7FFFFFFFF00
		return false;

	if (IsBadReadPtr((void*)address, (UINT_PTR)size))
		return false;

	memcpy(data, (void*)address, size);
	return true;
}

//string GetObjectFullNameA(UObject* obj);

template <typename T>
T readA(uint64_t address)
{
	T tmp;
	if (readA(&tmp, address, sizeof(tmp)))
		return tmp;
	else
		return T();
}

//uint32_t GetGNameID(UObject* obj)
//{
//	if (!obj)
//		return 0;
//	return readA<uint32_t>((uint64_t)(obj + offsetof(UObject, UObject::name)));
//}
//
//uint64_t GetGNameID64(uint64_t obj)
//{
//	if (!obj)
//		return 0;
//	return readA<uint64_t>(obj + offsetof(UObject, UObject::name));
//}

//using tGetNameFromId = uintptr_t(__fastcall*)(uint64_t* ID, void* buffer);
//tGetNameFromId GGetNameFromId = 0;
//UObject** pGEngine = 0;
//UObject* GEngine = 0;
tGetBoneMatrix GGetBoneMatrix = 0;
//FVector BoneToWorld(Bones boneid, uint64_t mesh);

FVector GetBone3D(UObject* _this, int bone)
{
	//return BoneToWorld((Bones)bone, (uint64_t)_this);

	//FMatrix vMatrix;
	//spoof_call(g_pSpoofGadget, GGetBoneMatrix, _this, &vMatrix, bone);
	//return vMatrix.WPlane;
}

bool B2S(UObject* _this, int bone, FVector2D& outScrLoc)
{
	FVector tmp = GetBone3D(_this, bone);
	//return W2S(tmp, outScrLoc);
}

//wstring GetGNameByIdW(uint64_t id)
//{
//	if (!id || id >= 1000000)
//		return E(L"None_X0");
//
//	static wchar_t buff[0x10000];
//	_ZeroMemory(buff, sizeof(buff));
//
//	auto v47 = spoof_call(g_pSpoofGadget, GGetNameFromId, &id, (void*)buff);
//	if (IsBadReadPtr((void*)v47, 0x8))
//	{
//		//dprintf(E("Getgnbyid bad result"));
//		return E(L"None_X1");
//	}
//	if (v47 && *((DWORD*)v47 + 2))
//	{
//		//dprintf(E("Getgnbyid gud result"));
//		return *(const wchar_t**)v47;
//	}
//	else
//	{
//		//dprintf(E("Getgnbyid bad result #2"));
//		return E(L"None_X2");
//	}
//}
//
//string GetGNameByIdA(uint64_t id)
//{
//	auto str = GetGNameByIdW(id);
//	//dprintf(E("123234434"));
//	return WideToAnsi(str.c_str());
//}

//void PrintNames(int end)
//{
//	if (end == 0)
//		end = 500000;
//
//	dprintf(E("Looping through names.."));
//	for (int i = 0; i < end; i++)
//	{
//		auto name = GetGNameByIdA(i);
//		dprintf(E("[%d] -> %s"), i, name.c_str());
//	}
//	dprintf(E("Done.."));
//}

//wstring GetObjectNameW(UObject* obj);
//
//string GetObjectNameA(UObject* obj)
//{
//	auto name = GetObjectNameW(obj);
//	return WideToAnsi(name.c_str());
//}

void GetAll(UObject* _this, std::vector<UObject*>* memes)
{
	memes->push_back(_this);

	if (!((UStruct*)_this)->Children)
		return;

	//dprintf("2");

	int cnt = 0;
	auto child = readA<UStruct*>((uint64_t)_this + offsetof(UStruct, UStruct::Children));
	//dprintf("3");
	for (; child != nullptr; child = readA<UStruct*>((uintptr_t)child + offsetof(UField, Next)))
	{
		if (cnt >= 100)
			return;
		//dprintf("4X");
		if (IsBadReadPtr(child, 0x8) || IsBadReadPtr(child->Class, 0x8))
			return;
		memes->push_back(child);
		cnt++;
	}
	//dprintf("5");
}

//void PrintObjects(int max)
//{
//	dprintf(E("Looping through objects..."));
//
//	if (max == 0)
//		max = GObjects->Num();
//
//	for (int i = 0; i < max; i++)
//	{
//		auto objItem = GObjects->GetById(i);
//
//		dprintf(E(" Obj #%d"), i);
//
//		if (!objItem || !objItem->Object)
//		{
//			continue;
//		}
//
//		auto obj_x = objItem->Object;
//
//		vector<UObject*> objs;
//		GetAll(obj_x, &objs);
//
//		for (int x = 0; x < objs.size(); x++)
//		{
//			auto obj = objs[x];
//			auto name = GetObjectFullNameA(obj);
//			dprintf(E("\t %d -> 0x%p -> %s"), x, obj, name.c_str());
//		}
//	}
//	dprintf(E("Done.."));
//}

uintptr_t GetGObjects()
{
	auto ss = FindPattern(E("48 8B 05 ? ? ? ? 48 8B 0C C8 48 8B 04 D1"));
	ss = (uintptr_t)RVA(ss, 7);
	if (!ss)
		return 0;

	ss += 7;

	return (ss + 7 + *(int32_t*)(ss + 3));
}

uintptr_t ResolveRelativeReference(uintptr_t address, uint32_t offset = 0)
{
	if (address)
	{
		address += offset;

		if (*reinterpret_cast<BYTE*>(address) == 0xE9 || *reinterpret_cast<BYTE*>(address) == 0xE8)
		{
			auto displacement = *reinterpret_cast<uint32_t*>(address + 1);
			auto ret = address + displacement + 5;

			if (displacement & 0x80000000)
				ret -= 0x100000000;

			return ret;
		}
		else if (*reinterpret_cast<BYTE*>(address + 1) == 0x05)
		{
			auto displacement = *reinterpret_cast<uint32_t*>(address + 2);
			auto ret = address + displacement + 6;

			if (displacement & 0x80000000)
				ret -= 0x100000000;

			return ret;
		}
		else
		{
			auto displacement = *reinterpret_cast<uint32_t*>(address + 3);
			auto ret = address + displacement + 3 + sizeof(uint32_t);

			if (displacement & 0x80000000)
				ret -= 0x100000000;

			return ret;
		}
	}
	else
	{
		return 0;
	}
}

uint64_t SigScanSimple(uint64_t base, uint32_t size, PBYTE sig, int len)
{
	for (size_t i = 0; i < size; i++)
		if (MemoryBlocksEqual((void*)(base + i), sig, len))
			return base + i;
	return NULL;
}

UINT32 UWorldOffset = 0x9864730;

typedef void(*tUE4ProcessEvent)(UObject*, UObject*, void*);

tUE4ProcessEvent GoPE = 0;

template<typename Fn>
inline Fn GetVFunction(const void* instance, std::size_t index)
{
	auto vtable = *reinterpret_cast<const void***>(const_cast<void*>(instance));
	return reinterpret_cast<Fn>(vtable[index]);
}

//wstring GetObjectNameW(UObject* obj)
//{
//	if (!obj)
//		return E(L"None_X4");
//
//	if (IsBadReadPtr(obj, sizeof(UObject)))
//		return E(L"None_X5");
//
//	auto id = obj->name.ComparisonIndex;
//	return GetGNameByIdW(id);
//}

uint32_t GetVtableSize(void* object)
{
	auto vtable = *(void***)(object);
	int i = 0;

	for (; vtable[i]; i++)
		__noop();

	return i;
}

void freememory(uintptr_t Ptr, int Length = 8)
{
	VirtualFree((LPVOID)Ptr, (SIZE_T)0, (DWORD)MEM_RELEASE);
}

template <typename T>
std::string GetObjectName(T Object, bool GetOuter = false)
{
	static uintptr_t GetObjectName;

	if (!GetObjectName)
		GetObjectName = FindPattern(E("48 89 5C 24 ? 48 89 74 24 ? 55 57 41 56 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 45 33 F6 48 8B F2 44 39 71 04 0F 85 ? ? ? ? 8B 19 0F B7 FB E8 ? ? ? ? 8B CB 48 8D 54 24"));

	auto UFUNGetObjectNameByIndex = reinterpret_cast<FString * (__fastcall*)(DWORD*, FString*)>(GetObjectName);

	DWORD ObjectIndex = *(DWORD*)((PBYTE)Object + 0x18);
	if (!ObjectIndex || ObjectIndex >= MAXDWORD) return xorstr_("");

	if (!GetOuter)
	{
		FString A;
		std::string B = "";
		UFUNGetObjectNameByIndex(&ObjectIndex, &A);
		B = A.ToString();
		return B;
	}

	std::string Ret;

	UObject* Object_ = (UObject*)Object;
	for (int i = 0; Object_; Object_ = Object_->Outer, i++)
	{
		FString Result;

		UFUNGetObjectNameByIndex(&ObjectIndex, &Result);

		std::string tmp = Result.ToString();

		if (tmp.c_str() == 0) return xorstr_("");

		freememory((__int64)Result.c_str(), tmp.size() + 8);

		char return_string[1024] = {};
		for (size_t i = 0; i < tmp.size(); i++)
		{
			return_string[i] += tmp[i];
		}

		Ret = return_string + std::string(i > 0 ? "." : "") + Ret;
	}

	return Ret;
}

std::vector<void*>* GHookedObjects;

D3DMATRIX Matrix(FRotator rot, FVector origin = { 0, 0, 0 })
{
	float radPitch = rot.Pitch * M_PI / 180.f;
	float radYaw = rot.Yaw * M_PI / 180.f;
	float radRoll = rot.Roll * M_PI / 180.f;

	float SP = sin(radPitch);
	float CP = cos(radPitch);
	float SY = sin(radYaw);
	float CY = cos(radYaw);
	float SR = sin(radRoll);
	float CR = cos(radRoll);

	D3DMATRIX matrix;
	matrix.m[0][0] = CP * CY;
	matrix.m[0][1] = CP * SY;
	matrix.m[0][2] = SP;
	matrix.m[0][3] = 0.f;

	matrix.m[1][0] = SR * SP * CY - CR * SY;
	matrix.m[1][1] = SR * SP * SY + CR * CY;
	matrix.m[1][2] = -SR * CP;
	matrix.m[1][3] = 0.f;

	matrix.m[2][0] = -(CR * SP * CY + SR * SY);
	matrix.m[2][1] = CY * SR - CR * SP * SY;
	matrix.m[2][2] = CR * CP;
	matrix.m[2][3] = 0.f;

	matrix.m[3][0] = origin.X;
	matrix.m[3][1] = origin.Y;
	matrix.m[3][2] = origin.Z;
	matrix.m[3][3] = 1.f;

	return matrix;
}

bool IsObjectHooked(void* obj)
{
	for (auto x : *GHookedObjects)
	{
		if (x == obj)
			return true;
	}

	return false;
}

void SwapVtable(void* obj, uint32_t index, void* hook)
{
	if (!IsObjectHooked(obj))
	{
		auto currVt = *(void**)(obj);
		auto size = GetVtableSize(obj);
		dprintf(E("VT has %d functions"), size);
		auto newVt = new uintptr_t[size];
		memcpy(newVt, currVt, size * 0x8);
		newVt[index] = (uintptr_t)hook;
		*(uintptr_t**)(obj) = newVt;
		GHookedObjects->push_back(obj);
	}
	else
	{
		dprintf(E("0x%p is already hooked.."), obj);
	}
}

class UFunction : public UStruct
{
public:
	int32_t FunctionFlags; //0x0088
	int16_t RepOffset; //0x008C
	int8_t NumParms; //0x008E
	char pad_0x008F[0x1]; //0x008F
	int16_t ParmsSize; //0x0090
	int16_t ReturnValueOffset; //0x0092
	int16_t RPCId; //0x0094
	int16_t RPCResponseId; //0x0096
	class UProperty* FirstPropertyToInit; //0x0098
	UFunction* EventGraphFunction; //0x00A0
	int32_t EventGraphCallOffset; //0x00A8
	char pad_0x00AC[0x4]; //0x00AC
	void* Func; //0x00B0
};

UFunction* S_ReceiveDrawHUD()
{
	static UFunction* ass = 0;
	if (!ass)
		ass = UObject::FindObject<UFunction>(xorstr_("Function Engine.HUD.ReceiveDrawHUD"));
	return ass;
}

UObject* GHUD;
UObject* GCanvas;

UFont* GetFont()
{
	static UFont* font = 0;
	if (!font)
	{
	*dprintf(E("GetFont init: GEngine: %s"), GetObjectName(GEngine).c_str());
		font = *(UObject**)((uintptr_t)(GEngine)+DGOffset_Font);
		dpritf(E("GetFont init: font: %s"), GetObjectName(font).c_str());

		font = UObject::FindObject<UFont>("Font Roboto.Roboto");
	}

	return font;
}

TArray<UObject*>* GActorArray = 0;

struct UCanvas_K2_DrawText_Params
{
	class UFont* RenderFont;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     RenderText;                                               // (Parm, ZeroConstructor)
	struct FVector2D                                   ScreenPosition;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	struct FVector2D                                   Scale;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                RenderColor;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              Kerning;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                ShadowColor;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	struct FVector2D                                   ShadowOffset;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bCentreX;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bCentreY;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bOutlined;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                OutlineColor;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};

void ProcessEvent(UObject* obj, class UFunction* function, void* parms)
{
	if (!function)
		return;
	auto func = GetVFunction<void(__thiscall*)(UObject*, class UFunction*, void*)>(obj, PROCESSEVENT_INDEX);

	func(obj, function, parms);
}

void Render_Toggle(FVector2D& loc_ref, const wchar_t* name, bool* on);

FVector GPawnLocation;

void K2_DrawText(UObject* _this, class UFont* RenderFont, const class FString& RenderText, const struct FVector2D& ScreenPosition, const struct FVector2D& Scale, const struct FLinearColor& RenderColor, float Kerning, const struct FLinearColor& ShadowColor, const struct FVector2D& ShadowOffset, bool bCentreX, bool bCentreY, bool bOutl, const struct FLinearColor& OutlineColor)
{
	static UFunction* fn = nullptr;

	if (!fn)
		fn = UObject::FindObject<UFunction>(xorstr_("Function Engine.Canvas.K2_DrawText"));

	UCanvas_K2_DrawText_Params params;
	params.RenderFont = RenderFont;
	params.RenderText = RenderText;
	params.ScreenPosition = ScreenPosition;
	params.Scale = Scale;
	params.RenderColor = RenderColor;
	params.Kerning = Kerning;
	params.ShadowColor = ShadowColor;
	params.ShadowOffset = ShadowOffset;
	params.bCentreX = bCentreX;
	params.bCentreY = bCentreY;
	params.bOutlined = bOutl;
	params.OutlineColor = OutlineColor;

	ProcessEvent(_this, fn, &params);
}

namespace G
{
	bool EspWeapon = true;
	bool RefreshEach1s = true;
	bool Snaplines = false;
	bool CornerBox = true;
	float CornerBoxThicc = 1.7f;
	float RedDistance = 40.0f;
	float CornerBoxScale = 0.20;
	bool PunktierSnaplines = true;
	float PunktierPower = 16.6f;
	bool SnaplinesIn50m = false;
	bool Baim = true;
	float SkeletonThicc = 1.0f;
	//bool AimbotUseRightButton = false;
	float PlayerBoxThicc = 1.0f;
	bool WeakSpotAimbot = true;
	bool ProjectileTpEnable = true;
	bool ShowTimeConsumed = true;
	float Smooth = 0.3;
	bool CollisionDisableOnAimbotKey = true;
	bool FlyingCars = false;
	bool UseEngineW2S = true;
	bool Chests = true;
	bool TpPrisonersEnable = true;
	bool DrawSelf = true;
	bool LootWeapons = true;
	int JumpScale = 1;
	bool Projectiles = true;
	int TpTimeInterval = 250;
	float LootTier = 1;
	bool LootMelee = true;
	bool bAllowedTp = true;
	bool Outline = true;
	bool Skeletons = true;
	bool EspPlayerName = true;
	bool EspLoot = true;
	bool EspRifts = false;
	bool EspSupplyDrops = false;
	bool EspTraps = false;
	bool EspVehicles = false;
	bool Healthbars = true;
	bool LootHeals = true;
	bool LootAttachments = true;
	bool LootAmmo = true;
	bool EspBox = true;
	bool LootEquipment = true;
	bool TpLootAndCorpses = true;
	bool TpZombiesEnable = true;
	bool EnableHack = true;
	bool LootFood = true;
	bool LootWear = true;
	bool TpAnimalsEnable = true;
	bool TpSentriesEnable = true;
	uintptr_t MmBase;
	bool TimeSpeedhackEnable = false;
	bool MovSpeedhackEnable = true;
	int MovSpeedhackScale = 2;
	bool AimbotEnable = true;
	bool EspSentries = true;
	bool EspZombies = false;
	bool EspPlayers = true;
	bool EspCorpses = true;
	bool EspAnimals = true;
	bool EspDrones = true;
	float RenderDist = 200;
	float ChestsRdist = 200;
	UObject* Closest;
	bool AimbotTargetPlayers = true;
	bool AimbotTargetZombies;
	float LootRenderDist = 200;
	int IconScale = 21;
	bool LootEnable = false;
	bool AimbotTargetDrones;
	bool OnlyWeapons = true;
	uintptr_t MmSize;
	bool AimbotTargetAnimals;
	uintptr_t CurrentTime;
	bool AimbotTargetSentries;
	int ItemRarityLevel = 7;
	UObject* CameraManager;
	uintptr_t LastTimePEHookCalled;
	bool NoRecoil = true;
	bool InfAmmo = true;
}

FVector2D K2_StrLen(UObject* canvas, class UObject* RenderFont, const struct FString& RenderText)
{
	static UFunction* fn = 0; if (!fn) fn = UObject::FindObject<UFunction>(xorstr_("Function Engine.Canvas.K2_StrLen"));

	struct
	{
		class UObject* RenderFont;
		struct FString                 RenderText;
		struct FVector2D               ReturnValue;
	} params;

	params.RenderFont = RenderFont;
	params.RenderText = RenderText;

	ProcessEvent(canvas, fn, &params);

	return params.ReturnValue;
}


inline D3DMATRIX matrix(FRotator rot, FVector origin = FVector(0, 0, 0))
{

	float radPitch = (rot.Pitch * float(M_PI) / 180.f);
	float radYaw = (rot.Yaw * float(M_PI) / 180.f);
	float radRoll = (rot.Roll * float(M_PI) / 180.f);

	float SP = sinf(radPitch);
	float CP = cosf(radPitch);
	float SY = sinf(radYaw);
	float CY = cosf(radYaw);
	float SR = sinf(radRoll);
	float CR = cosf(radRoll);

	D3DMATRIX matrix;
	matrix.m[0][0] = CP * CY;
	matrix.m[0][1] = CP * SY;
	matrix.m[0][2] = SP;
	matrix.m[0][3] = 0.f;

	matrix.m[1][0] = SR * SP * CY - CR * SY;
	matrix.m[1][1] = SR * SP * SY + CR * CY;
	matrix.m[1][2] = -SR * CP;
	matrix.m[1][3] = 0.f;

	matrix.m[2][0] = -(CR * SP * CY + SR * SY);
	matrix.m[2][1] = CY * SR - CR * SP * SY;
	matrix.m[2][2] = CR * CP;
	matrix.m[2][3] = 0.f;

	matrix.m[3][0] = origin.X;
	matrix.m[3][1] = origin.Y;
	matrix.m[3][2] = origin.Z;
	matrix.m[3][3] = 1.f;

	return matrix;
}

FVector GetCameraLocation(UObject* _this)
{
	static UFunction* fn = 0; if (!fn) fn = UObject::FindObject<UFunction>(xorstr_("Function Engine.Controller.LineOfSightTo"));

	struct
	{
		struct FVector ReturnValue;
	} params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

float GetFOVAngle(UObject* _this)
{
	static UFunction* fn = 0; if (!fn) fn = UObject::FindObject<UFunction>(xorstr_("Function Engine.PlayerCameraManager.GetFOVAngle"));

	struct
	{
		float ReturnValue;
	} params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

inline FVector xWorldToScreen(FVector worldloc, FRotator camrot)
{
	FVector screenloc = FVector(0, 0, 0);
	FRotator rot = camrot;

	D3DMATRIX tempMatrix = matrix(rot);
	FVector vAxisX, vAxisY, vAxisZ;

	vAxisX = FVector(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
	vAxisY = FVector(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
	vAxisZ = FVector(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

	FVector vDelta = worldloc - GetCameraLocation((UObject*)GCanvas);
	FVector vTransformed = FVector(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

	float fov_angle = GetFOVAngle((UObject*)GCanvas);
	float ScreenCenterX = static_cast<float>(g_ScreenWidth) / 2.0f;
	float ScreenCenterY = static_cast<float>(g_ScreenHeight) / 2.0f;

	if (vTransformed.Z < 1.f || mytan(fov_angle * (float)M_PI / 360.f) == 0.f) return FVector(0, 0, 0);

	screenloc.X = ScreenCenterX + vTransformed.X * (ScreenCenterX / mytan(fov_angle * (float)M_PI / 360.f)) / vTransformed.Z;
	screenloc.Y = ScreenCenterY - vTransformed.Y * (ScreenCenterX / mytan(fov_angle * (float)M_PI / 360.f)) / vTransformed.Z;

	return screenloc;

}

/*
bool xWorldToScreen(FVector WorldLocation, FVector2D& outLocScreen)
{

	if (WorldLocation.Size() == 0.0f)
		return false;

	FVector2D Screenlocation;

	FRotator rot = camrot;
	D3DMATRIX tempMatrix = matrix(rot);

	auto vAxisX = FVector(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
	auto vAxisY = FVector(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
	auto vAxisZ = FVector(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

	FVector vDelta = WorldLocation - CameraCacheL->Location;
	FVector vTransformed = FVector(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

	if (vTransformed.Z < 1.f)
		vTransformed.Z = 1.f;

	float FovAngle = CameraCacheL->FOV;
	float ScreenCenterX = static_cast<float>(g_ScreenWidth) / 2.0f;
	float ScreenCenterY = static_cast<float>(g_ScreenHeight) / 2.0f;
	auto f = (ScreenCenterX / mytan(FovAngle * M_PI / 360.0f));

	Screenlocation.X = ScreenCenterX + vTransformed.X * f / vTransformed.Z;
	Screenlocation.Y = ScreenCenterY - vTransformed.Y * f / vTransformed.Z;

	outLocScreen = Screenlocation;

	return true;
}

void xDrawText(const wchar_t* str, FVector2D pos, FLinearColor clr, float box_center_offset = 0.0f)
{
	auto font = GetFont();

	auto name_w = K2_StrLen(GCanvas, (UObject*)font, str).X;

	if (box_center_offset != -1.0f)
	{
		pos.X -= name_w / 2;
		pos.X += box_center_offset;
	}
	else
	{
		pos.X -= name_w;
	}

	K2_DrawText(GCanvas, font, str, pos, FVector2D(1.0f, 1.0f), clr, 1.0f, FLinearColor(0, 0, 0, 255), FVector2D(), false, false, G::Outline, FLinearColor(0, 0, 0, 1.0f));
}

uintptr_t GOffset_Levels = 0;
uintptr_t GOffset_Actors = 0;
uintptr_t GOffset_RootComponent = 0;
uintptr_t GOffset_ComponentLocation;

UObject* SC_FortPlayerPawn()
{
	static UClass* obj = 0;
	if (!obj)
		obj = UObject::FindObject<UClass>(xorstr_("Class FortniteGame.FortPlayerPawnAthena"));
	return obj;
}

bool ProjectWorldLocationToScreen(UObject* _this, const struct FVector& WorldLocation, bool bPlayerViewportRelative, struct FVector2D* ScreenLocation)
{
	static UFunction* fn = 0; if (!fn) fn = UObject::FindObject<UFunction>(xorstr_("Function Engine.PlayerController.ProjectWorldLocationToScreen"));

	struct
	{
		struct FVector                 WorldLocation;
		struct FVector2D               ScreenLocation;
		bool                           bPlayerViewportRelative;
		bool                           ReturnValue;
	} params;

	params.WorldLocation = WorldLocation;
	params.bPlayerViewportRelative = bPlayerViewportRelative;

	ProcessEvent(_this, fn, &params);

	if (ScreenLocation != nullptr)
		*ScreenLocation = params.ScreenLocation;

	return params.ReturnValue;
}

FCameraCacheEntry* GCameraCache = nullptr;

bool Object_IsA(UObject* obj, UObject* cmp);

float GetDistanceTo(UObject* _this, class UObject* OtherActor)
{
	static UFunction* fn = 0; if (!fn) fn = UObject::FindObject<UFunction>(xorstr_("Function Engine.Actor.GetDistanceTo"));

	struct
	{
		class UObject* OtherActor;
		float                          ReturnValue;
	} params;

	params.OtherActor = OtherActor;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

int __forceinline GetDistanceMeters(FVector& location)
{
	return (int)(location.DistanceFrom(GPawnLocation) / 100);
}

int Dist(UObject* other)
{
	if (!GPawn)
		return 0;

	return (int)(GetDistanceTo((UObject*)GPawn, other) / 100);
}

bool LineOfSightTo(UObject* _this, class UObject* Other, const struct FVector& ViewPoint, bool bAlternateChecks)
{
	static UFunction* fn = 0; if (!fn) fn = UObject::FindObject<UFunction>(xorstr_("Function Engine.Controller.LineOfSightTo"));

	struct
	{
		class UObject* Other;
		struct FVector                 ViewPoint;
		bool                           bAlternateChecks;
		bool                           ReturnValue;
	} params;

	params.Other = Other;
	params.ViewPoint = ViewPoint;
	params.bAlternateChecks = bAlternateChecks;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

uintptr_t GOffset_BlockingHit;
uintptr_t GOffset_PlayerCameraManager;
uintptr_t GOffset_TeamIndex = 0;

// ScriptStruct Engine.HitResult
// 0x0088

// Enum Engine.EDrawDebugTrace
enum class EDrawDebugTrace : uint8_t
{
	EDrawDebugTrace__None = 0,
	EDrawDebugTrace__ForOneFrame = 1,
	EDrawDebugTrace__ForDuration = 2,
	EDrawDebugTrace__Persistent = 3,
	EDrawDebugTrace__EDrawDebugTrace_MAX = 4
};


// Enum Engine.ETraceTypeQuery
enum class ETraceTypeQuery : uint8_t
{
	TraceTypeQuery1 = 0,
	TraceTypeQuery2 = 1,
	TraceTypeQuery3 = 2,
	TraceTypeQuery4 = 3,
	TraceTypeQuery5 = 4,
	TraceTypeQuery6 = 5,
	TraceTypeQuery7 = 6,
	TraceTypeQuery8 = 7,
	TraceTypeQuery9 = 8,
	TraceTypeQuery10 = 9,
	TraceTypeQuery11 = 10,
	TraceTypeQuery12 = 11,
	TraceTypeQuery13 = 12,
	TraceTypeQuery14 = 13,
	TraceTypeQuery15 = 14,
	TraceTypeQuery16 = 15,
	TraceTypeQuery17 = 16,
	TraceTypeQuery18 = 17,
	TraceTypeQuery19 = 18,
	TraceTypeQuery20 = 19,
	TraceTypeQuery21 = 20,
	TraceTypeQuery22 = 21,
	TraceTypeQuery23 = 22,
	TraceTypeQuery24 = 23,
	TraceTypeQuery25 = 24,
	TraceTypeQuery26 = 25,
	TraceTypeQuery27 = 26,
	TraceTypeQuery28 = 27,
	TraceTypeQuery29 = 28,
	TraceTypeQuery30 = 29,
	TraceTypeQuery31 = 30,
	TraceTypeQuery32 = 31,
	TraceTypeQuery_MAX = 32,
	ETraceTypeQuery_MAX = 33
};

// Function Engine.KismetSystemLibrary.LineTraceSingle
struct UKismetSystemLibrary_LineTraceSingle_Params
{
	class UObject* WorldContextObject;                                       // (Parm, ZeroConstructor, IsPlainOldData)
	struct FVector                                     Start;                                                    // (ConstParm, Parm, IsPlainOldData)
	struct FVector                                     End;                                                      // (ConstParm, Parm, IsPlainOldData)
	TEnumAsByte<ETraceTypeQuery>                       TraceChannel;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bTraceComplex;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	TArray<class AActor*>                              ActorsToIgnore;                                           // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	TEnumAsByte<EDrawDebugTrace>                       DrawDebugType;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	struct FHitResult                                  OutHit;                                                   // (Parm, OutParm, IsPlainOldData)
	bool                                               bIgnoreSelf;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                TraceColor;                                               // (Parm, IsPlainOldData)
	struct FLinearColor                                TraceHitColor;                                            // (Parm, IsPlainOldData)
	float                                              DrawTime;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

bool LineTraceSingle(UObject* k2, class UObject* WorldContextObject, const struct FVector& Start, const struct FVector& End, TEnumAsByte<ETraceTypeQuery> TraceChannel, bool bTraceComplex, TArray<class AActor*> ActorsToIgnore, TEnumAsByte<EDrawDebugTrace> DrawDebugType, bool bIgnoreSelf, const struct FLinearColor& TraceColor, const struct FLinearColor& TraceHitColor, float DrawTime, struct FHitResult* OutHit)
{
	static UFunction* fn = nullptr;
	if (!fn) fn = UObject::FindObject<UFunction>(xorstr_("Function Engine.KismetSystemLibrary.LineTraceSingle"));

	UKismetSystemLibrary_LineTraceSingle_Params params;
	params.WorldContextObject = WorldContextObject;
	params.Start = Start;
	params.End = End;
	params.TraceChannel = TraceChannel;
	params.bTraceComplex = bTraceComplex;
	params.ActorsToIgnore = ActorsToIgnore;
	params.DrawDebugType = DrawDebugType;
	params.bIgnoreSelf = bIgnoreSelf;
	params.TraceColor = TraceColor;
	params.TraceHitColor = TraceHitColor;
	params.DrawTime = DrawTime;

	auto flags = fn->FunctionFlags;

	ProcessEvent(k2, fn, &params);

	fn->FunctionFlags = flags;

	if (OutHit != nullptr)
		*OutHit = params.OutHit;

	return params.ReturnValue;
}


bool TraceVisibility(UObject* mesh, FVector& p1, FVector& p2)
{
	FVector hitLoc;
	FVector hitNormal;
	static FHitResult kek;
	FName boneName;
	return VisibilityCheck(mesh, p1, p2, true, false, &hitLoc, &hitNormal, &boneName, &kek);
}

bool IsVisible(UObject* actor)
{
	return LineOfSightTo((UObject*)GController, actor, FVector{ 0, 0, 0 }, true);
}

namespace Colors
{
	FLinearColor AliceBlue = { 0.941176534f, 0.972549081f, 1.000000000f, 1.000000000f };
	FLinearColor AntiqueWhite = { 0.980392218f, 0.921568692f, 0.843137324f, 1.000000000f };
	FLinearColor Aqua = { 0.000000000f, 1.000000000f, 1.000000000f, 1.000000000f };
	FLinearColor Aquamarine = { 0.498039246f, 1.000000000f, 0.831372619f, 1.000000000f };
	FLinearColor Azure = { 0.941176534f, 1.000000000f, 1.000000000f, 1.000000000f };
	FLinearColor Beige = { 0.960784376f, 0.960784376f, 0.862745166f, 1.000000000f };
	FLinearColor Bisque = { 1.000000000f, 0.894117713f, 0.768627524f, 1.000000000f };
	FLinearColor Black = { 0.000000000f, 0.000000000f, 0.000000000f, 1.000000000f };
	FLinearColor BlanchedAlmond = { 1.000000000f, 0.921568692f, 0.803921640f, 1.000000000f };
	FLinearColor Blue = { 0.000000000f, 0.000000000f, 1.000000000f, 1.000000000f };
	FLinearColor BlueViolet = { 0.541176498f, 0.168627456f, 0.886274576f, 1.000000000f };
	FLinearColor Brown = { 0.647058845f, 0.164705887f, 0.164705887f, 1.000000000f };
	FLinearColor BurlyWood = { 0.870588303f, 0.721568644f, 0.529411793f, 1.000000000f };
	FLinearColor CadetBlue = { 0.372549027f, 0.619607866f, 0.627451003f, 1.000000000f };
	FLinearColor Chartreuse = { 0.498039246f, 1.000000000f, 0.000000000f, 1.000000000f };
	FLinearColor Chocolate = { 0.823529482f, 0.411764741f, 0.117647067f, 1.000000000f };
	FLinearColor Coral = { 1.000000000f, 0.498039246f, 0.313725501f, 1.000000000f };
	FLinearColor CornflowerBlue = { 0.392156899f, 0.584313750f, 0.929411829f, 1.000000000f };
	FLinearColor Cornsilk = { 1.000000000f, 0.972549081f, 0.862745166f, 1.000000000f };
	FLinearColor Crimson = { 0.862745166f, 0.078431375f, 0.235294133f, 1.000000000f };
	FLinearColor Cyan = { 0.000000000f, 1.000000000f, 1.000000000f, 1.000000000f };
	FLinearColor DarkBlue = { 0.000000000f, 0.000000000f, 0.545098066f, 1.000000000f };
	FLinearColor DarkCyan = { 0.000000000f, 0.545098066f, 0.545098066f, 1.000000000f };
	FLinearColor DarkGoldenrod = { 0.721568644f, 0.525490224f, 0.043137256f, 1.000000000f };
	FLinearColor DarkGray = { 0.662745118f, 0.662745118f, 0.662745118f, 1.000000000f };
	FLinearColor DarkGreen = { 0.000000000f, 0.392156899f, 0.000000000f, 1.000000000f };
	FLinearColor DarkKhaki = { 0.741176486f, 0.717647076f, 0.419607878f, 1.000000000f };
	FLinearColor DarkMagenta = { 0.545098066f, 0.000000000f, 0.545098066f, 1.000000000f };
	FLinearColor DarkOliveGreen = { 0.333333343f, 0.419607878f, 0.184313729f, 1.000000000f };
	FLinearColor DarkOrange = { 1.000000000f, 0.549019635f, 0.000000000f, 1.000000000f };
	FLinearColor DarkOrchid = { 0.600000024f, 0.196078449f, 0.800000072f, 1.000000000f };
	FLinearColor DarkRed = { 0.545098066f, 0.000000000f, 0.000000000f, 1.000000000f };
	FLinearColor DarkSalmon = { 0.913725555f, 0.588235319f, 0.478431404f, 1.000000000f };
	FLinearColor DarkSeaGreen = { 0.560784340f, 0.737254918f, 0.545098066f, 1.000000000f };
	FLinearColor DarkSlateBlue = { 0.282352954f, 0.239215702f, 0.545098066f, 1.000000000f };
	FLinearColor DarkSlateGray = { 0.184313729f, 0.309803933f, 0.309803933f, 1.000000000f };
	FLinearColor DarkTurquoise = { 0.000000000f, 0.807843208f, 0.819607913f, 1.000000000f };
	FLinearColor DarkViolet = { 0.580392182f, 0.000000000f, 0.827451050f, 1.000000000f };
	FLinearColor DeepPink = { 1.000000000f, 0.078431375f, 0.576470613f, 1.000000000f };
	FLinearColor DeepSkyBlue = { 0.000000000f, 0.749019623f, 1.000000000f, 1.000000000f };
	FLinearColor DimGray = { 0.411764741f, 0.411764741f, 0.411764741f, 1.000000000f };
	FLinearColor DodgerBlue = { 0.117647067f, 0.564705908f, 1.000000000f, 1.000000000f };
	FLinearColor Firebrick = { 0.698039234f, 0.133333340f, 0.133333340f, 1.000000000f };
	FLinearColor FloralWhite = { 1.000000000f, 0.980392218f, 0.941176534f, 1.000000000f };
	FLinearColor ForestGreen = { 0.133333340f, 0.545098066f, 0.133333340f, 1.000000000f };
	FLinearColor Fuchsia = { 1.000000000f, 0.000000000f, 1.000000000f, 1.000000000f };
	FLinearColor Gainsboro = { 0.862745166f, 0.862745166f, 0.862745166f, 1.000000000f };
	FLinearColor GhostWhite = { 0.972549081f, 0.972549081f, 1.000000000f, 1.000000000f };
	FLinearColor Gold = { 1.000000000f, 0.843137324f, 0.000000000f, 1.000000000f };
	FLinearColor Goldenrod = { 0.854902029f, 0.647058845f, 0.125490203f, 1.000000000f };
	FLinearColor Gray = { 0.501960814f, 0.501960814f, 0.501960814f, 1.000000000f };
	FLinearColor Green = { 0.000000000f, 0.501960814f, 0.000000000f, 1.000000000f };
	FLinearColor GreenYellow = { 0.678431392f, 1.000000000f, 0.184313729f, 1.000000000f };
	FLinearColor Honeydew = { 0.941176534f, 1.000000000f, 0.941176534f, 1.000000000f };
	FLinearColor HotPink = { 1.000000000f, 0.411764741f, 0.705882370f, 1.000000000f };
	FLinearColor IndianRed = { 0.803921640f, 0.360784322f, 0.360784322f, 1.000000000f };
	FLinearColor Indigo = { 0.294117659f, 0.000000000f, 0.509803951f, 1.000000000f };
	FLinearColor Ivory = { 1.000000000f, 1.000000000f, 0.941176534f, 1.000000000f };
	FLinearColor Khaki = { 0.941176534f, 0.901960850f, 0.549019635f, 1.000000000f };
	FLinearColor Lavender = { 0.901960850f, 0.901960850f, 0.980392218f, 1.000000000f };
	FLinearColor LavenderBlush = { 1.000000000f, 0.941176534f, 0.960784376f, 1.000000000f };
	FLinearColor LawnGreen = { 0.486274540f, 0.988235354f, 0.000000000f, 1.000000000f };
	FLinearColor LemonChiffon = { 1.000000000f, 0.980392218f, 0.803921640f, 1.000000000f };
	FLinearColor LightBlue = { 0.678431392f, 0.847058892f, 0.901960850f, 1.000000000f };
	FLinearColor LightCoral = { 0.941176534f, 0.501960814f, 0.501960814f, 1.000000000f };
	FLinearColor LightCyan = { 0.878431439f, 1.000000000f, 1.000000000f, 1.000000000f };
	FLinearColor LightGoldenrodYellow = { 0.980392218f, 0.980392218f, 0.823529482f, 1.000000000f };
	FLinearColor LightGreen = { 0.564705908f, 0.933333397f, 0.564705908f, 1.000000000f };
	FLinearColor LightGray = { 0.827451050f, 0.827451050f, 0.827451050f, 1.000000000f };
	FLinearColor LightPink = { 1.000000000f, 0.713725507f, 0.756862819f, 1.000000000f };
	FLinearColor LightSalmon = { 1.000000000f, 0.627451003f, 0.478431404f, 1.000000000f };
	FLinearColor LightSeaGreen = { 0.125490203f, 0.698039234f, 0.666666687f, 1.000000000f };
	FLinearColor LightSkyBlue = { 0.529411793f, 0.807843208f, 0.980392218f, 1.000000000f };
	FLinearColor LightSlateGray = { 0.466666698f, 0.533333361f, 0.600000024f, 1.000000000f };
	FLinearColor LightSteelBlue = { 0.690196097f, 0.768627524f, 0.870588303f, 1.000000000f };
	FLinearColor LightYellow = { 1.000000000f, 1.000000000f, 0.878431439f, 1.000000000f };
	FLinearColor Lime = { 0.000000000f, 1.000000000f, 0.000000000f, 1.000000000f };
	FLinearColor LimeGreen = { 0.196078449f, 0.803921640f, 0.196078449f, 1.000000000f };
	FLinearColor Linen = { 0.980392218f, 0.941176534f, 0.901960850f, 1.000000000f };
	FLinearColor Magenta = { 1.000000000f, 0.000000000f, 1.000000000f, 1.000000000f };
	FLinearColor Maroon = { 0.501960814f, 0.000000000f, 0.000000000f, 1.000000000f };
	FLinearColor MediumAquamarine = { 0.400000036f, 0.803921640f, 0.666666687f, 1.000000000f };
	FLinearColor MediumBlue = { 0.000000000f, 0.000000000f, 0.803921640f, 1.000000000f };
	FLinearColor MediumOrchid = { 0.729411781f, 0.333333343f, 0.827451050f, 1.000000000f };
	FLinearColor MediumPurple = { 0.576470613f, 0.439215720f, 0.858823597f, 1.000000000f };
	FLinearColor MediumSeaGreen = { 0.235294133f, 0.701960802f, 0.443137288f, 1.000000000f };
	FLinearColor MediumSlateBlue = { 0.482352972f, 0.407843173f, 0.933333397f, 1.000000000f };
	FLinearColor MediumSpringGreen = { 0.000000000f, 0.980392218f, 0.603921592f, 1.000000000f };
	FLinearColor MediumTurquoise = { 0.282352954f, 0.819607913f, 0.800000072f, 1.000000000f };
	FLinearColor MediumVioletRed = { 0.780392230f, 0.082352944f, 0.521568656f, 1.000000000f };
	FLinearColor MidnightBlue = { 0.098039225f, 0.098039225f, 0.439215720f, 1.000000000f };
	FLinearColor MintCream = { 0.960784376f, 1.000000000f, 0.980392218f, 1.000000000f };
	FLinearColor MistyRose = { 1.000000000f, 0.894117713f, 0.882353008f, 1.000000000f };
	FLinearColor Moccasin = { 1.000000000f, 0.894117713f, 0.709803939f, 1.000000000f };
	FLinearColor NavajoWhite = { 1.000000000f, 0.870588303f, 0.678431392f, 1.000000000f };
	FLinearColor Navy = { 0.000000000f, 0.000000000f, 0.501960814f, 1.000000000f };
	FLinearColor OldLace = { 0.992156923f, 0.960784376f, 0.901960850f, 1.000000000f };
	FLinearColor Olive = { 0.501960814f, 0.501960814f, 0.000000000f, 1.000000000f };
	FLinearColor OliveDrab = { 0.419607878f, 0.556862772f, 0.137254909f, 1.000000000f };
	FLinearColor Orange = { 1.000000000f, 0.647058845f, 0.000000000f, 1.000000000f };
	FLinearColor OrangeRed = { 1.000000000f, 0.270588249f, 0.000000000f, 1.000000000f };
	FLinearColor Orchid = { 0.854902029f, 0.439215720f, 0.839215755f, 1.000000000f };
	FLinearColor PaleGoldenrod = { 0.933333397f, 0.909803987f, 0.666666687f, 1.000000000f };
	FLinearColor PaleGreen = { 0.596078455f, 0.984313786f, 0.596078455f, 1.000000000f };
	FLinearColor PaleTurquoise = { 0.686274529f, 0.933333397f, 0.933333397f, 1.000000000f };
	FLinearColor PaleVioletRed = { 0.858823597f, 0.439215720f, 0.576470613f, 1.000000000f };
	FLinearColor PapayaWhip = { 1.000000000f, 0.937254965f, 0.835294187f, 1.000000000f };
	FLinearColor PeachPuff = { 1.000000000f, 0.854902029f, 0.725490212f, 1.000000000f };
	FLinearColor Peru = { 0.803921640f, 0.521568656f, 0.247058839f, 1.000000000f };
	FLinearColor Pink = { 1.000000000f, 0.752941251f, 0.796078503f, 1.000000000f };
	FLinearColor Plum = { 0.866666734f, 0.627451003f, 0.866666734f, 1.000000000f };
	FLinearColor PowderBlue = { 0.690196097f, 0.878431439f, 0.901960850f, 1.000000000f };
	FLinearColor Purple = { 0.501960814f, 0.000000000f, 0.501960814f, 1.000000000f };
	FLinearColor Red = { 1.000000000f, 0.000000000f, 0.000000000f, 1.000000000f };
	FLinearColor RosyBrown = { 0.737254918f, 0.560784340f, 0.560784340f, 1.000000000f };
	FLinearColor RoyalBlue = { 0.254901975f, 0.411764741f, 0.882353008f, 1.000000000f };
	FLinearColor SaddleBrown = { 0.545098066f, 0.270588249f, 0.074509807f, 1.000000000f };
	FLinearColor Salmon = { 0.980392218f, 0.501960814f, 0.447058856f, 1.000000000f };
	FLinearColor SandyBrown = { 0.956862807f, 0.643137276f, 0.376470625f, 1.000000000f };
	FLinearColor SeaGreen = { 0.180392161f, 0.545098066f, 0.341176480f, 1.000000000f };
	FLinearColor SeaShell = { 1.000000000f, 0.960784376f, 0.933333397f, 1.000000000f };
	FLinearColor Sienna = { 0.627451003f, 0.321568638f, 0.176470593f, 1.000000000f };
	FLinearColor Silver = { 0.752941251f, 0.752941251f, 0.752941251f, 1.000000000f };
	FLinearColor SkyBlue = { 0.529411793f, 0.807843208f, 0.921568692f, 1.000000000f };
	FLinearColor SlateBlue = { 0.415686309f, 0.352941185f, 0.803921640f, 1.000000000f };
	FLinearColor SlateGray = { 0.439215720f, 0.501960814f, 0.564705908f, 1.000000000f };
	FLinearColor Snow = { 1.000000000f, 0.980392218f, 0.980392218f, 1.000000000f };
	FLinearColor SpringGreen = { 0.000000000f, 1.000000000f, 0.498039246f, 1.000000000f };
	FLinearColor SteelBlue = { 0.274509817f, 0.509803951f, 0.705882370f, 1.000000000f };
	FLinearColor Tan = { 0.823529482f, 0.705882370f, 0.549019635f, 1.000000000f };
	FLinearColor Teal = { 0.000000000f, 0.501960814f, 0.501960814f, 1.000000000f };
	FLinearColor Thistle = { 0.847058892f, 0.749019623f, 0.847058892f, 1.000000000f };
	FLinearColor Tomato = { 1.000000000f, 0.388235331f, 0.278431386f, 1.000000000f };
	FLinearColor Transparent = { 0.000000000f, 0.000000000f, 0.000000000f, 0.000000000f };
	FLinearColor Turquoise = { 0.250980407f, 0.878431439f, 0.815686345f, 1.000000000f };
	FLinearColor Violet = { 0.933333397f, 0.509803951f, 0.933333397f, 1.000000000f };
	FLinearColor Wheat = { 0.960784376f, 0.870588303f, 0.701960802f, 1.000000000f };
	FLinearColor White = { 1.000000000f, 1.000000000f, 1.0f, 1.000000000f };
	FLinearColor WhiteSmoke = { 0.960784376f, 0.960784376f, 0.960784376f, 1.000000000f };
	FLinearColor Yellow = { 1.000000000f, 1.000000000f, 0.000000000f, 1.000000000f };
	FLinearColor YellowGreen = { 0.603921592f, 0.803921640f, 0.196078449f, 1.000000000f };
};

// ScriptStruct CoreUObject.Quat
// 0x0010
struct alignas(16) FQuat
{
	float                                              X;                                                        // 0x0000(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
	float                                              Y;                                                        // 0x0004(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
	float                                              Z;                                                        // 0x0008(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
	float                                              W;                                                        // 0x000C(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
};

// ScriptStruct CoreUObject.Transform
// 0x0030
struct alignas(16) FTransform
{
	struct FQuat                                       Rotation;                                                 // 0x0000(0x0010) (CPF_Edit, CPF_BlueprintVisible, CPF_SaveGame, CPF_IsPlainOldData)
	struct FVector                                     Translation;                                              // 0x0010(0x000C) (CPF_Edit, CPF_BlueprintVisible, CPF_SaveGame, CPF_IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x001C(0x0004) MISSED OFFSET
	struct FVector                                     Scale3D;                                                  // 0x0020(0x000C) (CPF_Edit, CPF_BlueprintVisible, CPF_SaveGame, CPF_IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x002C(0x0004) MISSED OFFSET
};

uintptr_t GOffset_Mesh = 0;
uintptr_t GOffset_Weapon = 0;
uintptr_t GOffset_WeaponData = 0;
uintptr_t GOffset_DisplayName = 0;
uintptr_t GOffset_ViewportClient = 0;

struct UCanvas_K2_DrawLine_Params
{
	FVector2D                                   ScreenPositionA;                                          // (Parm, IsPlainOldData)
	FVector2D                                   ScreenPositionB;                                          // (Parm, IsPlainOldData)
	float                                              Thickness;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                RenderColor;                                              // (Parm, IsPlainOldData)
};

void K2_DrawLine(UObject* _this, FVector2D ScreenPositionA, FVector2D ScreenPositionB, FLOAT Thickness, FLinearColor Color)
{
	static uintptr_t addr = NULL;
	if (!addr)
	{
		addr = FindPattern(E("40 55 48 8D 6C 24 ? 48 81 EC ? ? ? ? 4C 89 45 DF F3 0F 10 4D ?"));
		if (!addr) return;
	}

	if (!_this) return;

	auto K2_DrawLine = reinterpret_cast<VOID(__fastcall*)(PVOID, FVector2D, FVector2D, FLOAT, FLinearColor)>(addr);

	return K2_DrawLine((PVOID)_this, ScreenPositionA, ScreenPositionB, Thickness, Color);
}

//void K2_DrawLine(UObject* _this, const struct FVector2D& ScreenPositionA, const struct FVector2D& ScreenPositionB, float Thickness, const struct FLinearColor& RenderColor)
//{
//	static UFunction* fn = nullptr;
//
//	if (!fn)
//		fn = (UFunction*)FindObject(E("Function Engine.Canvas.K2_DrawLine"));
//
//	UCanvas_K2_DrawLine_Params params;
//	params.ScreenPositionA = ScreenPositionA;
//	params.ScreenPositionB = ScreenPositionB;
//	params.Thickness = Thickness;
//	params.RenderColor = RenderColor;
//
//	ProcessEvent(_this, fn, &params);
//}

//void K2_DrawLine(UObject* _this, const struct FVector2D& ScreenPositionA, const struct FVector2D& ScreenPositionB, float Thickness, const struct FLinearColor& RenderColor)
//{
//	auto a1 = ScreenPositionA;
//	a1.X += 1;
//	a1.Y += 1;
//	auto b1 = ScreenPositionB;
//	b1.X += 1;
//	b1.Y += 1;
//
//	auto a2 = ScreenPositionA;
//	a2.X -= 1;
//	a2.Y -= 1;
//	auto b2 = ScreenPositionB;
//	b2.X -= 1;
//	b2.Y -= 1;
//
//	K2_DrawLine_Internal(_this, a1, b1, Thickness, Colors::Gray);
//	K2_DrawLine_Internal(_this, ScreenPositionA, ScreenPositionB, Thickness, RenderColor);
//	K2_DrawLine_Internal(_this, a2, b2, Thickness, Colors::Gray);
//}

uintptr_t GetGetBoneMatrix()
{
	auto ss = FindPattern(E("E8 ? ? ? ? 0F 10 48 30"));
	if (!ss) ss = FindPattern(E("E8 ? ? ? ? 48 8B 8C 24 ? ? ? ? 0F 28 00"));
	if (!ss) ss = FindPattern(E("E8 ? ? ? ? 4C 8B 8D ? ? ? ? 48 8D 4D F0"));

	if (!ss)
		return ss;

	return ss;
}

struct FName GetBoneName(UObject* _this, int BoneIndex)
{
	static UFunction* fn = 0; if (!fn) fn = UObject::FindObject<UFunction>(xorstr_("Function Engine.SkinnedMeshComponent.GetBoneName"));

	struct
	{
		int                            BoneIndex;
		struct FName                   ReturnValue;
	} params;

	params.BoneIndex = BoneIndex;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

bool __forceinline point_valid(FVector2D& val)
{
	return val.X > 0 && val.X < (float)g_ScreenWidth&& val.Y > 0 && val.Y < (float)g_ScreenHeight;
}

void DrawBones(UObject* mesh, Bones* arr, int sz, FLinearColor clr, FVector2D& topleft, FVector2D& downright, float b_thicc = 1.0f)
{
	for (int i = 1; i < sz; i++)
	{
		FVector2D spPrev;
		FVector2D spNext;

		FVector previousBone = GetBone3D(mesh, arr[i - 1]);

		if (previousBone == FVector())
			continue;

		//if (!W2S(previousBone, spPrev))
			continue;

		FVector nextBone = GetBone3D(mesh, arr[i]);

		if (nextBone == FVector())
			continue;

		//if (!W2S(nextBone, spNext))
			continue;

		if (previousBone.DistanceFrom(nextBone) > 100)
			continue;

		auto x = spPrev;

		if (x.X > downright.X)
			downright.X = x.X;

		if (x.Y > downright.Y)
			downright.Y = x.Y;

		if (x.X < topleft.X)
			topleft.X = x.X;

		if (x.Y < topleft.Y)
			topleft.Y = x.Y;

		x = spNext;

		if (x.X > downright.X)
			downright.X = x.X;

		if (x.Y > downright.Y)
			downright.Y = x.Y;

		if (x.X < topleft.X)
			topleft.X = x.X;

		if (x.Y < topleft.Y)
			topleft.Y = x.Y;

		if (G::Skeletons)
			K2_DrawLine((UObject*)GCanvas, spPrev, spNext, b_thicc, clr);
	}
}

void DrawBox(FVector2D& topleft, FVector2D& downright, FLinearColor clr = Colors::Red)
{
	//xDrawText(E(L"T L"), topleft, clr);
	//xDrawText(E(L"D R"), downright, clr);

	float thicc = G::PlayerBoxThicc;

	if (!G::CornerBox)
	{
		K2_DrawLine(GCanvas, topleft, { downright.X, topleft.Y }, thicc, clr);
		K2_DrawLine(GCanvas, topleft, { topleft.X , downright.Y }, thicc, clr);
		K2_DrawLine(GCanvas, downright, { topleft.X , downright.Y }, thicc, clr);
		K2_DrawLine(GCanvas, downright, { downright.X, topleft.Y }, thicc, clr);
	}
	else
	{
		auto h = downright.Y - topleft.Y;
		auto w = downright.X - topleft.X;

		auto downleft = FVector2D{ topleft.X, downright.Y };
		auto topright = FVector2D{ downright.X, topleft.Y };

		thicc = G::CornerBoxThicc;

		K2_DrawLine(GCanvas, topleft, { topleft.X, topleft.Y + h * G::CornerBoxScale }, thicc, clr);
		K2_DrawLine(GCanvas, topleft, { topleft.X + w * G::CornerBoxScale, topleft.Y }, thicc, clr);

		K2_DrawLine(GCanvas, downright, { downright.X, downright.Y - h * G::CornerBoxScale }, thicc, clr);
		K2_DrawLine(GCanvas, downright, { downright.X - w * G::CornerBoxScale, downright.Y }, thicc, clr);

		K2_DrawLine(GCanvas, downleft, { downleft.X, downleft.Y - h * G::CornerBoxScale }, thicc, clr);
		K2_DrawLine(GCanvas, downleft, { downleft.X + w * G::CornerBoxScale, downright.Y }, thicc, clr);

		K2_DrawLine(GCanvas, topright, { topright.X, topright.Y + h * G::CornerBoxScale }, thicc, clr);
		K2_DrawLine(GCanvas, topright, { topright.X - w * G::CornerBoxScale, topright.Y }, thicc, clr);
	}
}

UFunction* FindFunction(const char* memes)
{
	return UObject::FindObject<UFunction>(memes);
}

struct FString GetPlayerName(UObject* player)
{
	static UFunction* fn = 0; if (!fn) fn = FindFunction(E("Function Engine.PlayerState.GetPlayerName"));

	struct
	{
		struct FString                 ReturnValue;
	} params;


	ProcessEvent(player, fn, &params);

	auto ret = params.ReturnValue;
	return ret;
}

uintptr_t GOffset_PlayerState = 0;

class FTextData {
public:
	char pad_0x0000[0x28];  //0x0000
	wchar_t* Name;          //0x0028
	__int32 Length;         //0x0030

};

struct FText {
	FTextData* Data;
	char UnknownData[0x10];

	wchar_t* Get() const {
		if (Data) {
			return Data->Name;
		}

		return nullptr;
	}
};

class UControl
{
public:

	FVector2D Origin;
	FVector2D Size;
	bool* BoundBool = nullptr;
	bool bIsMenuTabControl;
	bool bIsRangeSlider;
	int RangeValueMin;
	int RangeValueMax;
	int* pBoundRangeValue;
	int BoundMenuTabIndex;

	bool ContainsPoint(FVector2D pt)
	{
		auto extent = Origin + Size;
		return (pt.X > Origin.X && pt.Y > Origin.Y && pt.X < extent.X&& pt.Y < extent.Y);
	}
};

UClass* SC_Pickaxe()
{
	static UClass* memes = 0;
	if (!memes)
		memes = UObject::FindObject<UClass>(xorstr_("Class FortniteGame.AthenaPickaxeItemDefinition"));
	return memes;
}

uintptr_t GOffset_PrimaryPickupItemEntry = 0;
uintptr_t GOffset_Tier = 0;
uintptr_t GOffset_ItemDefinition = 0;

FText QueryDroppedItemNameAndTier(uint64_t item, BYTE* tier)
{
	auto definition = readA<uint64_t>(item + DGOffset_PrimaryPickupItemEntry + DGOffset_ItemDefinition);
	if (definition)
	{
		*tier = readA<BYTE>(definition + DGOffset_Tier);
		return readA<FText>(definition + DGOffset_DisplayName);
	}
	else
		return FText{};
}

void MwMenuDraw();

std::vector<UControl>* g_ControlBoundsList;

uintptr_t g_VehSelected = 0;

HWND GHGameWindow = 0;

int GetTeamId(UObject* actor)
{
	auto playerState = readA<UObject*>((uintptr_t)actor + DGOffset_PlayerState);

	if (playerState)
	{
		return readA<int>((uint64_t)playerState + DGOffset_TeamIndex);
	}

	return 0;
}

float cached_bullet_gravity_scale = 0.f, cached_world_gravity = 0.f;

int GMyTeamId = 0;

uintptr_t GOffset_GravityScale = 0;
uintptr_t GOffset_Searched = 0;

bool AController_SetControlRotation(FRotator rot, uint64_t controller)
{
	auto VTable = readA<uintptr_t>(controller);
	if (!VTable)
		return false;

	auto func = (*(void(__fastcall**)(uint64_t, void*))(VTable + 0x688));
	func(controller, (void*)&rot);

	return true;
}

FRotator Clamp(FRotator r)
{
	if (r.Yaw > 180.f)
		r.Yaw -= 360.f;
	else if (r.Yaw < -180.f)
		r.Yaw += 360.f;

	if (r.Pitch > 180.f)
		r.Pitch -= 360.f;
	else if (r.Pitch < -180.f)
		r.Pitch += 360.f;

	if (r.Pitch < -89.f)
		r.Pitch = -89.f;
	else if (r.Pitch > 89.f)
		r.Pitch = 89.f;

	r.Roll = 0.f;

	return r;
}

#define M_RADPI	57.295779513082f
__forceinline FRotator calc_angle(FVector& Src, FVector& Dst)
{
	FVector Delta = Src - Dst;
	FRotator AimAngles;
	float Hyp = sqrt(powf(Delta.X, 2.f) + powf(Delta.Y, 2.f));
	AimAngles.Yaw = atanf(Delta.Y / Delta.X) * M_RADPI;
	AimAngles.Pitch = (atanf(Delta.Z / Hyp) * M_RADPI) * -1.f;
	if (Delta.X >= 0.f) AimAngles.Yaw += 180.f;
	//AimAngles.Roll = 0.f;
	return AimAngles;
}

void SetViewAngles(FRotator ang)
{
	auto angls = Clamp(ang);
	angls.Roll = 0.0f;
	AController_SetControlRotation(ang, GController);
}

void AimToTarget(FRotator ang)
{
	//if (bestFOV >= AimbotFOV)
		//return;

	bAimbotActivated = true;

	SetViewAngles(ang);
}

#define DEG2RAD(x)  ( (float)(x) * (float)(M_PI_F / 180.f) )
#define M_PI_F		((float)(M_PI))
#define RAD2DEG(x)  ( (float)(x) * (float)(180.f / M_PI_F) )


UClass* SC_BuildingContainer()
{
	static UClass* bc = 0;
	if (!bc) bc = UObject::FindObject<UClass>(xorstr_("Class FortniteGame.BuildingContainer"));
	return bc;
}

bool GetActorEnableCollision(UObject* a)
{
	static UFunction* fn = 0; if (!fn) fn = FindFunction(E("Function Engine.Actor.GetActorEnableCollision"));

	struct
	{
		bool                           ReturnValue;
	} params;


	ProcessEvent(a, fn, &params);

	return params.ReturnValue;
}

void SetActorEnableCollision(UObject* a, bool bNewActorEnableCollision)
{
	static UFunction* fn = 0; if (!fn) fn = FindFunction(E("Function Engine.Actor.SetActorEnableCollision"));

	struct
	{
		bool                           bNewActorEnableCollision;
	} params;

	params.bNewActorEnableCollision = bNewActorEnableCollision;

	ProcessEvent(a, fn, &params);
}

uintptr_t GOffset_VehicleSkeletalMesh = 0;
uintptr_t GOffset_Visible = 0;

SHORT myGetAsyncKeyState(int kode)
{
	return GetAsyncKeyState(kode);
}

#pragma pack(push, 1)
// Function Engine.PrimitiveComponent.SetAllPhysicsLinearVelocity
struct UPrimitiveComponent_SetAllPhysicsLinearVelocity_Params
{
	struct FVector                                     NewVel;                                                   // (Parm, IsPlainOldData)
	bool                                               bAddToCurrent;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Engine.PrimitiveComponent.SetEnableGravity
struct UPrimitiveComponent_SetEnableGravity_Params
{
	bool                                               bGravityEnabled;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Engine.Actor.K2_SetActorRotation
struct AActor_K2_SetActorRotation_Params
{
	struct FRotator                                    NewRotation;                                              // (Parm, IsPlainOldData)
	bool                                               bTeleportPhysics;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};
#pragma pack(pop)

void SetAllPhysicsAngularVelocity(uint64_t primitive_component, const struct FVector& NewVel, bool bAddToCurrent)
{
	static UFunction* fn = nullptr;

	if (!fn)
		fn = FindFunction(E("Function Engine.PrimitiveComponent.SetAllPhysicsAngularVelocity"));
	UPrimitiveComponent_SetAllPhysicsLinearVelocity_Params params;
	params.NewVel = NewVel;
	params.bAddToCurrent = bAddToCurrent;

	ProcessEvent((UObject*)primitive_component, fn, &params);
}


void SetAllPhysicsLinearVelocity(uint64_t primitive_component, const struct FVector& NewVel, bool bAddToCurrent)
{
	static UFunction* fn = nullptr;

	if (!fn)
		fn = FindFunction(E("Function Engine.PrimitiveComponent.SetAllPhysicsLinearVelocity"));
	UPrimitiveComponent_SetAllPhysicsLinearVelocity_Params params;
	params.NewVel = NewVel;
	params.bAddToCurrent = bAddToCurrent;

	ProcessEvent((UObject*)primitive_component, fn, &params);
}

void SetEnableGravity(uint64_t primitive_component, bool bEnable)
{
	static UFunction* fn = nullptr;

	if (!fn)
		fn = FindFunction(E("Function Engine.PrimitiveComponent.SetEnableGravity"));
	UPrimitiveComponent_SetEnableGravity_Params params;
	params.bGravityEnabled = bEnable;
	ProcessEvent((UObject*)primitive_component, fn, &params);
}

void ProcessVehicle(uintptr_t pawn)
{
	auto rc = readA<uintptr_t>(pawn + DGOffset_RootComponent);

	if (!rc)
		return;

	auto loc = readA<FVector>(rc + DGOffset_ComponentLocation);

	if (GetDistanceMeters(loc) > 10)
		return;

	auto veh_mesh = *(uintptr_t*)(pawn + DGOffset_VehicleSkeletalMesh);

	if (veh_mesh)
	{
		if (myGetAsyncKeyState(VK_CAPITAL) & 1)
		{
			SetActorEnableCollision((UObject*)pawn, false);

			float coeff = (60.0f * 60);

			if (myGetAsyncKeyState(VK_SHIFT))
			{
				coeff *= 2;
			}

			SetAllPhysicsAngularVelocity(veh_mesh, { 0, 0, 0 }, false);
			SetAllPhysicsLinearVelocity(veh_mesh, { 0, 0, 0 }, false);
			SetEnableGravity(veh_mesh, false);
			bool bKp = false;

			if (myGetAsyncKeyState('Q') & 0x8000)
			{
				SetAllPhysicsLinearVelocity(veh_mesh, { 0.f, 0.f, coeff / 2 }, true);
				bKp = true;
			}

			if (myGetAsyncKeyState('E') & 0x8000)
			{
				SetAllPhysicsLinearVelocity(veh_mesh, { 0.f, 0.f, -(coeff / 2) }, true);
				bKp = true;
			}

			if (myGetAsyncKeyState(0x57))
			{
				FVector vel;
				auto yaw = GCameraCache->Rotation.Yaw;
				float theta = 2.f * M_PI * (yaw / 360.f);

				vel.X = (coeff * cos(theta));
				vel.Y = (coeff * sin(theta));
				vel.Z = 0.f;

				SetAllPhysicsLinearVelocity(veh_mesh, vel, true);
				bKp = true;
			}
			if (myGetAsyncKeyState(0x53))
			{
				FVector vel;
				auto yaw = GCameraCache->Rotation.Yaw;
				float theta = 2.f * M_PI * (yaw / 360.f);

				vel.X = -(coeff * cos(theta));
				vel.Y = -(coeff * sin(theta));

				SetAllPhysicsLinearVelocity(veh_mesh, vel, true); //{ -80.f, 0.f, 0.f }
				bKp = true;
			}
			if (myGetAsyncKeyState(0x41)) // A
			{
				FVector vel;
				auto yaw = GCameraCache->Rotation.Yaw;
				float theta = 2.f * M_PI * (yaw / 360.f);

				vel.X = (coeff * sin(theta));
				vel.Y = -(coeff * cos(theta));

				SetAllPhysicsLinearVelocity(veh_mesh, vel, true); //{ -80.f, 0.f, 0.f }
				bKp = true;
			}
			if (myGetAsyncKeyState(0x44)) // D
			{
				FVector vel;
				auto yaw = GCameraCache->Rotation.Yaw;
				float theta = 2.f * M_PI * (yaw / 360.f);

				vel.X = -(coeff * sin(theta));
				vel.Y = (coeff * cos(theta));

				SetAllPhysicsLinearVelocity(veh_mesh, vel, true); //{ -80.f, 0.f, 0.f }
				bKp = true;
			}

			if (!bKp || myGetAsyncKeyState(VK_SPACE))
			{
				SetAllPhysicsLinearVelocity(veh_mesh, { 0.0, 0.0, 0.0 }, false);
			}
		}
		else
		{
			SetEnableGravity(veh_mesh, true);
			SetActorEnableCollision((UObject*)pawn, true);
		}
	}
}

bool K2_SetActorLocation(UObject* a, const struct FVector& NewLocation, bool bSweep, bool bTeleport, struct FHitResult* SweepHitResult)
{
	static UFunction* fn = nullptr;
	if (!fn) fn = FindFunction(E("Function Engine.Actor.K2_SetActorLocation"));

	// Function Engine.Actor.K2_SetActorLocation
	struct AActor_K2_SetActorLocation_Params
	{
		struct FVector                                     NewLocation;                                              // (Parm, IsPlainOldData)
		bool                                               bSweep;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
		struct FHitResult                                  SweepHitResult;                                           // (Parm, OutParm, IsPlainOldData)
		bool                                               bTeleport;                                                // (Parm, ZeroConstructor, IsPlainOldData)
		bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
	};

	AActor_K2_SetActorLocation_Params params;

	params.NewLocation = NewLocation;
	params.bSweep = bSweep;
	params.bTeleport = bTeleport;

	auto flags = fn->FunctionFlags;

	ProcessEvent(a, fn, &params);

	fn->FunctionFlags = flags;

	if (SweepHitResult != nullptr)
		*SweepHitResult = params.SweepHitResult;

	return params.ReturnValue;
}

void Render()
{
	//dprintf("RENDERER CHECK");
	FLinearColor clr(1, 1, 1, 1);

	if (g_ControlBoundsList && g_ControlBoundsList->size())
		g_ControlBoundsList->clear();
	else
		g_ControlBoundsList = new std::vector<UControl>();

	int closestEnemyDist = 9999999;
	FVector closestEnemyAss;
	if (G::RefreshEach1s)
	{
		ULONGLONG tLastTimeRefreshd = 0;
		if (GetTickCount64() - tLastTimeRefreshd >= 1000)
		{
			//dprintf("RENDERER CHECK3");
			RECT rect;
			if (GHGameWindow && GetWindowRect(GHGameWindow, &rect))
			{
				g_ScreenWidth = rect.right - rect.left;
				g_ScreenHeight = rect.bottom - rect.top;
			}
			//dprintf("RENDERER CHECK4");
			tLastTimeRefreshd = GetTickCount64();

			dprintf(E("Refreshed: g_ScrenWidth: %d px, height: %d px"), g_ScreenWidth, g_ScreenHeight);
		}
	}

	if (G::EnableHack)
	{
		if (G::AimbotEnable)
			AimbotBeginFrame();

		static UClass* VehicleSK_class = nullptr;
		if (!VehicleSK_class)
			VehicleSK_class = UObject::FindObject<UClass>(xorstr_("Class FortniteGame.FortAthenaSKVehicle"));

		bool bInExplosionRadius = false;
		bool bEnemyClose = false;

		auto UWorld = GWorld;
		if (!UWorld)
		{
			//xDrawText(E(L"NO WORLD!"), { 600, 600 }, clr);
		}

		auto levels = *(TArray<UObject*>*)((uintptr_t)UWorld + DGOffset_Levels);

		if (!levels.Num())
		{
			//xDrawText(E(L"NO LEVEL #1!"), { 600, 600 }, clr);
			return;
		}

		auto bCaps = false;
		if (G::WeakSpotAimbot)
		{
			if (GetAsyncKeyState((int)WeakSpotAimbotKey))
			{
				bCaps = true;

				K2_DrawText(GCanvas, GetFont(), xorstr_(L"WeakSpot aimbot is ON"), { 30, 800 }, FVector2D(1.0f, 1.0f), Colors::Red, 1.0f, FLinearColor(0, 0, 0, 255), FVector2D(), false, false, true, FLinearColor(0, 0, 0, 1.0f));
			}
		}


		for (int levelIndex = 0; (G::LootEnable ? (levelIndex != levels.Num()) : levelIndex != 1); levelIndex++)
		{
			auto level = levels[levelIndex];
			if (!level)
			{
				//xDrawText(E(L"NO LEVEL #2!"), { 600, 600 }, clr);
				return;
			}
			GActorArray = (TArray<UObject*>*)((uintptr_t)level + DGOffset_Actors);
			auto actors = *GActorArray;
			static UClass* supply_class = nullptr;
			static UClass* trap_class = nullptr;
			static UClass* fortpickup_class = nullptr;
			static UClass* BuildingContainer_class = nullptr;
			static UClass* Chests_class = nullptr;
			static UClass* AB_class = nullptr;
			static UClass* GolfCarts_class = nullptr;
			static UClass* Rifts_class = nullptr;

			if (!supply_class)
				supply_class = UObject::FindObject<UClass>(xorstr_("Class FortniteGame.FortAthenaSupplyDrop"));

			if (!trap_class)
				trap_class = UObject::FindObject<UClass>(xorstr_("Class FortniteGame.BuildingTrap"));

			if (!fortpickup_class)
				fortpickup_class = UObject::FindObject<UClass>(xorstr_("Class FortniteGame.FortPickup"));

			if (!Rifts_class)
				Rifts_class = UObject::FindObject<UClass>(xorstr_("Class FortniteGame.FortAthenaRiftPortal"));

			static UClass* projectiles_class = nullptr;

			static UClass* weakspot_class = nullptr;

			if (!weakspot_class)
				weakspot_class = UObject::FindObject<UClass>(xorstr_("Class FortniteGame.BuildingWeakSpot"));

			if (!projectiles_class)
				projectiles_class = UObject::FindObject<UClass>(xorstr_("Class FortniteGame.FortProjectileBase"));

			for (int i = 0; i < actors.Num(); i++)
			{
				auto actor = actors[i];

				if (!actor)
					continue;

				//if (!G::DrawSelf)
				//{
				if (actor == (UObject*)GPawn)
					continue;
				//}

				if (G::EspLoot && Object_IsA((UObject*)actor, fortpickup_class))
				{
					auto rc = *(UObject**)((uintptr_t)actor + DGOffset_RootComponent);

					if (!rc)
						continue;

					FVector loc = *(FVector*)((uintptr_t)rc + DGOffset_ComponentLocation);

					FVector2D sp;

					auto dist = GetDistanceMeters(loc);

					if (dist > G::RenderDist)
						continue;

					if (dist > G::LootRenderDist)
						continue;

					//if (W2S(loc, sp))
					{
						static char buf[512];
						static wchar_t wmemes[512];
						BYTE tier;
						auto name = QueryDroppedItemNameAndTier((uintptr_t)actor, &tier);
						if (name.Get() && tier > 0)
						{
							auto color = Colors::LightYellow;

							/*switch (tier)
							{
							case 0:
							case 1:
								break;
							case 2:
								color = Colors::LightGreen;
								break;
							case 3:
								color = Colors::DarkCyan;
								break;
							case 4:
								color = Colors::Purple;
								break;
							case 5:
								color = Colors::Orange;
								break;
							}

							//if (tier >= G::LootTier)
							//{
							sprintf(buf, E("[ %s %d m ]"), WideToAnsi(name.Get()).c_str(), dist);
							AnsiToWide(buf, wmemes);
							xDrawText(wmemes, sp, color);
							//}
						}
					}
				}
				else if (G::Chests && Object_IsA(actor, SC_BuildingContainer()))
				{

					FVector2D sp;

					auto rc = *(UObject**)((uintptr_t)actor + DGOffset_RootComponent);

					if (!rc)
						continue;

					FVector loc = *(FVector*)((uintptr_t)rc + DGOffset_ComponentLocation);

					auto dist = GetDistanceMeters(loc);

					if (dist > G::RenderDist)
						continue;

					if (dist > G::ChestsRdist)
						continue;



					//if (W2S(loc, sp))
					{
						char memes[128];
						wchar_t wmemes[128];

						auto _class = actor->Class;
						auto drawColor = Colors::Yellow;
						auto drawName = E("Chest");

						static UClass* Ammoboxes_class = 0;

						bool bDraw = true;

						if (G::Chests)
						{
							if (!Chests_class)
							{
								auto className = GetObjectName(_class);
								if (MemoryBlocksEqual((void*)className.c_str(), (void*)E("Tiered_Chest"), 12))
								{
									Chests_class = _class;
									dprintf(E("Chests class: %s"), className.c_str());
									bDraw = true;
								}
							}
							else if (Object_IsA(actor, Chests_class))
							{
								bDraw = true;
							}
						}

						if (!bDraw && G::LootTier <= 1)
						{
							if (!Ammoboxes_class)
							{
								auto className = GetObjectName(_class);
								if (MemoryBlocksEqual((void*)className.c_str(), (void*)E("Tiered_Ammo"), 11))
								{
									Ammoboxes_class = _class;
									dprintf(E("AmmoBoxes class: %s"), className.c_str());
									bDraw = true;
									drawName = xorstr_("Ammo");
									drawColor = Colors::White;
								}
							}
							else if (Object_IsA(actor, Ammoboxes_class))
							{
								drawName = xorstr_("Ammo");
								bDraw = true;
								drawColor = Colors::White;
							}
						}

						if (!bDraw)
							continue;

						//auto searched = *(UObject**)((uintptr_t)actor + DGOffset_Searched);
						//auto mesh = *(UObject**)((uintptr_t)actor + DGOffset_Mesh);

						sprintf(memes, E("[ %s %d m ]"), drawName, GetDistanceMeters(loc));
						AnsiToWide(memes, wmemes);
						xDrawText(wmemes, sp, drawColor);
					}
				}

				else if (levelIndex == 0 && Object_IsA(actor, SC_FortPlayerPawn()))
				{

					auto rc = *(UObject**)((uintptr_t)actor + DGOffset_RootComponent);

					if (!rc)
						continue;

					FVector loc = *(FVector*)((uintptr_t)rc + DGOffset_ComponentLocation);

					auto dist = GetDistanceMeters(loc);

					if (dist > G::RenderDist)
						continue;

					FVector2D sp;

					//if (W2S(loc, sp))
					{
						//if ((uintptr_t)actor != GPawn)
						//{
							//if (GMyTeamId && (GetTeamId((UObject*)actor) == GMyTeamId))
								//continue;
						//}

						auto mesh = *(UObject**)((uintptr_t)actor + DGOffset_Mesh);

						if (!mesh)
							continue;

						//auto traced_color = TraceVisibility(mesh, GPawnLocation, loc) ? Colors::Red : Colors::Yellow;

						//auto isVisible = LineOfSightTo;

						auto bone = GetBone3D(mesh, !G::Baim ? (Bones)66 : Bones::spine_02);

						//if (!bCaps && G::AimbotEnable && actor != (UObject*)GPawn)
							//EvaluateTarget(bone);

						static Bones p1[] = // left arm - neck - right arm
						{
							Bones(55),
							Bones(92),
							Bones(91),
							Bones(36),
							Bones(9),
							Bones(10),
							Bones(27)
						};

						static Bones p2[] = // head-spine-pelvis
						{
							(Bones)66,
							(Bones)64,
							(Bones)2
						};

						static Bones p3[] = // left leg - pelvis - right leg
						{
							Bones(79),
							Bones(83),
							Bones(75),
							Bones(74),
							Bones(2),
							Bones(67),
							Bones(68),
							Bones(82),
							Bones(72)
						};

						FVector2D downright;
						FVector2D topleft;

						float box_center_offset = 0;

						auto dsit = GetDistanceMeters(loc);

						float bone_thicc = G::SkeletonThicc;
						auto b_color = Colors::LightCyan;

						if (dsit < G::RedDistance)
							b_color = Colors::Red;

						//dprintf("ENABLEHACK CHECK10\n");

						if (dsit < G::RedDistance && G::SnaplinesIn50m)
						{
							K2_DrawLine((UObject*)GCanvas, sp, { (float)(g_ScreenWidth / 2) , (float)(g_ScreenHeight - 20) }, 1, Colors::Red);
						}
						else if (G::Snaplines)
						{
							K2_DrawLine((UObject*)GCanvas, sp, { (float)(g_ScreenWidth / 2) , (float)(g_ScreenHeight - 20) }, 1, Colors::White);
						}

						if (dsit < G::RedDistance && !bEnemyClose)
						{
							xDrawText(E(L"ENEMY IS CLOSE TO YOU!"), { (float)(g_ScreenWidth / 2) , (float)(g_ScreenHeight - 180) }, Colors::Red);
							bEnemyClose = true;
						}

						if (G::Skeletons || G::EspBox)
						{
							topleft.X = 9999999;
							topleft.Y = 9999999;
							downright.X = -9999999;
							downright.Y = -9999999;

							DrawBones(mesh, p1, sizeof(p1), b_color, topleft, downright, bone_thicc);
							DrawBones(mesh, p2, sizeof(p2), b_color, topleft, downright, bone_thicc);
							DrawBones(mesh, p3, sizeof(p3), b_color, topleft, downright, bone_thicc);

							if (point_valid(topleft) && point_valid(downright))
							{
								FVector2D dim(downright.X - topleft.X, downright.Y - topleft.Y);
								topleft -= dim * 0.15;
								downright += dim * 0.15;

								if (G::EspBox)
								{
									DrawBox(topleft, downright);
								}

								box_center_offset = ((downright.X - topleft.X) / 2);
							}
							else
							{
								topleft = sp;
								downright = sp;
							}
						}
						else
						{
							topleft = sp;
							downright = sp;
						}

						float offset = -24;

						if (G::EspPlayerName)
						{
							auto playerState = readA<UObject*>((uintptr_t)actor + DGOffset_PlayerState);

							if (playerState)
							{
								auto name = GetPlayerName(playerState);
								if (name.c_str())
								{
									xDrawText(name.c_str(), topleft + FVector2D(0, offset), Colors::White, box_center_offset);
									offset -= 18;
								}
							}
						}

						if (G::EspWeapon)
						{
							auto weapon = readA<uint64_t>((uintptr_t)actor + DGOffset_Weapon);
							if (weapon)
							{
								auto wdata = readA<uint64_t>(weapon + DGOffset_WeaponData);
								if (wdata)
								{
									auto name = readA<FText>(wdata + DGOffset_DisplayName);
									auto tier = readA<UINT8>(wdata + DGOffset_Tier);
									auto naam = name.Get();

									if (naam)
									{
										if (naam[0] != 'H' && naam[1] != 'a')
										{
											auto color = Colors::LightYellow;

											switch (tier)
											{
											case 0:
											case 1:
												break;
											case 2:
												color = Colors::LightGreen;
												break;
											case 3:
												color = Colors::DarkCyan;
												break;
											case 4:
												color = Colors::Purple;
												break;
											case 5:
												color = Colors::Orange;
												break;
											}

											xDrawText(naam, topleft + FVector2D(0, offset), color, box_center_offset);
											offset -= 18;
										}
									}
								}
							}
						}

						static char memes[128];
						static wchar_t wmemes[128];

						sprintf(memes, E("[ %d m ]"), dsit);
						AnsiToWide(memes, wmemes);

						if (dsit < closestEnemyDist)
						{
							closestEnemyAss = GetBone3D(mesh, Bones::HEAD);
							closestEnemyDist = dsit;
						}

						xDrawText(wmemes, topleft + FVector2D(0, offset), Colors::Cyan, box_center_offset); // dist
					}
				}
				/*else if (G::EspLoot && Object_IsA((UObject*)actor, fortpickup_class))
				{
					auto rc = *(UObject**)((uintptr_t)actor + DGOffset_RootComponent);

					if (!rc)
						continue;

					FVector loc = *(FVector*)((uintptr_t)rc + DGOffset_ComponentLocation);

					FVector2D sp;

					auto dist = GetDistanceMeters(loc);

					if (dist > G::RenderDist)
						continue;

					if (dist > G::LootRenderDist)
						continue;

					if (W2S(loc, sp))
					{
						static char buf[512];
						static wchar_t wmemes[512];
						BYTE tier;
						auto name = QueryDroppedItemNameAndTier((uintptr_t)actor, &tier);
						if (name.Get() && tier > 0)
						{
							auto color = Colors::LightYellow;

							switch (tier)
							{
							case 0:
							case 1:
								break;
							case 2:
								color = Colors::LightGreen;
								break;
							case 3:
								color = Colors::DarkCyan;
								break;
							case 4:
								color = Colors::Purple;
								break;
							case 5:
								color = Colors::Orange;
								break;
							}

							if (tier >= G::LootTier)
							{
								sprintf(buf, E("[ %s %d m ]"), WideToAnsi(name.Get()).c_str(), dist);
								AnsiToWide(buf, wmemes);
								xDrawText(wmemes, sp, color);
							}
						}
					}
				}
				else if (levelIndex == 0 && G::EspRifts && Object_IsA(actor, Rifts_class))
				{
					auto rc = *(UObject**)((uintptr_t)actor + DGOffset_RootComponent);

					if (!rc)
						continue;

					FVector loc = *(FVector*)((uintptr_t)rc + DGOffset_ComponentLocation);

					FVector2D sp;

					auto dist = GetDistanceMeters(loc);

					if (dist > G::RenderDist)
						continue;

					//if (W2S(loc, sp))
					{
						static char memes[128];
						static wchar_t wmemes[128];
						sprintf(memes, E("[ Rift %d m ]"), GetDistanceMeters(loc));
						AnsiToWide(memes, wmemes);
						xDrawText(wmemes, sp, Colors::Green);
					}
				}
				else if (levelIndex == 0 && (G::FlyingCars || G::EspVehicles) && Object_IsA(actor, VehicleSK_class))
				{
					auto rc = *(UObject**)((uintptr_t)actor + DGOffset_RootComponent);

					if (!rc)
						continue;

					FVector loc = *(FVector*)((uintptr_t)rc + DGOffset_ComponentLocation);

					FVector2D sp;

					auto dist = GetDistanceMeters(loc);

					if (dist > G::RenderDist)
						continue;

					//if (W2S(loc, sp))
					{
						static char memes[128];
						static wchar_t wmemes[128];
						sprintf(memes, E("[ V %d m ]"), GetDistanceMeters(loc));
						AnsiToWide(memes, wmemes);
						xDrawText(wmemes, sp, Colors::Cyan);
					}

					if (G::FlyingCars)
					{
						ProcessVehicle((uintptr_t)actor);
					}

				}
				else if (levelIndex == 0 && G::EspSupplyDrops && Object_IsA(actor, supply_class))
				{
					auto rc = *(UObject**)((uintptr_t)actor + DGOffset_RootComponent);

					if (!rc)
						continue;

					FVector loc = *(FVector*)((uintptr_t)rc + DGOffset_ComponentLocation);

					FVector2D sp;

					auto dist = Dist((UObject*)actor);

					if (dist > G::RenderDist)
						continue;

					if (dist > G::LootRenderDist)
						continue;

					//if (W2S(loc, sp))
					{
						char memes[128];
						wchar_t wmemes[128];
						sprintf(memes, E("[ Supplies! %d m ]"), GetDistanceMeters(loc));
						AnsiToWide(memes, wmemes);
						xDrawText(wmemes, sp, Colors::Cyan);
					}
				}
				else if (levelIndex == 0 && G::EspTraps && Object_IsA(actor, trap_class))
				{
					auto rc = *(UObject**)((uintptr_t)actor + DGOffset_RootComponent);

					if (!rc)
						continue;

					FVector loc = *(FVector*)((uintptr_t)rc + DGOffset_ComponentLocation);

					FVector2D sp;

					auto dist = GetDistanceMeters(loc);

					if (dist > 30)
						continue;

					//if (W2S(loc, sp))
					{
						char memes[128];
						wchar_t wmemes[128];
						sprintf(memes, E("[ TRAP %d m ]"), GetDistanceMeters(loc));
						AnsiToWide(memes, wmemes);
						xDrawText(wmemes, sp, Colors::Red);
					}
				}
				else if (Object_IsA(actor, projectiles_class))
				{
					auto rc = *(UObject**)((uintptr_t)actor + DGOffset_RootComponent);

					if (!rc)
						continue;

					FVector loc = *(FVector*)((uintptr_t)rc + DGOffset_ComponentLocation);

					FVector2D sp;

					auto dist = GetDistanceMeters(loc);

					if (dist > G::RenderDist)
						continue;

					if (dist > 50)
						continue;

					//if (W2S(loc, sp))
					{
						static char memes[128];
						static wchar_t wmemes[128];
						sprintf(memes, E("[ PROJECTILE %d m ]"), dist);
						AnsiToWide(memes, wmemes);
						xDrawText(wmemes, sp, Colors::Red);

						if (dist < 20 && !bInExplosionRadius)
						{
							xDrawText(E(L"YOU'RE IN EXPLOSION RADIUS!"), { (float)(g_ScreenWidth / 2) , (float)(g_ScreenHeight - 200) }, Colors::Red);
							bInExplosionRadius = true;
						}
					}

					if (G::ProjectileTpEnable)
					{
						FHitResult xxxx;
						K2_SetActorLocation(actor, closestEnemyAss, true, true, &xxxx);
					}
				}
				else if (G::WeakSpotAimbot && bCaps && Object_IsA(actor, weakspot_class))
				{
					auto rc = *(UObject**)((uintptr_t)actor + DGOffset_RootComponent);

					if (!rc)
						continue;

					FVector loc = *(FVector*)((uintptr_t)rc + DGOffset_ComponentLocation);

					FVector2D sp;

					auto dist = GetDistanceMeters(loc);

					if (dist > 5)
						continue;

					if (!(*(bool*)((uintptr_t)actor + DGOffset_bHit)))
					{
						continue;
					}

					//if (W2S(loc, sp))
					{
						xDrawText(E(L"[ x ]"), sp, Colors::Cyan);
						//EvaluateTarget(loc);
					}
				}
			}
		}

		bAimbotActivated = false;

		if (G::AimbotEnable)
		{
			if (bCaps)
			{
				auto old = AimbotFOV;
				AimbotFOV = 90;
				AimbotFOV = old;
			}
			else
			{
				if (GetAsyncKeyState((int)AimbotKey))
				{
					auto angle = calc_angle(GCameraCache->Location, closestEnemyAss);

					bAimbotActivated = true;
					AimToTarget(angle);
				}
			}
		}
	}

	static char tier_data[256];
	static wchar_t tier_data_wide[256];

	auto color = Colors::LightYellow;

	switch ((int)G::LootTier)
	{
	case 0:
	case 1:
		break;
	case 2:
		color = Colors::LightGreen;
		break;
	case 3:
		color = Colors::DarkCyan;
		break;
	case 4:
		color = Colors::Purple;
		break;
	case 5:
		color = Colors::Orange;
		break;
	}

	sprintf(tier_data, E("Current loot tier (Page Up/Down): %d"), (int)G::LootTier);
	AnsiToWide(tier_data, tier_data_wide);
	K2_DrawText(GCanvas, GetFont(), tier_data_wide, { 30, 220 }, FVector2D(1.0f, 1.0f), color, 1.0f, FLinearColor(0, 0, 0, 255), FVector2D(), false, false, true, FLinearColor(0, 0, 0, 1.0f));

	sprintf(tier_data, E("Render distance: overall: %d m, loot: %d m"), (int)G::RenderDist, (int)G::LootRenderDist);
	AnsiToWide(tier_data, tier_data_wide);
	K2_DrawText(GCanvas, GetFont(), tier_data_wide, { 30, 240 }, FVector2D(1.0f, 1.0f), Colors::White, 1.0f, FLinearColor(0, 0, 0, 255), FVector2D(), false, false, true, FLinearColor(0, 0, 0, 1.0f));

	if (closestEnemyDist < 10000)
	{
		sprintf(tier_data, E("CLOSEST ENEMY: %d m"), closestEnemyDist);
		AnsiToWide(tier_data, tier_data_wide);
		K2_DrawText(GCanvas, GetFont(), tier_data_wide, { 30, (float)(g_ScreenHeight / 2) }, FVector2D(1.0f, 1.0f), closestEnemyDist < 50 ? Colors::Red : Colors::White, 1.0f, FLinearColor(0, 0, 0, 255), FVector2D(), false, false, true, FLinearColor(0, 0, 0, 1.0f));
	}
	//if (g_Menu)
		//MwMenuDraw();
}

uintptr_t GOffset_Pawn;

uintptr_t GetWorld()
{
	return *(uint64_t*)(GFnBase + UWorldOffset);
}

struct FMinimalViewInfo
{
	FCameraCacheEntry cache;
	struct FVector                                     Location;                                                 // 0x0000(0x000C) (Edit, BlueprintVisible, IsPlainOldData)
	struct FRotator                                    Rotation;                                                 // 0x000C(0x000C) (Edit, BlueprintVisible, IsPlainOldData)
	float                                              FOV;                                                      // 0x0018(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              DesiredFOV;                                               // 0x001C(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	float                                              OrthoWidth;                                               // 0x0020(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              OrthoNearClipPlane;                                       // 0x0024(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              OrthoFarClipPlane;                                        // 0x0028(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              AspectRatio;                                              // 0x002C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      bConstrainAspectRatio : 1;                                // 0x0030(0x0001) (Edit, BlueprintVisible)
	unsigned char                                      bUseFieldOfViewForLOD : 1;                                // 0x0030(0x0001) (Edit, BlueprintVisible)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0031(0x0003) MISSED OFFSET
	/*TEnumAsByte<ECameraProjectionM>                    ProjectionMode;                                           // 0x0034(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0035(0x0003) MISSED OFFSET
	float                                              PostProcessBlendWeight;                                   // 0x0038(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x003C(0x0004) MISSED OFFSET
	struct FPostProcessSettings                        PostProcessSettings;                                      // 0x0040(0x0520) (BlueprintVisible)
	struct FVector2D                                   OffCenterProjectionOffset;                                // 0x0560(0x0008) (Edit, BlueprintVisible, DisableEditOnTemplate, Transient, EditConst, IsPlainOldData)
	unsigned char                                      UnknownData03[0x8];                                       // 0x0568(0x0008) MISSED OFFSET
};

bool get_camera(FMinimalViewInfo* view, uint64_t player_camera_mgr)
{
	auto player_camera_mgr_VTable = readA<uintptr_t>(player_camera_mgr);
	if (!player_camera_mgr_VTable)
		return false;
	if (IsBadCodePtr(*(FARPROC*)(player_camera_mgr_VTable + 0x670)))
		return false;

	//(*(void(__fastcall **)(__int64, void*))(player_camera_mgr_VTable + 0x630))(player_camera_mgr, view);
	auto func = (*(void(__fastcall**)(uint64_t, void*))(player_camera_mgr_VTable + 0x670));

	func(player_camera_mgr, (void*)view);

	return (view[0].cache.Location.Size() != 0 && view[0].cache.Rotation.Size() != 0);
}

void PreRender()
{
	GWorld = GetWorld();

	if (GWorld && GCanvas)
	{
		auto GameInstance = readA<uint64_t>(GWorld + DGOffset_OGI);
		auto LocalPlayers = readA<uint64_t>(GameInstance + DGOffset_LocalPlayers);
		auto ULocalPlayer = readA<uint64_t>(LocalPlayers);
		GController = readA<uint64_t>(ULocalPlayer + DGOffset_PlayerController);
		GPlayerCameraManager = readA<uint64_t>(GController + DGOffset_PlayerCameraManager);
		if (GPlayerCameraManager)
		{
			static FMinimalViewInfo* view = nullptr;
			if (!view) view = (FMinimalViewInfo*)new BYTE[1024 * 50];

			if (get_camera(view, GPlayerCameraManager))
			{
				GCameraCache = &view[0].cache;
				GPawn = readA<uint64_t>(GController + DGOffset_Pawn);
				GPawnLocation = GCameraCache->Location;
				GMyTeamId = GetTeamId((UObject*)GPawn);
				if (GController)
					Render();
			}
		}
	}
}

void HkProcessEvent(UObject* _this, UFunction* fn, void* parms)
{
	if (!_this || !fn)
		return GoPE(_this, (UObject*)fn, parms);

	if (fn == S_ReceiveDrawHUD())
	{
		auto canvas = readA<UObject*>((uintptr_t)_this + DGOffset_Canvas);

		GHUD = _this;
		GCanvas = canvas;

		PreRender();

		K2_DrawLine(canvas, FVector2D(1920, 1080), FVector2D(50, 50), 100.0f, FLinearColor(255, 255, 255, 255));

	}

	return GoPE(_this, (UObject*)fn, parms);
}

int find_last_of(std::string _this, char c)
{
	auto last = -1;
	for (int i = 0; i < _this.length(); i++)
	{
		auto cCurrent = _this[i];
		if (cCurrent == c)
			last = i;
	}
	return last;
}

//string GetObjectFullNameA(UObject* obj)
//{
//	if (IsBadReadPtr(obj, sizeof(UObject)))
//		return E("None_X9");
//
//	if (IsBadReadPtr(obj->Class, sizeof(UClass)))
//		return E("None_X10");
//
//	auto objName = GetObjectNameA(obj);
//	auto className = GetObjectNameA(obj->Class);
//
//	std::string temp;
//	std::string name;
//	//dprintf("14");
//	int memes = 0;
//	for (auto p = obj->Outer; !IsBadReadPtr(p, 0x8); p = p->Outer)
//	{
//		memes++;
//		if (memes >= 100)
//			return E("None_X13");
//		//dprintf("14.5");
//		std::string temp2;
//		auto outerName = GetObjectNameA(p);
//		temp2 = outerName;
//		temp2.append(E("."));
//		temp2.append(temp);
//		temp = temp2;
//	}
//	//dprintf("16");
//
//	std::string shit;
//
//	shit.append(temp);
//	shit.append(objName);
//
//	auto last = find_last_of(shit, '/');
//	if (last != -1)
//		shit.push_back(last + 1);
//
//	name.append(className);
//	name.append(E(" "));
//	name.append(shit);
//
//	//name.append(" ");
//	//name.append(myitoa(last));
//
//	return name;
//}

uintptr_t GOffset_ComponentVelocity = 0;
uintptr_t GOffset_MovementComponent = 0;
uintptr_t GOffset_Acceleration = 0;

struct AFortWeapon_GetProjectileSpeed_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

void CallUFunction(UObject* obj, UFunction* fn, void* params)
{
	if (!obj || !fn)
		return;
	static int FunctionFlags_Offset = 0x88; //tried from 0x80 - 0x8e
	/*{
		char buf[40];
		sprintf_s(buf, "trying 0x%x\r\n", FunctionFlags_Offset);
		write_debug_log(buf);
	}

	auto flags = *(uint32_t*)((uint64_t)fn + FunctionFlags_Offset);
	//auto flags = fn->FunctionFlags;
	//fn->FunctionFlags |= 0x400;
	*(uint32_t*)((uint64_t)fn + FunctionFlags_Offset) |= 0x400;
	ProcessEvent(obj, fn, params);
	*(uint32_t*)((uint64_t)fn + FunctionFlags_Offset) = flags;

	//fn->FunctionFlags = flags;
}

void predict_hit(UObject* enemy, uint64_t local_weapon, FVector& pos, float distance)
{
	auto weapon_speed = GetWeaponBulletSpeed(local_weapon);
	if (weapon_speed == 0.f)
		return;

	auto rc = readA<uint64_t>((uintptr_t)enemy + DGOffset_RootComponent);

	if (!rc)
		return;

	float travel_time = distance / weapon_speed;
	auto velocity = get_velocity(rc);
	auto acceleration = get_acceleration((uintptr_t)enemy);
	velocity.X *= travel_time;
	velocity.Y *= travel_time;
	velocity.Z *= travel_time;
	if (acceleration.Size())
	{
		acceleration.X /= 2.f;
		acceleration.Y /= 2.f;
		acceleration.Z /= 2.f;
		acceleration.X *= pow(travel_time, 2.f);
		acceleration.Y *= pow(travel_time, 2.f);
		acceleration.Z *= pow(travel_time, 2.f);
	}

	pos += velocity + acceleration;

	double gravity = cached_bullet_gravity_scale * cached_world_gravity;

	pos.Z -= .5 * (gravity * travel_time * travel_time);
}

float GetWeaponBulletSpeed(uint64_t cwep)
{
	if (!cwep)
		return 0.f;
	//Function FortniteGame.FortWeapon.GetProjectileSpeed
	static UFunction* f = nullptr;
	if (!f)
		f = FindFunction(E("Function FortniteGame.FortWeapon.GetProjectileSpeed"));
	if (f)
	{
		AFortWeapon_GetProjectileSpeed_Params ret{};
		CallUFunction((UObject*)cwep, f, &ret);
		return ret.ReturnValue;
	}
	else
		return 0.f;
}

bool Object_IsA(UObject* obj, UObject* cmp)
{
	if (!cmp)
		return false;

	UINT i = 0;

	//dprintf(E(""));
	//dprintf(E("-> IsA %p (%s)"), cmp, GetObjectFullNameA(cmp).c_str());
	//dprintf(E(""));

	for (auto super = readA<uint64_t>((uint64_t)obj + offsetof(UObject, UObject::Class)); super; super = readA<uint64_t>(super + offsetof(UStruct, UStruct::SuperField)))
	{
		//dprintf(E("SF # %d -> 0x%p -> %s"), i, super, GetObjectFullNameA((UObject*)super).c_str());
		if (super == (uint64_t)cmp)
		{
			//dprintf(E("IsA: positive result"));
			return true;
		}
		i++;
	}

	//dprintf(E(""));
	//dprintf(E("-> IsA: bad result"));
	//dprintf(E(""));

	return false;
}

bool bLogFindObject = true;




UClass* SC_AHUD()
{
	static UClass* obj = 0;
	if (!obj)
		obj = UObject::FindObject<UClass>(xorstr_("Class Engine.HUD"));
	return obj;
}

using tUE4PostRender = void(*)(UObject* _this, UObject* canvas);

tUE4PostRender GoPR = 0;

FVector get_velocity(uint64_t root_comp)
{
	return readA<FVector>(root_comp + DGOffset_ComponentVelocity);
	/*
	if (!actor)
		return FVector();
	static UFunction* f = nullptr;
	if (!f)
		f = FindObject<UFunction>("Function Engine.Actor.GetVelocity");
	if (f) {
		AActor_GetVelocity_Params ret{};
		CallUFunction((UObject*)actor, f, &ret);
		return ret.ReturnValue;
	}
	else
		return FVector();
}

FVector get_acceleration(uint64_t target)
{
	if (auto char_movement = readA<uint64_t>(target + DGOffset_MovementComponent)) {
		return readA<FVector>(char_movement + DGOffset_Acceleration);
	}
	else
		return { 0, 0, 0 };
}

void HkPostRender(UObject* _this, UObject* canvas)
{
	if (!HOOKED)
		return GoPR(_this, canvas);

	tStarted = GetTickCount64();
	GCanvas = canvas;
	dprintf("hooking prerender");
	//MwMenuDraw();
	PreRender();
	dprintf("hooked prerender");
	tEnded = GetTickCount64();


	auto delta = (tEnded - tStarted);

	static auto old_delta = 0;

	if (delta == 0)
	{
		delta = old_delta;
	}
	else
	{
		old_delta = delta;
	}

	if (GCanvas && G::ShowTimeConsumed)
	{
		static char time_buff[256];
		static wchar_t time_buff_wide[256];
		sprintf(time_buff, E("PostRender: time consumed: %d"), delta);
		AnsiToWide(time_buff, time_buff_wide);
		K2_DrawText(GCanvas, GetFont(), time_buff_wide, { 30, 260 }, FVector2D(1.0f, 1.0f), Colors::LightGreen, 1.0f, FLinearColor(0, 0, 0, 255), FVector2D(), false, false, true, FLinearColor(0, 0, 0, 1.0f));
	}

	GoPR(_this, canvas);
}

void HookPE()
{
	dprintf(E("Hooking PE"));

	auto UWorld = GetWorld();

	auto GameInstance = readA<uint64_t>(UWorld + DGOffset_OGI);
	auto LocalPlayers = readA<uint64_t>(GameInstance + DGOffset_LocalPlayers);
	auto ULocalPlayer = readA<uint64_t>(LocalPlayers);

	auto UViewportClient = readA<uint64_t>(ULocalPlayer + DGOffset_ViewportClient);

	if (!UWorld || !ULocalPlayer || !UViewportClient)
	{
		dprintf(E("Bad world/localplayer/viewportshit"));
		return;
	}

	dprintf(E("ViewportClient name: %s"), GetObjectName((UObject*)UViewportClient).c_str());
	auto vpVt = *(void***)(UViewportClient);
	GoPR = (tUE4PostRender)vpVt[POSTRENDER_INDEX];
	SwapVtable((void*)UViewportClient, POSTRENDER_INDEX, HkPostRender);
	dprintf(E("Hooked the viewport client!"));
}

int g_MenuW = 500;
int g_MenuH = 470;


//uintptr_t GetGetGNameById()
//{
//	uintptr_t cs = 0;
//	int addy = 0;
//
//	cs = FindPattern(E("E8 ? ? ? ? 83 7C 24 ? ? 48 0F 45 7C 24 ? EB 0E"));
//	if (!cs)
//	{
//		dprintf(E("SS Fail (1)"));
//		cs = FindPattern(E("48 83 C3 20 E8 ? ? ? ?"));
//		addy = 4;
//	}
//	if (!cs)
//	{
//		dprintf(E("SS Fail (2)"));
//		addy = 0;
//		cs = FindPattern(E("E8 ? ? ? ? 48 8B D0 48 8D 4C 24 ? E8 ? ? ? ? 48 8B D8 E8 ? ? ? ?"));
//	}
//
//	if (!cs)
//	{
//		dprintf(E("SS Fail (3)"));
//		return 0;
//	}
//
//	cs += addy;
//
//	return cs;
//}

uintptr_t GetOffset(std::string propName)
{
	bLogFindObject = false;
	auto prop = UObject::FindObject<UObject>(propName.c_str());
	auto off = ((UProperty*)prop)->Offset;
	dprintf(E("Offset: %s -> 0x%X"), propName.c_str(), off);
	bLogFindObject = true;
	return off;
}

bool g_Chineese = false;
bool g_Russian = false;
bool g_Korean = false;

void drawFilledRect(const FVector2D& initial_pos, float w, float h, const FLinearColor& color);

void RegisterButtonControl(const FVector2D initial_pos, float w, float h, const FLinearColor color, int tabIndex = -1, bool* boundBool = nullptr)
{
	drawFilledRect(initial_pos, w, h, color);
	UControl bounds;
	bounds.Origin = initial_pos;
	bounds.Size = { w, h };
	if (tabIndex != -1)
	{
		bounds.bIsMenuTabControl = true;
		bounds.BoundMenuTabIndex = tabIndex;
	}
	else
	{
		bounds.BoundBool = boundBool;
		bounds.bIsMenuTabControl = false;
	}
	g_ControlBoundsList->push_back(bounds);
}


void S2(UFont* font, FVector2D sp, FLinearColor color, const wchar_t* string)
{
	K2_DrawText(GCanvas, font, string, sp, FVector2D(1, 1), color, 1.0f, FLinearColor(0, 0, 0, 255), FVector2D(), false, false, true, FLinearColor(0, 0, 0, 0.f));
}

FVector2D g_Clientarea;

FVector2D g_MenuInitialPos = { 400, 400 };

int g_MenuIndex = 1;

FLinearColor SkeetMenuOutline = COLLINMENU_COLOR_1;

void MenuDrawTabs()
{
	std::vector<const wchar_t*> pTabs;

	wchar_t strAimbot[7];
	memcpy(strAimbot, E(L"AIMBOT"), 7 * 2);

	wchar_t strVisuals[7];
	memcpy(strVisuals, E(L"VISUALS"), 8 * 2);

	wchar_t strMisc[7];
	memcpy(strMisc, E(L"MISC"), 5 * 2);

	pTabs.push_back(strAimbot);
	pTabs.push_back(strVisuals);
	pTabs.push_back(strMisc);

	auto inp = g_MenuInitialPos + FVector2D({ 20, 35 });

	static char logo_buff[256];
	static wchar_t logo_buff_wide[256];
	sprintf(logo_buff, E("gay"), E(__DATE__), E(__TIME__));
	AnsiToWide(logo_buff, logo_buff_wide);
	K2_DrawText(GCanvas, GetFont(), logo_buff_wide, g_MenuInitialPos + FVector2D({ 20, 11 }), FVector2D(1.0f, 1.0f), Colors::Black, 1.0f, FLinearColor(0, 0, 0, 255), FVector2D(), false, false, false, FLinearColor(0, 0, 0, 1.0f));

	auto tabsz = (g_MenuW - 40) / pTabs.size();
	tabsz -= 2;
	FVector2D ip = inp + FVector2D(2, 2);

	auto i = 0;
	for (int fuck = 0; fuck < pTabs.size(); fuck++)
	{
		auto tab = pTabs.at(fuck);


		auto clr2 = Colors::Black;
		auto clr = Colors::Black;
		if (g_MenuIndex == i)
		{
			clr = Colors::White;
			clr2 = Colors::Black;
		}

		RegisterButtonControl(ip, tabsz, 22, clr2, i);

		S2(GetFont(), { ip.X + tabsz / 2 - (lstrlenW((LPCWSTR)tab) * 10) / 2, ip.Y + 3 }, clr, (wchar_t*)tab);
		K2_DrawText(GCanvas, GetFont(), tab, { ip.X + tabsz / 2 - (lstrlenW((LPCWSTR)tab) * 10) / 2, ip.Y + 3 }, FVector2D(1.0f, 1.0f), clr, 1.0f, FLinearColor(0, 0, 0, 255), FVector2D(), false, false, false, FLinearColor(0, 0, 0, 1.0f));
		K2_DrawText(GCanvas, GetFont(), logo_buff_wide, g_MenuInitialPos + FVector2D({ 20, 11 }), FVector2D(1.0f, 1.0f), Colors::Black, 1.0f, FLinearColor(0, 0, 0, 255), FVector2D(), false, false, false, FLinearColor(0, 0, 0, 1.0f));

		//drawFilledRect(ip-2, 2, 22, clr);
		ip.X += tabsz + 2;
		i++;
	}

	g_Clientarea = inp + FVector2D(0, 35);
}

FLinearColor SkeetMenuBg = { 1 , 1 , 1 , 1.000000000f };

void MenuCheckbox(FVector2D sp, const wchar_t* text, bool* shittobind)
{
	auto color = *shittobind ? Colors::Green : Colors::SlateGray;
	sp.X += 3;
	FLinearColor gayshit = { 0.06f, 0.06f, 0.06f, 1.000000000f };
	RegisterButtonControl(sp + g_Clientarea, 15, 15, gayshit, -1, shittobind);
	drawFilledRect(sp + g_Clientarea + 3, 9, 9, color);
	K2_DrawText(GCanvas, GetFont(), text, sp + g_Clientarea + FVector2D({ 20, -2 }), FVector2D(1.0f, 1.0f), Colors::White, 1.0f, FLinearColor(0, 0, 0, 255), FVector2D(), false, false, true, FLinearColor(0, 0, 0, 0));
}

void MenuSlider(FVector2D sp, const wchar_t* text, int* shittobind, int min, int max);

void RegisterSliderControl(FVector2D initial_pos, float w, float h, const FLinearColor color, int* boundShit, int min, int max)
{
	drawFilledRect(initial_pos, w, h, color);
	UControl bounds;
	initial_pos.Y -= 10;
	h += 10;
	bounds.Origin = initial_pos;
	bounds.Size = { w, h };
	bounds.BoundMenuTabIndex = 0;
	bounds.bIsMenuTabControl = false;
	bounds.pBoundRangeValue = boundShit;
	bounds.RangeValueMin = min;
	bounds.RangeValueMax = max;
	bounds.bIsRangeSlider = true;
	g_ControlBoundsList->push_back(bounds);
}

float g_SliderScale;



void MenuSlider(FVector2D sp, const wchar_t* text, int* shittobind, int min, int max)
{
	g_SliderScale = 462;//g_MenuW * 0.5;

	auto g_Canvas = GCanvas;
	sp.Y += 30;
	RegisterSliderControl(sp + g_Clientarea, g_SliderScale, 4, Colors::White, shittobind, min, max);
	auto sp1 = sp + g_Clientarea + FVector2D((*shittobind) * ((g_SliderScale) / (max - min)), 0);
	auto sp2 = sp1;
	sp2.Y -= 5;
	sp1.Y += 5;
	auto fMain = GetFont();

	auto textpos = g_Clientarea + sp + FVector2D({ 0, -26 });

	K2_DrawLine(GCanvas, sp1, sp2, 5, SkeetMenuOutline);
	//xDrawText(wstring(*shittobind).c_str(), sp + g_Clientarea + FVector2D((*shittobind) * ((g_SliderScale) / (max - min)), 10), Colors::White);
	//K2_DrawText(GCanvas, fMain, to_wstring(*shittobind).c_str(), sp + g_Clientarea + FVector2D((*shittobind) * ((g_SliderScale) / (max - min)), 10), Colors::White, 1.0f, FLinearColor(0, 0, 0, 255), FVector2D(), false, false, true, FLinearColor(0, 0, 0, 0));
	//xDrawText(to_wstring(max).c_str(), sp + g_Clientarea + FVector2D(g_SliderScale, 10), Colors::White, -1);
	//K2_DrawText(GCanvas, fMain, to_wstring(min).c_str(), sp + g_Clientarea + FVector2D(0, 10), FVector2D(), Colors::White, 1.0f, FLinearColor(0, 0, 0, 255), FVector2D(), false, false, true, FLinearColor(0, 0, 0, 0));
	//K2_DrawText(GCanvas, fMain, text, textpos, FVector2D(), Colors::White, 1.0f, FLinearColor(0, 0, 0, 255), FVector2D(), false, false, true, FLinearColor(0, 0, 0, 0));
}

void Render_Slider(const wchar_t* name, float minimum, float maximum, float* val, FVector2D* loc);

void MenuDrawItemsFor(int index)
{
	if (index == 0)
	{
		auto loc = g_Clientarea;
		Render_Toggle(loc, E(L"Enable aimbot"), &G::AimbotEnable);
		//Render_Toggle(loc, E(L"Use mouse left/right buttons instead of side buttons"), &G::AimbotUseRightButton);
		Render_Toggle(loc, E(L"Building weaks spot aimbot on CAPS_LOCK"), &G::WeakSpotAimbot);
		Render_Toggle(loc, E(L"Disable collision when aimbotting (noclip) (F2 on/off)"), &G::CollisionDisableOnAimbotKey);
		Render_Toggle(loc, E(L"Bodyaim"), &G::Baim);
		Render_Slider(E(L"FOV"), 0, 90, &AimbotFOV, &loc);
		Render_Slider(E(L"Smooth"), 0, 1, &G::Smooth, &loc);
		Render_Slider(E(L"Aimbot key"), 0, 200, &AimbotKey, &loc);
		Render_Slider(E(L"WeakSpot aimbot key"), 0, 200, &WeakSpotAimbotKey, &loc);
		AimbotKey = (float)(int)(AimbotKey);
		WeakSpotAimbotKey = (float)(int)(WeakSpotAimbotKey);
		//MenuCheckbox({ 0, 20 * 3 }, E(L"Aim at bots"), &G::AimbotTargetZombies);
	}
	if (index == 1)
	{
		auto loc = g_Clientarea;
		Render_Toggle(loc, E(L"Enable hack"), &G::EnableHack);
		Render_Toggle(loc, E(L"Supply crates / Llamas"), &G::EspSupplyDrops);
		Render_Toggle(loc, E(L"Rifts"), &G::EspRifts);
		Render_Toggle(loc, E(L"Loot / dropped items"), &G::EspLoot);
		Render_Toggle(loc, E(L"Vehicles"), &G::EspVehicles);
		Render_Toggle(loc, E(L"Traps"), &G::EspTraps);
		Render_Toggle(loc, E(L"Chests / ammo (F1)"), &G::Chests);
		Render_Toggle(loc, E(L"Player weapons"), &G::EspWeapon);
		Render_Toggle(loc, E(L"Player name"), &G::EspPlayerName);
		Render_Toggle(loc, E(L"Player skeleton"), &G::Skeletons);
		Render_Toggle(loc, E(L"Player box"), &G::EspBox);
		Render_Toggle(loc, E(L"Draw red snaplines in RED radius"), &G::SnaplinesIn50m);
		Render_Toggle(loc, E(L"Draw snaplines (always)"), &G::Snaplines);
		Render_Toggle(loc, E(L"Slicing on snaplines"), &G::PunktierSnaplines);
		Render_Toggle(loc, E(L"CornerBox"), &G::CornerBox);
		Render_Toggle(loc, E(L"Draw local player / self"), &G::DrawSelf);

		loc.Y = g_Clientarea.Y;
		loc.X += g_MenuW / 2;

		Render_Slider(E(L"Supply / Loot distance"), 50, 500, &G::LootRenderDist, &loc);
		Render_Slider(E(L"Chests / ammo distance"), 50, 500, &G::ChestsRdist, &loc);
		Render_Slider(E(L"Overall ESP render distance"), 1, 650, &G::RenderDist, &loc);
		Render_Slider(E(L"RED distance"), 1, 300, &G::RedDistance, &loc);
		Render_Slider(E(L"Loot minimal tier"), 1, 5, &G::LootTier, &loc);
		Render_Slider(E(L"Snapline slicing power"), 1, 20, &G::PunktierPower, &loc);
		Render_Slider(E(L"CornerBox corner lines scale"), 0, 1, &G::CornerBoxScale, &loc);
		Render_Slider(E(L"CornerBox thickness"), 1, 4, &G::CornerBoxThicc, &loc);
	}
	if (index == 2)
	{
		auto loc = g_Clientarea;
#ifdef GLOBAL_DEBUG_FLAG
		Render_Toggle(loc, E(L"Projectile TP"), &G::ProjectileTpEnable);
		Render_Toggle(loc, E(L"Flying vehicles"), &G::FlyingCars);
#endif GLOBAL_DEBUG_FLAG
		Render_Toggle(loc, E(L"Outline enable"), &G::Outline);
		Render_Toggle(loc, E(L"Show time consumed"), &G::ShowTimeConsumed);
		Render_Toggle(loc, E(L"Use engine W2S"), &G::UseEngineW2S);
		Render_Toggle(loc, E(L"Refresh resolution each 1 second"), &G::RefreshEach1s);
	}
}

void drawRect(const FVector2D initial_pos, float w, float h, const FLinearColor color, float thickness = 1.f)
{
	K2_DrawLine(GCanvas, initial_pos, FVector2D(initial_pos.X + w, initial_pos.Y), thickness, color);
	K2_DrawLine(GCanvas, initial_pos, FVector2D(initial_pos.X, initial_pos.Y + h), thickness, color);
	K2_DrawLine(GCanvas, FVector2D(initial_pos.X + w, initial_pos.Y), FVector2D(initial_pos.X + w, initial_pos.Y + h), thickness, color);
	K2_DrawLine(GCanvas, FVector2D(initial_pos.X, initial_pos.Y + h), FVector2D(initial_pos.X + w, initial_pos.Y + h), thickness, color);
}

void drawFilledRect(const FVector2D& initial_pos, float w, float h, const FLinearColor& color)
{
	for (float i = 0.f; i < h; i += 1.f)
		K2_DrawLine(GCanvas, FVector2D(initial_pos.X, initial_pos.Y + i), FVector2D(initial_pos.X + w, initial_pos.Y + i), 1.f, color);
}

void K2_DrawBox(UObject* canvas, const struct FVector2D& ScreenPosition, const struct FVector2D& ScreenSize, float Thickness)
{
	static UFunction* fn = 0; if (!fn) fn = FindFunction(E("Function Engine.Canvas.K2_DrawBox"));

	struct
	{
		struct FVector2D               ScreenPosition;
		struct FVector2D               ScreenSize;
		float                          Thickness;
	} params;

	params.ScreenPosition = ScreenPosition;
	params.ScreenSize = ScreenSize;
	params.Thickness = Thickness;

	ProcessEvent(canvas, fn, &params);
}

void MwMenuDraw()
{
#define MENU_OUTLINE_THICC 2
	//drawRect(
	//	g_MenuInitialPos - MENU_OUTLINE_THICC,  // initialpos
	//	g_MenuW - 1 + MENU_OUTLINE_THICC,
	//	g_MenuH - 1 + MENU_OUTLINE_THICC,
	//	SkeetMenuOutline,
	//	MENU_OUTLINE_THICC);

	drawFilledRect(g_MenuInitialPos, g_MenuW - MENU_OUTLINE_THICC, g_MenuH - MENU_OUTLINE_THICC, SkeetMenuBg);
	MenuDrawTabs();
	MenuDrawItemsFor(g_MenuIndex);
	if (g_MX && g_MY)
	{
		K2_DrawBox(GCanvas, { (float)g_MX - 2, (float)g_MY - 1 }, { 4, 4 }, 4);
	}
	//dprintf("MenuDrawing5\n");
	//dprintf(E("5"));
	//MenuCheckbox({ 0, (20 * 43) - 180 }, E(L"Включить русский язык"), &g_Russian);
	//MenuCheckbox({ 0, (20 * 44) - 180 }, E(L"한국어 사용 가능"), &g_Korean);
	//MenuCheckbox({ 0 , (20 * 45) - 180 }, E(L"选中文"), &g_Chineese);
}

void PatchFuncRet0(void* fn)
{
	uint8_t patch[] = { 0x31, 0xC0, 0xC3 };
	DWORD old;
	DWORD old2;
	VirtualProtect(fn, 3, PAGE_EXECUTE_READWRITE, &old);
	memcpy(fn, patch, 3);
	VirtualProtect(fn, 3, old, &old2);
}

void PatchFwFuncs()
{
	printf(E("Patching FW funcs"));

	void* funcs[] = { EnumWindows };
	for (auto x : funcs)
		PatchFuncRet0(x);

	printf(E("Done"));
}



uintptr_t GetGEngine()
{
	auto ss = FindPattern(E("48 8B 0D ? ? ? ? 45 0F B6 C6 F2 0F 10 0D ? ? ? ? 66 0F 5A C9 48 8B 11 FF 92 ? ? ? ? "));
	if (!ss)
	{
		dprintf(E("SS Failed (1) !"));
		return ss;
	}

	return (*(int32_t*)(ss + 3) + ss + 7);
}

LRESULT HkWndProcInternal(uintptr_t unk, HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

using tWndProc = decltype(&HkWndProcInternal);

tWndProc G_oWndProc = 0;

#define GET_X_LPARAM(lp)                        ((int)(short)LOWORD(lp))
#define GET_Y_LPARAM(lp)                        ((int)(short)HIWORD(lp))

int g_MenuDragStartX = 0;
int g_MenuDragStartY = 0;

bool bDragging = 0;

void MenuProcessClick(int x, int y)
{
	if (!g_ControlBoundsList)
		dprintf(E("No controlbounds list"));

	if (g_ControlBoundsList && g_Menu)
	{
		//dprintf(E("g_ControlBounds list size %d"), g_ControlBoundsList->size());
		for (auto fuck = 0; fuck < g_ControlBoundsList->size(); fuck++)
		{
			auto bi = g_ControlBoundsList->at(fuck);
			if (bi.ContainsPoint({ (float)x, (float)y }))
			{
				if (bi.bIsMenuTabControl)
				{
					g_MenuIndex = bi.BoundMenuTabIndex;
				}
				else if (bi.BoundBool)
				{
					*bi.BoundBool = !*bi.BoundBool;

					if ((bi.BoundBool == &g_Russian) && *bi.BoundBool
						&& (g_Chineese || g_Korean)) // wanna enable russian but chineese is enabled
					{
						g_Korean = false;
						g_Chineese = false;
					}
					else if ((bi.BoundBool == &g_Chineese) && *bi.BoundBool && (g_Russian || g_Korean))
					{
						g_Korean = false;
						g_Russian = false;
					}
					else if ((bi.BoundBool == &g_Korean) && *bi.BoundBool && (g_Chineese || g_Russian))
					{
						g_Russian = false;
						g_Chineese = false;
					}
				}
				else if (bi.pBoundRangeValue)
				{
					auto how_far_clicked = g_MX - bi.Origin.X;
					if (how_far_clicked <= 0)
						continue;

					how_far_clicked *= (bi.RangeValueMax - bi.RangeValueMin) / (g_SliderScale);

					auto delta = how_far_clicked - *bi.pBoundRangeValue;
					auto willbe = *bi.pBoundRangeValue + delta;
					if (willbe >= bi.RangeValueMin && willbe <= bi.RangeValueMax)
						*bi.pBoundRangeValue = willbe;
				}
			}
		}
	}
}

bool IsInMenu(int x, int y)
{
	return (x >= g_MenuInitialPos.X) && (x <= g_MenuInitialPos.X + g_MenuW) && (y >= g_MenuInitialPos.Y) && (y <= g_MenuInitialPos.Y + g_MenuH);
}

WNDPROC G_oWndProcUnsafe = 0;

using tCallWindowProcW = decltype(&CallWindowProcW);
tCallWindowProcW fnCallWindowProcW;

LRESULT
WINAPI
myCallWindowProcW(
	_In_ WNDPROC lpPrevWndFunc,
	_In_ HWND hWnd,
	_In_ UINT Msg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam)
{
	return fnCallWindowProcW(lpPrevWndFunc, hWnd, Msg, wParam, lParam);
}

void SetIgnoreLookInput(bool bNewLookInput)
{
	static UFunction* fn = 0; if (!fn) fn = FindFunction(E("Function Engine.Controller.SetIgnoreLookInput"));

	struct
	{
		bool                           bNewLookInput;
	} params;

	params.bNewLookInput = bNewLookInput;

	ProcessEvent((UObject*)GController, fn, &params);
}

int myceilf(float num)
{
	int inum = (int)num;
	if (num == (float)inum) {
		return inum;
	}
	return inum + 1;
}

void ResetIgnoreLookInput()
{
	static UFunction* fn = 0; if (!fn) fn = fn = FindFunction(E("Function Engine.Controller.ResetIgnoreLookInput"));

	struct
	{
	} params;

	ProcessEvent((UObject*)GController, fn, &params);
}

#define M_PI 3.14159265358979323846264338327950288419716939937510582f
#define D2R(d) (d / 180.f) * M_PI
#define MAX_SEGMENTS 180

void Render_Line(FVector2D one, FVector2D two, FLinearColor color)
{
	K2_DrawLine(GCanvas, one, two, 1, color);
}

void Render_Circle(FVector2D pos, int r, FLinearColor color)
{
	float circum = M_PI * 2.f * r;
	int seg = myceilf(circum);

	if (seg > MAX_SEGMENTS) seg = MAX_SEGMENTS;

	float theta = 0.f;
	float step = 180.f / seg;

	for (size_t i = 0; i < seg; ++i)
	{
		theta = i * step;
		auto delta = FVector2D(round(r * sin(D2R(theta))), round(r * cos(D2R(theta))));
		Render_Line(pos + delta, pos - delta, color);
	}
}

void Render_Clear(FVector2D one, FVector2D two, FLinearColor color)
{
	for (auto x = one.X; x < two.X; x += 1.f)
	{
		K2_DrawLine(GCanvas, FVector2D(x, one.Y), FVector2D(x, two.Y), 1.f, color);
	}
}


void Render_PointArray(size_t count, FVector2D* ary, FLinearColor color)
{
	for (size_t i = 1; i < count; ++i)
		Render_Line(ary[i - 1], ary[i], color);
}

void Render_CircleOutline(FVector2D pos, int r, FLinearColor outline)
{
	float circum = M_PI * 2.f * r;
	int seg = myceilf(circum);

	if (seg > MAX_SEGMENTS) seg = MAX_SEGMENTS;

	float theta = 0.f;
	float step = 360.f / seg;

	FVector2D points[MAX_SEGMENTS] = {};

	for (size_t i = 0; i < seg; ++i)
	{
		theta = i * step;
		points[i] = FVector2D(pos.X + roundf(r * sin(D2R(theta))), pos.Y + roundf(r * cos(D2R(theta))));
	}

	Render_PointArray(seg, points, outline);
}

void Render_CircleOutlined(FVector2D pos, int r, FLinearColor fill, FLinearColor outline)
{
	Render_Circle(pos, r, fill);
	Render_CircleOutline(pos, r, outline);
}

void Render_MenuText(const wchar_t* text, FLinearColor col, FVector2D loc, bool centered)
{
	//	ctx->Canvas->K2_DrawText(ctx->menu_font(), _X(L"Colors"), FVector2D(tabx + tab_width / 2.f - 2.f, menu_y + 31), (i == tab_index) ? FLinearColor(1.f, 1.f, 1.f, 1.f) : menu_color1, 1.f, FLinearColor(), FVector2D(), true, true, true, FLinearColor(0, 0, 0, 1.f));

	K2_DrawText(GCanvas, GetFont(), text, loc, FVector2D(0.0f, 0.0f), Colors::Black, 0.0f, FLinearColor(), FVector2D(), centered, centered, false, FLinearColor(0, 0, 0, 1.f));
}

void Render_Slider(const wchar_t* name, float minimum, float maximum, float* val, FVector2D* loc)
{
	//auto menu_color1 = FLinearColor(0.8f, 0.f, 0.4f, 1.f);
	auto kinda_white = FLinearColor(0.8f, 0.8f, 0.8f, 1.f);

	constexpr float _width = 180 + 19;

	//ctx->Canvas->K2_DrawText(ctx->menu_font(), name, FVector2D(loc->X + 6, loc->Y + 10), FLinearColor(255, 255, 255, 255), 1.f, FLinearColor(), FVector2D(), false, true, true, FLinearColor(0, 0, 0, 255));
	Render_MenuText(name, Colors::White, FVector2D(loc->X + 6, loc->Y), false);

	loc->X += 6.f;

	/*bool hover = k->mouseX > loc->X && k->mouseX < (loc->X + _width) && k->mouseY > loc->Y && k->mouseY < (loc->Y + 30);
	if (k->mouse[0] && hover)
	{
		float ratio = (float)(k->mouseX - loc->X) / _width;
		if (ratio < 0.f) ratio = 0.f;
		if (ratio > 1.f) ratio = 1.f;
		*val = minimum + ((maximum - minimum) * ratio);
	}

	int xpos = ((*val - minimum) / (maximum - minimum)) * _width;
	loc->Y += 24.f;

	Render_Circle(*loc, 3, COLLINMENU_COLOR_1);
	Render_Clear(FVector2D(loc->X, loc->Y - 3), FVector2D(loc->X + xpos, loc->Y + 3), COLLINMENU_COLOR_1);

	Render_Clear(FVector2D(loc->X + xpos, loc->Y - 3), FVector2D(loc->X + _width, loc->Y + 3), kinda_white);
	Render_Circle(FVector2D(loc->X + _width, loc->Y), 3, kinda_white);

	Render_CircleOutlined(FVector2D(loc->X + xpos, loc->Y), 5, Colors::White, Colors::Black);

	loc->Y -= 24.f;

	wchar_t wstr[16] = {};
	char __str[16] = {};
	sprintf(__str, E("%0.1f"), *val);
	AnsiToWide(__str, wstr);
	//ctx->Canvas->K2_DrawText(ctx->menu_font(), FString(wstr), FVector2D(loc->X + _width - 20.f, loc->Y + 10), FLinearColor(255, 255, 255, 255), 1.f, FLinearColor(), FVector2D(), false, true, false, FLinearColor());
	Render_MenuText(wstr, Colors::White, FVector2D(loc->X + _width - 30.0f, loc->Y + 33), false);

	loc->X -= 6.f;
	loc->Y += 35.0f;
	loc->Y += 13.0f;
}

void Render_Toggle(FVector2D& loc_ref, const wchar_t* name, bool* on)
{
	//auto menu_color1 = FLinearColor(0.8f, 0.f, 0.4f, 1.f);

	//loc_nonp += g_Clientarea;

	auto loc = &loc_ref;

	bool hover;
	//bool hover = k->mouseX > loc->X && k->mouseX < (loc->X + 64) && k->mouseY > loc->Y && k->mouseY < (loc->Y + 20);

	//if (k->mouse[0] && hover)
	//{
		//*on = !*on;
		//k->mouse[0] = true;
	//}

	FLinearColor col = *on ? COLLINMENU_COLOR_1 : FLinearColor(1.f, 1.f, 1.f, 1.f);

	Render_Circle(FVector2D(loc->X + 10, loc->Y + 10), 6, col);
	Render_Circle(FVector2D(loc->X + 18, loc->Y + 10), 6, col);
	Render_Clear(FVector2D(loc->X + 10, loc->Y + 4), FVector2D(loc->X + 18, loc->Y + 16), col);

	if (*on)
	{
		Render_CircleOutlined(FVector2D(loc->X + 18, loc->Y + 10), 5, hover ? FLinearColor(0.8f, 0.8f, 0.8f, 1.f) : FLinearColor(1, 1, 1, 1), FLinearColor(0, 0, 0, 1.f));
		Render_Line(FVector2D(loc->X + 9, loc->Y + 8), FVector2D(loc->X + 9, loc->Y + 12), FLinearColor(0, 0, 0, 1.f));
	}
	else
	{
		Render_CircleOutlined(FVector2D(loc->X + 10, loc->Y + 10), 5, hover ? FLinearColor(0.8f, 0.8f, 0.8f, 1.f) : FLinearColor(1, 1, 1, 1), FLinearColor(0, 0, 0, 1.f));
		Render_CircleOutline(FVector2D(loc->X + 19, loc->Y + 10), 2, FLinearColor(0, 0, 0, 1.f));
	}

	//ctx->Canvas->K2_DrawText(ctx->menu_font(), name, FVector2D(loc->X + 32, loc->Y + 10), FLinearColor(255, 255, 255, 255), 1.f, FLinearColor(), FVector2D(), false, true, true, FLinearColor(0, 0, 0, 255));
	Render_MenuText(name, Colors::Black, FVector2D(loc->X + 32, loc->Y + 2), false);

	loc->Y += 25.0f;
}

void WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_MBUTTONDOWN:
	{
		int button = 0;
		//if (msg == WM_LBUTTONDOWN) button = 0;
		if (msg == WM_RBUTTONDOWN) button = 1;
		if (msg == WM_MBUTTONDOWN) button = 2;
		k->mouse[button] = true;
		return;
	}
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MBUTTONUP:
	{
		int button = 0;
		//if (msg == WM_LBUTTONUP) button = 0;
		if (msg == WM_RBUTTONUP) button = 1;
		if (msg == WM_MBUTTONUP) button = 2;
		k->mouse[button] = false;
		return;
	}
	case WM_MOUSEWHEEL:
		k->mouse_wheel += GET_WHEEL_DELTA_WPARAM(wParam) > 0 ? +1.0f : -1.0f;
		return;
	case WM_MOUSEMOVE:
		k->mouseX = (signed short)(lParam);
		k->mouseY = (signed short)(lParam >> 16);
		return;
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
		if (wParam < 256)
			k->key[wParam] = true;
		return;
	case WM_KEYUP:
	case WM_SYSKEYUP:
		if (wParam < 256)
			k->key[wParam] = false;
		return;
		//case WM_CHAR:
		//	// You can also use ToAscii()+GetKeyboardState() to retrieve characters.
		//	if (wParam > 0 && wParam < 0x10000)
		//		io.AddInputCharacter((unsigned short)wParam);
		//	return 0;
	}
}

LRESULT HkWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	auto x = 0;
	auto y = 0;

	if (!HOOKED)
		goto fok_u;

	if (!k)
	{
		auto fuck_cpp = new uint8_t[sizeof(keys)];
		k = (keys*)fuck_cpp;
	}

	WndProcHandler(hWnd, msg, wParam, lParam);

	switch (msg)
	{

	case WM_SIZE:
		if (wParam != SIZE_MINIMIZED)
		{
			dprintf(E("Resize event"));
			RECT rect;
			if (GHGameWindow && GetWindowRect(GHGameWindow, &rect))
			{
				g_ScreenWidth = rect.right - rect.left;
				g_ScreenHeight = rect.bottom - rect.top;
				dprintf(E("Resized %d %d"), g_ScreenWidth, g_ScreenHeight);
			}
		}
		break;

	case WM_MOUSEMOVE:
		g_MX = GET_X_LPARAM(lParam);
		g_MY = GET_Y_LPARAM(lParam);
		if (bDragging)
		{
			auto newX = g_MenuInitialPos.X + g_MX - g_MenuDragStartX;
			auto newY = g_MenuInitialPos.Y + g_MY - g_MenuDragStartY;
			if (newX >= g_ScreenWidth - g_MenuW)
				newX = g_ScreenWidth - g_MenuW;
			if (newY >= g_ScreenHeight - g_MenuH)
				newY = g_ScreenHeight - g_MenuH;
			if (newX <= 0)
				newX = 0;
			if (newY <= 0)
				newY = 0;

			g_MenuInitialPos.X = newX;
			g_MenuInitialPos.Y = newY;
			g_MenuDragStartX = g_MX;
			g_MenuDragStartY = g_MY;
		}
		break;

	case WM_LBUTTONUP:
		bDragging = false;
		x = GET_X_LPARAM(lParam);
		y = GET_Y_LPARAM(lParam);
		//dprintf(E("Processing un-click at %d %d"), x, y);
		MenuProcessClick(x, y);
		break;

	case WM_LBUTTONDOWN:
		if (IsInMenu(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)))
		{
			bDragging = true;
			g_MenuDragStartX = GET_X_LPARAM(lParam);
			g_MenuDragStartY = GET_Y_LPARAM(lParam);

			//dprintf(E("Processing click at %d %d"), g_MenuDragStartX, g_MenuDragStartY);
		}
		break;
	}

	if (msg == WM_KEYUP)
	{
		auto nVirtKey = (int)wParam;
		if (nVirtKey == VK_HOME)
		{
			dprintf(E("MENU HOTKEY HIT"));
			g_Menu = !g_Menu;
			if (g_Menu)
			{
				if (!IsBadReadPtr((void*)GController, 0x8))
				{
					SetIgnoreLookInput(true);
				}
			}
			else
			{
				if (!IsBadReadPtr((void*)GController, 0x8))
				{
					SetIgnoreLookInput(false);
				}
			}
		}
		else if (nVirtKey == VK_PRIOR)
		{
			if (G::LootTier != 5)
				G::LootTier++;
		}
		else if (nVirtKey == VK_NEXT)
		{
			if (G::LootTier != 1)
				G::LootTier--;
		}
		else if (nVirtKey == VK_NUMPAD5)
		{
#ifdef GLOBAL_UNLOAD_FLAG
			HOOKED = false;
#endif
		}
		else if (nVirtKey == VK_F1)
		{
			G::Chests = !G::Chests;
		}
		else if (nVirtKey == VK_F2)
		{
			G::CollisionDisableOnAimbotKey = !G::CollisionDisableOnAimbotKey;
		}
	}

	if (g_Menu && (msg == WM_LBUTTONDOWN || msg == WM_LBUTTONUP || msg == WM_LBUTTONDBLCLK || msg == WM_MOUSEMOVE))
	{
		if (IsInMenu(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)))
			return 0x0;
	}

fok_u:

	return myCallWindowProcW(G_oWndProcUnsafe, hWnd, msg, wParam, lParam);
}

LRESULT HkWndProcInternal(uintptr_t unk, HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HkWndProc(hWnd, msg, wParam, lParam);

	return G_oWndProc(unk, hWnd, msg, wParam, lParam);
}

void HookWndProcSafe()
{
	auto callSite = FindPattern(E("48 8B 0D ? ? ? ? 4C 8B CF 44 8B C6 48 89 5C 24 20 48 8B D5 E8 ? ? ? ?"));
	if (callSite)
	{
		printf(E("Found call site"));
		callSite += 21;
		auto func = ResolveRelativeReference(callSite, 0);
		printf(E("Function offset: 0x%p\n"), func - GFnBase);
		uint8_t origBytes[12];
		uint8_t jmp[] = { 0x48, 0xB8, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xFF, 0xE0 };
		memcpy(origBytes, (void*)func, 12);

		DWORD old;
		DWORD old2;

		auto trampoline = GFnBase + 0x1100;
		uint8_t trampolineBytes[24];
		memcpy(trampolineBytes, origBytes, 12);
		*(uintptr_t*)(jmp + 2) = (uintptr_t)func + 12;
		memcpy((void*)((uintptr_t)trampolineBytes + 12), jmp, 12);

		VirtualProtect((void*)trampoline, 24, PAGE_EXECUTE_READWRITE, &old);
		memcpy((void*)trampoline, trampolineBytes, 24);
		//myVirtualProtect((void*)trampoline, 24, old, &old2);

		VirtualProtect((void*)func, 12, PAGE_EXECUTE_READWRITE, &old);
		*(uintptr_t*)(jmp + 2) = (uintptr_t)HkWndProcInternal;
		memcpy((void*)func, jmp, 12);
		VirtualProtect((void*)func, 12, old, &old2);

		printf(E("Hook done!"));
		G_oWndProc = (tWndProc)trampoline;
	}
	else
	{
		printf(E("HookWndProc: FindPattern fucked up"));
	}
}

//void HookWndProcUnsafe()
//{
//	G_oWndProcUnsafe = (WNDPROC)GetWindowLongPtrA(GHGameWindow, GWLP_WNDPROC);
//	dprintf(E("G_oWndProcUnsafe: 0x%p"), G_oWndProcUnsafe);
//	SetWindowLongPtrA(GHGameWindow, GWLP_WNDPROC, (LONG_PTR)HkWndProc);
//	dprintf(E("SetWindowLongPtr done!"));
//}

void HookWndProcUnsafe()
{
	G_oWndProcUnsafe = reinterpret_cast<WNDPROC>(SetWindowLongPtr(GHGameWindow, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(HkWndProc)));
}

void InitializeWindowData()
{
	g_ControlBoundsList = new std::vector<UControl>();
	RECT rect;
	GHGameWindow = FindWindowA(E("UnrealWindow"), 0);

	dprintf(E("GHGameWindow: 0x%X"), GHGameWindow);

	if (GetWindowRect(GHGameWindow, &rect))
	{
		g_ScreenWidth = rect.right - rect.left;
		g_ScreenHeight = rect.bottom - rect.top;
	}

	fnCallWindowProcW = CallWindowProcW;

}



uintptr_t GetTraceVisibilityFn()
{
	return FindPattern(E("48 8B C4 48 89 58 20 55 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 44 0F 29 40 ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 20 45 8A E9"));

}


void main()
{

	GHookedObjects = new std::vector<void*>();

	MODULEINFO info;
	//spoof_call(g_pSpoofGadget, K32GetModuleInformation, GetCurrentProcess(), GetModuleHandle(0), &info, (DWORD)sizeof(info));
	K32GetModuleInformation(GetCurrentProcess(), GetModuleHandle(0), &info, (DWORD)sizeof(info));

	GFnBase = (uintptr_t)info.lpBaseOfDll;
	GFnSize = (uintptr_t)info.SizeOfImage;

	dprintf(E("GFnBase: 0x%p, GFnSize: 0x%X"), GFnBase, GFnSize);

	g_pSpoofGadget = (unsigned char*)FindSpooferFromModule((void*)GFnBase);
	dprintf(E("New Spoof gadget: 0x%p"), g_pSpoofGadget);

	//PatchFwFuncs();

	GObjects = (TObjectEntryArray*)(GetGObjects());

	if (!GObjects)
	{
		dprintf(E("Failed to initialize GObjects!"));
		return;
	}
	else
		dprintf(E("GObjects OK"));

	//GGetNameFromId = (tGetNameFromId)(GetGetGNameById());

	//if (!GGetNameFromId)
	//{
	//	dprintf(E("Failed to initialize GetGNameById!"));
	//	return;
	//}
	//else
	//	dprintf(E("GetNameShit OK"));

	//pGEngine = (UObject**)GetGEngine();

	//if (pGEngine)
	//{
	//	dprintf(E("GEngine OK"));
	//}
	//else
	//{
	//	dprintf(E("No GEngine!"));
	//	return;
	//}

	//GTraceVisibilityFn = (tTraceVisibility)GetTraceVisibilityFn();


	//GEngine = *pGEngine;

#ifdef GLOBAL_DEBUG_FLAG

	auto pUWorldRefFunc = FindPattern(E("48 89 05 ? ? ? ? 48 8B 8B ? ? ? ?"));
	pUWorldRefFunc = reinterpret_cast<decltype(pUWorldRefFunc)>(RVA(pUWorldRefFunc, 7));


	// 40 57 48 83 EC 50 48 8B 49 08 8B FA 48 83 C1 30

	if (!pUWorldRefFunc)
	{
		dprintf(E("No UWorld ref func!"));
		return;
	}
	else
	{
		dprintf((E("UWorld ref found!")));
	}

	/*for (int i = 0; i < 0x100; i++)
	{
		if (MemoryBlocksEqual(&PBYTE(pUWorldRefFunc)[i], (PBYTE)"\x48\x8B\x05", 3))
		{
			auto f = pUWorldRefFunc + i;
			auto offset = *PINT(f + 3);
			UWorldOffset = (f + offset + 7) - (uintptr_t)GFnBase;
			dprintf(E("UWorldOffset: 0x%X"), UWorldOffset);
		}
	}

	//PrintNames(0);
	//PrintObjects(0);

#else

	UWorldOffset = DGOffset_GWorld;

#endif


	//#ifdef GLOBAL_DEBUG_FLAG
	//
	//	GOffset_OGI = GetOffset(E("ObjectProperty Engine.World.OwningGameInstance"));
	//	GOffset_LocalPlayers = GetOffset(E("ArrayProperty Engine.GameInstance.LocalPlayers"));
	//	GOffset_PlayerController = GetOffset(E("ObjectProperty Engine.Player.PlayerController"));
	//	GOffset_MyHUD = GetOffset(E("ObjectProperty Engine.PlayerController.MyHUD"));
	//	GOffset_Canvas = GetOffset(E("ObjectProperty Engine.HUD.Canvas"));
	//	GOffset_Font = GetOffset(E("ObjectProperty Engine.Engine.LargeFont"));
	//	GOffset_Levels = GetOffset(E("ArrayProperty Engine.World.Levels"));
	//	GOffset_Actors = GetOffset(E("ObjectProperty Engine.Level.OwningWorld")) - 0x20;
	//	GOffset_RootComponent = GetOffset(E("ObjectProperty Engine.Actor.RootComponent"));
	//	GOffset_ComponentLocation = GetOffset(E("StructProperty Engine.SceneComponent.RelativeLocation"));
	//	GOffset_Pawn = GetOffset(E("ObjectProperty Engine.Controller.Character"));
	//	GOffset_Mesh = GetOffset(E("ObjectProperty Engine.Character.Mesh"));
	//	GOffset_PlayerState = GetOffset(E("ObjectProperty Engine.Pawn.PlayerState"));
	//	GOffset_Weapon = GetOffset(E("ObjectProperty FortniteGame.FortPawn.CurrentWeapon"));
	//	GOffset_WeaponData = GetOffset(E("ObjectProperty FortniteGame.FortWeapon.WeaponData"));
	//	GOffset_DisplayName = GetOffset(E("TextProperty FortniteGame.FortItemDefinition.DisplayName"));
	//	GOffset_ViewportClient = GetOffset(E("ObjectProperty Engine.LocalPlayer.ViewportClient"));
	//	GOffset_ItemDefinition = GetOffset(E("ObjectProperty FortniteGame.FortItemEntry.ItemDefinition"));
	//	GOffset_PrimaryPickupItemEntry = GetOffset(E("StructProperty FortniteGame.FortPickup.PrimaryPickupItemEntry"));
	//	GOffset_Tier = GetOffset(E("ByteProperty FortniteGame.FortItemDefinition.Tier"));
	//	GOffset_BlockingHit = GetOffset(E("BoolProperty Engine.HitResult.bBlockingHit"));
	//	GOffset_PlayerCameraManager = GetOffset(E("ObjectProperty Engine.PlayerController.PlayerCameraManager"));
	//	GOffset_TeamIndex = GetOffset(E("ByteProperty FortniteGame.FortPlayerStateAthena.TeamIndex"));
	//	GOffset_ComponentVelocity = GetOffset(E("StructProperty Engine.SceneComponent.ComponentVelocity"));
	//	GOffset_MovementComponent = GetOffset(E("ObjectProperty Engine.DefaultPawn.MovementComponent"));
	//	GOffset_Acceleration = GetOffset(E("StructProperty Engine.CharacterMovementComponent.Acceleration"));
	//	GOffset_GravityScale = GetOffset(E("FloatProperty FortniteGame.FortProjectileBase.GravityScale"));
	//	GOffset_Searched = GetOffset(E("ObjectProperty FortniteGame.BuildingContainer.SearchedMesh"));
	//	GOffset_bHit = GetOffset(E("BoolProperty FortniteGame.BuildingWeakSpot.bHit"));
	//	GOffset_VehicleSkeletalMesh = GetOffset(E("ObjectProperty FortniteGame.FortAthenaSKVehicle.SkeletalMesh"));
	//	GOffset_Visible = GetOffset(E("BoolProperty Engine.SkinnedMeshComponent.bRecentlyRendered"));
	//
	//	printf("check2");
	//
	//	dprintf(E("#define DGOffset_OGI 0x%X"), GOffset_OGI);
	//	dprintf(E("#define DGOffset_LocalPlayers 0x%X"), GOffset_LocalPlayers);
	//	dprintf(E("#define DGOffset_PlayerController 0x%X"), GOffset_PlayerController);
	//	dprintf(E("#define DGOffset_MyHUD 0x%X"), GOffset_MyHUD);
	//	dprintf(E("#define DGOffset_Canvas 0x%X"), GOffset_Canvas);
	//	dprintf(E("#define DGOffset_Font 0x%X"), GOffset_Font);
	//	dprintf(E("#define DGOffset_Levels 0x%X"), GOffset_Levels);
	//	dprintf(E("#define DGOffset_Actors 0x%X"), GOffset_Actors);
	//	dprintf(E("#define DGOffset_RootComponent 0x%X"), GOffset_RootComponent);
	//	dprintf(E("#define DGOffset_ComponentLocation 0x%X"), GOffset_ComponentLocation);
	//	dprintf(E("#define DGOffset_Pawn 0x%X"), GOffset_Pawn);
	//	dprintf(E("#define DGOffset_Mesh 0x%X"), GOffset_Mesh);
	//	dprintf(E("#define DGOffset_PlayerState 0x%X"), GOffset_PlayerState);
	//	dprintf(E("#define DGOffset_WeaponData 0x%X"), GOffset_WeaponData);
	//	dprintf(E("#define DGOffset_Weapon 0x%X"), GOffset_Weapon);
	//	dprintf(E("#define DGOffset_DisplayName 0x%X"), GOffset_DisplayName);
	//	dprintf(E("#define DGOffset_ViewportClient 0x%X"), GOffset_ViewportClient);
	//	dprintf(E("#define DGOffset_ItemDefinition 0x%X"), GOffset_ItemDefinition);
	//	dprintf(E("#define DGOffset_PrimaryPickupItemEntry 0x%X"), GOffset_PrimaryPickupItemEntry);
	//	dprintf(E("#define DGOffset_Tier 0x%X"), GOffset_Tier);
	//	dprintf(E("#define DGOffset_BlockingHit 0x%X"), GOffset_BlockingHit);
	//	dprintf(E("#define DGOffset_PlayerCameraManager 0x%X"), GOffset_PlayerCameraManager);
	//	dprintf(E("#define DGOffset_TeamIndex 0x%X"), GOffset_TeamIndex);
	//	dprintf(E("#define DGOffset_ComponentVelocity 0x%X"), GOffset_ComponentVelocity);
	//	dprintf(E("#define DGOffset_MovementComponent 0x%X"), GOffset_MovementComponent);
	//	dprintf(E("#define DGOffset_Acceleration 0x%X"), GOffset_Acceleration);
	//	dprintf(E("#define DGOffset_GravityScale 0x%X"), GOffset_GravityScale);
	//	dprintf(E("#define DGOffset_Searched 0x%X"), GOffset_Searched);
	//	dprintf(E("#define DGOffset_bHit 0x%X"), GOffset_bHit);
	//	dprintf(E("#define DGOffset_VehicleSkeletalMesh 0x%X"), GOffset_VehicleSkeletalMesh);
	//	dprintf(E("#define GOffset_Visible 0x%X"), GOffset_Visible);
	//
	//	dprintf(E("#define DGOffset_pGEngine 0x%X"), (uintptr_t)pGEngine - GFnBase);
	//	dprintf(E("#define DGOffset_GObjects 0x%X"), (uintptr_t)GObjects - GFnBase);
	//	//dprintf(E("#define DGOffset_GetNameById 0x%X"), (uintptr_t)GGetNameFromId - GFnBase);
	//	dprintf(E("#define DGOffset_GWorld 0x%X"), UWorldOffset);
	//	dprintf(E("#define DGOffset_TraceVisibility 0x%X"), (uintptr_t)GTraceVisibilityFn - GFnBase);
	//
	//	printf("check3");
	//
	//#endif // GLOBAL_DEBUG_FLAG

	InitializeWindowData();
	HookWndProcUnsafe();
	HookPE();
}

/*BOOL NoCrtDllMain(HMODULE hm, DWORD cr, void* lpParam)
{

	static bool bCalled = false;

	if (bCalled)
		return TRUE;
	else
		bCalled = true;

	g_pSpoofGadget = (unsigned char*)0x1; // will crash if called with

	g_pSpoofGadget = (unsigned char*)TraceToModuleBaseAndGetSpoofGadget(LoadLibraryA);
	if (!g_pSpoofGadget)
		g_pSpoofGadget = (unsigned char*)0x1;

	//InitializeRoutinePtrs();

	dprintf(E("g_pSpoofGadget: 0x%p, DllBase: 0x%p"), g_pSpoofGadget, hm);

	//NiggerPE(hm);

	dprintf(E("Preparations are done, calling main()"));

	main();

	dprintf(E("main() has returned.."));

	return TRUE;
}*/

/*
bool __stdcall DllMain(void* hModule, unsigned long ul_reason_for_call, void* lpReserved)
{
	if (ul_reason_for_call == 1)
	{
		//AllocConsole();
		//FILE* fileptr;
		//freopen_s(&fileptr, "CONOUT$", "w", stdout);
		//freopen_s(&fileptr, "CONOUT$", "w", stderr);
		//freopen_s(&fileptr, "CONIN$", "r", stdin);

		g_pSpoofGadget = (unsigned char*)0x1; // will crash if called with

		g_pSpoofGadget = (unsigned char*)TraceToModuleBaseAndGetSpoofGadget(LoadLibraryA);
		if (!g_pSpoofGadget)
			g_pSpoofGadget = (unsigned char*)0x1;

		//InitializeRoutinePtrs();

		dprintf(E("g_pSpoofGadget: 0x%p, DllBase: 0x%p"), g_pSpoofGadget, hModule);

		//NiggerPE(hModule);

		dprintf(E("Preparations are done, calling main()"));

		main();

		dprintf(E("main() has returned.."));

		return TRUE;
	}

	return 1;
}*/