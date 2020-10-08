// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanetResourceComponent.h"

// Sets default values for this component's properties
UPlanetResourceComponent::UPlanetResourceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// 
void UPlanetResourceComponent::InitializeResourceList(TArray<AActor*> GivenResources)
{
	for (auto& Resource : GivenResources) {
		Resources.Add(Resource);
	}

	// Tracks the ratio of resources to health such that
	PlanetResourceRatio = Resources.Num() / StartPlanetHealth;
}

void UPlanetResourceComponent::AddResource(AActor* GivenResource)
{
	Resources.Add(GivenResource);

	GrowPlanet();
}

void UPlanetResourceComponent::RemoveResource(AActor* GivenResource)
{
	Resources.Remove(GivenResource);

	// Slowly kill the planet if there are no more resources available to it
	if (Resources.Num() <= 0) { KillPlanet(); }
	else { HurtPlanet(); }
}

// Starts a growth/hurt loop that affects planet vegetation based on various factors
void UPlanetResourceComponent::IntervalGrowthLoop()
{
	
}

void UPlanetResourceComponent::HurtPlanet()
{

}

void UPlanetResourceComponent::GrowPlanet()
{

}

void UPlanetResourceComponent::KillPlanet()
{

}


// Called every frame
void UPlanetResourceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

