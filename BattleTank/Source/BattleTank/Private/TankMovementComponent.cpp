// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTracks.h"

void UTankMovementComponent::Initialize(UTankTracks* LeftTrackToSet, UTankTracks* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	// TODO prevent double-speed due to dual control use
	
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	UE_LOG(LogTemp, Warning, TEXT("Turn Right Throw: %f"), Throw)
	// TODO prevent double-speed due to dual control use

}
