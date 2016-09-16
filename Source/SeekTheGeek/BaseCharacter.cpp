// Fill out your copyright notice in the Description page of Project Settings.

#include "SeekTheGeek.h"
#include "BaseCharacter.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	
	
	
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachTo(GetCapsuleComponent());
	
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));  //uspring fiozinho/ligação da camera
	CameraBoom->AttachTo(RootComponent);
	PlayerCamera->AttachTo(CameraBoom);
	

	GetCharacterMovement()->MaxWalkSpeed = 400;
	

	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);

	//InputComponent->BindAxis("Turn", this, &ABaseCharacter::Turn);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	InputComponent->BindAction("Run", IE_Pressed, this, &ABaseCharacter::StartRun);
	InputComponent->BindAction("Run", IE_Released, this, &ABaseCharacter::StopRun);

	//InputComponent->BindAction("Drop", IE_Pressed, this, &AMyCharacter::DropProjectile);
}

void ABaseCharacter::MoveForward(float Value) {
	FVector Forward(1, 0, 0);
	AddMovementInput(Forward, Value);
}


void ABaseCharacter::MoveRight(float Value) {
	FVector Right(0, 1, 0);
	AddMovementInput(Right, Value);
}

void ABaseCharacter::StartRun() {
	GetCharacterMovement()->MaxWalkSpeed = 800;
}
void ABaseCharacter::StopRun() {
	GetCharacterMovement()->MaxWalkSpeed = 400;
}

//Encapsulamento da variável AreaBase
void ABaseCharacter::SetAreaBase(bool NewAreaBase) {
	AreaBase = NewAreaBase;
}

int ABaseCharacter::GetAreaBase() {
	return AreaBase;

}
