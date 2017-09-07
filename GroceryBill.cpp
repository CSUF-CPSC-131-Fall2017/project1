#include "GroceryBill.h"
#include <iostream>

using namespace std;

GroceryBill::GroceryBill(const PriceList *priceList, double taxRate) {
	// To be completed

}


void GroceryBill::scanItem(string scanCode, double quantity) {
	// To be completed
}

// Scan multiple codes and quantities from the given text file
// Each line contains two numbers separated by space: the first is the code (an integer), the second the quantity (a float/double)
// Example line from text file:
// 15000000 1.5
void GroceryBill::scanItemsFromFile(string filename) {
	// To be completed
	// HINT: Look at code in PriceList::createPriceListFromDatafile(string filename)
}

// return the total cost of all items scanned
double GroceryBill::getTotal() {
	// To be completed
}

// Print the bill to cout. Each line contains the name of an item, total price, and the letter "T" if tax was addded. 
// The last line shows the total.
// An example:
//Plastic_Wrap	1.60547 T
//Sugar_white	5.475
//Waffles_frozen	5.16
//Oil_Canola_100%_pure	2.69
//Potatoes_red	13.446
//TOTAL 	28.3765
void GroceryBill::printBill() {
	// To be completed

}

