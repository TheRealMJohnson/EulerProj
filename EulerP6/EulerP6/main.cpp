//
//  main.cpp
//  EulerP6
//
//  Created by Matthew Johnson on 2018-11-04.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    unsigned long long int sumSquares = 0;
    for (int i = 0; i <= 100; i ++) {
        sumSquares += i*i;
    }
    
    unsigned long long int squareSums = 0;
    for (int i = 0; i <= 100; i++) {
        squareSums += i;
    }
    squareSums *= squareSums;
    
    std::cout << "Difference is: [" << (squareSums-sumSquares) << "]\n";
    return 0;
}
