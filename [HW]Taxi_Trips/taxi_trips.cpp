#include <string>
#include "taxi_trips.h"
#include <iostream>

using std::string;
using std::invalid_argument;

bool is_payment_valid(string type, string valid_types[], unsigned int size) {
    int newSize = size;
    if(newSize < 1) //throws invalid argument if size is 0 or negative
    {
        throw invalid_argument("Invalid Input.");
    }
    for(int i = 0; i < newSize; i++) 
    {
        if(type == valid_types[i]) //if we found the payment type in the array then it returns true
        {
            return true;
        }
    }
  //we don't need an else statement. otherwise it just returns false.
  return false;
}

double max(double values[], unsigned int size) {
  int newSize = size;
  if(newSize < 1) //throws invalid argument if size is 0 or negative
    {
        throw invalid_argument("Invalid Input.");
    }
  double max = values[0];
  for(int i = 1; i < newSize; i++) 
    {
        if(max < values[i]) //if we max is smaller than the current value in the array, max becomes that value
        {
            max = values[i];
        }
    }
  
  return max;
}

double min(double values[], unsigned int size) {
  int newSize = size;
  if(newSize < 1) //throws invalid argument if size is 0 or negative
    {
        throw invalid_argument("Invalid Input.");
    }
  double min = values[0];
  for(int i = 1; i < newSize; i++) 
    {
        if(min > values[i]) //if we min is bigger than the current value in the array, min becomes that value
        {
            min = values[i];
        }
    }
  
  return min;
}

double average(double values[], unsigned int size) {
    int newSize = size;
    if(newSize < 1) //throws invalid argument if size is 0 or negative
    {
        throw invalid_argument("Invalid Input.");
    }
    double sum = values[0];
    for(int i = 1; i < newSize; i++)
    {
        sum+=values[i]; //adds up the values in the array
    }

  return sum / size;
}

int count_occurrences(double v, double values[], unsigned int size) {
    int newSize = size;
    if(newSize < 1) //throws invalid argument if size is 0 or negative
    {
        throw invalid_argument("Invalid Input.");
    }
    int occurances = 0; //holds the number of occurances 
    for(int i = 0; i < newSize; i++) //loops through values[]
    {
        if(v == values[i])
        {
            occurances++;
        }
    }
    return occurances;
}

double mode(double values[], unsigned int size) {
  int newSize = size;
  if(newSize < 1) //throws invalid argument if size is 0 or negative
    {
        throw invalid_argument("Invalid Input.");
    }
   int currentModeIndex = 0; //holds the current mode number
   int currentOccurances = 0; //holds the current index of the mode number
   for(int i = 0; i < newSize; i++)
   {
       int tempOccur = count_occurrences(values[i],values,newSize); 
       if( tempOccur > currentOccurances)//if the number of occurances for this number is > then mode becomes this  number
       {
           currentOccurances = tempOccur;
           currentModeIndex = i;
       }
   }
   return values[currentModeIndex]; 
}

int length_longest_seq_zeros(double values[], unsigned int size) {
    int newSize = size;
    if(newSize < 1) //throws invalid argument if size is 0 or negative
    {
        throw invalid_argument("Invalid Input.");
    }
  int currentSequence = 0; //holds the current sequence
  int maxSequence = 0;
  for(int i =0; i < newSize; i++)
  {
      if(values[i] == 0)
      {
          currentSequence++;
        if(currentSequence > maxSequence)
        {
          maxSequence = currentSequence;
        }
      }
      else
      {
          currentSequence = 0;
      }
      
  }
  return maxSequence;
}

bool valid_trip_seconds(const unsigned int seconds)
{
    if(seconds > 24*60*60)
    {
        return false;
    }
        return true;
}
bool valid_trip_miles(const double miles)
{
    if(miles > 1500)
    {
        return false;
    }
        return true;

}

bool valid_revenue(const double fare, const double tip)
{
    if(fare + tip > 5000)
    {
        return false;
    }
    return true;

}

bool valid_logic(const unsigned int seconds, const double miles, const double fare)
{
    if(seconds == 0 && miles == 0 && fare != 0)
    {
        return false;
    }
    return true;
}

