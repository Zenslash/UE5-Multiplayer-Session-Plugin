// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"
#include "MultiplayerSessionsSubsystem.h"

#include "Components/Button.h"

void UMenuWidget::MenuSetup()
{
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	bIsFocusable = true;

	UWorld* World = GetWorld();
	if(World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if(PlayerController)
		{
			FInputModeUIOnly InputModeData;
			InputModeData.SetWidgetToFocus(TakeWidget());
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(true);
		}
	}

	UGameInstance* GameInstance = GetGameInstance();
	if(GameInstance)
	{
		MultiplayerSessionsSubsystem = GameInstance->GetSubsystem<UMultiplayerSessionsSubsystem>();
	}
}

bool UMenuWidget::Initialize()
{
	if(!Super::Initialize())
	{
		return false;
	}

	if(HostButton)
	{
		HostButton->OnClicked.AddDynamic(this, &UMenuWidget::HostBtnClicked);
	}
	if(JoinButton)
	{
		JoinButton->OnClicked.AddDynamic(this, &UMenuWidget::JoinBtnClicked);
	}

	return true;
}

void UMenuWidget::HostBtnClicked()
{
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.f,
			FColor::Yellow,
			FString(TEXT("Host Btn Clicked!"))
		);
	}

	if(MultiplayerSessionsSubsystem)
	{
		//TODO Get params from UI
		MultiplayerSessionsSubsystem->CreateSession(4, FString("FreeForAll"));
	}
}

void UMenuWidget::JoinBtnClicked()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.f,
			FColor::Yellow,
			FString(TEXT("Join Btn Clicked!"))
		);
	}
}
