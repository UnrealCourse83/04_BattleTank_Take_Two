// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Classes/AIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}

//called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AITank = GetPawn();
	if (!ensure(PlayerTank && AITank)) { return; }

	//move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);//TODO check radius is in cm

	auto AimingComponent = AITank->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	//Aim towards the player
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	
	// TODO fix firing
	//AimingComponent->Fire(); //TODO Limit firing rate
	
}


