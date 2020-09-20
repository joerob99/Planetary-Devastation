// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanetBase.h"

void UPlanetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	OwningController = GetOwningPlayer();
}

void UPlanetBase::NativeConstruct()
{
	Super::NativeConstruct();

	CenterOfScreen = CalculateCenterOfScreen();
}

FVector2D UPlanetBase::CalculateCenterOfScreen() const
{
	int ViewportXSize = 0.0f;
	int ViewportYSize = 0.0f;
	if (OwningController)
	{
		OwningController->GetViewportSize(ViewportXSize, ViewportYSize);
	}
	return FVector2D(ViewportXSize * 0.5f, ViewportYSize * 0.5f);
}

