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
void BSTree<value_type>::add(value_type data) {
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
void BSTree<value_type>::add(value_type data, BTNode <value_type> *node) {

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

/*
template<typename value_type>
void BSTree<value_type>::remove(value_type data) {
    BTNode <value_type> *temp_Node = new BTNode<value_type>;     //create a new temporary root node
    if (root == NULL) {                                          //if the root is equal to null
        return;
    } else {
        temp_Node = search(data, root);                          //find the location the data in the tree
        if(temp_Node != NULL) {
            remove(data, temp_Node);                                 //location of node where the data is stored
        }
    }
    //temp_Node = NULL;
}
*/
/*template<typename value_type>
void BSTree<value_type>::remove(value_type data, BTNode <value_type> *node) {
    BTNode <value_type> *temp_Node = new BTNode<value_type>;

    if (node == root) {           //if the found node is the root
        std::cout << "ahhhhhhhhhhh" << std::endl;
        if (node->getLeftChild() == NULL && node->getRightChild() == NULL) {  //if it has no children
            delete node;
            node = NULL;
            root = NULL;
        } else if (node->getLeftChild() == NULL && node->getRightChild() != NULL) {    //only has right child
            temp_Node = node->getRightChild();
            delete root;
            root = temp_Node;
            root->setParent(NULL);
        } else if (node->getLeftChild() != NULL && node->getRightChild() == NULL) {    //only has left child
            temp_Node = node->getLeftChild();
            delete root;
            root = temp_Node;
            root->setParent(NULL);
        }
    } else if (node->getLeftChild() == NULL && node->getRightChild() == NULL) {    //has no child
        std::cout << "yeeeeeeeeeeeeee" << std::endl;
        if (node->getParent()->getLeftChild() == node) {      //the node it a left child
            node->getParent()->setLeftChild(NULL);
            delete node;
            node = NULL;
        } else {                                          //the node is a right child
            node->getParent()->setRightChild(NULL);
            delete node;
            node = NULL;
        }
    } else if (node->getLeftChild() == NULL && node->getRightChild() != NULL) {    //only the right child exists
        std::cout << "bruuuuuuuuuuuuuuuuuuuuuu" << std::endl;
        if (node->getParent()->getLeftChild() == node) {                      //if its a left child
            node->getParent()->setLeftChild(node->getRightChild());         //set the parents left child to nodes right child
            node->getRightChild()->setParent(node->getParent());            //set the nodes right childs parent to nodes parent
            delete node;
            node = NULL;                                                    //removes node
        } else {                                                              // if its a right child
            node->getParent()->setRightChild(node->getRightChild());        //get the nodes parent and set its right child to nodes right child
            node->getRightChild()->setParent(node->getParent());            //get nodes right child and set its parent to nodes parent
            delete node;
            node = NULL;                                                    //removes node
        }
    } else if (node->getLeftChild() != NULL && node->getRightChild() == NULL) {     //only the left child exist
        std::cout << "minecraft" << std::endl;
        if (node->getParent()->getLeftChild() == node) {                          //the node is the left child of the parent
            node->getParent()->setLeftChild(node->getLeftChild());              //get the nodes parent and set its left child to nodes left child
            node->getLeftChild()->setParent(node->getParent());                 //get the nodes left child and set its parent to nodes parent
            delete node;
            node = NULL;                                                        //removes node
        } else {                                                                  //if node it a right child
            node->getParent()->setRightChild(node->getLeftChild());             //get nodes parent and set its right child to nodes left child
            node->getLeftChild()->setParent(node->getParent());                 //get nodes left child and set its parent to nodes parent
            delete node;
            node = NULL;                                                        //removes node
        }
    } else if (node->getLeftChild() != NULL && node->getRightChild() != NULL) {    //it has 2 children
        std::cout << "fuck you too" << std::endl;
        temp_Node = find(node->getRightChild());                            //goes right, then as far left as possible
        if(temp_Node->getParent()->getLeftChild() == temp_Node){            //if node to replace is a left child
            temp_Node->getParent()->setLeftChild(NULL);                     //set its parents left child to null
            node->setData(temp_Node->getData());                            //move its data to node
            delete temp_Node;                                               //delete temp node
            temp_Node = NULL;                                               //set it to null
        }else{
            temp_Node->getParent()->setRightChild(NULL);                    //set the temps parents right child to null
            node->setData(temp_Node->getData());                            //move data to node
            delete temp_Node;                                               //delete temp
            temp_Node = NULL;                                               //set it to null
        }
    }



    //temp_Node = NULL;
}*/

template<typename value_type>
void BSTree<value_type>::remove(const value_type data){
    root = remove(data, root);
}

template<typename value_type>
BTNode<value_type>* BSTree<value_type>::remove(const value_type& data, BTNode<value_type>* node)
{
    BTNode<value_type>* temp;
    if (node == NULL){
        return NULL;
    }

    if (data < node->getData()){
        node->setLeftChild(remove(data, node->getLeftChild()));

        if (node->getLeftChild()){
            node->getLeftChild()->setParent(node);
        }
    }else if (data > node->getData()){
        node->setRightChild(remove(data, node->getRightChild()));
        if (node->getRightChild()){
            node->getRightChild()->setParent(node);
        }
    }else{
        // for 2 child
        if (node->getLeftChild() && node->getRightChild()){
            temp = find(node->getRightChild());
            node->setData(temp->getData());
            node->setRightChild(remove(node->getData(), node->getRightChild()));
        }else{// not 2 children
            temp = node;
            // check left
            if (node->getLeftChild() == NULL){
                node = node->getRightChild();
            } else if (node->getRightChild() == NULL){
                node = node->getLeftChild();
            }
            delete temp;
           // size--;
        }
    }

    // Check node
    if (!node) {
        return node;
    }

    return node;
}

template<typename value_type>
BTNode <value_type> *BSTree<value_type>::find(BTNode <value_type> *node) {
    if (node->getLeftChild() == NULL) {
        return node;
    } else {
        return find(node->getLeftChild());
    }
}

template<typename value_type>
BTNode <value_type> *BSTree<value_type>::search(value_type data, BTNode <value_type> *node) {
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
    print(out, temp_Node);       //pass the root node to print
}

template<typename value_type>
std::ostream &BSTree<value_type>::print(std::ostream &out, BTNode <value_type> *node) {
    if (node != NULL) {                                   //if the node is not equal to NULL
        print(out, node->getLeftChild());               //go left and recurse
        out << node->getData() << "";                   //print the data
        print(out, node->getRightChild());              //go right and recurse
    }
}

template<typename value_type>
int BSTree<value_type>::calculateParts() {
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
int BSTree<value_type>::calculateInventory() {
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
int BSTree<value_type>::calculateLessThan(int pass) {
    int total = 0;                                      //initialise total
    total = calculate_LessThan(root,
                               pass);             //total = the recursion at the root node, passing the requested integer
    return total;                                       //return total
}

template<typename value_type>
int BSTree<value_type>::calculate_LessThan(BTNode <value_type> *node, int pass) {
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



