#include <iostream>
using namespace std;

class Node{

    public :
        int data ;
        Node *next;

        Node(){
            this->next=NULL ;
        }
};

class SortedLinkedList{

    private:
        Node *head;
        Node *tail;
    public:
        SortedLinkedList(){
            head=NULL ;
            tail=NULL;
        }

        void add(int x){
                Node *myNode=new Node();
                myNode->data=x;
    
            // If there is no element in the linked list
            if(head==NULL && tail==NULL){
                myNode->next=NULL;
                head=myNode;
                tail=head;
            }

            // If there is only one element in the linked list
            else if(tail==head ){
                if(head->data < myNode->data){
                    myNode->next=NULL;
                    head->next=myNode;
                    tail=myNode;
                }
                else{
                    myNode->next=head;
                    Node *temp=head;
                    head=myNode;
                    tail=temp;
                }
            }

            // If there are elements in the Linked List
            else{
                Node* current=head;

                Node* Nextcurrent=current->next;
                
                while(Nextcurrent == tail ){                   
                    if(Nextcurrent->data>myNode->data){
                        Node *temp=new Node();
                        temp=Nextcurrent;
                        current->next=myNode;
                        myNode->next=temp;
                        return;
                    }

                    else if(Nextcurrent->data < myNode->data){
                        myNode->next=Nextcurrent;
                        current->next=myNode;
                        return;
                    }
                    
                    else{
                        current->next=Nextcurrent;
                    }
                }                
            }
        }
    

        void display(){
            if(head==NULL){
                cout<<"List is Empty "<< endl;
            }
            else{
                Node *temp=head;
                while(temp!=NULL){
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }
            }
        }       
};


int main(){
    SortedLinkedList obj;
    bool flag=true;
    while(flag){
        int choice;
        cout<<"\n\nEnter Your Choice."<<endl;
        cout<<"1. Add a Number to list.\n"
            <<"2. Display the DoublyLinked List\n"
            <<"3. EXIT"<<endl
            <<"CHOICE : " ;
        cin>>choice;
        int num ;

        switch (choice){
        case 1:
            cout<<"Enter the Number to Add to beginnig to list : ";
            cin >> num;
            obj.add(num);
            break;
        
        case 2:
            obj.display();
            break;
        
        case 3:
            flag=false;
            break;
        }
    }   
    return 0;
}