// Aryan Pratap Singh Arya
// Implementataion of Circular Linked List

#include<iostream>
using namespace std;

template <class T>
class Node{
    public:
        T data;
        Node* next;
        // Node* previous;

        Node(){
            next=NULL;
            // previous=NULL;
        }  
        
        Node (T data){
            this->data=data;
            next=NULL;
            // previous=NULL;
        }        
};

template <class T>
class circularLinkedList{
        private : 
            Node<T> *head;
            Node<T> *tail;

    public:
        circularLinkedList(){
            head=NULL;
            tail=NULL;
        }

        int addToHead(T data){
            Node<T> *newNode=new Node(data);
            if(head==NULL){
                head=newNode;
                tail=head;
                return 0;
            }
            else if(head==tail){
                newNode->next=head;
                head=newNode;
                tail=newNode->next;
                tail->next=head;
                return 2;
            }
            else{
                newNode->next=head;
                head=newNode;
                tail->next=head;
                return 1;
            }
            return -1;
        }

        int addToTail(T data){
            Node <T> *newNode=new Node(data);
            if(tail==NULL){
                addToHead(data);
                return 0;
            }
        
            else{
                tail->next=newNode;
                newNode->next=head;
                tail=newNode;
                return 2;
            }
            return -1;
        }

        int deleteFromHead(){
            if(head==tail){
                Node<T>*temp=head;
                head=NULL;
                tail=NULL;
                delete temp;
            }
            
            else{
                Node <int> *temp=head;
                head=head->next;
                tail->next=head;
                delete temp;
                return 0;
            }
            return -1;           
        }

        int deleteFromTail(){
            Node<int> *temp=head;
            if(tail==NULL){
                cout<<"No Element to Delete !!" <<endl;
                return 0;
            }
            else if(head==tail){
                head=NULL;
                tail=NULL;
                delete temp;
                return 1;
            }
            else{
                while(temp->next!=tail){
                    temp=temp->next;
                }
                Node <int> *grbg=temp->next;
                temp->next=head;
                tail=temp;
                delete grbg;
                return 2;
            }
            return -1;
        }

        bool search(int data){
            if(head==NULL){
                cout<<"List is Empty !!";
                return false;
            }
            else{
                Node <T> *traverser=head;
                do{
                    if(traverser->data==data){
                        return true;
                    }
                    else{
                        traverser=traverser->next;
                    }
                }while(traverser!=head);
            }
            return false;
        }

        int insertAtPos(int data,int pos){
            if(pos==1){
                addToHead(data);
                return 0;
            }
            else{
                Node<T> *newNode=new Node(data);
                Node <T> *traverser=head;
                int count=1;
                while (count!=pos-1){
                    traverser=traverser->next;
                    count++;
                }
                newNode->next=traverser->next;
                traverser->next=newNode;

                return 1;
            }
            return -1;
        }

        int deleteFromPos(int pos){
            if(pos==1){
                deleteFromHead();
                return 0;
            }
            else{
                Node<int> *previous;
                Node<int> *traverser=head;
                int count=0;
                while(count!=pos-1){
                    previous=traverser;
                    traverser=traverser->next;
                    count++;
                }
                if(traverser==tail){
                    deleteFromTail();
                    return 1;
                }
                else{
                    previous->next=traverser->next;
                    delete traverser;
                    return 2;
                }
            }
            return -1;
        }

        int concatenate(circularLinkedList* A){
            this->tail->next=A->head;
            A->tail->next=this->head;
            return 0;
        }

        void display(){
            Node<T> *traverser=head;
            if(head==NULL){
                cout<<"List is Empty!!!"<<endl;
                return;
            }
            else{
                do{
                    cout<<traverser->data<<" " ;
                    traverser=traverser->next;
                }
                while(traverser!=head and traverser!=NULL);
            }
        }
};

int main(){
    circularLinkedList <int> obj;

    circularLinkedList<int> obj2;
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
            <<"9. EXIT"<<endl
            <<"CHOICE : " ;
        cin>>choice;
        int num ;

        switch (choice){
        case 1:
            cout<<"Enter the Number to Add to beginnig to list : ";
            cin >> num;
            cout<<obj.addToHead(num)<<endl;
            break;
        
        case 2:
            cout<<"Enter the Number to add to end of list : ";
            cin >> num;
            obj.addToTail(num);
            break;
        
        case 3:
            cout<<obj.deleteFromHead()<<endl;
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
    obj.concatenate(&obj2);
    obj.display(); 
    return 0;
}