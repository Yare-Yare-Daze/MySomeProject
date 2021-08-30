// Fill out your copyright notice in the Description page of Project Settings.


#include "MSPGameModeBase.h"
#include "Player/FPCharacter.h"
#include "Player/FPController.h"

AMSPGameModeBase::AMSPGameModeBase()
{
	DefaultPawnClass = AFPCharacter::StaticClass();
	PlayerControllerClass = AFPController::StaticClass();
}
