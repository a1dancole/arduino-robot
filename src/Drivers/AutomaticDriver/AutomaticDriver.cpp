#include "Drivers/AutomaticDriver/AutomaticDriver.h"
#include "Drivers/DriverBase.h"
#include "DistanceUnit/DistanceUnit.h"
#include "MotorUnit/MotorUnit.h"
#include "DistanceUnit/"

// is interruptible
class AutomaticDriver : public DriverBase
{
  public:
	AutomaticDriver(int pSafetyDistanceInCM, DistanceUnit &pDistUnit, MotorUnit &pMotorUnit) : DriverBase(pSafetyDistanceInCM, pDistUnit, pMotorUnit)
	{
	}

	virtual ~AutomaticDriver()
	{
	}

	virtual int processCommand(Command cmd)
	{
		DistanceData biggestDistance = distUnit.scanBiggestDistance();
		distUnit.frontDistance(); // position "eyes" to the front
		adjustPositionForDirection(biggestDistance.direction);

		if (biggestDistance.distance < safetyDistanceInCM)
		{
			return backOut().statusOK();
		}

		int milliSeconds = biggestDistance.distance * 10;
		if (milliSeconds > 3000)
		{
			milliSeconds = 3000;
		}

		return motorUnit.moveForwards(milliSeconds).stopMoving().statusOK();
	}

  private:
	// is interruptible
	MotorUnit &adjustPositionForDirection(int direction)
	{
		if (motorUnit.hasCommand())
		{
			return motorUnit;
		}

		if (direction == DistanceUnit::HALF_LEFT)
		{
			return motorUnit.turnHalfLeft();
		}
		if (direction == DistanceUnit::HALF_RIGHT)
		{
			return motorUnit.turnHalfRight();
		}
		if (distUnit.isFarLeftDirection(direction))
		{
			return motorUnit.turnLeft();
		}
		if (distUnit.isFarRightDirection(direction))
		{
			return motorUnit.turnRight();
		}

		return motorUnit;
	}
};
