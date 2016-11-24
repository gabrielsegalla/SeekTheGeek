#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"
UCLASS()
class SEEKTHEGEEK_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	ABaseCharacter();
<<<<<<< HEAD

	
=======
>>>>>>> 7426cf9a746a8bbbda4abda356e8e8d9188a7181
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
<<<<<<< HEAD



=======
	
>>>>>>> 7426cf9a746a8bbbda4abda356e8e8d9188a7181
	//GETTERS E SETTERS
	FORCEINLINE bool GetAreaBase() const { return AreaBase; }
	FORCEINLINE void ABaseCharacter::SetAreaBase(bool NewAreaBase) { AreaBase = NewAreaBase; }

	FORCEINLINE bool GetPowerUp() const { return PowerUp; }
	FORCEINLINE void ABaseCharacter::SetPowerUp(bool NewPowerUp) { PowerUp = NewPowerUp; }

	FORCEINLINE bool GetOnLego() const { return OnLego; }
	FORCEINLINE void ABaseCharacter::SetOnLego(bool NewOnLego) { OnLego = NewOnLego; }

	FORCEINLINE int GetStamina() const { return Stamina; }
	FORCEINLINE void ABaseCharacter::SetStamina(int NewStamina) { Stamina = NewStamina; }

<<<<<<< HEAD
	FORCEINLINE bool GetFounded() const { return Founded; }
	FORCEINLINE void ABaseCharacter::SetFounded(bool NewFounded) { Founded = NewFounded; }

	FORCEINLINE bool GetFoundAnother() const { return FoundAnother; }
	FORCEINLINE void ABaseCharacter::SetFoundAnother(bool NewFoundAnother) { FoundAnother = NewFoundAnother; }
=======
	FORCEINLINE bool GetFound() const { return Found; }
	FORCEINLINE void ABaseCharacter::SetFound(bool NewFound) { Found = NewFound; }

>>>>>>> 7426cf9a746a8bbbda4abda356e8e8d9188a7181

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
<<<<<<< HEAD
	


	//área de colisão para pegar outro char
	USphereComponent* CollectCollisionComp;

	//lista para coletagem de poção
	TArray<class ABaseCharacter*> CharFounded;
=======

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
>>>>>>> 7426cf9a746a8bbbda4abda356e8e8d9188a7181


	void MoveForward(float Value);
	void MoveRight(float Value);
	void StartRun();
	void StopRun();
	void Turn(float Value);
	void LookUp(float Value);
	void LookUpAtRate(float Rate);
	void TurnAtRate(float Rate);
	void StartCrouch();
	void StopCrouch();
	void Pause();

	//variáveis de encontrar/ ser encontrado

<<<<<<< HEAD
	bool Founded;
	bool FoundAnother;
=======
	bool Found;
>>>>>>> 7426cf9a746a8bbbda4abda356e8e8d9188a7181

	TSubclassOf<class UUserWidget> UserWidget;

	USoundCue* walkSound;
	UAudioComponent* AudioComp;



	//bool pra identificar se o personagem está na área da base
	bool AreaBase = false;

	//bool para corrida
	bool Run = false;

	//bool para power up
	bool PowerUp = false;

	//bool para lego
	bool OnLego = false;

	//bool para teleport
	bool Teleporting = false;

};