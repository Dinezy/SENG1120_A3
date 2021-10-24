//
// Created by TobyD on 21/10/2021.
//
#include <cstddef>

template <typename value_type>
BTNode<value_type>::BTNode(){
    //default constructor
    parent = NULL;
    left = NULL;        //initially setting nodes to null
    right = NULL;

}
template <typename value_type>
BTNode<value_type>::~BTNode(){
    //as data is not a pointer there is nothing to delete
}

template <typename value_type>
void BTNode<value_type>::setRightChild(BTNode<value_type>* right_){
    right = right_;               //moves requested next to next Node
}


template <typename value_type>
BTNode<value_type>* BTNode<value_type>::getRightChild(){
    return right;                //returns next
}
template <typename value_type>
void BTNode<value_type>::setLeftChild(BTNode<value_type>* left_){
    left = left_;               //moves requested prev to prev node
}
template <typename value_type>
BTNode<value_type>* BTNode<value_type>::getLeftChild(){
    return left;                //returns prev
}
template <typename value_type>
void BTNode<value_type>::setData(value_type& data_){
    data = data_;           //moves data into data node
}

template <typename value_type>
value_type BTNode<value_type>::getData(){
    return data;                //returns data
}

template <typename value_type>
void BTNode<value_type>::setParent(BTNode<value_type>* parent_){
    parent = parent_;
}

template <typename value_type>
BTNode<value_type>* BTNode<value_type>::getParent(){
    return parent;
}