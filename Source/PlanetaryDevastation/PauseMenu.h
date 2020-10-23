// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseMenu.generated.h"

class UButton;

UCLASS()
class PLANETARYDEVASTATION_API UPauseMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	/** Triggered by player input. */
	UFUNCTION(BlueprintCallable)
	void ResumeGame();

protected:
	virtual void NativeConstruct() override;
	virtual void NativeOnInitialized() override;

private:
	UPROPERTY(meta = (BindWidgetAnim, AllowPrivateAccess = "true"), BlueprintReadOnly, Category = "Animations")
	UWidgetAnimation* FadeIn = nullptr;

	UPROPERTY(meta = (BindWidgetAnim, AllowPrivateAccess = "true"), BlueprintReadOnly, Category = "Animations")
	UWidgetAnimation* Hover = nullptr;

	UPROPERTY(meta = (BindWidget, AllowPrivateAccess = "true"), BlueprintReadOnly)
	UButton* ResumeButton = nullptr;
	
};
