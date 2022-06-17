
#include "Queue.h"
#include <iostream>
using namespace std;

// Desc:  Constructor
Queue::Queue() : size(0), capacity(INITIAL_SIZE), frontindex(0), backindex(0), arr(new int[size]) {
} // constructor


// Desc:  Destructor
Queue::~Queue() {
    delete [] arr;
} // destructor

// Desc:  Copy Constructor
Queue::Queue(const Queue &other) {

    if (this != &other) {
        arr = new int[other.capacity];
        size = other.size;
        capacity = other.capacity;
        frontindex = other.frontindex;
        backindex = other.backindex;

        for (unsigned i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }
} // copy constructor


// Desc:  Assignment operator
Queue & Queue::operator=(const Queue &rhs) {

    if (this != &rhs) {
        size = rhs.size;
        capacity = rhs.capacity;
        frontindex = rhs.frontindex;
        backindex = rhs.backindex;

        for (unsigned i = 0; i < capacity; i++) {
            arr[i] = rhs.arr[i];
        }
    }
    return *this;
} // lhs = rhs


// Desc:  Inserts element x at the back (O(1))
void Queue::enqueue(int x) {
    // resizes the array if capacity is reached
    if(size == capacity){
        // creates a new array with double the capacity of the old array
        int * arr2 = new int[capacity*2];
        int j = frontindex;
        // "straightens" out the array by copying the elements over so that arr[frontindex] = arr2[0]
        for(int i = 0;i<size;i++){
            
            arr2[i] = arr[j];
            j = (j+1) % capacity;
        }
        // sets capacity, deletes the old queue and resets front and back index
        capacity = capacity * 2;
        backindex = size;
        frontindex = 0;
        delete [] arr;
        arr = arr2;
        size++;
        arr[backindex] = x;
        backindex = (backindex + 1)%capacity;
    }
    else{
        size++;
        arr[backindex] = x;
        backindex = (backindex + 1)%capacity;
    }
}

// Desc:  Removes the frontmost element (O(1))
//  Pre:  Queue not empty
void Queue::dequeue() {
    // checks if the queue is empty
    if(size < 1){
        throw std::logic_error("Queue is empty");
    }
    // checks if the queue is less than 1/4 full and cuts the capacity in half if it is
    // but not if cutting capacity in half will be less than the original size
    else if(size<(capacity/4) && (capacity/2)>= INITIAL_SIZE){
        int *arr2 = new int[capacity/2];
        int j = frontindex;
        // "straightens out" the queue and copies over the values from the old array to the new one with half capacity
        for(int i = 0;i<size;i++){
            arr2[i] = arr[j];
            j = (j+1) % capacity;
        }
        // resets frontindex and deletes old queue
        frontindex = 0;
        capacity = capacity/2;
        delete [] arr;
        arr = arr2;
        size--;
        frontindex = (frontindex + 1) % capacity;
    }
    else{
        size--;
        frontindex = (frontindex + 1) % capacity;
    }

} // dequeue

// Desc:  Returns a copy of the frontmost element (O(1))
//  Pre:  Queue not empty
int Queue::peek() const {
    // checks if the queue is empty
    if(size < 1){
        throw std::logic_error("Queue is empty");
    }
    return arr[frontindex];
} // top


// Desc:  Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const {
    return size == 0;
} // isempty




