#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>

const double MARKUP_STANDARD = 0.33;
const double MARKUP_EXPEDITE = 0.55;
const double MARKUP_EXTREME = 0.77;

const double WIDGET_PRICE = 10.00;
const int DEFAULT_INVENTORY_SIZE = 1000;

const int MAX_HEAP_SIZE = 100; // Maximum orders that can be placed in a day
const int FIRST_ORDER_NUM = 101; // First order number of the day

const int AVAILABLE_WIDGETS_WIDTH = 20; // "Available Widgets" header width
const int WIDGET_PRICE_WIDTH = 20; // "Price Per Widget ($)" header width
const int ORDER_WIDTH = 10; // "Order #" header width
const int STATUS_WIDTH = 15; // "Rush Status" header width
const int QUANT_WIDTH = 17; // "Quantity Ordered" header width
const int WH_COST_WIDTH = 28; // "Total Warehouse Cost" header width
const int MARKUP_WIDTH = 22; // "Amount Markup" header width
const int DAILY_TOTALS_WIDTH = 30; // "Daily Totals" left header width

const int TABLE_WIDTH = ORDER_WIDTH + STATUS_WIDTH + QUANT_WIDTH + MARKUP_WIDTH + WH_COST_WIDTH + WH_COST_WIDTH + MARKUP_WIDTH; // Total width of the table

const int SENTINEL = -999; // Sentinel value for input validation
const int AVAILABLE_WIDGETS_LEN = 17; // Length of "Available Widgets" header

enum RushStatus { STANDARD = 1, EXPEDITE_RUSH, EXTREME_RUSH };

const std::string RUSH_STATUS_STRINGS[] = { "", "STANDARD", "EXPEDITE", "EXTREME" };

const double RUSH_MARKUPS[] = { 0.0, MARKUP_STANDARD, MARKUP_EXPEDITE, MARKUP_EXTREME };

#endif