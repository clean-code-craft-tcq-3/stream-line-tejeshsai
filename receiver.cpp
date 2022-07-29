#include "receiver.h"
using namespace std;

void DisplayReadingsOnConsole(std::string msg, char Delimiter, float value)
{
     std::cout << msg << Delimiter << value << std::endl;
}
std::vector<std::string>  getLinesfromConsole()
{
     cout <<"getLinesfromConsole --" << endl;
     std::vector<std::string> vector_lines;
     std::string line = "";
     do{
         getline(cin,line,'\n');
         vector_lines.push_back(line);
       }while(line != "");
     
     cout << "vector_lines[0] : " << vector_lines[0] <<endl;
    return vector_lines;
}
std::vector<float> readCommaSeperatedValues(std::string line)
{
    cout <<"readCommaSeperatedValues --" << endl;
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
BMSParameters readBMSParametersFromConsole()
{
   cout <<"readBMSParametersFromConsole --" << endl;
   vector<std::string> lines;
   BMSParameters bmsParameter;  
   lines = getLinesfromConsole();
   std::cout << "---Received data from Sender---" << std::endl;
     
   //Read Temperature
    std::cout << lines[0] << std::endl; // Read Temperature Title
    bmsParameter.temperatureReadings = readCommaSeperatedValues(lines[1]); // Read Temperature Values
   //Read StateofChatrge
    std::cout << lines[2] << std::endl; // Read State Of Charge Title
    bmsParameter.stateOfChargeReadings = readCommaSeperatedValues(lines[3]); // Read State of Charge Values
   
     return bmsParameter;
}
/*---------------*/
std::vector<float> getLinesfromConsole2()
{
        cout <<"getLinesfromConsole2 --" << endl;
    std::string line, value;
    std::vector<float> parameterValues;
    getline(std::cin, line);
    std::stringstream values(line);
    while(getline(values, value, ','))
    {
        parameterValues.push_back(std::stoi(value));
    }
    return parameterValues;
}
void parseBmsParameter(std::string line, BMSParameters  &bmsParameter)
{
    cout <<"parseBmsParameter --" << endl;

    std::string value;
    if(line.find("Charge") != std::string::npos)
    {
        bmsParameter.stateOfChargeReadings = getLinesfromConsole2();
    }
    else if(line.find("Heat") != std::string::npos)
    {
        bmsParameter.temperatureReadings = getLinesfromConsole2();
    }
}
BMSParameters  readBMSParametersFromConsole2()
{
   cout <<"readBMSParametersFromConsole2 --" << endl;

    std::string line;
    BMSParameters bmsParameter;
    while(getline(std::cin, line))
    {
        cout <<"while  getline--" << endl;
        parseBmsParameter(line, bmsParameter);
    }
    return bmsParameter;
}


/*-----------------*/

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
 
     bmsParameters = readBMSParametersFromConsole();
     batteryStatistics = computeStatistics(bmsParameters.temperatureReadings,bmsParameters.stateOfChargeReadings); 
     return batteryStatistics;
}
