// Fill out your copyright notice in the Description page of Project Settings.

#include "SeekTheGeek.h"
#include "Caixao.h"
#include "BaseCharacter.h"


// Sets default values
ACaixao::ACaixao()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));

	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &ACaixao::OnOverlapBegin);
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void ACaixao::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACaixao::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ACaixao::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	//Se o ator for diferente de um ponteiro nulo / se o ator n�o for ele mesmo / se o comp for difertente de nulo
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherActor->IsA(ABaseCharacter::StaticClass())) {

		//Converter objeto de um tipo generalizado para um mais espec�fico (cast)
		ABaseCharacter* Character = Cast<ABaseCharacter>(OtherActor);


		//LOG
		//Par�metros: categoria, tipo, conte�do (%d -> indica que ali haver� um int, que deve ser indicado no pr�ximo par�metro)
		//UE_LOG(LogTemp, Warning, TEXT("Colect = %d"), Robson->GetColect());

		UE_LOG(LogTemp, Warning, TEXT("GUARDANDO CAXI�O"));

	}
}

