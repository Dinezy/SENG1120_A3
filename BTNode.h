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

    BTNode(); // constructor

    ~BTNode(); // destructor

    void setRightChild(BTNode<value_type>* next_);

    BTNode<value_type>* getRightChild();

    void setLeftChild(BTNode<value_type>* prev_);

    BTNode<value_type>* getLeftChild();


    void setData(value_type data_);

    value_type getData();

    void setParent(BTNode<value_type>* parent_);

    BTNode<value_type>* getParent();

private:
    value_type data; // the data the Node holds
    BTNode* parent;
    BTNode* left; // a pointer to the next Node
    BTNode* right; // a pointer to the previous Node

};

#include "BTNode.hpp"
#endif //SENG1120_A3_BSNODE_H
