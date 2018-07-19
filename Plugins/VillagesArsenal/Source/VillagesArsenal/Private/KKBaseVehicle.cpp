// Fill out your copyright notice in the Description page of Project Settings.

#include "KKBaseVehicle.h"

#include "KKWheelSC.h"


// Sets default values
AKKBaseVehicle::AKKBaseVehicle()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MainMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MainMesh"));
	RootComponent = MainMesh;
	MainMesh->SetSimulatePhysics(true);
	MainMesh->SetLinearDamping(MainMeshLinearDamping);
	MainMesh->SetAngularDamping(MainMeshAngularDamping);

}

// Called when the game starts or when spawned
void AKKBaseVehicle::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AKKBaseVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AKKBaseVehicle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AKKBaseVehicle::PostEditChangeProperty(FPropertyChangedEvent & PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);


	if (PropertyChangedEvent.Property->IsValidLowLevel())
	{
		if (PropertyChangedEvent.Property->GetName() == "ForceUpdate")
		{
			//update vehicle setup
			//clear WheelsArray first
			WheelsArray.Empty();
			TArray<UKKWheelSC*> wheelArrayRef;
			this->GetComponents<UKKWheelSC>(wheelArrayRef);
			for (UKKWheelSC* wheel : wheelArrayRef)
			{
				if (wheel->IsValidLowLevel())
				{
					FWheelStruct wheelStruct;
					wheelStruct.WheelName = wheel->WheelName;
					wheelStruct.WheelRef = wheel;
					WheelsArray.Add(wheelStruct);
				}
			}
		}

		/*
		if (PropertyChangedEvent.Property->GetName() == "MainMeshLinearDamping")
		{
			MainMesh->SetLinearDamping(MainMeshLinearDamping);
		}

		if (PropertyChangedEvent.Property->GetName() == "MainMeshAngularDamping")
		{
			MainMesh->SetAngularDamping(MainMeshAngularDamping);
		}
		*/

	}


}

