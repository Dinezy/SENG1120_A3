//
// Created by TobyD on 16/10/2021.
//

#ifndef SENG1120_A3_BSTREE_H
#define SENG1120_A3_BSTREE_H
#include <cstddef>
#include "BTNode.h"

template <typename value_type>

class BSTree {
public:

    BSTree();
    ~BSTree();

    void add(value_type data);

    void add(value_type data, BTNode<value_type>* node);

    BTNode<value_type>* find(BTNode<value_type>* node);

    void remove(value_type data);

    void remove(value_type data, BTNode<value_type>* node);

    BTNode<value_type>* search(value_type data, BTNode<value_type>* node);

    /*<<;

    search();

    calculateParts();

    calculateLessThan();

    calculateInventory();*/

private:
    BTNode<value_type>* root;

};
//template <typename value_type>
//std::ostream &operator<<(std::ostream &out, value_type &Tree);
#include "BSTree.hpp"
#endif //SENG1120_A3_BSTREE_H
