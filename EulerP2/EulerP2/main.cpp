//
//  main.cpp
//  EulerP2
//
//  Created by Matthew Johnson on 2018-11-03.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>
#include <vector>

long int getNextFib(long int a, long int b) {
    return a+b;
}

int main(int argc, const char * argv[]) {
    long int arr[2] = {0,1};
    long int maximum = 4000000;
    long int tmp;
    unsigned int sum = 0;
    while (true) {
        tmp = arr[1];
        arr[1] = getNextFib(arr[0], arr[1]);
        arr[0] = tmp;
        if(arr[1] >= maximum) {break;}
        if(arr[1]%2 == 0) {
            sum += arr[1];
        }
    }
    std::cout << "Hello, World!\n";
    std::cout << "sum is: [" << sum << "]\n";
    return 0;
}
