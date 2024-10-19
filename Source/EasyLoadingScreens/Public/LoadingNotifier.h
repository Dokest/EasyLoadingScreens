// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LoadingNotifier.generated.h"


/**
 * Utility class that notifies the ULoadingScreenSubsystem whenever the level is loaded.
 * This actor should be placed on all levels where ULoadingScreenSubsystem will be used.
 */
UCLASS()
class EASYLOADINGSCREENS_API ALoadingNotifier : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALoadingNotifier();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
