// Fill out your copyright notice in the Description page of Project Settings.

#include "SeekTheGeek.h"
#include "PowerUp.h"
#include "BaseCharacter.h"



// Sets default values
APowerUp::APowerUp()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));

	//inidica tamanho inicial
	Root->SetWorldScale3D(FVector(2.0f, 2.0f, 2.0f));
	RootComponent = Root;

	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &APowerUp::OnOverlapBegin);
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	//Nada vai colidir com a forma para n�o haver conflitos
	MeshComp->SetCollisionProfileName("NoCollision");
	//Liga a forma � �rea
	MeshComp->AttachTo(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		Mesh(TEXT("StaticMesh'/Game/Objetos/bolo/bolo.bolo'"));

	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);

	}
	//MeshComp->SetWorldLocation(FVector(0.0f, 0.0f, -50.0f));
	//MeshComp->SetWorldScale3D(FVector(4.0f, 4.0f, 4.0f));
	MeshComp->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void APowerUp::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APowerUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ABaseCharacter* Char = Cast<ABaseCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (Char->GetPowerUp()) {
		Timer++;

		Char->GetCharacterMovement()->MaxWalkSpeed += 400;
		UE_LOG(LogTemp, Warning, TEXT("Timer: %d"), Timer);
	}

	if (Timer == 200) {

		Timer = 0;

		Char->SetPowerUp(false);
		Char->GetCharacterMovement()->MaxWalkSpeed = 400;

		UE_LOG(LogTemp, Warning, TEXT("Zerando Timer"));

	}


}


void APowerUp::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherActor->IsA(ABaseCharacter::StaticClass())) {

		ABaseCharacter* Char = Cast<ABaseCharacter>(OtherActor);

		UE_LOG(LogTemp, Warning, (TEXT("Pegou power-up")));

		Char->SetPowerUp(true);



	}

}
