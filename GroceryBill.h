//
//  GroceryBill.h
//  Project - CPSC - 131 -05
//
//  Created by Jeremy Escobar on 9/27/17.
//  Copyright © 2017 Jeremy Escobar. All rights reserved.
//

#pragma once

#include "PriceList.h"

class GroceryBill {
    
public:
    
    GroceryBill(const PriceList *priceList, double taxRate);
    void scanItem(string scanCode, double quantity);
    // add item and quantity to bill; throw exception if item's code is not found in the pricelist
    void scanItemsFromFile(string filename);
    // Scan multiple codes and quantities from the given text file
    double getTotal();
    // return the total cost of all items scanned
    void printBill();
    // Print the bill to cout. Each line contains the name of an item, total price, and the letter "T" if tax was addded.
    
private:

    const PriceList listOfItems;
    int    billCount;
    string *theCodesAre;
    double *quanity;
    double taxRate;
    double groceryBillTotal;
};
