//
//  PriceListItem.h
//  Project - CPSC - 131 -05
//
//  Created by Jeremy Escobar
//  Copyright © Jeremy Escobar. All rights reserved.
//

#pragma once

#include<iostream>
#include <string>

using namespace std;
class PriceListItem {
private:
    // private member variables
    string itemName;
    string code;
    double price;
    bool   taxable;
    
public:
    
    PriceListItem(); 
    PriceListItem(const string &itemName, const string &code, double price, bool taxable);
    string getItemName();
    string getCode();
    double getPrice();
    bool   isTaxable();
    
};
