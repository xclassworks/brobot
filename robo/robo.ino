#include "Motor.h"
#include "Robo.h"

// Commands
#define STOP                    83
#define MOVE_FORWARD            70
#define MOVE_BACKWARDS          66
#define ROTATE_LEFT             76
#define ROTATE_RIGHT            82

int command;

// Motor A
// Verde 6
// Amarelo 12 
// Vermelho 13
Motor motorEsquerda(6, 12, 13);

// Motor B
// Verde 5
// Amarelo 11
// Vermelho 10
Motor motorDireita(5, 10, 11);

Robo robo(&motorEsquerda, &motorDireita);

void setup() {
  robo.alterarVelocidade(255);

  Serial.begin(115200);
}

void loop() {
    int availableBytes = Serial.available();

    //robo.parar();
    delay(10);

    if (availableBytes >= 1) {
        command = Serial.read();

        Serial.println(command);

        switch (command) {
                break;
            case MOVE_FORWARD:
                robo.andarFrente();
                break;
            case MOVE_BACKWARDS:
                robo.andarTras();
                break;
            case ROTATE_LEFT:
                robo.girarDireita();
                break;
            case ROTATE_RIGHT:
                robo.girarEsquerda();
                break;
            case STOP:
                robo.parar();
                break;
        }

        //delay(2500);
    }
}

