#include <iostream>
#include <vector>
#include<string>
#include <assert.h>

struct TemperatureStatistics
{
   minimumReadings;
   maximumReadings;
   simpleMovingAvg;
}
struct StateOfChargeStatistics
{
   minimumReadings;
   maximumReadings;
   simpleMovingAvg;
}

struct BatteryStatistics
{     
  TemperatureStatistics tempreatureStats;
  StateOfChargeStatistics stateOfChargeStats;
}
