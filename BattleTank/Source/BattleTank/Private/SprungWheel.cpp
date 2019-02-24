// Copyright Nicholas Basansky 2019

#include "SprungWheel.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MassWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("MassWheelConstraint"));
	SetRootComponent(MassWheelConstraint);
	
	//Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	BetterWheel = CreateDefaultSubobject<USphereComponent>(FName("BetterWheel"));
	//Axle = CreateDefaultSubobject<UStaticMeshComponent>(FName("Axle"));
	BetterAxle = CreateDefaultSubobject<USphereComponent>(FName("BetterAxle"));
	AxleWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("AxleWheelConstraint"));

	BetterWheel->SetupAttachment(BetterAxle);
	BetterAxle->SetupAttachment(MassWheelConstraint);
	AxleWheelConstraint->SetupAttachment(BetterAxle);

}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();

	SetupConstraints();

}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASprungWheel::SetupConstraints()
{
	if (!ensure(GetAttachParentActor())) { return; }
	UPrimitiveComponent* BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!BodyRoot) { return; }
	MassWheelConstraint->SetConstrainedComponents(BodyRoot, NAME_None, BetterAxle, NAME_None);
	if (AxleWheelConstraint)
	{
		AxleWheelConstraint->SetConstrainedComponents(BetterAxle, NAME_None, BetterWheel, NAME_None);
	}
	else { UE_LOG(LogTemp, Warning, TEXT("No AxleWheelConstraint found!")) }
}