#include "receiver.h"
using namespace std;

void mockReceiver(std::vector<float> temperature, std::vector<float> stateOfCharge)
{

}

void DisplayReadingsOnConsole(std::string msg, char Delimiter, float value)
{
     std::cout << msg << Delimiter << value << std::endl;
}
std::vector<float> getTemperatureReadings(std::vector<float> temperatureReadings, std::vector<float> stateOfCharge, std::vector<float> (*receiverData)(std::vector<float>, std::vector<float>))
{
     receiverData(temperatureReadings, stateOfCharge);
     return temperatureReadings;    
}
std::vector<float> getStateOfChargeReadings(std::vector<float> temperatureReadings, std::vector<float> stateOfCharge, std::vector<float> (*receiverData)(std::vector<float>, std::vector<float>))
{
     receiverData(temperatureReadings, stateOfCharge);
     return stateOfCharge;    
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
   float sum, simpleMovingAvg;
   int totalCount;
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
