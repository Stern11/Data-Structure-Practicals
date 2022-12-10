#include <iostream>
using namespace std;

// template <class T>
class Node{

    public :
        int data ;
        Node *next;

        Node(){
            this->next=NULL ;
        }
        Node(int data){
            this->data=data;
        }
};

// template <class T>
class SinglyLinkedList{

    private:
        Node *head;
        int size;
    public:
        SinglyLinkedList(){
            head=NULL ;
            size=0;
        }

// **********************
        int addToBeginning(int x){
            Node *my_Node=new Node();
                my_Node->data=x;
                my_Node->next=head;
                head=my_Node;
                size++;
            return 0;
        }
// **********************
        int addToList(int data,int pos){
            int count=1;
            Node *newNode=new Node(data);
            Node *temp=head;
            while(temp->next!=NULL){
                count++;
                temp=temp->next;
                if(count==pos){
                    newNode->next=temp->next;
                    temp->next=newNode;
                }
            }
            size++;
            return 0;
        }
// *********************
        int addToTail(int data){
            Node *newNode=new Node(data);
            Node *temp=head;
            while(head!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
            size++;
            return 0;
        }
// *********************
        int removeFromList(int pos){
            Node *temp=head;
            Node* prev=NULL;
            int count=0;

            for(int i=0 ; i<pos ; i++){
                if(i==pos-1){
                    prev->next=temp->next;
                    temp=prev;
                    break;
                }
                else{
                    prev=temp;
                    temp=temp->next;
                }
            }
            size--;
            return 0;
        }
// **********************
        void removeFromBeginning(){
            head=head->next;
            size--;            
        }
// *********************
        int removeFromTail(){
            Node *temp=head;
            Node *prev;
            while(temp!=NULL){
                prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
            size--;
            return 0;
        }
// ********************
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
// *********************
        int search(int x){
            Node *temp=head;
            // Node *prev;
            for(int i=0 ; i<size ; i++){
                if(temp->data==x){
                    return i;
                }
                else{
                    temp=temp->next;
                }
            }
            return -1;
        }

        
        
};



int main(){

    SinglyLinkedList obj;
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
            obj.addToBeginning(num);
            break;
        
        case 2:
            cout<<"Enter the Number to add to end of list : ";
            cin >> num;
            obj.addToTail(num);
            break;
        
        case 3:
            obj.removeFromBeginning();
            cout<<"Deleted";
            break;
        
        case 4:
            obj.removeFromTail();
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
            Node* temp;
            foundAt=obj.search(ele);
            cout<<"Found at position : " << foundAt<<endl;
            break;

        case 7:
            int pos,data;
            cout<<"Enter the position to add a NODE into the list : " ;
            cin >> pos;
            cout<<"Enter the data of the list : ";
            cin >> data;
            obj.addToList(data,pos);
            break;

        case 8:
            int delPos;
            cout<<"Enter the position to delete an NODE from the list : " ;
            cin >> delPos;
            obj.removeFromList(delPos);
            break;
        
        case 9:
            flag=false;
            break;
        }
    }   

    return 0;
}