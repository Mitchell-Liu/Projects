#include "Stack.h"

#include <stdexcept>
#include <iostream>

using namespace std;

        // Post:  Stack is created
        Stack::Stack(): size(0){

        }

        // Desc:  Insert element x to the top of the stack.
        //  Pre:  Element inserted must be an integer and the stack is not full
        // Post:  New element is added to the back of the stack
        void Stack:: push(int x){
            if(size == STACKCAP){
                throw std::logic_error("Stack is full");
            }

            for(unsigned int i=size;i>0;i--){
                arr[i] = arr[i-1];
            }
            
            arr[0] = x;
            size++;
        }


        // Desc:  Remove and return element at the top of the stack.
        //  Pre:  Stack is not empty
        // Post:  last element is removed and returned
        int Stack:: pop(){
            if(size == 0){
                throw std::logic_error("Stack is empty");
            }
            int temp = arr[0];

            for(unsigned int i=0;i<size;i++){
                arr[i]=arr[i+1];
            }

            size--;
            return temp;
        }


        // Desc:  Return the topmost element of the stack.
        //  Pre:  Stack is not empty
        // Post:  The last element is returned
        int Stack:: peek() const{
            if(size == 0){
                throw std::logic_error("Stack is empty");
            }
            return arr[0];
        }


        // Desc:  Checks if the stack is empty
        // Post:  Returns true if the stack is empty and returns false otherwise
        bool Stack:: isEmpty() const{
            if(size == 0){
                return true;
            }
            else{
                return false;
            }
        }
