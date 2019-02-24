// Copyright Nicholas Basansky 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Engine/Classes/Components/SphereComponent.h"
#include "SprungWheel.generated.h"

UCLASS()
class BATTLETANK_API ASprungWheel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASprungWheel();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Wheel = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Axle = nullptr;


	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* BetterWheel = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* BetterAxle = nullptr;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPhysicsConstraintComponent* MassWheelConstraint = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPhysicsConstraintComponent* AxleWheelConstraint = nullptr;

	void SetupConstraints();
};
