//
// Created by TobyD on 16/10/2021.
//
#include <cstddef>
#include <iostream>
#include <ostream>

//constructor
template <typename value_type>
HTable<value_type>::HTable(){
    for(int i = 0; i < 5000; i++){          //initialise the array
        table[i].set_code("");              //initialise the array with ""
        table[i].set_quantity(0);           //initialise the array with 0
    }
}

template <typename value_type>
HTable<value_type>::~HTable(){
    //as its all stored on the stack, the array will go out of scope and be auto removed by the compiler
}

template <typename value_type>
int HTable<value_type>::hashfun(const value_type& value) {
    int position = 0;                                       //initialise the position
    std::string temp = value.get_code();                    //string is = to the passed vals code

    for (int i=0; i<(int)temp.length(); i++)
    {
        position += (i+1) * (i+1) * temp.at(i);             //position = formulae
    }

    return position % 5000;                                 //returns position mod size
}

template <typename value_type>
void HTable<value_type>::add(const value_type data){
        table[hashfun(data)] = data;                            //writes data to the position returned
}

template <typename value_type>
void HTable<value_type>::remove(const value_type data){
    table[hashfun(data)].set_code("");                          //sets the position back to the instantiated values
    table[hashfun(data)].set_quantity(0);
}

template <typename value_type>
const std::string HTable<value_type>::HTGetCode(const int i) const{
    return table[i].get_code();                                 //returns the code at index i
}

template <typename value_type>
const int HTable<value_type>::HTGetQuantity(const int i) const{
    return table[i].get_quantity();                         //returns the quantity at index i
}

template <typename value_type>
const int HTable<value_type>::calculateParts() const{
    int total = 0;                                              //instantiate total at 0
    for(int i = 0; i < 5000; i++) {                             //loop for size of array
        if (table[i].get_code() != "") {                        //if its not equal to ""
            total++;                                            //increment total
        }
    }
    return total;                                               //returns total
}

template <typename value_type>
const int HTable<value_type>::calculateInventory() const{
    int total = 0;                                      //instantiate total
    for(int i = 0; i < 5000; i++){                      //loop for size array
        total += table[i].get_quantity();               //total += the quantity at the index i
    }
    return total;
}

template <typename value_type>
const int HTable<value_type>::calculateLessThan(const int pass) const{
    int total = 0;                                                              //instantiate total at 0
    for(int i = 0; i < 5000; i++) {                                             //loop for size of array
        if (table[i].get_quantity() < pass && table[i].get_code() != "") {      //if data at quantity is < pass and is not 0
            total++;                                                            //increment total
        }
    }
    return total;                                                               //return total
}

template <typename value_type>
std::ostream &operator<<(std::ostream &out, HTable<value_type>& hashtable) {
        for (int i = 0; i < 5000; i++) {                                                            //loop for size of array
            if(hashtable.HTGetCode(i) != "" && hashtable.HTGetQuantity(i) != 0){                    //if the index is not equal to instantiation
            out << "(" << hashtable.HTGetCode(i) << ", " << hashtable.HTGetQuantity(i) << ")";      //move data to out                                                    //move data to "out" object  << is declared in EToll.cpp
        }
    }
    return out;                                                                                     //prints
}






