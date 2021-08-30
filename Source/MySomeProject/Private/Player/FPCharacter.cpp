// Fill out your copyright notice in the Description page of Project Settings.


#include "FPCharacter.h"

// Sets default values
AFPCharacter::AFPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;	
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->AttachTo(RootComponent);
	CameraComponent->SetRelativeLocation(FVector(0, 0, 50));
}

// Called when the game starts or when spawned
void AFPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &AFPCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AFPCharacter::MoveRight);
	InputComponent->BindAxis("LookUp", this, &AFPCharacter::LookUp);
	InputComponent->BindAxis("LookRight", this, &AFPCharacter::LookRight);
	InputComponent->BindAction("Jump", IE_Pressed, this, &AFPCharacter::Jump);
}

void AFPCharacter::MoveForward(float axis)
{
	AddMovementInput(GetActorForwardVector(), axis);
}

void AFPCharacter::MoveRight(float axis)
{
	AddMovementInput(GetActorRightVector(), axis);
}

void AFPCharacter::LookUp(float axis)
{
	AddControllerPitchInput(-axis);
}

void AFPCharacter::LookRight(float axis)
{
	AddControllerYawInput(axis);
}

