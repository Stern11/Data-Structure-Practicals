// #include "double.cpp"
#include <iostream>
using namespace std;

class deque
{
private:
    Node *front;
    Node *rear;

public:
    deque()
    {
        front = NULL;
        rear = NULL;
    }
    int insertFront(int data)
    {
        Node *temp = new Node(data);
        if (temp == NULL)
        {
            return -1;
        }
        else
        {
            if (front == NULL)
            {
                front = temp;
                rear = temp;
            }
            else
            {
                front->prev = temp;
                temp->next = front;
                front = temp;
            }
            return 1;
        }
    }

    int insertRear(int data)
    {
        Node *temp = new Node(data);
        if (temp == NULL)
        {
            return -1;
        }
        else
        {
            if (rear == NULL)
            {
                front = temp;
                rear = temp;
            }
            else
            {
                temp->prev = rear;
                rear->next = temp;
                rear = temp;
            }
            return 1;
        }
    }

    int deleteFromFront()
    {
        if (front == NULL)
        {
            return -1;
        }

        if (front != NULL)
        {
            Node *temp = front;
            front = front->next;
            if (front == NULL)
            {
                rear = NULL;
                delete temp;
            }
            else
            {
                front->prev = NULL;
                delete temp;
            }
        }
    }

    int deleteFromRear()
    {
        if (rear == NULL)
        {
            return -1;
        }
        else
        {
            Node *temp = rear;
            rear = rear->prev;
            if (rear == NULL)
            {
                front = NULL;
            }
            else
            {
                rear->next = NULL;
            }
            delete temp;
        }
    }
};