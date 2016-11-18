// Fill out your copyright notice in the Description page of Project Settings.

#include "SeekTheGeek.h"
#include "SeekTheGeekGameMode.h"
#include "MyHUD.h"
#include "BaseCharacter.h"

ASeekTheGeekGameMode::ASeekTheGeekGameMode() {

	HUDClass = AMyHUD::StaticClass();

	DefaultPawnClass = ABaseCharacter::StaticClass();



}


