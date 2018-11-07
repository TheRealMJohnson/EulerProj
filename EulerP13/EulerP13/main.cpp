//
//  main.cpp
//  EulerP13
//
//  Created by Matthew Johnson on 2018-11-07.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <string>

struct Node {
    int val = 0;
    Node * next = nullptr;
};

const int LINE_LENGTH = 50;
const int NUMBER_COUNT = 100;

int clean(Node * curr) {
    int toAdd = 0;
    if(curr) {
        toAdd = clean(curr->next);
        toAdd += curr->val;
        curr->val = toAdd % 10;
        return toAdd/10;
    }
    else {
        return 0;
    }
}

Node * cleanRoot(Node * root) {
    int result = clean(root);
    
    while(result != 0) {
        Node * parent = new Node;
        parent->val = result%10;
        result /= 10;
        parent->next = root;
        root = parent;
    }
    
    return root;
}

int getColumnSum(char array[NUMBER_COUNT][LINE_LENGTH], int columnIdx) {
    int sum = 0;
    for (int j = 0; j < NUMBER_COUNT; j++) {
        sum += (int) (array[j][columnIdx] - '0');
    }
    std::cout << "sum is: [" << sum << "]\n";
    return sum;
}

void pushInt(Node * root, int i) {
    while(root->next) {
        root = root->next;
    }
    root->next = new Node;
    root->next->val = i;
}

void printList(Node * root) {
    std::cout << "[";
    while (root) {
        std::cout << root->val << ", ";
        root = root->next;
    }
    std::cout << "]\n";
}

void printArray(char arr[NUMBER_COUNT][LINE_LENGTH]) {
    std::cout << "[";
    for (int i = 0; i < NUMBER_COUNT; i++) {
        std::cout << "{";
        for (int j = 0; j < LINE_LENGTH; j++) {
            std::cout << arr[i][j] << ", ";
        }
        std::cout << "}\n";
    }
    std::cout << "]\n";
}

int main(int argc, const char * argv[]) {
    std::fstream file;
    char numbers[NUMBER_COUNT][LINE_LENGTH];
    
    file.open("/Users/matthewjohnson/GIT/EulerProj/EulerP13/EulerP13/bigInt");
    for(int i = 0; i < NUMBER_COUNT; i ++) {
        file.getline(numbers[i], LINE_LENGTH+1);
    }
    
    std::cout << "file Input\n##########\n";
    printArray(numbers);
    
    Node * root = new Node;
    root->val = getColumnSum(numbers, 0);
    
    for (int j = 1; j < LINE_LENGTH; j++) {
        pushInt(root, getColumnSum(numbers, j));
    }

    std::cout << "unclean list\n##########\n";
    printList(root);

    root = cleanRoot(root);
    std::cout << "clean list\n##########\n";
    printList(root);
    
    return 0;
}
