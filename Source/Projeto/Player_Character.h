// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Player_Character.generated.h"

UCLASS()
class PROJETO_API APlayer_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayer_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//criando categorias nas bps
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parametros")
	float Velocidade;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parametros")
	float VelocidadeDeRotacao;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Parametros")
	float Altura;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parametros")
	bool IsAlive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adicionais")
	FName Nome;

	//criando os elementos que serao utilizados na ue
	UPROPERTY(VisibleDefaultsOnly)
	class UCameraComponent* Camera;

	UPROPERTY(VisibleDefaultsOnly)
	class USpringArmComponent* SpringArm;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//funções de movimento do personagem
	UFUNCTION()
	void MoverVertical(float eixoVertical);

	UFUNCTION()
	void MoverHorizontal(float eixoHorizontal);
	
};
