//
//  main.cpp
//  EulerP3
//
//  Created by Matthew Johnson on 2018-11-03.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>
#include <vector>

bool isPrime(long long int a, std::vector<long long int> & primes) {
    for(long long int i = 0; i < primes.size(); i++) {
        if(a%primes[i] == 0) {
            return false;
        }
    }
    for(long long int i = primes.back(); i < a/primes.back(); i++) {
        if(a%i == 0) {
            return false;
        }
    }
    return true;
}

void getNextPrime(std::vector<long long int> & primes) {
    long long int i = primes.back() + 1;
    while (!isPrime(i, primes)) {
        i++;
    }
    primes.push_back(i);
}

int main(int argc, const char * argv[]) {
    long long int examinedValue = 600851475143;
    //long long int examinedValue = 13195;
    std::vector<long long int> primes;
    primes.push_back(2);
    primes.push_back(3);
    
    while(primes.back() < examinedValue/primes.back()) {
        getNextPrime(primes);
    }
    
    std::cout << "primes are: [";
    for (int i = 0; i < primes.size(); i++) {
        std::cout << primes[i] << ", ";
    }
    std::cout << "]\n";
    long long int primeFactor  = 0;
    
    for (int i = 0; i < primes.size(); i++) {
        if(examinedValue%primes[i] == 0) {
            primeFactor = primes[i];
        }
    }
    std::cout << "largest prime factor is: [" << primeFactor << "]\n";
    std::cout << "Hello, World!\n";
    return 0;
}
