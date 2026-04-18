#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

// Constants //
const int MAX_QUEUE = 100;

struct QueueNode
{
	// Struct Stuff //
	int vertex;
	int priority;
};

class Queue{
private:
	// Data //
	QueueNode heap[MAX_QUEUE];
	int size;
	// Heap //
	void heapifyUp(int index);
	void heapifyDown(int index);
	// Other //
	void swap(int i1, int i2);

public:
	// Constructor //
	Queue();
	// Checks and Data Getting //
	bool isEmpty() const;
	bool isFull() const;
	int getSize() const;
	// Queue Stuff //
	void enqueue(int vertex, int priority);
	QueueNode dequeue();
	QueueNode peek() const;
	// Print //
	void printQueue() const;
};

#endif
