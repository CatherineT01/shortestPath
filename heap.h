#ifndef HEAP_H
#define HEAP_H

#include<iostream> 
#include<vector>

using namespace std;

struct Node {
    int data;
    Node* next;
};

template <class Type>
class BinaryHeap {
public:
    void push(const Type& value);
    void pop();
    const Type& top() const;
    bool isEmpty() const;
    int getSize() const;

private:
    vector<Type> data;
    int size;
    //may need to be Type

    void sift_up(int s);
    void sift_down(int s);
};

//adds to the vector then sifts up
template <class Type>
void BinaryHeap<Type>::push(const Type& value) {





}

// swaps root wit the last element and removes it then sifts down
template <class Type>
void BinaryHeap<Type>::pop() {


}


//return the root of the heap
template <class Type>
const Type& BinaryHeap<Type>::top() const {



}


//checks if the vector is empty
template <class Type>
bool BinaryHeap<Type>::isEmpty() const {



}


//returns the size of the heap (index of last elemtn in the vector)
template <class Type> 
int BinaryHeap<Type>::getSize() const {



}


template <class Type>
void BinaryHeap<Type>::sift_up(int s) {


}


template <class Type> 
void BinaryHeap<Type>::sift_down(int s) {



}






#endif
