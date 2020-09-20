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
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:
	APlayerController* OwningController = nullptr;

private:
	FVector2D CenterOfScreen = FVector2D(0.0f);
	FVector2D CalculateCenterOfScreen() const;

	FVector2D ButtonLocation = FVector2D(0.0f);
	FVector2D CalculateInitialScreenLocation() const;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float AnchorXPosition = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float AnchorYPosition = 0.0f;

	float Radius;
	float CalculateOrbitRadius() const;

	/** Rotate around the center of the screen. */
	void Orbit();

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed = 10.0f;

	FVector2D Velocity = FVector2D(0.0f);

	void Accelerate();
	
};
