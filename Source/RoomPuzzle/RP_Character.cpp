

#include "RP_Character.h"

ARP_Character::ARP_Character()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ARP_Character::BeginPlay()
{
	Super::BeginPlay();
	
}


void ARP_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARP_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this, &ARP_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ARP_Character::MoveRight);
}


void ARP_Character::MoveForward(float value)
{

	AddMovementInput(GetActorForwardVector()*value);
}

void ARP_Character::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector() * value);
}