// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "KKWheelSC.h"

#include "KKBaseVehicle.generated.h"


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

#if WITH_EDITOR
	UPROPERTY(EditDefaultsOnly, Category = "KKSwitch")
		bool ForceUpdate;
#endif

	UPROPERTY(EditDefaultsOnly, Category = "KKVehicleSetup")
		UStaticMeshComponent* MainMesh;

	UPROPERTY(EditDefaultsOnly, Category = "KKVehicleSetup")
		float MainMeshLinearDamping = 0;

	UPROPERTY(EditDefaultsOnly, Category = "KKVehicleSetup")
		float MainMeshAngularDamping = 0;

	UPROPERTY(EditDefaultsOnly, Category = "KKVehicleSetup")
		float HoverForceNewton = 20;

	UPROPERTY(BlueprintReadOnly, Category = "KKVehicleSetup")
		TArray<FWheelStruct> WheelsArray;
};
