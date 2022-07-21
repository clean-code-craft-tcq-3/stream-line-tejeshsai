#include "receiver.h"

//Test Minimum Temperature
void TestCheckMinimumTemperature()
{
  float temperatureMin;
  std::vector<float> temperatureReadings = {10,2,30,20,5};
  temperatureMin = getMinimumTemperatureReadings(temperatureReadings);
  assert(temperatureMin == 2); 
}

//Test Maximum Temperature
void TestCheckMaximumTemperature()
{
  float temperatureMax;
  std::vector<float> temperatureReadings = {10,2,30,20,5};
  temperatureMax = getMaximumTemperatureReadings(temperatureReadings);
  assert(temperatureMax == 30); 
}

//Test Minimum state of charge
void TestCheckMinimumStateofCharge()
{
  float stateOfChargeMin;
  std::vector<float> stateofChargeReadings = {60,68,70,74,80};
  stateOfChargeMin = getMinimumStateOfChargeReadings(stateofChargeReadings);
  assert(stateOfChargeMin == 60); 
}

//Test Maximum Temperature
void TestCheckMaximumStateofCharge()
{
  float stateOfChargeMax;
  std::vector<float> stateofChargeReadings = {60,68,70,74,80};
  stateOfChargeMax = getMaximumStateOfChargeReadings(stateofChargeReadings);
  assert(stateOfChargeMax == 80); 
}

//Test SimpleMovingAvergae of State Of Charge
void TestStaetOfChargeSimpleMovingAverage()
{
  float stateOfChargeSMA; // SMA - Simple Moving Avergae
  std::vector<float> stateofChargeReadings = {60,68,70,74,80};
  stateOfChargeSMA = getSimpleMovingAverage(stateofChargeReadings);
  assert(stateOfChargeSMA == 70.4); 
}

//Test SimpleMovingAvergae of Temperature
void TestTemperatureSimpleMovingAverage()
{
  float TemperatureSMA = 0; // SMA - Simple Moving Avergae
  float avg = 13.4;
  std::vector<float> temperatureReadings = {10,2,30,20,5};
  TemperatureSMA = getSimpleMovingAverage(temperatureReadings);
  DisplayReadingsOnConsole(" TemperatureSMA ",':',TemperatureSMA);
  assert(TemperatureSMA == avg); 
}

//Test Battery Statistics
void TestBatteryStatistics()
{
  BatteryStatistics batteryStats;
  std::vector<float> temperatureReadings = {10,2,30,20,5};
  std::vector<float> stateofChargeReadings = {60,68,70,74,80};
  batteryStats = computeStatistics(temperatureReadings,stateofChargeReadings);

  // Test Temperature Stats
  assert(batteryStats.tempereatureStats.minimumReadings == 2);
  assert(batteryStats.tempereatureStats.maximumReadings == 30);
 // assert(batteryStats.tempereatureStats.simpleMovingAvg == 13.4);
  //Test StateOfChargeStats
  assert(batteryStats.stateOfChargeStats.minimumReadings == 60);
  assert(batteryStats.stateOfChargeStats.maximumReadings == 80);
 // assert(batteryStats.stateOfChargeStats.simpleMovingAvg == 70.4);
}

void TestDisplayBatteryStats()
{
  BatteryStatistics batteryStatistics;
  std::vector<float> temperatureReadings = {5,7,25,10,1};
  std::vector<float> stateofChargeReadings = {62,64,70,74,80};
  batteryStatistics = computeStatistics(temperatureReadings,stateofChargeReadings);
  DisplayTemperatureStats(batteryStatistics.tempereatureStats);
  DisplayStateOfChargeStats(batteryStatistics.stateOfChargeStats);
}

int main()
{
  TestCheckMinimumTemperature();
  TestCheckMaximumTemperature();
  TestTemperatureSimpleMovingAverage();
  
  TestCheckMinimumStateofCharge();
  TestCheckMaximumStateofCharge();
 // TestStaetOfChargeSimpleMovingAverage();
  
  TestBatteryStatistics();
  TestDisplayBatteryStats();
  
  return 0;
}
  
