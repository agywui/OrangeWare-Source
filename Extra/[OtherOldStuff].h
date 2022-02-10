/*
Uworld: 0x9ca6030
GoObjects: 0x9abadd0
LineOfSightTo: 0xffffffff8fa21f03
ProjectWorldToScreen: 0xffffffff8e9705e6
CalculateSpreadHook: 0xffffffff937bbb02
SpreadCaller: 0x2530d078

--------------------

Levels 0x140
PersistentLevel 0x30
LocalPlayers 0x38
PlayerController 0x30
OwningGameInstance 0x188
ControlRotation 0x288
PlayerCameraManager 0x2B8
AcknowledgedPawn 0x2A0
PlayerState 0x240
RootComponent 0x130
Mesh 0x280
RelativeLocation 0x11C
RelativeRotation 0x128
ComponentVelocity 0x140
ComponentToWorld 0x14C
StaticMesh 0x480
CachedWorldSpaceBounds 0x618
CustomTimeDilation 0x98
RemoteViewPitch 0x232
LastFireTimeVerified 0x9F0
LastFireTime 0x9EC
bIsReloadingWeapon 0x2B9
bIsDBNO 0x58E
bIsDying 0x540
TeamIndex 0xED8
SquadId 0x105C
PrimaryPickupItemEntry 0x2A8
DisplayName 0x88
Tier 0x6C
ItemDefinition 0x18
CurrentWeapon 0x610
WeaponData 0x380
AmmoCount 0xA78
LastFireAbilityTime 0xC38
WeaponStatHandle 0x830
FireStartLoc 0x880
ReloadTime 0x10C
ReloadScale 0x110
ChargeDownTime 0x13C
RecoilHoriz 0x214
RecoilVert 0x204
RecoilDownsightsMultiplier 0x230
bAlreadySearched 0xE39
bActive 0x250
Spread 0x16C
SpreadDownsights 0x174
StandingStillSpreadMultiplier 0x178
AthenaJumpingFallingSpreadMultiplier 0x180
AthenaCrouchingSpreadMultiplier 0x17C
AthenaSprintingSpreadMultiplier 0x184
MinSpeedForSpreadMultiplier 0x188
MaxSpeedForSpreadMultiplier 0x18C
FortMeatballVehicleConfigsClass 0x1878
BoostMinPushForce 0x558
BoostTopSpeedForceMultiplier 0x55C
BoostTopSpeedMultiplier 0x560
LandTopSpeedMultiplier 0x568
LandPushForceMultiplier 0x56C
BoostSteeringMultiplier 0x5AC
LandSteeringMultiplier 0x5B4
LandMinSpeedSteeringAngle 0x5B8
LandMaxSpeedSteeringAngle 0x5BC
Uworld: 0x9ca6030
GoObjects: 0x9abadd0
LineOfSightTo: 0xffffffff8fa21f03
ProjectWorldToScreen: 0xffffffff8e9705e6
CalculateSpreadHook: 0xffffffff937bbb02
SpreadCaller: 0x2530d078
*/

/*Engine.World.Levels 0x140
*
* FortPlayerController
OnPlayerPawnPossessed 0x6F8
OnPickupCreated 0x708
OnInputFiltered 0x748
bAllowPcbBenefits 0x764
OnFortPawnChangedEvent 0x768
OnControllerComponentAttachedEvent 0x778
bInPossession 0x821
AircraftInputComponent 0x870
MiniMapInputComponent 0x878
SkydiveMusicAudioComp 0x880
bFailedToRespawn 0x888
bIsDisconnecting 0x888
bIsBeingKicked 0x888
bHasInitiallySpawned 0x888
bAssignedStartSpawn 0x888
bReadyToStartMatch 0x888
bClientPawnIsLoaded 0x888
SpawnLoc 0x88C
NumPreviousSpawns 0x898
bCanSpectateBot 0x89C
OnBlueprintReadyCheckCompleted 0x8A0
SimpleLoadingScreenSoundMix 0x8D0
RegisteredPartnerId 0x8E8
RegisteredPartnerTag 0x8F8
ManagedAIs 0x900
MyFortPawn 0x910
MyFortPawnBeforeTakeoverOfScriptedPawn 0x918
ScriptedPawnControllerBeforeTakeover 0x920
bHasClientFinishedLoading 0x928
bHasServerFinishedLoading 0x929
TimeStartedWaiting 0x92C
TimeFinishedNavigationBuild 0x930
MaterialParameterCollection 0x938
bLoadingScreenDropped 0x949
PendingSpectatorLocation 0x94C
ActorUnderReticle 0x958
AutoFireReticleTarget 0x960
AutofireTimerHandle 0x968
WeakspotUnderReticle 0x978
ActiveWeakSpots 0x980
IdleKickLastTimeActive 0x990
LastTimeActive 0x994
bRevertPlayerListenerChange 0x9B8
VehicleInputComponent 0x9D8
bHoldingPrimaryFireFromTouch 0x9E0
bSupportNextPieceAssist 0x9E1
bAutoBuildForTrapPlacement 0x9E2
bAutoBuildForFloorTrapPlacement 0x9E3
bAutoBuildForWallTrapPlacement 0x9E4
bAutoBuildForCeilingTrapPlacement 0x9E5
bNoControllerLighting 0x9E6
ReturnToMainMenuTimeoutDelay 0x9E8
OnQuestObjectiveStateChanged 0x9F0
LastDamager 0xA18
LastFallInstigator 0xA28
LastDamagerCreditThresholdDropElim 0xA34
LastDamagerCreditThresholdSelfElim 0xA38
LastDamagerCreditThresholdStormElim 0xA3C
bGiveLastDamagerElimCreditOnDrop 0xA40
bGiveLastDamagerElimCreditOnSelfDamage 0xA41
bGiveLastDamagerElimCreditOnStormDamage 0xA42
OnMcpProfilesInitializedEvent 0xA90
OnEnterVehicleDriver 0xC30
OnEnterVehiclePassenger 0xC40
OnExitVehicle 0xC50
OnFullyExitVehicle 0xC60
OnVehicleAbilitiesRemoved 0xC70
OnTetherChanged 0xC80
bHoldingObject 0xCC8
DBNOCarryInputComponent 0xCD0
HeldObjectsInputComponent 0xCD8
bWantsToSprint 0xD28
bHoldingSprint 0xD28
bSprintToggleable 0xD28
bSprintByDefault 0xD28
bSprintCancelsReload 0xD28
bSprintWasCancelledByReload 0xD28
bAutoRunOn 0xD28
bUseHoldToSwapPickup 0xD28
bTargetingToggleable 0xD29
bTargetingToggleableWithTouch 0xD29
bMovementDisabledDueToCancellableAction 0xD29
bIsPlayerActivelyMoving 0xD29
bPlaceHeldObjectPressed 0xD29
InMovementCancellableAction 0xD2C
bAllowHoldForAmmoCrafting 0xD30
bIsClientTimingOut 0xD31
ClientTimeoutBlockInputTime 0xD34
LastMoveInputFrame 0xD40
LastPressGamepadSprintTime 0xD48
bAutoRunWasHoldingForward 0xD4C
bAtNameBaseScreen 0xD4D
OnSetFirstPersonCamera 0xD50
CinematicCameraClassOverride 0xDD0
bOnPressExecuteJetpack 0xDD8
bShowHitMarkersForFriendlyFire 0xDF8
bServerSideHitMarkers 0xDF9
OnUiChoiceCompleted 0xE10
OnRegainedFocus 0xE20
OnOpenVoteDialog 0xE30
bGamepadAbilityPending 0x10D4
bForceAllowCursorMode 0x10D5
bForceAllowCameraMode 0x10D6
bSuppressEventNotifications 0x10D8
LastSpotTime 0x1148
CurrentMarks 0x1158
LoopingUIFeedbackComponents 0x1168
PreviewAbility 0x11B8
IntensityGraphInfo 0x11D8
PIDValuesGraphInfo 0x1200
PIDContributionsGraphInfo 0x1228
AIDirectorDataManager 0x1250
MusicManager 0x1258
OnBuildPreviewMarkerVisibilityChanged 0x1260
OnWeakSpotReset 0x1270
bUsePredictedBuildingActors 0x1290
bRegisterPredictedBuildingActorsWithGrid 0x1291
bPredictedBuildingWallsHaveNoCollision 0x1292
PredictedActorLifespan 0x1294
PredictedBuildingSMActors 0x1298
BuildPreviewModeInputComponent 0x1428
BuildPreviewMarker 0x1430
BuildPreviewMarkerExtraPiece 0x1438
bAllowBuildingPreviewAutoRotation 0x1470
bRequireTraceToExistingBuildingToSetContext 0x1471
bAllowTraceToExistingBuildingToSetContextToRedirectToBlockingBuilding 0x1472
bRequireTraceToExistingBuildingToSetContextExcludeCurrentContext 0x1473
TargetedBuilding 0x1538
TargetedVehicle 0x1540
ContextualConversionClass 0x1548
StartUpgradeSound 0x1550
HighlightedPrimaryBuildings 0x1578
HighlightedInteractionBuildings 0x1588
HighlightedPrimaryBuilding 0x1598
BuildPreviewMarkerParentMaterial 0x15A0
BuildPreviewMarkerMIDs 0x15C8
BuildPreviewRotationIterations 0x15D8
bBuildPreviewMirrored 0x15DC
BuildPreviewMarkerOptionalAdjustment 0x15E0
bBuildFree 0x15E4
bUseSmartBuild 0x15E4
bCraftFree 0x15E4
CurrentCostInfoType 0x15E8
CurrentBuildableClass 0x15F0
PreviousBuildableClass 0x15F8
CurrentResourceLevel 0x1600
CurrentResourceType 0x1601
LastBuildableStateData 0x1608
QueuedDamageNumbers 0x16D8
DamageNumbersActor 0x16E8
EditModeInputComponent 0x16F0
EditBuildingActor 0x16F8
EditModeDistance 0x1700
LastBuildPreviewGridSnapLoc 0x1704
LastBuildPreviewGridSnapRot 0x1710
LastBuildPreviewGridSnapCentroid 0x171C
PickerInputComponent 0x1728
TrapPickerDecoHelper 0x1730
TouchEditResults 0x1738
bBuildingPlacementTraceSkipInitialPenetrationOfBuildingSMActor 0x1749
bBuildingPlacementTraceSkipInitialPenetrationOfStaticMesh 0x174A
OnLowOnBuildingResources 0x1750
OnOutOfBuildingResources 0x1760
ClientQuickBars 0x17B0
RecentlyRemovedQuickbarInfo 0x17C0
DelayedQuickBarActions 0x1820
ClientProcessedQuickBarActions 0x1940
bShouldForceDeleteDroppedItems 0x1990
QueuedItemsToDrop 0x19B8
bAutoEquipBetterItems 0x1A60
WorldInventory 0x1A68
OutpostInventory 0x1A70
ViewTargetInventory 0x1A78
bHasInitializedWorldInventory 0x1ACC
bHasInitializedHeroInventory 0x1ACC
bAccountInventoryWasUpdated 0x1ACC
bForceWorldInventoryUpdate 0x1ACC
bIsSavingGadgetLoadout 0x1ACC
BotPilot 0x1B50
BotManager 0x1B70
ClientBotManagerClass 0x1B80
CosmeticLoadoutPC 0x1B88
LocalPawnCustomizationAssetLoader 0x1CC8
bDropWeaponsDuringAllMissionStates 0x1CE8
LatestRewardReport 0x1D08
MyPlayerInfo 0x1D78
UpdatedObjectiveStats 0x1D80
bHasUnsavedPrimaryMissionProgress 0x1D90
StatManager 0x1DD0
HeartbeatManager 0x1DD8
StatEventManager 0x1DE0
CachedPersistentGameplayStats 0x1DE8
LastEmotePlayed 0x1E08
EmoteUsageCounts 0x1E10
AnalyticsBuildingWallTooLowLocations 0x1E60
NearbyEmotingPawns 0x1E70
NearbyEmotingPawnCount 0x1EC0
McpProfileGroup 0x1F10
CommonPublicMcpProfile 0x1F18
CommonCoreMcpProfile 0x1F20
MainMcpProfile 0x1F28
AthenaProfile 0x1F30
MetadataProfile 0x1F38
CreativeModeProfile 0x1F40
TutorialCompletedState 0x1F48
bShouldReceiveCriticalMatchBonus 0x1F80
OnPlayerChangedBuildMode 0x1F88
OnAutoRunEnabled 0x1F98
VoiceInputSourceEffectPresetChain 0x2108
LocationUnderReticle 0x2110
bEnableVoiceChatPTT 0x211C
bVoiceChatPTTTransmit 0x211C
bInfiniteAmmo 0x211C
bInfiniteConsumables 0x211C
bInfiniteMagazine 0x211C
bNoCoolDown 0x211C
bInfiniteDurability 0x211C
bUsePickers 0x211C
bPickerOpen 0x211D
bPickerEnabled 0x211D
bCheatGhost 0x211D
bCheatFly 0x211D
bEnableShotLogging 0x211D
bIsNearActiveEncounters 0x211D
OverriddenBackpackSize 0x2120
CurrentReplaySpotLight 0x2128
AimHelpMode 0x2130
JumpStaminaCost 0x2134
CameraPrototypeName 0x2138
bHideHudEnglishText 0x2168
bAutoChangeMaterial 0x2169
bServerAutoChangeMaterial 0x216A
bPeripheralLightingEnabled 0x216B
bRudderControlEnabled 0x216C
RudderDeadZone 0x2170
RudderMaxThrottle 0x2174
ActiveSprayInstances 0x2178
ActiveToyInstances 0x2188
ToySummonCounts 0x2198
bSyncPeripheralLightingWithEmoteMusic 0x21E8
bPushEmoteAudioDataToCosmeticMaterials 0x21E9
LastEmoteMusicFFT100hz 0x21EC
LastEmoteMusicFFT2000hz 0x21F0
EmoteMusicBeatThreshold 0x21F4
EmoteMusicEnvelopeBeatCount 0x21F8
bZeroingCameraRoll 0x2358
bTryPickupSwap 0x2359
bClientSideEditPrediction 0x235A
ClientSideEditPredictionTimeout 0x235C
PendingEnterEditModeActor 0x2368
RandomCharacterIndex 0x2370
AntiAddictionPlayTimeMultiplier 0x2374
bSupportQuickEdit 0x2378
bQuickEditEnabled 0x2379
bUsesWidgetForFPSDisplay 0x237A
bShowFPS 0x237B
OnShowFPSChange 0x2380
bShowTemperature 0x2390
OnShowTemperatureChange 0x2398
LockOnInfo 0x23DC
bLockPrimaryInputMethodToMouse 0x2414
IndicatorManager 0x2428
bFinalXPUpdateFailed 0x2440
TestUserWidget 0x2448
PreviousStasisMode 0x2450
BattleMapSpectatorClass 0x2458
bReleaseBuildingContextOnPlace 0x247D
TurboPlaceFirstInterval 0x2480
TurboPlaceInterval 0x2484
bCreativeTurboDelete 0x2488
TurboDeleteFirstInterval 0x248C
TurboDeleteInterval 0x2490
bTurboBuild 0x2495
TurboBuildFirstInterval 0x2498
TurboBuildRequestFailedInterval 0x249C
TurboBuildInterval 0x24A0
FortControllerComponent_Telemetry 0x24B0
InventoryNetworkManagementComponent 0x24B8
InteractionComponent 0x24C0
CollectionsComponent 0x24C8
PendingExecuteInventoryItemDefinition 0x24D0
QuickHealItemPickerClass 0x24F0
MeshParentIds 0x2510
OnToggleFullscreenMap 0x2520
ForcedInputRotationSpeed 0x2618
PendingClientRestartPawn 0x2620






Engine.World.PersistentLevel 0x30
Engine.GameInstance.LocalPlayers 0x38
Engine.Player.PlayerController 0x30
Engine.World.OwningGameInstance 0x188
Engine.Controller.ControlRotation 0x288
Engine.PlayerController.PlayerCameraManager 0x2B8
Engine.PlayerController.AcknowledgedPawn 0x2A0
Engine.Pawn.PlayerState 0x240
Engine.Actor.RootComponent 0x130
Engine.Character.Mesh 0x280
Engine.SceneComponent.RelativeLocation 0x11C
Engine.SceneComponent.RelativeRotation 0x128
Engine.SceneComponent.ComponentVelocity 0x140
Engine.SceneComponent.ComponentToWorld 0x14C
Engine.StaticMeshComponent.StaticMesh 0x480
Engine.SkinnedMeshComponent.CachedWorldSpaceBounds 0x618
Engine.Actor.CustomTimeDilation 0x98
Engine.Controller.RemoteViewPitch 0x232
FortniteGame.FortWeapon.LastFireTimeVerified 0x9F0
FortniteGame.FortWeapon.LastFireTime 0x9EC
FortniteGame.FortWeapon.bIsReloadingWeapon 0x2B9
FortniteGame.FortPawn.bIsDBNO 0x58E
FortniteGame.FortPawn.bIsDying 0x540
FortniteGame.FortPlayerStateAthena.TeamIndex 0xED8
FortniteGame.FortPlayerStateAthena.SquadId 0x105C
FortniteGame.FortPickup.PrimaryPickupItemEntry 0x2A8
FortniteGame.FortItemDefinition.DisplayName 0x88
FortniteGame.FortItemDefinition.Tier 0x6C
FortniteGame.FortItemEntry.ItemDefinition 0x18
FortniteGame.FortPawn.CurrentWeapon 0x610
FortniteGame.FortWeapon.WeaponData 0x380
FortniteGame.FortWeapon.AmmoCount 0xA78
FortniteGame.FortWeapon.LastFireAbilityTime 0xC18
FortniteGame.FortWeaponItemDefinition.WeaponStatHandle 0x830
FortniteGame.FortProjectileAthena.FireStartLoc 0x880
FortniteGame.FortBaseWeaponStats.ReloadTime 0x10C
FortniteGame.FortBaseWeaponStats.ReloadScale 0x110
FortniteGame.FortBaseWeaponStats.ChargeDownTime 0x13C
FortniteGame.FortRangedWeaponStats.RecoilHoriz 0x214
FortniteGame.FortRangedWeaponStats.RecoilVert 0x204
FortniteGame.FortRangedWeaponStats.RecoilDownsightsMultiplier 0x230
FortniteGame.BuildingContainer.bAlreadySearched 0xE39
FortniteGame.BuildingWeakSpot.bActive 0x250
FortniteGame.FortRangedWeaponStats.Spread 0x16C
FortniteGame.FortRangedWeaponStats.SpreadDownsights 0x174
FortniteGame.FortRangedWeaponStats.StandingStillSpreadMultiplier 0x178
FortniteGame.FortRangedWeaponStats.AthenaJumpingFallingSpreadMultiplier 0x180
FortniteGame.FortRangedWeaponStats.AthenaCrouchingSpreadMultiplier 0x17C
FortniteGame.FortRangedWeaponStats.AthenaSprintingSpreadMultiplier 0x184
FortniteGame.FortRangedWeaponStats.MinSpeedForSpreadMultiplier 0x188
FortniteGame.FortRangedWeaponStats.MaxSpeedForSpreadMultiplier 0x18C
FortniteGame.FortMeatballVehicle.FortMeatballVehicleConfigsClass 0x1878
FortniteGame.FortMeatballVehicleConfigs.BoostMinPushForce 0x558
FortniteGame.FortMeatballVehicleConfigs.BoostTopSpeedForceMultiplier 0x55C
FortniteGame.FortMeatballVehicleConfigs.BoostTopSpeedMultiplier 0x560
FortniteGame.FortMeatballVehicleConfigs.LandTopSpeedMultiplier 0x568
FortniteGame.FortMeatballVehicleConfigs.LandPushForceMultiplier 0x56C
FortniteGame.FortMeatballVehicleConfigs.BoostSteeringMultiplier 0x5AC
FortniteGame.FortMeatballVehicleConfigs.LandSteeringMultiplier 0x5B4
FortniteGame.FortMeatballVehicleConfigs.LandMinSpeedSteeringAngle 0x5B8
FortniteGame.FortMeatballVehicleConfigs.LandMaxSpeedSteeringAngle 0x5BC*/

//HRESULT(*present_original)(IDXGISwapChain* swapChain, UINT syncInterval, UINT flags) = nullptr;
//HRESULT(*resize_original)(IDXGISwapChain* swapChain, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags) = nullptr;

/*
enum StaticMeshComponent : uint64_t
{
	RootComponent_P = 0x130,
};

enum SceneComponent : uint64_t
{
	RelativeLocation = 0x11C,
	ComponentVelocity = 0x140,
};

enum WeaponFireLoc : uint64_t
{
	FireStartLoc = 0x878,
};

/*
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

	inline void ProcessEvent(void* fn, void* parms)
	{
		auto vtable = *reinterpret_cast<void***>(this);
		auto processEventFn = static_cast<void(*)(void*, void*, void*)>(vtable[0x44]);
		processEventFn(this, fn, parms);
	}

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

GObjects* objects = nullptr;
bool once = false;
namespace Framework {
	namespace Structs {


		struct FMatrix
		{
			float M[4][4];
		};
		static FMatrix* myMatrix = new FMatrix();


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

		namespace Objects {

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


			static const char* GetUObjectName(UObject* Object)
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


			static const char* GetUObjectNameLoop(UObject* Object) {
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

			const char* Gobject_Sig = "48 8B 05 ? ? ? ? 48 8B 0C C8 48 8B 04 D1";

			PVOID FindObject(std::string name) {
				static bool once = false;
				if (!once)
				{
					auto UObjectPtr = MemoryHelper::PatternScan(Gobject_Sig);
					objects = decltype(objects)(RelativeAddress(UObjectPtr, 7));

					once = true;
				}
				for (auto array : objects->ObjectArray->Objects) {
					auto fuObject = array;
					std::cout << "";
					for (auto i = 0; i < 0x10000 && fuObject->Object; ++i, ++fuObject) {
						std::cout << "";
						auto object = fuObject->Object;
						if (object->ObjectFlags != 0x41) {}
						else {
							std::cout << "";
							if (strstr(GetUObjectNameLoop(object), name.c_str())) return object;
						}
						std::cout << "";
					}
				}
				return 0;
			}

			inline bool ProcessEvent(uintptr_t address, void* fnobject, void* parms)
			{
				UObject* addr = reinterpret_cast<UObject*>(address); if (!addr) return false;
				auto vtable = *reinterpret_cast<void***>(addr); if (!vtable) return false;
				auto processEventFn = static_cast<void(*)(void*, void*, void*)>(vtable[0x68]); if (!processEventFn) return false;
				SpoofCall(processEventFn, (void*)addr, (void*)fnobject, (void*)parms);
				return true;
			}
		}
	}
}*/
/*
typedef struct {
	float X, Y, Z;
} FVector;



struct UPrimitiveComponent_SetActorEnableCollision_Params
{
	bool                                               bNewActorEnableCollision;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

/*
void SetActorEnableCollision(uint64_t CurrentActor, bool bNewActorEnableCollision) {
	static PVOID fn = nullptr;

	if (!fn)
		fn = FindObject(xorstrstr("SetActorEnableCollision"));
	UPrimitiveComponent_SetActorEnableCollision_Params params;
	params.bNewActorEnableCollision = bNewActorEnableCollision;
	ProcessEvent(CurrentActor, fn, &params);
}


// Function Engine.PrimitiveComponent.SetEnableGravity
struct UPrimitiveComponent_SetEnableGravity_Params
{
	bool                                               bGravityEnabled;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};
void SetEnableGravity(uint64_t primitive_component, bool bEnable)
{
	static PVOID fn = nullptr;

	if (!fn)
		fn = FindObject(xorstrstr("SetEnableGravity"));
	UPrimitiveComponent_SetEnableGravity_Params params;
	params.bGravityEnabled = bEnable;
	ProcessEvent(primitive_component, fn, &params);
}

struct APlayerController_FOV_Params
{
	bool                                               NewFOV;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

void FOV(uint64_t _this, float NewFOV)
{
	static PVOID fn = nullptr;

	if (!fn)
		fn = FindObject(xorstrstr("Function Engine.PlayerController.FOV"));

	APlayerController_FOV_Params params;
	params.NewFOV = NewFOV;

	//auto flags = fn->FunctionFlags;
	//fn->FunctionFlags |= 0x400;

	ProcessEvent(_this, fn, &params);

	//fn->FunctionFlags = flags;
}
//GetDistanceMeters = cameralocation.distance(localpawn) / 100

struct UPrimitiveComponent_SetAllPhysicsLinearVelocity_Params
{
	FVector                                            NewVel;                                                   // (Parm, IsPlainOldData)
	bool                                               bAddToCurrent;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

void SetAllPhysicsAngularVelocity(uint64_t primitive_component, const FVector& NewVel, bool bAddToCurrent)
{
	static PVOID fn = nullptr;

	if (!fn)
		fn = FindObject(xorstrstr("SetPhysicsAngularVelocity"));

	if (!fn) return;

	UPrimitiveComponent_SetAllPhysicsLinearVelocity_Params params;
	params.NewVel = NewVel;
	params.bAddToCurrent = bAddToCurrent;

	ProcessEvent(primitive_component, fn, &params);
}

void SetAllPhysicsLinearVelocity(uint64_t primitive_component, const FVector& NewVel, bool bAddToCurrent)
{
	static PVOID fn = nullptr;

	if (!fn)
		fn = FindObject(xorstrstr("SetPhysicsLinearVelocity"));
	UPrimitiveComponent_SetAllPhysicsLinearVelocity_Params params;
	params.NewVel = NewVel;
	params.bAddToCurrent = bAddToCurrent;




	ProcessEvent(primitive_component, fn, &params);
}

//GCameraCache->Rotation.Yaw = camerarotation.y

void ProcessVehicle(uintptr_t CurrentActor, Vector3 LocalRelativeLocation1)
{
	auto rc = read<uintptr_t>(CurrentActor + Offsets::RootComponent);//root component

	if (!rc)
		return;

	auto loc = read<Vector3>(rc + Offsets::RelativeLocation);

	if (LocalRelativeLocation1.Distance(loc) > 10)
		return;

	auto veh_mesh = *(uintptr_t*)(CurrentActor + Offsets::VehicleSkeletalMesh); if (!veh_mesh) return; //DGOffset_VehicleSkeletalMesh

	if (veh_mesh)
	{
		if (Undetected1337GetAsyncKeyState(0x4F))
		{
			///SetActorEnableCollision(CurrentActor, false);

			float coeff = (60.0f * 60);

			if (Undetected1337GetAsyncKeyState(VK_SHIFT))
			{
				coeff *= 2;
			}

			SetAllPhysicsAngularVelocity(veh_mesh, { 0, 0, 0 }, false);
			SetAllPhysicsLinearVelocity(veh_mesh, { 0, 0, 0 }, false);
			SetEnableGravity(veh_mesh, false);
			bool bKp = false;

			if (Undetected1337GetAsyncKeyState(0x51) & 0x8000)
			{
				SetAllPhysicsLinearVelocity(veh_mesh, { 0.f, 0.f, coeff / 2 }, true);
				bKp = true;
			}

			if (Undetected1337GetAsyncKeyState(0x45) & 0x8000)
			{
				SetAllPhysicsLinearVelocity(veh_mesh, { 0.f, 0.f, -(coeff / 2) }, true);
				bKp = true;
			}

			if (Undetected1337GetAsyncKeyState(0x57))
			{
				FVector vel;
				auto yaw = CamRot.y;
				float theta = 2.f * M_PI * (yaw / 360.f);

				vel.X = (coeff * cos(theta));
				vel.Y = (coeff * sin(theta));
				vel.Z = 0.f;

				SetAllPhysicsLinearVelocity(veh_mesh, vel, true);
				bKp = true;
			}
			if (Undetected1337GetAsyncKeyState(0x53))
			{
				FVector vel;
				auto yaw = CamRot.y;
				float theta = 2.f * M_PI * (yaw / 360.f);

				vel.X = -(coeff * cos(theta));
				vel.Y = -(coeff * sin(theta));

				SetAllPhysicsLinearVelocity(veh_mesh, vel, true); //{ -80.f, 0.f, 0.f }
				bKp = true;
			}
			if (Undetected1337GetAsyncKeyState(0x41)) // A
			{
				FVector vel;
				auto yaw = CamRot.y;
				float theta = 2.f * M_PI * (yaw / 360.f);

				vel.X = (coeff * sin(theta));
				vel.Y = -(coeff * cos(theta));

				SetAllPhysicsLinearVelocity(veh_mesh, vel, true); //{ -80.f, 0.f, 0.f }
				bKp = true;
			}
			if (Undetected1337GetAsyncKeyState(0x44)) // D
			{
				FVector vel;
				auto yaw = CamRot.y;
				float theta = 2.f * M_PI * (yaw / 360.f);

				vel.X = -(coeff * sin(theta));
				vel.Y = (coeff * cos(theta));

				SetAllPhysicsLinearVelocity(veh_mesh, vel, true); //{ -80.f, 0.f, 0.f }
				bKp = true;
			}

			if (!bKp || Undetected1337GetAsyncKeyState(VK_SPACE))
			{
				SetAllPhysicsLinearVelocity(veh_mesh, { 0.0, 0.0, 0.0 }, false);
			}
		}
		else
		{
			SetEnableGravity(veh_mesh, true);
			SetActorEnableCollision(CurrentActor, true);
		}
	}
}*/

/*
namespace addresses
{
	PVOID* uWorld = 0;
	//PVOID GetPlayerName = 0;
	PVOID SetPawnVisibility = 0;
	PVOID ClientSetRotation = 0;
	PVOID K2_TeleportTo = 0;
	PVOID SetActorLocation = 0;
	PVOID ClientSetLocation = 0;
	PVOID IsInVehicle = 0;
	PVOID SetActorRelativeScale3D = 0;
	PVOID SetMouseLocation = 0;
	PVOID AddYawInput = 0;
	PVOID AddPitchInput = 0;
	PVOID GetVehicleActor = 0;
	PVOID GetVehicle = 0;
	PVOID K2_AttachToActor = 0;
	PVOID SetForcedLodModel = 0;
	PVOID LaunchCharacter = 0;
	PVOID GetActorEnableCollision = 0;
	PVOID SetActorEnableCollision = 0;
	PVOID ECollisionEnabled = 0;
	PVOID SetCollisionEnabled = 0;
	PVOID SetControlRotation = 0;
	PVOID SetFirstPersonCamera = 0;
	PVOID K2_SetActorRelativeLocation = 0;
	PVOID K2_SetActorLocationAndRotation = 0;
	PVOID K2_AddRelativeLocation = 0;
	PVOID K2_SetRelativeLocation = 0;
	PVOID CreativeToggleFly = 0;
	PVOID ServerCreativeToggleFly = 0;
	PVOID K2_AttachTo = 0;
	PVOID K2_SetWorldLocation = 0;
	PVOID LaunchPawn = 0;
	PVOID OnLaunchPawn = 0;
	PVOID TeleportVehicle = 0;
	PVOID TeleportPlayerPawn = 0;
	PVOID K2_SetActorRotation = 0;
	PVOID K2_SetActorRelativeRotation = 0;
	PVOID K2_SetWorldRotation = 0;
	PVOID ReloadTime = 0;
	PVOID Fov = 0;

}*/

/*
namespace offsets
{
	BOOLEAN Initialize()
	{
		uint64_t BaseAddress = (uint64_t)GetModuleHandleA(NULL);

		addresses::Fov = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.PlayerController.FOV"));
		//addresses::GetPlayerName = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.PlayerState.GetPlayerName"));
		addresses::SetPawnVisibility = Framework::Structs::Objects::FindObject(xorstrstr("/Script/FortniteGame.FortPawn.SetPawnVisibility"));
		addresses::ClientSetRotation = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.Controller.ClientSetRotation"));
		addresses::K2_TeleportTo = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.Actor.K2_TeleportTo"));
		addresses::ClientSetLocation = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.Controller.ClientSetLocation"));
		addresses::SetActorRelativeScale3D = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.Actor.SetActorRelativeScale3D"));
		addresses::IsInVehicle = Framework::Structs::Objects::FindObject(xorstrstr("/Script/FortniteGame.FortPlayerPawn.IsInVehicle"));
		addresses::AddYawInput = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.PlayerController.AddYawInput"));
		addresses::AddPitchInput = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.PlayerController.AddPitchInput"));
		addresses::GetVehicleActor = Framework::Structs::Objects::FindObject(xorstrstr("/Script/FortniteGame.FortPlayerPawn.GetVehicleActor"));
		addresses::GetVehicle = Framework::Structs::Objects::FindObject(xorstrstr("/Script/FortniteGame.FortPlayerPawn.GetVehicle"));
		addresses::K2_AttachToActor = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.Actor.K2_AttachToActor"));
		addresses::K2_AttachTo = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.SceneComponent.K2_AttachTo"));
		addresses::LaunchCharacter = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.Character.LaunchCharacter"));
		addresses::SetForcedLodModel = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.StaticMeshComponent.SetForcedLodModel"));
		addresses::SetActorLocation = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.Actor.K2_SetActorLocation"));
		addresses::GetActorEnableCollision = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.Actor.GetActorEnableCollision"));
		addresses::SetActorEnableCollision = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.Actor.SetActorEnableCollision"));
		addresses::ECollisionEnabled = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.ECollisionEnabled"));
		addresses::SetCollisionEnabled = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.PrimitiveComponent.SetCollisionEnabled"));
		addresses::SetControlRotation = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.Controller.SetControlRotation"));
		addresses::SetFirstPersonCamera = Framework::Structs::Objects::FindObject(xorstrstr("/Script/FortniteGame.FortPlayerPawn.SetFirstPersonCamera"));
		addresses::K2_SetActorRelativeLocation = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.Actor.K2_SetActorRelativeLocation"));
		addresses::K2_SetActorLocationAndRotation = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.Actor.K2_SetActorLocationAndRotation"));
		addresses::K2_AddRelativeLocation = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.SceneComponent.K2_AddRelativeLocation"));
		addresses::K2_SetRelativeLocation = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.SceneComponent.K2_SetRelativeLocation"));
		addresses::CreativeToggleFly = Framework::Structs::Objects::FindObject(xorstrstr("/Script/FortniteGame.FortPlayerControllerGameplay.CreativeToggleFly")); //player fly ez
		addresses::ServerCreativeToggleFly = Framework::Structs::Objects::FindObject(xorstrstr("/Script/FortniteGame.FortPlayerControllerGameplay.ServerCreativeToggleFly")); //player fly ez
		addresses::K2_SetWorldLocation = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.SceneComponent.K2_SetWorldLocation"));
		addresses::LaunchPawn = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.Pawn.LaunchPawn"));
		addresses::OnLaunchPawn = Framework::Structs::Objects::FindObject(xorstrstr("/Script/FortniteGame.FortAthenaSKPushCannon.OnLaunchPawn"));
		addresses::TeleportVehicle = Framework::Structs::Objects::FindObject(xorstrstr("/Script/FortniteGame.FortRiftProjectile.TeleportVehicle"));
		addresses::TeleportPlayerPawn = Framework::Structs::Objects::FindObject(xorstrstr("/Script/FortniteGame.FortMissionLibrary.TeleportPlayerPawn"));
		addresses::K2_SetActorRotation = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.Actor.K2_SetActorRotation"));
		addresses::K2_SetActorRelativeRotation = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.Actor.K2_SetActorRelativeRotation"));
		addresses::K2_SetWorldRotation = Framework::Structs::Objects::FindObject(xorstrstr("/Script/Engine.SceneComponent.K2_SetWorldRotation"));

		return TRUE;
	}
}*/

/*
auto GetSyscallIndex(std::string ModuleName, std::string SyscallFunctionName, void* Function) -> bool
{
	auto ModuleBaseAddress = LI_FN(GetModuleHandleA).safe()(ModuleName.c_str());
	if (!ModuleBaseAddress)
		ModuleBaseAddress = LI_FN(LoadLibraryA).safe()(ModuleName.c_str());
	if (!ModuleBaseAddress)
		return false;

	auto GetFunctionAddress = LI_FN(GetProcAddress).safe()(ModuleBaseAddress, SyscallFunctionName.c_str());
	if (!GetFunctionAddress)
		return false;

	auto SyscallIndex = *(DWORD*)((PBYTE)GetFunctionAddress + 4);

	*(DWORD*)((PBYTE)Function + 4) = SyscallIndex;

	return true;
}

extern "C"
{
	NTSTATUS _NtUserSendInput(UINT a1, LPINPUT Input, int Size);
};

VOID mouse_event_(DWORD dwFlags, DWORD dx, DWORD dy, DWORD dwData, ULONG_PTR dwExtraInfo)
{
	static bool doneonce;
	if (!doneonce)
	{
		if (!GetSyscallIndex(xorstr_("win32u.dll"), xorstr_("NtUserSendInput"), _NtUserSendInput))
			return;
		doneonce = true;
	}

	INPUT Input[3] = { 0 };
	Input[0].type = INPUT_MOUSE;
	Input[0].mi.dx = dx;
	Input[0].mi.dy = dy;
	Input[0].mi.mouseData = dwData;
	Input[0].mi.dwFlags = dwFlags;
	Input[0].mi.time = 0;
	Input[0].mi.dwExtraInfo = dwExtraInfo;

	_NtUserSendInput((UINT)1, (LPINPUT)&Input, (INT)sizeof(INPUT));
}*/

/*
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
*/

//snapline from gun
//SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 85, gun_in_hand_pos);
//SDK::Classes::AController::WorldToScreen(gun_in_hand_pos, &gun_in_hand_pos);

//PVOID(*ProcessEvent)(uintptr_t, PVOID, PVOID, PVOID) = nullptr;

/*
void SetPlayerVisibility(int VisibilityValue, uintptr_t Pawn)
{
	if (LocalPawn && PlayerController)
	{
		ProcessEvent(Pawn, addresses::K2_TeleportTo, &VisibilityValue, 0);
	}
}*/

/*

void FOV(PVOID address, uintptr_t Controller, float NewFOV)
{
	//Framework::Structs::Objects::ProcessEvent(address, Controller, &NewFOV);
}


//float ItemDist;
bool objectA;

/*
BOOL IsPawnInVehicle()
{
	bool VehicleReturnValue;

	if (PlayerController)
		Framework::Structs::Objects::ProcessEvent(LocalPawn, addresses::IsInVehicle, &VehicleReturnValue);
	else
		VehicleReturnValue = false;

	return VehicleReturnValue;
}

void Teleport(uintptr_t Pawn, SDK::Structs::FVector Coords)
{
	if (LocalPawn && PlayerController)
	{
		Framework::Structs::Objects::ProcessEvent(Pawn, addresses::LaunchCharacter /*addresses::K2_TeleportTo, &Coords);
	}
}

void Teleport2(SDK::Structs::FVector Coords)
{
	//if (IsPawnInVehicle) {
		if (LocalPawn && PlayerController)
		{
			Framework::Structs::Objects::ProcessEvent(PlayerController, addresses::ClientSetLocation/*addresses::LaunchCharacte, &Coords);
		}
	//}
}*/

/*bool K2_TeleportTo(PVOID Actor, bool DestRotation, bool ReturnValue)
{
	if (Actor != nullptr)
	{
		auto vtable = ReadPointer(Actor, 0);
		if (!vtable) return false;

		auto func ReadPointer(vtable, 0x4F8);
		if (!func) return false;

		auto K2_TeleportTo = reinterpret_cast<void(__fastcall*)(uintptr_t, bool, bool)>(func);

		FortniteUtils::SpoofCall(K2_TeleportTo, (uintptr_t)Actor, DestRotation, ReturnValue);

		return true;
	}

	return false;
}*/

/*
bool K2_TeleportTo(PVOID Actor, SDK::Structs::FVector DestLocation, SDK::Structs::FRotator DestRotation)
{
	if (Actor != nullptr)
	{
		auto vtable = ReadPointer(Actor, 0);
		if (!vtable) return false;

		auto func ReadPointer(vtable, 0x4F8);
		if (!func) return false;

		auto K2_TeleportTo = reinterpret_cast<void(__fastcall*)(uintptr_t, SDK::Structs::FVector, SDK::Structs::FRotator)>(func);

		SpoofCall(K2_TeleportTo, (uintptr_t)Actor, DestLocation, DestRotation);

		return true;
	}

	return false;
}*/

/*
inline bool __fastcall SetCurrentSpread(__int64 CurrentWeapon, float spread)
{
	unsigned __int8* currentWeapon;
	__int64 v9;
	int v10;
	double v29;
	float result;

	currentWeapon = (unsigned __int8*)CurrentWeapon;
	v9 = currentWeapon[0x610];
	v10 = currentWeapon[0x610] | 0x4C000001; //3759

	if (!v9 || v10)
	{
		return 0;
	}

	v29 = *(DWORD*)&currentWeapon[4 * v9 + 0x610];

	result = *(float*)(v10 ^ (int)v29) = spread;

	return result;
}

ULONG GetViewPointHook(uintptr_t player, Vector3* viewInfo, Vector3* stereoPass)
{
	int fovval;
	if (Settings_as7d6as6d::Fovchanger_asdbasyudgasuydgasydugasdyuasgd)
	{
		fovval = Settings_as7d6as6d::fov_change_value_sahdbasuydgasuydgasyudgasuydgasuyd;
	}
	else
	{
		fovval = 80;
	}
	const float upperFOV = 50.534008f;
	const float lowerFOV = 40.0f;

	auto ret = GetViewPoint(player, viewInfo, stereoPass);

	auto fov = viewInfo->FOV;
	auto desired = (((180.0f - upperFOV) / (180.0f - 80.0f)) * (fovval - 80.0f)) + upperFOV;

	if (fov > upperFOV) {
		fov = desired;
	}
	else if (fov > lowerFOV) {
		fov = (((fov - lowerFOV) / (upperFOV - lowerFOV)) * (desired - lowerFOV)) + lowerFOV;
	}
	viewInfo->FOV = fov;

	return ret;
}*/

/*
void RadarRange(float* x, float* y, float range)
{
	if (fabs((*x)) > range || fabs((*y)) > range)
	{
		if ((*y) > (*x))
		{
			if ((*y) > -(*x))
			{
				(*x) = range * (*x) / (*y);
				(*y) = range;
			}
			else
			{
				(*y) = -range * (*y) / (*x);
				(*x) = -range;
			}
		}
		else
		{
			if ((*y) > -(*x))
			{
				(*y) = range * (*y) / (*x);
				(*x) = range;
			}
			else
			{
				(*x) = -range * (*x) / (*y);
				(*y) = -range;
			}
		}
	}
}

typedef struct {
	float Pitch;
	float Yaw;
	float Roll;
} FRotator;

void CalcRadarPoint(SDK::Structs::FVector vOrigin, int& screenx, int& screeny)
{
	FRotator vAngle = FRotator{ CamRot.x, CamRot.y, CamRot.z };
	auto fYaw = vAngle.Yaw * M_PI / 180.0f;
	float dx = vOrigin.X - CamLoc.x;
	float dy = vOrigin.Y - CamLoc.y;

	float fsin_yaw = sinf(fYaw);
	float fminus_cos_yaw = -cosf(fYaw);

	float x = dy * fminus_cos_yaw + dx * fsin_yaw;
	x = -x;
	float y = dx * fminus_cos_yaw - dy * fsin_yaw;

	float range = (float)Settings_as7d6as6d::RadarDistance_uytasfduasfdutasfdytasdfytasfdatysfd;

	RadarRange(&x, &y, range);

	ImVec2 DrawPos = ImGui::GetCursorScreenPos();
	ImVec2 DrawSize = ImGui::GetContentRegionAvail();

	int rad_x = (int)DrawPos.x;
	int rad_y = (int)DrawPos.y;

	float r_siz_x = DrawSize.x;
	float r_siz_y = DrawSize.y;

	int x_max = (int)r_siz_x + rad_x - 5;
	int y_max = (int)r_siz_y + rad_y - 5;

	screenx = rad_x + ((int)r_siz_x / 2 + int(x / range * r_siz_x));
	screeny = rad_y + ((int)r_siz_y / 2 + int(y / range * r_siz_y));

	if (screenx > x_max)
		screenx = x_max;

	if (screenx < rad_x)
		screenx = rad_x;

	if (screeny > y_max)
		screeny = y_max;

	if (screeny < rad_y)
		screeny = rad_y;
}

SDK::Structs::FVector* GetPawnRootLocation(uintptr_t pawn) {
	uintptr_t root = read(pawn, Offsets::RootComponent);
	if (!root) {
		return nullptr;
	}

	return reinterpret_cast<SDK::Structs::FVector*>(reinterpret_cast<PBYTE>(root) + Offsets::RelativeLocation);
}

std::vector<uint64_t> radarPawns;

void renderRadar() {
	for (auto CurrentActor : radarPawns) {
		auto player = CurrentActor;

		int screenx = 0;
		int screeny = 0;

		float Color_R = 255 / 255.f;
		float Color_G = 128 / 255.f;
		float Color_B = 0 / 255.f;

		SDK::Structs::FVector pos = *GetPawnRootLocation((uintptr_t)CurrentActor);

		CalcRadarPoint(pos, screenx, screeny);

		ImDrawList* Draw = ImGui::GetOverlayDrawList();

		SDK::Structs::FVector viewPoint = { 0 };
		//if (IsTargetVisible(pawn)) {
		//	Color_R = 128 / 255.f;
		//	Color_G = 224 / 255.f;
		//	Color_B = 0 / 255.f;
		//}
		Draw->AddRectFilled(ImVec2((float)screenx, (float)screeny),
			ImVec2((float)screenx + 5, (float)screeny + 5),
			ImColor(Color_R, Color_G, Color_B));
	}

}*/


//uintptr_t localPlayerWeapon = read<uintptr_t>(LocalPawn + Offsets::CurrentWeapon);
//if (!localPlayerWeapon) return false;

//auto weaponName = SDK::Classes::UObject::GetObjectNameA(localPlayerWeapon);

//auto isProjectileWeapon = strstr(weaponName, xorstr_("Rifle_Sniper"));
//auto isRocketLauncher = strstr(weaponName, xorstr_("RocketLauncher"));
//auto isGrenadeLauncher = strstr(weaponName, xorstr_("GrenadeLauncher"));
//auto isCrossbow = strstr(weaponName, xorstr_("Crossbow"));
//auto isBoomBow = strstr(weaponName, xorstr_("ExplosiveBow"));

					//auto localPlayerTeamIndex = read(LocalPlayer, Offsets::TeamIndex); //my player        
					//auto localPlayerSquadID = read(LocalPlayer, Offsets::SquadId); //my player

					//auto OtherPlayerTeamIndex = read(MyState, 0xED8); //other players
					//auto OtherPlayerSquadID = read(MyState, 0x105C);  //other players

					/*
					if (Settings_as7d6as6d::TeleportDownedToLocalPawn_asudygasuydgasydugasduygasyudgasd) {
						if (LocalPawn && PlayerController) {
							//uintptr_t bIsBeingDBNOCarried = 0x2A36; //huh
							//uintptr_t bIsDBNOCarrying = 0x2A37; //huh
							//write<float>(LocalPawn + 0x2A36, 1.00f);
							write<float>(LocalPawn + 0x2A37, 1.00f);

							//write<float>(MyState + 0xED8 + 0x2A36, 1.00f); // AFortPlayerPawnAthena->ReviveFromDBNOTime
							write<float>(MyState + 0x105C + 0x2A37, 1.00f); // AFortPlayerPawnAthena->ReviveFromDBNOTime

							//write<float>(MyState + 0x105C + 0x2A36, 1.00f); // AFortPlayerPawnAthena->ReviveFromDBNOTime
							write<float>(MyState + 0xED8 + 0x2A37, 1.00f); // AFortPlayerPawnAthena->ReviveFromDBNOTime
						}
					}
					*/

					//SquadId 0x105C
					//TeamIndex 0xED8 
					/*
					if (Settings_as7d6as6d::playerChams_asuijdhasiudhasiudhasuidh) {
						//writing the players squad id to our own squad id
						write<float>(MyState + 0x105C, localPlayerSquadID);
						//writing the players team index to our own team index
						write<float>(MyState + 0xED8, localPlayerTeamIndex);
					}*/

					/*
					if (Settings_as7d6as6d::Bullettp_usauuidhiusdahgsduifghf) {
						if (TargetPawn && LocalPawn) {
							if (strstr(name, xorstr_("B_Prj_Bullet_Sniper")) || strstr(name, xorstr_("OnRep_FireStart"))) {
								Vector3 ret;
								Vector3 headvec3;
								SDK::Classes::USkeletalMeshComponent::GetBoneLocation((uintptr_t)TargetPawn, Settings_as7d6as6d::aimbone_iyashgdiuyasgdyuasgds, &headvec3);
								SDK::Structs::FVector head = { headvec3.x, headvec3.y , headvec3.z };

								uintptr_t RootComp = read<uintptr_t>(LocalPawn + Offsets::RootComponent);
								Vector3 RootCompLocationvec3 = read<Vector3>(RootComp + Offsets::RelativeLocation);
								SDK::Structs::FVector RootCompLocation = { RootCompLocationvec3.x, RootCompLocationvec3.y , RootCompLocationvec3.z };
								SDK::Structs::FVector* RootCompLocation_check = &RootCompLocation;
								if (!RootCompLocation_check) return ret;
								auto root = RootCompLocation;

								auto dx = head.X - root.X;
								auto dy = head.Y - root.Y;
								auto dz = head.Z - root.Z;

								*reinterpret_cast<Vector3*>(reinterpret_cast<PBYTE>(objectA) + Offsets::FireStartLoc) = RootCompLocation;

								auto root = reinterpret_cast<PBYTE>(read(objectA, Offsets::RootComponent));
								*reinterpret_cast<Vector3*>(root + Offsets::RelativeLocation) = RootCompLocation;
								memset(root + Offsets::ComponentVelocity, 0, sizeof(Vector3));
							}
						}
					}*/

					//uintptr_t MyTeamIndex = 0x44D, EnemyTeamIndex = 0x2E8;


										//if (Settings_as7d6as6d::smooth_yuasghsdyiuawsgdyasgduy > 0)
										//NewRotation = SDK::Utils::SmoothAngles(CamRot, NewRotation);

										//NewRotation.z = 0;


									//if (Settings_as7d6as6d::smooth_yuasghsdyiuawsgdyasgduy > 0)
									//NewRotation = SDK::Utils::SmoothAngles(CamRot, NewRotation);

									//NewRotation.z = 0;

					/*
					if (Settings_as7d6as6d::Tp_yashdguyasdgauysdgasudgasuydgasyud) {
						uintptr_t VehicleRootComponent = read<uintptr_t>(CurrentActor + Offsets::RootComponent);
						Vector3 VehiclePosition1 = read<Vector3>(VehicleRootComponent + Offsets::RelativeLocation);

						SDK::Structs::FVector TpPos = { 1,1,1 };

						if (Undetected1337GetAsyncKeyState(0x57)) { //w
							TpPos.X = TpPos.X + 50;
						}
						if (Undetected1337GetAsyncKeyState(0x53)) { //s
							TpPos.X = TpPos.X - 50;
						}
						if (Undetected1337GetAsyncKeyState(0x41)) { //a
							TpPos.Y = TpPos.Y + 50;
						}
						if (Undetected1337GetAsyncKeyState(0x44)) { //d
							TpPos.Y = TpPos.Y - 50;
						}
						if (Undetected1337GetAsyncKeyState(VK_SPACE)) { //space
							TpPos.Z = TpPos.Z + 50;
						}

						Teleport(CurrentActor, { TpPos });
					}*/

					/*
					if (Settings_as7d6as6d::memoryv2_asdhfiusdhuidshfiudfshfuidfshiudfghiufdhgfdui) //xd it's just spinbot
					{
						if (Settings_as7d6as6d::VisibleCheck_dsf7fg676dfg6dgf67hdg67h56dfgh and IsVisible and SDK::Utils::CheckIfInFOV(CurrentActor, FOVmax))
						{
							if (LocalPawn && PlayerController)
							{
								Vector3 HeadPos, Headbox, bottom;
								SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 66, &HeadPos);
								SDK::Classes::AController::WorldToScreen(Vector3(HeadPos.x, HeadPos.y, HeadPos.z), &Headbox);

								if (Undetected1337GetAsyncKeyState(Settings_as7d6as6d::aimkey_asuydguyasdguyasdyfgyu)) {
									SDK::Structs::FVector F_1Rotation = { 100,0,0 };
									SDK::Structs::FVector F_2Rotation = { 200,0,0 };
									SDK::Structs::FVector F_3Rotation = { 300,0,0 };
									SDK::Structs::FVector F_4Rotation = { 400,0,0 };
									SDK::Structs::FVector F_5Rotation = { 500,0,0 };
									SDK::Structs::FVector F_6Rotation = { 600,0,0 };
									Framework::Structs::Objects::ProcessEvent(PlayerController, addresses::ClientSetLocation, &F_1Rotation);
									Framework::Structs::Objects::ProcessEvent(PlayerController, addresses::ClientSetLocation, &F_2Rotation);
									Framework::Structs::Objects::ProcessEvent(PlayerController, addresses::ClientSetLocation, &F_3Rotation);
									Framework::Structs::Objects::ProcessEvent(PlayerController, addresses::ClientSetLocation, &F_4Rotation);
									Framework::Structs::Objects::ProcessEvent(PlayerController, addresses::ClientSetLocation, &F_5Rotation);
									Framework::Structs::Objects::ProcessEvent(PlayerController, addresses::ClientSetLocation, &F_6Rotation);
								}
								else if (!Settings_as7d6as6d::VisibleCheck_dsf7fg676dfg6dgf67hdg67h56dfgh) {
									if (LocalPawn && PlayerController)
									{
										if (Undetected1337GetAsyncKeyState(Settings_as7d6as6d::aimkey_asuydguyasdguyasdyfgyu)) {
											SDK::Structs::FVector F_1Rotation = { 100,0,0 };
											SDK::Structs::FVector F_2Rotation = { 200,0,0 };
											SDK::Structs::FVector F_3Rotation = { 300,0,0 };
											SDK::Structs::FVector F_4Rotation = { 400,0,0 };
											SDK::Structs::FVector F_5Rotation = { 500,0,0 };
											SDK::Structs::FVector F_6Rotation = { 600,0,0 };
											Framework::Structs::Objects::ProcessEvent(PlayerController, addresses::ClientSetLocation, &F_1Rotation);
											Framework::Structs::Objects::ProcessEvent(PlayerController, addresses::ClientSetLocation, &F_2Rotation);
											Framework::Structs::Objects::ProcessEvent(PlayerController, addresses::ClientSetLocation, &F_3Rotation);
											Framework::Structs::Objects::ProcessEvent(PlayerController, addresses::ClientSetLocation, &F_4Rotation);
											Framework::Structs::Objects::ProcessEvent(PlayerController, addresses::ClientSetLocation, &F_5Rotation);
											Framework::Structs::Objects::ProcessEvent(PlayerController, addresses::ClientSetLocation, &F_6Rotation);
										}
									}
								}
							}
						}
					}*/

					// AFortPlayerPawnAthena->ReviveFromDBNOTime
											   //Settings_as7d6as6d::InstantRevive_ayussgd7adft76sdf5s6df56sdf = false;

					/*
					uintptr_t localPlayerWeapon;

					if (Settings_as7d6as6d::norecoil_ashdyiasdgasydgasyudgasyudgasydg && LocalPawn) {

						static float last_fire_ability_time = 0.f;
						localPlayerWeapon = read(LocalPawn, Offsets::CurrentWeapon);
						auto stats = GetWeaponStats(localPlayerWeapon);

						auto& RecoilVert = *reinterpret_cast<float*>(reinterpret_cast<PBYTE>(stats) + Offsets::RecoilVert);
						auto& RecoilHoriz = *reinterpret_cast<float*>(reinterpret_cast<PBYTE>(stats) + Offsets::RecoilHoriz);
						auto& RecoilDownsightsMultiplier = *reinterpret_cast<float*>(reinterpret_cast<PBYTE>(stats) + Offsets::RecoilDownsightsMultiplier);

						bool originalRecoilVert;
						bool originalRecoilHoriz;
						bool originalRecoilDownsightsMultiplier;

						if (GetWeaponStats(localPlayerWeapon) != nullptr)
						{
							if (Undetected1337GetAsyncKeyState(0x51)) {
								return false;
							}
							if (stats)
							{
								if (*(float*)(localPlayerWeapon + Offsets::LastFireAbilityTime) != last_fire_ability_time) {
									last_fire_ability_time = *(float*)(localPlayerWeapon + Offsets::LastFireAbilityTime);

									originalRecoilVert = RecoilVert;
									originalRecoilHoriz = RecoilHoriz;
									originalRecoilDownsightsMultiplier = RecoilDownsightsMultiplier;

									RecoilVert = 0.0f;
									RecoilHoriz = 0.0f;
									RecoilDownsightsMultiplier = 0.0f;

								}

							}
						}
						else if (*(float*)(localPlayerWeapon + Offsets::LastFireAbilityTime) == last_fire_ability_time) {
							last_fire_ability_time = *(float*)(localPlayerWeapon + Offsets::LastFireAbilityTime);

							RecoilVert = originalRecoilVert;
							RecoilHoriz = originalRecoilHoriz;
							RecoilDownsightsMultiplier = originalRecoilDownsightsMultiplier;
							return true;
						}
					}

					if (Settings_as7d6as6d::NospreadV3_svdiousdfuihsdfhuidsfuyhsfdhuifhsudi && LocalPawn) {

						static float last_fire_ability_time = 0.f;
						localPlayerWeapon = read(LocalPawn, Offsets::CurrentWeapon);
						auto stats = GetWeaponStats(localPlayerWeapon);

						auto& Spread = *reinterpret_cast<float*>(reinterpret_cast<PBYTE>(stats) + Offsets::Spread);
						auto& SpreadDownsights = *reinterpret_cast<float*>(reinterpret_cast<PBYTE>(stats) + Offsets::SpreadDownsights);
						auto& StandingStillSpreadMultiplier = *reinterpret_cast<float*>(reinterpret_cast<PBYTE>(stats) + Offsets::StandingStillSpreadMultiplier);
						auto& AthenaJumpingFallingSpreadMultiplier = *reinterpret_cast<float*>(reinterpret_cast<PBYTE>(stats) + Offsets::AthenaJumpingFallingSpreadMultiplier);
						auto& AthenaCrouchingSpreadMultiplier = *reinterpret_cast<float*>(reinterpret_cast<PBYTE>(stats) + Offsets::AthenaCrouchingSpreadMultiplier);
						auto& AthenaSprintingSpreadMultiplier = *reinterpret_cast<float*>(reinterpret_cast<PBYTE>(stats) + Offsets::AthenaSprintingSpreadMultiplier);
						auto& MinSpeedForSpreadMultiplier = *reinterpret_cast<float*>(reinterpret_cast<PBYTE>(stats) + Offsets::MinSpeedForSpreadMultiplier);
						auto& MaxSpeedForSpreadMultiplier = *reinterpret_cast<float*>(reinterpret_cast<PBYTE>(stats) + Offsets::MaxSpeedForSpreadMultiplier);

						bool originalSpread;
						bool originalSpreadDownsights;
						bool originalStandingStillSpreadMultiplier;
						bool originalAthenaJumpingFallingSpreadMultiplier;
						bool originalAthenaCrouchingSpreadMultiplier;
						bool originalAthenaSprintingSpreadMultiplier;
						bool originalMinSpeedForSpreadMultiplier;
						bool originalMaxSpeedForSpreadMultiplier;

						if (GetWeaponStats(localPlayerWeapon) != nullptr)
						{
							if (Undetected1337GetAsyncKeyState(0x51)) {
								return false;
							}
							if (stats)
							{
								if (*(float*)(localPlayerWeapon + Offsets::LastFireAbilityTime) != last_fire_ability_time) {

									last_fire_ability_time = *(float*)(localPlayerWeapon + Offsets::LastFireAbilityTime);
									originalSpread = Spread;
									originalSpreadDownsights = SpreadDownsights;
									originalStandingStillSpreadMultiplier = StandingStillSpreadMultiplier;
									originalAthenaJumpingFallingSpreadMultiplier = AthenaJumpingFallingSpreadMultiplier;
									originalAthenaCrouchingSpreadMultiplier = AthenaCrouchingSpreadMultiplier;
									originalAthenaSprintingSpreadMultiplier = AthenaSprintingSpreadMultiplier;
									originalMinSpeedForSpreadMultiplier = MinSpeedForSpreadMultiplier;
									originalMaxSpeedForSpreadMultiplier = MaxSpeedForSpreadMultiplier;

									Spread = 0.0f;
									SpreadDownsights = 0.0f;
									StandingStillSpreadMultiplier = 0.0f;
								}

							}
						}
						else if (*(float*)(localPlayerWeapon + Offsets::LastFireAbilityTime) == last_fire_ability_time) {

							last_fire_ability_time = *(float*)(localPlayerWeapon + Offsets::LastFireAbilityTime);
							Spread = originalSpread;
							SpreadDownsights = originalSpreadDownsights;
							StandingStillSpreadMultiplier = originalStandingStillSpreadMultiplier;
							AthenaJumpingFallingSpreadMultiplier = originalAthenaJumpingFallingSpreadMultiplier;
							AthenaCrouchingSpreadMultiplier = originalAthenaCrouchingSpreadMultiplier;
							AthenaSprintingSpreadMultiplier = originalAthenaSprintingSpreadMultiplier;
							MinSpeedForSpreadMultiplier = originalMinSpeedForSpreadMultiplier;
							MaxSpeedForSpreadMultiplier = originalMaxSpeedForSpreadMultiplier;

							return true;
						}
					}

					if (Settings_as7d6as6d::instantreload_sahduyhiasdgbjyasdvasdg && LocalPawn) {

						static float last_fire_ability_time = 0.f;
						localPlayerWeapon = read(LocalPawn, Offsets::CurrentWeapon);
						auto stats = GetWeaponStats(localPlayerWeapon);

						auto& reloadTime = *reinterpret_cast<float*>(reinterpret_cast<PBYTE>(stats) + Offsets::ReloadTime);
						auto& ReloadScale = *reinterpret_cast<float*>(reinterpret_cast<PBYTE>(stats) + Offsets::ReloadScale);
						auto& ChargeDownTime = *reinterpret_cast<float*>(reinterpret_cast<PBYTE>(stats) + Offsets::ChargeDownTime);

						float originalReloadTime = 1.0f;
						float originalReloadScale = 1.0f;
						float originalChargeDownTime = 1.0f;

						if (GetWeaponStats(localPlayerWeapon) != nullptr)
						{
							if (Undetected1337GetAsyncKeyState(0x51)) {
								return false;
							}
							if (stats) {
								if (reloadTime != 0.01f && *(float*)(localPlayerWeapon + Offsets::LastFireAbilityTime) == last_fire_ability_time) {
									last_fire_ability_time = *(float*)(localPlayerWeapon + Offsets::LastFireAbilityTime);

									originalReloadTime = reloadTime;
									originalReloadScale = ReloadScale;
									originalChargeDownTime = ChargeDownTime;

									reloadTime = 0.0f;
									ReloadScale = 0.0f;
									ChargeDownTime = 0.1f;
								}
								else if (reloadTime = 0.0f && *(float*)(localPlayerWeapon + Offsets::LastFireAbilityTime) != last_fire_ability_time) {
									{
										last_fire_ability_time = *(float*)(localPlayerWeapon + Offsets::LastFireAbilityTime);
										reloadTime = originalReloadTime;
										ReloadScale = originalReloadScale;
										ChargeDownTime = originalChargeDownTime;
										return true;
									}
								}
							}
						}
					}*/

					//Framework::Structs::FString PlayerName;

					//if (Settings_as7d6as6d::playerflyez_yashdguyasdgauysdgasudgasuydgasyud) //vehicle tp
					//{
					//if (LocalPawn) {
					//Framework::Structs::Objects::ProcessEvent(LocalPawn, addresses::ServerCreativeToggleFly, &PlayerName);
					//}
					//}

					//addresses::CreativeToggleFly = Framework::Structs::Objects::FindObject(xorstr_("/Script/FortniteGame.FortPlayerControllerGameplay.CreativeToggleFly")); //player fly ez
					//addresses::ServerCreativeToggleFly = Framework::Structs::Objects::FindObject(xorstr_("/Script/FortniteGame.FortPlayerControllerGameplay.ServerCreativeToggleFly")); //player fly ez

					/*
					if (Settings_as7d6as6d::FriendlyFire_ashduyasghduyasgdyuasghdyasd) {
						if (LocalPawn && PlayerController)
						{
							write<float>(LocalPawn + 0x1A0, 1.00f);
							write<float>(LocalPawn + 0xC82, 1.00f);
						}
					}*/
					//end


					//Framework::Structs::FString PlayerName;

					//Framework::Structs::Objects::ProcessEvent(PlayerState, FNObjects::GetPlayerName, &PlayerName);

					//color SkeletonColor;

					//SkeletonColor = { 230, 255, 231, 94 }; //Visible Color

/*
if (Settings_as7d6as6d::PlayerNames_asiudhasuydgasuydgasuydgadysugdsyugdsauyasgd)
{
	//pFontWrapper->DrawString(pContext, PlayerName.c_str(), 14, Headbox.x, Headbox.y, kekColorToUint32(SkeletonColor), FW1_RESTORESTATE);
}

/*
if (Settings_as7d6as6d::radaresp_uaisdghaisdgdygyugasyugasuyas) {

	ImGuiStyle* style = &ImGui::GetStyle();
	style->WindowRounding = 0.2f;

	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.13529413f, 0.14705884f, 0.15490198f, 0.82f));
	ImGuiWindowFlags TargetFlags;

	TargetFlags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse;

	if (!firstS) {
		ImGui::SetNextWindowPos(ImVec2{ /*220, 40015, 830 }, ImGuiCond_Once);
		firstS = true;
	}
	if (ImGui::Begin(xorstr_("radar"), 0, ImVec2(200, 200), -1.f, TargetFlags))
	{
		ImDrawList* Draw = ImGui::GetOverlayDrawList();
		ImVec2 DrawPos = ImGui::GetCursorScreenPos();
		ImVec2 DrawSize = ImGui::GetContentRegionAvail();

		ImVec2 midRadar = ImVec2(DrawPos.x + (DrawSize.x / 2), DrawPos.y + (DrawSize.y / 2));

		Overlay()->AddLine(ImVec2(midRadar.x - DrawSize.x / 2.f, midRadar.y), ImVec2(midRadar.x + DrawSize.x / 2.f, midRadar.y), ImColor(0, 0, 0, 50));
		Overlay()->AddLine(ImVec2(midRadar.x, midRadar.y - DrawSize.y / 2.f), ImVec2(midRadar.x, midRadar.y + DrawSize.y / 2.f), ImColor(0, 0, 0, 50));

		if (PlayerController || PlayerCameraManager && LocalPawn && CamRot.y) {
			//renderRadar();
		}
	}
	ImGui::PopStyleColor();
	ImGui::End();

}*/




/*
if (!LocalPawn) return false;

int AtLeastOneBool = 0;
if (Settings_as7d6as6d::ChestESP_sadhufgsuydfgsdyufgtsdyufgsdf) AtLeastOneBool++;
if (Settings_as7d6as6d::AmmoBoxESP_asydgausydt6asdtauysdtgausydtasyud) AtLeastOneBool++;
if (Settings_as7d6as6d::LootESP_std67astd76as5dt6as5d6as5dasdasdas) AtLeastOneBool++;
//if (Settings_as7d6as6d::PlayerWeapons_asuisdghasuydgasyudgasuydgasudygasudy) AtLeastOneBool++;

if (AtLeastOneBool == 0) return false;

for (auto Itemlevel_i = 0UL; Itemlevel_i < read<DWORD>(GWorld + (Offsets::Levels + sizeof(PVOID))); ++Itemlevel_i)
{
	uintptr_t ItemLevels = read<uintptr_t>(GWorld + Offsets::Levels);
	if (!ItemLevels) return false;

	uintptr_t ItemLevel = read<uintptr_t>(ItemLevels + (Itemlevel_i * sizeof(uintptr_t)));
	if (!ItemLevel) return false;

	for (int i = 0; i < read<DWORD>(ItemLevel + (Offsets::AActors + sizeof(PVOID))); ++i)
	{
		uintptr_t ItemsPawns = read<uintptr_t>(ItemLevel + Offsets::AActors);
		if (!ItemsPawns) return false;

		uintptr_t CurrentItemPawn = read<uintptr_t>(ItemsPawns + (i * sizeof(uintptr_t)));
		if (!CurrentItemPawn) return false;

		auto CurrentItemPawnName = SDK::Classes::UObject::GetObjectNameA(CurrentItemPawn);

		if (LocalPawn && CurrentItemPawn && CurrentItemPawnName) {
			//Loot ESP
			//LootESP(Overlay(), CurrentItemPawnName, CurrentItemPawn, LocalRelativeLocation1);
		}
	}
}*/

//colors[ImGuiCol_Text] = textColor;
//colors[ImGuiCol_TextDisabled] = textDisabledColor;
//colors[ImGuiCol_TextSelectedBg] = panelActiveColor;

	//colors[ImGuiCol_ChildBg] = bgColor;

	//colors[ImGuiCol_Header] = panelColor;
	//colors[ImGuiCol_HeaderHovered] = panelHoverColor;
	//colors[ImGuiCol_HeaderActive] = panelActiveColor;

	//colors[ImGuiCol_NavHighlight] = bgColor;
	//colors[ImGuiCol_Tab] = 37, 37, 38;
	//colors[ImGuiCol_TabActive] = panelActiveColor;
	//colors[ImGuiCol_TabUnfocused] = bgColor;
	//colors[ImGuiCol_TabUnfocusedActive] = panelActiveColor;
	//colors[ImGuiCol_TabHovered] = panelHoverColor;
	// 
		//colors[ImGuiCol_NavHighlight] = bgColor;
	//colors[ImGuiCol_Tab] = bgColor;
	//colors[ImGuiCol_TabActive] = panelActiveColor;
	//colors[ImGuiCol_TabUnfocused] = bgColor;
	//colors[ImGuiCol_TabUnfocusedActive] = panelActiveColor;
	//colors[ImGuiCol_TabHovered] = panelHoverColor;

		//colors[ImGuiCol_Button] = ImColor(37, 37, 37);
		//colors[ImGuiCol_ButtonHovered] = ImColor(30, 30, 30);
		//colors[ImGuiCol_ButtonActive] = ImColor(30, 30, 30);
		//if (index > 0)
		//ImGui::SameLine();

			//style.Colors[ImGuiCol_Text] = colortextHover;
/*
ImGuiStyle* dst;

void ColorAndStyle() {
	ImGuiStyle* style = dst ? dst : &ImGui::GetStyle();
	ImVec4* colors = style->Colors;

	ImVec4 bgColor = ImColor(37, 37, 38);
	ImVec4 bgAAAColor = ImColor(24, 24, 24);
	ImVec4 lightBgColor = ImColor(82, 82, 85);
	ImVec4 veryLightBgColor = ImColor(90, 90, 95);

	ImVec4 panelColor = ImColor(51, 51, 55);
	ImVec4 panelHoverColor = ImColor(19, 110, 173);
	ImVec4 panelActiveColor = ImColor(0, 134, 224);

	ImVec4 textColor = ImColor(255, 255, 255);
	ImVec4 textDisabledColor = ImColor(151, 151, 151);
	ImVec4 borderColor = ImColor(78, 78, 78);
	ImVec4 black = ImColor(0, 0, 0);

	colors[ImGuiCol_WindowBg] = bgAAAColor;
	colors[ImGuiCol_PopupBg] = bgColor;
	colors[ImGuiCol_Border] = borderColor;
	colors[ImGuiCol_BorderShadow] = borderColor;
	colors[ImGuiCol_FrameBg] = panelColor;
	colors[ImGuiCol_FrameBgHovered] = panelHoverColor;
	colors[ImGuiCol_FrameBgActive] = panelActiveColor;
	colors[ImGuiCol_TitleBg] = panelActiveColor;
	colors[ImGuiCol_TitleBgActive] = panelActiveColor;
	colors[ImGuiCol_TitleBgCollapsed] = panelActiveColor;
	colors[ImGuiCol_MenuBarBg] = panelColor;
	colors[ImGuiCol_ScrollbarBg] = panelColor;
	colors[ImGuiCol_ScrollbarGrab] = lightBgColor;
	colors[ImGuiCol_ScrollbarGrabHovered] = veryLightBgColor;
	colors[ImGuiCol_ScrollbarGrabActive] = veryLightBgColor;
	colors[ImGuiCol_CheckMark] = panelActiveColor;
	colors[ImGuiCol_SliderGrab] = panelHoverColor;
	colors[ImGuiCol_SliderGrabActive] = panelActiveColor;
	colors[ImGuiCol_Button] = panelHoverColor;
	colors[ImGuiCol_Separator] = panelActiveColor;
	colors[ImGuiCol_SeparatorHovered] = panelActiveColor;
	colors[ImGuiCol_SeparatorActive] = panelActiveColor;
	colors[ImGuiCol_ButtonHovered] = panelActiveColor;
	colors[ImGuiCol_ButtonActive] = panelHoverColor;
	colors[ImGuiCol_ResizeGrip] = panelColor;
	colors[ImGuiCol_ResizeGripHovered] = panelHoverColor;
	colors[ImGuiCol_ResizeGripActive] = panelActiveColor;
	colors[ImGuiCol_PlotLines] = panelActiveColor;
	colors[ImGuiCol_PlotLinesHovered] = panelHoverColor;
	colors[ImGuiCol_PlotHistogram] = panelActiveColor;
	colors[ImGuiCol_PlotHistogramHovered] = panelHoverColor;
	colors[ImGuiCol_DragDropTarget] = bgColor;
	colors[ImGuiCol_CloseButton] = ImColor(0, 0, 0, 0);
	colors[ImGuiCol_CloseButtonHovered] = ImColor(0, 0, 0, 0);
	colors[ImGuiCol_CloseButtonActive] = ImColor(0, 0, 0, 0);
}

/*
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	//if (msg == WM_QUIT && ShowMenu) {
	//ExitProcess(0);
	//}

	if (ShowMenu) {
		//ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam);
		return TRUE;
	}

	return CallWindowProc(oWndProc, hWnd, msg, wParam, lParam);
}
*/

//Overlay()->AddRectFilled(ImVec2(10080, 10920), ImVec2(Renderer_Defines_dayf76d6f7dsaf6::Width_sdf5tsdff5sdff565sd5fsd5f5sdf5 / 2 - 3000, Renderer_Defines_dayf76d6f7dsaf6::Height_sdxfxgsad76fsdytfgasdytdgasytdgasd / 2 - 800), ImGui::GetColorU32({ 0, 0, 0, 0.10f }), 0.1);

	//Overlay()->AddRectFilled(ImVec2(10080, 10920), ImVec2(Renderer_Defines_dayf76d6f7dsaf6::Width_sdf5tsdff5sdff565sd5fsd5f5sdf5 / 2 - 3000, Renderer_Defines_dayf76d6f7dsaf6::Height_sdxfxgsad76fsdytfgasdytdgasytdgasd / 2 - 800), ImGui::GetColorU32({ 0, 0, 0, 0.10f }), 0.1);



		//colors[ImGuiCol_FrameBg] = ImColor(0, 0, 0, 0);
		//colors[ImGuiCol_ChildBg] = ImColor(0, 0, 0, 0);
		//colors[ImGuiCol_ChildWindowBg] = ImColor(0, 0, 0, 0);
		//colors[ImGuiCol_Header] = ImColor(0, 0, 0, 0);
		//colors[ImGuiCol_TextSelectedBg] = ImColor(0, 0, 0, 0);

		//ColorAndStyle();

					//ImGui::Checkbox(xorstr_("No Spread V3 \"SAFE\" "), &Settings_as7d6as6d::NospreadV3_svdiousdfuihsdfhuidsfuyhsfdhuifhsudi);
					//ImGui::Checkbox(xorstr_("No Recoil \"SAFE\" "), &Settings_as7d6as6d::norecoil_ashdyiasdgasydgasyudgasyudgasydg);

					//ImGui::Checkbox(xorstr_("Instant Reload v2"), &Settings_as7d6as6d::instantreload_sahduyhiasdgbjyasdvasdg);

		/*
		if (ImGui::Begin(xorstr_("##########"), &ShowMenu_hasdbghuasdgbuyhasdguasdydgauysdgasuydg, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar))
		{
			colors[ImGuiCol_ChildBg] = ImColor(37, 37, 37);

			ImGui::SetCursorPos({ 4.f,5.f });

			if (ImGui::BeginChild(xorstr_("##"), { 155,475 }))
			{
				colors[ImGuiCol_Button] = ImColor(37, 37, 37);
				colors[ImGuiCol_ButtonHovered] = ImColor(30, 30, 30);
				colors[ImGuiCol_ButtonActive] = ImColor(30, 30, 30);

				style->WindowRounding = 0.f;
				style->FramePadding = ImVec2(4.5f, 2.5f);

				ImGui::SetCursorPos({ 0.f,0.f });
				colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
				ImGui::SetCursorPos({ 4.f,29.f });

				ImGui::SetCursorPos({ 0.f,0 });
				ImGui::Tab(0, xorstr_("AIMBOT                          "), &maintabs);
				ImGui::SetCursorPos({ 0.f,29 });
				ImGui::Tab(1, xorstr_("PLAYER VISUALS              "), &maintabs);
				ImGui::SetCursorPos({ 0.f,58 });
				ImGui::Tab(2, xorstr_("WORLD VISUALS              "), &maintabs);
				ImGui::SetCursorPos({ 0.f,87 });
				ImGui::Tab(4, xorstr_("MISC                               "), &maintabs);
				ImGui::SetCursorPos({ 0.f,116 });
				ImGui::Tab(5, xorstr_("PLAYER MODS                  "), &maintabs);
				ImGui::SetCursorPos({ 0.f,145 });
				ImGui::Tab(6, xorstr_("WEAPON MODS                "), &maintabs);
				ImGui::SetCursorPos({ 0.f,174 });
				ImGui::Tab(7, xorstr_("VEHICLE MODS                "), &maintabs);
				//ImGui::SetCursorPos({ 0.f,193 });
				//ImGui::Tab(4, xorstr_("EXPERIMENTAL               "), &maintabs);

				colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
				ImGui::SetCursorPos({ 0.f,460 });
				ImGui::Text(xorstr_(" GayGarden | FPS: %.7f"), ImGui::GetIO().Framerate);
			}
			ImGui::EndChild();

			ImGui::SetCursorPos({ 155,460 });
			ImGui::NextColumn();
			ImGui::VerticalSeparator();

			if (maintabs == 0) {
				colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
				ImGui::SetCursorPos({ 170.f,15 });
				ImGui::Text(xorstr_("Aimbot"));
				ImGui::SetCursorPos({ 170.f,45 });
				ImGui::Checkbox(xorstr_("Memory"), &Settings_as7d6as6d::Aim_asysdguaysdguaysdgauysdg);
				ImGui::SetCursorPos({ 170.f,65 });
				ImGui::Checkbox(xorstr_("Silent"), &Settings_as7d6as6d::SilentAim_ayusdgausydgyausdgauysdg);
				ImGui::SetCursorPos({ 170.f,85 });
				ImGui::Checkbox(xorstr_("Silent V2 \"Only Works In Vehicles / Turrets\" "), &Settings_as7d6as6d::Bullettp_usauuidhiusdahgsduifghf);
				//ImGui::Checkbox(xorstr_("Sticky Silent \"Turn Up Smoothing To Make It Less Sticky\" "), &Settings_as7d6as6d::StickySilent_ashnduashdaushdasudh);

				//ImGui::Combo(xorstr_("Aimbone"), &Menu_AimBoneInt, AimBone_TypeItems, sizeof(AimBone_TypeItems) / sizeof(*AimBone_TypeItems));
				ImGui::Text(xorstr_(" "));

				//colors[ImGuiCol_Text] = ImColor(19, 110, 173);
				ImGui::SetCursorPos({ 170.f,115 });
				ImGui::Text(xorstr_("Aimbot Bones:"));
				//colors[ImGuiCol_Text] = ImColor(255, 255, 255);

				ImGui::SameLine();

				colors[ImGuiCol_Button] = ImColor(19, 110, 173);
				colors[ImGuiCol_ButtonHovered] = ImColor(0, 134, 224);
				colors[ImGuiCol_ButtonActive] = ImColor(19, 110, 173);

				style->FramePadding = ImVec2(4.5f, 2.5f);

				if (ImGui::Button(xorstr_("66"), ImVec2(47, 17))) {
					Settings_as7d6as6d::aimbone_iyashgdiuyasgdyuasgds = 66;

					Settings_as7d6as6d::Neck_dsahfuiasghdfyusdagf == 0;
					Settings_as7d6as6d::Pelvis_sdjhfguhgsdfgyusdfgsyudfg == 0;
					Settings_as7d6as6d::Bottom_ajsdijasdoiasduoiasudioasud == 0;
				}

				ImGui::SameLine();

				if (ImGui::Button(xorstr_("65"), ImVec2(47, 17))) {
					Settings_as7d6as6d::aimbone_iyashgdiuyasgdyuasgds = 65;
					//ImGui::Text(xorstr_("Current Bone: Neck"));
					Settings_as7d6as6d::Pelvis_sdjhfguhgsdfgyusdfgsyudfg == 0;
					Settings_as7d6as6d::Head_asdihyghasuydgasyd == 0;
					Settings_as7d6as6d::Bottom_ajsdijasdoiasduoiasudioasud == 0;
				}

				ImGui::SameLine();

				if (ImGui::Button(xorstr_("2"), ImVec2(47, 17))) {
					Settings_as7d6as6d::aimbone_iyashgdiuyasgdyuasgds = 2;
					//ImGui::Text(xorstr_("Current Bone: Pelvis"));
					Settings_as7d6as6d::Neck_dsahfuiasghdfyusdagf == 0;
					Settings_as7d6as6d::Bottom_ajsdijasdoiasduoiasudioasud == 0;
					Settings_as7d6as6d::Head_asdihyghasuydgasyd == 0;
				}

				ImGui::SameLine();

				if (ImGui::Button(xorstr_("0"), ImVec2(47, 17))) {
					Settings_as7d6as6d::aimbone_iyashgdiuyasgdyuasgds = 0;
					//ImGui::Text(xorstr_("Current Bone: Bottom"));
					Settings_as7d6as6d::Neck_dsahfuiasghdfyusdagf == 0;
					Settings_as7d6as6d::Pelvis_sdjhfguhgsdfgyusdfgsyudfg == 0;
					Settings_as7d6as6d::Head_asdihyghasuydgasyd == 0;
				}

				colors[ImGuiCol_Button] = ImColor(19, 110, 173);
				colors[ImGuiCol_ButtonHovered] = ImColor(0, 134, 224);
				colors[ImGuiCol_ButtonActive] = ImColor(19, 110, 173);

				style->FramePadding = ImVec2(3.0f, 3.0f);

				if (Settings_as7d6as6d::aimbone_iyashgdiuyasgdyuasgds == 66) {
					ImGui::SetCursorPos({ 170.f,135 });
					ImGui::Text(xorstr_("Current Bone:"));
					ImGui::SameLine();
					colors[ImGuiCol_Text] = ImColor(NORBNOG);
					ImGui::Text(xorstr_("Head"));
					colors[ImGuiCol_Text] = ImColor(255, 255, 255);
				}
				if (Settings_as7d6as6d::aimbone_iyashgdiuyasgdyuasgds == 65) {
					ImGui::SetCursorPos({ 170.f,135 });
					ImGui::Text(xorstr_("Current Bone:"));
					ImGui::SameLine();
					colors[ImGuiCol_Text] = ImColor(NORBNOG);
					ImGui::Text(xorstr_("Neck"));
					colors[ImGuiCol_Text] = ImColor(255, 255, 255);
				}
				if (Settings_as7d6as6d::aimbone_iyashgdiuyasgdyuasgds == 2) {
					ImGui::SetCursorPos({ 170.f,135 });
					ImGui::Text(xorstr_("Current Bone:"));
					ImGui::SameLine();
					colors[ImGuiCol_Text] = ImColor(NORBNOG);
					ImGui::Text(xorstr_("Pelvis"));
					colors[ImGuiCol_Text] = ImColor(255, 255, 255);
				}
				if (Settings_as7d6as6d::aimbone_iyashgdiuyasgdyuasgds == 0) {
					ImGui::SetCursorPos({ 170.f,135 });
					ImGui::Text(xorstr_("Current Bone:"));
					ImGui::SameLine();
					colors[ImGuiCol_Text] = ImColor(NORBNOG);
					ImGui::Text(xorstr_("Bottom"));
					colors[ImGuiCol_Text] = ImColor(255, 255, 255);
				}

				colors[ImGuiCol_Button] = ImColor(19, 110, 173);
				colors[ImGuiCol_ButtonHovered] = ImColor(0, 134, 224);
				colors[ImGuiCol_ButtonActive] = ImColor(19, 110, 173);

				style->FramePadding = ImVec2(4.5f, 2.5f);

				ImGui::Text(xorstr_(" "));

				//colors[ImGuiCol_Text] = ImColor(19, 110, 173);
				ImGui::SetCursorPos({ 170.f,165 });
				ImGui::Text(xorstr_("Aimbot Keys:"));
				//colors[ImGuiCol_Text] = ImColor(255, 255, 255);

				ImGui::SameLine();

				if (ImGui::Button(xorstr_("VK_RBUTTON"), ImVec2(75, 17))) {
					Settings_as7d6as6d::aimkey_asuydguyasdguyasdyfgyu = VK_RBUTTON;
					Settings_as7d6as6d::aimkeyint_ygdasyudgaysudgyasdg = 1;
				}

				ImGui::SameLine();

				if (ImGui::Button(xorstr_("VK_LBUTTON"), ImVec2(75, 17))) {
					Settings_as7d6as6d::aimkey_asuydguyasdguyasdyfgyu = VK_LBUTTON;
					Settings_as7d6as6d::aimkeyint_ygdasyudgaysudgyasdg = 2;
				}

				ImGui::SameLine();

				if (ImGui::Button(xorstr_("VK_SHIFT"), ImVec2(64, 17))) {
					Settings_as7d6as6d::aimkey_asuydguyasdguyasdyfgyu = VK_SHIFT;
					Settings_as7d6as6d::aimkeyint_ygdasyudgaysudgyasdg = 3;
				}

				colors[ImGuiCol_Button] = ImColor(19, 110, 173);
				colors[ImGuiCol_ButtonHovered] = ImColor(0, 134, 224);
				colors[ImGuiCol_ButtonActive] = ImColor(19, 110, 173);

				style->FramePadding = ImVec2(3.0f, 3.0f);

				if (Settings_as7d6as6d::aimkeyint_ygdasyudgaysudgyasdg == 1) {
					ImGui::SetCursorPos({ 170.f,185 });
					ImGui::Text(xorstr_("Current Aimbot Key:"));
					ImGui::SameLine();
					colors[ImGuiCol_Text] = ImColor(NORBNOG);
					ImGui::Text(xorstr_("Right Mouse Button"));
					colors[ImGuiCol_Text] = ImColor(255, 255, 255);
				}
				if (Settings_as7d6as6d::aimkeyint_ygdasyudgaysudgyasdg == 2) {
					ImGui::SetCursorPos({ 170.f,185 });
					ImGui::Text(xorstr_("Current Aimbot Key:"));
					ImGui::SameLine();
					colors[ImGuiCol_Text] = ImColor(NORBNOG);
					ImGui::Text(xorstr_("Left Mouse Button"));
					colors[ImGuiCol_Text] = ImColor(255, 255, 255);
				}
				if (Settings_as7d6as6d::aimkeyint_ygdasyudgaysudgyasdg == 3) {
					ImGui::SetCursorPos({ 170.f,185 });
					ImGui::Text(xorstr_("Current Aimbot Key:"));
					ImGui::SameLine();
					colors[ImGuiCol_Text] = ImColor(NORBNOG);
					ImGui::Text(xorstr_("Shift"));
					colors[ImGuiCol_Text] = ImColor(255, 255, 255);
				}

				ImGui::PushItemWidth(230);

				ImGui::Text(xorstr_(" "));
				//style->GrabMinSize = 6.0f;
				ImGui::SetCursorPos({ 170.f,215 });
				ImGui::SliderInt(xorstr_("Aimbot Random X"), &Settings_as7d6as6d::random_x, -100, 100);
				ImGui::SetCursorPos({ 170.f,235 });
				ImGui::SliderInt(xorstr_("Aimbot Random Y"), &Settings_as7d6as6d::random_y, -100, 100);
				ImGui::SetCursorPos({ 170.f,255 });
				ImGui::SliderInt(xorstr_("Aimbot Random Z"), &Settings_as7d6as6d::random_z, -100, 100);
				ImGui::SetCursorPos({ 170.f,275 });
				ImGui::SliderInt(xorstr_("Aimbot Smoothing"), &Settings_as7d6as6d::smooth_yuasghsdyiuawsgdyasgduy, 1, 20);
				ImGui::SetCursorPos({ 170.f,295 });
				ImGui::SliderInt(xorstr_("Fov Circle Value"), &Settings_as7d6as6d::FovCircle_Value_uaigdyuiasgdyasgd, 30, 1500);
				ImGui::SetCursorPos({ 170.f,315 });
				ImGui::Checkbox(xorstr_("Aimbot LockLine \"Only Works With Silent And Silent V2\" "), &Settings_as7d6as6d::LockLine_ashdiuashduiashdiuashd);


				ImGui::SetCursorPos({ 170.f,385 });
			}
			if (maintabs == 1) {
				colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
				ImGui::SetCursorPos({ 170.f,15 });
				ImGui::Text(xorstr_("Player Visuals"));

				ImGui::SetCursorPos({ 170.f,45 });
				ImGui::Checkbox(xorstr_("2D Box"), &Settings_as7d6as6d::Box2D_dfjghdfgbgbgbgbgbedfhud);
				ImGui::SetCursorPos({ 170.f,65 });
				ImGui::Checkbox(xorstr_("3D Box"), &Settings_as7d6as6d::Box3D_9dasasujihdfdhg);
				ImGui::SetCursorPos({ 170.f,85 });
				ImGui::Checkbox(xorstr_("Corner Box"), &Settings_as7d6as6d::BoxCorner_ashdgbashuydgasd);
				ImGui::SetCursorPos({ 170.f,105 });
				ImGui::Checkbox(xorstr_("Skeleton High Res"), &Settings_as7d6as6d::Skeleton_yhasgvdyuasfgdtasfdtasfd);
				ImGui::SetCursorPos({ 170.f,125 });
				ImGui::Checkbox(xorstr_("Skeleton Low Res"), &Settings_as7d6as6d::Skeleton_Low_yhasgvdyuasfgdtasfdtasfd);
				ImGui::SetCursorPos({ 170.f,145 });
				ImGui::Checkbox(xorstr_("Distance"), &Settings_as7d6as6d::DistanceESP_aysgduyasgdytfyhfuiyhdf);
				ImGui::SetCursorPos({ 170.f,165 });
				ImGui::Checkbox(xorstr_("Bot/Ai"), &Settings_as7d6as6d::botai_hufdsghfuysdgfyuygyusdgfuysdg);
				ImGui::SetCursorPos({ 170.f,185 });
				ImGui::Checkbox(xorstr_("PlayerDying"), &Settings_as7d6as6d::playerdying_yusdgfuydfguiwryewetrdgfdhsfg);
				ImGui::SetCursorPos({ 170.f,205 });
				ImGui::Checkbox(xorstr_("PlayerNames"), &Settings_as7d6as6d::PlayerNames_asiudhasuydgasuydgasuydgadysugdsyugdsauyasgd);
				ImGui::SetCursorPos({ 170.f,225 });
				ImGui::Checkbox(xorstr_("Snaplines"), &Settings_as7d6as6d::SnapLines_badshhfgvadsufdfsdfufg);


				ImGui::SetCursorPos({ 170.f,255 });
				ImGui::Text(xorstr_("ESP Visable Distance"));
				ImGui::SetCursorPos({ 170.f,275 });
				ImGui::SliderInt(xorstr_("####vis"), &Settings_as7d6as6d::MaxESPDistance_hguadsgysdfggsdhfgsgdfsdf, 10, 500);
			}
			if (maintabs == 2) {
				ImGui::SetCursorPos({ 170.f,15 });
				ImGui::Text(xorstr_("World Visuals"));

				ImGui::SetCursorPos({ 170.f,45 });
				ImGui::Checkbox(xorstr_("Chest"), &Settings_as7d6as6d::ChestESP_sadhufgsuydfgsdyufgtsdyufgsdf);
				ImGui::SetCursorPos({ 170.f,65 });
				ImGui::Checkbox(xorstr_("AmmoBox"), &Settings_as7d6as6d::AmmoBoxESP_asydgausydt6asdtauysdtgausydtasyud);
				ImGui::SetCursorPos({ 170.f,85 });
				ImGui::Checkbox(xorstr_("Loot"), &Settings_as7d6as6d::LootESP_std67astd76as5dt6as5d6as5dasdasdas);
				ImGui::SetCursorPos({ 170.f,105 });
				ImGui::Checkbox(xorstr_("LLama"), &Settings_as7d6as6d::LLamaESP_uaseyd87atsydastdyuasdtaysdtgasd);
				ImGui::SetCursorPos({ 170.f,125 });
				ImGui::Checkbox(xorstr_("Vehicles"), &Settings_as7d6as6d::VehiclesESP_auydy78asydtyuasgdyuasdgghasgdasd);
				ImGui::SetCursorPos({ 170.f,145 });
				ImGui::Checkbox(xorstr_("WeakSpot"), &Settings_as7d6as6d::weakspot_sdyhfg6we5gsadyugwergsadg);
				ImGui::SetCursorPos({ 170.f,165 });
				ImGui::Checkbox(xorstr_("Campfire"), &Settings_as7d6as6d::campfire_uysdgauysdguyasdguyasdgyuasdgasd);
				ImGui::SetCursorPos({ 170.f,185 });
				ImGui::Checkbox(xorstr_("Placeables"), &Settings_as7d6as6d::placeables_asiuyhdghasuyidgasuydgasduygasduyasgdas);

				ImGui::SetCursorPos({ 170.f,215 });
				ImGui::Text(xorstr_("ESP Visable Distance"));
				ImGui::SetCursorPos({ 170.f,235 });
				ImGui::SliderInt(xorstr_("####vis"), &Settings_as7d6as6d::MaxESPDistance_hguadsgysdfggsdhfgsgdfsdf, 10, 500);
			}
			if (maintabs == 4) {
				colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
				ImGui::SetCursorPos({ 170.f,15 });
				ImGui::Text(xorstr_("Misc"));

				ImGui::SetCursorPos({ 170.f,45 });
				ImGui::Checkbox(xorstr_("Show Fov Circle"), &Settings_as7d6as6d::ShowFovCircle_87gf6sdf567s5f6sd5fdsf);
				ImGui::SetCursorPos({ 170.f,65 });
				ImGui::Checkbox(xorstr_("Crosshair"), &Settings_as7d6as6d::crosshair_sdfsdfsdfsdfsdfsdf);
				ImGui::SetCursorPos({ 170.f,85 });
				ImGui::Checkbox(xorstr_("UD Crosshair"), &Settings_as7d6as6d::UDcrosshair_asdhasudhasuydhasyud);
				ImGui::SetCursorPos({ 170.f,105 });
				ImGui::Checkbox(xorstr_("Visible Check"), &Settings_as7d6as6d::VisibleCheck_dsf7fg676dfg6dgf67hdg67h56dfgh);

				ImGui::SetCursorPos({ 170.f,135 });
				ImGui::Text(xorstr_("Menu Cursors"));

				ImGui::SetCursorPos({ 170.f,165 });
				ImGui::Checkbox(xorstr_("Rainbow Menu Cursor"), &Settings_as7d6as6d::RainbowMenuCursor_dfg66d7fg5df75g5dfg5dfg);
				ImGui::SetCursorPos({ 170.f,185 });
				ImGui::Checkbox(xorstr_("Normal Menu Cursor (defualt)"), &Settings_as7d6as6d::NormalMenuCursor_ds7f667sdffg5sdfgf566dfg5);

				ImGui::SetCursorPos({ 170.f,215 });
				ImGui::Text(xorstr_("Visuals MISC"));

				ImGui::SetCursorPos({ 170.f,245 });
				ImGui::Checkbox(xorstr_("Rainbow ESP Mode"), &Settings_as7d6as6d::Gaybow_syuadgtasdfgtausdftsaddfg);
				ImGui::SetCursorPos({ 170.f,265 });
				ImGui::Checkbox(xorstr_("LSD Mode"), &Settings_as7d6as6d::LSDmodeLOL_ausysgdsyuadghyuasdgyuasdguaysdgyuasdg);
			}
			/*
			ImGui::Tab(4, xorstr_("MISC                               "), &maintabs);
			ImGui::SetCursorPos({ 0.f,116 });
			ImGui::Tab(5, xorstr_("PLAYER EXPLOITS          "), &maintabs);
			ImGui::SetCursorPos({ 0.f,116 });
			ImGui::Tab(6, xorstr_("WEAPON EXPLOITS          "), &maintabs);
			ImGui::SetCursorPos({ 0.f,116 });
			ImGui::Tab(7, xorstr_("VEHICLE EXPLOITS           "), &maintabs);
			//ImGui::SetCursorPos({ 0.f,193 });
			if (maintabs == 5) {
				colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
				ImGui::SetCursorPos({ 170.f,15 });
				ImGui::Text(xorstr_("Player Exploits"));

				ImGui::SetCursorPos({ 170.f,45 });
				ImGui::Checkbox(xorstr_("Instant Revive"), &Settings_as7d6as6d::InstantRevive_ayussgd7adft76sdf5s6df56sdf);
				ImGui::SetCursorPos({ 170.f,65 });
				ImGui::Checkbox(xorstr_("Client AirStuck"), &Settings_as7d6as6d::AirStuck_asdgfuydfgyusdaafgyusdfgsdyuf);
				ImGui::SetCursorPos({ 170.f,85 });
				ImGui::Checkbox(xorstr_("Server AirStuck"), &Settings_as7d6as6d::ServerAirStuck_asuyhdhgasuydgausydgasuydgasuydg);
				ImGui::SetCursorPos({ 170.f,105 });
				ImGui::Checkbox(xorstr_("Instant Actions"), &Settings_as7d6as6d::FastActions_sahdgbhasdghausydgauytdgasydgasd);

				colors[ImGuiCol_Button] = ImColor(19, 110, 173);
				colors[ImGuiCol_ButtonHovered] = ImColor(0, 134, 224);
				colors[ImGuiCol_ButtonActive] = ImColor(19, 110, 173);

				style->FramePadding = ImVec2(4.5f, 2.5f);

				ImGui::SetCursorPos({ 170.f,125 });
				if (ImGui::Button(xorstr_("ClientSidedDBNO ON"), ImVec2(108, 17))) {
					Settings_as7d6as6d::fakedownON_asuyidhyausydgasuydgausydgasd = true;
				}
				ImGui::SetCursorPos({ 170.f,145 });
				if (ImGui::Button(xorstr_("ClientSidedDBNO OFF"), ImVec2(110, 17))) {
					Settings_as7d6as6d::fakedownOFF_duhasguytasgdyaysdgyuasdgyuazsdg = true;
				}
				ImGui::SetCursorPos({ 170.f,165 });
				if (ImGui::Button(xorstr_("FirstPerson"), ImVec2(64, 17))) {
					Settings_as7d6as6d::FirstCamera_usadhfuysdagfgtswdgfysdfgsdf = true;
				}

				ImGui::SetCursorPos({ 170.f,185 });
				ImGui::Checkbox(xorstr_("FOV Changer"), &Settings_as7d6as6d::Fovchanger_asdbasyudgasuydgasydugasdyuasgd);
				ImGui::SetCursorPos({ 170.f,205 });
				ImGui::SliderFloat(xorstr_("Rapid Changer Value##slider"), &Settings_as7d6as6d::fov_change_value_sahdbasuydgasuydgasyudgasuydgasuyd, 80, 360, xorstr_("%.3f"));



				colors[ImGuiCol_Button] = ImColor(19, 110, 173);
				colors[ImGuiCol_ButtonHovered] = ImColor(0, 134, 224);
				colors[ImGuiCol_ButtonActive] = ImColor(19, 110, 173);

				style->FramePadding = ImVec2(3.0f, 3.0f);
			}
		}
		if (maintabs == 6) {
			ImGui::SetCursorPos({ 170.f,15 });
			ImGui::Text(xorstr_("Weapon Exploits"));

			ImGui::SetCursorPos({ 170.f,45 });
			ImGui::Checkbox(xorstr_("No Spread \"RISK\" "), &Settings_as7d6as6d::NoSpread_sd89f7sd67ft6sdf5s6df5);
			ImGui::SetCursorPos({ 170.f,65 });
			ImGui::Checkbox(xorstr_("No Spread V2 \"Only Works With AR's And Bursts\" "), &Settings_as7d6as6d::NospreadV2_suhdfiusdahasuidhasuidhausidh);
			ImGui::SetCursorPos({ 170.f,85 });
			ImGui::Checkbox(xorstr_("Spinbot \"Good With Silent\""), &Settings_as7d6as6d::Spinbot_ahsdhbayiusdgasydgasydgasydgasd);
			ImGui::SetCursorPos({ 170.f,105 });
			ImGui::Checkbox(xorstr_("Instant Reload"), &Settings_as7d6as6d::FastReload_ashdhgauysdgasydgasuytdgasuydgasuydg);
			ImGui::SetCursorPos({ 170.f,125 });
			ImGui::Checkbox(xorstr_("Instant Weapon Swap"), &Settings_as7d6as6d::Anim_a7s6ydas5da5d6as7d567f5sd67f5sdf6);
			ImGui::SetCursorPos({ 170.f,145 });
			ImGui::Checkbox(xorstr_("Aim While Jumping"), &Settings_as7d6as6d::AimWhileJumping_yatsdfysdtftsdtrftsdftusdftusdf);
			ImGui::SetCursorPos({ 170.f,165 });
			ImGui::Checkbox(xorstr_("360Fov \"Good With Silent\" "), &Settings_as7d6as6d::fov360_ghasdgdfytsdafggshdfgsdgf);
			ImGui::SetCursorPos({ 170.f,185 });
			ImGui::Checkbox(xorstr_("Aimbot Prediction \"Good To Use With Snipers\" "), &Settings_as7d6as6d::AimPrediction_ashdiuashduiashdiuashd);
			ImGui::SetCursorPos({ 170.f,205 });
			ImGui::Checkbox(xorstr_("Rapid Fire"), &Settings_as7d6as6d::RapidFire_ahsdgfdsfgsdfgsdfgsdyfgsdf);
			ImGui::SetCursorPos({ 170.f,225 });
			ImGui::SliderFloat(xorstr_("Rapid Fire Value##slider"), &Settings_as7d6as6d::RapidFireValue_hauysdgvuysdfguysdfguysdfg, 0.001, 0.500, xorstr_("%.3f"));
			/*ImGui::SetCursorPos({170.f,245});
			ImGui::Checkbox(xorstr_("Projectile TP \"Expermential\" "), &Settings_as7d6as6d::ProjectileTP_ashbdausdgbuasydgasyudgasduygasduygasyudgasyudg);
			ImGui::SetCursorPos({ 170.f,265 });
			ImGui::Checkbox(xorstr_("Teleport Downed Teammates To You \"Expermential\" "), &Settings_as7d6as6d::TeleportDownedToLocalPawn_asudygasuydgasydugasduygasyudgasd);
			ImGui::SetCursorPos({ 170.f,285 });
			ImGui::Checkbox(xorstr_("Invisable ON \"Expermential\" "), &Settings_as7d6as6d::Invis_ON_asdhudghauyshdsdhauyhsdgayusdg);
			ImGui::SetCursorPos({ 170.f,245 });
			ImGui::Checkbox(xorstr_("test1"), &Settings_as7d6as6d::test1);
			ImGui::SetCursorPos({ 170.f,265 });
			ImGui::Checkbox(xorstr_("test2"), &Settings_as7d6as6d::test2);
			ImGui::SetCursorPos({ 170.f,285 });
			ImGui::Checkbox(xorstr_("test3"), &Settings_as7d6as6d::test3);
		}
		if (maintabs == 7) {
			ImGui::SetCursorPos({ 170.f,15 });
			ImGui::Text(xorstr_("Vehicle Exploits"));

			ImGui::SetCursorPos({ 170.f,45 });
			//ImGui::Checkbox(xorstr_("Vehicle Fly [WASD / SPACE]##checkbox"), &Settings_as7d6as6d::playerflyez_yashdguyasdgauysdgasudgasuydgasyud);
			//ImGui::SetCursorPos({ 170.f,65 });
			ImGui::Checkbox(xorstr_("Vehicle Speed [SHIFT]##checkbox"), &Settings_as7d6as6d::Speed_asugdgausytdgauysdgausydgyuasdgaswd);
			ImGui::SetCursorPos({ 170.f,65 });
			if (Settings_as7d6as6d::Speed_asugdgausytdgauysdgausydgyuasdgaswd) {
				ImGui::SliderFloat(xorstr_("Vehicle Speed Value##slider"), &Settings_as7d6as6d::SpeedValue_hyasgduyasgduasgdyasgdyuasgduyasdg, 1.001, 100.0);
			}
			//
		}
		ImGui::End();*/

		/*
		if (!ProjectileTPInitialized_ashbdausdgbuasydgasyudgasduygasduygasyudgasyudg) {
			if (BulletTP) {
				auto ProcessEventAddr = MemoryHelper::PatternScan(xorstr_("40 55 56 57 41 54 41 55 41 56 41 57 48 81 EC ? ? ? ? 48 8D 6C 24 ? 48 89 9D ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C5 48 89 85 ? ? ? ? 8B 41 0C 45 33 F6 3B 05 ? ? ? ? 4D 8B F8 48 8B F2 4C 8B E1 41 B8 ? ? ? ? 7D 2A"));
				HookHelper::InsertHook(ProcessEventAddr, (uintptr_t)ProcessEventHook, (uintptr_t)&ProcessEvent);
				ProjectileTPInitialized_ashbdausdgbuasydgasyudgasduygasduygasyudgasyudg = true;
			}
		}*/

		//AllocConsole();
		//freopen("CONIN$", "r", stdin);
		//freopen("CONOUT$", "w", stderr);
		//freopen("CONOUT$", "w", stdout);

		//sd.OutputWindow = LI_FN(FindWindowA).safe()(xorstr_("UnrealWindow"), xorstr_("Fortnite  "));


	// Call this here or somewhere else!

				//if (!fnWorldToScreen) {
				//	fnWorldToScreen = reinterpret_cast<WorldToScreen_t>(ProjectWorldToScreen);
				//}

			//std::cout << "TheOmegaLul: " << RootComponent << "\n";
			//MessageBoxA(NULL, "Before RelativeLocation", "", MB_OK);
			//if (!RootComponent) return false;

				//MessageBoxA(NULL, "Before THE OMEGALUL IF", "", MB_OK);


			//SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, Settings_as7d6as6d::aimbone_iyashgdiuyasgdyuasgds, &rootHead);
			//SDK::Classes::AController::WorldToScreen(Vector3(rootHead.x, rootHead.y, rootHead.z + 20), &Headbox);

/*
void Theme()
{
	ImGuiStyle* style = &ImGui::GetStyle();

	style->WindowBorderSize = 0;
	style->ChildRounding = 3;
	style->WindowRounding = 0;

	style->WindowTitleAlign = ImVec2(0.5, 0.5);
	//style->WindowMinSize = ImVec2(680, 300);
	style->FramePadding = ImVec2(8.0, 6.0);
	style->FrameRounding = 3;

	style->Colors[ImGuiCol_CheckMark] = ImColor(52, 155, 235, 255);

	style->Colors[ImGuiCol_SliderGrab] = ImColor(255, 255, 255, 255);
	style->Colors[ImGuiCol_SliderGrabActive] = ImColor(255, 255, 255, 255);
	style->Colors[ImGuiCol_WindowBg] = ImColor(30, 37, 47, 255);

	style->Colors[ImGuiCol_TitleBg] = ImColor(255, 101, 53, 255);
	style->Colors[ImGuiCol_TitleBgActive] = ImColor(255, 101, 53, 255);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImColor(0, 0, 0, 130);

	style->Colors[ImGuiCol_Button] = ImColor(54, 63, 75);
	style->Colors[ImGuiCol_ButtonActive] = ImColor(54, 63, 75);
	style->Colors[ImGuiCol_ButtonHovered] = ImColor(54, 63, 75);

	style->Colors[ImGuiCol_Separator] = ImColor(70, 70, 70, 255);
	style->Colors[ImGuiCol_SeparatorActive] = ImColor(76, 76, 76, 255);
	style->Colors[ImGuiCol_SeparatorHovered] = ImColor(76, 76, 76, 255);

	style->Colors[ImGuiCol_ChildBg] = ImColor(40, 47, 58, 255);

	style->Colors[ImGuiCol_FrameBg] = ImColor(55, 63, 74, 255);
	style->Colors[ImGuiCol_FrameBgActive] = ImColor(55, 63, 74, 255);
	style->Colors[ImGuiCol_FrameBgHovered] = ImColor(55, 63, 74, 255);

	style->Colors[ImGuiCol_Header] = ImColor(0, 0, 0, 0);
	style->Colors[ImGuiCol_HeaderActive] = ImColor(0, 0, 0, 0);
	style->Colors[ImGuiCol_HeaderHovered] = ImColor(46, 46, 46, 255);
}

ImGui::Text(xorstr_("REVO.CC - PRIVATE"), ImGui::GetIO().Framerate);
ImGui::Spacing();

{

	ImGui::BeginChild(xorstr_("##LeftMainSide"), ImVec2(150, 250), true);
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));
	{
		ImGui::Spacing();
		if (ImGui::Button(xorstr_("Aimbot"), ImVec2(imguipp::getx(), 50))) { maintabs = 0; }
		ImGui::Spacing();
		if (ImGui::Button(xorstr_("ESP"), ImVec2(imguipp::getx(), 50))) { maintabs = 1; }
		ImGui::Spacing();
		if (ImGui::Button(xorstr_("Misc"), ImVec2(imguipp::getx(), 50))) { maintabs = 2; }
		ImGui::Spacing();
		if (ImGui::Button(xorstr_("Exploits"), ImVec2(imguipp::getx(), 50))) { maintabs = 3; }

	}
	ImGui::PopStyleVar();
	ImGui::EndChild();
}

ImGui::SameLine(0, 15);

{
	ImGui::BeginChild(xorstr_("##RightMainSide"), ImVec2(500, 250), true);
	{
		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));

		if (maintabs == 0)
		{
			ImGui::Columns(2);
			ImGui::Checkbox(xorstr_("Memory"), &Settings_as7d6as6d::Aim_asysdguaysdguaysdgauysdg);
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::Text(xorstr_("Locks On To Any Enemys In FOV"));
				ImGui::EndTooltip();
			}
			ImGui::Checkbox(xorstr_("Silent"), &Settings_as7d6as6d::SilentAim_ayusdgausydgyausdgauysdg);
			ImGui::SameLine();
			ImGui::TextColored(ImColor(255, 0, 0, 255), xorstr_("[ info ]"));
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::Text(xorstr_("Makes Your Bullets Goto The Nearest Players In FOV"));
				ImGui::EndTooltip();
			}
			ImGui::Checkbox(xorstr_("Projectile TP"), &Settings_as7d6as6d::Bullettp_usauuidhiusdahgsduifghf);
			ImGui::SameLine();
			ImGui::TextColored(ImColor(255, 0, 0, 255), xorstr_("[ info ]"));
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::Text(xorstr_("It Teleports Your Guns Bullet To The Nearest Players | Only Works In Cars And Turrets"));
				ImGui::EndTooltip();
			}
			ImGui::Text(xorstr_(" "));
			ImGui::PushItemWidth(190);
			ImGui::Text(xorstr_("Aimbot Smoothness"));
			ImGui::SliderInt(xorstr_("##smooth"), &Settings_as7d6as6d::smooth_yuasghsdyiuawsgdyasgduy, 1, 30);
			ImGui::Text(xorstr_("FOV Circle Value"));
			ImGui::SliderInt(xorstr_("##fov"), &Settings_as7d6as6d::FovCircle_Value_uaigdyuiasgdyasgd, 30, 1500);
			ImGui::Text(xorstr_(" "));

			ImGui::NextColumn();
			ImGui::Text(xorstr_("Aimbot Random X"));
			ImGui::SliderInt(xorstr_("##Aimbot Random X"), &Settings_as7d6as6d::random_x, -100, 100);
			ImGui::Text(xorstr_("Aimbot Random Y"));
			ImGui::SliderInt(xorstr_("##Aimbot Random Y"), &Settings_as7d6as6d::random_y, -100, 100);
			ImGui::Text(xorstr_("Aimbot Random Z"));
			ImGui::SliderInt(xorstr_("##Aimbot Random Z"), &Settings_as7d6as6d::random_z, -100, 100);
			ImGui::Checkbox(xorstr_("Aimbot LockLine"), &Settings_as7d6as6d::LockLine_ashdiuashduiashdiuashd);
			ImGui::Spacing();
			ImGui::Text(xorstr_("Aimbot Keys:"));

			ImGui::SameLine();

			style->FramePadding = ImVec2(4.5f, 2.5f);

			if (ImGui::Button(xorstr_("VK_RBUTTON"), ImVec2(75, 17))) {
				Settings_as7d6as6d::aimkey_asuydguyasdguyasdyfgyu = VK_RBUTTON;
				Settings_as7d6as6d::aimkeyint_ygdasyudgaysudgyasdg = 1;
			}

			ImGui::SameLine();

			if (ImGui::Button(xorstr_("VK_LBUTTON"), ImVec2(75, 17))) {
				Settings_as7d6as6d::aimkey_asuydguyasdguyasdyfgyu = VK_LBUTTON;
				Settings_as7d6as6d::aimkeyint_ygdasyudgaysudgyasdg = 2;
			}

			colors[ImGuiCol_Button] = ImColor(19, 110, 173);
			colors[ImGuiCol_ButtonHovered] = ImColor(0, 134, 224);
			colors[ImGuiCol_ButtonActive] = ImColor(19, 110, 173);

			style->FramePadding = ImVec2(3.0f, 3.0f);

			if (Settings_as7d6as6d::aimkeyint_ygdasyudgaysudgyasdg == 1) {
				ImGui::Text(xorstr_("Current Aimbot Key:"));
				ImGui::SameLine();
				colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
				ImGui::Text(xorstr_("Right Mouse Button"));
				colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			}
			if (Settings_as7d6as6d::aimkeyint_ygdasyudgaysudgyasdg == 2) {
				ImGui::Text(xorstr_("Current Aimbot Key:"));
				ImGui::SameLine();
				colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
				ImGui::Text(xorstr_("Left Mouse Button"));
				colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			}
		}

		if (maintabs == 1)
		{
			ImGui::Columns(2);

			ImGui::Text(xorstr_("Player Visuals"));
			ImGui::Checkbox(xorstr_("2D Box"), &Settings_as7d6as6d::Box2D_dfjghdfgbgbgbgbgbedfhud);
			ImGui::Checkbox(xorstr_("3D Box"), &Settings_as7d6as6d::Box3D_9dasasujihdfdhg);
			ImGui::Checkbox(xorstr_("Corner Box"), &Settings_as7d6as6d::BoxCorner_ashdgbashuydgasd);
			ImGui::Checkbox(xorstr_("Skeleton High Res"), &Settings_as7d6as6d::Skeleton_yhasgvdyuasfgdtasfdtasfd);
			ImGui::Checkbox(xorstr_("Skeleton Low Res"), &Settings_as7d6as6d::Skeleton_Low_yhasgvdyuasfgdtasfdtasfd);
			ImGui::Checkbox(xorstr_("Distance"), &Settings_as7d6as6d::DistanceESP_aysgduyasgdytfyhfuiyhdf);
			ImGui::Checkbox(xorstr_("Bot/Ai"), &Settings_as7d6as6d::botai_hufdsghfuysdgfyuygyusdgfuysdg);
			ImGui::Checkbox(xorstr_("PlayerDying"), &Settings_as7d6as6d::playerdying_yusdgfuydfguiwryewetrdgfdhsfg);
			ImGui::Checkbox(xorstr_("Line ESP"), &Settings_as7d6as6d::SnapLines_badshhfgvadsufdfsdfufg);

			ImGui::NextColumn();

			ImGui::Text(xorstr_("World Visuals"));
			ImGui::Checkbox(xorstr_("Vehicles"), &Settings_as7d6as6d::VehiclesESP_auydy78asydtyuasgdyuasdgghasgdasd);
			ImGui::Checkbox(xorstr_("Animals"), &Settings_as7d6as6d::animalsESP_edf87gdfsgdfg6dfghfgdh67gfdh7fdg6hfgh);
			ImGui::Checkbox(xorstr_("IO Guards"), &Settings_as7d6as6d::ioguardESP_dsuidsfydf7gdf6gfdgfgdhfgdhfghfghfg5h7);
			ImGui::Checkbox(xorstr_("Vending Machines"), &Settings_as7d6as6d::vendingmachineESP_assdasdtyf87d67sfg67dfg6dfs78g);
			ImGui::Checkbox(xorstr_("Burried Treasures"), &Settings_as7d6as6d::burriedtreasureESP_dsa76sgfd7dfgdfgdfgdgf67df6g);
			ImGui::Checkbox(xorstr_("Traders"), &Settings_as7d6as6d::tradersESP_hsdufhgsdfsfd6f6sd7fs6d76g79fsg7f6);
			ImGui::Checkbox(xorstr_("Zombies"), &Settings_as7d6as6d::ZombiesESP_ds7f6sd7f6sdf786sdf78s6df7sd6f7sdrfsdf);
			ImGui::Checkbox(xorstr_("Fireflys"), &Settings_as7d6as6d::FireflysESP_dffsdg6sdf7g6dfs7g6fds76gfdg);
			ImGui::Checkbox(xorstr_("Turrets"), &Settings_as7d6as6d::placeables_asiuyhdghasuyidgasuydgasduygasduyasgdas);
		}

		if (maintabs == 2)
		{
			ImGui::Columns(2);
			ImGui::Text(xorstr_("Misc"));
			ImGui::Checkbox(xorstr_("Show Fov Circle"), &Settings_as7d6as6d::ShowFovCircle_87gf6sdf567s5f6sd5fdsf);
			ImGui::Checkbox(xorstr_("Crosshair"), &Settings_as7d6as6d::crosshair_sdfsdfsdfsdfsdfsdf);
			ImGui::Checkbox(xorstr_("UD Crosshair"), &Settings_as7d6as6d::UDcrosshair_asdhasudhasuydhasyud);
			ImGui::Checkbox(xorstr_("Visible Check"), &Settings_as7d6as6d::VisibleCheck_dsf7fg676dfg6dgf67hdg67h56dfgh);
			ImGui::Checkbox(xorstr_("Object Debug"), &Settings_as7d6as6d::objectdebug_asuydgasdyugasyugyuasdgyusadgyusdaygusadygusadgyu);
			ImGui::NextColumn();
			ImGui::Text(xorstr_("Menu Cursors"));
			ImGui::Checkbox(xorstr_("Rainbow Menu Cursor"), &Settings_as7d6as6d::RainbowMenuCursor_dfg66d7fg5df75g5dfg5dfg);
			ImGui::Checkbox(xorstr_("Normal Menu Cursor (defualt)"), &Settings_as7d6as6d::NormalMenuCursor_ds7f667sdffg5sdfgf566dfg5);
			ImGui::Text(xorstr_("Visuals MISC"));
			ImGui::Checkbox(xorstr_("Rainbow ESP Mode"), &Settings_as7d6as6d::Gaybow_syuadgtasdfgtausdftsaddfg);
			ImGui::Checkbox(xorstr_("LSD Mode"), &Settings_as7d6as6d::LSDmodeLOL_ausysgdsyuadghyuasdgyuasdguaysdgyuasdg);
		}

		if (maintabs == 3) {
			ImGui::Columns(2);
			ImGui::Checkbox(xorstr_("No Spread"), &Settings_as7d6as6d::NoSpread_sd89f7sd67ft6sdf5s6df5);
			ImGui::SameLine();
			ImGui::TextColored(ImColor(255, 0, 0, 255), xorstr_("[ info ]"));
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::Text(xorstr_("Makes Your Spread Of Your Gun 0 | \"RISK\""));
				ImGui::EndTooltip();
			}
			ImGui::Checkbox(xorstr_("No Spread V2"), &Settings_as7d6as6d::NospreadV2_suhdfiusdahasuidhasuidhausidh);
			ImGui::SameLine();
			ImGui::TextColored(ImColor(255, 0, 0, 255), xorstr_("[ info ]"));
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::Text(xorstr_("Makes Your Spread Of Your Gun 0 | \"AR's / Bursts\""));
				ImGui::EndTooltip();
			}
			ImGui::Checkbox(xorstr_("Spinbot"), &Settings_as7d6as6d::Spinbot_ahsdhbayiusdgasydgasydgasydgasd);
			ImGui::SameLine();
			ImGui::TextColored(ImColor(255, 0, 0, 255), xorstr_("[ info ]"));
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::Text(xorstr_("Good With Silent"));
				ImGui::EndTooltip();
			}
			ImGui::Checkbox(xorstr_("Rapid Fire"), &Settings_as7d6as6d::RapidFire_ahsdgfdsfgsdfgsdfgsdyfgsdf);
			if (Settings_as7d6as6d::RapidFire_ahsdgfdsfgsdfgsdfgsdyfgsdf) {
				ImGui::Text(xorstr_("Rapid Fire Value"));
				ImGui::SliderFloat(xorstr_("##Rapid Fire Value"), &Settings_as7d6as6d::RapidFireValue_hauysdgvuysdfguysdfguysdfg, 0.001, 0.500, xorstr_("%.3f"));
			}
			ImGui::Checkbox(xorstr_("Instant Reload"), &Settings_as7d6as6d::FastReload_ashdhgauysdgasydgasuytdgasuydgasuydg);
			ImGui::Checkbox(xorstr_("Instant Weapon Swap"), &Settings_as7d6as6d::Anim_a7s6ydas5da5d6as7d567f5sd67f5sdf6);
			ImGui::Checkbox(xorstr_("Aim While Jumping"), &Settings_as7d6as6d::AimWhileJumping_yatsdfysdtftsdtrftsdftusdftusdf);
			ImGui::Checkbox(xorstr_("360Fov"), &Settings_as7d6as6d::fov360_ghasdgdfytsdafggshdfgsdgf);
			ImGui::SameLine();
			ImGui::TextColored(ImColor(255, 0, 0, 255), xorstr_("[ info ]"));
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::Text(xorstr_("Good With Silent"));
				ImGui::EndTooltip();
			}
			ImGui::Checkbox(xorstr_("Aimbot Prediction"), &Settings_as7d6as6d::AimPrediction_ashdiuashduiashdiuashd);
			ImGui::NextColumn();
			ImGui::Checkbox(xorstr_("Vehicle Speed ##checkbox"), &Settings_as7d6as6d::Speed_asugdgausytdgauysdgausydgyuasdgaswd);
			if (Settings_as7d6as6d::Speed_asugdgausytdgauysdgausydgyuasdgaswd) {
				ImGui::Text(xorstr_("Vehicle Speed Value"));
				ImGui::SliderFloat(xorstr_("##Vehicle Speed Value"), &Settings_as7d6as6d::SpeedValue_hyasgduyasgduasgdyasgdyuasgduyasdg, 1.001, 100.0);
			}

			ImGui::SameLine();
			ImGui::TextColored(ImColor(255, 0, 0, 255), xorstr_("[ info ]"));
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::Text(xorstr_("Key: Shift"));
				ImGui::EndTooltip();
			}

			ImGui::Checkbox(xorstr_("Instant Revive"), &Settings_as7d6as6d::InstantRevive_ayussgd7adft76sdf5s6df56sdf);
			ImGui::Checkbox(xorstr_("Instant Actions"), &Settings_as7d6as6d::FastActions_sahdgbhasdghausydgauytdgasydgasd);
			ImGui::Checkbox(xorstr_("Client AirStuck"), &Settings_as7d6as6d::AirStuck_asdgfuydfgyusdaafgyusdfgsdyuf);
			ImGui::Checkbox(xorstr_("Server AirStuck"), &Settings_as7d6as6d::ServerAirStuck_asuyhdhgasuydgausydgasuydgasuydg);
			if (ImGui::Button(xorstr_("ClientSidedDBNO ON"), ImVec2(150, 25))) {
				Settings_as7d6as6d::fakedownON_asuyidhyausydgasuydgausydgasd = true;
			}
			if (ImGui::Button(xorstr_("ClientSidedDBNO OFF"), ImVec2(150, 25))) {
				Settings_as7d6as6d::fakedownOFF_duhasguytasgdyaysdgyuasdgyuazsdg = true;
			}
			if (ImGui::Button(xorstr_("FirstPerson"), ImVec2(150, 25))) {
				Settings_as7d6as6d::FirstCamera_usadhfuysdagfgtswdgfysdfgsdf = true;
			}
		}

		ImGui::PopStyleVar();
	}
	ImGui::EndChild();

	namespace ImGui
	{
		IMGUI_API bool Tab(unsigned int index, const char* label, int* selected, float width = 155, float height = 29)
		{
			ImGuiStyle& style = ImGui::GetStyle();
			ImColor color = ImColor(37, 37, 37, 255)/*style.Colors[ImGuiCol_Button]*/;
			/*
			ImColor colortext = ImColor(255, 255, 255, 255)/*style.Colors[ImGuiCol_Text]*/;
			/*
			ImColor colortextActive = ImColor(0, 255, 255)/*style.Colors[ImGuiCol_Text]*/;
			/*
			ImColor colortextHover = ImColor(0, 255, 255)/*style.Colors[ImGuiCol_Text]*/;
			/*
			ImColor colorActive = ImColor(30, 30, 30, 255); /*style.Colors[ImGuiCol_ButtonActive]*/;
			/*
			ImColor colorHover = ImColor(30, 30, 30, 255)/*style.Colors[ImGuiCol_ButtonHovered]*/;
			/*
			if (index == *selected)
			{
				style.Colors[ImGuiCol_Text] = colortextActive;

				style.Colors[ImGuiCol_Button] = colorActive;
				style.Colors[ImGuiCol_ButtonActive] = colorActive;
				style.Colors[ImGuiCol_ButtonHovered] = colorActive;
			}
			else
			{
				style.Colors[ImGuiCol_Text] = colortext;

				style.Colors[ImGuiCol_Button] = color;
				style.Colors[ImGuiCol_ButtonActive] = colorActive;
				style.Colors[ImGuiCol_ButtonHovered] = colorHover;
			}

			if (ImGui::Button(label, ImVec2(width, height)))
				*selected = index;

			style.Colors[ImGuiCol_Text] = colortext;

			style.Colors[ImGuiCol_Button] = color;
			style.Colors[ImGuiCol_ButtonActive] = colorActive;
			style.Colors[ImGuiCol_ButtonHovered] = colorHover;

			return *selected == index;
		}

		IMGUI_API bool TabA(unsigned int index, const char* label, int* selected, float width = 46, float height = 17)
		{
			ImGuiStyle& style = ImGui::GetStyle();
			ImColor color = ImColor(27, 26, 35, 255)/*style.Colors[ImGuiCol_Button]*/;
			/*
			ImColor colorActive = ImColor(79, 79, 81, 255); /*style.Colors[ImGuiCol_ButtonActive]*/;
			/*
			ImColor colorHover = ImColor(62, 62, 66, 255)/*style.Colors[ImGuiCol_ButtonHovered]*/;
			/*


			if (index > 0)
				ImGui::SameLine();

			if (index == *selected)
			{
				style.Colors[ImGuiCol_Button] = colorActive;
				style.Colors[ImGuiCol_ButtonActive] = colorActive;
				style.Colors[ImGuiCol_ButtonHovered] = colorActive;
			}
			else
			{
				style.Colors[ImGuiCol_Button] = color;
				style.Colors[ImGuiCol_ButtonActive] = colorActive;
				style.Colors[ImGuiCol_ButtonHovered] = colorHover;
			}

			if (ImGui::Button(label, ImVec2(width, height)))
				*selected = index;

			style.Colors[ImGuiCol_Button] = color;
			style.Colors[ImGuiCol_ButtonActive] = colorActive;
			style.Colors[ImGuiCol_ButtonHovered] = colorHover;

			return *selected == index;
		}
	}*/