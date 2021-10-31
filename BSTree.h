//
// Created by TobyD on 16/10/2021.
//

#ifndef SENG1120_A3_BSTREE_H
#define SENG1120_A3_BSTREE_H
#include <cstddef>
#include <iostream>
#include <ostream>
#include "BTNode.h"

template <typename value_type>

class BSTree {
public:

    //precondition:
    //postcondition:
    BSTree();

    //precondition:
    //postcondition:
    ~BSTree();

    //precondition:
    //postcondition:
    void add(value_type data);

    //precondition:
    //postcondition:
    void add(value_type data, BTNode<value_type>* node);

    //precondition:
    //postcondition:
    BTNode<value_type>* find(BTNode<value_type>* node);

    //precondition:
    //postcondition:
    void remove(const value_type data);

    //precondition:
    //postcondition:
    BTNode<value_type>* remove(const value_type& data, BTNode<value_type>* node);

    //precondition:
    //postcondition:
    BTNode<value_type>* search(value_type data, BTNode<value_type>* node);

    //precondition:
    //postcondition:
    std::ostream& print(std::ostream& out, BTNode<value_type>* node);

    //precondition:
    //postcondition:
    std::ostream& print(std::ostream &out);

    //precondition:
    //postcondition:
    int calculateParts();

    //precondition:
    //postcondition:
    int calculate_Parts(BTNode<value_type> *node);

    //precondition:
    //postcondition:
    int calculateInventory();

    //precondition:
    //postcondition:
    int calculate_Inventory(BTNode<value_type>* node);

    //precondition:
    //postcondition:
    int calculateLessThan(int pass);

    //precondition:
    //postcondition:
    int calculate_LessThan(BTNode<value_type> *node, int pass);

private:
    BTNode<value_type>* root;

};

//precondition:
//postcondition:
template <typename value_type>
std::ostream &operator<<(std::ostream &out, BSTree<value_type>& Tree);

#include "BSTree.hpp"
#endif //SENG1120_A3_BSTREE_H
