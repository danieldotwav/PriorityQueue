#include "OrderType.h"

OrderType::OrderType() : orderNumber(0), quantity(0), basePrice(0.0), finalPrice(0.0), rush(STANDARD) {}

OrderType::OrderType(int n_quantity, double n_base_price, RushStatus rush) : quantity(n_quantity), basePrice(n_base_price), rush(STANDARD) {
	calculateFinalPrice();
}

void OrderType::calculateFinalPrice() {
	switch (rush) {
	case STANDARD:
		finalPrice = basePrice + (basePrice * MARKUP_STANDARD);
		break;
	case EXPEDITE_RUSH:
		finalPrice = basePrice * MARKUP_EXPEDITE;
		break;
	case EXTREME_RUSH:
		finalPrice = basePrice * MARKUP_EXTREME;
		break;
	default:
		std::cout << "ERROR: Unable to determine rush status. Final price set to base price.\n";
		finalPrice = basePrice;
	}
}