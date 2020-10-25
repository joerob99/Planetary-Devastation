// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenu.h"

#include "Components/Button.h"

void UPauseMenu::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (ResumeButton)
	{
		ResumeButton->OnClicked.AddDynamic(this, &UPauseMenu::ResumeGame);
	}
}

void UPauseMenu::NativeConstruct()
{
	Super::NativeConstruct();

	if (FadeIn)
	{
		PlayAnimation(FadeIn);
	}

	if (Hover)
	{
		const float StartAtTime = 0.0f;
		const int NumLoopsToPlay = 0;
		PlayAnimation(Hover, StartAtTime, NumLoopsToPlay);
	}

	if (APlayerController* const PlayerController = GetOwningPlayer())
	{
		FInputModeUIOnly InputMode;
		InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		bIsFocusable = true;
		InputMode.SetWidgetToFocus(this->TakeWidget());
		PlayerController->SetInputMode(InputMode);

		PlayerController->bShowMouseCursor = true;
	}
}

void UPauseMenu::ResumeGame()
{
	// GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Resume."));

	if (FadeIn)
	{
		const float StartAtTime = 0.0f;
		const int NumLoopsToPlay = 1;
		const EUMGSequencePlayMode::Type PlayMode = EUMGSequencePlayMode::Reverse;
		PlayAnimation(FadeIn, StartAtTime, NumLoopsToPlay, PlayMode);

		FTimerHandle UnloadMenuTimerHandle;
		GetWorld()->GetTimerManager().SetTimer(
			UnloadMenuTimerHandle,
			this,
			&UPauseMenu::RemoveFromViewport,
			FadeIn->GetEndTime(),
			false
		);
	}
	/** Even if the FadeIn animation is invalid, the menu still needs to be removed. */
	else
	{
		RemoveFromParent();
	}

	if (APlayerController* const PlayerController = GetOwningPlayer())
	{
		PlayerController->SetInputMode(FInputModeGameOnly());

		PlayerController->bShowMouseCursor = false;
	}
}

