//
//  main.cpp
//  EulerP16
//
//  Created by Matthew Johnson on 2018-11-09.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>

struct Node {
    Node * next = nullptr;
    int val = 0;
};

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

void printList(Node * root) {
    std::cout << "[";
    while (root) {
        std::cout << root->val << ", ";
        root = root->next;
    }
    std::cout << "]\n";
}

//BUG: longer list of the two must be the latter
//bug removed???
Node * getMultiplication(Node * rootA, Node * rootB) {
    Node * currA;
    Node * currB;
    Node * currOut;
    Node * startOut;
    Node * rootOut  = new Node;
    
    currA = rootA;
    startOut = rootOut;
    
    do {
        currB = rootB;
        currOut = startOut;
        do {
            currOut->val += currA->val * currB->val;
            currB = currB->next;
            if (!(currOut->next) && (currB ||currA->next)) {
                currOut->next = new Node;
            }
            currOut = currOut->next;
        } while (currB);
        
        startOut = startOut->next;
        currA = currA->next;
        
    } while (currA);
    //rootOut = cleanRoot(rootOut);
    return rootOut;
}

void deleteList(Node * root) {
    Node * next;
    while (root) {
        next = root->next;
        free(root);
        root = next;
    }
}

unsigned int sumList(Node * root) {
    unsigned int sum = 0;
    while (root) {
        sum += root->val;
        root = root->next;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    Node * result = new Node;
    result->val = 2;
    Node * two = new Node;
    two->val = 2;
    Node * tmp;
    
    for(int  i = 0; i < 999; i++) {
        tmp = cleanRoot(getMultiplication(result, two));
        deleteList(result);
        result = tmp;
        std::cout << "multiplied one column with next. Result:\n";
        printList(result);
    }
    
    std::cout << "Hello, World!\n";
    printList(result);
    std::cout << "Sum of list is: [" << sumList(result) << "]\n";
    return 0;
}
