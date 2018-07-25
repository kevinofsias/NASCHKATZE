// Fill out your copyright notice in the Description page of Project Settings.

#include "KKWheelSC.h"

#include "DrawDebugHelpers.h"
#include "CollisionQueryParams.h"




// Sets default values for this component's properties
UKKWheelSC::UKKWheelSC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
}


// Called when the game starts
void UKKWheelSC::BeginPlay()
{
	Super::BeginPlay();

	//Cache Wheel Setting
	parentVehicleClass = Cast<AKKBaseVehicle>(GetOwner());
	if (parentVehicleClass->IsValidLowLevel())
	{
		ParentHoverForceNewton = parentVehicleClass->HoverForceNewton;
		WheelDrivableChannel = parentVehicleClass->DrivableChannel;
		parentVehicleMesh = parentVehicleClass->GetMainMesh();
		//UStaticMeshComponent* parentVehicleMesh = Cast<UStaticMeshComponent>(GetAttachParent());
	}

}


// Called every frame
void UKKWheelSC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bIsTurnOn)
	{
		/* Generate force enough to hover vehicle when all wheel actived  */


		if (parentVehicleMesh->IsValidLowLevel())
		{
			//Prepare Tracing
			FCollisionQueryParams tracingParams;
			tracingParams.bTraceComplex = false;
			tracingParams.bReturnPhysicalMaterial = true;
			FHitResult outHit;

			float mass = parentVehicleMesh->GetMass();
			FVector worldLocation = GetComponentLocation();
			FVector upVector = GetUpVector();

			//Tracing
			bool isHit = GetWorld()->LineTraceSingleByChannel(outHit, worldLocation, worldLocation + (-1 * upVector)*SuspensionLength, WheelDrivableChannel, tracingParams);

			FVector hitVector = outHit.Location - worldLocation;
			float hitVectorLength = hitVector.Size();

			if (isHit)
			{
				bIsTouchingGround = true;
				float actualCompressed = SuspensionLength - outHit.Distance;
				float forceRatio = actualCompressed / SuspensionLength;
				//add force
				parentVehicleMesh->AddForceAtLocation(outHit.ImpactNormal * mass * 100 * ParentHoverForceNewton * forceRatio, worldLocation);
				DrawDebugLine(GetWorld(), worldLocation, worldLocation + (-1 * upVector)*SuspensionLength, FColor::Green, false, 0.001, 0, 2);
			}
			else
			{
				bIsTouchingGround = false;
				DrawDebugLine(GetWorld(), worldLocation, worldLocation + (-1 * upVector)*SuspensionLength, FColor::Red, false, 0.001, 0, 2);
			}




		}
	}
}

void UKKWheelSC::TurnOn(bool bIsToTurnOn)
{
	bIsTurnOn = bIsToTurnOn;
	bIsTouchingGround = !bIsToTurnOn;
}

