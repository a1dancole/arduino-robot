#ifndef __MATH__
#define __MATH__

#include <Arduino.h>

class Math
{
public:
	static int calculateDistance(const int i1, const int i2)
	{
		int minVal = min(i1, i2);
		int maxVal = max(i1, i2);
		return (maxVal - minVal);
	}
};

#endif
