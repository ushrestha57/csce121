#include <iostream>
#include <fstream>
#include <string>
#include "taxi_trips.h"
using std::string, std::ifstream, std::cin, std::cout, std::endl;

int main() {
  const unsigned int MAX_TRIPS = 10000;
  double duration[MAX_TRIPS];
  double distance[MAX_TRIPS];
  double fare[MAX_TRIPS];
  double tip[MAX_TRIPS];
  string paymentMethods[MAX_TRIPS];
  string validPayment[] = {"CreditCard", "Cash", "NoCharge", "Unknown"};

  int invalidData = 0;

  string inputFile;
  cout << "Enter name of input file: ";
  cin >> inputFile;

  ifstream fileReader;
  fileReader.open(inputFile);
  if(!fileReader.is_open())
  {
      cout << "Can't open " << inputFile << endl;
      exit(EXIT_FAILURE);
  }
  int arrayIndex = 0;
  // input format :str, int ,double, double double, str
  while (!fileReader.eof())
{   string waste;
    double tempDuration;
    double tempDistance;
    double tempFare;
    double tempTip;
    string tempPayment;
    fileReader >> waste >> tempDuration >> tempDistance >> tempFare >> tempTip >> tempPayment;

    if(valid_trip_miles(tempDistance) && valid_trip_seconds(tempDuration) &&valid_revenue(tempFare,tempTip) && valid_logic(tempDuration,tempDistance,tempFare) && is_payment_valid(tempPayment,validPayment,4))
    {
        duration[arrayIndex] = tempDuration;
        distance[arrayIndex] = tempDistance;
        fare[arrayIndex] = tempFare;
        tip[arrayIndex] = tempTip;
        paymentMethods[arrayIndex] = tempPayment;
        arrayIndex++;
    }
    else
    {
        invalidData++;
    }
  }
  int size = arrayIndex;
  cout << "Number of trips: " << size << endl;
  cout << "Number of trips with invalid data: " << invalidData  << endl;
  cout << "Duration: max " << static_cast<int>(max(duration,size)) << " min " << static_cast<int>(min(duration,size)) << " avg " << average(duration,size) << " mode " << static_cast<int>(mode(duration,size)) << endl; 
  cout << "Distance: max " << max(distance,size) << " min " << min(distance,size) << " avg " << average(distance,size) << " mode " << mode(distance,size) << endl;
  cout << "Fare: max " << max(fare,size) << " min " << min(fare,size) << " avg " << average(fare,size) << " mode " << mode(fare,size) << endl; 
  cout << "Tip: max " << max(tip,size) << " min " << min(tip,size) << " avg " << average(tip,size) << " mode " << mode(tip,size) << endl;
  cout << "Length of longest sequence without tips: " << length_longest_seq_zeros(tip,size);
  return 0;
}