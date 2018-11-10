//
//  main.cpp
//  EulerP17
//
//  Created by Matthew Johnson on 2018-11-10.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>
#include <string>

const std::string thou = "thousand";
const std::string hund = "hundred";
const std::string ones[10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const std::string teens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const std::string tens[10] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};


//this format repeats every 3 significant digits with a different qualifier (thousand, million, billion)
//following format NNN qualifier NNN qualifier
//N hundred, tens/teens + teens/ones
std:: string getNumberName(unsigned int val) {
    std::string name = "";
    if(val >= 1000) {
        name.append(ones[val/1000] + " " + thou);
    }
    val %= 1000;
    if(val >= 100) {
        name.append(ones[val/100] + " " + hund);
    }
    if(val%100 != 0 && val/100 > 0) {
        name.append(" and ");
    }
    val %= 100;
    if(val < 20 && 10 < val) {
        name.append(teens[val-10]);
    }
    else {
        name.append(tens[val/10]);
        val %=10;
        name.append("-"+ones[val]);
    }
    return name;
}

int main(int argc, const char * argv[]) {
    unsigned long long int charCount = 0;
    std::string tmpString;
    for(int i = 1; i <= 1000; i++) {
        tmpString = getNumberName(i);
        for (int j = 0; j < tmpString.length(); j++) {
            if(tmpString[j] == ' ' || tmpString[j] == '-') {
                continue;
            }
            charCount++;
        }
    }
    
    std::cout << "charCount is: [" << charCount << "]\n";
    return 0;
}
