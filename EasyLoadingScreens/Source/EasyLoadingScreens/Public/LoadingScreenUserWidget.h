// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoadingScreenUserWidget.generated.h"

/**
 * Loading screen parent widget to use on all loading screens.
 * Allows the display of loading messages through the use of the overrideable (C++/BP)
 *  ULoadingScreenUserWidget::AddLoadingMessage
 */
UCLASS(Abstract)
class EASYLOADINGSCREENS_API ULoadingScreenUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	/** Called by the LoadingScreenSubsystem whenever a message is sent */
	UFUNCTION(BlueprintNativeEvent)
	void AddLoadingMessage(const FText& LoadingMessage);
	virtual void AddLoadingMessage_Implementation(const FText& LoadingMessage);
};
