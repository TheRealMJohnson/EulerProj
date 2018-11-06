//
//  main.cpp
//  EulerP1
//
//  Created by Matthew Johnson on 2018-11-03.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    std::vector<int> array;
    int maximum = 1000;
    unsigned int sum = 0;
    for (int i = 0; i < maximum; i++) {
        if( i%3 == 0 || i%5 == 0) {
            sum += i;
        }
    }
    std::cout << "Hello, World!\n";
    std::cout << "sum is: [" << sum << "]\n";
    return 0;
}
