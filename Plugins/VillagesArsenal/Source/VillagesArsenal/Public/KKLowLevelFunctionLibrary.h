// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Slate/WidgetRenderer.h"
#include "Runtime/Engine/Classes/Engine/TextureRenderTarget2D.h"


#include "Kismet/BlueprintFunctionLibrary.h"
#include "KKLowLevelFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class VILLAGESARSENAL_API UKKLowLevelFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "KKLowLevel")
		static UTexture2D* TextureFromWidget(UUserWidget *const Widget, const FVector2D &DrawSize);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "KKReplication")
		static ENetRole GetActorRole(const AActor* Actor);

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", Keywords = "KKShutDown"))
		static void ShutDown();
	
	
};
