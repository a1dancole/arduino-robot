#ifndef __CAR__
#define __CAR__

#include "CarConfig.h"

class Car
{
public:
  Car(CarConfig *pCarConfig);
  int setup();
  int drive();
  void testDistanceUnit();

private:
  void initializeDrivers();
};

#endif