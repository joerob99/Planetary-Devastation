// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlanetBase.generated.h"

/**
* Base class for planet buttons.
* Handles rotating widget around the center of the screen.
*/
UCLASS()
class PLANETARYDEVASTATION_API UPlanetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;

protected:
	APlayerController* OwningController = nullptr;

private:
	FVector2D CenterOfScreen = FVector2D(0.0f);
	FVector2D CalculateCenterOfScreen() const;
	
};
