// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "FallingTree.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFall);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WITCHHUNT_API UFallingTree : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFallingTree();

	UPROPERTY(Blueprintassignable)
		FOnFall FOnFall;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;

	AActor* ActorThatFalls = nullptr;
};
