// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "W_Gun.generated.h"


class USkeletalMeshComponent;

UCLASS()
class PROTO0322CPP_API AW_Gun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AW_Gun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//½ºÄÌ·¹Å» ¸Å½¬ ÄÄÆ÷³ÍÆ®
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent* MeshComp;
    


    

	//Fire ÇÔ¼ö
	UFUNCTION(BlueprintCallable,Category = "Weapon")
	void fire();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
