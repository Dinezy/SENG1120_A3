//
// Created by TobyD on 16/10/2021.
//

#ifndef HTable_Header
#define HTable_Header

#include <cstddef>
#include <iostream>
#include <ostream>
template <typename value_type>

class HTable {
public:

    HTable(); //constructor

    ~HTable(); //deconstructor

    //precondition: the value must be of type value type
    //postcondition: returns position in HTable for data / value
    int hashfun(const value_type& value);

    //precondition: the data passed is valid of value_type
    //postcondition:
    void add(const value_type data);

    //precondition:
    //postcondition:
    void remove(const value_type data);

    //precondition:
    //postcondition:
    const std::string HTGetCode(int i) const;

    //precondition:
    //postcondition:
    const int HTGetQuantity(int i) const;

    //precondition:
    //postcondition:
    const int calculateParts() const;

    //precondition:
    //postcondition:
    const int calculateInventory() const;

    //precondition:
    //postcondition:
    const int calculateLessThan(int pass) const;


private:

    value_type table[5000];
};

//precondition:
//postcondition:
template <typename value_type>
std::ostream &operator<<(std::ostream &out, HTable<value_type>& hashtable);
#include "HTable.hpp"
#endif //HTable_Header
