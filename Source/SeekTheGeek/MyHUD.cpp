// Fill out your copyright notice in the Description page of Project Settings.

#include "SeekTheGeek.h"
#include "MyHUD.h"

AMyHUD::AMyHUD() {
	
	UE_LOG(LogTemp, Warning, TEXT("TESTE"));


}

void AMyHUD::DrawHUD() {

	Super::DrawHUD();

	UE_LOG(LogTemp, Warning, TEXT("TESTE"));




}




