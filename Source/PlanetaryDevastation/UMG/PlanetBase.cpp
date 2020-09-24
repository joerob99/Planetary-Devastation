// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanetBase.h"
#include "PlanetaryDevastation/FunctionLibraries/PlanetaryDevastationMathLibrary.h"
#include "UnrealClient.h"

void UPlanetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	OwningController = GetOwningPlayer();

	GEngine->GameViewport->Viewport->ViewportResizedEvent.AddUObject(this, &UPlanetBase::ResetPlanet);
}

void UPlanetBase::NativeConstruct()
{
	Super::NativeConstruct();

	SetupPlanet();
}

void UPlanetBase::SetupPlanet()
{
	Velocity = InitialDirection * Speed;
	CenterOfScreen = CalculateCenterOfScreen();
	ButtonLocation = CalculateInitialScreenLocation();
	Radius = CalculateOrbitRadius();
}

void UPlanetBase::ResetPlanet(FViewport* Viewport, uint32)
{
	SetupPlanet();
}

void UPlanetBase::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	Orbit();
	Accelerate();
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
	return UPlanetaryDevastationMathLibrary::VMagnitude(ButtonToCenter);
}

void UPlanetBase::Orbit()
{
	ButtonLocation = ButtonLocation + (Velocity * GetWorld()->DeltaTimeSeconds);
	SetPositionInViewport(ButtonLocation);
}

void UPlanetBase::Accelerate()
{
	FVector2D Direction = CenterOfScreen - ButtonLocation;
	UPlanetaryDevastationMathLibrary::Normalize(Direction);
	FVector2D CentripetalAcceleration = UPlanetaryDevastationMathLibrary::VCentripetalAcceleration(Speed, Radius) * Direction;
	Velocity = Velocity + (CentripetalAcceleration * GetWorld()->DeltaTimeSeconds);
}

