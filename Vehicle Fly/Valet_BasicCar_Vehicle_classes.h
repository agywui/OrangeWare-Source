// BlueprintGeneratedClass Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C
// Size: 0x2920 (Inherited: 0x1ed0)
struct AValet_BasicCar_Vehicle_C : AFortDagwoodVehicle {
	struct FPointerToUberGraphFrame UberGraphFrame; // 0x1ed0(0x08)
	struct UFortVehicleFuelComponent* FuelComponent; // 0x1ed8(0x08)
	struct UValetLightSpawnerComponent_C* ValetLightSpawnerComponent; // 0x1ee0(0x08)
	struct UChildActorComponent* AudioControllerBP; // 0x1ee8(0x08)
	struct UParticleSystemComponent* FireSystem; // 0x1ef0(0x08)
	struct UBoxComponent* OverlapVolume; // 0x1ef8(0x08)
	float BoostFOVRumbleTimeline_Rumble_4398A5E6444D49F8629D269235124894; // 0x1f00(0x04)
	float BoostFOVRumbleTimeline_FoV_4398A5E6444D49F8629D269235124894; // 0x1f04(0x04)
	enum class ETimelineDirection BoostFOVRumbleTimeline__Direction_4398A5E6444D49F8629D269235124894; // 0x1f08(0x01)
	char pad_1F09[0x7]; // 0x1f09(0x07)
	struct UTimelineComponent* BoostFOVRumbleTimeline; // 0x1f10(0x08)
	float TimeLineBoostFast_JetSparksCounts_23CFE84A48582AA363A21891FC410F04; // 0x1f18(0x04)
	float TimeLineBoostFast_JetFlameHight_23CFE84A48582AA363A21891FC410F04; // 0x1f1c(0x04)
	enum class ETimelineDirection TimeLineBoostFast__Direction_23CFE84A48582AA363A21891FC410F04; // 0x1f20(0x01)
	char pad_1F21[0x7]; // 0x1f21(0x07)
	struct UTimelineComponent* TimeLineBoostFast; // 0x1f28(0x08)
	float TimeLineBoost_JetFlameHight_46B59FC64BBD70FB1C84F292AABA9218; // 0x1f30(0x04)
	enum class ETimelineDirection TimeLineBoost__Direction_46B59FC64BBD70FB1C84F292AABA9218; // 0x1f34(0x01)
	char pad_1F35[0x3]; // 0x1f35(0x03)
	struct UTimelineComponent* TimeLineBoost; // 0x1f38(0x08)
	float Fade_Fade_C0442AEC47AB69188F18FBB055F64424; // 0x1f40(0x04)
	enum class ETimelineDirection Fade__Direction_C0442AEC47AB69188F18FBB055F64424; // 0x1f44(0x01)
	char pad_1F45[0x3]; // 0x1f45(0x03)
	struct UTimelineComponent* Fade; // 0x1f48(0x08)
	float OutOfFuel_Intensity_C83D96E348E80AB3A7B67182D3F6C892; // 0x1f50(0x04)
	enum class ETimelineDirection OutOfFuel__Direction_C83D96E348E80AB3A7B67182D3F6C892; // 0x1f54(0x01)
	char pad_1F55[0x3]; // 0x1f55(0x03)
	struct UTimelineComponent* OutOfFuel; // 0x1f58(0x08)
	struct USoundBase* OnDeathSound; // 0x1f60(0x08)
	float MaxSpeedForAccelFX; // 0x1f68(0x04)
	char pad_1F6C[0x4]; // 0x1f6c(0x04)
	struct AFortPlayerPawn* PassengerPawn; // 0x1f70(0x08)
	struct APlayerController* DrivingPlayerController; // 0x1f78(0x08)
	struct AFortPlayerPawn* DriverPawn; // 0x1f80(0x08)
	struct AFortPlayerPawn* LastDriver; // 0x1f88(0x08)
	struct AFortPlayerPawnAthena* LastHitPlayer; // 0x1f90(0x08)
	bool IgnoreHitLastDriver; // 0x1f98(0x01)
	bool PassengerIsInstigator; // 0x1f99(0x01)
	char pad_1F9A[0x6]; // 0x1f9a(0x06)
	struct FScalableFloat CanLaunchPlayer; // 0x1fa0(0x28)
	struct APlayerController* PassengerPlayerController; // 0x1fc8(0x08)
	struct TArray<struct AFortPlayerPawn*> Passengers; // 0x1fd0(0x10)
	bool Debug_NoCameraShake; // 0x1fe0(0x01)
	char pad_1FE1[0x7]; // 0x1fe1(0x07)
	struct TArray<struct AFortPlayerPawn*> BounceIgnoreList; // 0x1fe8(0x10)
	float DestructionAngle; // 0x1ff8(0x04)
	float MinSpeedToDestroyObjects; // 0x1ffc(0x04)
	float EngineSoundMaxDistance; // 0x2000(0x04)
	float SavedDamageValueForMID; // 0x2004(0x04)
	struct AActor* VehicleHitActor; // 0x2008(0x08)
	struct UParticleSystemComponent* InWaterFX; // 0x2010(0x08)
	struct FGameplayCueParameters GCParamsEmpty; // 0x2018(0xc0)
	struct FGameplayTag HitPlayerCue; // 0x20d8(0x08)
	struct FGameplayTag HitFiendCue; // 0x20e0(0x08)
	struct USoundBase* WaterMovementSound; // 0x20e8(0x08)
	struct USoundBase* InWaterLoopSound; // 0x20f0(0x08)
	struct UParticleSystem* InWaterSplashFX; // 0x20f8(0x08)
	struct UParticleSystem* InWaterLoopingFX; // 0x2100(0x08)
	float AccelRumbleIntensityFalloff; // 0x2108(0x04)
	char pad_210C[0x4]; // 0x210c(0x04)
	struct UParticleSystem* DestroyedFX; // 0x2110(0x08)
	struct UForceFeedbackEffect* MovementForceFeedback; // 0x2118(0x08)
	struct UMatineeCameraShake* Movement_CameraShake; // 0x2120(0x08)
	struct UMatineeCameraShake* Driver_CameraShake; // 0x2128(0x08)
	struct UGameplayEffect* GE_DamageWalls_301; // 0x2130(0x08)
	struct UGameplayEffect* GE_DamageWalls_201; // 0x2138(0x08)
	bool bLocalPlayerADS; // 0x2140(0x01)
	char pad_2141[0x7]; // 0x2141(0x07)
	struct UMatineeCameraShake* BigHit_CameraShake; // 0x2148(0x08)
	struct UForceFeedbackEffect* BigHitForceFeedback; // 0x2150(0x08)
	struct UForceFeedbackEffect* SmallHitForceFeedback; // 0x2158(0x08)
	struct UMatineeCameraShake* SmallHit_CameraShake; // 0x2160(0x08)
	struct UForceFeedbackEffect* SpringCompressionForceFeedback; // 0x2168(0x08)
	struct UMatineeCameraShake* DriverCameraShake; // 0x2170(0x08)
	struct UMatineeCameraShake* OffRoadCamera_Shake; // 0x2178(0x08)
	float OffRoadCameraShakeFalloff; // 0x2180(0x04)
	float OffRoadCameraSpeedForShakes; // 0x2184(0x04)
	float OffRoadNormalizedSpeedForRumble; // 0x2188(0x04)
	float OffRoadCameraMinFrequency; // 0x218c(0x04)
	float OffRoadCameraMaxFrequency; // 0x2190(0x04)
	float OffRoadCameraY_Amp; // 0x2194(0x04)
	float OffRoadCameraZ_Amp; // 0x2198(0x04)
	float OffRoadCameraRot_Amp; // 0x219c(0x04)
	float AccelRumbleIntensityPower; // 0x21a0(0x04)
	float AccelRumbleIntensity; // 0x21a4(0x04)
	bool LargeRumble; // 0x21a8(0x01)
	char pad_21A9[0x7]; // 0x21a9(0x07)
	struct UMatineeCameraShake* OffRoad_CameraShake; // 0x21b0(0x08)
	float VehicleMaxSpeed; // 0x21b8(0x04)
	float ImpactEjectUpVelocity; // 0x21bc(0x04)
	float ImpactEjectForwardVelocity; // 0x21c0(0x04)
	char pad_21C4[0x4]; // 0x21c4(0x04)
	struct UMatineeCameraShake* OutOfFuelCameraShake; // 0x21c8(0x08)
	float MaxSpeedForAccelRumble; // 0x21d0(0x04)
	float MinSkidAmountRequired; // 0x21d4(0x04)
	float TireSkidRumbleFalloff; // 0x21d8(0x04)
	float MinSpeedForTireSkid; // 0x21dc(0x04)
	float MinSpeedForBrakingSkid; // 0x21e0(0x04)
	float MinDamageToEjectDriver; // 0x21e4(0x04)
	struct UParticleSystem* WindshieldBreakFX; // 0x21e8(0x08)
	struct FTimerHandle HandbrakeSmoke; // 0x21f0(0x08)
	struct UMatineeCameraShake* AccelCameraShake; // 0x21f8(0x08)
	struct UMatineeCameraShake* HandbrakeCameraShake; // 0x2200(0x08)
	struct UMatineeCameraShake* Handbrake_CameraShake; // 0x2208(0x08)
	float HandbrakeCameraShakeFalloff; // 0x2210(0x04)
	float HandbrakeCameraSpeedForShakes; // 0x2214(0x04)
	float NormalizedSpeedForRumble; // 0x2218(0x04)
	float HandbrakeCameraMinFrequency; // 0x221c(0x04)
	float HandbrakeCameraMaxFrequency; // 0x2220(0x04)
	float HandbrakeCameraY_Amp; // 0x2224(0x04)
	float HandbrakeCameraZ_Amp; // 0x2228(0x04)
	float HandbrakeCameraRot_Amp; // 0x222c(0x04)
	float FuelLeakPerDrop; // 0x2230(0x04)
	float FuelLeakFrequency; // 0x2234(0x04)
	struct FTimerHandle LeakingFuelTimer; // 0x2238(0x08)
	bool bFuelLeaking; // 0x2240(0x01)
	char pad_2241[0x7]; // 0x2241(0x07)
	struct TArray<enum class EObjectTypeQuery> LeakObjectTrace; // 0x2248(0x10)
	bool bIsOnFire; // 0x2258(0x01)
	char pad_2259[0x3]; // 0x2259(0x03)
	int32_t DripOntoFuelCount; // 0x225c(0x04)
	struct FVector DripDistanceCheck; // 0x2260(0x0c)
	char pad_226C[0x4]; // 0x226c(0x04)
	struct AAthena_PlayerController_C* DamagingPlayerController; // 0x2270(0x08)
	struct AFortPlayerPawn* DamagingPlayerPawn; // 0x2278(0x08)
	struct UGameplayEffect* GE_DamagePlayerHit; // 0x2280(0x08)
	struct UMatineeCameraShake* CameraShakeBoost; // 0x2288(0x08)
	struct UMatineeCameraShake* BoostCameraShake; // 0x2290(0x08)
	struct UParticleSystem* ExplodeFX; // 0x2298(0x08)
	struct UGameplayEffect* GE_RimScrapeDamage; // 0x22a0(0x08)
	float LowFuelThreshold; // 0x22a8(0x04)
	char pad_22AC[0x4]; // 0x22ac(0x04)
	struct USoundBase* LowFuelWarningSound; // 0x22b0(0x08)
	struct USoundBase* OutOfFuelSound_1; // 0x22b8(0x08)
	struct UParticleSystem* PopTireFX; // 0x22c0(0x08)
	struct UParticleSystem* WheelScrapeSparksFX; // 0x22c8(0x08)
	struct FName WheelSocket_FR; // 0x22d0(0x08)
	struct FName WheelSocket_FL; // 0x22d8(0x08)
	struct FName WheelSocket_BR; // 0x22e0(0x08)
	struct FName WheelSocket_BL; // 0x22e8(0x08)
	struct FName WheelSocketBR_Mid; // 0x22f0(0x08)
	struct FName WheelSocketBL_Mid; // 0x22f8(0x08)
	bool MidR_TirePop; // 0x2300(0x01)
	bool MidL_TirePop; // 0x2301(0x01)
	bool IsBigRig; // 0x2302(0x01)
	char pad_2303[0x5]; // 0x2303(0x05)
	struct UMaterialInstanceDynamic* BodyMID; // 0x2308(0x08)
	float DamageValue; // 0x2310(0x04)
	char pad_2314[0x4]; // 0x2314(0x04)
	struct UParticleSystem* WheelScrapeDustFX; // 0x2318(0x08)
	struct FVector LaunchVelocity; // 0x2320(0x0c)
	char pad_232C[0x4]; // 0x232c(0x04)
	struct TArray<struct AActor*> TargetedActors; // 0x2330(0x10)
	struct AFortPawn* ExplodeInstigator; // 0x2340(0x08)
	struct UGameplayEffect* GE_ExplodeBuildingDamage; // 0x2348(0x08)
	struct TArray<enum class EObjectTypeQuery> ObjectArray; // 0x2350(0x10)
	float ExplodeRadius; // 0x2360(0x04)
	char pad_2364[0x4]; // 0x2364(0x04)
	struct UGameplayEffect* GE_ExplodePlayerDamage; // 0x2368(0x08)
	struct UGameplayEffect* GE_ExplodeVehicleDamage; // 0x2370(0x08)
	struct FVector ExplodeVehicleSpin; // 0x2378(0x0c)
	float ExplodeVehicleImpulse; // 0x2384(0x04)
	float Turn Signal Update Frequencey; // 0x2388(0x04)
	float BasePontoonRadiusFront; // 0x238c(0x04)
	float BasePontoonRadiusRear; // 0x2390(0x04)
	float MinPontoonRadiusToSink; // 0x2394(0x04)
	float ReduceRadiusTerTickRear; // 0x2398(0x04)
	float ReduceRadiusTerTickFront; // 0x239c(0x04)
	float ScalePontoonTickRateFront; // 0x23a0(0x04)
	float ScalePontoonTickRateRear; // 0x23a4(0x04)
	float ScaledPontoonRadiusRear; // 0x23a8(0x04)
	float ScaledPontoonRadiusFront; // 0x23ac(0x04)
	struct FTimerHandle ScalePontoonTimerFront; // 0x23b0(0x08)
	struct FTimerHandle ScalePontoonTimerRear; // 0x23b8(0x08)
	float FuelGainPerInteract; // 0x23c0(0x04)
	char pad_23C4[0x4]; // 0x23c4(0x04)
	struct UNiagaraComponent* FX Road Interaction And Exhaust; // 0x23c8(0x08)
	struct FTimerHandle TimerSnapFoamToWaterSurface; // 0x23d0(0x08)
	struct UNiagaraComponent* NS_LargeSplashFX; // 0x23d8(0x08)
	struct UNiagaraComponent* FX_LowFuelSputterSmoke; // 0x23e0(0x08)
	bool Tire_Popped_FL; // 0x23e8(0x01)
	bool Tire_Popped_FR; // 0x23e9(0x01)
	bool Tire_Popped_RL; // 0x23ea(0x01)
	bool Tire_Popped_RR; // 0x23eb(0x01)
	struct FVector Wheel_Scale_Rear; // 0x23ec(0x0c)
	struct FVector Wheel_Scale_Front; // 0x23f8(0x0c)
	struct FVector Tire_Scale_Rear; // 0x2404(0x0c)
	struct FVector Tire_Scale_Front; // 0x2410(0x0c)
	float MinSpeedForDust; // 0x241c(0x04)
	struct FLinearColor FX_Dust_Color_Dirt; // 0x2420(0x10)
	struct FLinearColor FX_Dust_Color_Default; // 0x2430(0x10)
	struct UNiagaraComponent* FX_LeakingFuel; // 0x2440(0x08)
	char pad_2448[0x8]; // 0x2448(0x08)
	struct FTransform WindowTransform_F; // 0x2450(0x30)
	struct FTransform WindowTransform_FL; // 0x2480(0x30)
	struct FTransform WindowTransform_FR; // 0x24b0(0x30)
	struct FTransform WindowTransform_BL; // 0x24e0(0x30)
	struct FTransform WindowTransform_BR; // 0x2510(0x30)
	struct FTransform WindowTransform_B; // 0x2540(0x30)
	bool CanExplodeHack; // 0x2570(0x01)
	bool VehicleImpulseOnExplode; // 0x2571(0x01)
	char pad_2572[0x2]; // 0x2572(0x02)
	float ExplodeSpinThrustMagnitude; // 0x2574(0x04)
	struct UNiagaraSystem* PopTireFXNiagara; // 0x2578(0x08)
	struct UNiagaraSystem* ExplodeFXNiagara; // 0x2580(0x08)
	struct UNiagaraComponent* FX_TireSkid; // 0x2588(0x08)
	float Damage_Stage1; // 0x2590(0x04)
	float Damage_Stage2; // 0x2594(0x04)
	float Damage_Stage3Critical; // 0x2598(0x04)
	float VehicleFallSpeed; // 0x259c(0x04)
	struct UNiagaraSystem* WreckFXNiagara; // 0x25a0(0x08)
	struct ABP_Vehicle_Radio_C* VehicleRadio; // 0x25a8(0x08)
	float LastCollisionTime; // 0x25b0(0x04)
	float MinTimeBetweenCollision; // 0x25b4(0x04)
	float ScrapeImpact_Strength; // 0x25b8(0x04)
	bool isVehicleOccupied?; // 0x25bc(0x01)
	char pad_25BD[0x3]; // 0x25bd(0x03)
	struct FString SportCar; // 0x25c0(0x10)
	struct FString SportCarUpgrade; // 0x25d0(0x10)
	struct FString SemiTruck; // 0x25e0(0x10)
	struct UNiagaraComponent* FX_LeakingFuel_r; // 0x25f0(0x08)
	bool IsInDeepWater; // 0x25f8(0x01)
	char pad_25F9[0x3]; // 0x25f9(0x03)
	int32_t NumWheels; // 0x25fc(0x04)
	struct TArray<float> WheelSpringLength; // 0x2600(0x10)
	float SurfaceChangeTime; // 0x2610(0x04)
	char pad_2614[0x4]; // 0x2614(0x04)
	struct ABP_Valet_AudioController_Parent_C* AudioControllerClass; // 0x2618(0x08)
	float MaxDepthToEject; // 0x2620(0x04)
	char pad_2624[0x4]; // 0x2624(0x04)
	struct AFortWaterBodyActor* WaterBody; // 0x2628(0x08)
	struct FTimerHandle WaterDepthCheckTimer; // 0x2630(0x08)
	float Explosion_CameraShake_Radius; // 0x2638(0x04)
	float SpawnImpactFX_VehicleSpeed; // 0x263c(0x04)
	float SpawnImpactFX_VehicleSpeed_Limit; // 0x2640(0x04)
	float ExplodeImpulseZ_Magnitude; // 0x2644(0x04)
	float MaxSpeedToHandbrakeHaptics; // 0x2648(0x04)
	float ExplodePlayerImpulse; // 0x264c(0x04)
	float ScalePlayerHitImpulseBySpeed; // 0x2650(0x04)
	float ScalePlayerHitImpulseNoDriver; // 0x2654(0x04)
	int32_t RandomMatInt; // 0x2658(0x04)
	char pad_265C[0x4]; // 0x265c(0x04)
	struct TArray<struct UMaterialInterface*> SK_RandomMat2_Array; // 0x2660(0x10)
	struct TArray<struct UMaterialInterface*> SK_RandomMat0_Array; // 0x2670(0x10)
	struct TArray<struct UMaterialInterface*> SK_RandomMat1_Array; // 0x2680(0x10)
	struct UTexture* Diffuse; // 0x2690(0x08)
	struct UTexture* Mask; // 0x2698(0x08)
	struct UTexture* Normal; // 0x26a0(0x08)
	struct UTexture* ScratchGrime; // 0x26a8(0x08)
	struct UTexture* SpecularMask; // 0x26b0(0x08)
	struct UMaterialInstanceDynamic* Mid; // 0x26b8(0x08)
	struct UMaterialInstanceDynamic* DestroyedMID; // 0x26c0(0x08)
	struct FLinearColor Primary Color; // 0x26c8(0x10)
	struct UGameplayEffect* GE_ApplyInValetTag; // 0x26d8(0x08)
	struct FGameplayTagContainer InValetVehicleTag; // 0x26e0(0x20)
	struct UGameplayEffect* GE_ApplyAllowFlippingTag; // 0x2700(0x08)
	struct FGameplayTagContainer VehicleAllowFlippingTag; // 0x2708(0x20)
	struct FScalableFloat HotfixCurieEnabled; // 0x2728(0x28)
	struct UAudioComponent* FuelGainedLoop; // 0x2750(0x08)
	struct USoundBase* GainFuelSound; // 0x2758(0x08)
	float CurrentFuelGainPercent; // 0x2760(0x04)
	char pad_2764[0x4]; // 0x2764(0x04)
	struct UNiagaraComponent* DamageFX; // 0x2768(0x08)
	struct FScalableFloat RagdollEnabled; // 0x2770(0x28)
	struct AFN_RadialForce_C* FN_RadialForce; // 0x2798(0x08)
	struct FScalableFloat Row_ShouldDropLootOnDamage; // 0x27a0(0x28)
	struct FScalableFloat LootDropDamageThresholds; // 0x27c8(0x28)
	int32_t LootDropCurentThreshold; // 0x27f0(0x04)
	struct FName LootOnDamagePackage; // 0x27f4(0x08)
	float LootTossOffset; // 0x27fc(0x04)
	struct UParticleSystem* FX_LootDropOnDamagedSpawn; // 0x2800(0x08)
	float LootTossMin; // 0x2808(0x04)
	struct FGameplayTag Boost_GC; // 0x280c(0x08)
	char pad_2814[0x4]; // 0x2814(0x04)
	struct UNiagaraSystem* Wheel Scrape Sparks FX; // 0x2818(0x08)
	struct UNiagaraSystem* Wheel Scrape Dust FX; // 0x2820(0x08)
	struct UNiagaraComponent* NS_TurboBoost_FX; // 0x2828(0x08)
	struct FRotator BoostFXRotation; // 0x2830(0x0c)
	bool bBoostUsesQuadExhaust; // 0x283c(0x01)
	char pad_283D[0x3]; // 0x283d(0x03)
	float BoostQuadExhaustHorizontalOffset; // 0x2840(0x04)
	float BoostJetLocationOffsetX; // 0x2844(0x04)
	float BoostJetLocationOffsetZ; // 0x2848(0x04)
	float BoostJetFlameHeight; // 0x284c(0x04)
	float BoostJetFlameHeightMax; // 0x2850(0x04)
	bool NewVar_1; // 0x2854(0x01)
	char pad_2855[0x3]; // 0x2855(0x03)
	float WheelWidth; // 0x2858(0x04)
	float WheelWidthBack; // 0x285c(0x04)
	struct FLinearColor ExhaustColor; // 0x2860(0x10)
	float ExhaustScale; // 0x2870(0x04)
	bool BoostCameraActive; // 0x2874(0x01)
	bool IsBoosting; // 0x2875(0x01)
	char pad_2876[0x2]; // 0x2876(0x02)
	float BoostRumbleIntensity; // 0x2878(0x04)
	float MaxBoostFOV; // 0x287c(0x04)
	float HealthPctMissingToShowDmgCrinkle; // 0x2880(0x04)
	float MaxCrinkleSeverity; // 0x2884(0x04)
	struct FScalableFloat ExplosionDamageBuildings; // 0x2888(0x28)
	float CachedExplosionDamageBuildings; // 0x28b0(0x04)
	char pad_28B4[0x4]; // 0x28b4(0x04)
	struct FScalableFloat ExplosionDamagePlayers; // 0x28b8(0x28)
	float CachedExplosionDamagePlayers; // 0x28e0(0x04)
	char pad_28E4[0x4]; // 0x28e4(0x04)
	struct FScalableFloat ExplosionDamageVehicles; // 0x28e8(0x28)
	float CachedExplosionDamageVehicles; // 0x2910(0x04)
	char pad_2914[0x4]; // 0x2914(0x04)
	struct UGameplayEffect* GE_Explode_BuildingDamage; // 0x2918(0x08)

	void ApplyBuildingExplosionDamage(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.ApplyBuildingExplosionDamage // (Public|HasDefaults|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void CacheExplosionDamageValues(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.CacheExplosionDamageValues // (Public|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void Is Driver Restricted By Team Setting(struct AFortPlayerPawn* PlayerPawn, bool& Restricted); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.Is Driver Restricted By Team Setting // (Public|HasOutParms|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void CreateBaseMID(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.CreateBaseMID // (Public|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void CreateDestroyedMIDApply(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.CreateDestroyedMIDApply // (Public|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void GenerateRandomInt(struct TArray<struct UMaterialInterface*>& TargetArray); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.GenerateRandomInt // (Public|HasOutParms|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnRep_RandomMatInt(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnRep_RandomMatInt // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void DamgeStateSetAmount(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.DamgeStateSetAmount // (Public|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void ToggleGlassFX(struct FName AttachPointName, struct FTransform& InTransform); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.ToggleGlassFX // (Public|HasOutParms|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void ToggleDustFX(bool InValue); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.ToggleDustFX // (Public|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void SetFxSettingsForVehicleType(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.SetFxSettingsForVehicleType // (Public|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void TurnSignalsandBrakes(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.TurnSignalsandBrakes // (Public|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void DamageBuildings(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.DamageBuildings // (Public|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	struct FVector CalcImpulseDirection(struct AActor* Vehicle, float Magnitude); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.CalcImpulseDirection // (Public|HasOutParms|BlueprintCallable|BlueprintEvent|BlueprintPure) // @ game+0xccddc0
	void SetFallInstigator(struct AFortPlayerPawnAthena* Pawn); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.SetFallInstigator // (Public|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void Damageable Part Changed(struct FVehicleDamageablePartConfig PartConfig, struct FVehicleDamageablePart Part, bool NewlyDisabled); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.Damageable Part Changed // (Public|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void IsVehicleAccelerating?(float MaxSpeed, bool& Return); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.IsVehicleAccelerating? // (Public|HasOutParms|BlueprintCallable|BlueprintEvent|BlueprintPure) // @ game+0xccddc0
	float CalcAccelRumbleIntensity(float MaxIntensity); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.CalcAccelRumbleIntensity // (Public|HasOutParms|BlueprintCallable|BlueprintEvent|BlueprintPure) // @ game+0xccddc0
	void SendDamageValueToMaterials(float ParameterValue); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.SendDamageValueToMaterials // (Public|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void GetIconPlacement(struct AActor* SelfActor, struct AActor* ViewingActor, struct FVector& OutLocation, struct FVector& OutExtents); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.GetIconPlacement // (Event|Public|HasOutParms|BlueprintCallable|BlueprintEvent|BlueprintPure|Const) // @ game+0xccddc0
	void DestroyOrDamageBuildingPiece(struct ABuildingActor* BuildingActor, bool CheckForHealth, struct UGameplayEffect* GameplayEffectClass, float DestroyThreshold); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.DestroyOrDamageBuildingPiece // (Public|HasDefaults|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void PlayHapticsOnHit(float HitMagnitude); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.PlayHapticsOnHit // (Public|HasDefaults|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void UserConstructionScript(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.UserConstructionScript // (Event|Public|HasDefaults|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OutOfFuel__FinishedFunc(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OutOfFuel__FinishedFunc // (BlueprintEvent) // @ game+0xccddc0
	void OutOfFuel__UpdateFunc(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OutOfFuel__UpdateFunc // (BlueprintEvent) // @ game+0xccddc0
	void Fade__FinishedFunc(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.Fade__FinishedFunc // (BlueprintEvent) // @ game+0xccddc0
	void Fade__UpdateFunc(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.Fade__UpdateFunc // (BlueprintEvent) // @ game+0xccddc0
	void TimeLineBoostFast__FinishedFunc(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.TimeLineBoostFast__FinishedFunc // (BlueprintEvent) // @ game+0xccddc0
	void TimeLineBoostFast__UpdateFunc(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.TimeLineBoostFast__UpdateFunc // (BlueprintEvent) // @ game+0xccddc0
	void TimeLineBoost__FinishedFunc(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.TimeLineBoost__FinishedFunc // (BlueprintEvent) // @ game+0xccddc0
	void TimeLineBoost__UpdateFunc(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.TimeLineBoost__UpdateFunc // (BlueprintEvent) // @ game+0xccddc0
	void BoostFOVRumbleTimeline__FinishedFunc(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.BoostFOVRumbleTimeline__FinishedFunc // (BlueprintEvent) // @ game+0xccddc0
	void BoostFOVRumbleTimeline__UpdateFunc(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.BoostFOVRumbleTimeline__UpdateFunc // (BlueprintEvent) // @ game+0xccddc0
	void OnCurieActive_1D9CDF534780404ABF0AA6893CD541A6(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnCurieActive_1D9CDF534780404ABF0AA6893CD541A6 // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnReady_04DD3D3E4FBD21BFC0E43DAB4B40FA90(struct AGameStateBase* GameState); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnReady_04DD3D3E4FBD21BFC0E43DAB4B40FA90 // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void UpdateMovementCosmeticParameters(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.UpdateMovementCosmeticParameters // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnCollisionHitEffects(struct FVector& HitLocation, struct FVector& HitNormalImpulse, struct FVector& HitFrictionImpulse, struct FVector& HitNormal, struct AActor* HitActor, enum class EPhysicalSurface HitSurfaceType); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnCollisionHitEffects // (BlueprintCosmetic|Event|Public|HasOutParms|BlueprintEvent) // @ game+0xccddc0
	void OnPawnEnterVehicle(struct AFortPlayerPawn* PlayerPawn, int32_t SeatIdx); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnPawnEnterVehicle // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void OnPawnExitVehicle(struct AFortPlayerPawn* PlayerPawn, struct FName ExitSocketName); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnPawnExitVehicle // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void OnDamaged(float Damage, struct FGameplayTagContainer& DamageTags, struct FGameplayEffectContextHandle& EffectContext, struct AController* EventInstigator, struct AActor* DamageCauser); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnDamaged // (Event|Public|HasOutParms|BlueprintEvent) // @ game+0xccddc0
	void Update Damage State(float Damage); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.Update Damage State // (Net|NetMulticast|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnSpringCompression(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnSpringCompression // (Event|Protected|BlueprintEvent) // @ game+0xccddc0
	void LocalPassengerADS(bool IsADS); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.LocalPassengerADS // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void BndEvt__SkeletalMesh_K2Node_ComponentBoundEvent_2_ComponentHitSignature__DelegateSignature(struct UPrimitiveComponent* HitComponent, struct AActor* OtherActor, struct UPrimitiveComponent* OtherComp, struct FVector NormalImpulse, struct FHitResult& Hit); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.BndEvt__SkeletalMesh_K2Node_ComponentBoundEvent_2_ComponentHitSignature__DelegateSignature // (HasOutParms|BlueprintEvent) // @ game+0xccddc0
	void ReceiveBeginPlay(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.ReceiveBeginPlay // (Event|Protected|BlueprintEvent) // @ game+0xccddc0
	void Handle Spring Compression Audio(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.Handle Spring Compression Audio // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnEnteredWaterVolume(struct FVector& WaterSurfacePoint); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnEnteredWaterVolume // (Event|Public|HasOutParms|BlueprintEvent) // @ game+0xccddc0
	void OnExitedWaterVolume(struct FVector& WaterSurfacePoint); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnExitedWaterVolume // (Event|Public|HasOutParms|BlueprintEvent) // @ game+0xccddc0
	void CheckWater(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.CheckWater // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void PawnHitByVehicle(struct AFortPawn* Pawn, struct FVector& ImpactPoint, struct FVector& ImpactNormal, struct FVector LaunchVector); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.PawnHitByVehicle // (Event|Public|HasOutParms|BlueprintEvent) // @ game+0xccddc0
	void OnStopTick(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnStopTick // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void OnHoldExitStarted(struct AFortPawn* ExitingPawn, float ExitDuration); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnHoldExitStarted // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void OnHoldExitStopped(struct AFortPawn* ExitingPawn); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnHoldExitStopped // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void OnHonk(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnHonk // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void OnFireStart(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnFireStart // (Event|Protected|BlueprintEvent) // @ game+0xccddc0
	void OnFireStop(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnFireStop // (Event|Protected|BlueprintEvent) // @ game+0xccddc0
	void OffRoadCameraShake(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OffRoadCameraShake // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OffRoadShakeEnd(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OffRoadShakeEnd // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void StopAccelRumble(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.StopAccelRumble // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void StartAccelRumble(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.StartAccelRumble // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void HandleTireSmoke(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.HandleTireSmoke // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void ActivateTireSmoke(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.ActivateTireSmoke // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void DeactivateTireSmoke(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.DeactivateTireSmoke // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnGainedFuel(float NewPercent); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnGainedFuel // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void EventOutOfFuel(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.EventOutOfFuel // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void StartOutOfGasRumble(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.StartOutOfGasRumble // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void StopOutOfGasRumble(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.StopOutOfGasRumble // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void ManageAccelRumble(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.ManageAccelRumble // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnImpactDamageApplied(float Damage, struct FVector ImpactNormal); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnImpactDamageApplied // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void TireSkid(bool Condition); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.TireSkid // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void SkidRumbleStop(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.SkidRumbleStop // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void SkidRumbleStart(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.SkidRumbleStart // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void BrakingRumbleStart(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.BrakingRumbleStart // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void BrakingRumbleStop(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.BrakingRumbleStop // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnStartHandbrake(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnStartHandbrake // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void OnStopHandbrake(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnStopHandbrake // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void StopHandbrakeHaptics(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.StopHandbrakeHaptics // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void HandbrakeSkid(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.HandbrakeSkid // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void UpdateOffRoadCameraShake(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.UpdateOffRoadCameraShake // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void AccelCameraShakeBegin(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.AccelCameraShakeBegin // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void AccelCameraShakeEnd(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.AccelCameraShakeEnd // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void StartHandbrakeCameraShake(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.StartHandbrakeCameraShake // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void StopHandbrakeCameraShake(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.StopHandbrakeCameraShake // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void UpdateHandbrakeCameraShake(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.UpdateHandbrakeCameraShake // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnFuelTouchedFire(struct AActor* SourceActor); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnFuelTouchedFire // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void BP_OnBoostStarted(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.BP_OnBoostStarted // (Event|Protected|BlueprintEvent) // @ game+0xccddc0
	void BP_OnBoostFinished(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.BP_OnBoostFinished // (Event|Protected|BlueprintEvent) // @ game+0xccddc0
	void StopBoostCameraShake(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.StopBoostCameraShake // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void BoostRumbleStop(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.BoostRumbleStop // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnRimScrapeDamage(int32_t TireIndex); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnRimScrapeDamage // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void OnExplode(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnExplode // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void ResetLastHitPlayer(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.ResetLastHitPlayer // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void ReceiveDestroyed(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.ReceiveDestroyed // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void OnDamageablePartHealthChanged_Event(struct FVehicleDamageablePartConfig& PartConfig, struct FVehicleDamageablePart& Part, bool bNewlyDisabled, bool bNewlyEnabled); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnDamageablePartHealthChanged_Event // (HasOutParms|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void ScalePontoonFront(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.ScalePontoonFront // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void ScalePontoonRear(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.ScalePontoonRear // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnClientBeginAltInteract(struct AFortPawn* Pawn); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnClientBeginAltInteract // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void OnServerAltInteract(struct AFortPawn* Pawn); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnServerAltInteract // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void FX_Init_Settings(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.FX_Init_Settings // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnLeakingFuelStart(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnLeakingFuelStart // (Event|Protected|BlueprintEvent) // @ game+0xccddc0
	void OnLeakingFuelStop(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnLeakingFuelStop // (Event|Protected|BlueprintEvent) // @ game+0xccddc0
	void ExplodeCosmetics(struct AActor* DestroyedActor); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.ExplodeCosmetics // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnEnteredWaterBody(struct AFortWaterBodyActor* WaterBody); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnEnteredWaterBody // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void OnExitedWaterBody(struct AFortWaterBodyActor* WaterBody); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnExitedWaterBody // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void SnapFoamtoWaterSurface(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.SnapFoamtoWaterSurface // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void CE_WaterFX_ResetDeepWaterEffectActivate(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.CE_WaterFX_ResetDeepWaterEffectActivate // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void BrakingSkid(bool Condition); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.BrakingSkid // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void VFX_DamageState(float Damage); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.VFX_DamageState // (Net|NetMulticast|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void FadeoutCosmetics(struct AActor* DestroyedActor); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.FadeoutCosmetics // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void CreateRadio(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.CreateRadio // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void RadioGo(bool Start, int32_t RadioStationIndex); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.RadioGo // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void DestroyRadio(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.DestroyRadio // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void ReceiveEndPlay(enum class EEndPlayReason EndPlayReason); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.ReceiveEndPlay // (Event|Protected|BlueprintEvent) // @ game+0xccddc0
	void SpawnWreckFX(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.SpawnWreckFX // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void CE_PawnEnterVehicleWhileInWater(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.CE_PawnEnterVehicleWhileInWater // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void CE_PawnExitVehicleWhileInWater(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.CE_PawnExitVehicleWhileInWater // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void CE_ResetWaterFXSnapping(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.CE_ResetWaterFXSnapping // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void FX_RemoveFuelLeaking(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.FX_RemoveFuelLeaking // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnSleepStateChanged(bool bAwake); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnSleepStateChanged // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void OnTickAudioController(float DeltaTime); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnTickAudioController // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void PickRandomMaterial(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.PickRandomMaterial // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnStartCriticalHealth(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnStartCriticalHealth // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void CleanupLoopingPooledFX(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.CleanupLoopingPooledFX // (Event|Public|BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void DisolveVehicle(float Fade); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.DisolveVehicle // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnSurfaceTypeVehicleIsOnChanged(enum class EPhysicalSurface SurfaceTypeVehicleIsOn); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnSurfaceTypeVehicleIsOnChanged // (Event|Protected|BlueprintEvent) // @ game+0xccddc0
	void HealthChanged(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.HealthChanged // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void CheckSpeed(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.CheckSpeed // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnTickAudioFade(float FadeParam); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnTickAudioFade // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void DropLootOnDamage(struct AActor* DamagingActor, struct FHitResult HitResult); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.DropLootOnDamage // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void ResetDamageBuildings(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.ResetDamageBuildings // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void DeactivateBoostFX(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.DeactivateBoostFX // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void ActivateBoostFX(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.ActivateBoostFX // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void StopHandbrakeRumble(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.StopHandbrakeRumble // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnCurieContainerInitialized_BP(struct FCurieContainerHandle CurieContainerHandle); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnCurieContainerInitialized_BP // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void ShiftBlip(bool bUpshift); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.ShiftBlip // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void BoostFOV_Rumble(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.BoostFOV_Rumble // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void ReverseBoostTimeline(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.ReverseBoostTimeline // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void UpdateBoostRumble(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.UpdateBoostRumble // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void StopBoostRumble(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.StopBoostRumble // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void BoostCameraReverse(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.BoostCameraReverse // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void StartBoostRumble(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.StartBoostRumble // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void OnWaterTooDeep(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnWaterTooDeep // (Event|Public|BlueprintEvent) // @ game+0xccddc0
	void OnExitLandscape(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnExitLandscape // (Event|Protected|BlueprintEvent) // @ game+0xccddc0
	void OnEnterLandscape(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnEnterLandscape // (Event|Protected|BlueprintEvent) // @ game+0xccddc0
	void OnIsSprintingChanged(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.OnIsSprintingChanged // (Event|Protected|BlueprintEvent) // @ game+0xccddc0
	void StartDriverCameraShake(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.StartDriverCameraShake // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void StopDriverCameraShake(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.StopDriverCameraShake // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void CanHitLastDriver(); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.CanHitLastDriver // (BlueprintCallable|BlueprintEvent) // @ game+0xccddc0
	void ExecuteUbergraph_Valet_BasicCar_Vehicle(int32_t EntryPoint); // Function Valet_BasicCar_Vehicle.Valet_BasicCar_Vehicle_C.ExecuteUbergraph_Valet_BasicCar_Vehicle // (Final|UbergraphFunction|HasDefaults) // @ game+0xccddc0
};

