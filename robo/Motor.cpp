/*
  Motor.cpp - Biblioteca para controle de motor.
  Criada por Henrique Nunes, 13 de agosto de 2016.
*/

#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int pinoVelocidade, int pinoFrente, int pinoTras)
{
	pinMode(pinoVelocidade, OUTPUT);
	pinMode(pinoFrente, OUTPUT);
	pinMode(pinoTras, OUTPUT);

	_pinoVelocidade = pinoVelocidade;
	_pinoFrente = pinoFrente;
	_pinoTras = pinoTras;
}

void Motor::tras()
{
	digitalWrite(_pinoTras, HIGH);
	digitalWrite(_pinoFrente, LOW);
}

void Motor::frente()
{
	digitalWrite(_pinoTras, LOW);
	digitalWrite(_pinoFrente, HIGH);
}

void Motor::parar()
{
	digitalWrite(_pinoTras, LOW);
	digitalWrite(_pinoFrente, LOW);
}

void Motor::alterarVelocidade(int velocidade) {
	analogWrite(_pinoVelocidade, velocidade);
}
