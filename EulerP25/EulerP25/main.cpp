//
//  main.cpp
//  EulerP25
//
//  Created by Matthew Johnson on 2018-11-21.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//
// could probably parallelize multiplication in some way?
#include <iostream>
#include "BigInt.hpp"

int main(int argc, const char * argv[]) {
    /*
     int n = 32000;
     int curr = n;//32768, 3640
     do {
     curr = n;
     for (int i = 0; i < 100; i++) {
     curr = n+curr/10;
     }
     std::cout << "curr is [" << curr << "]\n";
     std::cout << "n is [" << n << "]\n";
     n--;
     } while(curr > 32768);
     */
    
    BigInt add = BigInt(1);
    BigInt myInt = BigInt(1);
    BigInt nextAdd = BigInt(1);
    BigInt tmp;
    myInt.printList();
    long index = 2;
    while (myInt.depth < 1000){
        nextAdd = myInt;
        myInt += add;
        add = nextAdd;
        index++;
        std::cout << "\ncurrent depth:[" << myInt.depth << "] at index: [" << index << "] has digits: ";
        //myInt.printList();
    }
    
    std::cout << "\ncurrent depth:[" << myInt.depth << "] at index: [" << index << "] has digits: ";
    myInt.printList();
    
    return 0;
}
