// Fill out your copyright notice in the Description page of Project Settings.

#include "SeekTheGeek.h"
#include "LocationToSpawn.h"


// Sets default values
ALocationToSpawn::ALocationToSpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->AttachTo(RootComponent);
}

void ALocationToSpawn::SetPosX(int NewPosX) {
	posX = NewPosX;
}

float ALocationToSpawn::GetPosX() {
	return posX;
}

void ALocationToSpawn::SetPosY(int NewPosY) {
	posY = NewPosY;
}

float ALocationToSpawn::GetPosY() {
	return posY;
}

// Called when the game starts or when spawned
void ALocationToSpawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALocationToSpawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

