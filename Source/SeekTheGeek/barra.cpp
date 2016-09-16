// Fill out your copyright notice in the Description page of Project Settings.

#include "SeekTheGeek.h"
#include "barra.h"


// Sets default values
Abarra::Abarra()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));

	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &Abarra::OnOverlapBegin);
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void Abarra::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Abarra::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void Abarra::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	
	
	
	
	
	
	//Se o ator for diferente de um ponteiro nulo / se o ator não for ele mesmo / se o comp for difertente de nulo
	//if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherActor->IsA(ARobson::StaticClass())) {
		//Converter objeto de um tipo generalizado para um mais específico (cast)
		//ARobson* Robson = Cast<ARobson>(OtherActor);

		
		//LOG
		//Parâmetros: categoria, tipo, conteúdo (%d -> indica que ali haverá um int, que deve ser indicado no próximo parâmetro)
		//UE_LOG(LogTemp, Warning, TEXT("Colect = %d"), Robson->GetColect());

		UE_LOG(LogTemp, Warning, TEXT("TESTE"));


		//Quando ocorrer a colisão e acrescentar a vida, destrói o objeto
		//Destroy();




	
}


