//
//  BigInt.hpp
//  DataStructures
//
//  Created by Matthew Johnson on 2018-11-10.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//
#pragma once
#ifndef BigInt_hpp
#define BigInt_hpp
#include <stdio.h>


//could expand each node to contain 3 digits instead of just 1. Reduces memory useage, and improves speed
class BigInt{
    //worst case of addition from the multiplication occurs when every node = n, where n is the threshold
    //maximum value where all nodes are threshold is found at the asymptote of n(i+1) = n+n(i)/10
    static const int CLEAN_THRESHOLD = 29492;
    static const int CAP = 10;
    
    struct Node {
        Node * next = nullptr;
        int val = 0;
    };
    
private:
    Node * root;
    int clean(Node * curr);
    Node * cleanRoot(Node * root);
    void printList(Node * root);
    void deleteList(Node * root);
    int getDepth();
    Node * at(int i);
    int valAt(int i) const;
    
    
public:
    int depth;
    void printList();
    void cleanRoot();
    BigInt();
    BigInt(Node * rIn);
    BigInt(int initVal);
    ~BigInt();
    BigInt operator+(BigInt const & m);
    BigInt& operator+=(BigInt const & m);
    BigInt operator*(BigInt const & m);
    BigInt& operator*=(BigInt const & m);
    BigInt& operator=(BigInt const & m);
    //+ operator??
    unsigned int getLength();
    
};
#endif /* BigInt_hpp */
