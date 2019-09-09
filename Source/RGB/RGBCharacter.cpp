// Fill out your copyright notice in the Description page of Project Settings.

#include "RGBCharacter.h"
#include "Camera\CameraComponent.h"
#include "Components\CapsuleComponent.h"
#include "Components\InputComponent.h"
#include "Components\SkeletalMeshComponent.h"
#include "ConstructorHelpers.h"
#include "Engine\SkeletalMesh.h"
#include "GameFramework\CharacterMovementComponent.h"
#include "GameFramework\SpringArmComponent.h"
#include "Materials\MaterialInstanceDynamic.h"
#include "Materials\MaterialInterface.h"
#include "RGBCharacterAnimInstance.h"

// Sets default values
ARGBCharacter::ARGBCharacter() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	InitMesh();
	InitCamera();
	InitCharacterMovement();
}

void ARGBCharacter::SetBodyColor(EColor Color) {
	BodyColor = Color;
	FLinearColor NewColor = ConvertToColor(Color);
	BodyMaterial->SetVectorParameterValue(TEXT("BodyColor"), NewColor);
	LogoMaterial->SetVectorParameterValue(TEXT("BodyColor"), NewColor);
	OnColorChange.Broadcast(Color);
}

EColor ARGBCharacter::GetBodyColor() {
	return BodyColor;
}

void ARGBCharacter::InitMesh() {
	const auto Mannequin = ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'")).Object;
	GetMesh()->SetSkeletalMesh(Mannequin);

	BodyMaterial = UMaterialInstanceDynamic::Create(GetMesh()->GetMaterial(0), this, TEXT("Body"));
	GetMesh()->SetMaterial(0, BodyMaterial);
	LogoMaterial = UMaterialInstanceDynamic::Create(GetMesh()->GetMaterial(1), this, TEXT("Logo"));
	GetMesh()->SetMaterial(1, LogoMaterial);
	SetBodyColor(EColor::WHITE);
	const auto HalfHeight = GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
	GetMesh()->SetRelativeLocation(FVector(0, 0, -HalfHeight));
	GetMesh()->SetRelativeRotation(FRotator(0, -90.0f, 0));
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	const auto AnimInstance = ConstructorHelpers::FClassFinder<URGBCharacterAnimInstance>(TEXT("AnimBlueprint'/Game/Animation/RGBCharacterAnimBP.RGBCharacterAnimBP_C'")).Class;
	GetMesh()->SetAnimInstanceClass(AnimInstance);
}

void ARGBCharacter::InitCamera() {
	const auto Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));
	Camera->SetupAttachment(SpringArm);
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bEnableCameraLag = true;
	SpringArm->SetRelativeRotation(FRotator(-30.0f, 0, 0));
	const auto HalfHeight = GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
	SpringArm->SetRelativeLocation(FVector(0, 0, HalfHeight / 2));
	bUseControllerRotationYaw = false;
}

void ARGBCharacter::InitCharacterMovement() {
	const auto CharacterMovement = GetCharacterMovement();
	CharacterMovement->bOrientRotationToMovement = true;
	CharacterMovement->RotationRate = FRotator(0, 720.0f, 0);
	CharacterMovement->JumpZVelocity = 1100.0f;
	CharacterMovement->AirControl = 0.5f;
	CharacterMovement->GravityScale = 3.f;
}

// Called when the game starts or when spawned
void ARGBCharacter::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void ARGBCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ARGBCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ARGBCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ARGBCharacter::MoveRight);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ARGBCharacter::Jump);

	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ARGBCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ARGBCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Zoom"), this, &ARGBCharacter::Zoom);
}

void ARGBCharacter::MoveForward(float Scale) {
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), Scale);
}

void ARGBCharacter::MoveRight(float Scale) {
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), Scale);
}

void ARGBCharacter::Turn(float Scale) {
	if (Scale == 0) {
		return;
	}
	AddControllerYawInput(Scale);
	SpringArm->bEnableCameraRotationLag = false;
}

void ARGBCharacter::LookUp(float Scale) {
	if (Scale == 0) {
		return;
	}
	AddControllerPitchInput(Scale);
	SpringArm->bEnableCameraRotationLag = false;
}

void ARGBCharacter::Zoom(float Scale) {
	const float CurrentLength = SpringArm->TargetArmLength;
	if (Scale < 0 && CurrentLength <= MinTargetArmLength) {
		return;
	}

	if (Scale > 0 && CurrentLength >= MaxTargetArmLength) {
		return;
	}

	SpringArm->TargetArmLength += Scale * ZoomRate;
}

void ARGBCharacter::WarpTo(FVector DestLocation, FRotator DestDirection) {
	SpringArm->bEnableCameraRotationLag = true;
	auto YawScale = Cast<APlayerController>(GetController())->InputYawScale;
	SetActorLocationAndRotation(DestLocation, DestDirection);
	auto Scale = (-GetControlRotation().Yaw + DestDirection.Yaw) / YawScale;
	AddControllerYawInput(Scale);
}
