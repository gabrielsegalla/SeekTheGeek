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
	virtual void Tick(float DeltaSeconds) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
	//GETTERS E SETTERS
	FORCEINLINE bool GetAreaBase() const { return AreaBase; }
	FORCEINLINE void ABaseCharacter::SetAreaBase(bool NewAreaBase) { AreaBase = NewAreaBase; }

	FORCEINLINE bool GetPowerUp() const { return PowerUp; }
	FORCEINLINE void ABaseCharacter::SetPowerUp(bool NewPowerUp) { PowerUp = NewPowerUp; }

	FORCEINLINE bool GetOnLego() const { return OnLego; }
	FORCEINLINE void ABaseCharacter::SetOnLego(bool NewOnLego) { OnLego = NewOnLego; }

	FORCEINLINE int GetStamina() const { return Stamina; }
	FORCEINLINE void ABaseCharacter::SetStamina(int NewStamina) { Stamina = NewStamina; }

	FORCEINLINE bool GetFound() const { return Found; }
	FORCEINLINE void ABaseCharacter::SetFound(bool NewFound) { Found = NewFound; }


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
	UPROPERTY(EditAnywhere)
		UBoxComponent* RangeToFind;
	UPROPERTY(VisibleAnywhere, Category = Camera)
		float BaseLookUpRate;
	UPROPERTY(VisibleAnywhere, Category = Camera)
		float BaseTurnRate;



	//área de colisão para pegar outro char
	USphereComponent* FoundCollisionComp;

	//lista para coletagem de poção
	TArray<class ALegos*> TodosCharsEncontrados;


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

	void FoundingAChar();

	bool Found;

	TSubclassOf<class UUserWidget> UserWidget;


	

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