// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PowerUp.generated.h"

UCLASS()
class SEEKTHEGEEK_API APowerUp : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APowerUp();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

private:

	int Timer = 0;



	UPROPERTY(EditAnywhere)
		UShapeComponent* Root;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;


	UPROPERTY(VisibleAnyWhere, Category = Tick)
		float RunningTime;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};
