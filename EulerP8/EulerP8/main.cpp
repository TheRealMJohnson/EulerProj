//
//  main.cpp
//  EulerP8
//
//  Created by Matthew Johnson on 2018-11-04.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

long long int const tenP12 = 1000000000000;
long long int const tenP3 = 1000;

long long int getProd(long long int numSet) {
    long long int result = 1;
    do {
        result *= numSet%10;
        numSet = numSet/10;
    } while (numSet > 0);
    return result;
}

long long int pushPop(long long int numSet, int pushVal) {
    return numSet = (numSet%(tenP12))*10 + pushVal;
}

int main(int argc, const char * argv[]) {
    std::string number[20];
    std::ifstream inFile;
    inFile.open("/Users/matthewjohnson/GIT/EulerProj/EulerP8/EulerP8/LargeNumber");
    if(!inFile.is_open()) {
        std::cout << "File is not open\n";
        return 1;
    }
    
    int i = 0;
    while (getline (inFile,number[i])) {
        i++;
    }
    
    long long int numSet = 0;
    long long int maxProd = 0;
    long long int maxSet = 0;
    
    long long int currProd;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 50; j++) {
            if(i*20+j < 13) {
                numSet = numSet*10 + (number[i][j] - '0');
            }
            else {
                numSet = pushPop(numSet, (number[i][j] - '0'));
            }
            
            currProd = getProd(numSet);
            if(currProd > maxProd) {
                maxProd = currProd;
                maxSet = numSet;
            }
            /*
            std::cout << "New currProd is: [" << currProd << "]\n";
            std::cout << "New currSet is: [" << numSet << "]\n";
            std::cout << "value is: [" << int (number[i][j] - '0') << "]\n";
            std::cout << "curr maxProd is: [" << maxProd << "]\n";
            std::cout << "curr maxSet is: [" << maxSet << "]\n";
            std::cout << "###-----###\n";
             */
        }
    }
    
    std::cout << "final maxProd is: [" << maxProd << "]\n";
    std::cout << "final maxSet is: [" << maxSet << "]\n";
    std::cout << "-----\n";
    
    return 0;
}
