

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RP_Door2.generated.h"

class UsceneComponent;
class UStaticMeshComponent;

UCLASS()
class ROOMPUZZLE_API ARP_Door2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARP_Door2();

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	USceneComponent* CustomRootComponent;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* DoorFrameComponent;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* DoorComponent;

	UPROPERTY(EditAnywhere, Category = "Door")
		float openAngle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OpenDoor();

};
