

#include "RP_Character.h"
#include "Camera/CameraComponent.h"

ARP_Character::ARP_Character()
{
	PrimaryActorTick.bCanEverTick = true;

	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FPS_CameraComponent"));
	FPSCameraComponent->bUsePawnControlRotation = true;
	FPSCameraComponent->SetupAttachment(RootComponent);

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

	PlayerInputComponent->BindAxis("LookUp", this, &ARP_Character::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookRight", this, &APawn::AddControllerYawInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ARP_Character::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ARP_Character::StopJumping);
}

void ARP_Character::AddControllerPitchInput(float value)
{

	Super::AddControllerPitchInput(bIsLookInversion ? -value : value);
	/*
	if (bIsLookInversion)
	{
		Super::AddControllerPitchInput(-value);

	}
	else 
	{
		Super::AddControllerPitchInput(value);
	}
	*/
}


void ARP_Character::MoveForward(float value)
{

	AddMovementInput(GetActorForwardVector()*value);
}

void ARP_Character::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector() * value);
}

void ARP_Character::Jump()
{
	Super::Jump();
}

void ARP_Character::StopJumping()
{
	Super::StopJumping();
}
