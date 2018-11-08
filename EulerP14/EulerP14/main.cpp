//
//  main.cpp
//  EulerP14
//
//  Created by Matthew Johnson on 2018-11-08.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
// This requires too much memory to successfully run

#include <iostream>
#include <vector>

#define INT_TYPE unsigned long int
#define NULL_LENGTH 0
//#define debug

//                            18446744073709551615
const long long int ASSUMED_SPAN = 9000000;


INT_TYPE getCollatzLength(INT_TYPE index, std::vector<INT_TYPE> & solutions) {
    INT_TYPE tmp = NULL_LENGTH;
    
    if(index >= solutions.size()) {
        solutions.reserve(index);
    }
    
    if(solutions[index] != NULL_LENGTH) {
        return solutions[index];
    }
    
    if(index%2 == 0) {
        tmp = getCollatzLength(index/2, solutions);
    }
    else {
        tmp = getCollatzLength(index*3+1, solutions);
    }
    solutions[index] = tmp+1;
    return solutions[index];
}


int main(int argc, const char * argv[]) {
    //INT_TYPE solutions[ASSUMED_SPAN];
    std::vector<INT_TYPE> solutions;
    solutions.resize(ASSUMED_SPAN, NULL_LENGTH);
    
    solutions[1] = 1;
    
    std::cout << "size: " << ASSUMED_SPAN << "\n";
    
    INT_TYPE chainMax = 0;
    INT_TYPE chainOwner = 0;
    for (INT_TYPE i = 2; i < 1000000; i++) {
        solutions[i] = getCollatzLength(i, solutions);
        if(solutions[i] > chainMax) {
            chainMax = solutions[i];
            chainOwner = i;
        }
        if(i %10000 == 0) {
            std::cout << "reached I: [" << i << "]\n";
        }
    }
#ifdef debug
    std::cout << "Solutions: {\n";
    for (unsigned long int i = 0; i < ASSUMED_SPAN; i++) {
        std::cout << solutions[i] << ", ";
    }
    std::cout << "}\n";
#endif
    
    std::cout << "Largest chain of size: [" << chainMax << "] is owned by: [" << chainOwner << "]\n";
    return 0;
}
