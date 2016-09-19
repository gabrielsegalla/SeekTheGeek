// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "LocationToSpawn.generated.h"

UCLASS()
class SEEKTHEGEEK_API ALocationToSpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALocationToSpawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void SetPosX(int NewPosX);
	int GetPosX();

	void SetPosY(int NewPosY);
	int GetPosY();

private:

	UPROPERTY(EditAnywhere)
		UShapeComponent* Root;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere)
		float posX = 0.0f;
	UPROPERTY(EditAnywhere)
		float posY = 0.0f;
};