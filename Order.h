#ifndef ORDER_H
#define ORDER_H

#include "Constants.h"

// Just order
class Order {
private:
	RushStatus rush;
	int orderNumber;
	int quantity; // Number of widgets in the order
	double warehouseCost; // Base price before markup
	double customerCost; // Price after applying the rush markup

public:
	Order();
	Order(int n_order_num, int n_quantity, double n_base_price, RushStatus n_rush);
	bool operator<(const Order& other) const;
	bool operator<=(const Order& other) const;

	void calculateCustomerCost();
	int getOrderNumber() const { return orderNumber; }
	int getQuantity() const { return quantity; }
	double getWarehouseCost() const { return warehouseCost; }
	double getCustomerCost() const { return customerCost; }

	double getMarkupAmount() const { return customerCost - warehouseCost; }
	double getMarkupPercent() const { return (getMarkupAmount() / getWarehouseCost() * 100); }
	RushStatus getRushStatus() const { return rush; }
};

#endif