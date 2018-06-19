// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "VillagesCustomGM.generated.h"

/**
 * 
 */
UCLASS()
class VILLAGESGOLDEDITION_API AVillagesCustomGM : public AGameMode
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable)
		virtual void ReturnToMainMenuHost()  override;

	//UFUNCTION(BlueprintCallable)
		//virtual void GameEnding()  override;
	
	
};
