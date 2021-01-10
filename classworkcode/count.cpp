#include <iostream>
#include <string>

#define expect(X) if (!(X)) {\
    std::cout << "[FAIL] ("<<__FUNCTION__<<":"<<__LINE__<<") " <<#X<<std::endl;\
} else {\
    std::cout << "[PASS] ("<<__FUNCTION__<<":"<<__LINE__<<") " <<#X<<std::endl;\
}

using std::cin;
using std::cout;
using std::endl;
using std::string;

unsigned count(const string&, const string&);

int main() {
    expect(count("aaaaaaaaaa", "aaa") == 8);
    expect(count("abbabaabbababaaba", "abba") == 2);
    
    return 0;
}

/*
str: string within which to search
key: string to count
return number of times key occurs in str
example: count("aaaaaaaaaa", "aaa") should return 8
*/
unsigned count(const string& str, const string& key) {
    unsigned cnt = 0;
    for(int i = 0; i < (str.length() - key.length()+1); i++)
    {
            bool cont = true;
        for(int j = 0; j < key.length(); j++)
        {
            if(str.at(i+j)!= key.at(j))
            {
                cont = false;
                j = key.length();
            } 
        }
        if(cont)
        {
            cnt++;
        }
    }
    cout << cnt;
    return cnt;
}