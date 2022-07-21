#include "receiver.h"
using namespace std;

//Test Minimum Temperature
void TestCheckMinimumTemperature()
{
  float temperatureMin;
  temperatureMin = getMinimumTemperature(temperatureReadings);
  assert(temperatureMin == 0); 
}

//Test Maximum Temperature
void TestCheckMaximumTemperature()
{
  float temperatureMax;
  temperatureMax = getMaximumTemperature(temperatureReadings);
  assert(TemperatureMax == 0); 
}

//Test Minimum state of charge
void TestCheckMinimumStateofCharge()
{
  float stateOfChargeMin;
  stateOfChargeMin = getMinimumStateofCharge(stateofChargeReadings);
  assert(stateOfChargeMin == 60); 
}

//Test Maximum Temperature
void TestCheckMaximumStateofCharge()
{
  float stateOfChargeMax;
  stateOfChargeMax = getMaximumStateofCharge(stateofChargeReadings);
  assert(stateOfChargeMax == 80); 
}

//Test SimpleMovingAvergae of State Of Charge
void TestStaetOfChargeSimpleMovingAverage()
{
  float stateOfChargeSMA; // SMA - Simple Moving Avergae
  stateOfChargeSMA = getSimpleMovingAverage(stateofChargeReadings);
  assert(stateOfChargeSMA == 50); 
}

//Test SimpleMovingAvergae of Temperature
void TestTemperatureSimpleMovingAverage()
{
  float TemperatureSMA; // SMA - Simple Moving Avergae
  TemperatureSMA = getSimpleMovingAverage(temperatureReadings);
  assert(TemperatureSMA == 50); 
}

//Test Battery Statistics
void TestBatteryStatistics()
{
  BatteryStatistics batteryStats;
  batteryStats = computeStatistics(temperatureReadings,stateofChargeReadings);

  // Test Temperature Stats
  assert(batteryStats.tempereatureStats.minimumReadings == 0);
  assert(batteryStats.tempereatureStats.maximumReadings == 60);
  assert(batteryStats.tempereatureStats.simpleMovingAvg == 50);
  //Test StateOfChargeStats
  assert(batteryStats.stateOfChargeStats.minimumReadings == 60);
  assert(batteryStats.stateOfChargeStats.maximumReadings == 80);
  assert(batteryStats.stateOfChargeStats.simpleMovingAvg == 50);
}

int main()
{
  TestCheckMinimumTemperature();
  TestCheckMaximumTemperature();
  TestTemperatureSimpleMovingAverage();
  
  TestCheckMinimumStateofCharge();
  TestCheckMaximumStateofCharge();
  TestStaetOfChargeSimpleMovingAverage();
  
  TestBatteryStatistics();
  
  return 0;
}
  
