//
//  main.cpp
//  EulerP10
//
//  Created by Matthew Johnson on 2018-11-04.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>
#include <vector>

bool isPrime(long long int a, std::vector<long int> & primes) {
    for(long long int i = 0; i < primes.size(); i++) {
        if(a%primes[i] == 0) {
            return false;
        }
    }
    for(long int i = primes.back(); i < a/primes.back(); i++) {
        if(a%i == 0) {
            return false;
        }
    }
    return true;
}

void getNextPrime(std::vector<long int> & primes) {
    long int i = primes.back() + 1;
    while (!isPrime(i, primes)) {
        i++;
    }
    primes.push_back(i);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<long int> primes;
    
    primes.push_back(2);
    primes.push_back(3);
    
    std::cout << "Primes are: [";
    while(primes.back() < 2000000) {
        getNextPrime(primes);
        //std::cout << primes.back() << ", ";
    }
    std::cout << "]\n#####-----#####\n";
    primes.pop_back();
    
    unsigned long long int sum = 0;
    
    for (int i = 0; i < primes.size(); i++) {
        sum += primes[i];
    }
    
    std::cout << "Prime sum is: [" << sum << "]\n";
    return 0;
}
