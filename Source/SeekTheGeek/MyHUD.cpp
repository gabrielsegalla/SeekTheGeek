// Fill out your copyright notice in the Description page of Project Settings.

#include "SeekTheGeek.h"
#include "MyHUD.h"
#include "Engine/Font.h"
#include "Engine/Canvas.h"
#include "Kismet/GameplayStatics.h"
#include "BaseCharacter.h"

AMyHUD::AMyHUD() {
	
	static ConstructorHelpers::FObjectFinder<UFont>Font(TEXT("Font'/Game/BebasNeue.BebasNeue'"));

	if (Font.Succeeded()) {
		HUDFont = Font.Object;
	}

	static ConstructorHelpers::FObjectFinder<UTexture2D>Texture(TEXT("Texture2D'/Game/Materials/texture.texture'"));

	if (Font.Succeeded()) {
		MyTexture = Texture.Object;
	}

}

void AMyHUD::DrawHUD() {

	Super::DrawHUD();

	FVector2D ScreenDimensions = FVector2D(Canvas->SizeX, Canvas->SizeY);

	ABaseCharacter* Char = Cast<ABaseCharacter>(

		UGameplayStatics::GetPlayerPawn(this, 0));

	/*FString StaminaString = FString::Printf(TEXT("%d / 200"), BaseCharacter->GetStamina());

	DrawText(StaminaString, FColor::Red, 300, 50, HUDFont);

	DrawTexture(MyTexture, 200, 150, BaseCharacter->GetStamina(), MyTexture->GetSizeY(), 200, 200, BaseCharacter->GetStamina(), MyTexture->GetSizeY(), FLinearColor::White, EBlendMode::BLEND_Opaque, 1.0, false, 1.0f, FVector2D::ZeroVector);

	*/

	FString EncontradoString = FString::Printf(TEXT("CORRA!!!"));

	FString VenceuString = FString::Printf(TEXT("VOCÊ VENCEU!!!"));


	if (Char->GetEncontrado()) {
		DrawText(EncontradoString, FColor::Red, 300, 200, HUDFont);
	}

	if (Char->GetVenceu()) {
		DrawText(VenceuString, FColor::Yellow, 300, 200, HUDFont);

	}


}




