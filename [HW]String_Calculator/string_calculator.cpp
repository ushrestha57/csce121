// my_string_calculator.cpp
#include <iostream>
#include "my_string.h"
#include "string_calculator.h"
using std::cout;
using std:: endl;
using std::invalid_argument;
using std::max;

unsigned int digit_to_decimal(char digit) {
    int toInt = digit-48;

    if(toInt > 9 || toInt< 0)
    {
        throw invalid_argument("Invalifsdd input");
    }
    return toInt;
}

char decimal_to_digit(unsigned int decimal) {
    int decHolder = decimal;
    if(decHolder > 9 || decHolder < 0)
    {
        throw invalid_argument("Invalid input");
    }
    char output = char(decHolder+48);
    
    return output;
}

my_string trim_leading_zeros(const my_string& num) {
    bool isNeg = false;
    my_string newNum = num;
    if(newNum.at(0) == '-')
    {
      newNum = newNum.substr(1,num.size());
      isNeg = true;
    }
    my_string concat = "";
    bool initialZeros = true;
    int numSize = newNum.size();
    for(int i = 0;i < numSize; i++)
    {
        if(!(initialZeros && newNum.at(i) == '0'))
        {
          concat+=newNum.at(i);
          initialZeros = false;
        }
    }
    if(isNeg)
      {
        concat = "-" + concat;
      }
    if(initialZeros)
    {
        concat = "0";
    }
    return concat;
}
bool smallerNumber(const my_string& lhs, const my_string& rhs)
{
    bool isLeftNeg = lhs.at(0) == '-';
    bool isRightNeg = rhs.at(0) == '-';
    int lhsSize = lhs.size();
    if(isLeftNeg && !isRightNeg)
    {
        return true;
    }
    else if(!isLeftNeg && isRightNeg){
        return false;

    }
    if(lhs.size() > rhs.size() && isLeftNeg && isRightNeg)
    {
        return true;
    }
    else if(lhs.size() < rhs.size() && isRightNeg && isLeftNeg)
    {
        return false;
    }
    else if(lhs.size() > rhs.size() && !isLeftNeg && !isRightNeg)
    {
        return false;
    }
    else if(lhs.size() < rhs.size() && !isLeftNeg && !isRightNeg)
    {
        return true;
    }
    else{
        for(int i =0; i < lhsSize; i++)
        {
            if(lhs.at(i) < rhs.at(i))
            {
                return true;
            }
            else if(lhs.at(i) > rhs.at(i))
            {
                return false;
            }
        
            
        }
    }
    return false;
}
my_string equalLength(my_string& str, int maxSize)
{
  for(int i = str.size(); i <maxSize; i++ )
  {
      str = "0" + str;
  }
  return str;
}
my_string reverse(my_string& str)
{
  my_string concat = "";
  for(int i = str.size()-1; i >= 0; i--)
  {
    concat+=str.at(i);
  }
  return concat;
}

my_string add(const my_string& lhs, const my_string& rhs) {
    bool isPos = true;
    my_string newRHS = rhs;
    my_string newLHS = lhs;
    if(smallerNumber(newLHS,newRHS))
    {
        my_string mid = newRHS;
        newRHS = lhs;
        newLHS = mid;
    }
    //get the signs of each
    bool lhsPos = newLHS.at(0) !='-';
    bool rhsPos = newRHS.at(0) !='-';
    //if lhs is negative then both of them are negative so we only worry about one case. if rhs is negative. then we subtract
    if(lhsPos && !rhsPos)
    {
        return subtract(newLHS,newRHS.substr(1,newRHS.size()));
    }
    else if(!lhsPos && !rhsPos)
    {
        isPos = false;
        newLHS = newLHS.substr(1,newLHS.size());
        newRHS = newRHS.substr(1,newRHS.size());
    }
    
    //if same sign, we add n truncate the sign n store it in isPos.
    //if they have a different sign, 



      int maxSize;
      //the requirement for equal length is that there are no signs in the beginning
      if(newRHS.size() > newLHS.size())
      {
        newRHS  = "0" + newRHS; // 123 + 68 -> 123 + 068
        maxSize = newRHS.size();
        newLHS = equalLength(newLHS,maxSize);
      }
      else
      {
        newLHS  = "0" + newLHS;
        maxSize = newLHS.size();
        newRHS = equalLength(newRHS,maxSize);
      }
      my_string toAppend = "";
      int numL;
      int numR;
      int carryOver = 0;
      int sum;
      for(int i = newLHS.size()-1; i >=0 ;i--)
      {
        numL = digit_to_decimal(newLHS.at(i));
        numR = digit_to_decimal(newRHS.at(i));
        sum = numL + numR + carryOver;
        carryOver = 0;
        if(sum > 9)
        {
          sum -= 10;
          carryOver++;
        }
        toAppend+= decimal_to_digit(sum);
      }
      my_string reversed = reverse(toAppend);
      if(!isPos)
      {
          reversed = "-" + reversed;
      } 
      
      return trim_leading_zeros(reversed);
}

my_string subtract(const my_string& lhs, const my_string& rhs) {
    bool isPos = true;
    my_string newRHS = rhs;
    my_string newLHS = lhs;
    bool lhsPos = newLHS.at(0) !='-';
    bool rhsPos = newRHS.at(0) =='-';
    if(!lhsPos)
    {
        newLHS = newLHS.substr(1,newLHS.size());
    }
    if(rhsPos)
    {
        newRHS = newRHS.substr(1,newRHS.size());
    }
    
  if(smallerNumber(newLHS,newRHS))
    {
        my_string mid = newRHS;
        newRHS = newLHS;
        newLHS = mid;
        bool middd = lhsPos;
        lhsPos = rhsPos;
        rhsPos = middd;
    }
    if(lhsPos && rhsPos)
    {
       return add(newLHS,newRHS);
    }
    else if(!lhsPos && !rhsPos)
    {
      return add('-'+newLHS,'-'+newRHS);
    }
    else if(!lhsPos && rhsPos)
    {
        isPos = false;
    }
    //get the signs of each
    
    int maxSize;
  
      if(newRHS.size() > newLHS.size())
      {
        newRHS  = "0" + newRHS;
        maxSize = newRHS.size();
        newLHS = equalLength(newLHS,maxSize);
      }
      else
      {
        newLHS  = "0" + newLHS;
        maxSize = newLHS.size();
        newRHS = equalLength(newRHS,maxSize);
      }
    my_string toAppend = "";
    int numL;
    int numR;
    int carryOver = 0;
    int sum;
    for(int i = newLHS.size()-1; i >=0 ;i--)
    {
        numL = digit_to_decimal(newLHS.at(i));
        numR = digit_to_decimal(newRHS.at(i));
        sum = numL - numR - carryOver;
        carryOver = 0;
        if(sum <0 && i!=0)
        {
          sum += 10;
          carryOver++;
        }
        toAppend+= decimal_to_digit(sum);
  }
  my_string reversed = reverse(toAppend);
      if(!isPos)
      {
          reversed = "-" + reversed;
      } 
      
      return trim_leading_zeros(reversed);
}

my_string multiply(const my_string& lhs, const my_string& rhs) {
    my_string newLHS = trim_leading_zeros(lhs);
    my_string newRHS = trim_leading_zeros(rhs);
    if(newLHS == "0" || newRHS == "0")
    {
        return "0";
    }
    bool isPos = true;
    bool lhsPos = newLHS.at(0) !='-';
    bool rhsPos = newRHS.at(0) !='-';
    my_string sum = "0";
    if(!lhsPos)
    {
        newLHS = newLHS.substr(1,lhs.size());
    }
    if(!rhsPos)
    {
        newRHS = newRHS.substr(1,rhs.size());
    }
    if(lhsPos == rhsPos)
    {
        isPos = true;
    }
    else{
        isPos = false;
    }
    int lhsSize = newLHS.size();
    for(int i = 0; i < lhsSize; i++)
    {
        my_string tempSum = "0";
        int num = digit_to_decimal(newLHS.at(newLHS.size()-i-1));
        for(int j = 0; j < num; j++)
        {
            tempSum = add(tempSum,newRHS);
        }
        for(int k = 0; k < i; k++)
        {
            tempSum +="0";
        }
        sum = add(sum,tempSum);
    }
    if(!isPos)
    {
        sum = "-" + sum;
    }
    return sum;
}
