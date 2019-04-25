// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBaseC.h"

#include "Kismet/GameplayStatics.h"
#include "Witch.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

AMyGameModeBaseC::AMyGameModeBaseC()
{

}

void AMyGameModeBaseC::BeginPlay()
{

	Super::BeginPlay();

	SetCurrentState(EGamePlayState::EPlaying);

	MyCharacter = Cast<AWitch>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AMyGameModeBaseC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MyCharacter)
	{
		if (FMath::IsNearlyZero(MyCharacter->GetHealth(), 0.001f))
		{
			SetCurrentState(EGamePlayState::EGameOver);
		}
	}
}

EGamePlayState AMyGameModeBaseC::GetCurrentState() const
{
	return CurrentState;
}

void AMyGameModeBaseC::SetCurrentState(EGamePlayState NewState)
{
	CurrentState = NewState;
	HandleNewState(CurrentState);
}

void AMyGameModeBaseC::HandleNewState(EGamePlayState NewState)
{
	switch (NewState)
	{
	case EGamePlayState::EPlaying:
	{
		// do nothing
	}
	break;
	// Unknown/default state
	case EGamePlayState::EGameOver:
	{
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
	}
	break;
	// Unknown/default state
	default:
	case EGamePlayState::EUnknown:
	{
		// do nothing
	}
	break;
	}
}
