//
//  BigInt.cpp
//  DataStructures
//
//  Created by Matthew Johnson on 2018-11-10.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include "BigInt.hpp"
#include <iostream>


int BigInt::clean(Node * curr) {
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

BigInt::Node * BigInt::cleanRoot(Node * root) {
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

void BigInt::printList(Node * root) {
    std::cout << "[";
    while (root) {
        std::cout << root->val << ", ";
        root = root->next;
    }
    std::cout << "]\n";
}

//BUG: longer list of the two must be the latter
//bug removed???
BigInt::Node * BigInt::getMultiplication(Node * rootA, Node * rootB) {
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

void BigInt::deleteList(Node * root) {
    Node * next;
    while (root) {
        next = root->next;
        free(root);
        root = next;
    }
}

void BigInt::printList() {
    printList(root);
}
void BigInt::cleanRoot() {
    root = cleanRoot(root);
}
BigInt * BigInt::getMultiplication(BigInt & rootA) {
    BigInt * returnBigInt = new BigInt;
    returnBigInt->root = getMultiplication(root, rootA.root);
    return returnBigInt;
}

void BigInt::pushBack(int pushedVal) {
    if(!root) {
        root = new Node;
        root->val = pushedVal;
        return;
    }
    Node * iterator = root;
    while (iterator->next) {
        iterator = iterator->next;
    }
    iterator->next = new Node;
    iterator->next->val = pushedVal;
}

void BigInt::popBack() {
    if(!root) {
        return;
    }
    if(!(root->next)) {
        free(root);
        root = nullptr;
    }
    Node * iterator = root;
    while (iterator->next->next) {
        iterator = iterator->next;
    }
    free(iterator->next);
    iterator->next = nullptr;
}
