// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Projectile.h"

// Sets default values
ACamera::ACamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Constructing a Capsule Component - hitbox
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>( TEXT("Capsule Collider") );
		RootComponent = CapsuleComp; //Making it a root
	
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>( TEXT("BaseMesh") );
		BaseMesh->SetupAttachment(CapsuleComp); // Attaching to Capsule	

	LensMesh = CreateDefaultSubobject<UStaticMeshComponent>( TEXT("Turret Mesh") );
		LensMesh->SetupAttachment(BaseMesh); // Attaching to BaseMesh

	CameraProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>( TEXT("Projectile Spawn Point") );
		CameraProjectileSpawnPoint->SetupAttachment(LensMesh); // Attaching to LensMesh

}

// Called when the game starts or when spawned
void ACamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

	
void ACamera::CameraShot()
{
	
	//Shooting projectile
	
	FVector Location = CameraProjectileSpawnPoint->GetComponentLocation();
	FRotator Rotation = CameraProjectileSpawnPoint->GetComponentRotation();

	//test
	//AActor* Projectile = 
	GetWorld()->SpawnActor<AProjectile>(ProjectileClas, Location, Rotation);
}

void ACamera::DestroyingActor_Implementation()
{
	
}

