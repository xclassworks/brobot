/*
  Robo.cpp - Biblioteca para controle das direções do robô.
  Criada por Henrique Nunes, 13 de agosto de 2016.
*/

#include "Motor.h"
#include "Robo.h"

Robo::Robo(Motor* motorEsquerda, Motor* motorDireita)
{
	_motorEsquerda = motorEsquerda;
	_motorDireita = motorDireita;
}

void Robo::girarEsquerda()
{
	(*_motorEsquerda).tras();
	(*_motorDireita).frente();
}

void Robo::girarDireita()
{
	(*_motorEsquerda).frente();
	(*_motorDireita).tras();
}

void Robo::andarFrente()
{
	(*_motorEsquerda).frente();
	(*_motorDireita).frente();
}

void Robo::andarTras()
{
	(*_motorEsquerda).tras();
	(*_motorDireita).tras();
}

void Robo::parar()
{
	(*_motorEsquerda).parar();
	(*_motorDireita).parar();
}

void Robo::alterarVelocidade(int velocidade) {
	(*_motorEsquerda).alterarVelocidade(velocidade);
	(*_motorDireita).alterarVelocidade(velocidade);
}

