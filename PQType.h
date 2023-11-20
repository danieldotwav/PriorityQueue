// PQType.h - Header file for priority queue and related exceptions

#ifndef PQTYPE_H
#define PQTYPE_H

#include "HeapType.h"
#include "OrderType.h"

// FullPQ exception class definition
class FullPQ : public std::exception {
public:
	FullPQ(const std::string& message = "Priority Queue is full") : msg(message) {}
	virtual const char* what() const throw() {
		return msg.c_str();
	}

private:
	std::string msg;
};

// EmptyPQ exception class definition
class EmptyPQ : public std::exception {
public:
	EmptyPQ(const std::string& message = "Priority Queue is full") : msg(message) {}
	virtual const char* what() const throw() {
		return msg.c_str();
	}

private:
	std::string msg;
};


// PQType class template definition
template<class ItemType>
class PQType {
public:
	PQType();
	PQType(int);
	~PQType();
	PQType(const PQType<ItemType>& other);
	PQType<ItemType>& operator=(const PQType<ItemType>& other);

	void makeEmpty();
	bool isEmpty() const;
	bool isFull() const;
	void enqueue(ItemType newItem);
	void dequeue(ItemType& item);

private:
	HeapType<ItemType> items;
	int length; // Keeps track of number of orders
	int maxItems;
	int nextOrderNumber;

	void copyQueue(const PQType<ItemType>& other);
};


// Template member function definitions (for template instantiation)
template<class ItemType>
PQType<ItemType>::PQType() {
	maxItems = DEFAULT_INVENTORY_SIZE;
	length = 0;
	nextOrderNumber = 1;
	try {
		items.elements = new ItemType[maxItems];
	}
	catch (std::bad_alloc& e) {
		std::cerr << "Error: Unable to allocate memory for the priority queue" << e.what() << "\n";
	}
}

template <class ItemType>
PQType<ItemType>::PQType(int max) {
	maxItems = max;
	length = 0;
	nextOrderNumber = 1;
	try {
		items.elements = new ItemType[max];
	}
	catch (std::bad_alloc& e) {
		std::cerr << "Error: Unable to allocate memory for the priority queue" << e.what() << "\n";
	}
}

template <class ItemType>
PQType<ItemType>::~PQType() {
	delete[] items.elements;
}

template <class ItemType>
PQType<ItemType>::PQType(const PQType<ItemType>& other) {
	try {
		copyQueue(other);
	}
	catch (std::bad_alloc& e) {
		std::cerr << "Error: Unable to allocate memory for the priority queue" << e.what() << "\n";
	}
}

template <class ItemType>
PQType<ItemType>& PQType<ItemType>::operator=(const PQType<ItemType>& other) {
	if (this != &other) {
		delete[] items.elements;
		copyQueue(other);
	}
	return *this;
}

template<class ItemType>
void PQType<ItemType>::copyQueue(const PQType<ItemType>& other) {
	maxItems = other.maxItems;
	length = other.length;
	items.elements = new ItemType[maxItems];

	for (int i = 0; i < length; i++) {
		items.elements[i] = other.items.elements[i];
	}
}

template <class ItemType>
void PQType<ItemType>::makeEmpty() {
	length = 0;
}

template <class ItemType>
bool PQType<ItemType>::isEmpty() const {
	return length == 0;
}

template <class ItemType>
bool PQType<ItemType>::isFull() const {
	return length == maxItems;
}

template <class ItemType>
void PQType<ItemType>::enqueue(ItemType newItem) {
	if (isFull()) {
		throw FullPQ();
	}
	else {
		newItem.orderNumber = nextOrderNumber++;
		newItem.calculateFinalPrice();
		items.elements[length] = newItem;
		length++;
		items.reheapUp(0, length - 1);
	}
}

template <class ItemType>
void PQType<ItemType>::dequeue(ItemType& item) {
	if (isEmpty()) {
		throw EmptyPQ();
	}
	else {
		item = items.elements[0];
		items.elements[0] = items.elements[length - 1];
		length--;
		items.reheapDown(0, length - 1);
	}
}




#endif