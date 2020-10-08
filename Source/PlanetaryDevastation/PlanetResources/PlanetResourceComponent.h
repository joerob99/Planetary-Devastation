// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlanetResourceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PLANETARYDEVASTATION_API UPlanetResourceComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlanetResourceComponent();

protected:

	UFUNCTION(BlueprintCallable, Category="Planet")
	virtual void InitializeResourceList(TArray<AActor*> GivenResources);

	UFUNCTION(BlueprintCallable, Category="Planet")
	virtual void AddResource(AActor* GivenResource);

	UFUNCTION(BlueprintCallable, Category="Planet")
	virtual void RemoveResource(AActor* GivenResource);

	// Starts a growth/hurt loop that affects planet vegetation based on various factors
	virtual void IntervalGrowthLoop();

	UFUNCTION(BlueprintCallable, Category = "Planet")
	virtual void HurtPlanet();

	UFUNCTION(BlueprintCallable, Category = "Planet")
	virtual void GrowPlanet();

	UFUNCTION(BlueprintCallable, Category = "Planet")
	virtual void KillPlanet();

private:
	// All of the resources confined within the planet
	TArray<AActor*> Resources;

	UPROPERTY(EditAnywhere, Category="Planet")
	FString PlanetName;

	UPROPERTY(EditAnywhere, Category="Planet")
	int32 MaxPlanetHealth = 100;

	UPROPERTY(EditAnywhere, Category="Planet")
	int32 MinPlanetHealth = 0;

	UPROPERTY(EditAnywhere, Category = "Planet")
	int32 StartPlanetHealth = 50;

	// Planet resource to health ratio determined by initial resources
	int32 PlanetResourceRatio;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
