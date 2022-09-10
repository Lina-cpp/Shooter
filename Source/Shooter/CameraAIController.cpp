// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraAIController.h"

#include "Kismet/GameplayStatics.h"

void ACameraAIController::BeginPlay()
{
    Super::BeginPlay();


}

void ACameraAIController::FacePlayer()
{
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0); //get player to pawn to set focus on

    SetFocus(PlayerPawn);   
}