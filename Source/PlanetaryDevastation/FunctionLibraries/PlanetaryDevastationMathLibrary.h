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
	static float Magnitude(const FVector2D& Vector);
	
};
