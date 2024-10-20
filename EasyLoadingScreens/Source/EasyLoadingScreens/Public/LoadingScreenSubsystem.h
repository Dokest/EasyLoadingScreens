// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "LoadingScreenSubsystem.generated.h"


class ULoadingScreenUserWidget;


DECLARE_LOG_CATEGORY_EXTERN(LogLoadingScreenSubsystem, Log, All);


/**
 * Subsystem to manage the loading screen:
 * - Allows to show/hide an "ULoadingScreenUserWidget",
 * - Allows to send messages to the Widget via the ULoadingScreenSubsystem::SendLoadingMessage method.
 * - The loading screen widget is removed automatically by a ALoadingNotifier (if used)
 *		or manually by calling ULoadingScreenSubsystem::NotifyLevelLoadingFinished
 */
UCLASS()
class EASYLOADINGSCREENS_API ULoadingScreenSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:

	/** Widget to show when loading */
	UPROPERTY()
	ULoadingScreenUserWidget* LoadingScreen;

public:

	/** Returns an instance of ULoadingScreenSubsystem from the GameInstance */
	static ULoadingScreenSubsystem* Get(const UWorld* World);

	/** Shows the loading screen */
	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"), Category="Loading Screens")
	void ShowLoadingScreen(const TSubclassOf<ULoadingScreenUserWidget> LoadingScreenWidget);

	/** Removes the LoadingScreen from the viewport */
	UFUNCTION(BlueprintCallable, Category="Loading Screens")
	void NotifyLevelLoadingFinished();

	/** Removes the LoadingScreen from the viewport and logs an error message */
	UFUNCTION(BlueprintCallable, Category="Loading Screens")
	void NotifyLevelLoadingError(const FString& DebugReason);

	/** Sends a message to display in the LoadingScreen */
	UFUNCTION(BlueprintCallable, Category="Loading Screens")
	void SendLoadingMessage(const FText& Message);

private:

	/** Removes the loading screen widget from the viewport (and possibly destroys it) */
	void RemoveLoadingScreen();
};
