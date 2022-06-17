
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
        arr = new int[other.size];
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
// void Queue::enqueue(int x) {
//     if(size == capacity){
//         cout<<"size = "<< size<< " capacity = "<< capacity<<endl;
//         int * arr2 = new int[capacity*2];
//         int j = frontindex;
//         for(int i = 0;i<size;i++){
            
//             arr2[i] = arr[j];
//             cout<<"arr2 = "<<arr2[i]<<" arr = "<<arr[j]<<endl;
//             j = (j+1) % capacity;
//             cout<<"j = "<<j<<endl;
//         }
//         capacity = capacity * 2;
//         backindex=size;
//         delete [] arr;
//         arr = arr2;
//         size++;
//         arr[backindex] = x;
//         backindex = (backindex + 1)%capacity;
//         frontindex = 0;
//         cout<<"new bac = "<<backindex;
//         cout<<"new cap = "<<capacity<<endl;
//     }
//     else{
        
//         size++;
//         arr[backindex] = x;
//         // cout<<"backindex = "<<backindex<<endl;
//         // cout<<"val = "<<arr[backindex]<<endl;
//         backindex = (backindex + 1)%capacity;
//         // cout<<"size = "<<size<<endl;
        
//     }
// } // enqueue

void Queue::enqueue(int x) {
    if(size == capacity){
        cout<<"size = "<< size<< " capacity = "<< capacity<<endl;
        int * arr2 = new int[capacity*2];
        int j = frontindex;
        for(int i = 0;i<size;i++){
            
            arr2[i] = arr[j];
            cout<<"arr2 = "<<arr2[i]<<" arr = "<<arr[j]<<endl;
            j = (j+1) % capacity;
            cout<<"j = "<<j<<endl;
        }
        capacity = capacity * 2;
        backindex=size;
        delete [] arr;
        arr = arr2;
        size++;
        arr[backindex] = x;
        backindex = (backindex + 1)%capacity;
        frontindex = 0;
        cout<<"new bac = "<<backindex;
        cout<<"new cap = "<<capacity<<endl;
    }
    else{
        
        size++;
        arr[backindex] = x;
        // cout<<"backindex = "<<backindex<<endl;
        // cout<<"val = "<<arr[backindex]<<endl;
        backindex = (backindex + 1)%capacity;
        // cout<<"size = "<<size<<endl;
        
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
        cout<<"1"<<endl;
        int *arr2 = new int[capacity/2];
        int j = frontindex;
        // "straightens out" the queue and copies over the values from the old array to the new one with half capacity
        for(int i = 0;i<capacity;i++){
            arr2[i] = arr[j];
            j = (j+1) % capacity;
        }
        cout<<"2"<<endl;
        capacity = capacity/2;
        delete [] arr;
        cout<<"3"<<endl;
        arr = arr2;
        size--;
        cout<<"frountindex = "<<frontindex<<endl;
        frontindex = (frontindex + 1) % capacity;
        cout<<"4"<<endl;
        
    }
    else{
        cout<<"frountindex = "<<frontindex<<" Size = "<<size<<" capacity = "<<capacity<<endl;
        size--;
        frontindex = (frontindex + 1) % capacity;
    }

} // dequeue
void Queue::enqueue(int x) {

    if(size == capacity){
        cout<<"size = "<< size<< " capacity = "<< capacity<<endl;
        int * arr2 = new int[capacity*2];
        int j = frontindex;
        int count = 0;

        for(int i = 0;i<capacity;i++){

            if(i<frontindex){
                cout<<"pos = "<<i<<endl;
                arr2[i] = arr[i];
                cout<<"arr2 = "<<arr2[i]<<endl;
            }

            else{
                
                arr2[(capacity*2)-(capacity-frontindex)+count] = arr[j];
                cout<<"Frontindex = "<<frontindex<<endl;
                cout<<"arr2 pos = "<<(capacity*2)-(capacity-frontindex)+count<<" arr = "<<arr[j]<<endl;
                cout<<"j = "<<j<<endl;
                j++;
                count++;
            }
        }
        
        frontindex = (capacity*2)-(capacity-frontindex);
        capacity = capacity * 2;
        delete [] arr;
        arr = arr2;
        size++;
        arr[backindex] = x;
        backindex = (backindex + 1)%capacity;
        cout<<"new bac = "<<backindex;
        cout<<"new cap = "<<capacity<<endl;
        cout<<"new front = "<<frontindex<<endl;
    }
    else{
        
        size++;
        arr[backindex] = x;
        cout<<"backindex = "<<backindex<<endl;
        cout<<"val = "<<arr[backindex]<<endl;
        backindex = (backindex + 1)%capacity;
        cout<<"size = "<<size<<endl;
        
    }
} // enqueue

// Desc:  Removes the frontmost element (O(1))
//  Pre:  Queue not empty
void Queue::dequeue() {
    if(size < 1){
        throw std::logic_error("Queue is empty");
    }
    else if(size<(capacity/4) && (capacity/4)>= INITIAL_SIZE){
        cout<<"size = "<< size<< " capacity = "<< capacity<<endl;
        int *arr2 = new int[capacity/4];
        int j = frontindex;
        for(int i = 0;i<capacity;i++){
            
            arr2[j] = arr[j];
            j = (j+1) % capacity;
        }
        capacity = capacity/2;
        cout<< "new capacity = "<< capacity<<endl;
        delete [] arr;
        arr = arr2;
        size--;
        frontindex = (frontindex + 1) % capacity;
        cout<<"new front = "<<frontindex;
    }
    else{
        // cout<<"size = "<<size<<endl;
        size--;
        frontindex = (frontindex + 1) % capacity;
        // cout<<"frontindex = "<<frontindex<<endl;

    }

} // dequeue
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
        int count = 0;
        // copies over the old queue by first adding the elements that wraped around, meaning the ones that have indexs less than the front index
        // then copies over the rest of the values by placing them at the end of the queue
        for(int i = 0;i<capacity;i++){
            if(i<frontindex){
                arr2[i] = arr[i];
            }
            // copies over the old queue by first adding the elements that wraped around, meaning the ones that have indexs less than the front index
            // then copies over the rest of the values by placing them at the end of the queue
            else{
                arr2[(capacity-frontindex+count) - (capacity/2)] = arr[j];
                j++;
                count++;
            }
        }
        // sets the new frontindex, deletes the old queue and reasigns the larger one to the old pointer
        frontindex = (capacity-frontindex) - (capacity/2);
        capacity = capacity/2;
        delete [] arr;
        arr = arr2;
        size--;
        frontindex = (frontindex + 1) % capacity;
    }

    else{
        // decrease size and updates frontindex
        size--;
        frontindex = (frontindex + 1) % capacity;
    }

} // dequeue

// Desc:  Returns a copy of the frontmost element (O(1))
//  Pre:  Queue not empty
int Queue::peek() const {
    if(size < 1){
        throw std::logic_error("Queue is empty");
    }
    return arr[frontindex];
} // top


// Desc:  Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const {
    return size == 0;
} // isempty




void Queue::enqueue(int x) {
    if(size == capacity){
        cout<<"size = "<< size<< " capacity = "<< capacity<<endl;
        int * arr2 = new int[capacity*2];
        // int j = frontindex;
        for(int i = 0;i<size;i++){
            backindex++;
            arr2[i] = arr[i];
            // cout<<"arr2 = "<<arr2[i]<<" arr = "<<arr[j]<<endl;

            // cout<<"j = "<<j<<endl;
        }
        arr = arr2;
        capacity = capacity * 2;
        // backindex=size;
        // delete [] arr;
        
        size++;
        arr[backindex] = x;
        backindex = (backindex + 1)%capacity;
        // frontindex = 0;
        cout<<"new bac = "<<backindex;
        cout<<"new cap = "<<capacity<<endl;
    }
    else{
        
        size++;
        arr[backindex] = x;
        // cout<<"backindex = "<<backindex<<endl;
        // cout<<"val = "<<arr[backindex]<<endl;
        backindex = (backindex + 1)%capacity;
        // cout<<"size = "<<size<<endl;
        
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
        cout<<"1"<<endl;
        int *arr2 = new int[capacity/2];
        int j = frontindex;
        // "straightens out" the queue and copies over the values from the old array to the new one with half capacity
        for(int i = 1;i<size;i++){
            // arr2[i] = arr[j];
            // j = (j+1) % capacity;
            arr2[i-1]=arr[i];
        }
        arr = arr2;
        // cout<<"2"<<endl;
        capacity = capacity/2;
        // delete [] arr;
        // cout<<"3"<<endl;
        
        size--;
        // cout<<"frountindex = "<<frontindex<<endl;
        frontindex = (frontindex + 1) % capacity;
        // cout<<"4"<<endl;
        
    }
    else{
        frontindex = (frontindex + 1) % capacity;
        int * arr2 = new int[capacity];
        for(int i = 1;i<size;i++){
            // arr2[i] = arr[j];
            // j = (j+1) % capacity;
            arr2[i-1]=arr[i];
        }
        arr = arr2;
        // cout<<"frountindex = "<<frontindex<<" Size = "<<size<<" capacity = "<<capacity<<endl;
        size--;
        // frontindex = (frontindex + 1) % capacity;
    }

} // dequeue