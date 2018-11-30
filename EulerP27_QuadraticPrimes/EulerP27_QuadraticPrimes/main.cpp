//
//  main.cpp
//  EulerP27_QuadraticPrimes
//
//  Created by Matthew Johnson on 2018-11-30.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>
#include <vector>

bool isPrime(long long int val) {
    for(long long int i = 2; i < std::abs(val/2); i++) {
        if(val%i == 0)
            return false;
    }
    return true;
}

long long int getNextPrime(long long int start) {
    while (!isPrime(++start));
    return start;
}

int main(int argc, const char * argv[]) {
    std::vector<long long int> primes;
    primes.resize(1001);
    primes[0] = 1;
    primes[1] = 2;
    for(int i = 2; i < 1001; i++) {
        primes[i] = getNextPrime(primes[i-1]);
    }
    int countMax = 0;
    long long int bestA, bestB;
    std::vector<long long int>tmp;
    tmp.resize(1001);
    std::vector<long long int>result;
    volatile long long int eval;
    for(long long int a = -999; a < 1000; a++) {
        int alternator = 1;
        int path = 0;
        int n = 0;
        while(path != 2) {
            for(int i = 0; primes[i] <= 1000; i++) {
                n = 0;
                eval = n*n + a*n + primes[i]*alternator;
                while(isPrime(eval)) {
                    tmp[n] = eval;
                    n++;
                    eval = n*n + a*n + primes[i]*alternator;
                }
                if(n > countMax) {
                    countMax = n;
                    bestA = a;
                    bestB = primes[i]*alternator;
                    result = std::vector<long long int>(tmp);
                }
            }
            alternator = -1;
            path++;
        }
    }
    
    std::cout << "Best A and B are:[" << bestA << ", " << bestB << "] with count: " << countMax <<"]\n";
    //debugging purposes. this doesn't produce correct values
    int i = 0;
    std::cout << "{";
    while(i < countMax) {
        std::cout << result[i] << ", ";
    }
    std::cout << "}";
    
    return 0;
}
