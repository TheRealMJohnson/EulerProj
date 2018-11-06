//
//  main.cpp
//  EulerP5
//
//  Created by Matthew Johnson on 2018-11-04.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>

bool isDivisible(unsigned long long int input) {
    for (int i = 2; i <= 20; i++) {
        if(input%i != 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    unsigned long long int start = 1*2*3*4*5*6*7*11*13*17*19;
    unsigned long long int LCM = start;
    unsigned long long int i = start;
    while (i > 10) {
        if(isDivisible(i)) {
            LCM = i;
        }
        i--;
    }
    
    std::cout << "LCM of set is: [" << LCM << "]\n";
    std::cout << isDivisible(LCM);
    return 0;
}
