#include <Arduino.h>

#define DEBUG_THE_CAR 0
#define TEST_THE_CAR 1

#include "Car/Car.h"
#include "Car/CarConfig.h"

Car * car = 0;

void setup()
{
	CarConfig * carConfig = new CarConfig();
	carConfig->SAFETY_DISTANCE_CM = 30;
	carConfig->serialConfig.BAUD_RATE = 9600;
	carConfig->distanceUnitConfig.SERVO_RIGHT = 20;
	carConfig->distanceUnitConfig.SERVO_LEFT = 180;
	carConfig->motorUnitConfig.SPEED = 170;

	car = new Car(carConfig);
	car->setup();

	if (TEST_THE_CAR)
	{
		car->testDistanceUnit();
	}
}

void loop()
{
	car->drive();
}
