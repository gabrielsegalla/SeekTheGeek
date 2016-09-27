// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Paredes.generated.h"

UCLASS()
class SEEKTHEGEEK_API AParedes : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParedes();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
private:
	UPROPERTY(EditAnywhere)
		UShapeComponent* Root;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;
};
