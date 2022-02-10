/*
int sigs() {
	UWorld = MemoryHelper::PatternScan(xorstr_("48 8B 05 ? ? ? ? 4D 8B C2"));
	UWorld = RelativeAddress(UWorld, 7);

	FreeFn = MemoryHelper::PatternScan(xorstr_("48 85 C9 0F 84 ? ? ? ? 53 48 83 EC 20 48 89 7C 24 30 48 8B D9 48 8B 3D ? ? ? ? 48 85 FF 0F 84 ? ? ? ? 48 8B 07 4C 8B 40 30 48 8D 05 ? ? ? ? 4C 3B C0"));
	ProjectWorldToScreen = MemoryHelper::PatternScan(xorstr_("E8 ? ? ? ? 41 88 07 48 83 C4 30"));
	ProjectWorldToScreen = RelativeAddress(ProjectWorldToScreen, 5);

	LineOfS = MemoryHelper::PatternScan(xorstr_("E8 ? ? ? ? 48 8B 0D ? ? ? ? 33 D2 40 8A F8"));
	LineOfS = RelativeAddress(LineOfS, 5);

	GetNameByIndex = MemoryHelper::PatternScan(xorstr_("48 89 5C 24 ? 48 89 74 24 ? 55 57 41 56 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 45 33 F6 48 8B F2 44 39 71 04 0F 85 ? ? ? ? 8B 19 0F B7 FB E8 ? ? ? ? 8B CB 48 8D 54 24"));
	BoneMatrix = MemoryHelper::PatternScan(xorstr_("E8 ? ? ? ? 48 8B 47 30 F3 0F 10 45"));
	BoneMatrix = RelativeAddress(BoneMatrix, 5);

	//addr = MemoryHelper::PatternScan(xorstr_("\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\xD9\x41\x8B\xF0\x48\x8B\x49\x30\x48\x8B\xFA\xE8\x00\x00\x00\x00\xBA\x00\x00\x00\x00\x48\x8B\xC8"), xorstr_("xxxx?xxxx?xxxxxxxxxxxxxxxxxxx????x????xxx"));

	//auto SpreadAddr = MemoryHelper::PatternScan(xorstr_("E8 ? ? ? ? 48 8D 4B 28 E8 ? ? ? ? 48 8B C8"));
	//SpreadAddr = RVA(SpreadAddr, 5);
	//HookHelper::InsertHook(SpreadAddr, (uintptr_t)SpreadHook, (uintptr_t)&Spread);
	//SpreadCaller = (PVOID)(MemoryHelper::PatternScan(xorstr_("0F 57 D2 48 8D 4C 24 ? 41 0F 28 CC E8 ? ? ? ? 48 8B 4D B0 0F 28 F0 48 85 C9")));

	// CalculateShot
	//auto CalcShotAddr = MemoryHelper::PatternScan(xorstr_("48 8B C4 48 89 58 18 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 48 FE ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 44 0F 29 40 ? 44 0F 29 48 ? 44 0F 29 90 ? ? ? ? 44 0F 29 98 ? ? ? ? 44 0F 29 A0 ? ? ?"));
	//HookHelper::InsertHook(CalcShotAddr, (uintptr_t)CalculateShotHook, (uintptr_t)&CalculateShot);
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

//fNamePool = MemoryHelper::PatternScan(xorstr_("74 09 48 8D 15 ? ? ? ? EB 16"));

	//auto GetWeaponStatsAddr = MemoryHelper::PatternScan(xorstr_("48 83 EC 58 48 8B 91 ? ? ? ? 48 85 D2 0F 84 ? ? ? ? F6 81 ? ? ? ? ? 74 10 48 8B 81 ? ? ? ? 48 85 C0 0F 85 ? ? ? ? 48 8B 8A ? ? ? ? 48 89 5C 24 ? 48 8D 9A ? ? ? ? 48 85 C9"));
	//GetWeaponStats = reinterpret_cast<decltype(GetWeaponStats)>(GetWeaponStatsAddr);

	//addr = MemoryHelper::PatternScan(xorstr_("\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\xD9\x41\x8B\xF0\x48\x8B\x49\x30\x48\x8B\xFA\xE8\x00\x00\x00\x00\xBA\x00\x00\x00\x00\x48\x8B\xC8"), xorstr_("xxxx?xxxx?xxxxxxxxxxxxxxxxxxx????x????xxx"));

	//auto SpreadAddr = MemoryHelper::PatternScan(xorstr_("E8 ? ? ? ? 48 8D 4B 28 E8 ? ? ? ? 48 8B C8"));
	//SpreadAddr = RVA(SpreadAddr, 5);
	//HookHelper::InsertHook(SpreadAddr, (uintptr_t)SpreadHook, (uintptr_t)&Spread);
	//SpreadCaller = (PVOID)(MemoryHelper::PatternScan(xorstr_("0F 57 D2 48 8D 4C 24 ? 41 0F 28 CC E8 ? ? ? ? 48 8B 4D B0 0F 28 F0 48 85 C9")));

	//CalculateShot
	//auto CalcShotAddr = MemoryHelper::PatternScan(xorstr_("48 8B C4 48 89 58 18 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 48 FE ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 44 0F 29 40 ? 44 0F 29 48 ? 44 0F 29 90 ? ? ? ? 44 0F 29 98 ? ? ? ? 44 0F 29 A0 ? ? ?"));
	//HookHelper::InsertHook(CalcShotAddr, (uintptr_t)CalculateShotHook, (uintptr_t)&CalculateShot);