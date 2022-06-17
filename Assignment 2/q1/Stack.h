


// Desc:  Implementation of an int sequence with push/pop in a LIFO order
class Stack {

    private:

        // Desc:  arr = static array of capacity STACKCAP
        //        size = the number of elements presently in the stack
        //  Inv:  Follows the A2 Spec, namely that the stack elements 
        //        are in order within A[0..size-1], where the top of
        //        the stack is A[0].
        static const unsigned STACKCAP = 8;
        int arr[STACKCAP];
        unsigned size;

    public:

        // Desc:  Object constructor
        // Post:  Stack is created
        Stack();


        // Desc:  Insert element x to the top of the stack.
        //  Pre:Element inserted must be an integer and the stack is not full
        // Post:  New element is added to the back of the stack  
        void push(int x);


        // Desc:  Remove and return element at the top of the stack.
        //  Pre:  Stack is not empty
        // Post:  last element is removed and returned  
        int pop();


        // Desc:  Return the topmost element of the stack.
        //  Pre:  Stack is not empty
        // Post:  The last element is returned  
        int peek() const;


        // Desc:  Checks if the stack is empty
        // Post:  Returns true if the stack is empty and returns false otherwise
        bool isEmpty() const;

};


