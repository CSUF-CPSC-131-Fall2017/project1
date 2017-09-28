//
//  GroceryBill.cpp
//  Project - CPSC - 131 -05
//
//  Created by Jeremy Escobar on 9/27/17.
//  Copyright © 2017 Jeremy Escobar. All rights reserved.
//

#include <fstream>
#include <iostream>

#include "GroceryBill.h"

using namespace std;

GroceryBill::GroceryBill(const PriceList *priceList, double taxRate) {
    groceryBillTotal      = 0;
    billCount         = 0;
    theCodesAre       = new string [1000000];
    quanity           = new double [1000000];
    this->listOfItems = *priceList;
    this->taxRate     = taxRate;
}

void GroceryBill::scanItem(string scanCode, double quantity) {
    
    PriceListItem items = listOfItems.getItem (scanCode);
    
        groceryBillTotal += items.getPrice()*quantity;
    
    if (items.isTaxable())
        
                groceryBillTotal += items.getPrice()*quantity*(taxRate/100);
    
                    theCodesAre[billCount] = scanCode;
    
                        quanity[billCount++] = quantity;
    
}

// Scan multiple codes and quantities from the given text file

// Each line contains two numbers separated by space: the first is the code (an integer), the second the quantity (a float/double)

// Example line from text file:

// 15000000 1.5

void GroceryBill::scanItemsFromFile(string filename) {
    
    // To be completed
    
    // HINT: Look at code in PriceList::createPriceListFromDatafile(string filename)
    
    ifstream myfile(filename);
    
    if (myfile.is_open()) {
        
        cout << "Successfully opened file " << filename << endl;
        string code;
        double qty;
        while (myfile >> code >> qty) {
            scanItem (code, qty);
        }
            myfile.close();
        
    }
    
    else
        
        throw invalid_argument("Could not open file " + filename);
    
}

// return the total cost of all items scanned

double GroceryBill::getTotal() {
    
    return groceryBillTotal;
    
}

// Print the bill to cout. Each line contains the name of an item, total price, and the letter "T" if tax was addded.

// The last line shows the total.

// An example:

//Plastic_Wrap 1.60547 T

//Sugar_white 5.475

//Waffles_frozen 5.16

//Oil_Canola_100%_pure 2.69

//Potatoes_red 13.446

//TOTAL 28.3765

void GroceryBill::printBill() {
    
    for(int i = 0; i < billCount; i++)
        
    {
        
        cout << listOfItems.getItem(theCodesAre[i]).getItemName()<< " "<<quanity[i] << " ";
        
            if (listOfItems.getItem(theCodesAre[i]).isTaxable())
            
                cout << "T";
        
                    cout << endl;
        
                        }
    
}
