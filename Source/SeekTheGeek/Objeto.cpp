// Fill out your copyright notice in the Description page of Project Settings.

#include "SeekTheGeek.h"
#include "Objeto.h"



// Sets default values
AObjeto::AObjeto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	Root->SetSimulatePhysics(true);
	Root->SetMassOverrideInKg("Peso", peso, true);

	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("BlockAllDynamic");
	MeshComp->AttachTo(RootComponent);

	bReplicates = true;

}

// Called when the game starts or when spawned
void AObjeto::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObjeto::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}




