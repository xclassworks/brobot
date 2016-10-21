#include "Motor.h"
#include "Robo.h"

// Commands
#define STOP                    83
#define MOVE_FORWARD            70
#define MOVE_BACKWARDS          66
#define ROTATE_LEFT             76
#define ROTATE_RIGHT            82
#define CAMERA_MOVE_FORWARD     70
#define CAMERA_MOVE_BACKWARDS   66
#define CAMERA_ROTATE_LEFT      76
#define CAMERA_ROTATE_RIGHT     82

int command;
#include <AFMotor.h>

AF_DCMotor motorLeft(3);
AF_DCMotor motorRight(4);

void setup() {
    Serial.begin(115200);
}

void _enableSpeed() {
    motorLeft.setSpeed(255);
    motorRight.setSpeed(255);

    delay(100);
}

void _disableSpeed() {
    motorLeft.setSpeed(0);
    motorRight.setSpeed(0);

    delay(500);
}

void freeze() {
    _disableSpeed();

    motorLeft.run(RELEASE);
    motorRight.run(RELEASE);
}

void goFoward() {
    _enableSpeed();

    motorLeft.run(FORWARD);
    motorRight.run(FORWARD);
}

void goBack() {
    _enableSpeed();

    motorLeft.run(BACKWARD);
    motorRight.run(BACKWARD);
}

void goLeft() {
    _enableSpeed();

    motorLeft.run(BACKWARD);
    motorRight.run(FORWARD);
}

void goRight() {
    _enableSpeed();

    motorLeft.run(FORWARD);
    motorRight.run(BACKWARD);
}

void loop() {
    int availableBytes = Serial.available();

    if (availableBytes >= 1) {
        command = Serial.read();

        Serial.println(command);

        switch (command) {
            case MOVE_FORWARD:
                goFoward();
                break;
            case MOVE_BACKWARDS:
                goBack();
                break;
            case ROTATE_LEFT:
                goLeft();
                break;
            case ROTATE_RIGHT:
                goRight();
                break;
            case STOP:
                freeze();
                break;
        }

        delay(2500);
    }
}
