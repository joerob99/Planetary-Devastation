// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlanetBase.generated.h"

class FViewport;

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
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:
	APlayerController* OwningController = nullptr;

private:
	/** Setup the necessary variables to calculate the orbit position. */
	void SetupPlanet();
	
	/** The planet needs to reset it's position when the viewport size changes. */
	void ResetPlanet(FViewport* Viewport, uint32);

	FVector2D CenterOfScreen = FVector2D(0.0f);
	FVector2D CalculateCenterOfScreen() const;

	FVector2D ButtonLocation = FVector2D(0.0f);
	FVector2D CalculateInitialScreenLocation() const;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "0.0", ClampMax = "1.0"), Category = "Movement")
	float AnchorXPosition = 0.6f;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "0.0", ClampMax = "1.0"), Category = "Movement")
	float AnchorYPosition = 0.5f;

	float Radius;
	float CalculateOrbitRadius() const;

	/** Rotate around the center of the screen. */
	void Orbit();

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed = 10.0f;

	/** Needs to be a unit vector. */
	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector2D InitialDirection = FVector2D(0.0f, -1.0f);

	FVector2D Velocity = FVector2D(0.0f, 0.0f);

	void Accelerate();
	
};
