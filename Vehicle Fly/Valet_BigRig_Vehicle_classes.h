// BlueprintGeneratedClass Valet_BigRig_Vehicle.Valet_BigRig_Vehicle_C
// Size: 0x29b0 (Inherited: 0x2920)
struct AValet_BigRig_Vehicle_C : AValet_BasicCar_Vehicle_C {
	struct FPointerToUberGraphFrame UberGraphFrame; // 0x2920(0x08)
	struct UParticleSystemComponent* SmokeLeft_FX; // 0x2928(0x08)
	struct UParticleSystemComponent* SmokeRight_FX; // 0x2930(0x08)
	struct FScalableFloat HotfixScalePontoonTickRateFront_1; // 0x2938(0x28)
	struct FScalableFloat HotfixScalePontoonTickRateRear_1; // 0x2960(0x28)
	int32_t MatIndex; // 0x2988(0x04)
	char pad_298C[0x4]; // 0x298c(0x04)
	struct TArray<struct UMaterialInterface*> SK_RandomMat0_Array_Occluded; // 0x2990(0x10)
	bool IsLocalPlayerPassenger; // 0x29a0(0x01)
	char pad_29A1[0x7]; // 0x29a1(0x07)
	struct AFortPlayerPawn* PawnPassenger; // 0x29a8(0x08)

	void PassengerExit(struct AFortPawn* PlayerPawn); // Function Valet_BigRig_Vehicle.Valet_BigRig_Vehicle_C.PassengerExit // (Public|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void PassengerEnter(struct AFortPlayerPawn* PlayerPawn); // Function Valet_BigRig_Vehicle.Valet_BigRig_Vehicle_C.PassengerEnter // (Public|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void LocalPassengerMatSwap(); // Function Valet_BigRig_Vehicle.Valet_BigRig_Vehicle_C.LocalPassengerMatSwap // (Public|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void UserConstructionScript(); // Function Valet_BigRig_Vehicle.Valet_BigRig_Vehicle_C.UserConstructionScript // (Event|Public|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnEnteredWaterBody(struct AFortWaterBodyActor* WaterBody); // Function Valet_BigRig_Vehicle.Valet_BigRig_Vehicle_C.OnEnteredWaterBody // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void OnPawnEnterVehicle(struct AFortPlayerPawn* PlayerPawn, int32_t SeatIdx); // Function Valet_BigRig_Vehicle.Valet_BigRig_Vehicle_C.OnPawnEnterVehicle // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void OnPawnExitVehicle(struct AFortPlayerPawn* PlayerPawn, struct FName ExitSocketName); // Function Valet_BigRig_Vehicle.Valet_BigRig_Vehicle_C.OnPawnExitVehicle // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void ExecuteUbergraph_Valet_BigRig_Vehicle(int32_t EntryPoint); // Function Valet_BigRig_Vehicle.Valet_BigRig_Vehicle_C.ExecuteUbergraph_Valet_BigRig_Vehicle // (Final|UbergraphFunction) // @ game+0xccddc0
};

