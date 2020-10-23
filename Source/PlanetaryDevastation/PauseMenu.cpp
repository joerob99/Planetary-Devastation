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
}

void UPauseMenu::ResumeGame()
{
	// GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Resume."));

	// TODO: If the button is not activated (bAreButtonsEnabled == false), don't do anything.

	if (FadeIn)
	{
		// TODO: Disable buttons.

		const float StartAtTime = 0.0f;
		const int NumLoopsToPlay = 1;
		const EUMGSequencePlayMode::Type PlayMode = EUMGSequencePlayMode::Reverse;
		PlayAnimation(FadeIn, StartAtTime, NumLoopsToPlay, PlayMode);

		// TODO: Create unload function to enable buttons. Replace with remove from parent.
		FTimerHandle UnloadMenuTimerHandle;
		GetWorld()->GetTimerManager().SetTimer(
			UnloadMenuTimerHandle,
			this,
			&UPauseMenu::RemoveFromParent,
			FadeIn->GetEndTime(),
			false
		);
	}
	/** Even if the FadeIn animation is invalid, the menu still needs to be removed. */
	else
	{
		RemoveFromParent();
	}

	// TODO: Set input enabled state. Make game instance function.
}

