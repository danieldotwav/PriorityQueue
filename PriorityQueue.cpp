#include "PriorityQueue.h"

// Just use regular arrays

PriorityQueue::PriorityQueue() : length(0), maxItems(MAX_HEAP_SIZE) {
}

PriorityQueue::PriorityQueue(int max) : length(0), maxItems((max <= MAX_HEAP_SIZE) ? max : MAX_HEAP_SIZE) {
}

PriorityQueue::PriorityQueue(const PriorityQueue& other) {
	copyQueue(other);
}


PriorityQueue& PriorityQueue::operator=(const PriorityQueue& other) {
	if (this != &other) {
		copyQueue(other);
	}
	return *this;
}

void PriorityQueue::enqueue(Order newItem) {
	if (isFull()) {
		throw FullPQ();
	}
	else {
		newItem.calculateCustomerCost();
		items.elements[length] = newItem;
		length++;
		items.reheapUp(0, length - 1);
	}
}

void PriorityQueue::dequeue(Order& item) {
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

void PriorityQueue::copyQueue(const PriorityQueue& other) {
	maxItems = other.maxItems;
	length = other.length;

	// Ensure that we do not copy more elements than the allocated space
	int elementsToCopy = (length < maxItems) ? length : maxItems;

	for (int i = 0; i < elementsToCopy; i++) {
		items.elements[i] = other.items.elements[i];
	}
}