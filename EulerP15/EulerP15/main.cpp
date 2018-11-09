//
//  main.cpp
//  EulerP15
//
//  Created by Matthew Johnson on 2018-11-09.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

// Example program
#include <iostream>

int main()
{
    const int size = 21;
    long long int distances[size][size];
    
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << "{";
        for (int j = 0; j < size; j++) {
            if (i == 0 || j == 0) {
                distances[i][j] = 1;
            }
            else {
                distances[i][j] = distances[i-1][j]+distances[i][j-1];
            }
            std::cout << distances[i][j] << ", ";
        }
        std::cout << "}\n";
    }
    std::cout << "]\n";
    
    std::cout << "Total number paths is: [" << distances[size-1][size-1] << "]\n";
}
