#include <iostream>
#include "cstring.h"

unsigned int length(char str[]) {
  int i;
  for(i =0; str[i]!= '\0'; i++)
  {
  }
  return i;
}

unsigned int find(char str[], char character) {
  int i;
  for(i = 0; str[i]!= character && str[i] != '\0'; i++)
  {
  }
  return i;
}

bool equalStr(char str1[], char str2[]) {
  // returns true if they are equal and false if they are not
  return true;
}