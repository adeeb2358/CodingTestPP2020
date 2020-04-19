//
//  main.cpp
//  CodingTestPP2020
//
//  Created by adeeb mohammed on 19/04/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//


#include <iostream>
#include <string>

std::string removeZero(std::string inputString){
    int i = 0;
    while (inputString[i] == '0'){
        i++;
    }
    inputString.erase(0, i);
    return inputString;
}

std::string binarySum(std::string line){
    std::string result;
    size_t found;
    std::string num_1 = "";
    std::string num_2 = "";
    if ((found = line.find(",")) != std::string::npos){
        num_1 = line.substr(0,found);
        num_2 = line.substr(found+1,std::string::npos);
    }
    int digitSum = 0;
    int i = (int)num_1.size() - 1;
    int j = (int)num_2.size() - 1;
    while(i >= 0 || j >= 0 || digitSum == 1){
        digitSum += ((i >= 0)? num_1[i] - '0': 0);
        digitSum += ((j >= 0)? num_2[j] - '0': 0);
        result = char(digitSum % 2 + '0') + result;
        
        digitSum /= 2;
        i--;j--;
    }
    return removeZero(result);
}

int main() {
    std::cout << "Program for binary sum = ";
    std::cout << binarySum("000101,1001");
}
