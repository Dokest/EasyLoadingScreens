// Fill out your copyright notice in the Description page of Project Settings.


#include "LoadingNotifier.h"

#include "LoadingScreenSubsystem.h"


// Sets default values
ALoadingNotifier::ALoadingNotifier()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}


// Called when the game starts or when spawned
void ALoadingNotifier::BeginPlay()
{
	Super::BeginPlay();

	ULoadingScreenSubsystem::Get(GetWorld())->NotifyLevelLoadingFinished();
}
