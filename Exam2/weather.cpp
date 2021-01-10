#include <iostream>
#include "test_helpers.h"
#define EXPECT_DBL_EQ(X, Y) EXPECT_NEAR(X, Y)
#include "weatherFunctions.h"
#include <string>
using std:: cout, std::endl;
int main() {
    bool pass;
    size_t cities = 0, days = 0;
    double** table = nullptr;
    EXPECT_NO_THROW(table = add_cities_from_file(table, cities, days, "cities_0.txt"));
    EXPECT_EQ(cities, 10);
    EXPECT_EQ(days, 192);
    ASSERT_NE(table, nullptr);
    cout << "debug line 15" << endl;
    if (table) {
      EXPECT_DBL_EQ(table[1][33], 13.51);
      EXPECT_DBL_EQ(table[3][118], 0.56);
      EXPECT_DBL_EQ(table[7][104], 19.05);
    }
    EXPECT_DBL_EQ(get_average_rainfall_between_days_given_city(table, cities, days, 164, 178, 2), 12.1673);
    cout << __LINE__ << endl;
    EXPECT_DBL_EQ(get_average_rainfall_between_days_all_cities(table, cities, days, 106, 189), 9.85533);
    cout << __LINE__ << endl;
    EXPECT_DBL_EQ(get_max_rainfall_all_cities_given_day(table, cities, days, 65), 13.07);
    cout << __LINE__ << endl;
    EXPECT_DBL_EQ(get_max_rainfall_given_city(table, cities, days, 3), 19.96);
    cout << __LINE__ << endl;
    EXPECT_NO_THROW(table = add_cities_from_file(table, cities, days, "cities_1.txt"));
    cout << __LINE__ << endl;
    EXPECT_EQ(cities, 32);
    cout << __LINE__ << endl;
    EXPECT_EQ(days, 192);
    cout << __LINE__ << endl;
    ASSERT_NE(table, nullptr);
    if (table) {
      EXPECT_DBL_EQ(table[19][159], 15.11);
      EXPECT_DBL_EQ(table[23][74], 4.63);
      EXPECT_DBL_EQ(table[27][88], 7.24);
    }
    cout << __LINE__ << endl;
    EXPECT_DBL_EQ(get_average_rainfall_between_days_given_city(table, cities, days, 142, 144, 27), 7.88667);
    EXPECT_DBL_EQ(get_average_rainfall_between_days_all_cities(table, cities, days, 70, 153), 9.97377);
    EXPECT_DBL_EQ(get_max_rainfall_all_cities_given_day(table, cities, days, 69), 19.6);
    EXPECT_DBL_EQ(get_max_rainfall_given_city(table, cities, days, 15), 19.95);
    EXPECT_NO_THROW(table = add_cities_from_file(table, cities, days, "cities_2.txt"));
    cout << __LINE__ << endl;
    EXPECT_EQ(cities, 53);
    EXPECT_EQ(days, 192);
    ASSERT_NE(table, nullptr);
    cout << __LINE__ << endl;
    if (table) {
      EXPECT_DBL_EQ(table[33][176], 14.22);
      EXPECT_DBL_EQ(table[45][20], 6.1);
      EXPECT_DBL_EQ(table[47][135], 1.35);
      EXPECT_DBL_EQ(table[48][51], 14.76);
    }
    cout << __LINE__ << endl;
    EXPECT_DBL_EQ(get_average_rainfall_between_days_given_city(table, cities, days, 148, 175, 37), 11.0261);
    EXPECT_DBL_EQ(get_average_rainfall_between_days_all_cities(table, cities, days, 104, 151), 9.9566);
    EXPECT_DBL_EQ(get_max_rainfall_all_cities_given_day(table, cities, days, 67), 20);
    EXPECT_DBL_EQ(get_max_rainfall_given_city(table, cities, days, 46), 20);
    cout << __LINE__ << endl;
    EXPECT_NO_THROW(destroy_table(table, cities));
    cout << __LINE__ << endl;
      
}