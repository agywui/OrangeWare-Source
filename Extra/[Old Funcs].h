//old tabs

				/*
				if (ImGui::Button(xorstr_("AIMBOT                          "), { 155,28.f }))
				{
					//colors[ImGuiCol_Text] = ImColor(75, 88, 141, 255);
					maintabs = 0;
				}
				ImGui::SetCursorPos({ 0.f,89.f });
				if (ImGui::Button(xorstr_("VISUALS                         "), { 155,28.f }))
				{
					//colors[ImGuiCol_Text] = ImColor(75, 88, 141, 255);
					maintabs = 1;
				}
				ImGui::SetCursorPos({ 0.f,118.f });
				if (ImGui::Button(xorstr_("MISC                              "), { 155,28.f }))
				{
					//colors[ImGuiCol_Text] = ImColor(75, 88, 141, 255);
					maintabs = 2;
				}
				ImGui::SetCursorPos({ 0.f,147.f });
				if (ImGui::Button(xorstr_("EXPLOITS                       "), { 155,28.f }))
				{
					//colors[ImGuiCol_Text] = ImColor(75, 88, 141, 255);
					maintabs = 3;
				}*/

				//old titles
								//static char logo_buff[256];
								//sprintf(logo_buff, xorstr_("SKILL.CC FORTNITE @ %s : %s)"), xorstr_(__DATE__), xorstr_(__TIME__));
								//const char* title = (xorstr_("SKILL.CC FORTNITE @ %s : %s)", xorstr_(__DATE__), xorstr_(__TIME__)));


//old menu 

/*
VOID dsfbdsfubsfdbfsbdfdfhbsdhsbhhbsd(ImGuiWindow& window) {

	// Call rainbow here!

	ColorChange();
	ColorChangeForBonesAndAimKeys();

	Overlay()->PushClipRectFullScreen();
	ImGui::End();
	ImGui::PopStyleColor();
	ImGui::PopStyleVar(2);

	auto RGB = ImGui::GetColorU32({ color_red, color_green, color_blue, 255 });

	auto NORBNOG = ImGui::GetColorU32({ 0, 100, color_blue_100, 255 });

	ImGuiStyle* style = dst ? dst : &ImGui::GetStyle();
	ImVec4* colors = style->Colors;

	ImGuiIO& io = ImGui::GetIO();

	POINT p;
	SpoofCall(LI_FN(GetCursorPos).safe(), &p);
	io.MousePos.x = p.x;
	io.MousePos.y = p.y;

	if (ShowMenu_hasdbghuasdgbuyhasdguasdydgauysdgasuydg == true and Settings_as7d6as6d::RainbowMenuCursor_dfg66d7fg5df75g5dfg5dfg == 1) {
		Overlay()->AddLine(ImVec2(io.MousePos.x - 10, io.MousePos.y), ImVec2((io.MousePos.x - 10) + (10 * 2), io.MousePos.y), (RGB), 2.0);
		Overlay()->AddLine(ImVec2(io.MousePos.x, io.MousePos.y - 10), ImVec2(io.MousePos.x, (io.MousePos.y - 10) + (10 * 2)), (RGB), 2.0);
	}
	if (ShowMenu_hasdbghuasdgbuyhasdguasdydgauysdgasuydg == true and Settings_as7d6as6d::NormalMenuCursor_ds7f667sdffg5sdfgf566dfg5 == 1) {
		ImGui::GetIO().MouseDrawCursor = true;
	}
	if (Settings_as7d6as6d::NormalMenuCursor_ds7f667sdffg5sdfgf566dfg5 == 0) {
		ImGui::GetIO().MouseDrawCursor = false;
	}
	if (Settings_as7d6as6d::NormalMenuCursor_ds7f667sdffg5sdfgf566dfg5 == 1 and ShowMenu_hasdbghuasdgbuyhasdguasdydgauysdgasuydg == false) {
		ImGui::GetIO().MouseDrawCursor = false;
	}

	if (ShowMenu_hasdbghuasdgbuyhasdguasdydgauysdgasuydg) {
		ColorAndStyle();
		ImGui::SetNextWindowSize({ 395, 322 });
		ImGuiStyle* style = &ImGui::GetStyle();
		static int maintabs = 0;
		static int esptabs = 0;
		static int exploittabs = 0;

		//static char logo_buff[256];
		//sprintf(logo_buff, xorstr_("SKILL.CC FORTNITE @ %s : %s)"), xorstr_(__DATE__), xorstr_(__TIME__));
		//const char* title = (xorstr_("SKILL.CC FORTNITE @ %s : %s)", xorstr_(__DATE__), xorstr_(__TIME__)));

		if (ImGui::Begin(xorstr_("DoggyWare Internal @ 18.20"), &ShowMenu_hasdbghuasdgbuyhasdguasdydgauysdgasuydg, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse ))
		{
			ImGui::Tab(0, xorstr_("Aimbot"), &maintabs);
			ImGui::Tab(1, xorstr_("Visuals"), &maintabs);
			ImGui::Tab(2, xorstr_("Mods"), &maintabs);
			ImGui::Tab(3, xorstr_("Misc"), &maintabs);
			//ImGui::Tab(4, xorstr_("Developers Only"), &maintabs, 90);

			ImGui::Separator(4);

			if (maintabs == 0) {
				//colors[ImGuiCol_Text] = ImColor(255, 255, 255);
				//ImGui::Columns(2);
				//ImGui::Text(xorstr_("Aimbot:"));
				ImGui::Checkbox(xorstr_("Memory"), &Settings_as7d6as6d::Aim_asysdguaysdguaysdgauysdg);
				ImGui::Checkbox(xorstr_("Silent"), &Settings_as7d6as6d::SilentAim_ayusdgausydgyausdgauysdg);
				ImGui::Checkbox(xorstr_("Silent V2 \"Only Works In Vehicles\" "), &Settings_as7d6as6d::Bullettp_usauuidhiusdahgsduifghf);
				//ImGui::Checkbox(xorstr_("Sticky Silent \"Turn Up Smoothing To Make It Less Sticky\" "), &Settings_as7d6as6d::StickySilent_ashnduashdaushdasudh);

				//ImGui::Combo(xorstr_("Aimbone"), &Menu_AimBoneInt, AimBone_TypeItems, sizeof(AimBone_TypeItems) / sizeof(*AimBone_TypeItems));
				ImGui::Text(xorstr_(" "));

				//colors[ImGuiCol_Text] = ImColor(19, 110, 173);
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
					ImGui::Text(xorstr_("Current Bone:"));
					ImGui::SameLine();
					colors[ImGuiCol_Text] = ImColor(NORBNOG);
					ImGui::Text(xorstr_("Head"));
					colors[ImGuiCol_Text] = ImColor(255, 255, 255);
				}
				if (Settings_as7d6as6d::aimbone_iyashgdiuyasgdyuasgds == 65) {
					ImGui::Text(xorstr_("Current Bone:"));
					ImGui::SameLine();
					colors[ImGuiCol_Text] = ImColor(NORBNOG);
					ImGui::Text(xorstr_("Neck"));
					colors[ImGuiCol_Text] = ImColor(255, 255, 255);
				}
				if (Settings_as7d6as6d::aimbone_iyashgdiuyasgdyuasgds == 2) {
					ImGui::Text(xorstr_("Current Bone:"));
					ImGui::SameLine();
					colors[ImGuiCol_Text] = ImColor(NORBNOG);
					ImGui::Text(xorstr_("Pelvis"));
					colors[ImGuiCol_Text] = ImColor(255, 255, 255);
				}
				if (Settings_as7d6as6d::aimbone_iyashgdiuyasgdyuasgds == 0) {
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

				ImGui::SameLine();

				if (ImGui::Button(xorstr_("VK_CONTROL"), ImVec2(75, 17))) {
					Settings_as7d6as6d::aimkey_asuydguyasdguyasdyfgyu = VK_CONTROL;
					Settings_as7d6as6d::aimkeyint_ygdasyudgaysudgyasdg = 4;
				}

				colors[ImGuiCol_Button] = ImColor(19, 110, 173);
				colors[ImGuiCol_ButtonHovered] = ImColor(0, 134, 224);
				colors[ImGuiCol_ButtonActive] = ImColor(19, 110, 173);

				style->FramePadding = ImVec2(3.0f, 3.0f);

				if (Settings_as7d6as6d::aimkeyint_ygdasyudgaysudgyasdg == 1) {
					ImGui::Text(xorstr_("Current Aimbot Key:"));
					ImGui::SameLine();
					colors[ImGuiCol_Text] = ImColor(NORBNOG);
					ImGui::Text(xorstr_("Right Mouse Button"));
					colors[ImGuiCol_Text] = ImColor(255, 255, 255);
				}
				if (Settings_as7d6as6d::aimkeyint_ygdasyudgaysudgyasdg == 2) {
					ImGui::Text(xorstr_("Current Aimbot Key:"));
					ImGui::SameLine();
					colors[ImGuiCol_Text] = ImColor(NORBNOG);
					ImGui::Text(xorstr_("Left Mouse Button"));
					colors[ImGuiCol_Text] = ImColor(255, 255, 255);
				}
				if (Settings_as7d6as6d::aimkeyint_ygdasyudgaysudgyasdg == 3) {
					ImGui::Text(xorstr_("Current Aimbot Key:"));
					ImGui::SameLine();
					colors[ImGuiCol_Text] = ImColor(NORBNOG);
					ImGui::Text(xorstr_("Shift"));
					colors[ImGuiCol_Text] = ImColor(255, 255, 255);
				}
				if (Settings_as7d6as6d::aimkeyint_ygdasyudgaysudgyasdg == 4) {
					ImGui::Text(xorstr_("Current Aimbot Key:"));
					ImGui::SameLine();
					colors[ImGuiCol_Text] = ImColor(NORBNOG);
					ImGui::Text(xorstr_("Ctrl"));
					colors[ImGuiCol_Text] = ImColor(255, 255, 255);
				}

				ImGui::PushItemWidth(230);

				ImGui::Text(xorstr_(" "));
				//style->GrabMinSize = 6.0f;
				ImGui::SliderInt(xorstr_("Aimbot Smoothing"), &Settings_as7d6as6d::smooth_yuasghsdyiuawsgdyasgduy, 1, 20);
				ImGui::SliderInt(xorstr_("Fov Circle Value"), &Settings_as7d6as6d::FovCircle_Value_uaigdyuiasgdyasgd, 30, 1500);
				ImGui::Checkbox(xorstr_("Aimbot LockLine \"Shows What Player You're About to Lock On Too\" "), &Settings_as7d6as6d::LockLine_ashdiuashduiashdiuashd);

				ImGui::NextColumn();
				ImGui::Text(xorstr_("Colors"));
				ImGui::ColorEdit4(xorstr_("Fov Circle"), SettingsColor_sd78fysd76f6sdf::FovCircle_float, ImGuiColorEditFlags_NoInputs);

				ImGui::NextColumn();
			}

			else if (maintabs == 1)
			{
				//colors[ImGuiCol_Text] = ImColor(255, 255, 255);
				ImGui::Tab(0, xorstr_("Player Visuals"), &esptabs, 80);
				ImGui::Tab(1, xorstr_("World Visuals"), &esptabs, 80);

				ImGui::Separator(4);

				if (esptabs == 0)
				{
					//ImGui::Columns(2);
					//ImGui::Text(xorstr_("Player Visuals:"));
					ImGui::Checkbox(xorstr_("2D Box"), &Settings_as7d6as6d::Box2D_dfjghdfgbgbgbgbgbedfhud);
					ImGui::Checkbox(xorstr_("3D Box"), &Settings_as7d6as6d::Box3D_9dasasujihdfdhg);
					ImGui::Checkbox(xorstr_("Corner Box"), &Settings_as7d6as6d::BoxCorner_ashdgbashuydgasd);
					ImGui::Checkbox(xorstr_("Skeleton High Res"), &Settings_as7d6as6d::Skeleton_yhasgvdyuasfgdtasfdtasfd);
					ImGui::Checkbox(xorstr_("Skeleton Low Res"), &Settings_as7d6as6d::Skeleton_Low_yhasgvdyuasfgdtasfdtasfd);
					ImGui::Checkbox(xorstr_("Distance"), &Settings_as7d6as6d::DistanceESP_aysgduyasgdytfyhfuiyhdf);
					ImGui::Checkbox(xorstr_("Bot/Ai"), &Settings_as7d6as6d::botai_hufdsghfuysdgfyuygyusdgfuysdg);
					ImGui::Checkbox(xorstr_("PlayerDying"), &Settings_as7d6as6d::playerdying_yusdgfuydfguiwryewetrdgfdhsfg);
					//ImGui::Checkbox(xorstr_("PlayerWeapon"), &Settings_as7d6as6d::PlayerWeapons_asuisdghasuydgasyudgasuydgasudygasudy);
					ImGui::Checkbox(xorstr_("Snaplines"), &Settings_as7d6as6d::SnapLines_badshhfgvadsufdfsdfufg);
					//ImGui::Checkbox(xorstr_("Chams"), &Settings_as7d6as6d::playerChams_asuijdhasiudhasiudhasuidh);
					ImGui::SliderInt(xorstr_("ESP Max Distance"), &Settings_as7d6as6d::MaxESPDistance_hguadsgysdfggsdhfgsgdfsdf, 10, 500);

					/*
					ImGui::NextColumn();

					ImGui::Text(xorstr_("Players Colors"));
					ImGui::ColorEdit4(xorstr_("##BoxESPvis"), SettingsColor_sd78fysd76f6sdf::Box_float, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::ColorEdit4(xorstr_("##BoxESPnotvis"), SettingsColor_sd78fysd76f6sdf::Box_notvisible_float, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::Text(xorstr_("Box Visible / Not Visible"));
					ImGui::ColorEdit4(xorstr_("##SkeletonESPvis"), SettingsColor_sd78fysd76f6sdf::Skeleton_float, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::ColorEdit4(xorstr_("##SkeletonESPnotvis"), SettingsColor_sd78fysd76f6sdf::Skeleton_notvisible_float, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::Text(xorstr_("Skeleton Visible / Not Visible"));
					ImGui::ColorEdit4(xorstr_("##DistanceESPvis"), SettingsColor_sd78fysd76f6sdf::Distance_float, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::ColorEdit4(xorstr_("##DistanceESPnotvis"), SettingsColor_sd78fysd76f6sdf::Distance_notvisible_float, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::Text(xorstr_("Distance Visible / Not Visible"));
					ImGui::ColorEdit4(xorstr_("##Snaplinesvis"), SettingsColor_sd78fysd76f6sdf::Snaplines_float, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::ColorEdit4(xorstr_("##Snaplinesnotvis"), SettingsColor_sd78fysd76f6sdf::Snaplines_notvisible_float, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::Text(xorstr_("Snaplines Visible / Not Visible"));

					ImGui::NextColumn();
				}
				else if (esptabs == 1)
				{
					//colors[ImGuiCol_Text] = ImColor(255, 255, 255);
					//ImGui::Text(xorstr_("World Visuals:"));
					ImGui::Checkbox(xorstr_("Chest"), &Settings_as7d6as6d::ChestESP_sadhufgsuydfgsdyufgtsdyufgsdf);
					ImGui::Checkbox(xorstr_("AmmoBox"), &Settings_as7d6as6d::AmmoBoxESP_asydgausydt6asdtauysdtgausydtasyud);
					ImGui::Checkbox(xorstr_("Loot"), &Settings_as7d6as6d::LootESP_std67astd76as5dt6as5d6as5dasdasdas);
					ImGui::Checkbox(xorstr_("LLama"), &Settings_as7d6as6d::LLamaESP_uaseyd87atsydastdyuasdtaysdtgasd);
					ImGui::Checkbox(xorstr_("Vehicles"), &Settings_as7d6as6d::VehiclesESP_auydy78asydtyuasgdyuasdgghasgdasd);
					ImGui::Checkbox(xorstr_("WeakSpot"), &Settings_as7d6as6d::weakspot_sdyhfg6we5gsadyugwergsadg);
					ImGui::Checkbox(xorstr_("Campfire"), &Settings_as7d6as6d::campfire_uysdgauysdguyasdguyasdgyuasdgasd);
					//ImGui::Checkbox(xorstr_("Vehicles"), &Settings_as7d6as6d::VehiclesESP_auydy78asydtyuasgdyuasdgghasgdasd);

					/*
					ImGui::NextColumn();

					ImGui::Text(xorstr_("Loot Colors"));
					ImGui::ColorEdit4(xorstr_("Chest ESP"), SettingsColor_sd78fysd76f6sdf::ChestESP_float, ImGuiColorEditFlags_NoInputs);
					ImGui::ColorEdit4(xorstr_("AmmoBox ESP"), SettingsColor_sd78fysd76f6sdf::AmmoBox_float, ImGuiColorEditFlags_NoInputs);
					ImGui::ColorEdit4(xorstr_("Loot ESP"), SettingsColor_sd78fysd76f6sdf::LootESP_float, ImGuiColorEditFlags_NoInputs);
					ImGui::ColorEdit4(xorstr_("LLama ESP"), SettingsColor_sd78fysd76f6sdf::LLamaESP_float, ImGuiColorEditFlags_NoInputs);
					ImGui::ColorEdit4(xorstr_("Vehicle ESP"), SettingsColor_sd78fysd76f6sdf::VehicleESP_float, ImGuiColorEditFlags_NoInputs);

					ImGui::NextColumn();
				}
			}
			else if (maintabs == 2)
			{
				ImGui::Tab(0, xorstr_("Player Mods"), &exploittabs, 80);
				ImGui::Tab(1, xorstr_("Weapon Mods"), &exploittabs, 80);
				ImGui::Tab(2, xorstr_("Vehicle Mods"), &exploittabs, 80);

				ImGui::Separator(4);

				if (exploittabs == 0) {
					//colors[ImGuiCol_Text] = ImColor(255, 255, 255);
					//ImGui::Text(xorstr_("Player Mods:"));

					ImGui::Checkbox(xorstr_("Instant Revive"), &Settings_as7d6as6d::InstantRevive_ayussgd7adft76sdf5s6df56sdf);
					//ImGui::Checkbox(xorstr_("BulletTP [Only in vehicle!]"), &Settings_as7d6as6d::Bullettp_usauuidhiusdahgsduifghf);
					ImGui::Checkbox(xorstr_("Client AirStuck"), &Settings_as7d6as6d::AirStuck_asdgfuydfgyusdaafgyusdfgsdyuf);
					ImGui::Checkbox(xorstr_("Server AirStuck"), &Settings_as7d6as6d::ServerAirStuck_asuyhdhgasuydgausydgasuydgasuydg);
					ImGui::Checkbox(xorstr_("Instant Actions"), &Settings_as7d6as6d::FastActions_sahdgbhasdghausydgauytdgasydgasd);

					colors[ImGuiCol_Button] = ImColor(19, 110, 173);
					colors[ImGuiCol_ButtonHovered] = ImColor(0, 134, 224);
					colors[ImGuiCol_ButtonActive] = ImColor(19, 110, 173);

					style->FramePadding = ImVec2(4.5f, 2.5f);

					if (ImGui::Button(xorstr_("ClientSidedDBNO ON"), ImVec2(108, 17))) {
						Settings_as7d6as6d::fakedownON_asuyidhyausydgasuydgausydgasd = true;
					}

					if (ImGui::Button(xorstr_("ClientSidedDBNO OFF"), ImVec2(110, 17))) {
						Settings_as7d6as6d::fakedownOFF_duhasguytasgdyaysdgyuasdgyuazsdg = true;
					}

					if (ImGui::Button(xorstr_("FirstPerson"), ImVec2(64, 17))) {
						Settings_as7d6as6d::FirstCamera_usadhfuysdagfgtswdgfysdfgsdf = true;
					}

					colors[ImGuiCol_Button] = ImColor(19, 110, 173);
					colors[ImGuiCol_ButtonHovered] = ImColor(0, 134, 224);
					colors[ImGuiCol_ButtonActive] = ImColor(19, 110, 173);

					style->FramePadding = ImVec2(3.0f, 3.0f);
				}
				if (exploittabs == 1) {
					//ImGui::Text(xorstr_("Weapon Mods:"));
					ImGui::Checkbox(xorstr_("No Spread \"RISK\" "), &Settings_as7d6as6d::NoSpread_sd89f7sd67ft6sdf5s6df5);
					ImGui::Checkbox(xorstr_("No Spread V2 \"Only Works With AR's And Bursts\" "), &Settings_as7d6as6d::NospreadV2_suhdfiusdahasuidhasuidhausidh);
					//ImGui::Checkbox(xorstr_("Bullet TP"), &Settings_as7d6as6d::SniperBulletTP_uasdukyiasgdyuasdgaysudg);
					ImGui::Checkbox(xorstr_("Spinbot \"Good With Silent\""), &Settings_as7d6as6d::Spinbot_ahsdhbayiusdgasydgasydgasydgasd);
					ImGui::Checkbox(xorstr_("Instant Reload"), &Settings_as7d6as6d::FastReload_ashdhgauysdgasydgasuytdgasuydgasuydg);
					ImGui::Checkbox(xorstr_("Instant Weapon Swap"), &Settings_as7d6as6d::Anim_a7s6ydas5da5d6as7d567f5sd67f5sdf6);
					ImGui::Checkbox(xorstr_("Aim While Jumping"), &Settings_as7d6as6d::AimWhileJumping_yatsdfysdtftsdtrftsdftusdftusdf);
					ImGui::Checkbox(xorstr_("Rapid Fire"), &Settings_as7d6as6d::RapidFire_ahsdgfdsfgsdfgsdfgsdyfgsdf);
					if (Settings_as7d6as6d::RapidFire_ahsdgfdsfgsdfgsdfgsdyfgsdf) {
						ImGui::SliderFloat(xorstr_("Rapid Fire Value##slider"), &Settings_as7d6as6d::RapidFireValue_hauysdgvuysdfguysdfguysdfg, 0.001, 0.500, xorstr_("%.3f"));
					}
					ImGui::Checkbox(xorstr_("360Fov \"Good With Silent\" "), &Settings_as7d6as6d::fov360_ghasdgdfytsdafggshdfgsdgf);
					ImGui::Checkbox(xorstr_("Aimbot Prediction \"Good To Use With Snipers\" "), &Settings_as7d6as6d::AimPrediction_ashdiuashduiashdiuashd);
				}
				if (exploittabs == 2) {
					//ImGui::Text(xorstr_("Vehicle Mods:"));
					ImGui::Checkbox(xorstr_("Vehicle Speed [SHIFT]##checkbox"), &Settings_as7d6as6d::Speed_asugdgausytdgauysdgausydgyuasdgaswd);

					if (Settings_as7d6as6d::Speed_asugdgausytdgauysdgausydgyuasdgaswd) {
						ImGui::SliderFloat(xorstr_("Vehicle Speed Value##slider"), &Settings_as7d6as6d::SpeedValue_hyasgduyasgduasgdyasgdyuasgduyasdg, 1.001, 100.0);
					}
				}
			}
			else if (maintabs == 3)
			{
				//colors[ImGuiCol_Text] = ImColor(255, 255, 255);
				ImGui::Text(xorstr_("Misc:"));
				ImGui::Checkbox(xorstr_("Show Fov Circle"), &Settings_as7d6as6d::ShowFovCircle_87gf6sdf567s5f6sd5fdsf);
				ImGui::Checkbox(xorstr_("Crosshair"), &Settings_as7d6as6d::crosshair_sdfsdfsdfsdfsdfsdf);
				ImGui::Checkbox(xorstr_("UD Crosshair"), &Settings_as7d6as6d::UDcrosshair_asdhasudhasuydhasyud);
				ImGui::Checkbox(xorstr_("Visible Check"), &Settings_as7d6as6d::VisibleCheck_dsf7fg676dfg6dgf67hdg67h56dfgh);
				ImGui::Text(xorstr_("Menu Cursors:"));
				ImGui::Checkbox(xorstr_("Rainbow Menu Cursor"), &Settings_as7d6as6d::RainbowMenuCursor_dfg66d7fg5df75g5dfg5dfg);
				ImGui::Checkbox(xorstr_("Normal Menu Cursor (defualt)"), &Settings_as7d6as6d::NormalMenuCursor_ds7f667sdffg5sdfgf566dfg5);
				ImGui::Text(xorstr_("Visuals MISC:"));
				ImGui::Checkbox(xorstr_("Rainbow ESP Mode"), &Settings_as7d6as6d::Gaybow_syuadgtasdfgtausdftsaddfg);
			}

			else if (maintabs == 4)
			{
				colors[ImGuiCol_Button] = ImColor(19, 110, 173);
				colors[ImGuiCol_ButtonHovered] = ImColor(0, 134, 224);
				colors[ImGuiCol_ButtonActive] = ImColor(19, 110, 173);

				style->FramePadding = ImVec2(4.5f, 2.5f);

				ImGui::Text(xorstr_("this tab is for developer's to test stuff please do not use any of these options"));

				if (ImGui::Button(xorstr_("test 1 (always sliding ON)"), ImVec2(200, 17))) {
					Settings_as7d6as6d::test1 = true;
				}

				if (ImGui::Button(xorstr_("test 2 (always sliding OFF)"), ImVec2(200, 17))) {
					Settings_as7d6as6d::test2 = true;
				}

				if (ImGui::Button(xorstr_("test 3 (bIsSwinging ON)"), ImVec2(200, 17))) {
					Settings_as7d6as6d::test3 = true;
				}

				if (ImGui::Button(xorstr_("test 4 (bIsSwinging OFF)"), ImVec2(200, 17))) {
					Settings_as7d6as6d::test4 = true;
				}

				if (ImGui::Button(xorstr_("test 5 (bIsParachuteForcedOpen ON)"), ImVec2(200, 17))) {
					Settings_as7d6as6d::test5 = true;
				}

				if (ImGui::Button(xorstr_("test 6 (bIsParachuteForcedOpen OFF)"), ImVec2(200, 17))) {
					Settings_as7d6as6d::test6 = true;
				}

				if (ImGui::Button(xorstr_("test 7 (bRegisterWithAISight ON) (botai godmode)"), ImVec2(250, 17))) {
					Settings_as7d6as6d::test7 = true;
				}

				if (ImGui::Button(xorstr_("test 8 (bRegisterWithAISight OFF) (botai godmode)"), ImVec2(250, 17))) {
					Settings_as7d6as6d::test8 = true;
				}

				if (ImGui::Button(xorstr_("test 9 (newsilent?)"), ImVec2(250, 17))) {
					Settings_as7d6as6d::test9 = true;
				}

				ImGui::SliderFloat(xorstr_("Circle Val##slider"), &Settings_as7d6as6d::test10, 1, 124, xorstr_("%.3f"));

				colors[ImGuiCol_Button] = ImColor(19, 110, 173);
				colors[ImGuiCol_ButtonHovered] = ImColor(0, 134, 224);
				colors[ImGuiCol_ButtonActive] = ImColor(19, 110, 173);

				style->FramePadding = ImVec2(3.0f, 3.0f);
			}
			ImGui::End();
		}
	}

	// Rainbow renders

	if (Settings_as7d6as6d::Gaybow_syuadgtasdfgtausdftsaddfg) {

		//SettingsColor_sd78fysd76f6sdf::FovCircle = RGB;

		SettingsColor_sd78fysd76f6sdf::Box_asdf67tsd76f6sdf676sdf686sdf = RGB;
		SettingsColor_sd78fysd76f6sdf::Skeleton_ds5f5sd5f5sd65f5sdf = RGB;
		SettingsColor_sd78fysd76f6sdf::Distance_sd7ft66sdf5s7df67sdf6 = RGB;
		SettingsColor_sd78fysd76f6sdf::Snaplines_6dsf556sdff45fg54df55g = RGB;

		SettingsColor_sd78fysd76f6sdf::Box_notvisible_dsyafty76sdfgtdf6g76df56g = RGB;
		SettingsColor_sd78fysd76f6sdf::Skeleton_notvisible_s6yf6765sdf6f65sdf66sdf = RGB;
		SettingsColor_sd78fysd76f6sdf::Distance_notvisible_a67dsf45asdf5assdasdasd = RGB;
		SettingsColor_sd78fysd76f6sdf::Snaplines_notvisible_adsdasdggh87778632 = RGB;

		//LootESP colors
		SettingsColor_sd78fysd76f6sdf::ChestESP_asd7665sdaa65f5sad5f5asddasd = ImColor(SettingsColor_sd78fysd76f6sdf::ChestESP_float_asyd76asd667asd6d67asd6e567asd[0], SettingsColor_sd78fysd76f6sdf::ChestESP_float_asyd76asd667asd6d67asd6e567asd[1], SettingsColor_sd78fysd76f6sdf::ChestESP_float_asyd76asd667asd6d67asd6e567asd[2], SettingsColor_sd78fysd76f6sdf::ChestESP_float_asyd76asd667asd6d67asd6e567asd[3]);
		SettingsColor_sd78fysd76f6sdf::AmmoBox_df6gty76dfg676df6gf6dg = ImColor(SettingsColor_sd78fysd76f6sdf::AmmoBox_float_sadf787sdf678dsf6gf7dsfg6dfg[0], SettingsColor_sd78fysd76f6sdf::AmmoBox_float_sadf787sdf678dsf6gf7dsfg6dfg[1], SettingsColor_sd78fysd76f6sdf::AmmoBox_float_sadf787sdf678dsf6gf7dsfg6dfg[2], SettingsColor_sd78fysd76f6sdf::AmmoBox_float_sadf787sdf678dsf6gf7dsfg6dfg[3]);
		SettingsColor_sd78fysd76f6sdf::LootESP_sd6f6dfg66dsf6g7dfr6gf = ImColor(SettingsColor_sd78fysd76f6sdf::LootESP_float_sd7f676sdf5fg6d7fg56dfg[0], SettingsColor_sd78fysd76f6sdf::LootESP_float_sd7f676sdf5fg6d7fg56dfg[1], SettingsColor_sd78fysd76f6sdf::LootESP_float_sd7f676sdf5fg6d7fg56dfg[2], SettingsColor_sd78fysd76f6sdf::LootESP_float_sd7f676sdf5fg6d7fg56dfg[3]);
		SettingsColor_sd78fysd76f6sdf::LLamaESP_sdy7f68sd6f6sd5fsd5f = ImColor(SettingsColor_sd78fysd76f6sdf::LLamaESP_float_dsf7867sdf78f7s7df7sdf[0], SettingsColor_sd78fysd76f6sdf::LLamaESP_float_dsf7867sdf78f7s7df7sdf[1], SettingsColor_sd78fysd76f6sdf::LLamaESP_float_dsf7867sdf78f7s7df7sdf[2], SettingsColor_sd78fysd76f6sdf::LLamaESP_float_dsf7867sdf78f7s7df7sdf[3]);
		SettingsColor_sd78fysd76f6sdf::VehicleESP_s7d6f76sdf566sdf56sdf5sdf = ImColor(SettingsColor_sd78fysd76f6sdf::VehicleESP_float_dsf6y76sdgf6dfgy87dfg778778[0], SettingsColor_sd78fysd76f6sdf::VehicleESP_float_dsf6y76sdgf6dfgy87dfg778778[1], SettingsColor_sd78fysd76f6sdf::VehicleESP_float_dsf6y76sdgf6dfgy87dfg778778[2], SettingsColor_sd78fysd76f6sdf::VehicleESP_float_dsf6y76sdgf6dfgy87dfg778778[3]);
	}
	else {
		//FovCircle Color
		SettingsColor_sd78fysd76f6sdf::FovCircle_asdasdgagshdgagsjdgadf = ImColor(SettingsColor_sd78fysd76f6sdf::FovCircle_float_as76dsd76fsd76f5sdf[0], SettingsColor_sd78fysd76f6sdf::FovCircle_float_as76dsd76fsd76f5sdf[1], SettingsColor_sd78fysd76f6sdf::FovCircle_float_as76dsd76fsd76f5sdf[2], SettingsColor_sd78fysd76f6sdf::FovCircle_float_as76dsd76fsd76f5sdf[3]);

		//PlayersESP colors
		SettingsColor_sd78fysd76f6sdf::Box_asdf67tsd76f6sdf676sdf686sdf = ImColor(SettingsColor_sd78fysd76f6sdf::Box_float_hwedf7ysdf87sd6f87sd6f68sd56f[0], SettingsColor_sd78fysd76f6sdf::Box_float_hwedf7ysdf87sd6f87sd6f68sd56f[1], SettingsColor_sd78fysd76f6sdf::Box_float_hwedf7ysdf87sd6f87sd6f68sd56f[2], SettingsColor_sd78fysd76f6sdf::Box_float_hwedf7ysdf87sd6f87sd6f68sd56f[3]);
		SettingsColor_sd78fysd76f6sdf::Skeleton_ds5f5sd5f5sd65f5sdf = ImColor(SettingsColor_sd78fysd76f6sdf::Skeleton_float_7sdfy6sf6gsf6g6sdf[0], SettingsColor_sd78fysd76f6sdf::Skeleton_float_7sdfy6sf6gsf6g6sdf[1], SettingsColor_sd78fysd76f6sdf::Skeleton_float_7sdfy6sf6gsf6g6sdf[2], SettingsColor_sd78fysd76f6sdf::Skeleton_float_7sdfy6sf6gsf6g6sdf[3]);
		SettingsColor_sd78fysd76f6sdf::Distance_sd7ft66sdf5s7df67sdf6 = ImColor(SettingsColor_sd78fysd76f6sdf::Distance_float_sd6f5sdf5ds7f5sd6f[0], SettingsColor_sd78fysd76f6sdf::Distance_float_sd6f5sdf5ds7f5sd6f[1], SettingsColor_sd78fysd76f6sdf::Distance_float_sd6f5sdf5ds7f5sd6f[2], SettingsColor_sd78fysd76f6sdf::Distance_float_sd6f5sdf5ds7f5sd6f[3]);
		SettingsColor_sd78fysd76f6sdf::Snaplines_6dsf556sdff45fg54df55g = ImColor(SettingsColor_sd78fysd76f6sdf::Snaplines_float_ad6s7f5tf56sdfr576sdf56sdf[0], SettingsColor_sd78fysd76f6sdf::Snaplines_float_ad6s7f5tf56sdfr576sdf56sdf[1], SettingsColor_sd78fysd76f6sdf::Snaplines_float_ad6s7f5tf56sdfr576sdf56sdf[2], SettingsColor_sd78fysd76f6sdf::Snaplines_float_ad6s7f5tf56sdfr576sdf56sdf[3]);

		SettingsColor_sd78fysd76f6sdf::Box_notvisible_dsyafty76sdfgtdf6g76df56g = ImColor(SettingsColor_sd78fysd76f6sdf::Box_notvisible_float_6sd6f67sd56f67ds5f66sdf[0], SettingsColor_sd78fysd76f6sdf::Box_notvisible_float_6sd6f67sd56f67ds5f66sdf[1], SettingsColor_sd78fysd76f6sdf::Box_notvisible_float_6sd6f67sd56f67ds5f66sdf[2], SettingsColor_sd78fysd76f6sdf::Box_notvisible_float_6sd6f67sd56f67ds5f66sdf[3]);
		SettingsColor_sd78fysd76f6sdf::Skeleton_notvisible_s6yf6765sdf6f65sdf66sdf = ImColor(SettingsColor_sd78fysd76f6sdf::Skeleton_notvisible_float_dfghsdfuygdsf7g7dfg[0], SettingsColor_sd78fysd76f6sdf::Skeleton_notvisible_float_dfghsdfuygdsf7g7dfg[1], SettingsColor_sd78fysd76f6sdf::Skeleton_notvisible_float_dfghsdfuygdsf7g7dfg[2], SettingsColor_sd78fysd76f6sdf::Skeleton_notvisible_float_dfghsdfuygdsf7g7dfg[3]);
		SettingsColor_sd78fysd76f6sdf::Distance_notvisible_a67dsf45asdf5assdasdasd = ImColor(SettingsColor_sd78fysd76f6sdf::Distance_notvisible_float_dsf5t6sdf576sd5f76sd5fsdf[0], SettingsColor_sd78fysd76f6sdf::Distance_notvisible_float_dsf5t6sdf576sd5f76sd5fsdf[1], SettingsColor_sd78fysd76f6sdf::Distance_notvisible_float_dsf5t6sdf576sd5f76sd5fsdf[2], SettingsColor_sd78fysd76f6sdf::Distance_notvisible_float_dsf5t6sdf576sd5f76sd5fsdf[3]);
		SettingsColor_sd78fysd76f6sdf::Snaplines_notvisible_adsdasdggh87778632 = ImColor(SettingsColor_sd78fysd76f6sdf::Snaplines_notvisible_float_7sdf6786df6gb87dff78asddf6[0], SettingsColor_sd78fysd76f6sdf::Snaplines_notvisible_float_7sdf6786df6gb87dff78asddf6[1], SettingsColor_sd78fysd76f6sdf::Snaplines_notvisible_float_7sdf6786df6gb87dff78asddf6[2], SettingsColor_sd78fysd76f6sdf::Snaplines_notvisible_float_7sdf6786df6gb87dff78asddf6[3]);

		//LootESP colors
		SettingsColor_sd78fysd76f6sdf::ChestESP_asd7665sdaa65f5sad5f5asddasd = ImColor(SettingsColor_sd78fysd76f6sdf::ChestESP_float_asyd76asd667asd6d67asd6e567asd[0], SettingsColor_sd78fysd76f6sdf::ChestESP_float_asyd76asd667asd6d67asd6e567asd[1], SettingsColor_sd78fysd76f6sdf::ChestESP_float_asyd76asd667asd6d67asd6e567asd[2], SettingsColor_sd78fysd76f6sdf::ChestESP_float_asyd76asd667asd6d67asd6e567asd[3]);
		SettingsColor_sd78fysd76f6sdf::AmmoBox_df6gty76dfg676df6gf6dg = ImColor(SettingsColor_sd78fysd76f6sdf::AmmoBox_float_sadf787sdf678dsf6gf7dsfg6dfg[0], SettingsColor_sd78fysd76f6sdf::AmmoBox_float_sadf787sdf678dsf6gf7dsfg6dfg[1], SettingsColor_sd78fysd76f6sdf::AmmoBox_float_sadf787sdf678dsf6gf7dsfg6dfg[2], SettingsColor_sd78fysd76f6sdf::AmmoBox_float_sadf787sdf678dsf6gf7dsfg6dfg[3]);
		SettingsColor_sd78fysd76f6sdf::LootESP_sd6f6dfg66dsf6g7dfr6gf = ImColor(SettingsColor_sd78fysd76f6sdf::LootESP_float_sd7f676sdf5fg6d7fg56dfg[0], SettingsColor_sd78fysd76f6sdf::LootESP_float_sd7f676sdf5fg6d7fg56dfg[1], SettingsColor_sd78fysd76f6sdf::LootESP_float_sd7f676sdf5fg6d7fg56dfg[2], SettingsColor_sd78fysd76f6sdf::LootESP_float_sd7f676sdf5fg6d7fg56dfg[3]);
		SettingsColor_sd78fysd76f6sdf::LLamaESP_sdy7f68sd6f6sd5fsd5f = ImColor(SettingsColor_sd78fysd76f6sdf::LLamaESP_float_dsf7867sdf78f7s7df7sdf[0], SettingsColor_sd78fysd76f6sdf::LLamaESP_float_dsf7867sdf78f7s7df7sdf[1], SettingsColor_sd78fysd76f6sdf::LLamaESP_float_dsf7867sdf78f7s7df7sdf[2], SettingsColor_sd78fysd76f6sdf::LLamaESP_float_dsf7867sdf78f7s7df7sdf[3]);
		SettingsColor_sd78fysd76f6sdf::VehicleESP_s7d6f76sdf566sdf56sdf5sdf = ImColor(SettingsColor_sd78fysd76f6sdf::VehicleESP_float_dsf6y76sdgf6dfgy87dfg778778[0], SettingsColor_sd78fysd76f6sdf::VehicleESP_float_dsf6y76sdgf6dfgy87dfg778778[1], SettingsColor_sd78fysd76f6sdf::VehicleESP_float_dsf6y76sdgf6dfgy87dfg778778[2], SettingsColor_sd78fysd76f6sdf::VehicleESP_float_dsf6y76sdgf6dfgy87dfg778778[3]);
	}

	ImGui::Render();
}*/
/*
Unviversal
Process Event : 40 55 56 57 41 54 41 55 41 56 41 57 48 81 EC ? ? ? ? 48 8D 6C 24 ? 48 89 9D ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C5 48 89 85 ? ? ? ? 8B 41 0C 45 33 F6 3B 05 ? ? ? ? 4D 8B F8 48 8B F2 4C 8B E1 41 B8 ? ? ? ? 7D 2A
CurlEasySetOpt : 89 54 24 10 4C 89 44 24 18 4C 89 4C 24 20 48 83 EC 28 48 85 C9 75 08 8D 41 2B 48 83 C4 28 C3 4C
CurlSetOpt : 48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 48 83 EC 30 33 ED 49 8B F0 48 8B D9

C1
S9 and S10
Free : 48 85 C9 74 2E 53
GWorld : 48 8B 1D ? ? ? ? 48 85 DB 74 3B 41
Get Object Name : 40 53 48 83 EC 20 48 8B D9 48 85 D2 75 30 33 C0 48 89 01 48 C7 41 08 ? ? ? ? E8 ? ? ? ? 48 8B 0B 48 8D 15 ? ? ? ? 41 B8 ? ? ? ? E8 ? ? ? ? 48 8B C3 48 83 C4 20 5B C3 48
GObjects : 49 63 C8 48 8D 14 40 48 8B 05 ? ? ? ? 48 8B 0C C8 48 8D 04 D1
Get Player Controller : 83 B9 ? ? ? ? ? 7E ? 48 8B 89 ? ? ? ? E9
Static Construct Object : 48 89 5C 24 18 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 44 8B A5 ? ? ? ? 48 8D 05
Spawn Actor : 40 53 56 57 48 83 EC 70 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 ? 0F 28 1D ? ? ? ? 0F 57 D2 48 8B B4 24 ? ? ? ? 0F 28 CB

S5 - S8
Free : 48 85 C9 74 2E 53 48 83 EC 20 48 8B D9
GWorld : 48 89 05 ? ? ? ? 48 8B 8F
FNameToString : 48 89 5C 24 ? 57 48 83 EC 30 83 79 04 00 48 8B DA 48 8B F9
GObjects : 48 8D 05 ? ? ? ? 48 89 01 33 C9 84 D2 41 8B 40 08 49 89 48 10 0F 45 05 ? ? ? ? FF C0 49 89 48 10 41 89 40 08 (Not Relative)
Get Player Controller : 83 B9 ? ? ? ? ? 7E ? 48 8B 89 ? ? ? ? E9
Static Construct Object : 48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 44 8B A5 ? ? ? ? 48 8D 05 ? ? ? ?
Spawn Actor : 40 53 56 57 48 83 EC 70 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 ? 0F 28 1D ? ? ? ? 0F 57 D2 48 8B B4 24 ? ? ? ? 0F 28 CB

C2
12.61 - 15.0 (GWorld doesnt work on 12.41 and older)
GWorld : 48 89 05 ? ? ? ? 48 8B B6 ? ? ? ?
GObjects : 49 63 C8 48 8D 14 40 48 8B 05 ? ? ? ? 48 8B 0C C8 48 8D 04 D1
Get Object Name : 40 53 48 83 EC 20 48 8B D9 48 85 D2 75 45 33 C0 48 89 01 48 89 41 08 8D 50 05 E8 ? ? ? ? 8B 53 08 8D 42 05 89 43 08 3B 43 0C 7E 08 48 8B CB E8 ? ? ? ? 48 8B 0B 48 8D 15 ? ? ? ? 41 B8 ? ? ? ? E8 ? ? ? ? 48 8B C3 48 83 C4 20 5B C3 48 8B 42 18
GetFirstPlayerController : 83 B9 ? ? ? ? ? 7E ? 48 8B 89 ? ? ? ? E9
Static Consturct Object : 4C 89 44 24 18 55 53 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4
Free : 48 85 C9 74 2E 53
Spawn Actor : 53 56 57 48 83 EC 70 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 60 0F 28 1D ? ? ? ? 0F 57 D2 48 8B B4 24 B0
*/

/*
namespace DiscordHelper
{
	uintptr_t module = (uintptr_t)LI_FN(GetModuleHandleA)(xorstr_("DiscordHook64.dll"));

	std::vector<uintptr_t> pCreatedHooksArray;
	bool CreateHook(uintptr_t pOriginal, uintptr_t pHookedFunction, uintptr_t pOriginalCall)
	{
		static uintptr_t addrCreateHook = NULL;

		if (!addrCreateHook)
			addrCreateHook = MemoryHelper::PatternScanW(module, xorstr_("41 57 41 56 56 57 55 53 48 83 EC 68 4D 89 C6 49 89 D7"));

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
			addrEnableHookQueu = MemoryHelper::PatternScanW(module, xorstr_("41 57 41 56 41 55 41 54 56 57 55 53 48 83 EC 38 48 ? ? ? ? ? ? 48 31 E0 48 89 44 24 30 BE 01 00 00 00 31 C0 F0 ? ? ? ? ? ? ? 74 2B"));

		if (!addrEnableHookQueu)
			return false;

		using EnableHookQueu_t = uint64_t(__stdcall*)(VOID);
		auto fnEnableHookQueu = (EnableHookQueu_t)addrEnableHookQueu;

		return SpoofCall(fnEnableHookQueu) == 0 ? true : false;
	}

	short Undetected1337GetAsyncKeyState(int key)
	{
		static uintptr_t Undetected1337GetAsyncKeyState_addr;
		if (!Undetected1337GetAsyncKeyState_addr)
			Undetected1337GetAsyncKeyState_addr = MemoryHelper::PatternScanW(module, xorstr_("48 FF ? ? ? ? ? CC CC CC CC CC CC CC CC CC 48 FF ? ? ? ? ? CC CC CC CC CC CC CC CC CC 48 83 EC 28 48 ? ? ? ? ? ? 48 85 C9"));
		if (!Undetected1337GetAsyncKeyState_addr)
			return false;

		auto queuehook = ((short(__fastcall*)(int))(Undetected1337GetAsyncKeyState_addr));
		return SpoofCall(queuehook, key);
	}

	bool EnableHook(uintptr_t pTarget, bool bIsEnabled)
	{
		static uintptr_t addrEnableHook = NULL;

		if (!addrEnableHook)
			addrEnableHook = MemoryHelper::PatternScanW(module, xorstr_("41 56 56 57 53 48 83 EC 28 49 89 CE BF 01 00 00 00 31 C0 F0 ? ? ? ? ? ? ? 74"));

		if (!addrEnableHook)
			return false;

		using EnableHook_t = uint64_t(__fastcall*)(LPVOID, bool);
		auto fnEnableHook = (EnableHook_t)addrEnableHook;

		return SpoofCall(fnEnableHook, (void*)pTarget, bIsEnabled) == 0 ? true : false;
	}


	short SetCursorPos(int x, int y)
	{
		static uintptr_t addrSetCursorPos = NULL;

		if (!addrSetCursorPos)
		{
			addrSetCursorPos = MemoryHelper::PatternScanW(module,
				xorstr_("8A 05 ? ? ? ? 84 C0 74 12"));
		}

		if (!addrSetCursorPos)
			return false;

		using SetCursorPos_t = short(__fastcall*)(int, int);
		auto fnSetCursorPos = (SetCursorPos_t)addrSetCursorPos;

		return fnSetCursorPos(x, y);
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
}*/