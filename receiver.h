#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
#include <assert.h>

struct TemperatureStatistics
{
  float minimumReadings;
  float maximumReadings;
  float simpleMovingAvg;
};
struct StateOfChargeStatistics
{
  float minimumReadings;
  float maximumReadings;
  float simpleMovingAvg;
};

struct BatteryStatistics
{     
  TemperatureStatistics tempereatureStats;
  StateOfChargeStatistics stateOfChargeStats;
};

void DisplayReadingsOnConsole(std::string msg, char Delimiter, float value);
float getMinimumTemperatureReadings(std::vector<float> temperatureReadings);
float getMaximumTemperatureReadings(std::vector<float> temperatureReadings);
float getMinimumStateOfChargeReadings(std::vector<float> stateOfChargeReadings);
float getMaximumStateOfChargeReadings(std::vector<float> stateOfChargeReadings);
float getSimpleMovingAverage(std::vector<float> readings);
BatteryStatistics computeStatistics(std::vector<float> temperatureReadings , std::vector<float> stateOfChargeReadings);
void DisplayTemperatureStats(TemperatureStatistics tempStats);
void DisplayStateOfChargeStats(StateOfChargeStatistics socStats);


 
