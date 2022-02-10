#pragma once
#include "Structs.h"

#define M_PI	3.14159265358979323846264338327950288419716939937510
#define ToRadians(degr) ( degr * (3.14159265358979323846264338327950288419716939937510 / 180))

#define FIRST_PERSON 1

namespace FN {

	static GObjects* objects = nullptr;

	static void FreeFN(__int64 address)
	{
		if (!valid_pointer(address)) return;

		auto fFreeFN = reinterpret_cast<void(__fastcall*)(__int64 address)>(FreeFn);

		SpoofCall(fFreeFN, address);
	}

	static const char* GetObjectName(uintptr_t Object)
	{
		if (!valid_pointer(Object)) return skCrypt("");

		auto fGetNameByIndex = reinterpret_cast<FString * (__fastcall*)(int* index, FString * result)>(GetNameByIndex);

		int index = *(int*)(Object + 0x18);

		FString result;
		SpoofCall(fGetNameByIndex, &index, &result);

		if (result.c_str() == NULL)
			return skCrypt("");

		auto result_str = result.ToString();

		if (result.c_str() != NULL)
			FreeFN((__int64)result.c_str());

		return result_str.c_str();
	}

	static const char* GetUObjectNameLoop(UObject* Object) {

		if (!valid_pointer((uintptr_t)Object)) return "";

		std::string name("");
		for (auto i = 0; Object; Object = Object->Outer, ++i) {

			auto fGetNameByIndex = reinterpret_cast<FString * (__fastcall*)(int* index, FString * result)>(GetNameByIndex);
			int index = *(int*)(reinterpret_cast<uint64_t>(Object) + 0x18);

			FString internalName;
			SpoofCall(fGetNameByIndex, &index, &internalName);

			if (internalName.c_str() == NULL) {
				break;
			}

			auto objectName = internalName.ToString();

			name = objectName + std::string(i > 0 ? skCrypt(".") : skCrypt("")) + name;
			FreeFN((__int64)internalName.c_str());

		}
		return name.c_str();
	}

	static void eraseSubStr(std::string& mainStr, const std::string& toErase)
	{
		size_t pos = mainStr.find(toErase);
		if (pos != std::string::npos)
		{
			mainStr.erase(pos, toErase.length());
		}
	}

	static PVOID FindAllObjects(const char* name, const char* name2) {

		for (auto array : objects->ObjectArray->Objects) {
			auto fuObject = array;
			
			for (auto i = 0; i < 0x10000 && fuObject->Object; ++i, ++fuObject)
			{
			
				auto object = fuObject->Object;
				std::string objname = GetUObjectNameLoop(object);

				if (strstr(objname.c_str(), name)) {
					eraseSubStr(objname, name);
					if (strstr(objname.c_str(), name2)) {
						return object;
					}
				}
			}
		}
		return 0;
	}

	static PVOID FindObject(const char* name) {
		for (auto array : objects->ObjectArray->Objects) {
			auto fuObject = array;			
			for (auto i = 0; i < 0x10000 && fuObject->Object; ++i, ++fuObject)
			{				
				auto object = fuObject->Object;
				if (object->ObjectFlags != 0x41) {
					continue;
				}
				
				if (strstr(GetUObjectNameLoop(object), name)) {
					return object;
				}
			}
		}
		return 0;
	}

	static PVOID FindObject2(const char* name, const char* name2) {
		for (auto array : objects->ObjectArray->Objects) {
			auto fuObject = array;
			
			for (auto i = 0; i < 0x10000 && fuObject->Object; ++i, ++fuObject)
			{				
				auto object = fuObject->Object;
				if (object->ObjectFlags != 0x41) {
					continue;
				}
			
				if ((strstr(GetUObjectNameLoop(object), name)) and (strstr(GetUObjectNameLoop(object), name2))) {
					return object;
				}
			}
		}

		return 0;
	}

	static BOOL ProcessEvent(uintptr_t address, void* fnobject, void* parms)
	{
		if (!valid_pointer(address)) return FALSE;
		auto index = *reinterpret_cast<void***>(address); if (!index) return FALSE;
		auto fProcessEvent = static_cast<void(*)(void* address, void* fnobject, void* parms)>(index[0x4B]); if (!fProcessEvent) return FALSE;
		SpoofCall(fProcessEvent, (void*)address, (void*)fnobject, (void*)parms);
		return TRUE;
	}
}



class APlayerState {
public:

	uintptr_t TeamIndex() {
		if (!valid_pointer((uintptr_t)this)) return 0;
		return *(uintptr_t*)(this + 0xF28);
	}

	FString GetPlayerName() {
		if (!valid_pointer((uintptr_t)this)) return (wchar_t*)skCrypt(L"");
		FString PlayerName;
		FN::ProcessEvent((uintptr_t)this, ObjectsAddresses::GetPlayerName, &PlayerName);
		if (!PlayerName.IsValid()) return (wchar_t*)skCrypt(L"");
		return PlayerName;
	}
};

class ARootComponent {
public:

	Vector3 RelativeLocation() {
		if (!valid_pointer((uintptr_t)this)) return { 0, 0, 0 };
		return *(Vector3*)((uintptr_t)this + 0x11c);
	}

	Vector3 RelativeRotation() {
		if (!valid_pointer((uintptr_t)this)) return { 0, 0, 0 };
		return *(Vector3*)((uintptr_t)this + 0x128);
	}

	//Vector3 GetComponentVelocity()
	//{
	//	if (!valid_pointer((uintptr_t)this)) return { 0, 0, 0 };
	//	StructsParams::USceneComponent_GetComponentVelocity_Params params;

	//	FN::ProcessEvent(uintptr_t(this), ObjectsAddresses::GetComponentVelocity, &params);

	//	return params.ReturnValue;
	//}
};

class AFortItemDefinition {
public:

	FText* DisplayName() {
		if (!valid_pointer((uintptr_t)this)) return 0;
		return reinterpret_cast<FText*>(*(uintptr_t*)(this + 0x88));
	}
};

//class AFortWeapon {
//public:
//
//	AFortItemDefinition* WeaponData() {
//		if (!valid_pointer((uintptr_t)this)) return 0;
//		return (AFortItemDefinition*)(*(uintptr_t*)(this + 0x380));
//	}
//
//	float GetWeaponBulletSpeed(float speed)
//	{
//		if (!valid_pointer((uintptr_t)this)) return 0;
//
//		StructsParams::AFortWeapon_GetProjectileSpeed_Params params;
//
//		FN::ProcessEvent(uintptr_t(this), ObjectsAddresses::GetProjectileSpeed, &params);
//
//		return params.ReturnValue;
//	}
//
//	AFortWeapon* GetReloadTime() {
//		if (!valid_pointer((uintptr_t)this)) return 0;
//		uintptr_t result;
//
//		FN::ProcessEvent((uintptr_t)this, ObjectsAddresses::GetReloadTime, &result);
//
//		return (AFortWeapon*)result;
//	}
//};

class AFortPawn {
public:
	
	const char* ObjectName() {
		if (!valid_pointer((uintptr_t)this)) return "";
		return SDK::Classes::APlayerCameraManager::GetUObjectName((uintptr_t*)this);
	}

	uintptr_t Mesh() {
		if (!valid_pointer((uintptr_t)this)) return 0;
		return *(uintptr_t*)((uintptr_t)this + 0x280);
	}

	//AFortWeapon* CurrentWeapon() {
	//	if (!valid_pointer((uintptr_t)this)) return 0;
	//	return (AFortWeapon*)(*(uintptr_t*)(this + 0x5E8));
	//}

	ARootComponent* RootComponent() {
		if (!valid_pointer((uintptr_t)this)) return 0;
		return (ARootComponent*)(*(uintptr_t*)(this + 0x130));
	}


	APlayerState* PlayerState() {
		if (!valid_pointer((uintptr_t)this)) return 0;
		return (APlayerState*)(*(uintptr_t*)(this + 0x238));
	}

	//VOID SetReviveFromDBNOTime(float value) {
	//	if (!valid_pointer((uintptr_t)this)) return;
	//	*(float*)((uintptr_t)this + 0x35E0) = value;
	//}

	//VOID SetbADSWhileNotOnGround(bool value) {
	//	if (!valid_pointer((uintptr_t)this)) return;
	//	*(bool*)((uintptr_t)this + 0x3CD1) = value;
	//}

	//BOOL IsDBNO() {
	//	if (!valid_pointer((uintptr_t)this)) return 0;
	//	return *(bool*)((uintptr_t)this + 0x58E);
	//}

	//BOOL IsDying() {
	//	if (!valid_pointer((uintptr_t)this)) return 0;
	//	return *(bool*)((uintptr_t)this + 0x540);
	//}

	//BOOL IsPlayer() {
	//	if (!valid_pointer((uintptr_t)this)) return 0;
	//	if (strstr(ObjectName(), xorstr_("PlayerPawn_Athena_"))) return TRUE;
	//	else return FALSE;
	//}

	//Vector3 GetBone(int boneidx)
	//{
	//	if (!valid_pointer((uintptr_t)this)) return { 0, 0, 0 };
	//	Vector3 result;
	//	auto fGetBoneMatrix = ((FMatrix * (__fastcall*)(uintptr_t, FMatrix*, int))(BoneMatrix));
	//	SpoofCall(fGetBoneMatrix, Mesh(), myMatrix, boneidx);

	//	result.x = myMatrix->M[3][0];
	//	result.y = myMatrix->M[3][1];
	//	result.z = myMatrix->M[3][2];

	//	return result;
	//}

	//BOOL IsInVehicle() {
	//	if (!valid_pointer((uintptr_t)this)) return 0;
	//	bool result;
	//	FN::ProcessEvent((uintptr_t)this, ObjectsAddresses::IsInVehicle, &result);
	//	return result;
	//}

	//Vector3 get_acceleration()
	//{
	//	if (!valid_pointer((uintptr_t)this)) return { 0, 0, 0 };
	//	auto char_movement = *(uintptr_t*)(uintptr_t(this) + 0x288); //DGOffset_MovementComponent
	//	if (valid_pointer(char_movement)) {
	//		return *(Vector3*)(char_movement + 0x24C); //DGOffset_Acceleration
	//	}
	//	else {
	//		return { 0, 0, 0 };
	//	}
	//}

	AFortPawn* GetVehicle() {

		if (!valid_pointer((uintptr_t)this)) return 0;
		uintptr_t result;

		FN::ProcessEvent((uintptr_t)this, ObjectsAddresses::GetVehicle, &result);

		return (AFortPawn*)result;
	}

	BOOL InVis(bool ret) {
		if (!valid_pointer((uintptr_t)this)) return 0;
		FN::ProcessEvent((uintptr_t)this, ObjectsAddresses::SetPawnVisibility, &ret);
		return TRUE;
	}

	BOOL PlayerFly(bool ret) {
		if (!valid_pointer((uintptr_t)this)) return 0;
		FN::ProcessEvent((uintptr_t)this, ObjectsAddresses::CreativeToggleFly, &ret);
		FN::ProcessEvent((uintptr_t)this, ObjectsAddresses::ServerCreativeToggleFly, &ret);
		return TRUE;
	}

	//BOOL K2_SetActorLocation(const Vector3& NewLocation, bool bSweep, bool bTeleport)
	//{
	//	if (!valid_pointer((uintptr_t)this)) return 0;
	//	StructsParams::AActor_K2_SetActorLocation_Params params;
	//	params.NewLocation = NewLocation;
	//	params.bSweep = bSweep;
	//	params.bTeleport = bTeleport;

	//	FN::ProcessEvent((uintptr_t)this, ObjectsAddresses::K2_SetActorLocation, &params);

	//	return params.ReturnValue;
	//}

	BOOL K2_TeleportTo(const Vector3& DestLocation, const Vector3& DestRotation)
	{
		if (!valid_pointer((uintptr_t)this)) return 0;

		StructsParams::AActor_K2_TeleportTo_Params params;

		params.DestLocation = DestLocation;
		params.DestRotation = DestRotation;

		FN::ProcessEvent((uintptr_t)this, ObjectsAddresses::K2_TeleportTo, &params);

		return params.ReturnValue;
	}

};



class APlayerCameraManager {
public:

	float GetFOVAngle()
	{
		if (!valid_pointer((uintptr_t)this)) return 0;
		auto fGetFOVAngle = reinterpret_cast<float(*)(UINT64, char*)>(*(uintptr_t*)(*(uintptr_t*)uintptr_t(this) + 0x740));
		return SpoofCall(fGetFOVAngle, (uintptr_t)this, (char*)0);
	}
	
	bool GetPlayerViewPoint(Vector3* vCameraPos, Vector3* vCameraRot)
	{
		if (!valid_pointer((uintptr_t)this)) return 0;

		static uintptr_t GetPlayerViewPoint = 0;
		if (!GetPlayerViewPoint)
		{
			uintptr_t VTable = *(uintptr_t*)this;
			if (!VTable)  return false;

			GetPlayerViewPoint = *(uintptr_t*)(VTable + 0x788);
			if (!GetPlayerViewPoint)  return false;
		}

		auto fGetPlayerViewPoint = reinterpret_cast<void(__fastcall*)(uintptr_t, Vector3*, Vector3*)>(GetPlayerViewPoint);

		SpoofCall(fGetPlayerViewPoint, (uintptr_t)this, vCameraPos, vCameraRot);

		return true;
	}
};

class APlayerController {
public:

	AFortPawn* LocalPawn() {
		if (!valid_pointer((uintptr_t)this)) return 0;
		return (AFortPawn*)(*(uintptr_t*)(this + 0x2A8));
	}

	APlayerCameraManager* PlayerCameraManager() {
		if (!valid_pointer((uintptr_t)this)) return 0;
		return (APlayerCameraManager*)(*(uintptr_t*)(this + 0x2C0));
	}

	BOOL IsAiming() {
		return A1337GetAsyncKeyState(VK_RBUTTON);
	}

	//BOOL IsVisible(PVOID TargetActor) {
	//	if (!valid_pointer((uintptr_t)this)) return 0;
	//	Vector3 ViewPoint;
	//	auto fLineOfSightTo = reinterpret_cast<bool(__fastcall*)(PVOID PlayerController, PVOID TargetActor, Vector3 * ViewPoint)>(LineOfS);
	//	return SpoofCall(fLineOfSightTo, (PVOID)this, TargetActor, &ViewPoint);
	//}

	//BOOL ClientSetCameraMode(int CameraMode) {
	//	if (!valid_pointer((uintptr_t)this)) return 0;
	//	auto fClientSetCameraMode = (*(void(__fastcall**)(uintptr_t PlayerController, int h))(*(uintptr_t*)(uintptr_t)(this) + 0x940));
	//	SpoofCall(fClientSetCameraMode, (uintptr_t)this, CameraMode);
	//	return TRUE;
	//}

	//FVector2D WorldToScreen(Vector3 WorldLocation) {
	//	if (!valid_pointer((uintptr_t)this)) return { 0, 0 };
	//	return FN::ProjectWorldLocationToScreen(WorldLocation);
	//}

	//BOOL ClientSetRotation(const Vector3& NewRotation, bool bResetCamera)
	//{
	//	if (!valid_pointer((uintptr_t)this)) return 0;

	//	StructsParams::AController_ClientSetRotation_Params params;
	//	params.NewRotation = NewRotation;
	//	params.bResetCamera = bResetCamera;

	//	FN::ProcessEvent(uintptr_t(this), ObjectsAddresses::ClientSetRotation, &params);
	//	return TRUE;
	//}

	//BOOL ClientSetLocation(const Vector3& NewLocation, const Vector3& NewRotation)
	//{

	//	if (!valid_pointer((uintptr_t)this)) return 0;

	//	StructsParams::AController_ClientSetLocation_Params params;
	//	params.NewLocation = NewLocation;
	//	params.NewRotation = NewRotation;

	//	FN::ProcessEvent(uintptr_t(this), ObjectsAddresses::ClientSetLocation, &params);
	//	return TRUE;
	//}

	/*
	BOOL GetMousePosition(float* LocationX, float* LocationY)
	{
		if (!valid_pointer((uintptr_t)this)) return 0;

		StructsParams::APlayerController_GetMousePosition_Params params;

		FN::ProcessEvent(uintptr_t(this), ObjectsAddresses::GetMousePosition, &params);

		if (LocationX != nullptr)
			*LocationX = params.LocationX;
		if (LocationY != nullptr)
			*LocationY = params.LocationY;

		return params.ReturnValue;
	}*/

	
	//VOID ClientReturnToMainMenu(const FString& ReturnReason)
	//{
	//	if (!valid_pointer((uintptr_t)this)) return;

	//	StructsParams::APlayerController_ClientReturnToMainMenu_Params params;
	//	params.ReturnReason = ReturnReason;

	//	FN::ProcessEvent(uintptr_t(this), ObjectsAddresses::ClientReturnToMainMenu, &params);
	//}

	BOOL FOV(float NewFOV) {
		if (!valid_pointer((uintptr_t)this)) return 0;
		FN::ProcessEvent((uintptr_t)this, ObjectsAddresses::FOV, &NewFOV);
		return TRUE;
	}
};

class ULocalPlayer {
public:
	APlayerController* PlayerController() {
		if (!valid_pointer((uintptr_t)this)) return 0;
		return (APlayerController*)(*(uintptr_t*)(this + 0x30));
	}
};

class ULocalPlayers {
public:
	ULocalPlayer* LocalPlayer() {
		if (!valid_pointer((uintptr_t)this)) return 0;
		return (ULocalPlayer*)(*(uintptr_t*)(this));
	}
};

class UGameInstance {
public:
	ULocalPlayers* LocalPlayers() {
		if (!valid_pointer((uintptr_t)this)) return 0;
		return (ULocalPlayers*)(*(uintptr_t*)(this + 0x38));
	}
};

class AActorss {
public:

	AFortPawn* GetCurrentActor(int i) {
		if (!valid_pointer((uintptr_t)this)) return 0;
		return (AFortPawn*)(*(uintptr_t*)(this + i * sizeof(uintptr_t)));
	}
};

class ULevel {
public:
	AActorss* Actors() {
		if (!valid_pointer((uintptr_t)this)) return 0;
		return (AActorss*)(*(uintptr_t*)(this + 0x98));
	}

	int ActorCount() {
		if (!valid_pointer((uintptr_t)this)) return 0;
		return (int)(*(uintptr_t*)(this + 0xA0));
	}
};
//
//class UEngineRenderer {
//public:
//
//	VOID K2_DrawLine(const FVector2D& ScreenPositionA, const FVector2D& ScreenPositionB, const FLinearColor& RenderColor, float Thickness)
//	{
//		if (!valid_pointer((uintptr_t)this)) return;
//		auto canvas = (UCanvas*)this;
//		StructsParams::UCanvas_K2_DrawLine_Params params;
//		params.ScreenPositionA = ScreenPositionA;
//		params.ScreenPositionB = ScreenPositionB;
//		params.Thickness = Thickness;
//		params.RenderColor = RenderColor;
//
//		FN::ProcessEvent(uintptr_t(canvas), ObjectsAddresses::K2_DrawLine, &params);
//	}
//
//	VOID K2_DrawText(PVOID RenderFont, const FVector2D& ScreenPosition, const FString& RenderText, const FLinearColor& RenderColor, bool centered, bool bOutlined)
//	{
//		if (!valid_pointer((uintptr_t)this)) return;
//		auto canvas = (UCanvas*)this;
//		if (!valid_pointer((uintptr_t)RenderFont)) return;
//		StructsParams::UCanvas_K2_DrawText_Params params;
//		params.RenderFont = RenderFont;
//		params.RenderText = RenderText;
//		params.ScreenPosition = ScreenPosition;
//		params.Scale = FVector2D{ 0.6f, 0.6f };
//		params.RenderColor = RenderColor;
//		params.Kerning = false;
//		params.ShadowColor = FLinearColor{ 0.0f, 0.0f, 0.0f, 0.0f };
//		params.ShadowOffset = FVector2D{ ScreenPosition.X + 1, ScreenPosition.Y + 1 };
//		if (centered) {
//			params.bCentreX = true;
//			params.bCentreY = true;
//		}
//		else {
//			params.bCentreX = false;
//			params.bCentreY = false;
//		}
//		params.bOutlined = bOutlined;
//		params.OutlineColor = { 0.0f, 0.0f, 0.0f, 1.f };
//		FN::ProcessEvent(uintptr_t(canvas), ObjectsAddresses::K2_DrawText, &params);
//	}
//
//	void DrawCircle(FVector2D pos, int radius, FLinearColor Color, int numSides = 450)
//	{
//		if (!valid_pointer((uintptr_t)this)) return;
//		float Step = M_PI * 2.0 / numSides;
//		int Count = 0;
//		FVector2D V[128];
//		for (float a = 0; a < M_PI * 2.0; a += Step) {
//			float X1 = radius * cos(a) + pos.X;
//			float Y1 = radius * sin(a) + pos.Y;
//			float X2 = radius * cos(a + Step) + pos.X;
//			float Y2 = radius * sin(a + Step) + pos.Y;
//			V[Count].X = X1;
//			V[Count].Y = Y1;
//			V[Count + 1].X = X2;
//			V[Count + 1].Y = Y2;
//			K2_DrawLine(FVector2D{ V[Count].X, V[Count].Y }, FVector2D{ X2, Y2 }, Color, 1.f);// Circle Around
//		}
//	}
//};
//
//class UKismetMathLibrary {
//public:
//	Vector3 FindLookAtRotation(const Vector3& Start, const Vector3& Target)
//	{
//		if (!valid_pointer((uintptr_t)this)) return { 0, 0, 0 };
//
//		StructsParams::UKismetMathLibrary_FindLookAtRotation_Params params;
//		params.Start = Start;
//		params.Target = Target;
//
//		FN::ProcessEvent(uintptr_t(this), ObjectsAddresses::FindLookAtRotation, &params);
//
//		return params.ReturnValue;
//	}
//};
//
//class UFortKismetLibrary
//{
//public:
//	TArray<AFortPawn*> STATIC_GetFortPlayerPawns(UObject* WorldContextObject)
//	{
//		//if (!valid_pointer((uintptr_t)this)) return;
//
//		StructsParams::UFortKismetLibrary_GetFortPlayerPawns_Params params;
//		params.WorldContextObject = WorldContextObject;
//
//		FN::ProcessEvent(uintptr_t(this), ObjectsAddresses::FortKismetLibrary, &params);
//
//		return params.ReturnValue;
//	}
//};

class UWorldA {
public:

	UGameInstance* OwningGameInstance() {
		if (!valid_pointer((uintptr_t)this)) return 0;
		return (UGameInstance*)(*(uintptr_t*)(this + 0x190));
	}

	ULevel* PersistentLevel() {
		if (!valid_pointer((uintptr_t)this)) return 0;
		return (ULevel*)(*(uintptr_t*)(this + 0x30));
	}
};

namespace Addresses {
	static APlayerController* PlayerController;
	static AFortPawn* LocalPawn;
	/*static AFortWeapon* CurrentWeapon;*/
	static APlayerState* PlayerState;
	static AFortPawn* CurrentPawn;
	static AActorss* Actors;
}

//class UField : public UObject
//{
//public:
//	class UField* Next;                                                     // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//
//	static auto StaticClass()
//	{
//		static PVOID ptr = NULL;
//		if (!ptr)
//			ptr = ObjectsAddresses::Field; //Class CoreUObject.Field
//
//		return ptr;
//	}
//
//};
//class UStruct : public UField
//{
//public:
//	char                                               pad_0030[0x10];                                           // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//	class UStruct* SuperField;                                               // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//	class UField* Children;                                                 // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//	void* ChildProperties;                                          // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//	int32_t                                            PropertySize;                                             // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//	int32_t                                            MinAlignment;                                             // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//	char                                               pad_0060[0x50];                                           // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//
//	static auto StaticClass()
//	{
//		static PVOID ptr = NULL;
//		if (!ptr)
//			ptr = ObjectsAddresses::Struct; //Class CoreUObject.Struct
//
//		return ptr;
//	}
//
//};
//class UFunction : public UStruct
//{
//public:
//	int32_t FunctionFlags; //0x0088
//	int16_t RepOffset; //0x008C
//	int8_t NumParms; //0x008E
//	char pad_0x008F[0x1]; //0x008F
//	int16_t ParmsSize; //0x0090
//	int16_t ReturnValueOffset; //0x0092
//	int16_t RPCId; //0x0094
//	int16_t RPCResponseId; //0x0096
//	class UProperty* FirstPropertyToInit; //0x0098
//	UFunction* EventGraphFunction; //0x00A0
//	int32_t EventGraphCallOffset; //0x00A8
//	char pad_0x00AC[0x4]; //0x00AC
//	void* Func; //0x00B0
//};
//
//struct FHitResult {
//	char bBlockingHit : 1;
//	char pad_5E[0x2];
//};

//namespace FN {
//	namespace CanvasFunctions {
//		static VOID K2_DrawText(PVOID RenderFont, const FString& RenderText, const FVector2D& ScreenPosition, const FVector2D& Scale, const FLinearColor& RenderColor, float Kerning, const FLinearColor& ShadowColor, const FVector2D& ShadowOffset, bool bCentreX, bool bCentreY, bool bOutlined, const FLinearColor& OutlineColor)
//		{
//			if (!valid_pointer((uintptr_t)Renderer_Defines::EngineRenderer)) return;
//			auto canvas = (uintptr_t)Renderer_Defines::EngineRenderer;
//			StructsParams::UCanvas_K2_DrawText_Params params;
//			params.RenderFont = RenderFont;
//			params.RenderText = RenderText;
//			params.ScreenPosition = ScreenPosition;
//			params.Scale = Scale;
//			params.RenderColor = RenderColor;
//			params.Kerning = Kerning;
//			params.ShadowColor = ShadowColor;
//			params.ShadowOffset = ShadowOffset;
//			params.bCentreX = bCentreX;
//			params.bCentreY = bCentreY;
//			params.bOutlined = bOutlined;
//			params.OutlineColor = OutlineColor;
//
//			FN::ProcessEvent(canvas, ObjectsAddresses::K2_DrawText, &params);
//		}
//
//		//bool K2_SetActorLocation(UObject* Actor, const struct FVector& NewLocation, bool bSweep, bool bTeleport, struct FHitResult* SweepHitResult)
//		//{
//		//	static UFunction* fn = ObjectsAddresses::K2_SetActorLocation;
//
//		//	struct AActor_K2_SetActorLocation_Params
//		//	{
//		//		struct FVector                                     NewLocation;
//		//		bool                                               bSweep;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
//		//		struct FHitResult								   SweepHitResult;
//		//		bool                                               bTeleport;                                                // (Parm, ZeroConstructor, IsPlainOldData)
//		//		bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
//		//	};
//		//	AActor_K2_SetActorLocation_Params params;
//
//		//	params.NewLocation = NewLocation;
//		//	params.bSweep = bSweep;
//		//	params.bTeleport = bTeleport;
//
//		//	auto flags = fn->FunctionFlags;
//
//		//	FN::ProcessEvent((uintptr_t)Actor, ObjectsAddresses::K2_SetActorLocation, &params);
//
//		//	fn->FunctionFlags = flags;
//
//		//	if (SweepHitResult != nullptr)
//		//		*SweepHitResult = params.SweepHitResult;
//
//		//	return params.ReturnValue;
//		//}
//
//		static VOID K2_DrawLine(const FVector2D& ScreenPositionA, const FVector2D& ScreenPositionB, float Thickness, const FLinearColor& RenderColor)
//		{
//			if (!valid_pointer((uintptr_t)Renderer_Defines::EngineRenderer)) return;
//			auto canvas = (uintptr_t)Renderer_Defines::EngineRenderer;
//			StructsParams::UCanvas_K2_DrawLine_Params params;
//			params.ScreenPositionA = ScreenPositionA;
//			params.ScreenPositionB = ScreenPositionB;
//			params.Thickness = Thickness;
//			params.RenderColor = RenderColor;
//
//			FN::ProcessEvent(uintptr_t(canvas), ObjectsAddresses::K2_DrawLine, &params);
//		}
//	}
//}