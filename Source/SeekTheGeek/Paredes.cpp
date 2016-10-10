// Fill out your copyright notice in the Description page of Project Settings.

#include "SeekTheGeek.h"
#include "Paredes.h"


// Sets default values
AParedes::AParedes()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->SetCollisionProfileName("BlockAll");


	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("BlockAll");           
	MeshComp->AttachTo(RootComponent);


}

// Called when the game starts or when spawned
void AParedes::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AParedes::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

