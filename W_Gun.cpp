// Fill out your copyright notice in the Description page of Project Settings.

#include "W_Gun.h"
//디버그
#include "DrawDebugHelpers.h"


// Sets default values
AW_Gun::AW_Gun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void AW_Gun::BeginPlay()
{
	Super::BeginPlay();
	
}

void AW_Gun::fire()
{

	//Get OwnerActor
	AActor* MyOwner = GetOwner();
	if (MyOwner)
	{


		//월드에서 크로스헤어로부터 보는 것을 트레이스

		FVector EyeLocation;
		FRotator EyeRotation;
		MyOwner->GetActorEyesViewPoint(EyeLocation,EyeRotation);

		FVector TraceEnd = EyeLocation + (EyeRotation.Vector() * 10000);

		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(MyOwner);
		QueryParams.AddIgnoredActor(this);
		QueryParams.bTraceComplex = true;

		FHitResult Hit;
		if (GetWorld()->LineTraceSingleByChannel(Hit, EyeLocation, TraceEnd, ECC_Visibility))
		{
			// Blocking Hit damage
		}
		DrawDebugLine(GetWorld(), EyeLocation, TraceEnd, FColor::White, false, 1.0f, 0, 1.0f);
	}



}

// Called every frame
void AW_Gun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

