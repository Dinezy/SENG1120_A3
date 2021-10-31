//
// Created by TobyD on 16/10/2021.
//

#ifndef BSTree_Header
#define BSTree_Header
#include <cstddef>
#include <iostream>
#include <ostream>
#include "BTNode.h"

template <typename value_type>

class BSTree {
public:

    BSTree(); //constructor

    ~BSTree(); //destructor

    //precondition: only data of value_type is being passed to function
    //postcondition: data is added to root, or is added to node. pending on rank
    void add(const value_type data);

    //precondition: none
    //postcondition: data is added to nodes pending on its rank in the tree
    void add(const value_type data, BTNode<value_type>* node);

    //precondition: none
    //postcondition: returns the node with the smallest data rank
    BTNode<value_type>* find(BTNode<value_type>* node);

    //precondition: only data of value_type is being passed to the function
    //postcondition: finds position in tree, and passes info to 2nd remove func
    void remove(const value_type data);

    //precondition: none
    //postcondition: removes the required node from the BST
    BTNode<value_type>* remove(const value_type& data, BTNode<value_type>* node);

    //precondition: the passed node must be valid
    //postcondition: finds location of requested data in BST
    BTNode<value_type>* search(const value_type data, BTNode<value_type>* node);

    //precondition: the passed node must be valid
    //postcondition: returns out object containing all the data to be printed
    std::ostream& print(std::ostream& out, BTNode<value_type>* node);

    //precondition: none
    //postcondition: returns out object to be printed
    std::ostream& print(std::ostream &out);

    //precondition: none
    //postcondition: returns total amount of parts in BST
    const int calculateParts();

    //precondition: none
    //postcondition: calculates the total amount of parts in BST and returns the total
    int calculate_Parts(BTNode<value_type> *node);

    //precondition: none
    //postcondition: returns the total amount of inventory
    const int calculateInventory();

    //precondition: the passed node is valid
    //postcondition: calculates the total inventory of the tree and returns it
    int calculate_Inventory(BTNode<value_type>* node);

    //precondition: none
    //postcondition: passes the requested int to other function, and returns total
    const int calculateLessThan(const int pass);

    //precondition: the passed int is not equal to 0
    //postcondition: calculates the total amount of nodes that are less than the requested int and returns it
    int calculate_LessThan(BTNode<value_type> *node, const int pass);

private:
    BTNode<value_type>* root;

};

//precondition: passed BST must exist / be initialised
//postcondition: prints BST to console
template <typename value_type>
std::ostream &operator<<(std::ostream &out, BSTree<value_type>& Tree);

#include "BSTree.hpp"
#endif //BSTree Header
