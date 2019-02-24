// Copyright Nicholas Basansky 2019

#include "SpawnPoint.h"
#include "Engine/World.h"
//#include "Public/UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
USpawnPoint::USpawnPoint()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	//Trying to attach the SprungWheel_BP to the SpawnClass inside the Tank_BP
	//static ConstructorHelpers::FClassFinder<AActor>SprungWheel_BP(TEXT("Blueprint'/Game/Tank/SprungWheel_BP.SprungWheel_BP_C'"));
	//SpawnClass = SprungWheel_BP.Class;


}


// Called when the game starts
void USpawnPoint::BeginPlay()
{
	Super::BeginPlay();

	auto NewActor = GetWorld()->SpawnActorDeferred<AActor>(SpawnClass, GetComponentTransform());
	if (!NewActor) { return; }
	NewActor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
	UGameplayStatics::FinishSpawningActor(NewActor, GetComponentTransform());

}


// Called every frame
void USpawnPoint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

