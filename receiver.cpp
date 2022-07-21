#include "receiver.h"
using namespace std;

void getSingleStreamOfValues(int dataStream[])
{
    int idx;
    scanf("%*s", &dataStream); // Skip parameter string at beginning of stream
    for (idx = 0; idx < 50 ; idx++)
    {
        scanf("%i", &dataStream[idx]);
    }
     std::cout << "dataStream : " << dataStream[5] << std::endl;
}

void DisplayReadingsOnConsole(std::string msg, char Delimiter, float value)
{
     std::cout << msg << Delimiter << value << std::endl;
}
float getMinimumTemperatureReadings(std::vector<float> temperatureReadings)
{
      float min = *min_element(temperatureReadings.begin(), temperatureReadings.end());
      return min;
}
float getMaximumTemperatureReadings(std::vector<float> temperatureReadings)
{
    float max = *max_element(temperatureReadings.begin(), temperatureReadings.end());
    return max;
}
float getMinimumStateOfChargeReadings(std::vector<float> stateOfChargeReadings)
{
      float min = *min_element(stateOfChargeReadings.begin(), stateOfChargeReadings.end());
      return min;
}
float getMaximumStateOfChargeReadings(std::vector<float> stateOfChargeReadings)
{
    float max = *max_element(stateOfChargeReadings.begin(), stateOfChargeReadings.end());
    return max;
}
float getSimpleMovingAverage(std::vector<float> readings)
{
   float sum = 0, simpleMovingAvg = 0;
   int totalCount = 0;
   totalCount = readings.size();
   for(int i = 0; i < totalCount; i++)
   {
       sum +=readings[i];
    }
    simpleMovingAvg=(sum/totalCount);
    return simpleMovingAvg;
}

BatteryStatistics computeStatistics(std::vector<float> temperatureReadings , std::vector<float> stateOfChargeReadings)
{
  TemperatureStatistics tempStats;
  StateOfChargeStatistics socStats;
  BatteryStatistics batteryStats;
  
  //Process Temperature Readings
  tempStats.minimumReadings = getMinimumTemperatureReadings(temperatureReadings);
  tempStats.maximumReadings = getMaximumTemperatureReadings(temperatureReadings);
  tempStats.simpleMovingAvg = getSimpleMovingAverage(temperatureReadings);
  
  //Process State Of Charge Readings
  socStats.minimumReadings = getMinimumStateOfChargeReadings(stateOfChargeReadings);
  socStats.maximumReadings = getMaximumStateOfChargeReadings(stateOfChargeReadings);
  socStats.simpleMovingAvg = getSimpleMovingAverage(stateOfChargeReadings);
  
  batteryStats.tempereatureStats = tempStats;
  batteryStats.stateOfChargeStats = socStats;
  
  return batteryStats;
}

void DisplayTemperatureStats(TemperatureStatistics tempStats)
{
     DisplayReadingsOnConsole("Temperature Minimum",':',tempStats.minimumReadings);
     DisplayReadingsOnConsole("Temperature Maximum",':',tempStats.maximumReadings);
     DisplayReadingsOnConsole("Temperature Average",':',tempStats.simpleMovingAvg);
}


void DisplayStateOfChargeStats(StateOfChargeStatistics socStats)
{
     DisplayReadingsOnConsole("SOC Minimum",':',socStats.minimumReadings);
     DisplayReadingsOnConsole("SOC Maximum",':',socStats.maximumReadings);
     DisplayReadingsOnConsole("SOC Average",':',socStats.simpleMovingAvg);
     
     int temperatureDataStream[50];
     getSingleStreamOfValues(&temperatureDataStream[0]);


    printf("TEMPERATURE");
    for (idx = 0; idx < 50; idx++)
    {
        printf(" %i", temperatureDataStream[idx]);
    }
    printf("\n");
}
