#ifndef __DISTANCEUNIT__
#define __DISTANCEUNIT__

class DistanceData
{
public:
  int direction;
  int distance;
};

class DistanceUnit
{
public:
  boolean isFarRightDirection(const int direction);
  boolean isFarLeftDirection(const int direction);
  void setup();
  void test();
  int frontDistance();
  int rightDistance();
  int leftDistance();
  DistanceData scanBiggestDistance();

private:
  const char *getDirectionString(const int direction);
  void setDirection();
  void setDirection(const int direction);
  void debugOrgVsAdjDirection(int direction, int adjustedDirection);
  int readDistance();
  void scanDistances(DistanceData distances[]);
  DistanceData readDistanceDataForDirection(const int direction);
  int readDistanceForDirection(const int direction);
  void debugDistanceForDirection(const int direction, const int distance);
  int getServoMinPos();
  int getServoMaxPos();
};

#endif