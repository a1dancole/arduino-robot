#ifndef __DRIVERBASE__
#define __DRIVERBASE__

class DriverBase
{
  public:
    DriverBase(int pSafetyDistanceInCM, DistanceUnit &pDistUnit, MotorUnit &pMotorUnit) : safetyDistanceInCM(pSafetyDistanceInCM), distUnit(pDistUnit), motorUnit(pMotorUnit);
    virtual ~DriverBase();
    virtual int processCommand();

  protected:
    int checkFrontForObstacles(Command cmd);
    MotorUnit &backOut();
};

#endif