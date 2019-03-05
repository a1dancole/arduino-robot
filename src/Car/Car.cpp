#include <Arduino.h>
#include "Car.h"
#include "Helpers/Constants.h"
#include "CarConfig.h"
#include "DistanceUnit/DistanceUnit.h"
#include "MotorUnit/MotorUnit.h"
#include "Drivers/AutomaticDriver/AutomaticDriver.h"

class Car
{
private:
	CarConfig *carConfig;
	DistanceUnit distUnit;
	MotorUnit motorUnit;
	DriverBase *drivers[5];
	DriverBase *currentDriver = 0;

	int safetyDistanceInCM;

public:
	Car(CarConfig *pCarConfig) : carConfig(pCarConfig),										//
															 distUnit(carConfig->distanceUnitConfig), //
															 motorUnit(carConfig->motorUnitConfig),		//
															 safetyDistanceInCM(carConfig->SAFETY_DISTANCE_CM)
	{
	}

	int setup()
	{
		Serial.begin(carConfig->serialConfig.BAUD_RATE);
		distUnit.setup();
		distUnit.registerCommandReader(&commandReader);
		motorUnit.setup();
		motorUnit.registerCommandReader(&commandReader);

		initializeDrivers();

		return Constants::OK;
	}

private:
	void initializeDrivers()
	{
		new AutomaticDriver(safetyDistanceInCM, distUnit, motorUnit);
	}

public:
	int drive()
	{
		return currentDriver->processCommand(ElegooCommand::NO_COMMAND);
	}
	void testDistanceUnit()
	{
		Serial.println("Test Distance Unit");
		distUnit.frontDistance();
		distUnit.test();
		distUnit.frontDistance();
		Serial.println();
	}
};
