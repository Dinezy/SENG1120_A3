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
    //postcondition: adds the data to the position that hashfun generates
    void add(const value_type data);

    //precondition: the data passed to function is valid
    //postcondition: the data is removed from the array
    void remove(const value_type data);

    //precondition: that the int i is within the array size
    //postcondition: returns the code at index i
    const std::string HTGetCode(const int i) const;

    //precondition: that the int i is within the array size
    //postcondition: returns the quantity at index i
    const int HTGetQuantity(const int i) const;

    //precondition: none
    //postcondition: increments everytime a position in the array has data, returns total
    const int calculateParts() const;

    //precondition: none
    //postcondition: returns the total amount of inventory in the array
    const int calculateInventory() const;

    //precondition: none
    //postcondition: increments a counter whenever quantity is < pass. returns total
    const int calculateLessThan(const int pass) const;


private:
    value_type table[5000];
};

//precondition: passed HTable must exist / be initialised
//postcondition: prints HTable to console
template <typename value_type>
std::ostream &operator<<(std::ostream &out, HTable<value_type>& hashtable);
#include "HTable.hpp"
#endif //HTable_Header
