// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"

#include "KKBaseVehicle.h"

#include "KKWheelSC.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VILLAGESARSENAL_API UKKWheelSC : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UKKWheelSC();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void TurnOn(bool isToTurnOn);

	UPROPERTY(EditDefaultsOnly, Category = "KKVehicleSetup")
		FString WheelName = "Wheel Name";

	UPROPERTY(EditAnywhere, Category = "KKVehicleSetup")
		float SuspensionLength = 50;

	//UPROPERTY(BlueprintReadOnly, Category = "KKVehicleSetup")
		float HoverForceNewton = 0;

	UPROPERTY(EditAnywhere, Category = "KKVehicleSetup")
		bool bIsTurnOn = true;
	
};
