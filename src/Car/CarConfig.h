#ifndef __CARCONFIG__
#define __CARCONFIG__

#include <Arduino.h>

class CarConfig
{
  public:
	class DistanceUnitConfig
	{
	  public:
		uint8_t ECHO_PIN = PIN_A4;
		uint8_t TRIGGER_PIN = PIN_A5;
		int SERVO_PIN = 3;
		int SERVO_RIGHT = 20; // taking 20 as default instead of 0, since sometimes the servo seems to have issues with value 0
		int SERVO_LEFT = 160; // taking 160 as default instead of 180, since sometimes the servo may have issues with value 180
	};

	class MotorUnitConfig
	{
	  public:
		int SPEED = 170;
	};

	class SerialConfig
	{
	  public:
		unsigned long BAUD_RATE = 9600;
	};

	int SAFETY_DISTANCE_CM = 30;
	DistanceUnitConfig distanceUnitConfig;
	MotorUnitConfig motorUnitConfig;
	SerialConfig serialConfig;
};

#endif
