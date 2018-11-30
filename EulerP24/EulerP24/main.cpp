//
//  main.cpp
//  EulerP24
//
//  Created by Matthew Johnson on 2018-11-26.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

//#define debug

int loops[10];


int strCompare(std::string str1, std::string str2) {
#ifdef debug
    std::cout << "comparing {" << str1 << ", " << str2 << "}\n";
#endif
    
    int i = 0;
    do {
        if(str1[i] > str2[i]) {
            return 1;
        }
        if(str1[i] < str2[i]) {
            return -1;
        }
        i++;
    } while (i < std::min(str1.length(), str2.length()));
    if(str1.size() > str2.size()) {
        return 1;
    }
    else {
        return -1;
    }
    return 0;
}
//2,4,8,16,32,64,128,256
void printVector(std::vector<std::string> & vec) {
    for (int i = 0; i < vec.size(); i++){
        std::cout << "{" << vec[i] << "}\n";
    }
}

std::vector<std::string> mergeSortString(std::vector<std::string> & unsorted, unsigned long subLength) {
    unsigned long middle = (subLength/2);
    if(subLength <= 1) {
        return unsorted;
    }
    std::vector<std::string> bottom = std::vector<std::string>(unsorted.begin(), unsorted.begin()+middle);
    std::vector<std::string> top = std::vector<std::string>(unsorted.begin()+middle, unsorted.end());
#ifdef debug
    std::cout << "bottom is:";
    printVector(bottom);
    std::cout << "top is:";
    printVector(top);
#endif
    bottom = mergeSortString(bottom, middle);
#ifdef debug
    std::cout << "Merged bottom is:";
    printVector(bottom);
#endif
    top = mergeSortString(top, subLength-middle);
#ifdef debug
    std::cout << "Merged top is:";
    printVector(top);
#endif
    
    std::vector<std::string> sortedArr;
    sortedArr.resize(subLength);
    
    long i = middle-1;
    long j = subLength-middle-1;
    
    for (int k = 1; k <= subLength; k++) {
        if(i >= 0 && j >= 0) {
            if(strCompare(bottom[i], top[j]) > 0) {
#ifdef debug
                std::cout << bottom[i] << " is later than: " << top[j] << "\n";
#endif
                sortedArr[subLength-k] = bottom[i];
                i--;
            }
            else {
#ifdef debug
                std::cout << bottom[i] << " is earlier than: " << top[j] << "\n";
#endif
                sortedArr[subLength-k] = top[j];
                j--;
            }
        }
        else if (i < 0) {
#ifdef debug
            std::cout << top[j] << " is leftover and is being inserted\n";
#endif
            sortedArr[subLength-k] = top[j];
            j--;
        }
        else if (j < 0) {
#ifdef debug
            std::cout << bottom[i] << " is leftover and is being inserted\n";
#endif
            sortedArr[subLength-k] = bottom[i];
            i--;
        }
    }
    return sortedArr;
}

bool isLoopsValid() {
    bool validSet[10] = {false, false, false, false, false, false, false, false, false, false};
    for(int i = 0; i < 10; i++) {
        if(validSet[loops[i]]) {
            return false;
        } else {
            validSet[loops[i]] = true;
        }
    }
    return true;
}

std::string getLoopString() {
    std::string output;
    for(int i = 0; i < 10; i++) {
        output.push_back((loops[i]+'0'));
    }
    return output;
}

int main(int argc, const char * argv[]) {
    int NUM_SIZE = 1000000;
    for (int i = 0; i < 10; i++) {
        loops[i] = 0;
    }
    std::vector<std::string> nums;
    nums.clear();

    int i = 9;
    int j = 0;
    int totalValidNums = 0;
    
    while(totalValidNums < NUM_SIZE) {
        loops[i]++;
        while(loops[i] == 10) {
            loops[i] = 0;
            i--;
            j++;
            loops[i]++;
        }
        
        if(i == 0){
            std::cout << "bottom digit incremented\n";
        }
        
        while( j != 0) {
            i++; j--;
        }
        if(isLoopsValid()) {
            totalValidNums++;
            nums.push_back(getLoopString());
        }
    }
    
    nums.shrink_to_fit();
    printVector(nums);
    std::cout << "\n\n\n########--------########\n\n\n\n";
    nums = mergeSortString(nums, NUM_SIZE);
    printVector(nums);
    
    std::cout << "millionth number is: [" << nums[NUM_SIZE-1] << "]\n";
    return 0;
}
