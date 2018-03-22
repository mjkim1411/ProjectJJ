// Fill out your copyright notice in the Description page of Project Settings.

#include "DestroyActorOnOverLap.h"
#include "DrawDebugHelpers.h"
#include "Components/SphereComponent.h"


// Sets default values
ADestroyActorOnOverLap::ADestroyActorOnOverLap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereRadius = 100.f;

	MyCollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("My sphere Componentr")); // 디폴트에 메쉬 불러옴
	MyCollisionSphere->InitSphereRadius(SphereRadius);
	MyCollisionSphere->SetCollisionProfileName("Trigger");
	RootComponent = MyCollisionSphere;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MY MESH"));
	MyMesh->SetupAttachment(RootComponent);

	MyCollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ADestroyActorOnOverLap::OnOverlapBegin);

}

// Called when the game starts or when spawned
void ADestroyActorOnOverLap::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADestroyActorOnOverLap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebugSphere(GetWorld(), GetActorLocation(), SphereRadius, 20, FColor::Purple, false, -1, 0, 1);

}

void ADestroyActorOnOverLap::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		Destroy();
	}
}