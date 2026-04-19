#include "Queue.h"

// ----------------------------------------------------------- //
// Author: AJ Freeman                                          //
// Date: 4/17/2026                                             //
// Name: Queue()                                               //
// Description: Default constructor for the Queue class.       //
// Incoming: None                                              //
// Outgoing: size = 0                                          //
// Return Type: None                                           //
// References: size data member                                //
// ----------------------------------------------------------- //
Queue::Queue() :size(0) {}

// ----------------------------------------------------------- //
// Author: AJ Freeman                                          //
// Date: 4/17/2026                                             //
// Name: isEmpty()const                                        //
// Description: Determines whether the priority queue contains //
// any elements. Returns true if the queue size is 0.          //
// Incoming: None                                              //
// Outgoing: true if queue is empty, false otherwise           //
// Return Type: bool                                           //
// References: size data member                                //
// ----------------------------------------------------------- //
bool Queue::isEmpty() const{
	return size == 0;
}

// ----------------------------------------------------------- //
// Author: AJ Freeman                                          //
// Date: 4/17/2026                                             //
// Name: bool isFull()const                                    //
// Description: Determines whether the priority queue has      //
// reached its maximum allowed capacity.                       //
// Incoming: None                                              //
// Outgoing: true if queue is full (false otherwise)           //
// Return Type: bool                                           //
// References: size data member and MAX_QUEUE constant         //
// ----------------------------------------------------------- //
bool Queue::isFull() const{
	return size == MAX_QUEUE;
}

// ----------------------------------------------------------- //
// Author: AJ Freeman                                          //
// Date: 4/17/2026                                             //
// Name: int getSize() const                                   //
// Description: Returns the current number of elements stored  //
// in the priority queue.                                      //
// Incoming: none                                              //
// Outgoing: current size of queue                             //
// Return Type: int                                            //
// References: size data member                                //
// ----------------------------------------------------------- //
int Queue::getSize() const{
	return size;
}

// ----------------------------------------------------------- //
// Author: AJ Freeman                                          //
// Date: 4/17/2026                                             //
// Name: swap(int index1, int index2)                          //
// Description: Swaps the positions of two nodes in the heap   //
// array. Used by heapifyUp and heapifyDown to maintain the    //
// min-heap property of the priority queue.                    //
// Incoming: int i1, int i2                                    //
// Outgoing: contents of heap[index1] and heap[index2] swapped //
// Return Type: void                                           //
// References: heap array and QueueNode struct                 //
// ----------------------------------------------------------- //
void Queue::swap(int i1, int i2){
	QueueNode temp = heap[i1];
	heap[i1] = heap[i2];
	heap[i2] = temp;
}

// ----------------------------------------------------------- //
// Author: AJ Freeman                                          //
// Date: 4/17/2026                                             //
// Name: heapifyUp(int index)                                  //
// Description: Moves a newly inserted node upward through the //
// heap until the min-heap property is restored. A node with   //
// a smaller priority value rises above larger priority values //
// so the minimum element stays at the root.                   //
// Incoming: int index                                         //
// Outgoing: heap reordered upward as needed                   //
// Return Type: void                                           //
// References: swap(), heap array, and QueueNode struct        //
// ----------------------------------------------------------- //
void Queue::heapifyUp(int index){
	int parent;
	while (index > 0){
		parent = (index - 1) / 2;
		if (heap[index].priority < heap[parent].priority) {
			swap(index, parent);
			index = parent;
		}
		else
			break;
	}
}

// ----------------------------------------------------------- //
// Author: AJ Freeman                                          //
// Date: 4/17/2026                                             //
// Name: heapifyDown(int index)                                //
// Description: Moves a node downward through the heap until   //
// the min-heap property is restored. This is used after       //
// removing the root node and replacing it with the last node. //
// Incoming: int index                                         //
// Outgoing: heap reordered downward as needed                 //
// Return Type: void                                           //
// References: swap(), heap array, and QueueNode struct        //
// ----------------------------------------------------------- //

void Queue::heapifyDown(int index)
{
	int left;
	int right;
	int smallest;

	while (true)
	{
		left = 2 * index + 1;
		right = 2 * index + 2;
		smallest = index;
		if (left < size && heap[left].priority < heap[smallest].priority){
			smallest = left;
		}

		if (right < size && heap[right].priority < heap[smallest].priority){
			smallest = right;
		}

		if (smallest != index){
			swap(index, smallest);
			index = smallest;
		}

		else
			break;
	}
}

// ----------------------------------------------------------- //
// Author: AJ Freeman                                          //
// Date: 4/17/2026                                             //
// Name: enqueue(int vertex, int priority)                     //
// Description: Inserts a new vertex and its priority value    //
// into the priority queue. The new node is placed at the end  //
// of the heap, then moved upward to preserve heap order.      //
// Incoming: int vertex, int priority                          //
// Outgoing: new QueueNode added to heap if queue not full     //
// Return Type: void                                           //
// References: isFull(), heapifyUp(), and heap array           //
// ----------------------------------------------------------- //
void Queue::enqueue(string vertex, int priority){
	if (isFull()){
		cout << "Queue is full!" << endl;
		return;
	}
	heap[size].vertex = vertex;
	heap[size].priority = priority;
	size++;
	heapifyUp(size - 1);
}

// ----------------------------------------------------------- //
// Author: AJ Freeman                                          //
// Date: 4/17/2026                                             //
// Name: QueueNode dequeue()                                   //
// Description: Removes and returns the node with the smallest //
// priority value, which is stored at the root of the min-     //
// heap. After removal, the last node is moved to the root and //
// pushed downward to restore heap order.                      //
// Incoming: none                                              //
// Outgoing: root node removed from queue and returned         //
// Return Type: QueueNode                                      //
// References: isEmpty(), heapifyDown(), and heap array        //
// ----------------------------------------------------------- //
QueueNode Queue::dequeue() {

	QueueNode removedNode;
	removedNode.vertex = "- 1";
	removedNode.priority = -1;

	if (isEmpty()) {
		cout << "Queue is empty!" << endl;
		return removedNode;
	}

	QueueNode minNode = heap[0];
	heap[0] = heap[size - 1];
	size--;

	if (!isEmpty()) {
		heapifyDown(0);
	}

	return minNode;
}

// ----------------------------------------------------------- //
// Author: AJ Freeman                                          //
// Date: 4/17/2026                                             //
// Name: QueueNode peek() const                                //
// Description: Returns the node with the smallest priority    //
// without removing it from the queue. If the queue is empty,  //
// a default invalid node is returned instead.                 //
// Incoming: none                                              //
// Outgoing: root node of heap returned without deletion       //
// Return Type: QueueNode                                      //
// References: isEmpty() and heap array                        //
// ----------------------------------------------------------- //
QueueNode Queue::peek() const {

	QueueNode removedNode;
	removedNode.vertex = -1;
	removedNode.priority = -1;

	if (isEmpty()) {
		cout << "Queue is empty!" << endl;
		return removedNode;
	}

	return heap[0];
}

// ----------------------------------------------------------- //
// Author: AJ Freeman                                          //
// Date: 4/17/2026                                             //
// Name: printQueue() const                                    //
// Description: Displays the contents of the priority queue in //
// its current heap order for testing and debugging purposes.  //
// Each line shows the vertex and its associated priority.     //
// Incoming: none                                              //
// Outgoing: printed queue contents to console                 //
// Return Type: void                                           //
// References: heap array and size                             //
// ----------------------------------------------------------- //
void Queue::printQueue() const {
	cout << "Queue contents (vertex, priority):" << endl;
	for (int i = 0; i < size; i++) {
		cout << "Vertex: " << heap[i].vertex
			<< ", Priority: " << heap[i].priority << endl;
	}
}