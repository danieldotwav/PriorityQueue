#include "PQType.h"
#include "HeapType.h"
//#include "OrderType.h"
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

// Create an enum class
enum Menu { SHOW_INVENTORY = 1, ENTER_NEW_ORDER, PROCESS_DAILY_ORDERS, EXIT };

void printCurrentInventory(int dailyInventory);
void placeNewOrder(int& dailyInventory, PQType<OrderType> orderQueue);
int getNumWidgets(int dailyInventory);
RushStatus getRushStatus(bool& isOrderCancelled);
void purgeInputErrors(string errorMessage);

int main() {
    cout << "Welcome to the Widget Ordering System\n\n";

    int selection;
    int dailyInventory = WIDGET_DAILY_INVENTORY;
    PQType<OrderType> orderQueue(MAX_ORDERS);

    do {
        cout << "MAIN MENU\nPlease select one of the following:\n"
            "1. Show Inventory\n"
            "2. Place New Order\n"
            "3. Close Day - Process Total Daily Orders\n"
            "4. Exit\n"
            "Selection: ";
        cin >> selection;

        switch (selection) {
        case SHOW_INVENTORY:
            printCurrentInventory(dailyInventory);
            break;
        case ENTER_NEW_ORDER:
            if (dailyInventory > 0) {
                placeNewOrder(dailyInventory, orderQueue);
            }
            else {
				cout << "No more widgets available today. Please try again tomorrow.\n";
			}
            break;
        case PROCESS_DAILY_ORDERS:
            //printBinaryTree(tree);
            break;
        case EXIT:
            cout << "\nHave a nice day!\n";
            break;
        default:
            purgeInputErrors("\nError: Invalid Menu Option\n");
        }
    } while (selection != EXIT);

	return 0;
}

void printCurrentInventory(int dailyInventory) {
    // Table Header
    cout << "\n\n" << left << setw(WIDTH) << "Available Widgets"
        << right << setw(WIDTH) << "Price per Widget ($)" 
        << left << '\n';

    // Line separator
    cout << setfill('-') << setw(WIDTH * 2) << "" << setfill(' ')
        << endl;

    // Table Data
    cout << left << setw(WIDTH) << dailyInventory
        << right << setw(WIDTH) << fixed << setprecision(2) << WIDGET_PRICE << "\n\n";
}

void placeNewOrder(int& dailyInventory, PQType<OrderType> orderQueue) {
    cout << "\nNEW ORDER\n";
	int numWidgets = getNumWidgets(dailyInventory);
    bool isOrderValid = true;

    if (numWidgets <= 0 || numWidgets > dailyInventory) {
		cout << "***Returning to Main Menu***\n\n";
        isOrderValid = false;
	}

    bool isOrderCancelled = false;
    RushStatus rushStatus;
	
    // Get the rush status
    if (isOrderValid == true) {
        rushStatus = getRushStatus(isOrderCancelled);
        if (isOrderCancelled == true) {
            cout << "\nOrder cancelled\n***Returning to Main Menu***\n\n";
            isOrderValid = false;
        }
    }

    if (isOrderValid && !isOrderCancelled) {
        int basePrice = numWidgets * WIDGET_PRICE;
        OrderType order(numWidgets, basePrice, rushStatus);

        try {
            //orderQueue.enqueue(order);
            dailyInventory -= numWidgets;
            cout << "***Order Placed Successfully***\n\n"
                "\nOrder Details:\n"
                "Order #" << order.orderNumber << "\n"
                "Rush Status: 	" << order.rush << "\n"
                "Quantity:      " << order.quantity << "\n"
                "Total Cost:   $" << order.finalPrice << "\n\n";
        }
        catch (std::bad_alloc& e) {
            cerr << "Error: Unable to allocate memory for the priority queue" << e.what() << "\n";
        }
	}
}

int getNumWidgets(int dailyInventory) {
    int numWidgets;
    string errorMessage;

    cout << "Please enter the number of widgets to order: ";
    cin >> numWidgets;

    if (numWidgets <= 0) {
        errorMessage = "\nError: Quantity must be greater than 0";
        purgeInputErrors(errorMessage);
        numWidgets = SENTINEL;
    }
    else if (numWidgets > dailyInventory) {
        errorMessage = "\nError: Only " + to_string(dailyInventory) + " widgets are available in stock today";
        purgeInputErrors(errorMessage);
        numWidgets = SENTINEL;
    }

    return numWidgets;
}

RushStatus getRushStatus(bool& isOrderCancelled) {
    RushStatus rush = CANCEL_ORDER;
    int userInput;

    cout << "\nPlease select the Delivery Speed:\n"
        "1. Standard \n"
        "2. Expedite\n"
        "3. Extreme\n"
        "4. Cancel Order\n"
        "Selection: ";
    cin >> userInput;

    switch (userInput) {
        case STANDARD:
        case EXPEDITE_RUSH:
        case EXTREME_RUSH:
            rush = static_cast<RushStatus>(userInput);
            break;
        case CANCEL_ORDER:
            isOrderCancelled = true;
			break;
        default:
            purgeInputErrors("\nError: Invalid Delivery Speed");
            isOrderCancelled = true;
    }

    return rush;
}

void purgeInputErrors(string errorMessage) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << errorMessage << endl;
}