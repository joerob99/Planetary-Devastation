// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanetaryDevastationMathLibrary.h"

float UPlanetaryDevastationMathLibrary::VMagnitude(const FVector2D& Vector)
{
	const float XSquared = FMath::Square(Vector.X);
	const float YSquared = FMath::Square(Vector.Y);
	return FMath::Sqrt(XSquared + YSquared);
}

void UPlanetaryDevastationMathLibrary::Normalize(FVector2D& Vector)
{
	float Magnitude = VMagnitude(Vector);
	if (Magnitude <= 0.0f)
	{
		Vector = FVector2D(0.0f);
	}
	else
	{
		Vector = (1.0f / Magnitude) * Vector;
	}
}

float UPlanetaryDevastationMathLibrary::VAngularVelocity(const float& Speed, const float& Radius)
{
	if (Radius <= 0.0f)
	{
		return 0.0f;
	}
	else
	{
		return Speed / Radius;
	}
}

float UPlanetaryDevastationMathLibrary::VCentripetalAcceleration(const float& Speed, const float& Radius)
{
	float AngularVelocity = VAngularVelocity(Speed, Radius);
	return FMath::Square(AngularVelocity) * Radius;
}

