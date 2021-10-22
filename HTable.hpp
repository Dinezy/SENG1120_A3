//
// Created by TobyD on 16/10/2021.
//
/*
//constructor
HTable(){
int TABLE_SIZE = 5000;
int size = 0;
}

~HTable(){

}

void add(value_type data){
    if(size == 0){
        Node* temp_Head = new Node;     //create a new temporary head node
        temp_Head->setData(data);   //move data to temp head node
        head = temp_Head;               //move data from temp variable to Head
        temp_Head->setNextNode(NULL);   //initialise next and previous Nodes to be linked
        temp_Head->setPrevNode(NULL);
        tail = head;                    //only one Node in linked list ==> that tail and head are the same
        size++;                         //size increases to 1
        current = head;                 //reseting current to head
        temp_Head = NULL;               //"reseting temporary variable"

    }else if(size > 0){                 //if the linkedlist has objects in it
        Node* temp_Head = new Node;     //create a temp Head Node
        temp_Head->setData(data);   //move data to temp head
        temp_Head->setNextNode(head);   //create link to new nodes
        temp_Head->setPrevNode(NULL);   //
        head->setPrevNode(temp_Head);   //reset head to start of list
        head = temp_Head;
        size++;                         //increment size
        temp_Head = NULL;               //reset "temp var"
    }
}

void operator<<(){

};

void remove(){

}

search(){

}

calculateParts(){

}

calculateLessThan(){

}

calculateInventory(){

}

template <typename T>
int HTable<T>::hashfun(const T& value) {
    int position = 0;
    string temp = value.get_code();

    for (int i=0; i<(int)temp.length(); i++)
    {
        position += (i+1) * (i+1) * temp.at(i);
    }

    return position % TABLE_SIZE;
}

*/


