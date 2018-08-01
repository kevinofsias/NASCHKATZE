// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "MoviePlayer.h"
#include "Runtime/UMG/Public/Components/Widget.h"

#include "KKBaseGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class VILLAGESARSENAL_API UKKBaseGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

		virtual void Init() override;

	UFUNCTION()
		void BeginLoadingScreen(const FString& MapName);
	UFUNCTION()
		void EndLoadingScreen(UWorld* InLoadedWorld);
	UFUNCTION(BlueprintImplementableEvent)
		void LoadingScreenLoaded(const FString& MapName, UUserWidget* CurrentLoadingScreenWidget);

	UPROPERTY(EditAnywhere, Category = "KKLoadingScreen")
		TSubclassOf<UUserWidget> NextLoadingScreenWidget;

	UPROPERTY(BlueprintReadOnly)
	UUserWidget* CurrentLoadingScreenWidget = 0;

	UPROPERTY(EditAnywhere, Category = "KKLoadingScreen")
		float NextMinimumLoadingScreenTime = 3.0f;
	
};
