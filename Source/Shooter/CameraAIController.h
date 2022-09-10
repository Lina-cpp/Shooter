// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CameraAIController.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API ACameraAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void FacePlayer();

};
