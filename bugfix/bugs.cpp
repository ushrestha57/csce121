#include <iostream>
 
using namespace std;
   
int mamountin() {
	int numNickels = 0,numDimes = 0,numNickels = 0,numDimes = 0,numQuarters = 0,coinsUsed = 0,numPennies = 0,amount = 0,numCents = 0;
	char dot;
    cout << "enter amountmount: $";
    cin >> amount >> dot >> numCents;
    amount*= 100;
    amount+= numCents;
    coinsUsed = 0;
	if (amount>=25,amount>0){
  	  numQuarters = amount/25;
      amount %= 25;
      coinsUsed+=numQuarters;
	}
	if (amount>=10){
        numDimes = amount / 10;
        amount %=10;
        coinsUsed += numDimes;
		
    }
	if (amount >= 5)
	{
  	    numNickels = amount / 5;
          amount %= 5;
        coinsUsed += numNickels;
	}
    numPennies = amount;
    coinsUsed+= amount;
    cout << "pennies: "		     << numPennies  << endl;
    cout << "nickels: "		     << numNickels   << endl;
	cout << "dimes: "  			 << numDimes	   << endl;
    cout << "quarters: "		 << numQuarters		   << endl;
	cout << "total coins used: " << coinsUsed << endl;
    return 0;
    
}	
 			  	  		 	  	 			 	   		   		 		 	    		  	 	 				  