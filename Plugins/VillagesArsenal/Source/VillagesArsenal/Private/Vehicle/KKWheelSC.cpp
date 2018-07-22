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

	//Cache Wheel Setting
	AKKBaseVehicle* parentVehicleClass = Cast<AKKBaseVehicle>(GetOwner());
	if (parentVehicleClass->IsValidLowLevel())
	{
		HoverForceNewton = parentVehicleClass->HoverForceNewton;
		BaseWheelFrictionCoeff = parentVehicleClass->BaseWheelFrictionCoeff;

	}
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
			
			
			
			

			FCollisionQueryParams tracingParams;
			tracingParams.bTraceComplex = false;
			tracingParams.bReturnPhysicalMaterial = true;
			FHitResult outHit;

			float mass = parentVehicleMesh->GetMass();
			FVector worldLocation = GetComponentLocation();
			FVector localLocation = RelativeLocation;
			FVector upVector = GetUpVector();

			bool isHit = GetWorld()->LineTraceSingleByChannel(outHit, worldLocation, worldLocation + (-1 * upVector)*SuspensionLength, ECC_GameTraceChannel2, tracingParams);

			FVector hitVector = outHit.Location - worldLocation;
			float hitVectorLength = hitVector.Size();
			//float actualCompressed = SuspensionLength - hitVectorLength;

			if (isHit)
			{
				float actualCompressed = SuspensionLength - outHit.Distance;
				float forceRatio = actualCompressed / SuspensionLength;
				float finalDirection = FMath::Abs(FVector::DotProduct(hitVector, upVector));
				//parentVehicleMesh->AddForceAtLocationLocal(upVector*mass*98*ForceNewton*forceRatio, localLocation);
				parentVehicleMesh->AddForceAtLocationLocal(upVector*mass * 98 * HoverForceNewton*forceRatio, localLocation);
				DrawDebugLine(GetWorld(), worldLocation, worldLocation + (-1 * upVector)*SuspensionLength, FColor::Green, false, 0.001, 0, 2);
			}
			else
			{
				DrawDebugLine(GetWorld(), worldLocation, worldLocation + (-1 * upVector)*SuspensionLength, FColor::Red, false, 0.001, 0, 2);
			}

			

			
		}
	}
}

void UKKWheelSC::TurnOn(bool isToTurnOn)
{
	bIsTurnOn = isToTurnOn;
}

void UKKWheelSC::applyFrictions()
{
	FVector velocity = ComponentVelocity;
}

