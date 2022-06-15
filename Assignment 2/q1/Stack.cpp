
#include "Stack.h"

#include <stdexcept>

        // Post:  
        Stack::Stack(){

        };

        // Desc:  Insert element x to the top of the stack.
        //  Pre:  
        // Post:  
        void Stack:: push(int x){
            arr[STACKCAP-size-1] = x;
            size++;
        }


        // Desc:  Remove and return element at the top of the stack.
        //  Pre:  
        // Post:  
        int Stack:: pop(){
            int temp = arr[STACKCAP-size];
            size--;
            return temp;
        }


        // Desc:  Return the topmost element of the stack.
        //  Pre:  
        // Post:  
        int Stack:: peek() const{
            return arr[size];
        }


        // Desc:  
        // Post:  
        bool Stack:: isEmpty() const{
            if(size == 0){
                return true;
            }
            else{
                return false;
            }
        }
