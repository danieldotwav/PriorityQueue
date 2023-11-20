#ifndef ORDERTYPE_H
#define ORDERTYPE_H

#include "Constants.h"
#include <iostream>

struct OrderType {
public:
	OrderType();
	OrderType(int quantity, double basePrice, RushStatus rush);
	RushStatus rush;
	int orderNumber;
	int quantity; // Number of widgets in the order
	double basePrice; // Base price before markup
	double finalPrice; // Price after applying the rush markup

	void calculateFinalPrice();
};

#endif