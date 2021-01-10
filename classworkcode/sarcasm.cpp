#include <iostream>
#include <string>
#include <cctype>

#define expect(X) if (!(X)) {\
    std::cout << "[FAIL] ("<<__FUNCTION__<<":"<<__LINE__<<") " <<#X<<std::endl;\
} else {\
    std::cout << "[PASS] ("<<__FUNCTION__<<":"<<__LINE__<<") " <<#X<<std::endl;\
}

using std::cin;
using std::cout;
using std::endl;
using std::string;

string toSaRcAsM(const string& str);

int main() {
    expect(toSaRcAsM("howdy") == "HoWdY");
    expect(toSaRcAsM("the eyes of texas are upon you") == "ThE eYeS oF tExAs ArE uPoN yOu");
    
    return 0;
}

/*
str: string to convert to SaRcAsM
return StRiNg CoNvErTeD tO sArCaSm 
example: toSaRcAsM("howdy") should return "HoWdY"
*/
string toSaRcAsM(const string& str) {
    string concat = "";
    bool upper = true;
    for(char c : str)
    {
       if(!isspace(c))
       {
           if(upper)
           {
               concat+=toupper(c);
           }
           else
           {
              concat+=tolower(c);
           }
           
       }
       else
       {
           concat+=c;
       }
       
       
    }
    cout << concat;
    return concat;
}