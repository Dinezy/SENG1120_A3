//
// Created by TobyD on 16/10/2021.
//

#ifndef SENG1120_A3_HTABLE_H
#define SENG1120_A3_HTABLE_H

#include <cstddef>
#include <iostream>
#include <ostream>
template <typename value_type>

class HTable {
public:

    HTable();
    ~HTable();

    int hashfun(const value_type& value);

    void add(value_type data);

    void remove(value_type data);

    std::string HTGetCode(int i);

    int HTGetQuantity(int i);

    int calculateParts();

    int calculateInventory();

    int calculateLessThan(int pass);


private:

    value_type table[5000];         //TODO: work this out properly
    int size;

};
template <typename value_type>
std::ostream &operator<<(std::ostream &out, HTable<value_type>& hashtable);
#include "HTable.hpp"
#endif //SENG1120_A3_HTABLE_H
