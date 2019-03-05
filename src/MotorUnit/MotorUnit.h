#ifndef __MOTORUNIT__
#define __MOTORUNIT__

class Action
{
  public:
    Action();
    virtual void execute();
    virtual ~Action();
};

class DriveAction : public Action
{

  public:
    DriveAction(
        uint8_t pPin1, uint8_t pVal1,
        uint8_t pPin2, uint8_t pVal2,
        uint8_t pPin3, uint8_t pVal3,
        uint8_t pPin4, uint8_t pVal4) : Action();
    virtual void execute();
    virtual ~DriveAction();
};

class MotorUnit : public Base, public InterruptibleUnit
{
  private:
    CarConfig::MotorUnitConfig &config;

  public:
    MotorUnit(CarConfig::MotorUnitConfig &pMotorUnitConfig) : Base(),              //
                                                              InterruptibleUnit(), //
                                                              config(pMotorUnitConfig);
    MotorUnit &setup();
    MotorUnit &moveForwards(int delayMS = 0);
    MotorUnit &moveBackwards(int delayMS = 500);
    MotorUnit &turnLeft(int delayMS = 500);
    MotorUnit &turnHalfLeft(int delayMS = 250);
    MotorUnit &turnRight(int delayMS = 500);
    MotorUnit &turnHalfRight(int delayMS = 250);
    MotorUnit &stopMoving(int delayMS = 250);

  private:
    MotorUnit &powerOnWheels();
    MotorUnit &stopWheels();
    MotorUnit &moveWheelsForTime(uint8_t valIn1, uint8_t valIn2, uint8_t valIn3, uint8_t valIn4, int timeMS);
    MotorUnit &runInterruptableAction(Action &action, int delayTotalMS, int delayIncrementMS = 50);
    MotorUnit &printMovement(int delayMs, Command cmd);
};

#endif