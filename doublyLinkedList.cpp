// Aryan Pratap Singh Arya

// Implementation of Doubly Linked List

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next ;
        Node* previous;

        Node(){
            next=NULL;
            previous=NULL;
        }

        Node(int data){
            this->data=data;
            previous=NULL;
            next=NULL;
        }
};

class doublyLinkedList{
    private:
        Node* head;
        Node* tail;
    public:

        doublyLinkedList(){
            head=NULL;
            tail=NULL;
        }

        void addToHead(int x){

            // if list is empty
            if(head==NULL){
                Node* myNode=new Node(); 
                myNode->data=x;
                head=myNode;
                tail=myNode;
            }

            // if list is not empty
            else{
                Node *myNode=new Node();
                myNode->data=x;
                myNode->next=head;
                head->previous=myNode;
                head=myNode;
            }
        }

        void addToTail(int x){
            // If list is Empty
            if(head==NULL){
                Node *myNode = new Node();
                myNode->data=x;
                head=myNode;
                tail=myNode;
            }

            // If List is not Empty
            else{
                Node *myNode=new Node();
                myNode->data=x;
                tail->next=myNode;
                myNode->previous=tail;
                tail=myNode;
            }
        }

        void deleteFromHead(){
            if(head==tail){
                head=NULL;
                tail=NULL;
            }

            if(head!=NULL){
                head=head->next;
                head->previous=NULL;
            }
            
        }

        void deleteFromTail(){

            if(head==tail){
                head=NULL;
                tail=NULL;
            }
            
            if(tail!=NULL){
                tail=tail->previous;
                tail->next=NULL;
            }
        }

        int insertAtPos(int ele,int pos){
            Node *traverser=head;
            Node *newNode=new Node(ele);

            if(pos==1){
                addToHead(ele);
                return 0;
            }
            else{
                int count=1;
                while(traverser!=NULL){
                    if(traverser==tail){
                        addToTail(ele);
                        break;
                    }
                    else if(count==pos-1){
                        newNode->next=traverser->next;
                        traverser->next=newNode;
                        break;
                    }
                    else{
                        traverser=traverser->next;
                        count++;
                    }                    
                }
            }
            return -1;
        }

        bool search(int data){
            Node* traverser=head;
            while(traverser!=NULL){
                if(traverser->data==data){
                    return true;
                }
                else{
                    traverser=traverser->next;
                }
            }
            return false;
        }

        int deleteFromPos(int pos){
            Node *traverser=head;
            Node *prev;
            if(pos==1){
                deleteFromHead();
            }
            else{
                int count=1;
                while(traverser!=NULL){
                    if(count==pos){
                        if(traverser==tail){
                            deleteFromTail();
                            break;
                        }
                        else{
                            prev->next=traverser->next;
                            traverser->next->previous=prev;
                            delete traverser;
                            break;
                        }
                    }   
                    else{
                        prev=traverser;
                        traverser=traverser->next;
                        count++;
                    }
                }
            }
            return 0;
        }

        int concatenate(doublyLinkedList *list2){
            this->tail->next=list2->head;
            return 0;
        }

        void display(){
            if(head==NULL){
                cout<<"List is Empty";
            }
            else{
                Node *temp=head;
                cout<<"Your List is : " ;
                while(temp!=NULL){
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }
            }
        }
};

int main(){
    doublyLinkedList obj;

    doublyLinkedList obj2;
    obj2.addToHead(25);
    obj2.addToTail(26);
    obj2.addToTail(27);
    obj2.addToTail(28);
    obj2.addToTail(29);
    obj2.addToTail(30);

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
            <<"9. Concatenate list2 into list1.\n"
            <<"10. EXIT"<<endl
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
        
    // concatenate obj2 to obj1;
        case 9:
            obj.concatenate(&obj2);
            obj.display(); ;
            break;
            
        case 10:
            flag=false;
            break;
        }
    }
        
    return 0;
}