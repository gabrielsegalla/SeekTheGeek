// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Legos.generated.h"

UCLASS()
class SEEKTHEGEEK_API ALegos : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALegos();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;




private:
	UPROPERTY(EditAnywhere)
		UShapeComponent* Root;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;


	UPROPERTY(VisibleAnyWhere, Category = Tick)
		float RunningTime;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	//bools para identificar se o lego está para ser coletado ou causar slow
	bool LegoColect;
	bool LegoDamage;

	int Timer = 0;


	//movimentação do projétil
	UProjectileMovementComponent* ProjectileMovement;


};
