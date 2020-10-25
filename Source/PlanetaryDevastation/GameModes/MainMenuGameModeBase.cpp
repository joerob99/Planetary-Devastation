// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuGameModeBase.h"

#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

AMainMenuGameModeBase::AMainMenuGameModeBase()
{
}

void AMainMenuGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	if (MainMenuClass)
	{
		MainMenu = CreateWidget<UUserWidget>(GetWorld(), MainMenuClass);
		if (MainMenu)
		{
			MainMenu->AddToViewport();
		}
	}
}

UUserWidget* AMainMenuGameModeBase::GetMainMenu() const
{
	return MainMenu;
}

