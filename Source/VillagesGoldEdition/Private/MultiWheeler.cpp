// Fill out your copyright notice in the Description page of Project Settings.

#include "MultiWheeler.h"


AMultiWheeler::AMultiWheeler(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UKarNW>(VehicleMovementComponentName))
{
	
}

void AMultiWheeler::FellOutOfWorld(const UDamageType & dmgType)
{
	RedirectFellOutOfWorld();
}
