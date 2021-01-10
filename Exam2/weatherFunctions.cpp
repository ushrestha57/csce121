#include <iostream>
#include "weatherFunctions.h"
#include <string>
#include <fstream>
using std::string, std::invalid_argument, std::ifstream, std::cout, std::endl;
// add function definitions
double** add_cities_from_file(double** array, size_t& numCities, size_t& numDays, string filename){
    ifstream ifs(filename); //open file
    if(!ifs.is_open())
    {
        throw invalid_argument("Unable to open file");
    }
    size_t fileCities,fileDays;
    ifs >> fileCities >> fileDays;
    if(array == nullptr)
    {
        numCities = 0;
        numDays = 0;
        array = new double*[fileCities];
        for(size_t i = 0; i < fileCities; ++i)
        {
            array[i] = new double[fileDays];
        }
    }
    else
    {
        if(fileDays != numDays)
        {
            throw invalid_argument("Invalid Days");
        }
        double** newArray = new double*[fileCities + numCities];
        for(size_t i = 0; i < numCities+fileCities; ++i) //allocate 2d array
        {
            newArray[i] = new double[numDays];
        }
        for(size_t i = 0; i < numCities; ++i) //move over values
        {
            for(size_t j = 0; j < numDays; ++j)
            {
                newArray[i][j] = array[i][j];
            }
        }
        destroy_table(array,numCities);
        array = newArray;
    }
    double value;
    size_t count  = 0;
    while(ifs >> value)
    {
        if(count == (fileDays) * (fileCities))
        {
            throw invalid_argument("Too many");
        }
        array[count/fileDays+numCities][count%fileDays] = value;
        count++;
    }    
    if(count != (fileDays) * (fileCities))
    {
        throw invalid_argument("Too little values in file");
    }
    numCities+=fileCities;
    numDays = fileDays;
    return array;
}
double get_average_rainfall_between_days_given_city(double** table, size_t numCities, size_t numDays, size_t startDays, size_t endDays, size_t cityIndex){
    if(table == nullptr)
    {
        throw invalid_argument("Table is nullptr");
    }
    if(cityIndex >= numCities)
    {
        throw invalid_argument("invalid city index");
    }
    if(startDays >= numDays)
    {
        throw invalid_argument("invalid day index");
    }
    if(endDays >= numDays || endDays < startDays)
    {
        throw invalid_argument("invalid day index");
    }
    double sum = 0;
    for(size_t i = startDays; i <= endDays; ++i)
    {
        sum+= table[cityIndex][i];
    }
    return sum / (endDays-startDays+1);
}
void destroy_table(double** array, size_t numCities){
    if(array == nullptr)
    {
        throw invalid_argument("nullptr");
    }
    if(numCities == 0)
    {
        throw invalid_argument("0 Cities");
    }
    for(size_t i = 0; i < numCities; ++i)
    {
        delete[] array[i];
    }
    delete[] array;
    numCities = 0;
    array = nullptr;
}
double get_average_rainfall_between_days_all_cities(double** array, size_t numCities, size_t numDays, size_t startDay, size_t endDay)
{
    if(array == nullptr)
    {
        throw invalid_argument("Table is nullptr");
    }
    if(startDay >= numDays)
    {
        throw invalid_argument("invalid city index");
    }
    if(endDay >= numDays || endDay < startDay)
    {
        throw invalid_argument("invalid day index");
    }
    double sum = 0;
    for(size_t i = 0; i < numCities; ++i)
    {
        for(size_t j = startDay; j <= endDay; ++j)
        {
            sum+= array[i][j];
        }
    }
    return sum / (numCities * (endDay - startDay + 1));

}
double get_max_rainfall_all_cities_given_day(double** table,size_t numCities, size_t numDays, size_t dayIndex){
    cout << "NUMDAYS: " << numDays << endl;
    if(table == nullptr)
    {
        throw invalid_argument("Table is a nullptr");
    }
    if(numCities == 0)
    {
        throw invalid_argument("0 cities");
    }
    if(dayIndex >= numDays)
    {
        throw invalid_argument("Day index out of bounds");
    }
    double max = 0;
    for(size_t i = 0; i < numCities; ++i)
    {
        cout << "I,DAYINDEX:" << i <<  "," << dayIndex << endl;
        if(table[i][dayIndex] > max)
        {
            max = table[i][dayIndex];
        }
    }
    return max;


}
double get_max_rainfall_given_city(double** table, size_t numCities, size_t numDays, size_t cityIndex){
    if(table == nullptr)
    {
        throw invalid_argument("Table is a nullptr");
    }
    if(numDays == 0)
    {
        throw invalid_argument("0 Days");
    }
    if(cityIndex >= numCities)
    {
        throw invalid_argument("City index out of bounds");
    }
    double max = 0;
    for(size_t i = 0; i < numDays; ++i)
    {
        if(table[cityIndex][i] > max)
        {
            max = table[cityIndex][i];
        }
    }
    return max;

}
void print(double** array, size_t numCities, size_t numDays){
    for(size_t i = 0; i < numCities; ++i)
    {
        for(size_t j = 0; j < numDays; ++j)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

