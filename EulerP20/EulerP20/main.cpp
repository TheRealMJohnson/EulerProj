//
//  main.cpp
//  EulerP20
//
//  Created by Matthew Johnson on 2018-11-10.
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
    rootOut = cleanRoot(rootOut);
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

unsigned long long int sumList(Node * root) {
    unsigned long long int sum = 0;
    while (root) {
        sum += root->val;
        root = root->next;
    }
    return sum;
}
int main(int argc, const char * argv[]) {
   
    Node * result = new Node;
    result->val = 1;
    Node * tmp;
    
    Node * iterator = new Node;
    
    for(int i = 1; i <= 100; i++) {
        iterator->val = i;
        tmp = getMultiplication(result, iterator);
        deleteList(result);
        result = tmp;
    }
    
    std::cout << "Hello, World!\n";
    
    std::cout << "sum of list is: [" << sumList(result) << "]\n";
    
    return 0;
}
