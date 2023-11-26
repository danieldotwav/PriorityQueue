// PriorityQueue.h - Header file for priority queue and related exceptions

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Heap.h"


// FullPQ exception class definition
class FullPQ : public std::exception {
public:
	FullPQ(const std::string& message = "Priority Queue is Full") : msg(message) {}
	virtual const char* what() const throw() {
		return msg.c_str();
	}

private:
	std::string msg;
};

// EmptyPQ exception class definition
class EmptyPQ : public std::exception {
public:
	EmptyPQ(const std::string& message = "Priority Queue is Empty") : msg(message) {}
	virtual const char* what() const throw() {
		return msg.c_str();
	}

private:
	std::string msg;
};

// Priority Queue class definition
class PriorityQueue {
public:
	PriorityQueue();
	PriorityQueue(int max);

	PriorityQueue(const PriorityQueue& other);
	PriorityQueue& operator=(const PriorityQueue& other);

	void enqueue(Order newItem);
	void dequeue(Order& item);
	void makeEmpty() { length = 0; }
	bool isEmpty() const { return length == 0; }
	bool isFull() const { return length == maxItems; }
	int getLength() const { return length; }
	int getMaxItems() const { return maxItems; }

private:
	Heap items;
	int length; // Keeps track of number of orders
	int maxItems;

	void copyQueue(const PriorityQueue& other);
};



#endif