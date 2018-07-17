// Fill out your copyright notice in the Description page of Project Settings.

#include "KKWheelSC.h"


// Sets default values for this component's properties
UKKWheelSC::UKKWheelSC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UKKWheelSC::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UKKWheelSC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bIsTurnOn)
	{
		UStaticMeshComponent* parentVehicleMesh = Cast<UStaticMeshComponent>(GetAttachParent());
		if (parentVehicleMesh->IsValidLowLevel())
		{
			parentVehicleMesh->AddForce(FVector(99999,99999,99999));
		}
	}
}

void UKKWheelSC::TurnOn(bool isToTurnOn)
{
	bIsTurnOn = isToTurnOn;
}

