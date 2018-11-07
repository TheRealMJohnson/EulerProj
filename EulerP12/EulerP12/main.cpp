//
//  main.cpp
//  EulerP12
//
//  Created by Matthew Johnson on 2018-11-06.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

//#########################################################
// this design ran overnight. should rework for less than 1 minute runtime
//#########################################################

#include <iostream>
#include <vector>

long long int getNextTriangleNum(long long int currTriangleNum, long long int addition) {
    return currTriangleNum + addition;
}

int getNumFactors(long long int number) {
    int numFactors = 0;
    for(long long int i = 1; i <= number/2; i++) {
        if(number%i == 0){
            numFactors++;
        }
    }
    numFactors++;
    return numFactors;
}

int main(int argc, const char * argv[]) {

    long long int lastTriangleNumber = 1;
    long long int i = 1;
    long long int factors;
    do {
        i++;
        lastTriangleNumber = getNextTriangleNum(lastTriangleNumber, i);
        factors = getNumFactors(lastTriangleNumber);
        //std::cout << "[" << i << ", " << lastTriangleNumber << ", " << factors << "]\n";
    } while (factors <= 500);
    std::cout << "[" << i << ", " << lastTriangleNumber << ", " << factors << "]\n";
    std::cout << "Number with over 500 divisors is: [" << lastTriangleNumber << "]\n";
    return 0;
}
