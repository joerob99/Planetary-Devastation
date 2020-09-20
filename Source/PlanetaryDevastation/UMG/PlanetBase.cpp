// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanetBase.h"
#include "PlanetaryDevastation/FunctionLibraries/PlanetaryDevastationMathLibrary.h"

void UPlanetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	OwningController = GetOwningPlayer();
}

void UPlanetBase::NativeConstruct()
{
	Super::NativeConstruct();

	CenterOfScreen = CalculateCenterOfScreen();
	ButtonLocation = CalculateInitialScreenLocation();
	Radius = CalculateOrbitRadius();
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

FVector2D UPlanetBase::CalculateInitialScreenLocation() const
{
	int ViewportXSize = 0.0f;
	int ViewportYSize = 0.0f;
	if (OwningController)
	{
		OwningController->GetViewportSize(ViewportXSize, ViewportYSize);
	}
	return FVector2D(ViewportXSize * AnchorXPosition, ViewportYSize * AnchorYPosition);
}

float UPlanetBase::CalculateOrbitRadius() const
{
	/** Vector pointing from the button to the center of the screen. */
	FVector2D ButtonToCenter = CenterOfScreen - ButtonLocation;
	return UPlanetaryDevastationMathLibrary::Magnitude(ButtonToCenter);
}

