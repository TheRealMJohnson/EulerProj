//
//  main.cpp
//  EulerP18
//
//  Created by Matthew Johnson on 2018-11-10.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
const int LINES = 15;

void readTree(std::fstream & file, int data[LINES][LINES]) {
    for (int i = 0; i < LINES; i++) {
        for (int j = 0; j <= i; j++) {
            data[i][j] = 10*(file.get()-'0') + (file.get()-'0');
            file.get();
        }
    }
}

void printTree(int data[LINES][LINES]) {
    std::cout <<  "[";
    for (int i = 0; i < LINES; i++) {
        std::cout <<  "{";
        for (int j = 0; j <= i; j++) {
            std::cout << data[i][j] << ", ";
        }
        std::cout <<  "}\n";
    }
     std::cout <<  "]\n";
}

void processTree(int data[LINES][LINES], int pathSums[LINES][LINES]) {
    pathSums[0][0] = data[0][0];
    
    for (int i = 0; i < (LINES-1); i++) {
        for (int j = 0; j <= i; j++) {
            //set child to max of: (pathsum at current node + childValue -AND- existing pathSum)
            pathSums[i+1][j] = std::max(pathSums[i][j]+data[i+1][j], pathSums[i+1][j]);
            pathSums[i+1][j+1] = std::max(pathSums[i][j]+data[i+1][j+1], pathSums[i+1][j+1]);
        }
    }
}

int main(int argc, const char * argv[]) {
    std::fstream file;
    file.open("/Users/matthewjohnson/GIT/EulerProj/EulerP18/EulerP18/Tree");
    
    int data[LINES][LINES];
    int resultsTree[LINES][LINES];
    readTree(file, data);
    printTree(data);
    
    for(int i = 0; i < LINES; i++) {
        for (int j = 0; j < LINES; j++) {
            resultsTree[i][j] = 0;
        }
    }
    
    processTree(data, resultsTree);
    printTree(resultsTree);
    
    std::cout << "Hello, World!\n";
    return 0;
}
