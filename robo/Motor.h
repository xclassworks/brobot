/*
  Motor.h - Biblioteca para controle de motor.
  Criada por Henrique Nunes, 13 de agosto de 2016.
*/
#ifndef Motor_h
#define Motor_h

class Motor {
	public:
		Motor(int pinoVelocidade, int pinoFrente, int pinoTras);
		void tras();
		void frente();
		void parar();
		void alterarVelocidade(int velocidade);
	private:
		int _pinoVelocidade;
		int _pinoFrente;
		int _pinoTras;
};

#endif
