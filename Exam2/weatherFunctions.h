#ifndef WEATHERFUNCTIONS_H
#define WEATHERFUNCTIONS_H
#include <string>
using std::string;
// add function declarations/prototypes
double** add_cities_from_file(double** array, size_t& numCities, size_t& numDays, string filename);
double get_average_rainfall_between_days_all_cities(double** array, size_t numCities, size_t numDays, size_t startDay, size_t endDay);
double get_average_rainfall_between_days_given_city(double** table, size_t numCities, size_t numDays, size_t startDays, size_t endDays, size_t cityIndex);
double get_max_rainfall_all_cities_given_day(double** table,size_t numCities, size_t numDays, size_t dayIndex);
double get_max_rainfall_given_city(double** table, size_t numCities, size_t numDays, size_t cityIndex);
void print(double** array, size_t numCities, size_t numDays);
void destroy_table(double** array, size_t numCities);
#endif