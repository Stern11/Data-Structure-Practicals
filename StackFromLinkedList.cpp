// Aryan Pratap Singh Arya

// Implement Stack using Linked list

#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
        T data;
        Node *next;

        Node(T data){
            this->data=data;
            next=NULL;
        }        

        Node(){
            next=NULL;
        }
};

template <class T>
class stack{
    private:
        Node<T> *head;
        
    public:
        stack(){
            head=NULL;
        }

        int push(T data){
            Node<T> *newNode=new Node(data);
            if(head==NULL){
                head=newNode;
                return 0;
            }

            else{
                newNode->next=head;
                head=newNode;
                return 1;
            }
            return -1;
        }

        int pop(){
            if(isEmpty()){
                cout<<"Stack is Empty!!!" <<endl;
                return 0;
            }
            else{
                Node<T> *temp=head;
                cout<<temp->data<<endl;
                head=head->next;
                delete temp;
                return 1;
            }
            return -1;
        }

        T topEl(){
            return this->head->data;
        }

        bool isEmpty(){
            if(head==NULL){
                return true;
            }
            else{
                return false;
            }
        }

        void display(){
            Node<T> * temp=head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            return;
        }
};

int main(){
    stack<int> obj;

    bool flag=true;
    while(flag){
        int choice;
        cout<<"\n\nEnter Your Choice."<<endl;
        cout<<"1. Push.\n"
            <<"2. Pop\n"
            <<"3. TopEl\n"
            <<"4. isEmpty\n"
            <<"5. Display\n"
            <<"6. EXIT"<<endl
            <<"CHOICE : " ;
        cin>>choice;
        int num ;

        switch (choice){
        case 1:
            cout<<"Enter the Number to Push to stack : ";
            cin >> num;
            obj.push(num);
            break;
        case 2:
            cout<<"POP from the stack : ";
            obj.pop();
            break;
        case 3:
            cout<<"TopEl of the stack is : ";
            cout<<obj.topEl()<<endl;
            break;
        case 4:
            cout<<"Is the stack empty : ";
            cout<<obj.isEmpty()<<endl;
            break;
        case 5:
            cout<<"Stack is : ";
            obj.display();
            break;
        case 6:
            flag=false;
            break;
        }
    }
    return 0;
}
