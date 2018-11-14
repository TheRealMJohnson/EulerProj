//
//  main.cpp
//  EulerP23
//
//  Created by Matthew Johnson on 2018-11-14.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>
#include <vector>

const unsigned long int UPPER_LIMIT = 28123;

int getDivisorSum(int divisee) {
    int sum = 0;
    for(int i = 1; i <= divisee/2; i++) {
        if(divisee%i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    std::vector<unsigned long int> abundantNumbers;
    bool abundantSpans[UPPER_LIMIT];
    
    for(int i = 0; i < UPPER_LIMIT; i++) {
        abundantSpans[i] = false;
    }
    
    for(int i = 0; i < UPPER_LIMIT; i++) {
        if(getDivisorSum(i) > i) {
            abundantNumbers.push_back(i);
        }
    }
    unsigned long int index = 0;
    for(int i = 0; i < abundantNumbers.size(); i++) {
        for(int j = i; j < abundantNumbers.size(); j++) {
            index = abundantNumbers[i]+abundantNumbers[j];
            if(index < UPPER_LIMIT) {
                abundantSpans[index] = true;
            }
        }
    }
    
    unsigned long int sum = 0;
    for(int i = 0; i < UPPER_LIMIT; i++) {
        if(!abundantSpans[i]) {
            sum += i;
        }
    }
    
    std::cout << "sum of all non-abundant expressible numbers is: [" << sum << "]\n";
    return 0;
}
