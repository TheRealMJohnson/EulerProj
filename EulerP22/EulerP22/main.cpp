//
//  main.cpp
//  EulerP22
//
//  Created by Matthew Johnson on 2018-11-14.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>

//(int)compareString(str1, str2) function: returns positive int if str1 is > str2, 0 if equal, and negative if str2 is greater
//if merge[i][m] == merge2[j][m], m++
//if merge.length() >= m insert,
//else
//if merge2.length() >= m insert,
//#define debug

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

inline std::string stripString(std::string str) {
    return str.substr(1, str.length()-2);
}

long getStringScore(std::string str) {
    long sum = 0;
    for (int i = 0; i < str.length(); i++) {
        sum += str[i] - '@';
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    /*
    const int size = 20;
    std::vector<std::string> arr;
    arr.resize(size);
    std::cout << "unsortedStringOut = [\n";
    for(int i = 0; i < size; i++) {
        arr[i] = "str";
        arr[i].append(1,(char) i + '0');
        std::cout << "{" << arr[i] << "}\n";
    }
    std::cout << "]\n";
    arr = mergeSortString(arr, size);
    std::cout << "###---###\n";
    std::cout << "SortedStringOut = [\n";
    for(int i = 0; i < size; i++) {
        std::cout << "{" << arr[i] << "}\n";
    }
    std::cout << "]\n";
    */
    
    std::fstream file;
    std::vector<std::string> names;
    names.resize(5000);
    file.open("/Users/matthewjohnson/Downloads/p022_names.txt");
    unsigned long i = 0;
    while (std::getline(file, names[i], ',')) {
        if(i == (names.size()-2)) {
            names.resize(names.size()*2);
        }
        names[i] = stripString(names[i]);
        i++;
    }
    names.shrink_to_fit();
    
    printVector(names);
    std::cout << "\n\n\n########--------########\n\n\n\n";
    names = mergeSortString(names, i);
    printVector(names);
    unsigned long long max = 0;
    unsigned long long location = 0;
    unsigned long long score = 0;
    unsigned long long sum = 0;
    for(unsigned long j = 0; j < i; j++) {
        score = getStringScore(names[j]) * (j+1);
        std::cout << "[" << j << "] " << names[j] <<": " << score << "\n";
        if(score > max) {
            max = score;
            location = j;
        }
        sum += score;
    }
    std::cout << "total is: " << sum << "\n";
    
    std::cout << "max String score is: [" << max << "] with string " << names[location] << " at location " << location << " \n";
    
    return 0;
}
