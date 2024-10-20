// Fill out your copyright notice in the Description page of Project Settings.


#include "LoadingScreenSubsystem.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "LoadingScreenUserWidget.h"

DEFINE_LOG_CATEGORY(LogLoadingScreenSubsystem);


ULoadingScreenSubsystem* ULoadingScreenSubsystem::Get(const UWorld* World)
{
	return UGameplayStatics::GetGameInstance(World)->GetSubsystem<ULoadingScreenSubsystem>();
}


void ULoadingScreenSubsystem::ShowLoadingScreen(const TSubclassOf<ULoadingScreenUserWidget> LoadingScreenWidget)
{
	LoadingScreen = CreateWidget<ULoadingScreenUserWidget>(GetWorld(), LoadingScreenWidget);
	LoadingScreen->AddToViewport(0);
}


void ULoadingScreenSubsystem::NotifyLevelLoadingFinished()
{
	const FString LevelName = GetWorld()->GetCurrentLevel()->GetName();
	UE_LOG(LogLoadingScreenSubsystem, Error, TEXT("Level [%s] has finished loading"), *LevelName)
	
	RemoveLoadingScreen();
}


void ULoadingScreenSubsystem::NotifyLevelLoadingError(const FString& DebugReason)
{
	UE_LOG(LogLoadingScreenSubsystem, Error, TEXT("Failed to load the level. Reason: %s"), *DebugReason)
	RemoveLoadingScreen();
}


void ULoadingScreenSubsystem::SendLoadingMessage(const FText& Message)
{
	if (LoadingScreen)
	{
		LoadingScreen->AddLoadingMessage(Message);
	}
}


void ULoadingScreenSubsystem::RemoveLoadingScreen()
{
	if (LoadingScreen)
	{
		LoadingScreen->RemoveFromParent();
		LoadingScreen = nullptr;
	}
}
