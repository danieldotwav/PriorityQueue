#ifndef CONSTANTS_H
#define CONSTANTS_H

const double MARKUP_STANDARD = 0.33;
const double MARKUP_EXPEDITE = 0.55;
const double MARKUP_EXTREME = 0.77;

const double WIDGET_PRICE = 10.00;
const double WIDGET_DAILY_INVENTORY = 1000;
const int DEFAULT_INVENTORY_SIZE = 1000;

const int MAX_ORDERS = 100; // Maximum orders that can be placed in a day

const int WIDTH = 20; // Width for setw formatting
const int SENTINEL = -999; // Sentinel value for input validation

enum RushStatus { STANDARD = 1, EXPEDITE_RUSH, EXTREME_RUSH, CANCEL_ORDER };


#endif