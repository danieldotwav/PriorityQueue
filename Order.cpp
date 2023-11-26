#include "Order.h"
//#include "RushStatus.h"

Order::Order() : orderNumber(0), quantity(0), warehouseCost(0.0), customerCost(0.0), rush(STANDARD) {}

Order::Order(int n_order_num, int n_quantity, double n_base_price, RushStatus n_rush) : orderNumber(n_order_num), quantity(n_quantity), warehouseCost(n_base_price), rush(n_rush) {
	calculateCustomerCost();
}

//  Assume high enum value represent higher priority
bool Order::operator<(const Order& other) const {
	return this->rush < other.rush;
}

bool Order::operator<=(const Order& other) const {
	return this->rush <= other.rush;
}

void Order::calculateCustomerCost() {
	customerCost = warehouseCost + (warehouseCost * RUSH_MARKUPS[rush]);
}
