// Fill out your copyright notice in the Description page of Project Settings.

#include "SeekTheGeek.h"
#include "Teleport.h"
#include "BaseCharacter.h"



// Sets default values
ATeleport::ATeleport()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));

	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &ATeleport::OnOverlapBegin);
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void ATeleport::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATeleport::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ATeleport::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {



	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherActor->IsA(ABaseCharacter::StaticClass())) {

		ABaseCharacter* Char = Cast<ABaseCharacter>(OtherActor);

		Random = FMath::RandRange(1, 5);

		FVector InitialLocation1(2335.0f, 64.0f, 62.0f);
		FVector InitialLocation2(330.0f, 620.0f, 20.0f);
		FVector InitialLocation3(1710.0f, -1190.0f, 150.0f);
		FVector InitialLocation4(-1070.0f, -1140.0f, 10.0f);
		FVector InitialLocation5(-220.0f, 100.0f, 390.0f);


		switch (Random) {

		case 1:
			Char->SetActorLocation(InitialLocation1);
			break;

		case 2:
			Char->SetActorLocation(InitialLocation2);
			break;

		case 3:
			Char->SetActorLocation(InitialLocation3);
			break;

		case 4:
			Char->SetActorLocation(InitialLocation4);
			break;

		case 5:
			Char->SetActorLocation(InitialLocation5);
			break;

		default:
			UE_LOG(LogTemp, Warning, TEXT("Random: %d"), Random);



		}





	}

}


