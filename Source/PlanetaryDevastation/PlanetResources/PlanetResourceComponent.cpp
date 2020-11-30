// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanetResourceComponent.h"
#include "Kismet/GameplayStatics.h"

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

	// Tracks the ratio of resources to health
	PlanetResourceRatio = Resources.Num() / StartPlanetHealth;

	// Default values for debugging
	if (PlanetResourceRatio <= 0.0) { PlanetResourceRatio = 0.5; }
}

void UPlanetResourceComponent::InitializeAlienList(TArray<AActor*> GivenAliens)
{
	for (auto& Alien : GivenAliens) {
		Aliens.Add(Alien);
	}

	// Tracks the ratio of resources to health
	//PlanetResourceRatio = Resources.Num() / StartPlanetHealth;
}

void UPlanetResourceComponent::AddResource(AActor* GivenResource)
{
	Resources.Add(GivenResource);
}

void UPlanetResourceComponent::RemoveResource(AActor* GivenResource)
{
	Resources.Remove(GivenResource);
	//GivenResource->Destroy();
}

void UPlanetResourceComponent::AddAlien(AActor* GivenAlien)
{
	Aliens.Add(GivenAlien);
}

void UPlanetResourceComponent::RemoveAlien(AActor* GivenAlien)
{
	Aliens.Remove(GivenAlien);
	//GivenAlien->Destroy();
}

int32 UPlanetResourceComponent::GetPlanetHealth() {return CurrentPlanetHealth;}
bool UPlanetResourceComponent::GetIsHomePlanet() {return IsHomePlanet;}
int32 UPlanetResourceComponent::GetAlienNum() { return Aliens.Num(); }
int32 UPlanetResourceComponent::GetResourceNum() { return Resources.Num(); }
FString UPlanetResourceComponent::GetPlanetName() {return PlanetName;}

// Starts a growth/hurt loop that affects planet vegetation based on various factors
void UPlanetResourceComponent::IntervalGrowthLoop()
{
	// If the planet isn't currently destroyed, set a timer to call growth and hurt events
	if (!PlanetIsDestroyed) {
		GetWorld()->GetTimerManager().SetTimer(PlanetGrowTimerHandle, this, &UPlanetResourceComponent::GrowPlanet, PlanetHurtTimer / 2.0, false);
		GetWorld()->GetTimerManager().SetTimer(PlanetHurtTimerHandle, this, &UPlanetResourceComponent::HurtPlanet, PlanetHurtTimer, false);
	}
}

void UPlanetResourceComponent::HurtPlanet()
{
	CurrentPlanetHealth -= Aliens.Num();

	// Clear all timers so that they can be used again
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);

	// Either kill the planet or re-loop
	if (CurrentPlanetHealth <= MinPlanetHealth) { KillPlanet(); }
	else { IntervalGrowthLoop(); }
}

void UPlanetResourceComponent::GrowPlanet()
{
	CurrentPlanetHealth += Resources.Num();

	if (CurrentPlanetHealth > MaxPlanetHealth && CurrentPlanetHealth < MaxPlanetHealth * 2.0) {
		// Possibly do something in the future to increase or inhibit growth based on how much it goes over the planet's
		// MaxPlanetHealth for each growth cycle
	}
}

void UPlanetResourceComponent::KillPlanet()
{
	// Destroy planet's physical form and explode
	CurrentPlanetHealth = MinPlanetHealth;
	PlanetIsDestroyed = true;

	// Return to the main menu if the world blows up
	if (IsHomePlanet) { UGameplayStatics::OpenLevel(GetWorld(), "MainMenu"); }
}


// Called every frame
void UPlanetResourceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

