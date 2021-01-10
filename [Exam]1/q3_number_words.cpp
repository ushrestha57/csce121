#include <string>
#include <iostream>
using std::string;
using std::invalid_argument;
string number_words(unsigned int n) {
    /*
    first we check the bounds of n. if n is within range, we continue, otherwise we throw std::invalid argument
    second make an array that holds the string values for 0-19.
    third, make an array that holds the string values for each tenth place like twenty, thirty, etc.
    if its between 0-19 just return numbers[n]
    then, peel the ones place digit from n and divide by 10. if n!= 0, then we set a string called second half equal to numbers[digit]
    if n == 0, we just return numbers[digit], if n == 1, we return numbers[digit+10], else we set the string equal to "-" + numbers[digit]
    finally, we peel the tenths place and we return tenths[digit] + string
    a bit of a hard coded solution but i dont know anyway other than this
    */
    string numbers[] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    string tenths[] = {"twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
    int digit;
    if(n > 99) //since its unsigned we dont have to worry about it being less than 0
    {
        throw invalid_argument("Invalid argument");
    }
    else if(n < 20){
        return numbers[n];
    }
    else
    {
        digit = n % 10;
        n /= 10;
        if(digit == 0)
        {
            return tenths[n-2];
        }
        
        
    }
    return (tenths[n-2] + "-" + numbers[digit]);
    
}

