//
//  PriceListItem.cpp
//  Project - CPSC - 131 -05
//
//  Created by Jeremy Escobar on 9/27/17.
//  Copyright © 2017 Jeremy Escobar. All rights reserved.
//

#include<iostream>
#include<string>

#include "PriceListItem.h"
using namespace std;

//paramter constructor
PriceListItem::PriceListItem(const string &itemName, const string &code, double price, bool taxable) {
    this->itemName = itemName;
    this->code     = code;
    this->price    = price;
    this->taxable  = taxable;
    
}
//default constructor
PriceListItem::PriceListItem() {
    itemName = "";
    code     = "";
    price    = 0;
    taxable  = false;
}
string PriceListItem::getItemName() { return itemName;}
string PriceListItem::getCode()     { return code;    }
double PriceListItem::getPrice()    { return price;   }
bool   PriceListItem::isTaxable()   { return taxable; }

