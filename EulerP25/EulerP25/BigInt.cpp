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
    if(curr) {
        int toAdd = clean(curr->next);
        toAdd += curr->val;
        curr->val = toAdd % CAP;
        return toAdd/CAP;
    }
    else {
        return 0;
    }
}

BigInt::Node * BigInt::cleanRoot(Node * root) {
    int result = clean(root);
    
    while(result != 0) {
        Node * parent = new Node;
        parent->val = result%CAP;
        result /= CAP;
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

void BigInt::deleteList(Node * rootList) {
    Node * iter = root;
    Node * next = root->next;
    while(iter) {
        next = iter->next;
        delete iter;
        iter = next;
    }
}

void BigInt::printList() {
    printList(root);
}
inline void BigInt::cleanRoot() {
    root = cleanRoot(root);
    depth = getDepth();
}

BigInt::BigInt () {
    root = new Node;
    root->val = 0;
    root->next = nullptr;
    depth = getDepth();
}

BigInt::BigInt (int initVal) {
    root = new Node;
    root->val = initVal;
    root->next = nullptr;
    cleanRoot();
}

BigInt::BigInt (Node * rIn) {
    root = rIn;
    cleanRoot();
}

BigInt::~BigInt() {
    deleteList(root);
}

BigInt BigInt::operator*(BigInt const & m) {
    Node * currA;
    Node * currB;
    Node * currOut;
    Node * startOut;
    Node * rootOut = new Node;
    BigInt dummy;
    
    currA = this->root;
    startOut = rootOut;
    
    do {
        currB = m.root;
        currOut = startOut;
        do {
            currOut->val += currA->val * currB->val;
            if(currOut->val >= CLEAN_THRESHOLD) {
                rootOut = dummy.cleanRoot(rootOut);
            }
            currB = currB->next;
            if (!(currOut->next) && (currB ||currA->next)) {
                currOut->next = new Node;
            }
            currOut = currOut->next;
            
        } while (currB);
        
        startOut = startOut->next;
        currA = currA->next;
    } while (currA);
    rootOut = dummy.cleanRoot(rootOut);
    return BigInt(rootOut);
}

int BigInt::getDepth() {
    int sum = 0;
    Node * iterator = root;
    while (iterator) {
        iterator = iterator->next;
        sum++;
    }
    return sum;
}

BigInt::Node * BigInt::at(int i) {
    Node * iter = root;
    while(i != 0) {
        iter = iter->next;
        i--;
    }
    return iter;
}

int BigInt::valAt(int i) const {
    Node * iter = root;
    while(i > 0) {
        iter = iter->next;
        i--;
    }
    return iter->val;
}

BigInt BigInt::operator+(BigInt const & m) {
    int j = 1;
    BigInt out = BigInt(1)*(*this);
    
    while(j <= std::min(depth, m.depth)) {
        out.at(out.depth - j)->val += m.valAt(m.depth - j);
        j++;
    }
    out.cleanRoot();
    return out;
}

BigInt& BigInt::operator+=(BigInt const & m) {
    return *this =  (*this + m);
}

//unsafe when m is void
BigInt& BigInt::operator=(BigInt const & m) {
    Node * mIter = m.root;
    deleteList(root);
    root = new Node;
    Node * cIter = root;
    cIter->val = mIter->val;
    
    while(mIter->next) {
        mIter = mIter->next;
        cIter->next = new Node;
        cIter = cIter->next;
        cIter->val = mIter->val;
    }
    cleanRoot();
    return *this;
}

BigInt& BigInt::operator*=(BigInt const & m){
    return *this = (*this * m);
}

unsigned int BigInt::getLength() {
    unsigned int sum = 0;
    Node * current = this->root;
    while(current) {
        sum++;
        current = current->next;
    }
    return sum;
}
