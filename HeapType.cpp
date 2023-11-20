#include "HeapType.h"
#include "OrderType.h"

// Pre-Condition: root should be a valid index within the heap array (0 to numElements - 1), and bottom should be the index of the last element in the heap. The subtree rooted at root must satisfy the heap property except possibly for the node at root.
template <class ItemType>
void HeapType<ItemType>::reheapDown(int root, int bottom) {
	
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;

	if (leftChild <= bottom) {
		if (leftChild == bottom) {
			maxChild = leftChild;
		}
		else {
			if (elements[leftChild] <= elements[rightChild]) {
				maxChild = rightChild;
			}
			else {
				maxChild = leftChild;
			}
		}
		if (elements[root] < elements[maxChild]) {
			Swap(elements[root], elements[maxChild]);
			reheapDown(maxChild, bottom);
		}
	}
}

// Pre-Condition: bottom should be a valid index within the heap array (greater than or equal to 0 and less than numElements), and root should typically be the index of the root of the heap (0). The path from bottom to root may violate the heap property, and this function is called to restore it.
template <class ItemType>
void HeapType<ItemType>::reheapUp(int root, int bottom) {
	int parent;

	if (bottom > root) {
		parent = (bottom - 1) / 2;
		if (elements[parent] < elements[bottom]) {
			Swap(elements[parent], elements[bottom]);
			reheapUp(root, parent);
		}
	}
}


// Pre-Condition: values should be a valid array of ItemType objects, and numValues should be the number of elements in the array. This function is called to sort the array in ascending order.
template <class ItemType>
void HeapType<ItemType>::heapSort(ItemType values[], int numValues) {
	elements = values;
	numElements = numValues;

	for (int index = numElements / 2 - 1; index >= 0; index--) {
		reheapDown(index, numElements - 1);
	}

	for (int index = numElements - 1; index >= 1; index--) {
		Swap(elements[0], elements[index]);
		reheapDown(0, index - 1);
	}
}