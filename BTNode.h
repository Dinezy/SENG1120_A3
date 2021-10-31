//
// Created by TobyD on 21/10/2021.
//

#ifndef BTNode_Header
#define BTNode_Header
#include <cstddef>
template <typename value_type>

class BTNode
{
public:


    BTNode(); // constructor

    ~BTNode(); // destructor

    void setRightChild(BTNode<value_type>* next_);

    BTNode<value_type>* getRightChild() const;

    void setLeftChild(BTNode<value_type>* prev_);

    BTNode<value_type>* getLeftChild() const;

    void setData(value_type data_);

    const value_type getData() const;

    void setParent(BTNode<value_type>* parent_);

    BTNode<value_type>* getParent() const;

private:
    value_type data; // the data the Node holds
    BTNode* parent;
    BTNode* left; // a pointer to the next Node
    BTNode* right; // a pointer to the previous Node

};

#include "BTNode.hpp"
#endif //BTNode_Header
