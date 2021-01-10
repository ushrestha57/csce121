#include <iostream>
#include <cmath>
#include <vector>   
#include "./nth_root.h"


int main() {

    
        {   // MINIMUM REQUIREMENT (for this lab)
            // just call the function with various values of n and x
            
           
            

            try
            {
                nth_root(0,2); //A
                nth_root(2,-1); // B
                nth_root(-1,0); //C
            }
            catch(std::exception& excpt)
            {
                
            }
            
            nth_root(1,2); //D
            nth_root(-1,2); //E
            nth_root(-3,2); //F
            nth_root(-10,2); //G
            nth_root(-4,2); //H
            nth_root(10,2); //I
            nth_root(4,2); // J
            nth_root(2,0); //K
            nth_root(2,1); //L
            nth_root(3,-5); //M
            nth_root(2,5); //N
            nth_root(1, 3.5); //O

      

        }

        
        
}
