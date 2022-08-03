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
  float stateOfChargeSMA = 0; // SMA - Simple Moving Avergae
  float expectedSMA = 70.4;
  std::vector<float> stateofChargeReadings = {60,68,70,74,80};
  stateOfChargeSMA = getSimpleMovingAverage(stateofChargeReadings);
  assert(stateOfChargeSMA == expectedSMA); 
}

//Test SimpleMovingAvergae of Temperature
void TestTemperatureSimpleMovingAverage()
{
  float temperatureSMA = 0; // SMA - Simple Moving Avergae
  float expectedSMA = 13.4;
  std::vector<float> temperatureReadings = {10,2,30,20,5};
  temperatureSMA = getSimpleMovingAverage(temperatureReadings);
  assert(temperatureSMA == expectedSMA); 
}

//Test Battery Statistics
void TestBatteryStatistics()
{
  BatteryStatistics batteryStats;
  std::vector<float> temperatureReadings = {10,2,30,20,5};
  std::vector<float> stateofChargeReadings = {60,68,70,74,80};
  float expectedTemperatureSMA = 13.4;
  float expectedSOCSMA = 70.4;
  batteryStats = computeStatistics(temperatureReadings,stateofChargeReadings);

  // Test Temperature Stats
  assert(batteryStats.tempereatureStats.minimumReadings == 2);
  assert(batteryStats.tempereatureStats.maximumReadings == 30);
 // assert(batteryStats.tempereatureStats.simpleMovingAvg == expectedTemperatureSMA);
  //Test StateOfChargeStats
  assert(batteryStats.stateOfChargeStats.minimumReadings == 60);
  assert(batteryStats.stateOfChargeStats.maximumReadings == 80);
  assert(batteryStats.stateOfChargeStats.simpleMovingAvg == expectedSOCSMA);
}

//Test to Check Sender Data Received by receiver 
void TestReceiver()
{
  BatteryStatistics batteryStats;
  float temperatureSMA = 34.52; // SMA - Simple Moving Avergae
  float expectedSMA = 70.2;
  float temperatureMin,temperatureMax;

  batteryStats = processReceiverData();
  DisplayTemperatureStats(batteryStats.tempereatureStats);
  DisplayStateOfChargeStats(batteryStats.stateOfChargeStats);
  
  /*Test Temperature Stats*/
  assert(batteryStats.tempereatureStats.minimumReadings == 2); 
  assert(batteryStats.tempereatureStats.maximumReadings == 60); 
  assert(batteryStats.tempereatureStats.simpleMovingAvg == temperatureSMA); 
  
   /*Test State of Charge Stats*/
  assert(batteryStats.stateOfChargeStats.minimumReadings == 60); 
  assert(batteryStats.stateOfChargeStats.maximumReadings == 80); 
  assert(batteryStats.stateOfChargeStats.simpleMovingAvg == expectedSMA); 
  
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
  TestReceiver();
  return 0;
}
  
