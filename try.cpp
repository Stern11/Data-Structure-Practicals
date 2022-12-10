#include <iostream>
using namespace std;

class Node{
    public :
        Node * next;
        int data;
        Node(int data){
            this->data=data;
            next=NULL;
        }
        Node(){
            next=NULL;
        }
};

class SLL{
    public :
        Node * head=NULL ;

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

        int deleteFromHead(){
            if(head==NULL){
                cout<<"No element in linked list.";
                return -1;
            }
            else{
                Node* temp=head;
                head=head->next;
                delete temp;
            }
            return 0;
        }

        int deleteFromTail(){
            if(head==NULL){
                cout<<"List is Empty";
                return -1;
            }

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
                        return 1; 
                    }
                    else{
                        count++;
                        prev=traverser;
                        traverser=traverser->next;
                    }
                }
            }
            return 2;
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
     SLL obj;
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
            cout<<"Found at position : " << obj.search(ele)<<endl;
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
        
        // case 9:
        //     flag=false;
        //     break;
        }
    }   
    return 0;
}