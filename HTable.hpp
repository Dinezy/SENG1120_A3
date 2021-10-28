//
// Created by TobyD on 16/10/2021.
//
#include <cstddef>
#include <iostream>
#include <ostream>
//constructor
template <typename value_type>
HTable<value_type>::HTable(){
    for(int i = 0; i < 5000; i++){
        table[i].set_code("");
        table[i].set_quantity(0);
    }
}

template <typename value_type>
HTable<value_type>::~HTable(){

}

template <typename value_type>
int HTable<value_type>::hashfun(const value_type& value) {
    int position = 0;
    std::string temp = value.get_code();

    for (int i=0; i<(int)temp.length(); i++)
    {
        position += (i+1) * (i+1) * temp.at(i);
    }

    return position % 5000;
}

template <typename value_type>
void HTable<value_type>::add(value_type data){
        table[hashfun(data)] = data;
}

template <typename value_type>
void HTable<value_type>::remove(value_type data){
    table[hashfun(data)].set_code("");
    table[hashfun(data)].set_quantity(0);
}

template <typename value_type>
std::string HTable<value_type>::HTGetCode(int i){
    return table[i].get_code();
}

template <typename value_type>
int HTable<value_type>::HTGetQuantity(int i){
    return table[i].get_quantity();
}

template <typename value_type>
int HTable<value_type>::calculateParts(){
    int total = 0;
    for(int i = 0; i < 5000; i++){
        if(table[i].get_code() != "")
        total++;       // sad
    }
    return total;
}

template <typename value_type>
int HTable<value_type>::calculateInventory(){
    int total = 0;
    for(int i = 0; i < 5000; i++){
        total += table[i].get_quantity();
    }
    return total;
}

template <typename value_type>
int HTable<value_type>::calculateLessThan(int pass){
    int total = 0;
    for(int i = 0; i < 5000; i++){
        if(table[i].get_quantity() < pass)
        total++;
    }
    return total;
}

template <typename value_type>
std::ostream &operator<<(std::ostream &out, HTable<value_type>& hashtable) {

        for (int i = 0; i < 5000; i++) {                                                      //loop till end of list
            if(hashtable.HTGetCode(i) != "" && hashtable.HTGetQuantity(i) != 0){
            out << "(" << hashtable.HTGetCode(i) << ", " << hashtable.HTGetQuantity(i) << ")";                                                                //move data to "out" object  << is declared in EToll.cpp
        }                                                                                           // NOTE: only license and type is moved
    }
    return out;                                                                                 //returns object to be printed to screen
}






