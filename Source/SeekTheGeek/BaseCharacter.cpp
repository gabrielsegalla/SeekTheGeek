// Fill out your copyright notice in the Description page of Project Settings.

#include "SeekTheGeek.h"
#include "BaseCharacter.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/UserWidget.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	

	
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachTo(GetCapsuleComponent());
	
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));  //uspring fiozinho/liga��o da camera
	CameraBoom->AttachTo(RootComponent);
	PlayerCamera->AttachTo(CameraBoom);
	CameraBoom->bUsePawnControlRotation = true;


	GetCharacterMovement()->MaxWalkSpeed = 800;
	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;

	ConstructorHelpers::FClassFinder<UUserWidget>Widget(TEXT("WidgetBlueprint'/Game/Blueprint/pause.pause_C'"));

	if (Widget.Succeeded()) {
		UserWidget = Widget.Class;
	}
	bReplicateMovement = true;

	//AutoPossessPlayer = EAutoReceiveInput::Player0;

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

	if (Run) {
		Stamina--;

		//UE_LOG(LogTemp, Warning, TEXT("Stamina--: %d"), Stamina);
	}
	else if(!Run) {
		//UE_LOG(LogTemp, Warning, TEXT("Stamina++: %d"), Stamina);
		
		Stamina++;
	}

	if (Stamina > 200) {
		Stamina = 200;
	}

	if (Stamina < 0) {
		StopRun();
		Stamina = 0;
	}


}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);

	InputComponent->BindAxis("Turn", this, &ABaseCharacter::Turn);
	InputComponent->BindAxis("TurnRate", this, &ABaseCharacter::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &ABaseCharacter::LookUp);
	InputComponent->BindAxis("LookUpRate", this, &ABaseCharacter::LookUpAtRate);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	InputComponent->BindAction("Run", IE_Pressed, this, &ABaseCharacter::StartRun);
	InputComponent->BindAction("Run", IE_Released, this, &ABaseCharacter::StopRun);

	InputComponent->BindAction("Crouch", IE_Pressed, this, &ABaseCharacter::StartCrouch);
	InputComponent->BindAction("Crouch", IE_Released, this, &ABaseCharacter::StopCrouch);

	InputComponent->BindAction("Pause", IE_Released, this, &ABaseCharacter::Pause);

	bReplicates = true;
	bReplicateMovement = true;
	
	

	//InputComponent->BindAction("Drop", IE_Pressed, this, &AMyCharacter::DropProjectile);
}

void ABaseCharacter::MoveForward(float Value) {
	if (Value != 0.0f)
	{
		FVector Forward(1, 0, 0);
		AddMovementInput(GetActorForwardVector(), Value);
	}
	
	
}

void ABaseCharacter::MoveRight(float Value) {
	if (Value != 0.0f)
	{
		FVector Right(0, 1, 0);
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void ABaseCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ABaseCharacter::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ABaseCharacter::StartRun() {
	if (Stamina > 0) {
		Run = true;
	}

	if (Run) {
		GetCharacterMovement()->MaxWalkSpeed =1600;
	}
	
}
void ABaseCharacter::StopRun() {
	Run = false;
	GetCharacterMovement()->MaxWalkSpeed = 800;
}

void ABaseCharacter::StartCrouch() {
	Crouch();
}
void ABaseCharacter::StopCrouch() {
	UnCrouch();
}


//movimento do mouse
void ABaseCharacter::Turn(float Value) {
	AddControllerYawInput(Value);
}

void ABaseCharacter::LookUp(float Value) {
	AddControllerPitchInput(Value);
}


//Encapsulamento da vari�vel AreaBase
void ABaseCharacter::SetAreaBase(bool NewAreaBase) {
	AreaBase = NewAreaBase;
}

int ABaseCharacter::GetAreaBase() {
	return AreaBase;

}


void ABaseCharacter::SetStamina(int NewStamina) {
	Stamina = NewStamina;
}
int ABaseCharacter::GetStamina() {
	return Stamina;
}


void ABaseCharacter::Pause() {
	UWorld* World = GetWorld();
	if (World != nullptr) {
		APlayerController * PlayerController = UGameplayStatics::GetPlayerController(World, 0);
		if (PlayerController != nullptr && UserWidget != NULL) {
			PlayerController->SetPause(true);
			UUserWidget *UserW = UWidgetBlueprintLibrary::Create(World, UserWidget, PlayerController);
			if (UserW != nullptr) {
				UserW->AddToViewport();
				PlayerController->bShowMouseCursor = true;
			}
		}
	}
}
