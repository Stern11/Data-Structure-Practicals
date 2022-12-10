// Aryan Pratap Singh Arya
// Implement Queue using Linked List.

#include <iostream>
using namespace std;

template<class T>
class Node{
    public:
        T data;
        Node* next;

        Node(T data){
            this->data=data;
            next=NULL;
        }

        Node(){
            this->next=NULL;
        }
};

template <class T>
class Queue{
    private:
        Node<T> *head;
        Node<T> *tail;
        
    public:

        Queue(){
            head=NULL;
            tail=NULL;
        }

        int enqueue(T data){
            Node<T> *newNode=new Node(data);
            if(tail==NULL){
                tail=newNode;
                head=tail;
                return 0;
            }
            else{
                tail->next=newNode;
                newNode->next=head;
                tail=newNode;
                return 1;
            }
            return -1;
        }

        int dequeue(){
            if(this->isEmpty()){
                cout<<"Queue is Empty !!!"<<endl;
                return 0;
            }
            else if(head==tail){
                head=NULL;
                tail=NULL;
                return 1;
            }
            else{
                Node<int> *temp;
                temp=head;
                cout<<head->data;
                tail->next=head->next;
                head=head->next;
                delete temp;
                return 2;
            }
            return -1;
        }

        bool isEmpty(){
            if(head==NULL and tail==NULL){
                return true;
            }
            else{
                return false;
            }
        }

        void display(){
            if(isEmpty()){
                cout<<"Queue is Empty !!!"<<endl;
                return;
            }
            else{
                Node<int> *traverser=head;
                do{
                    cout<<traverser->data<<" " ;
                    traverser=traverser->next;
                }while(traverser!=head and traverser!=NULL);
                return ;
            }
        }
};

int main(){

    Queue<int> obj;

    bool flag=true;
    while(flag){
        int choice;
        cout<<"\n\nEnter Your Choice."<<endl;
        cout<<"1. Enqueue.\n"
            <<"2. Dequeue\n"
            <<"3. isEmpty\n"
            <<"4. Display\n"
            <<"5. EXIT"<<endl
            <<"CHOICE : " ;
        cin>>choice;
        int num ;

        switch (choice){
        case 1:
            cout<<"Enter the Number to enqueue to Queue : ";
            cin >> num;
            obj.enqueue(num);
            break;
        case 2:
            cout<<"POP from the stack : ";
            obj.dequeue();
            break;
        case 3:
            cout<<"Is the stack empty : ";
            cout<<obj.isEmpty()<<endl;
            break;
        case 4:
            cout<<"Queue is : ";
            obj.display();
            break;
        case 5:
            flag=false;
            break;
        }
    }

    return 0;
}

