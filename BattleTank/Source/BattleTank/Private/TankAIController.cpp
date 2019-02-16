// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Classes/AIController.h"
#include "Public/Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

//called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AITank = Cast<ATank>(GetPawn());
	if (ensure(PlayerTank))
	{
		//move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);//TODO check radius is in cm

		//Aim towards the player
		AITank->AimAt(PlayerTank->GetActorLocation());
		AITank->Fire(); //TODO Limit firing rate
	}
}


