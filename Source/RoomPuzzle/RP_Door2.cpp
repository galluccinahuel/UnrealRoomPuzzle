

#include "RP_Door2.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ARP_Door2::ARP_Door2()
{
	PrimaryActorTick.bCanEverTick = true;
	openAngle = -90.0f;

	CustomRootComponent = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("CustomRoot"));

	RootComponent = CustomRootComponent;

	DoorFrameComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorFrameComponent->SetupAttachment(CustomRootComponent);

	DoorComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	DoorComponent->SetupAttachment(CustomRootComponent);

}

// Called when the game starts or when spawned
void ARP_Door2::BeginPlay()
{
	Super::BeginPlay();

	OpenDoor();
}

// Called every frame
void ARP_Door2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARP_Door2::OpenDoor()
{
	FRotator newRotation = FRotator(0.0f, 0.0f, openAngle);
	DoorComponent->SetRelativeRotation(newRotation);
}

