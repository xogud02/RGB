// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RGB.h"
#include "GameFramework/Character.h"
#include "GameFramework\SpringArmComponent.h"
#include "RGBCharacter.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(OnColorChangeSignature, EColor);

UCLASS()
class RGB_API ARGBCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = SpringArm)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
	UMaterialInstanceDynamic* BodyMaterial;

	UPROPERTY(EditAnywhere)
	UMaterialInstanceDynamic* LogoMaterial;

	UPROPERTY(EditAnywhere, Category = SpringArm)
	float MinTargetArmLength = 150;

	UPROPERTY(EditAnywhere, Category = SpringArm)
	float MaxTargetArmLength = 450;

	UPROPERTY(EditAnywhere, Category = SpringArm)
	float ZoomRate = 15;

	EColor BodyColor;

public:
	OnColorChangeSignature OnColorChange;

public:
	// Sets default values for this character's properties
	ARGBCharacter();
	void SetBodyColor(EColor Color);
	EColor GetBodyColor();
private:

	inline void InitMesh();
	inline void InitCamera();
	inline void InitCharacterMovement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Scale);

	void MoveRight(float Scale);

	void Turn(float Scale);

	void LookUp(float Scale);

	void Zoom(float scale);
};
