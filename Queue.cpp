// // Aryan Pratap Singh Arya

// // Implementation of Queue using Circular array.

// #include<iostream>
// using namespace std;

// #define len 5
// #define show true

// template <class T>
// class Queue{
    
//     private:
//         T *arr ;
//         int front ;
//         int rear ;

//     public:
//         Queue{
//             front=-1;
//             rear=-1;
//             arr=new T [len];
//         }

//         int enqueue(T x){
//             if(front==-1 || rear==-1){
//                 front++;
//                 rear++;
//                 arr[rear]=x;
//                 return 0;
//             }

//             else if(!isfull()){
//                 rear++;
//                 arr[rear]=x ;
//                 return 0;
//             }
//             else{
//                 cout<<"Queue is already full."<<endl ;
//                 exit("Queue Full");
//             }
//         }

//         int dequeue(){
//             if(!isEmpty()){
//                 front++ ;
            
//                 return 0;
//             }
//             else{
//                 cout<<"Queue is Empty."<<endl ;
//                 exit("Queue empty")
//             }
//         }

//         T topElement(){
//             if(!isEmpty()){
//                 return arr[front];
//             }
//             else{
//                 return{
//                     exit("No front Element");
//                 }
//             }
//         }

//         bool isFull(){
            
//         }

//         bool isEmpty(){
            
//         }


// };

#include <iostream>
using namespace std;

template <typename T>
class Queue
{
public:
    T *arr;
    int length;
    int rear;
    int front;

    void setQueueLength(int a)
    {
        arr = new T[a];
        length = a;
        rear = -1;
        front = -1;
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isfull()
    {
        if (rear == length - 1 && front == 0 || rear == front - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int enqueue(T a)
    {
        if (!isfull())
        {
            if (front == -1)
            {
                front = 0;
                // rear = -1;
            }

            if (rear == length - 1)
            {
                rear = -1;
            }
            arr[++rear] = a;
            return 0;
        }
        else
        {
            return 1;
        }
    }

    T dequeue(){
        if (!isEmpty()){
            int c = arr[front];

            if (front == rear){
                front = -1;
                rear = -1;
            }
            else{
                if (front == length - 1){
                    front = 0;
                }

                else{
                    front++;
                }
            }
            return c;
        }
        else
        {
            return -1;
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements are :\n";
        if (front <= rear)
        {
            while (front <= rear)
            {
                cout << arr[front] << " ";
                front++;
            }
        }
        else
        {
            while (front <= length - 1)
            {
                cout << arr[front] << " ";
                front++;
            }
            front = 0;
            while (front <= rear)
            {
                cout << arr[front] << " ";
                front++;
            }
        }
        cout << endl;
    }
};

int main()
{
    int choice;
    char ch;

    Queue<int> obj;
    int len;
    cout << "Enter the length of the Queue : " << endl;
    cin >> len;
    obj.setQueueLength(len);
    while (true)
    {
        cout << "Enter Choice\n1)Enqueue an element\n2)Dequeue an element\n3)Display Queue\n"
             << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int a;
            cout << "Enter the element you want to enqueue" << endl;
            cin >> a;
            int b;
            b = obj.enqueue(a);
            if (b == 0)
            {
                cout << "Element Enqueued....." << endl;
            }
            else
            {
                cout << "Queue Overflow....Element not Enqueued" << endl;
            }
            break;
        case 2:
            int c;
            c = obj.dequeue();
            if (c == -1)
            {
                cout << "Queue Underflow....Element not Dequeued" << endl;
            }
            else
            {
                cout << "Element Dequeued is : " << c << endl;
            }
            break;
        case 3:

            obj.display();
            cout << endl;
            break;
        }
        cout << "Press Y to continue" << endl;
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            continue;
        }
        else
        {
            cout << "Exited...";
            break;
        }
    }
    return 0;
}
