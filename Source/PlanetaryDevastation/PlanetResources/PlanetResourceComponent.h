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

	UPROPERTY(EditAnywhere, Category = "Planet", BlueprintReadWrite)
	bool IsHomePlanet = false;

	// Track whether the planet has been 'killed' yet
	UPROPERTY(Category = "Planet", BlueprintReadWrite)
	bool PlanetIsDestroyed = false;

	// Track whether the planet has been 'killed' yet
	UPROPERTY(Category = "Planet", BlueprintReadWrite)
	bool PlanetIsDoneGrowing = false;

protected:

	UFUNCTION(BlueprintCallable, Category="Planet")
	virtual void InitializeResourceRatio(int32 StatisticResourceRatio);

	UFUNCTION(BlueprintCallable, Category="Planet")
	virtual void AddResource(AActor* GivenResource);

	UFUNCTION(BlueprintCallable, Category="Planet")
	virtual void RemoveResource(AActor* GivenResource);

	UFUNCTION(BlueprintCallable, Category = "Planet")
	virtual void AddAlien(AActor* GivenAlien);

	UFUNCTION(BlueprintCallable, Category = "Planet")
	virtual void RemoveAlien(AActor* GivenAlien);

	UFUNCTION(BlueprintCallable, Category = "Planet")
	virtual int32 GetPlanetHealth();

	UFUNCTION(BlueprintCallable, Category = "Planet")
	virtual int32 GetPlanetMaxHealth();

	UFUNCTION(BlueprintCallable, Category = "Planet")
	virtual bool GetIsHomePlanet();

	UFUNCTION(BlueprintCallable, Category = "Planet")
	virtual int32 GetAlienNum();

	UFUNCTION(BlueprintCallable, Category = "Planet")
	virtual int32 GetResourceNum();

	UFUNCTION(BlueprintCallable, Category = "Planet")
	virtual FString GetPlanetName();

	// Starts a growth/hurt loop that affects planet vegetation based on various factors
	UFUNCTION(BlueprintCallable, Category = "Planet")
	virtual void IntervalGrowthLoop();

	UFUNCTION()
	virtual void HurtPlanet();

	UFUNCTION()
	virtual void GrowPlanet();

	UFUNCTION()
	virtual void KillPlanet();

private:
	// All of the resources confined on the planet
	TArray<AActor*> Resources;

	// All of the aliens that reside on the planet
	TArray<AActor*> Aliens;

	// Handles to manage the timers
	FTimerHandle PlanetHurtTimerHandle;
	FTimerHandle PlanetGrowTimerHandle;

	UPROPERTY(EditAnywhere, Category="Planet")
	FString PlanetName;

	UPROPERTY(EditAnywhere, Category="Planet", meta = (ClampMin = "50", ClampMax = "300"))
	int32 MaxPlanetHealth = 100;

	int32 MinPlanetHealth = 0;

	UPROPERTY(EditAnywhere, Category = "Planet", meta = (ClampMin = "1", ClampMax = "200"))
	int32 StartPlanetHealth = 50;

	UPROPERTY(EditAnywhere, Category = "Planet")
	float PlanetHurtTimer = 5.0;

	// Planet resource to health ratio determined by initial resources
	UPROPERTY(EditAnywhere, Category = "Planet", meta = (ClampMin = "1", ClampMax = "200"))
	int32 PlanetResourceRatio = 10;

	// Track current health to determine whether planet goes extinct or not
	int32 CurrentPlanetHealth = StartPlanetHealth;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
