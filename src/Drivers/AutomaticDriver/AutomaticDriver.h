#ifndef __AUTOMATICDRIVER__
#define __AUTOMATICDRIVER__

#include "Drivers/DriverBase.h"

class AutomaticDriver
{
  public:
    AutomaticDriver(int pSafetyDistanceInCM, DistanceUnit &pDistUnit, MotorUnit &pMotorUnit) : DriverBase(pSafetyDistanceInCM, pDistUnit, pMotorUnit);
    virtual ~AutomaticDriver();
    virtual int processCommand();

  private:
    MotorUnit &adjustPositionForDirection(int direction);
};

#endif
