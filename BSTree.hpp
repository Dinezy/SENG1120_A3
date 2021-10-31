//
// Created by TobyD on 16/10/2021.
//
#include <cstddef>
#include <iostream>
#include <ostream>


template<typename value_type>
BSTree<value_type>::BSTree() {
  root = NULL;
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

    //node = temp_Node;


        if (data < node->getData()) {
            if (node->getLeftChild() == NULL) {
                BTNode <value_type> *temp_Node = new BTNode<value_type>;
                temp_Node->setData(data);
                temp_Node->setRightChild(NULL);         //initialise left and right Nodes to be linked
                temp_Node->setLeftChild(NULL);

                node->setLeftChild(temp_Node);
                temp_Node->setParent(node);
            } else {
                add(data, node->getLeftChild());
            }
        } else if (data > node->getData()) {
            if (node->getRightChild() == NULL) {
                BTNode <value_type> *temp_Node = new BTNode<value_type>;
                temp_Node->setData(data);
                temp_Node->setRightChild(NULL);         //initialise left and right Nodes to be linked
                temp_Node->setLeftChild(NULL);

                node->setRightChild(temp_Node);
                temp_Node->setParent(node);
            } else {
                add(data, node->getRightChild());
            }
        }
    //temp_Node = NULL;
}

template<typename value_type>
void BSTree<value_type>::remove(value_type data) {
    BTNode <value_type> *temp_Node = new BTNode<value_type>;     //create a new temporary root node
    //std::cout << "I have entered" << std::endl;

    if (root == NULL) {
        return;
    } else {
        temp_Node = search(data, root);
        remove(data, temp_Node);    //location of node where the data is stored
    }
    temp_Node = NULL;
}

template<typename value_type>
void BSTree<value_type>::remove(value_type data, BTNode <value_type> *node) {
    BTNode <value_type> *temp_Node = new BTNode<value_type>;

    if (node == root) {
        if (node->getRightChild() != NULL && node->getLeftChild() != NULL) {       //no children
            root = NULL;
        } else if (node->getRightChild() == NULL && node->getLeftChild() != NULL) {  //only has right
            root = root->getRightChild();
        } else if (node->getRightChild() != NULL && node->getLeftChild() == NULL) {  //only has left
            root = root->getLeftChild();
        }
    } else if (node->getRightChild() == NULL && node->getLeftChild() == NULL) {           //has no children
        if (node->getParent()->getLeftChild() == node) {
            node->getParent()->setLeftChild(NULL);
            node = NULL;
        } else {
            node->getParent()->setRightChild(NULL);
            node = NULL;
        }
    } else if (node->getRightChild() != NULL && node->getLeftChild() == NULL) {    //only has right child
        if (node->getParent()->getLeftChild() == node) {
            node->getParent()->setLeftChild(node->getRightChild());
            node->getRightChild()->setParent(node->getParent());
            node = NULL;
        } else {
            node->getParent()->setRightChild(node->getRightChild());
            node->getRightChild()->setParent(node->getParent());
            node = NULL;
        }
    }else if(node->getRightChild() == NULL && node->getLeftChild() != NULL) {   //only has left child
        if (node->getParent()->getLeftChild() == node) {
        node->getParent()->setLeftChild(node->getLeftChild());
        node->getLeftChild()->setParent(node->getParent());
        node = NULL;
        } else {
        node->getParent()->setRightChild(node->getLeftChild());
        node->getLeftChild()->setParent(node->getParent());
        node = NULL;
        }
    }else if(node->getRightChild() != NULL && node->getLeftChild() != NULL){    //has 2 children
        temp_Node = find(node->getRightChild());
        if(node->getParent()->getLeftChild() == node){
            node->getParent()->setLeftChild(temp_Node);
            temp_Node->setParent(node->getParent());
            temp_Node->setLeftChild(node->getLeftChild());
            temp_Node->setRightChild(node->getRightChild());
            node = NULL;

        }else{
            node->getParent()->setRightChild(temp_Node);
            temp_Node->setParent(node->getParent());
            temp_Node->setLeftChild(node->getLeftChild());
            temp_Node->setRightChild(node->getRightChild());
            node = NULL;
        }
    }
    temp_Node = NULL;
}


template<typename value_type>
BTNode <value_type> *BSTree<value_type>::find(BTNode <value_type> *node) {
    if (node->getLeftChild() != NULL) {
        node = node->getLeftChild();
        find(node);
    } else {
        return node;
    }
}

template <typename value_type>
BTNode <value_type> *BSTree<value_type>::search(value_type data, BTNode <value_type> *node) {
    if (data > node->getData()){
       if(node->getRightChild() != NULL){
        node = node->getRightChild();
        search(data, node);
       }else{
           return node;
       }
    }else if (data < node->getData()){
        if(node->getLeftChild() != NULL) {
            node = node->getLeftChild();
            search(data, node);
        }else{
            return node;
        }
    }else if (data == node->getData()){
      return node;
    }
}

template <typename value_type>
std::ostream& BSTree<value_type>::print(std::ostream &out){
    BTNode<value_type>* temp_Node = root;
    print(out, temp_Node);
}

template <typename value_type>
std::ostream& BSTree<value_type>::print(std::ostream& out, BTNode<value_type>* node){
    if(node != NULL){
        print(out, node->getLeftChild());
        out << node->getData() << "";
        print(out, node->getRightChild());
    }
}

template <typename value_type>
int BSTree<value_type>::calculateParts(){
    int total = 0;
    total = calculate_Parts(root);
    return total;
}

template <typename value_type>
int BSTree<value_type>::calculate_Parts(BTNode<value_type> *node){
        int total = 0;
        if (node != NULL) {
            total += calculate_Parts(node->getLeftChild());
            total++;
            total += calculate_Parts(node->getRightChild());
        }
    return total;
}

template <typename value_type>
int BSTree<value_type>::calculateInventory(){
    int total = 0;
    total = calculate_Inventory(root);
    return total;
}

template <typename value_type>
int BSTree<value_type>::calculate_Inventory(BTNode<value_type>* node){
    int total = 0;
    if (node != NULL) {
        total += calculate_Inventory(node->getLeftChild());
        total += node->getData().get_quantity();
        total += calculate_Inventory(node->getRightChild());
    }
    return total;
}

template <typename value_type>
int BSTree<value_type>::calculateLessThan(int pass){
    int total = 0;
    total = calculate_LessThan(root, pass);
    return total;
}

template <typename value_type>
int BSTree<value_type>::calculate_LessThan(BTNode<value_type> *node, int pass){
    int total = 0;
    if (node != NULL) {
      if(node->getData().get_quantity() < pass) {
          total++;
      }
      total += calculate_LessThan(node->getLeftChild(), pass);
      total += calculate_LessThan(node->getRightChild(), pass);

      }
    return total;
}

template <typename value_type>
std::ostream &operator<<(std::ostream &out, BSTree<value_type>& Tree) {

    Tree.print(out);

    return out;                                                                                 //returns object to be printed to screen
}



