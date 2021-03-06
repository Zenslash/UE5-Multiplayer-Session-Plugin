// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LobbyPluginGameMode.generated.h"

UCLASS(minimalapi)
class ALobbyPluginGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ALobbyPluginGameMode();

	virtual void PostLogin(APlayerController* NewPlayer) override;
	virtual void Logout(AController* Exiting) override;
};



