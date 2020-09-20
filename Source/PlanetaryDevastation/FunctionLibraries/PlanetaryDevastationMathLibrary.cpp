// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanetaryDevastationMathLibrary.h"

float UPlanetaryDevastationMathLibrary::Magnitude(const FVector2D& Vector)
{
	const float XSquared = FMath::Square(Vector.X);
	const float YSquared = FMath::Square(Vector.Y);
	return FMath::Sqrt(XSquared + YSquared);
}

