// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class SEEKTHEGEEK_API AMyHUD : public AHUD
{
	GENERATED_BODY()

public:
	AMyHUD();

	UPROPERTY(EditAnywhere)
		UFont* HUDFont;

	UPROPERTY(EditAnywhere)
		UTexture2D* MyTexture;

	virtual void DrawHUD() override;
	
	
	
	
};
