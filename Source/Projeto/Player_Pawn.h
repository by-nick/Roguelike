// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Player_Pawn.generated.h"

UCLASS()
class PROJETO_API APlayer_Pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayer_Pawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	//Configuração para personagem Jogavel
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parametros gerais")
	float Velocidade;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parametros gerais")
	float VelocidadeDeRotacao;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parametros gerais")
	float Altura;

	UPROPERTY(EditANywhere, BlueprintReadWrite, Category = "Parametros gerais")
	bool isAlive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dados Adicionais")
	FName Nome;

	//criando ponteiro para static mesh e a camera
	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleDefaultsOnly)
	class UCameraComponent* Camera;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	//criando rotação do personagem caso precise
	UFUNCTION()
	void MoveVertical(float eixoVertical);

	UFUNCTION()
	void MoveHorizontal(float eixoHorizontal);

};
