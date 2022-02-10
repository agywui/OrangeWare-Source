#include "Imgui/imgui.h"
#include "Imgui/imgui_impl_dx11.h"
#include "Imgui/imgui_internal.h"

namespace Offsets
{
	//static offsets
	uintptr_t CustomTimeDilation = 0x98; //Actor
	uintptr_t OwningGameInstance = 0x190; //World
	uintptr_t LocalPlayers = 0x38; //GameInstance
	uintptr_t PlayerController = 0x30; //Player
	uintptr_t StaticMesh = 0x480; //StaticMeshComponent
	uintptr_t AcknowledgedPawn = 0x2A8; //PlayerController
	uintptr_t PrimaryPickupItemEntry = 0x2A0; //FortPickup
	uintptr_t ItemDefinition = 0x18; //FortItemEntry
	uintptr_t DisplayName = 0x88; //FortItemDefinition
	uintptr_t Tier = 0x6C; //FortItemDefinition
	uintptr_t bComponentToWorldUpdated = 0x14C; //SceneComponent
	uintptr_t ComponentVelocity = 0x140; //SceneComponent
	uintptr_t Levels = 0x148; //World
	uintptr_t PersistentLevel = 0x30; //World
	uintptr_t AActors = 0x98; //ProceduralScatterActorContentVariation
	uintptr_t ActorCount = 0xA0; //GetActorCount old: 0xA0 new: 0xC0 = crash
	uintptr_t RootComponent = 0x130; //Actor
	uintptr_t RelativeLocation = 0x11C; //SceneComponent
	uintptr_t RelativeRotation = 0x128; //SceneComponent
	uintptr_t PlayerState = 0x238; //Pawn
	uintptr_t Mesh = 0x280; //Character
	uintptr_t ViewTarget = 0xE70; //PlayerCameraManager
	uintptr_t AmmoCount = 0xA70;
	uintptr_t ClipSize = 0x11c; //FortWeaponStats

	//need too update every update - not static
	uintptr_t TeamIndex = 0xF28; //FortPlayerStateAthena
	uintptr_t SquadId = 0x10AC; //FortPlayerStateAthena
	uintptr_t bIsReloadingWeapon = 0x2B1; //FortWeapon
	uintptr_t WeaponData = 0x378; //FortWeapon
	uintptr_t LastFireAbilityTime = 0x1238; //FortWeapon
	uintptr_t CurrentWeapon = 0x5F8; //FortPawn
	uintptr_t PlayerCameraManager = 0x2C0; //PlayerController
	uintptr_t CameraCache = 0x290; //PlayerCameraManager
	uintptr_t CameraCachePrivate = 0x1C20; //PlayerCameraManager
	uintptr_t LastFrameCameraCachePrivate = 0x2270; //PlayerCameraManager
	uintptr_t VehicleSkeletalMesh = 0x15A8; //FortAthenaSKVehicle.SkeletalMesh
	uintptr_t FireStartLoc = 0x8B8; //FortProjectileAthena
	uintptr_t DefaultFOV = 0x230; //PlayerCameraManager

	//exploits
	uintptr_t bADSWhileNotOnGround = 0x3E51; //FortPlayerPawnAthena
	uintptr_t bDisableEquipAnimation = 0x2B3; //FortWeapon
	uintptr_t ReviveFromDBNOTime = 0x3758; //FortPlayerPawnAthena
	uintptr_t LastFireTime = 0x9E4; //FortWeapon
	uintptr_t LastFireTimeVerified = 0x9E8; //FortWeapon
	uintptr_t LastReloadTime = 0xA3C; //FortWeapon
	uintptr_t LastSuccessfulReloadTime = 0xA40; //FortWeapon
	uintptr_t CurrentReloadDuration = 0xA44;
	uintptr_t bIsDBNO = 0x572; //FortPawn
}

namespace Renderer_Defines {
	float Width;
	float Height;
	float Length;
}

namespace Settings
{
	static bool PlayerAmmo = 0;
	static bool bUseFOV = 0;
	static bool ActorsAround = 0;
	static bool vehiclefly = 0;
	static bool vehicleflyv2 = 0;
	static bool Teleport = 0;
	//Aim
	static bool Aim = 1;
	static bool AimPrediction = 0;
	static bool MouseAim = 0;
	static int aimbone = 98;
	static float smooth = 1;
	static float fov_change_value = 80.f;
	static bool SilentAim = 0;
	static bool Bullettp = 0;
	static int aimkey = VK_RBUTTON;
	static int aimkeyint = 1;
	static float FovCircle_Value = 130;
	static float vehicleflyspeed = 15;
	static bool Head = 1;
	static bool Neck = 0;
	static bool Pelvis = 0;
	static bool Bottom = 0;
	static bool MarkerTP = 0;
	static bool UDcrosshair = 0;
	static bool LockLine = 0;
	static bool carflyUD = 0;
	static float carflyUD_value = 2;

	static bool objectdebug = 0;
	static bool tradersESP = 0;
	static bool animalsESP = 0;
	static bool ZombiesESP = 0;
	static bool FireflysESP = 0;
	static bool vendingmachineESP = 0;
	static bool burriedtreasureESP = 0;
	static bool ioguardESP = 0;

	//other experimental shit
	static bool Tp = 0;
	static bool memoryv2 = 0;
	static bool playerflyez = 0;
	static bool LSDmodeLOL = 0;
	static bool IsBulletTeleporting = 0;
	static bool PlayerNames = 0;
	static bool instantreload = 0;
	static bool NospreadV3 = 0;
	static bool norecoil = 0;
	static bool RadarDistance = 0;
	static bool radaresp = 0;

	//Vector3 Cords = { 0, 0, 0 };

	//Player ESP
	static bool Box2D = 0;
	static bool Box3D = 0;
	static bool BoxCorner = 1;
	static bool Skeleton = 0;
	static bool Skeleton_Low = 1;
	static bool DistanceESP = 0;
	static bool SnapLines = 0;
	static bool playerChams = 0;
	static bool PlayerWeapons = 0;

	//aimbot ranomiser func 
	static float random_x = 0;
	static float random_y = 0;
	static float random_z = 0;

	//Loot ESP
	static bool ChestESP = 0;
	static bool LLamaESP = 0;
	static bool WeaponESP = 0;
	static bool LootESP = 0;
	static bool AmmoBoxESP = 0;
	static bool VehiclesESP = 0;
	static bool campfire = 0;
	static bool botai = 0;
	static bool playerdying = 0;
	static bool weakspot = 0;
	static bool xpcoin = 0;
	static bool Turrent = 0;
	static bool placeables = 0;

	//Exploits
	static bool Speed = 0;
	static float SpeedValue = 2.0;
	static bool ServerAirStuck = 0;
	static bool fakedownON = 0;
	static bool fakedownOFF = 0;
	static bool Anim = 0;
	static bool NoSpread = 0;
	static bool InstantRevive = 0;
	static bool AimWhileJumping = 0;
	static bool AirStuck = 0;
	static bool RapidFire = 0;
	static float RapidFireValue = 0.003f;
	static bool fov360 = 0;
	static bool FirstCamera = 0;
	static bool Invis_ON = 0;
	static bool Invis_OFF = 0;
	static bool FastActions = 0;
	static bool FastReload = 0;
	static bool FriendlyFire = 0;
	static bool StickySilent = 0;
	static bool StickySilentInit = 0;
	static bool SniperBulletTP = 0;
	static bool NospreadV2 = 0;
	static bool Spinbot = 0;
	//static bool Fovchanger_asdbasyudgasuydgasydugasdyuasgd = 0;
	static bool ProjectileTP = 0;
	static bool TeleportDownedToLocalPawn = 0;

	//developers
	static bool test1 = 0;
	static bool test2 = 0;
	static bool test3 = 0;
	static bool test4 = 0;
	static bool test5 = 0;
	static bool test6 = 0;
	static bool test7 = 0;
	static bool test8 = 0;
	static bool test9 = 0;

	static bool test10 = 0;

	static bool debug = 0;

	//Misc
	static bool Gaybow = 0;
	static float MaxESPDistance = 300.f;
	static bool crosshair = 0;
	static bool ShowFovCircle = 1;
	static bool trigger = 0;
	static bool VisibleCheck = 0;
	static bool RainbowMenuCursor = 0;
	static bool NormalMenuCursor = 0;

	//Teleport Tab
	static bool EnableTP = 0;
	static bool CarTpToPing = 0;
	static bool CarTpToPlayer = 0;
	static bool WaypointTP = 0;

	static bool TP_lazylake = 0;
	static bool TP_WeepingWoods = 0;
	static bool TP_RetailRow = 0;
	static bool TP_SlurpySwamp = 0;
	static bool TP_BoneyBurbs = 0;
	static bool TP_PleasantPark = 0;
	static bool TP_PreLobby = 0;

	static bool TP_BeliverBeach = 0;
	static bool TP_Dirtydocks = 0;
	static bool TP_CornyCrops = 0;
	static bool TP_Craggyclifs = 0;
	static bool TP_coralcastle = 0;
	static bool TP_hollyhedges = 0;
	static bool TP_steamystacks = 0;
}

namespace SettingsColor {
	ImColor FovCircle = ImColor(0, 0, 0, 255);
	ImColor FovCircle360 = ImColor(255, 0, 0, 255);
	ImColor Box = ImColor(255, 0, 0, 255);
	ImColor Distance = ImColor(255, 0, 0, 255);
	ImColor Snaplines = ImColor(255, 0, 0, 255);
	ImColor Box_notvisible = ImColor(0, 0, 0, 255);

	ImColor Skeleton_notvisible = ImColor(255, 100, 0, 255);
	ImColor Distance_notvisible = ImColor(0, 0, 0, 255);
	ImColor Snaplines_notvisible = ImColor(0, 0, 0, 255);

	ImColor ChestESP = ImColor(255, 238, 0, 255);
	ImColor AmmoBox = ImColor(102, 101, 94, 255);
	ImColor LootESP = ImColor(255, 231, 94, 255);
	ImColor LLamaESP = ImColor(130, 19, 235, 255);
	ImColor VehicleESP = ImColor(235, 19, 19, 255);
}