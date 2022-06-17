
// #include "Queue.h"
// #include <iostream>
// using namespace std;


// int main () {
//     Queue Q;

//     // enqueue 1, 2, 3, 4, 5
//     for (int i = 1; i <= 5; i++) {
//         Q.enqueue(i);
//         cout << "enqueue " << i << endl;
//     }
//     Queue T(Q);
//     for (int i = 0; i < 1; i++) {
//         int y = T.peek();
//         T.dequeue();
//         cout << "T peek " << y << endl;
//     }
//     for (int i = 6; i <= 10; i++) {
//         T.enqueue(i);
//         cout << "T enqueue " << i << endl;
//     }
//     // dequeue 2x elements
//     for (int i = 0; i < 2; i++) {
//         int y = Q.peek();
//         Q.dequeue();
//         cout << "peek " << y << endl;
//     }


//     // enqueue 6, 7, 8, 9, 10
//     for (int i = 6; i <= 10; i++) {
//         Q.enqueue(i);
//         cout << "enqueue " << i << endl;
//     }

//     while (!T.isEmpty()) {
//         int y = T.peek();
//         T.dequeue();
//         cout << "T top " << y << endl;
//     }
//     // dequeue all elements
//     while (!Q.isEmpty()) {
//         int y = Q.peek();
//         Q.dequeue();
//         cout << "top " << y << endl;
//     }
//     cout << endl;


//     return 0;
// }

#include "Queue.h"
#include <iostream>
using namespace std;


int main () {
    Queue Q;

    // enqueue 1, 2, 3, 4, 5
    for (int i = 1; i <= 50; i++) {
        Q.enqueue(i);
        cout << "enqueue " << i << endl;
    }


    // dequeue 2x elements
    for (int i = 0; i < 2; i++) {
        int y = Q.peek();
        Q.dequeue();
        cout << "peek " << y << endl;
    }


    // enqueue 6, 7, 8, 9, 10
    for (int i = 6; i <= 10; i++) {
        Q.enqueue(i);
        cout << "enqueue " << i << endl;
    }

    
    cout<<"Print"<<endl;
    for(int i = 0; i<60; i++){
        cout<<Q.arr[i]<<endl;
    }
    // dequeue all elements
    while (!Q.isEmpty()) {
    
        int y = Q.peek();
        Q.dequeue();
        cout << "top " << y << endl;
    }
    cout << endl;


    return 0;
}


