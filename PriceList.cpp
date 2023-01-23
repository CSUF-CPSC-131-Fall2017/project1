//
//  PriceList.cpp
//  Project - CPSC - 131 -05
//
//  Created by Jeremy Escobar 
//  Copyright © Jeremy Escobar. All rights reserved.
//


#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

#include "PriceList.h"
#include "PriceListItem.h"

using namespace std;

PriceList::PriceList()
{
    futureItems = new PriceListItem[1000000];
    itemSize    = 0;
}

PriceList::PriceList(PriceList & pL) {
    itemSize = pL.itemSize;
    futureItems = new PriceListItem[1000000];
    for (int i=0; i< itemSize; i++) {
        futureItems[i] = pL.futureItems[i];
    }
}

PriceList & PriceList::operator=(const PriceList *pL) {
    delete [] futureItems;
    itemSize = pL->itemSize;
    futureItems = new PriceListItem[1000000];
    for (int i=0; i< itemSize; i++) {
        futureItems[i] = pL->futureItems[i];
    }
    return *this;
}
// Load information from a text file with the given filename.

void PriceList::createPriceListFromDatafile(string filename) {
    ifstream myfile(filename);
    
    if (myfile.is_open()) {
        cout << "Successfully opened file " << filename << endl;
        string name;
        string code;
        double price;
        bool taxable;
        while (myfile >> name >> code >> price >> taxable) {
            //cout << code << " " << taxable << endl;
            addEntry (name, code, price, taxable);
        }
        myfile.close();
    }
    else
        throw invalid_argument("Could not open file " + filename);
}
// return true only if the code is valid

bool PriceList::isValid(string code) const {
    if (itemSize ==0)
        return false;
    for ( int i = 0; i < itemSize; i++)
    {
        if ( futureItems[i].getCode() == code)
            return true;
    }
    return false;
}

// return price, item name, taxable? as an ItemPrice object; throw exception if code is not found

PriceListItem PriceList::getItem(string code) const {
    if (!isValid(code))
        throw runtime_error("Item not found");
    for (int j = 0; j < itemSize; j++)
    {
        if ( futureItems[j].getCode() == code)
            return futureItems[j];
    }
    throw invalid_argument("Invalid code: " + code);
}

// add to the price list information about a new item

void PriceList::addEntry(string itemName, string code, double price, bool taxable) {
    
    
    if ( itemSize == 0)
    {
        futureItems = new PriceListItem[1000000];
    }
    PriceListItem pricedItems = PriceListItem (itemName, code, price, taxable);
    futureItems [itemSize] = pricedItems;
    itemSize++;
    
}
