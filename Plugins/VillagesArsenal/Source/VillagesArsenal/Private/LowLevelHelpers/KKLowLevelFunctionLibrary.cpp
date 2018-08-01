// Fill out your copyright notice in the Description page of Project Settings.

#include "KKLowLevelFunctionLibrary.h"


ENetRole UKKLowLevelFunctionLibrary::GetActorRole(const AActor * Actor)
{
	if (IsValid(Actor))
	{
		return Actor->Role;
	}

	return ENetRole::ROLE_None;
}

void UKKLowLevelFunctionLibrary::ShutDown()
{
	GIsRequestingExit = true;
}
