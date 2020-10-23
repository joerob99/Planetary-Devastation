// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuGameModeBase.h"

#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

AMainMenuGameModeBase::AMainMenuGameModeBase(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> MainMenuBPClass(TEXT("/Game/UMG/MainMenu_WBP"));
	if (MainMenuBPClass.Class != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found class %s"), *MainMenuBPClass.Class->GetName());
		MainMenuClass = MainMenuBPClass.Class;
	}
}

void AMainMenuGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	if (MainMenuClass != nullptr)
	{
		MainMenu = CreateWidget<UUserWidget>(GetWorld(), MainMenuClass);
		if (MainMenu != nullptr)
		{
			MainMenu->AddToViewport();
		}
	}
}

UUserWidget* AMainMenuGameModeBase::GetMainMenu() const
{
	return MainMenu;
}

