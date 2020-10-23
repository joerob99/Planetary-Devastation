// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenuGameModeBase.generated.h"

/**
* Game mode base is the best class to add UMG references.
* The level BP is difficult to override in C++.
* & the game instance would cause the references to persist across other levels, using up space.
*/
UCLASS()
class PLANETARYDEVASTATION_API AMainMenuGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMainMenuGameModeBase(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UMG")
	UUserWidget* GetMainMenu() const;

protected:
	virtual void BeginPlay() override;

private:
	TSubclassOf<UUserWidget> MainMenuClass = nullptr;

	UPROPERTY()
	UUserWidget* MainMenu = nullptr;
	
};
