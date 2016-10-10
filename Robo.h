/*
  Robo.h - Biblioteca para controle das direções do robô.
  Criada por Henrique Nunes, 13 de agosto de 2016.
*/
#ifndef Robo_h
#define Robo_h

#include "Motor.h"

class Robo {
	public:
		Robo(Motor* motorEsquerda, Motor* motorDireita);
		void girarEsquerda();
		void girarDireita();
		void andarFrente();
		void andarTras();
		void parar();
		void alterarVelocidade(int velocidade);
	private:
		Motor* _motorEsquerda;
		Motor* _motorDireita;
};

#endif
