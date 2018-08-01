// Fill out your copyright notice in the Description page of Project Settings.

#include "KKBaseGameInstance.h"

void UKKBaseGameInstance::Init()
{
	Super::Init();

	//Binding Events
	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UKKBaseGameInstance::BeginLoadingScreen);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UKKBaseGameInstance::EndLoadingScreen);
}

void UKKBaseGameInstance::BeginLoadingScreen(const FString& MapName)
{
	if (!IsRunningDedicatedServer())
	{
		FLoadingScreenAttributes LoadingScreen;
		LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;
		LoadingScreen.MinimumLoadingScreenDisplayTime = NextMinimumLoadingScreenTime;
		if (!NextLoadingScreenWidget)
		{
			LoadingScreen.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget();
			GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
		}
		else
		{   
			CurrentLoadingScreenWidget = CreateWidget<UUserWidget>(this, NextLoadingScreenWidget);
			LoadingScreen.WidgetLoadingScreen = CurrentLoadingScreenWidget->TakeWidget();
			GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
		}
		
		//Implement in Blueprint
		LoadingScreenLoaded(MapName, CurrentLoadingScreenWidget);
		
		
	}
}

void UKKBaseGameInstance::EndLoadingScreen(UWorld * InLoadedWorld)
{
}
