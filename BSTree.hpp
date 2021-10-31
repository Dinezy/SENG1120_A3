//
// Created by TobyD on 16/10/2021.
//
#include <cstddef>
#include <iostream>
#include <ostream>


template<typename value_type>
BSTree<value_type>::BSTree() {
    root = NULL;  //initially sets root to null
}

template<typename value_type>
BSTree<value_type>::~BSTree() {
    while(root != NULL){
        remove(root->getData());
    }
}

template<typename value_type>
void BSTree<value_type>::add(const value_type data) {
    //edge case when list is empty
    if (root == NULL) {
        BTNode <value_type> *temp_Root = new BTNode<value_type>;     //create a new temporary root node
        temp_Root->setData(data);                                     //move data to temp node
        root = temp_Root;                                               //root equals the temp
        temp_Root->setRightChild(NULL);                                 //initialise left and right Nodes to be linked
        temp_Root->setLeftChild(NULL);
        temp_Root->setParent(NULL);

        //temp_Root = NULL;       //reseting temp variable
    } else {
        add(data, root);        //enters other add function for recursion
    }

}

template<typename value_type>
void BSTree<value_type>::add(const value_type data, BTNode <value_type> *node) {

    if (data < node->getData()) {                                       //if data is less that the nodes data
        if (node->getLeftChild() == NULL) {                             //if the left child is null
            BTNode <value_type> *temp_Node = new BTNode<value_type>;
            temp_Node->setData(data);                                   //set the node to data
            temp_Node->setRightChild(NULL);                             //initialise left and right Nodes to be linked
            temp_Node->setLeftChild(NULL);

            node->setLeftChild(temp_Node);                              //links node to new node
            temp_Node->setParent(node);                                 //links new node to node
        } else {
            add(data, node->getLeftChild());                            //recurse again
        }
    } else if (data > node->getData()) {
        if (node->getRightChild() == NULL) {
            BTNode <value_type> *temp_Node = new BTNode<value_type>;
            temp_Node->setData(data);
            temp_Node->setRightChild(NULL);         //initialise left and right Nodes to be linked
            temp_Node->setLeftChild(NULL);

            node->setRightChild(temp_Node);         //set the nodes right child to temp node
            temp_Node->setParent(node);             //link the temp node to node as the parent
        } else {
            add(data, node->getRightChild());       //recurse again
        }
    }
    //temp_Node = NULL;
}

template<typename value_type>
void BSTree<value_type>::remove(const value_type data){
    root = remove(data, root);  //pass root to remove fn
}

template<typename value_type>
BTNode<value_type>* BSTree<value_type>::remove(const value_type& data, BTNode<value_type>* node)
{
    BTNode<value_type>* temp;                           //create temp var
    if (node == NULL){                                  //if node == null return
        return NULL;
    }

    if (data < node->getData()){                                            //if data is less than nodes data
        node->setLeftChild(remove(data, node->getLeftChild()));             //remove nodes left child (recurse on it till found)

        if (node->getLeftChild()){                                          //if left child is not null
            node->getLeftChild()->setParent(node);                          //set the nodes left childs parent to node
        }
    }else if (data > node->getData()){                                      //if data is > nodes data
        node->setRightChild(remove(data, node->getRightChild()));           //remove nodes left child (recurse on it till found)
        if (node->getRightChild()){                                         //if nodes right child is not null
            node->getRightChild()->setParent(node);                         //set nodes right childs parent to node
        }
    }else{
        // for 2 children
        if (node->getLeftChild() && node->getRightChild()){                             //if the node has 2 children
            temp = find(node->getRightChild());                                         //temp = the min value in respect the node
            node->setData(temp->getData());                                             //set the data to temp nodes data
            node->setRightChild(remove(node->getData(), node->getRightChild()));        //remove the right child / recurse on it
        }else{// not 2 children
            temp = node;                                                                //temp = node
            // check left child
            if (node->getLeftChild() == NULL){                                          //if the left child is == nULL
                node = node->getRightChild();                                           //node equals the right child
            } else if (node->getRightChild() == NULL){                                  //if its equal to null
                node = node->getLeftChild();                                            //node equals the left child
            }
            delete temp;                                                                //delete temp
        }
    }

    // Check node
    if (!node) {                                                                        //if node equals null
        return node;                                                                    //return
    }
    return node;                                                                            //return
}

template<typename value_type>
BTNode <value_type> *BSTree<value_type>::find(BTNode <value_type> *node) {
    if (node->getLeftChild() == NULL) {                     //if the left child equal null
        return node;                                        //return
    } else {
        return find(node->getLeftChild());                  //recurse on the left child
    }
}

template<typename value_type>
BTNode <value_type> *BSTree<value_type>::search(const value_type data, BTNode <value_type> *node) {
    if (data > node->getData()) {                            //if data is greater than the node
        if (node->getRightChild() != NULL) {                   // and the right child is not NULL
            return search(data, node->getRightChild());                    //go right again and recurse
        }
    } else if (data < node->getData()) {                      //if data is less than node
        if (node->getLeftChild() != NULL) {                  //and the left child is not NULL
            return search(data, node->getLeftChild());             //go left and recurse
        }
    }else if(data == node->getData()) {
        std::cout << "social experiment" << std::endl;
        return node;                                          //return node WE FOUND IT!
    }
    return NULL;
}

template<typename value_type>
std::ostream &BSTree<value_type>::print(std::ostream &out) {
    BTNode <value_type> *temp_Node = root;
    return print(out, temp_Node);       //pass the root node to print
}

template<typename value_type>
std::ostream &BSTree<value_type>::print(std::ostream &out, BTNode <value_type> *node) {
    if (node != NULL) {                                   //if the node is not equal to NULL
        print(out, node->getLeftChild());               //go left and recurse
        out << node->getData() << "";                   //print the data
        return print(out, node->getRightChild());              //go right and recurse
    }
}

template<typename value_type>
const int BSTree<value_type>::calculateParts() {
    int total = 0;                          //initialise total
    total += calculate_Parts(root);          //pass the root into the recurse func
    return total;
}

template<typename value_type>
int BSTree<value_type>::calculate_Parts(BTNode <value_type> *node) {
    int total = 0;                                              //initialise total
    if (node != NULL) {                                         //if node is not equal NULL
        total = calculate_Parts(node->getLeftChild()) + 1 + calculate_Parts(node->getRightChild());
    }
    return total;                                                   //return total
}

template<typename value_type>
const int BSTree<value_type>::calculateInventory() {
    int total = 0;                                  //initialise total
    total = calculate_Inventory(root);              //pass root node for recursion
    return total;                                   //return total
}

template<typename value_type>
int BSTree<value_type>::calculate_Inventory(BTNode <value_type> *node) {
    int total = 0;                                                          //initialise total
    if (node != NULL) {                                                     // if node is not equal NULL
        total += calculate_Inventory(
                node->getLeftChild());                 // total is += to the recursion of the left child
        total += node->getData().get_quantity();                            // total is += to the nodes datas quantity
        total += calculate_Inventory(
                node->getRightChild());                // total is += to the recursion of the right child
    }
    return total;                                                           //return total
}

template<typename value_type>
const int BSTree<value_type>::calculateLessThan(const int pass) {
    int total = 0;                                      //initialise total
    total = calculate_LessThan(root, pass);             //total = the recursion at the root node, passing the requested integer
    return total;                                       //return total
}

template<typename value_type>
int BSTree<value_type>::calculate_LessThan(BTNode <value_type> *node,const int pass) {
    int total = 0;                                                      //initialise total
    if (node != NULL) {                                                 //if node is not equal NULL
        if (node->getData().get_quantity() < pass) {                       //if nodes data is < the passed int
            total++;                                                      //increment total
        }
        total += calculate_LessThan(node->getLeftChild(),
                                    pass);          //total is += to the recursion of the left child
        total += calculate_LessThan(node->getRightChild(),
                                    pass);         //total is += to the recursion of the right child

    }
    return total;                                                       //return total
}

template<typename value_type>
std::ostream &operator<<(std::ostream &out, BSTree <value_type> &Tree) {

    Tree.print(out);            //pass the out variable to be loaded with data from the tree

    return out;                                                                                 //returns object to be printed to screen
}



