// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/SkeletalMesh.h"
#include "Components/InputComponent.h"

// Sets default values
APlayer_Character::APlayer_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Anexa,cria e adiciona a localização da camera ao manequim
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));

	//define aonde o componente estará anexado
	SpringArm -> SetupAttachment(RootComponent);

	//controle o zoom e a distancia de visualizaçãoem jogos de terceira pessoa
	SpringArm -> TargetArmLength = 1000.f;
	//rotação da camera (para top-down)
	SpringArm -> SetRelativeRotation(FRotator(-90.f, 0.f, 0.f));

	//Cria a camera, adiciona a localização dela 
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Player"));
	//anexa a camera criada no spring arm
	Camera -> SetupAttachment(SpringArm);
	Camera -> AddRelativeLocation(FVector(-600, 0, 1186));


	//utiliza o esqueleto ja existente na engine atraves do lugar onde ele esta localizado
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> PlayerMesh(
		TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Quinn_Simple.SKM_Quinn_Simple'")
	);

	//se o manequim for spawnado com sucesso...
	if (PlayerMesh.Succeeded()){
		//adiciona a mesh do maniquim
		GetMesh() -> SetSkeletalMesh(PlayerMesh.Object);
		//localizações do maniquim (Onde sera spawnado no mapa)
		GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
		GetMesh()->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	}

}

// Called when the game starts or when spawned
void APlayer_Character::BeginPlay()
{
	Super::BeginPlay();
	

	
	
}

// Called every frame
void APlayer_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayer_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//conectando os inputs com as funções criadas
	PlayerInputComponent -> BindAxis ("Vertical", this, &APlayer_Character::MoverVertical);
	PlayerInputComponent -> BindAxis ("Horizontal", this, &APlayer_Character::MoverHorizontal);

}
//adicionando informações ás funções
void APlayer_Character::MoverVertical(float eixoVertical){

	FVector PosicaoAtual = GetActorLocation();
	FVector Frente = GetActorForwardVector();
	SetActorLocation(PosicaoAtual + (Frente * eixoVertical * Velocidade));

}
void APlayer_Character::MoverHorizontal(float eixoHorizontal){

	AddControllerYawInput(eixoHorizontal);
	FRotator RotacaoAtual = GetActorRotation();

	/* nome.yaw = adiciona um valor á rotação atual do eixo horizontal. o += faz com que a rotação se acumule, girando continuamente.
		getworld()->getdeltaseconds() = Representa o tempo decorrido entre frames (delta time)

		ou seja, "Gire o personagem horizontalmente à esquerda ou à direita, na velocidade definida, ajustando o movimento para que seja suave e igual em qualquer taxa de quadros."

	*/ 
    RotacaoAtual.Yaw += eixoHorizontal * VelocidadeDeRotacao * GetWorld()->GetDeltaSeconds();
	FRotator eixoZ = FRotator::MakeFromEuler(FVector(0.f, 0.f, 1.f));
	SetActorRotation(RotacaoAtual + (eixoZ * eixoHorizontal * VelocidadeDeRotacao));
	
}



