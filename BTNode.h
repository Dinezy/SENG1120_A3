//
// Created by TobyD on 21/10/2021.
//

#ifndef SENG1120_A3_BSNODE_H
#define SENG1120_A3_BSNODE_H
#include <cstddef>
template <typename value_type>

class BTNode
{
public:

    //precondition:
    //postcondition:
    BTNode(); // constructor

    //precondition:
    //postcondition:
    ~BTNode(); // destructor

    //precondition:
    //postcondition:
    void setRightChild(BTNode<value_type>* next_);

    //precondition:
    //postcondition:
    BTNode<value_type>* getRightChild();

    //precondition:
    //postcondition:
    void setLeftChild(BTNode<value_type>* prev_);

    //precondition:
    //postcondition:
    BTNode<value_type>* getLeftChild();

    //precondition:
    //postcondition:
    void setData(value_type data_);

    //precondition:
    //postcondition:
    value_type getData();

    //precondition:
    //postcondition:
    void setParent(BTNode<value_type>* parent_);

    //precondition:
    //postcondition:
    BTNode<value_type>* getParent();

private:
    value_type data; // the data the Node holds
    BTNode* parent;
    BTNode* left; // a pointer to the next Node
    BTNode* right; // a pointer to the previous Node

};

#include "BTNode.hpp"
#endif //SENG1120_A3_BSNODE_H
