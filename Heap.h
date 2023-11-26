#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include "Order.h"

class Heap {
public:
	void reheapDown(int root, int bottom);
	void reheapUp(int root, int bottom);
	void heapSort(Order values[], int numValues);

	Order elements[MAX_HEAP_SIZE];
	int numElements;
};

#endif