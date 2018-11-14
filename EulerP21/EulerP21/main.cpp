//
//  main.cpp
//  EulerP21
//
//  Created by Matthew Johnson on 2018-11-11.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>
#include <vector>

int getDivisorSum(int divisee) {
    int sum = 0;
    for(int i = 1; i <= divisee/2; i++) {
        if(divisee%i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    std::vector<int> sums;
    sums.reserve(10000);
    sums[0] = 0;
    sums[1] = 1;
    long long int amicableSum = 0;
    for (int i = 1; i < 10000; i ++) {
        sums[i] = getDivisorSum(i);
        if(sums.size() > sums[i]) {
            sums.reserve(sums[i]);
            sums[sums[i]] = getDivisorSum(sums[i]);
        }
    }
    std::cout << "amicable numbers are: [";
    for (int i = 1; i < 10000; i ++) {
        if(sums[sums[i]] == i && i != sums[i]) {
            amicableSum += i;
            std::cout << "{" << i << ", " << sums[i] << ", " << sums[sums[i]] << "}\n";
        }
    }
    std::cout << "]\n";
    std::cout << "AmicableSum: [" << amicableSum << "]\n";
    return 0;
}
