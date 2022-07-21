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
  TemperatureStatistics tempereatureStats;
  StateOfChargeStatistics stateOfChargeStats;
}

std::vector<float> getTemperatureReadings(std::vector<float> temperatureReadings);
std::vector<float> getStateOfChargeReadings(std::vector<float> stateOfChargeReadings);
float getMinimumTemperatureReadings(std::vector<float> temperatureReadings);
float getMaximumTemperatureReadings(std::vector<float> temperatureReadings);
float getMinimumStateOfChargeReadings(std::vector<float> stateOfChargeReadings);
float getMaximumStateOfChargeReadings(std::vector<float> stateOfChargeReadings);
float getSimpleMovingAverage(std::vector<float> readings);
BatteryStatistics computeStatistics(std::vector<float> temperatureReadings , std::vector<float> stateOfChargeReadings);
