//
//  main.cpp
//  EulerP11
//
//  Created by Matthew Johnson on 2018-11-05.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>


const int GRID_HEIGHT = 20;
const int GRID_WIDTH = 20;
const int PROD_LENGTH = 4;
int grid[GRID_WIDTH][GRID_HEIGHT];

void readFile(std::fstream & fileStream, std::string name) {
    fileStream.open(name);
    std::cout << "file reads as:\n";
    char buffer[3*GRID_WIDTH];
    for (int i = 0; i < GRID_WIDTH; i++) {
        std::cout << "[";
        fileStream.getline(buffer, 3*GRID_WIDTH);
        for (int j = 0; j < GRID_HEIGHT; j++) {
            grid[i][j] = (buffer[j*3] -'0')*10 + buffer[j*3+1]-'0';
            std::cout << grid[i][j] << ", ";
        }
        std::cout << "]\n";
    }
}

long long int getHorProduct(int i, int j) {
    if (j > (GRID_WIDTH-PROD_LENGTH)) {
        return 0;
    }
    long int product = 1;
    for (int k = 0; k < PROD_LENGTH; k++) {
        product *= grid[i][j+k];
    }
    return product;
}

long long int getVertProduct(int i, int j) {
    if (i > (GRID_WIDTH-PROD_LENGTH)) {
        return 0;
    }
    long int product = 1;
    for (int k = 0; k < PROD_LENGTH; k++) {
        product *= grid[i+k][j];
    }
    return product;
}

long long int getDiagProductSE(int i, int j) {
    if ((j > (GRID_WIDTH-PROD_LENGTH)) || (i > (GRID_WIDTH-PROD_LENGTH))) {
        return 0;
    }
    long int product = 1;
    for (int k = 0; k < PROD_LENGTH; k++) {
        product *= grid[i+k][j+k];
    }
    return product;
}

long long int getDiagProductSW(int i, int j) {
    if ((j > (GRID_WIDTH-PROD_LENGTH)) || (i < PROD_LENGTH)) {
        return 0;
    }
    long int product = 1;
    for (int k = 0; k < PROD_LENGTH; k++) {
        product *= grid[i-k][j+k];
    }
    return product;
}

int main(int argc, const char * argv[]) {
    std::fstream file;
    readFile(file,"/Users/matthewjohnson/GIT/EulerProj/EulerP11/EulerP11/Grid");
    
    long long int product = 1;
    long long int tmpProd;
    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            tmpProd = getHorProduct(i, j);
            if(tmpProd > product) {
                product = tmpProd;
            }
            tmpProd = getVertProduct(i, j);
            if(tmpProd > product) {
                product = tmpProd;
            }
            tmpProd = getDiagProductSE(i, j);
            if(tmpProd > product) {
                product = tmpProd;
            }
            tmpProd = getDiagProductSW(i, j);
            if(tmpProd > product) {
                product = tmpProd;
            }
        }
    }
    
    std::cout << "Largest product is: [" << product << "]\n";
    return 0;
}
