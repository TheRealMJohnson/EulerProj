//
//  main.cpp
//  EulerP9
//
//  Created by Matthew Johnson on 2018-11-05.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>
int const TEST_LENGTH = 1000;
int squares[TEST_LENGTH];


bool isNumSquare(unsigned long int toTest) {
    for (int i = 0; i < TEST_LENGTH; i++) {
        if(squares[i] == toTest) {
            return true;
        }
    }
    return false;
}

int getIntSqrt(unsigned long int toTest) {
    for (int i = 0; i < TEST_LENGTH; i++) {
        if(squares[i] == toTest) {
            return i+1;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    for (int i = 1; i <= TEST_LENGTH; i++) {
        squares[i-1] = i*i;
    }
    
    unsigned long int a,b,cSquare;
    
    for (b = 10; b < TEST_LENGTH; b++) {
        for (a = 1; a < b; a++) {
            cSquare = a*a + b*b;
            if(isNumSquare(cSquare)) {
                int c = getIntSqrt(cSquare);
                if(a+b+c == 1000) {
                    std::cout << "A:[" << a << "]\n";
                    std::cout << "B:[" << b << "]\n";
                    std::cout << "C:[" << c << "]\n";
                    std::cout << "prod:[" << a*b*c << "]\n";
                }
            }
        }
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
