//
//  main.cpp
//  Project - CPSC - 131 -05
//
//  Created by Jeremy Escobar.
//  Copyright © Jeremy Escobar. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

#include "PriceList.h"
#include "GroceryBill.h"

//////////////////////////////////////////////////////////////////////////////////////////////
// DO NOT EDIT THIS FILE (except for your own testing)
// CODE WILL BE GRADED USING A MAIN FUNCTION SIMILAR TO THIS
//////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

template <typename T>
bool testAnswer(const string &nameOfTest, const T &received, const T &expected) {
	if (received == expected) {
		cout << "PASSED " << nameOfTest << ": expected and received " << received << endl;
		return true;
	}
	cout << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
	return false;
}

template <typename T>
bool testAnswerEpsilon(const string &nameOfTest, const T &received, const T &expected) {
	const double epsilon = 0.0001;
	if ((received - expected < epsilon) && (expected - received < epsilon)) {
		cout << "PASSED " << nameOfTest << ": expected and received " << received << endl;
		return true;
	}
	cout << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
	return false;
}

int main() {
	{
		// test only the PriceListItem class
		PriceListItem item("Apples", "1000", 1.29, true);
		testAnswer("PriceListItem.getCode test", item.getCode(), string("1000"));
		testAnswer("PriceListItem.getItemName test", item.getItemName(), string("Apples"));
		testAnswerEpsilon("PriceListItem.getPrice test", item.getPrice(), 1.29);
		testAnswer("PriceListItem.isTaxable test", item.isTaxable(), true);

	}

	{
		// test only the PriceList class
		PriceList priceList;
		priceList.addEntry("Apples", "1000", 1.99, false);
		priceList.addEntry("Bananas", "2000", 0.99, false);
		testAnswer("PriceList isValid1", priceList.isValid("1000"), true);
		testAnswer("PriceList isValid2", priceList.isValid("19"), false);

		// test copy constructor
		PriceList priceList2 = priceList;
		testAnswer("PriceList copy constructor test1", priceList2.isValid("1000"), true);
		priceList.addEntry("Milk", "3000", 3.49, false);
		priceList2.addEntry("Eggs", "4000", 4.99, false);
		testAnswer("PriceList copy constructor test2", priceList.isValid("4000"), false);

		// test assignment operator
		PriceList priceList3;
		priceList3 = priceList;
		testAnswer("PriceList assignment test1", priceList3.isValid("1000"), true);
		priceList.addEntry("Orange_juice_1gal", "4500", 6.49, false);
		priceList3.addEntry("Diapers_30ct", "5000", 19.99, false);
		testAnswer("PriceList assignment test2", priceList.isValid("5000"), false);
	}
	{
		// test capacity of the PriceList class
		PriceList priceList;
		for (int i = 1; i<100000; i++)
			priceList.addEntry(string("Apples_") + to_string(i), to_string(i), 1.99, false);
		testAnswer("PriceList big data1", priceList.isValid("20000"), true);
		testAnswer("PriceList big data2", priceList.isValid("100000"), false);
	}
	{
		// test the GroceryBill class
		PriceList priceList;
		priceList.createPriceListFromDatafile("pricelist.txt");
		GroceryBill mybill(&priceList, 7.75);
		testAnswer("GroceryBill initialization", mybill.getTotal(), 0.0);
		// test GroceryBill::scanItem
		mybill.scanItem("9752347409", 1);
		testAnswerEpsilon("GroceryBill.getTotal", mybill.getTotal(), 1.49*1.0775);

		// test if error checking is done in GroceryBill::scanItem
		try {
			mybill.scanItem("1000", 1);
			cout << "FAILED GroceryBill::scanItem did not throw exception for invalid input" << endl;
		}
		catch (exception &e) {
			cout << "Caught exception: " << e.what() << endl;
			cout << "PASSED GroceryBill::scanItem threw exception for invalid input" << endl;
		}

		// test quantity calculation in total
		mybill.scanItem("9129592337", 2.5);
		testAnswerEpsilon("GroceryBill.getTotal", mybill.getTotal(), 1.49*1.0775 + 2.5*2.19);
		mybill.printBill();

		// test reading items from file
		mybill.scanItemsFromFile("billitems1.txt");
		testAnswerEpsilon("GroceryBill.getTotal", mybill.getTotal(), 28.3765);
		mybill.printBill();

	}

	// system("pause");
}
