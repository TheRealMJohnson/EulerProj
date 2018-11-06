//
//  main.cpp
//  EulerP4
//
//  Created by Matthew Johnson on 2018-11-03.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>

bool isPalendrome(int num) {
    std::string numString = std::to_string(num).c_str();
    unsigned long length = numString.length();
    const char * numCString =  numString.c_str();
    
    for(int i = 0; i < length/2; i++) {
        if(numCString[i] != numCString[length-i-1]) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    unsigned long maxPalendrome = 0;
    
    for (int i = 900; i < 999; i++) {
        for (int j = 900; j < 999; j++) {
            if(i*j > maxPalendrome && isPalendrome(i*j)) {
                maxPalendrome = i*j;
            }
        }
    }
    
    std::cout << "Maximum palendrome is: [" << maxPalendrome << "]\n";
    return 0;
}
