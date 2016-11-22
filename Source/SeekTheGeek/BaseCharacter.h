// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class SEEKTHEGEEK_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//get e set do Life
	void SetAreaBase(bool NewAreaBase);
	int GetAreaBase();

	//get e set do stamina para o run
	void SetStamina(int NewStamina);
	int GetStamina();



	
private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere)
		UCameraComponent* PlayerCamera;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* CameraBoom;
	//stamina para o run
	UPROPERTY(EditAnywhere)
		int Stamina = 200;
	UPROPERTY(VisibleAnywhere, Category = Camera)
		float BaseLookUpRate;
	UPROPERTY(VisibleAnywhere, Category = Camera)
		float BaseTurnRate;


	void MoveForward(float Value);
	void MoveRight(float Value);
	void StartRun();
	void StopRun();

	void FoundMyFriend();

	void Turn(float Value);
	void LookUp(float Value);
	void LookUpAtRate(float Rate);
	void TurnAtRate(float Rate);

	void StartCrouch();
	void StopCrouch();

	void Pause();
	TSubclassOf<class UUserWidget> UserWidget;

	//bool pra identificar se o personagem está na área da base

	bool AreaBase = false;
	bool Run = false;





};
