// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"

// Sets default values
APlayer_Pawn::APlayer_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//criando a estaic mesh, camera e anexando ao rootcomponent
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malha estatica"));
	StaticMesh -> SetSimulatePhysics(true);
	RootComponent = StaticMesh;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Minha Camera"));
	//Anexando Camera na raiz do projeto
	Camera -> SetupAttachment(RootComponent);
	//Posição da camera
	Camera -> AddRelativeLocation(FVector(-332, 0, 301));


}

// Called when the game starts or when spawned
void APlayer_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayer_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayer_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Inputs para as teclas
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Vertical", this, &APlayer_Pawn::MoveVertical);
	PlayerInputComponent->BindAxis("MouseX", this, &APlayer_Pawn::MoveHorizontal);
	

}

//rotação do personagem
void APlayer_Pawn::MoveVertical(float eixoVertical)
{
	FVector PosicaoAtual = GetActorLocation();
	FVector Frente = GetActorForwardVector();
	SetActorLocation(PosicaoAtual + (Frente * eixoVertical * Velocidade));

}
//Andar do personagem
void APlayer_Pawn::MoveHorizontal(float eixoHorizontal)
{
	FRotator RotacaoAtual = GetActorRotation();
	FRotator eixoZ = FRotator::MakeFromEuler(FVector(0.f, 0.f, 1.f));
	SetActorRotation(RotacaoAtual + (eixoZ * eixoHorizontal * VelocidadeDeRotacao));
}

