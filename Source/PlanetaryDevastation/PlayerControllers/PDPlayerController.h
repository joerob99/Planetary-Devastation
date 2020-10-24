// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PDPlayerController.generated.h"

UCLASS()
class PLANETARYDEVASTATION_API APDPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APDPlayerController();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "UMG")
	TSubclassOf<UUserWidget> PauseMenuClass;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "UMG")
	UUserWidget* PauseMenu = nullptr;
	
};
