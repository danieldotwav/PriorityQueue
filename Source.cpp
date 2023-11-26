#include "PriorityQueue.h"
#include "Heap.h"
#include <limits>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

enum Menu { SHOW_INVENTORY = 1, ENTER_NEW_ORDER, PROCESS_DAILY_ORDERS, EXIT };

void placeNewOrder(int& numWidgetsRemaining, PriorityQueue& orderQueue, int& orderNumber);
void processDailyOrders(int numWidgetsRemaining, PriorityQueue& orderQueue);

int getUserNumWidgets(int numWidgetsRemaining);
RushStatus getUserRushStatus(bool& isOrderCancelled);
void purgeInputErrors(string errorMessage);
void printCurrentInventory(int numWidgetsRemaining);
stringstream getCurrentInventoryHeaderSS();
void printIndividualOrder(Order& order);
stringstream getIndividualOrderHeaderSS();


int main() {
    cout << "Welcome to the Widget Ordering System\n\n";

    int selection;
    int orderNumber = FIRST_ORDER_NUM;
    int numWidgetsRemaining = DEFAULT_INVENTORY_SIZE;
    PriorityQueue orderQueue(MAX_HEAP_SIZE);

    do {
        cout << "MAIN MENU\nPlease select one of the following:\n"
            "1. Show Inventory\n"
            "2. Place New Order\n"
            "3. Process Daily Orders\n"
            "4. Exit\n"
            "Selection: ";
        cin >> selection;

        switch (selection) {
        case SHOW_INVENTORY:
            printCurrentInventory(numWidgetsRemaining);
            break;
        case ENTER_NEW_ORDER:
            placeNewOrder(numWidgetsRemaining, orderQueue, orderNumber);
            break;
        case PROCESS_DAILY_ORDERS:
            processDailyOrders(numWidgetsRemaining, orderQueue);
            break;
        case EXIT:
            cout << "\nGoodbye!\n";
            break;
        default:
            purgeInputErrors("\nError: Invalid Menu Option\n");
        }
    } while (selection != EXIT && selection != PROCESS_DAILY_ORDERS);

    cout << "Terminating Program\n";
	return 0;
}


void placeNewOrder(int& numWidgetsRemaining, PriorityQueue& orderQueue, int& orderNumber) {
    if (numWidgetsRemaining <= 0) {
        cout << "\nNumber of Widget's In-Stock Today: " << numWidgetsRemaining << ". Please Process Daily Orders And Try Again Tomorrow.\n\n";
    }
    else {
        cout << "\nNEW ORDER\n";
        int numWidgetsToPurchase = getUserNumWidgets(numWidgetsRemaining);

        if (numWidgetsToPurchase <= 0 || numWidgetsToPurchase > numWidgetsRemaining) {
            cout << "Order Cancelled. Returning to Main Menu\n\n";
        }
        else {
            // Get the rush status
            bool isOrderCancelled = false;
            RushStatus rushStatus = getUserRushStatus(isOrderCancelled);

            if (isOrderCancelled == true) {
                cout << "\nOrder Cancelled\nReturning to Main Menu\n\n";
            }
            else {
                int warehouseCost = numWidgetsToPurchase * WIDGET_PRICE;
                Order order(orderNumber, numWidgetsToPurchase, warehouseCost, rushStatus);

                try {
                    orderQueue.enqueue(order);
                    numWidgetsRemaining -= numWidgetsToPurchase;
                    stringstream header = getIndividualOrderHeaderSS();
                    cout << header.str();
                    printIndividualOrder(order);
                    orderNumber++;
                }
                catch (FullPQ& e) {
                    cerr << "Error: " << e.what() << "\n";
                }
            }
        }
    }
}

void processDailyOrders(int numWidgetsRemaining, PriorityQueue& orderQueue) {
    if (orderQueue.isEmpty()) {
        cout << "\nNo Orders Placed Today\n\n";
    }
    else {
        try {
            double totalMarkup = 0.0;
            double totalCostToCustomer = 0.0;
            double totalCostToWarehouse = 0.0;

            cout << "\n-DAILY ORDERS-\n\n";

            // Testing Copy Constructor
            PriorityQueue tempPQ(orderQueue.getMaxItems());
            Order order;
            
            while (!orderQueue.isEmpty()) {
                orderQueue.dequeue(order);
                tempPQ.enqueue(order);

                totalMarkup += order.getMarkupAmount();
                totalCostToCustomer += order.getCustomerCost();
                totalCostToWarehouse += order.getWarehouseCost();
            }

            stringstream header = getIndividualOrderHeaderSS();
            cout << header.str();

            while (!tempPQ.isEmpty()) {
                tempPQ.dequeue(order);
                printIndividualOrder(order);
                orderQueue.enqueue(order);
            }

            cout << setfill('.') << endl;

            cout << setw(DAILY_TOTALS_WIDTH) << left << "Total Widgets Sold Today" 
                << setw(TABLE_WIDTH - DAILY_TOTALS_WIDTH) << right << (DEFAULT_INVENTORY_SIZE - numWidgetsRemaining) << '\n' 
                << setw(DAILY_TOTALS_WIDTH) << left << "Total Markup" 
                << setw(TABLE_WIDTH - DAILY_TOTALS_WIDTH) << right << "$" + to_string(totalMarkup).substr(0, to_string(totalMarkup).find('.') + 3) << '\n' 
                << setw(DAILY_TOTALS_WIDTH) << left << "Total Cost to Customer" 
                << setw(TABLE_WIDTH - DAILY_TOTALS_WIDTH) << right << "$" + to_string(totalCostToCustomer).substr(0, to_string(totalCostToCustomer).find('.') + 3) << '\n'
				<< setw(DAILY_TOTALS_WIDTH) << left << "Total Cost to Warehouse" 
                << setw(TABLE_WIDTH - DAILY_TOTALS_WIDTH) << right << "$" + to_string(totalCostToWarehouse).substr(0, to_string(totalCostToWarehouse).find('.') + 3);
            
            cout << "\n\nSuccessfully Processed All Orders\n\n";
        }
        catch (EmptyPQ& e) {
			cerr << "Error: " << e.what() << "\n";
		}
        catch (FullPQ& e) {
			cerr << "Error: " << e.what() << "\n";
		}
    }
}

int getUserNumWidgets(int numWidgetsRemaining) {
    int numWidgetsToPurchase;
    string input;
    string errorMessage;

    cout << "Please enter the number of widgets to order: ";
    cin >> input;

    try {
        numWidgetsToPurchase = stoi(input);

        if (numWidgetsToPurchase <= 0) {
            errorMessage = "\nError: Quantity must be greater than 0";
            purgeInputErrors(errorMessage);
            numWidgetsToPurchase = SENTINEL;
        }
        else if (numWidgetsToPurchase > numWidgetsRemaining) {
            errorMessage = "\nError: Only " + to_string(numWidgetsRemaining) + " widgets are available for purchase today";
            purgeInputErrors(errorMessage);
            numWidgetsToPurchase = SENTINEL;
        }
    }
    catch (invalid_argument& e) {
		errorMessage = "\nError: Invalid Input";
		purgeInputErrors(errorMessage);
		numWidgetsToPurchase = SENTINEL;
	}
    catch (out_of_range& e) {
		errorMessage = "\nError: Invalid Input";
		purgeInputErrors(errorMessage);
		numWidgetsToPurchase = SENTINEL;
	}
    
    return numWidgetsToPurchase;
}

// Remove option to cancel, if they enter incorrectly aback to main
RushStatus getUserRushStatus(bool& isOrderCancelled) {
    RushStatus rush = STANDARD;
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
            cout << '\n';
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

void printCurrentInventory(int numWidgetsRemaining) {
    cout << "\n-CURRENT INVENTORY-\n\n";

    // Printing the table header
    stringstream headerSS = getCurrentInventoryHeaderSS();
    cout << headerSS.str();

    int offset = AVAILABLE_WIDGETS_WIDTH - AVAILABLE_WIDGETS_LEN;

    // Printing the table data
    cout << right << setw(AVAILABLE_WIDGETS_WIDTH - offset) 
        << numWidgetsRemaining << setw(offset) << "" << right << setw(WIDGET_PRICE_WIDTH) << fixed
        << setprecision(2) << WIDGET_PRICE << "\n\n";
}

stringstream getCurrentInventoryHeaderSS() {
    stringstream ss;

    // Printing the table header
    ss << left << setw(AVAILABLE_WIDGETS_WIDTH) << "Available Widgets"
        << right << setw(WIDGET_PRICE_WIDTH) << "Price Per Widget ($)\n";

    // Printing the line separator
    ss << setfill('-') << setw(AVAILABLE_WIDGETS_WIDTH) << "" << setw(WIDGET_PRICE_WIDTH) << ""
        << setfill(' ') << "\n";

    return ss;
}

void printIndividualOrder(Order& order) {
    // Printing the table data
    cout << left << setw(ORDER_WIDTH) << order.getOrderNumber()
        << left << setw(STATUS_WIDTH) << RUSH_STATUS_STRINGS[order.getRushStatus()]
        << right << setw(QUANT_WIDTH) << order.getQuantity()
        << right << setw(MARKUP_WIDTH) << fixed << setprecision(2) << order.getMarkupPercent()
        << right << setw(WH_COST_WIDTH) << order.getCustomerCost()
        << right << setw(WH_COST_WIDTH) << order.getWarehouseCost()
        << right << setw(MARKUP_WIDTH) << order.getMarkupAmount() 
        << "\n\n";
}

stringstream getIndividualOrderHeaderSS() {
    stringstream ss;
    // Store the table header
    ss << left << setw(ORDER_WIDTH) << "Order #"
        << left << setw(STATUS_WIDTH) << "Rush Status"
        << right << setw(QUANT_WIDTH) << "Quantity Ordered"
        << right << setw(MARKUP_WIDTH) << "Percent Markup (%)"
        << right << setw(WH_COST_WIDTH) << "Total Customer Cost ($)"
        << right << setw(WH_COST_WIDTH) << "Total Warehouse Cost ($)"
        << right << setw(MARKUP_WIDTH) << "Amount Markup ($)" << "\n";

    // Store the line separator
    ss << setfill('-') << setw(TABLE_WIDTH) << "" << setfill(' ') << "\n";

    return ss;
}


