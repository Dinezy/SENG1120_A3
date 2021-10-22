//
// Created by TobyD on 16/10/2021.
//
#include <cstddef>

template <typename value_type>
BSTree<value_type>::BSTree(){
    BTNode<value_type>* root = NULL;
}

template <typename value_type>
BSTree<value_type>::~BSTree(){

}

template <typename value_type>
void BSTree<value_type>::add(value_type data){

    //edge case when list is empty
    if(root == NULL){
        BTNode<value_type>* temp_Root = new BTNode<value_type>;     //create a new temporary root node
        temp_Root->setData(data);   //move data to temp head node
        root = temp_Root;
        temp_Root->setRightChild(NULL);         //initialise left and right Nodes to be linked
        temp_Root->setLeftChild(NULL);

        temp_Root = NULL;       //reseting temp variable
    }else{
        add(data, root);
    }

}

template <typename value_type>
void BSTree<value_type>::add(value_type data, BTNode<value_type>* node){

    BTNode<value_type>* temp_Node = new BTNode<value_type>;
    temp_Node->setData(data);
    temp_Node->setRightChild(NULL);         //initialise left and right Nodes to be linked
    temp_Node->setLeftChild(NULL);

   if(data < node->getData()){

        if(node->getLeftChild() == NULL){
            node->setLeftChild(temp_Node);
            temp_Node->setParent(node);
        }


        add(data, node->getLeftChild());
    }else if(data > node->getData()){

       if(node->getRightChild() == NULL){
           node->setRightChild(temp_Node);
           temp_Node->setParent(node);
       }
        add(data, node->getRightChild());
    }
    temp_Node = NULL;
}

template <typename value_type>
void BSTree<value_type>::remove(value_type data){

    if(root == NULL){
        return;
    }else{
        remove(data, root);
    }
}
template <typename value_type>
void BSTree<value_type>::remove(value_type data, BTNode<value_type>* node){
    BTNode<value_type>* temp_Node = new BTNode<value_type>;
    if(node == NULL){
        return;
    }else if(data < node->getData()){
        remove(data, node->getLeftChild());
    }else if(data > node->getData()){
        remove(data, node->getRightChild());
    }else if(data == node->getData()) {



        //only has a right child
        if (node->getLeftChild() == NULL && node->getRightChild() != NULL) {

            node->getParent()->setRightChild(node->getRightChild());

        } else if (node->getLeftChild() != NULL && node->getRightChild() == NULL) {        //only has left child

            node->getParent()->setLeftChild(node->getLeftChild());

        } else if (node->getLeftChild() != NULL && node->getRightChild != NULL) {          //has 2 childs

            temp_Node = node->getRightChild();
            temp_Node = find(temp_Node);

            if (node->getParent()->getLeftChild == node) {
                node->getParent() - setLeftChild(temp_Node);
            } else if (node->getParent()->getRightChild == node) {
                node->getParent() - setRightChild(temp_Node);
                node = NULL;
            }
        } else if (node == root) {                                                         //is root
            temp_Node = node->getRightChild();
            temp_Node = find(temp_Node);
            temp_Node->setLeftChild(node->getLeftChild());
            temp_Node->setLeftChild(node->getRightChild());
            root = temp_Node;

        } else if (node->getLeftChild() == NULL && node->getRightChild() == NULL) {        //no children :(

            if (node->getParent()->getLeftChild() == node) {
                temp_Node == node;
                temp_Node->getParent()->setLeftChild(NULL);
                delete node;
            } else if (node->getParent()->getRightChild() == node)
                temp_Node == node;
            temp_Node->getParent()->setRightChild(NULL);
            delete node;
        }
    }

    temp_Node = NULL;

}

template <typename value_type>
BTNode<value_type>* BSTree<value_type>::find(BTNode<value_type>* node){
    if(node->getLeftChild() != NULL){
        node = node->getLeftChild();
        find(node);
    }else{
        return node;
    }
}
