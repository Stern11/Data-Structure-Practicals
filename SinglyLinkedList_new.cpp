// Singly Linked list

// Aryan Pratap Singh Arya

#include <iostream>
using namespace std;

class Node{
    public: 
        int  data ;
        Node * next;

        Node(){
            data=-1;
            next=NULL;
        }

        Node(int  data){
            this->data=data;
            next=NULL;
        }
};

class SinglyLinkedList{
    public:
        Node* head;

        SinglyLinkedList(){
            head=NULL;
        }

        int addToHead(int data){
            Node *newNode=new Node(data);
            if(head==NULL){
                head=newNode;
            }
            else{
                newNode->next=head;
                head=newNode;
            }

            return 0;
        }

        int addToTail(int data){
            Node *newNode=new Node(data);
            Node *temp=head;

            if(head==NULL){
                addToHead(data);
            }
            else{
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=newNode;
            }
            return 0;
        }

        int deleteFromHead(){
            Node* grbCollection;

            if(head==NULL){
                return -1;
            }
            else{
                grbCollection=head;
                head=head->next;
                delete grbCollection;
            }
            return 0;
        }

        int deleteFromTail(){
            if(head==NULL){
                cout<<"List is Empty";
                return -1;
            }
            // Only one element in the list
            else if(head->next==NULL){
                deleteFromHead();
            }
            else{
                Node *traverser=head;
                Node* temp;

                while(traverser->next->next!=NULL){
                    traverser=traverser->next;
                }
                temp=traverser->next;
                traverser->next=NULL;
                delete temp;
            }
            return 0;
        }

        bool search(int ele){
            Node* traverser=head;
            while(traverser!=NULL){
                if(traverser->data==ele){
                    return true;
                }
                else{
                    traverser=traverser->next;
                }
            }
            return false;
        }

        int insertAtPos(int ele , int pos){
            Node *traverser=head;
            if(pos==1){
                addToHead(ele);
                return 1;
            }
            else{
                int count=1;
                Node *prev =head;
                Node *newNode=new Node(ele);
                while(traverser!=NULL){
                    if(count==pos){
                        prev->next=newNode;
                        newNode->next=traverser;
                        break;
                        return 2;
                    }
                    else{
                        count++;
                        prev=traverser;
                        traverser=traverser->next;
                    }
                }
            }
            return 0;
        }

        int deleteFromPos(int pos){
            Node* traverser=head;
            if(pos==1){
                deleteFromHead();
                return 0;
            }
            else{
                Node* prev=head;
                int count=1;
                while(traverser!=NULL){
                    if(count==pos){
                        prev->next=traverser->next;
                        delete traverser;
                        break;
                        return 0; 
                    }
                    else{
                        count++;
                        prev=traverser;
                        traverser=traverser->next;
                    }
                }
            }
            return -1;
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

        int concatenateSLL(SinglyLinkedList* l2){
            Node* temp=this->head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=l2->head;
            return 0;
        }

    ~SinglyLinkedList(){
        cout<<"\nMemory Cleaned\n";
    }

};

int main(){

    SinglyLinkedList obj;
    SinglyLinkedList obj2;

    obj2.addToTail(6);
    obj2.addToTail(7);
    obj2.addToTail(8);
    obj2.addToTail(9);
    obj2.addToTail(10);

    bool flag=true;
    while(flag){
        int choice;
        cout<<"\n\nEnter Your Choice."<<endl;
        cout<<"1. Add a Number to beginning.\n"
            <<"2. Add a number to tail\n"
            <<"3. Delete an Element from head\n"
            <<"4. Delete an Element from Tail\n"
            <<"5. Display the SinglyLinked List\n"
            <<"6. Search an Element in List\n"
            <<"7. Add an element at any given position.\n"
            <<"8. Delete a Node from any given position.\n"
            <<"9. EXIT"<<endl
            <<"CHOICE : " ;
        cin>>choice;
        int num ;

        switch (choice){
        case 1:
            cout<<"Enter the Number to Add to beginnig to list : ";
            cin >> num;
            obj.addToHead(num);
            break;
        
        case 2:
            cout<<"Enter the Number to add to end of list : ";
            cin >> num;
            obj.addToTail(num);
            break;
        
        case 3:
            obj.deleteFromHead();
            cout<<"Deleted";
            break;
        
        case 4:
            obj.deleteFromTail();
            cout<<"Deleted";
            break;
        
        case 5:
            obj.display();
            break;

        case 6:
            int ele;
            int foundAt;
            cout<<"Enter the element to search in the list : " ;
            cin >> ele;
            cout<<"Found {1 resembles True} : " << obj.search(ele)<<endl;
            break;

        case 7:
            int pos,data;
            cout<<"Enter the position to add a NODE into the list : " ;
            cin >> pos;
            cout<<"Enter the data of the list : ";
            cin >> data;
            obj.insertAtPos(data,pos);
            break; 

        case 8:
            int delPos;
            cout<<"Enter the position to delete an NODE from the list : " ;
            cin >> delPos;
            obj.deleteFromPos(delPos);
            break;
        
        case 9:
            flag=false;
            break;
        }
    } 

    obj.concatenateSLL(&obj2);

    obj.display();  

    return 0;
}