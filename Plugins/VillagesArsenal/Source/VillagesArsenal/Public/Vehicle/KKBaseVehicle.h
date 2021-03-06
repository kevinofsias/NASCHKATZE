// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "KKBaseVehicle.generated.h"

class UKKWheelSC;

USTRUCT(BlueprintType)
struct FWheelStruct
{
	GENERATED_USTRUCT_BODY()
	UPROPERTY(BlueprintReadOnly, Category = "KKVehicleSetup")
		FString WheelName;
		
	UKKWheelSC* WheelRef;
};

UCLASS()
class VILLAGESARSENAL_API AKKBaseVehicle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AKKBaseVehicle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void PostEditChangeProperty(FPropertyChangedEvent &PropertyChangedEvent) override;



	UPROPERTY(EditAnywhere, Category = "KKVehicleSetup")
		class UStaticMeshComponent* MainMesh;

	UPROPERTY(EditAnywhere, Category = "KKVehicleSetup")
		float MainMeshLinearDamping = 0;

	UPROPERTY(EditAnywhere, Category = "KKVehicleSetup")
		float MainMeshAngularDamping = 0;

	UPROPERTY(EditAnywhere, Category = "KKVehicleSetup")
		float LateralFrictionFactor = 1;

	UPROPERTY(EditAnywhere, Category = "KKVehicleSetup")
		float HoverForceNewton = 0;

	UPROPERTY(EditAnywhere, Category = "KKVehicleSetup")
		TEnumAsByte<ECollisionChannel> DrivableChannel = ECC_WorldStatic;

	UPROPERTY(EditAnywhere, Category = "KKVehicleSetup")
		float BaseWheelFrictionCoeff = 1;

	UPROPERTY(BlueprintReadOnly, Category = "KKVehicleSetup")
		TArray<FWheelStruct> WheelsArray;

	int32 WheelsOnGroundCount = 0;

	UStaticMeshComponent* GetMainMesh();

private :

	void ApplyFrictions(float DeltaTime);
};
