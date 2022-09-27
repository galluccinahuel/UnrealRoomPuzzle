// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RP_Character.generated.h"

UCLASS()
class ROOMPUZZLE_API ARP_Character : public ACharacter
{
	GENERATED_BODY()

public:

	ARP_Character();

protected:

	virtual void BeginPlay() override;

	void MoveForward(float value);

	void MoveRight(float value);

public:	

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
