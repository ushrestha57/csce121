/*
DADA function definitions
*/

#include <iostream>
#include <cmath>
#include "dada.h"
using std::cout, std::endl, std::abs, std::sqrt;

int amax(const double x[], const unsigned int len) {
    int newLen = len;
    if(len == 0)
    {
        return -1;
    }
    int maxIndex = 0;
    for(int i =0; i < newLen; i++)
    {
        if(abs(x[i]) > abs(x[maxIndex]))
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

double asum(const double x[], const unsigned int len) {
    int newLen = len;
    double sum = 0;
    for(int i =0; i < newLen; i++)
    {
        sum += abs(x[i]);
    }
    return sum;
}

void axpy(const double a, const double x[], double y[], const unsigned int len) {
    int newLen = len;
    for(int i =0; i < newLen; i++)
    {
        y[i] += a * x[i];
    }
}

void copy(const double src[], double dest[], const unsigned int len) {
    int newLen = len;
    for(int i =0; i < newLen; i++)
    {
        dest[i] = src[i];
    }
}

double dot(const double x[], const double y[], const unsigned int len) {
    int newLen = len;
    double sum = 0;
    for(int i =0; i < newLen; i++)
    {
        sum += (x[i] * y[i]);
    }
    return sum;
}

double norm2(const double x[], const unsigned int len) {
    int newLen = len;
    double sum = 0;
    for(int i = 0; i < newLen; i++)
    {
        sum += x[i] * x[i];
    }
    return sqrt(sum);
}

void scale(const double a, double x[], const unsigned int len) {
    int newLen = len;
    for(int i =0; i < newLen; i++)
    {
        x[i] *= a;
    }
}

void swap(double x[], double y[], const unsigned int len) {
    int newLen = len;
    for(int i =0; i < newLen; i++)
    {
        double middleman = x[i];
        x[i] = y[i];
        y[i] = middleman;
    }
}
