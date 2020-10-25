// Fill out your copyright notice in the Description page of Project Settings.


#include "PDPlayerController.h"

#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

APDPlayerController::APDPlayerController()
{
}

void APDPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (PauseMenuClass)
	{
		PauseMenu = CreateWidget<UUserWidget>(GetWorld(), PauseMenuClass);
	}
}

