#include "DriverBase.h"
#include "Helpers/Constants.h"
#include "DistanceUnit/DistanceUnit.h"
#include "MotorUnit/MotorUnit.h"

class DriverBase
{
  protected:
	int safetyDistanceInCM;
	DistanceUnit &distUnit;
	MotorUnit &motorUnit;

  public:
	DriverBase(int pSafetyDistanceInCM, DistanceUnit &pDistUnit, MotorUnit &pMotorUnit) : safetyDistanceInCM(pSafetyDistanceInCM), distUnit(pDistUnit), motorUnit(pMotorUnit)
	{
	}

	virtual ~DriverBase()
	{
	}

	virtual int processCommand(Command cmd) = 0;

  protected:
	int checkFrontForObstacles(Command cmd)
	{
		if (cmd == Command::NO_COMMAND || cmd == Command::MOVE_FORWARDS)
		{
			// check front sensor and stop
			const int frontDistance = distUnit.frontDistance();
			if (frontDistance < safetyDistanceInCM)
			{
				motorUnit.stopMoving();
				return Constants::STOPPED;
			}
		}

		return Constants::OK;
	}

	MotorUnit &backOut()
	{
		bool doBackOut = true;
		int rightDistance = 0;
		int leftDistance = 0;

		do
		{
			motorUnit.moveBackwards().stopMoving();
			rightDistance = distUnit.rightDistance();
			leftDistance = distUnit.leftDistance();

			doBackOut = (rightDistance <= safetyDistanceInCM) && (leftDistance <= safetyDistanceInCM);

		} while (doBackOut);

		// here either (rightDistance > safetyDistanceInCM) || (leftDistance > safetyDistanceInCM)
		if (rightDistance > safetyDistanceInCM)
		{
			return motorUnit.turnRight();
		}
		else
		{
			return motorUnit.turnLeft();
		}
	}
};
