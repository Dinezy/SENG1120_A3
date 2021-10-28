//
// Created by TobyD on 16/10/2021.
//
#include <cstddef>
#include <iostream>
#include <ostream>


template<typename value_type>
BSTree<value_type>::BSTree() {
    BTNode <value_type> *root = NULL;
}

template<typename value_type>
BSTree<value_type>::~BSTree() {

}

template<typename value_type>
void BSTree<value_type>::add(value_type data) {
    //edge case when list is empty
    if (root == NULL) {
        BTNode <value_type> *temp_Root = new BTNode<value_type>;     //create a new temporary root node
        temp_Root->setData(data);   //move data to temp head node
        root = temp_Root;
        temp_Root->setRightChild(NULL);         //initialise left and right Nodes to be linked
        temp_Root->setLeftChild(NULL);

        temp_Root = NULL;       //reseting temp variable
    } else {
        add(data, root);
    }

}

template<typename value_type>
void BSTree<value_type>::add(value_type data, BTNode <value_type> *node) {
    BTNode <value_type> *temp_Node = new BTNode<value_type>;
    temp_Node->setData(data);
    temp_Node->setRightChild(NULL);         //initialise left and right Nodes to be linked
    temp_Node->setLeftChild(NULL);
    node = temp_Node;
    if (data.get_quantity() < node->getData().get_quantity()) {
        if (node->getLeftChild() == NULL) {
            node->setLeftChild(temp_Node);
            temp_Node->setParent(node);
        }


        add(data, node->getLeftChild());
    } else if (data.get_quantity() > node->getData().get_quantity()) {
        if (node->getRightChild() == NULL) {
            node->setRightChild(temp_Node);
            temp_Node->setParent(node);
        }
        add(data, node->getRightChild());
    }
    temp_Node = NULL;
}

template<typename value_type>
void BSTree<value_type>::remove(value_type data) {
    BTNode <value_type> *temp_Node = new BTNode<value_type>;     //create a new temporary root node
    //std::cout << "I have entered" << std::endl;


    if (root == NULL) {
        return;
    } else {
        temp_Node = search(data, root);
        remove(data, temp_Node);
    }
    temp_Node = NULL;
}

template<typename value_type>
void BSTree<value_type>::remove(value_type data, BTNode <value_type> *node) {
    BTNode <value_type> *temp_Node = new BTNode<value_type>;
    temp_Node = node;

    std::cout << "hello" << std::endl;
    if (node == root) {

        if (node->getRightChild() != NULL && node->getLeftChild() == NULL) {          //only has a right child
            root = node->getRightChild();
            root->setParent(NULL);

            node = NULL;
        } else if (node->getRightChild() == NULL && node->getLeftChild() != NULL) {     //only has a left child
            root = node->getLeftChild();
            root->setParent(NULL);

            node = NULL;

        } else if (node->getRightChild() != NULL && node->getLeftChild() != NULL) {
            temp_Node = node->getRightChild();
            temp_Node = find(temp_Node);

            node->getLeftChild()->setParent(temp_Node);
            node->getRightChild()->setParent(temp_Node);

            temp_Node->setRightChild(node->getRightChild());
            temp_Node->setLeftChild(node->getLeftChild());

            node = temp_Node;
            root = node;

            temp_Node = NULL;
        } else if (node->getRightChild() == NULL && node->getLeftChild() == NULL) {
            root = NULL;
        }

    } else if (node->getLeftChild() != NULL && node->getRightChild() == NULL) {                //only has left child

        temp_Node = node->getLeftChild();
        temp_Node->setParent(node->getParent());

        if(node->getParent()->getLeftChild() == node){
            node->getParent()->setLeftChild(temp_Node);
        }else{
            node->getParent()->setRightChild(temp_Node);
        }

        node = temp_Node;
        temp_Node = NULL;

    } else if (node->getLeftChild() == NULL && node->getRightChild() != NULL) {                //only has right child

        temp_Node = node->getRightChild();
        temp_Node->setParent(node->getParent());

        if(node->getParent()->getLeftChild() == node){
            node->getParent()->setLeftChild(temp_Node);
        }else{
            node->getParent()->setRightChild(temp_Node);
        }

        node = temp_Node;
        temp_Node = NULL;

    } else if (node->getLeftChild() != NULL && node->getRightChild() != NULL) {                //has 2 children

        if(node->getParent()->getLeftChild() == node){
            temp_Node = find(node->getRightChild());
            node->getParent()->setLeftChild(temp_Node);
            temp_Node->setParent(node->getParent());

        }else{
            temp_Node = find(node);
            node->getParent()->setRightChild(temp_Node);
            temp_Node->setParent(node->getParent());
        }

        node = temp_Node;
        temp_Node = NULL;


    } else if (node->getLeftChild() == NULL && node->getRightChild() == NULL) {                //has no children
        if(node->getParent()->getLeftChild() == node){
            node->getParent()->setLeftChild(NULL);
        }else{
            node->getParent()->setRightChild(NULL);
        }
        node = NULL;
    }
    temp_Node = NULL;
}

template<typename value_type>
BTNode <value_type> *BSTree<value_type>::find(BTNode <value_type> *node) {
    if (node->getLeftChild() != NULL) {
        node = node->getLeftChild();
        find(node);
        return node;
    } else {
        return node;
    }
}

template <typename value_type>
BTNode <value_type> *BSTree<value_type>::search(value_type data, BTNode <value_type> *node) {
    std::cout << "Hello There" << std::endl;
    //TODO: broken :(
    if (data.get_code().compare(node->getData().get_code()) > 0){
    //if(data > node->getData()){
        std::cout << "D" << std::endl;
        node = node->getRightChild();
        search(data, node);
    }else if (data.get_code().compare(node->getData().get_code()) < 0){
   // else if(data < node->getData()){
        std::cout << "E" << std::endl;
        node = node->getLeftChild();
        search(data, node);
    }else if (data.get_code().compare(node->getData().get_code()) == 0){
    //else if(data == node->getData()){
        std::cout << "ahhhh" << std::endl;
        return node;
    }
}


//template<typename value_type>
/*std::ostream &operator<<(std::ostream &out, value_type &Tree) {

return out;
}*/
