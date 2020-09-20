// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlanetaryDevastationMathLibrary.generated.h"

UCLASS()
class PLANETARYDEVASTATION_API UPlanetaryDevastationMathLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static float VMagnitude(const FVector2D& Vector);

	UFUNCTION(BlueprintCallable)
	static void Normalize(FVector2D& Vector);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static float VAngularVelocity(const float& Speed, const float& Radius);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static float VCentripetalAcceleration(const float& Speed, const float& Radius);
	
};
