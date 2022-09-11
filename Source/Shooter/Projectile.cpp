// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh")); //creating mesh to choose in BP
	RootComponent = ProjectileMesh; //attaching ProjectileMesh to Root

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	ProjectileMovementComponent->MaxSpeed = 1300.f; 	//projectile max speed
	ProjectileMovementComponent->InitialSpeed = 1300.f; //projectile start speed
	ProjectileMovementComponent->ProjectileGravityScale = 0; //0 gravity


}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	//binding onhit() to OnHitComponent - ulog should work now!
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//it's working!
	UE_LOG(LogTemp, Warning, TEXT("onhit!"));
	UE_LOG(LogTemp, Warning, TEXT("Hit comp: %s"), *HitComp->GetName());
	UE_LOG(LogTemp, Warning, TEXT("Other actor: %s"), *OtherActor->GetName());
	UE_LOG(LogTemp, Warning, TEXT("Other comp: %s"), *OtherComp->GetName());

	/*
	//setting instigator
	auto MyOwner = GetOwner();
	if(MyOwner == nullptr)
	{
		Destroy();
		return;
	}
	
	auto MyOwnerInstigator = MyOwner->GetInstigatorController();
	auto DamageTypeClass = UDamageType::StaticClass();

	//setting projectiles to deal damage and destroying them
	if(OtherActor && OtherActor !=this && OtherActor != MyOwner)
	{
		UGameplayStatics::ApplyDamage(OtherActor, Damage, MyOwnerInstigator, this, DamageTypeClass);
	}
	*/
	//Destroy();


}

