//
//  main.cpp
//  EulerP28_SpiralDiagonals
//
//  Created by Matthew Johnson on 2018-11-30.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>
const int DIM = 1001;

bool inline withinBounds(int i, int j, int bounds[4]) {
    return (i >= bounds[0] && i <= bounds[1]) && (j >= bounds[2] && j <= bounds[3]);
}

void popArr(long int (&arr)[DIM][DIM]){
    long int sum = DIM*DIM;
    int bounds[4] = {0, DIM-1, 0, DIM-1};
    int actions[2][4] = {{0,1,0,-1},{-1,0,1,0}};
    int act = 0;
    int i = 0;
    int j = DIM-1;
    
    while (sum > 0) {
        do {
            arr[i][j] = sum;
            i += actions[0][act];
            j += actions[1][act];
            sum--;
        } while(withinBounds(i, j, bounds));
        i -= actions[0][act];
        j -= actions[1][act];
        act = (act+1)%4;
        i += actions[0][act];
        j += actions[1][act];
        
        switch(act) {
            case 1:
                bounds[0]++;
                break;
            case 2:
                bounds[2]++;
                break;
            case 3:
                bounds[1]--;
                break;
            case 0:
                bounds[3]--;
                break;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    long int arr[DIM][DIM];
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            arr[i][j] = 0;
        }
    }
    popArr(arr);
    /*
    for(int i = 0; i < DIM; i++) {
        std::cout << "{";
        for(int j = 0; j < DIM; j++) {
            std::cout << arr[i][j] << ", ";
        }
        std::cout << "}\n";
    }
     */
    int sum = -1;
    for(int i = 0; i < DIM; i ++) {
        sum += arr[i][i] + arr[DIM-(1+i)][i];
    }
    std::cout << "sum is: " << sum << "\n";
    
    return 0;
}
