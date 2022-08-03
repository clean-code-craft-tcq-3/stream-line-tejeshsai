#include "receiver.h"
using namespace std;

void DisplayReadingsOnConsole(std::string msg, char Delimiter, float value)
{
     std::cout << msg << Delimiter << value << std::endl;
}
std::vector<std::string>  getLines()
{
     ifstream inputFileStream;
     inputFileStream.open("./receiver.txt");
     vector<string> linesVector;
     string line;
     while (inputFileStream.peek() != EOF)
     {
        getline(inputFileStream, line, '\n');
        linesVector.push_back(line);
     }
    inputFileStream.close();
    return linesVector;
}
std::vector<float> readCommaSeperatedValues(std::string line)
{
    std::vector<float> readValues;
    stringstream ss(line);
    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        if (!substr.empty())
        {
           readValues.push_back(std::stof(substr)); // Convert String to Float.
        }
    }
    return readValues;
}
BMSParameters readBMSParametersFromFile()
{
   vector<std::string> lines;
   BMSParameters bmsParameter;  
   lines = getLines();
   bmsParameter.stateOfChargeReadings = readCommaSeperatedValues(lines[1]); // Read State of Charge Values from Second line.
   bmsParameter.temperatureReadings = readCommaSeperatedValues(lines[3]); // Read Temperature Values from Fourth line.
   return bmsParameter;
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
}

BatteryStatistics processReceiverData()
{
     BMSParameters bmsParameters;
     BatteryStatistics batteryStatistics;
 
     bmsParameters = readBMSParametersFromFile();
     batteryStatistics = computeStatistics(bmsParameters.temperatureReadings,bmsParameters.stateOfChargeReadings); 
     return batteryStatistics;
}
