#ifndef HEAPTYPE_H
#define HEAPTYPE_H

#include <iostream>
#include "OrderType.h"

template<class ItemType>
class HeapType {
public:
	void reheapDown(int root, int bottom);
	void reheapUp(int root, int bottom);
	void heapSort(ItemType values[], int numValues);

	ItemType* elements;
	int numElements;
};

#endif