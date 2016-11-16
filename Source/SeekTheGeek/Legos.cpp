// Fill out your copyright notice in the Description page of Project Settings.

#include "SeekTheGeek.h"
#include "Legos.h"
#include "BaseCharacter.h"



// Sets default values
ALegos::ALegos()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->bGenerateOverlapEvents = true;

	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &ALegos::OnOverlapBegin);
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void ALegos::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALegos::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ALegos::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherActor->IsA(ABaseCharacter::StaticClass())) {

		ABaseCharacter* BaseCharacter = Cast<ABaseCharacter>(OtherActor);

		BaseCharacter->GetCharacterMovement()->MaxWalkSpeed = 300;

		//LOG
		//Parâmetros: categoria, tipo, conteúdo (%d -> indica que ali haverá um int, que deve ser indicado no próximo parâmetro)
		UE_LOG(LogTemp, Warning, TEXT("COLISÃO"));

	}

}


