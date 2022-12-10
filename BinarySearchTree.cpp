// Binary Search Tree Implementation

#include <iostream>
using namespace std;

// template <class T>

class BSTNode{
    public: 
        int element;
        BSTNode *lchild;
        BSTNode *rchild;

        BSTNode(){
            element=-1 ;
            lchild=NULL;
            rchild=NULL;
        }

        BSTNode(int element){
            this->element=element;
            lchild=NULL;
            rchild=NULL;
        }

        ~BSTNode(){
            cout <<"BSTNode executed";
        }
};

class BinarySearchTree{
    
        BSTNode *root=new BSTNode();
        
    public :

    // insert a node in the BST table
        int insert(int data){
            BSTNode *newNode=new BSTNode(data);
            
            if(root->element==-1){
                root=newNode;
            }

            else{
                BSTNode *prev=NULL;
                BSTNode *temp=root;
                while(temp){
                    if(temp->element<data){
                        prev=temp;
                        temp=temp->rchild;
                    }
                    else if(temp->element>data){
                        prev=temp;
                        temp=temp->lchild;
                    }
                }
                if(prev->element<data){
                    prev->rchild=newNode;
                }
                else if (prev->element>data){
                    prev->lchild=newNode;
                }
            }
            
            return 1;
        }

// search in the binary search tree
        BSTNode* search(int data){
            BSTNode *temp=root;
            BSTNode *currentNode=NULL;
            
            while(temp != NULL){
                currentNode=temp;
                if(temp->element==data){
                    return currentNode;
                }
                else if(temp->element<data){
                    temp=currentNode->rchild;
                }
                else if(temp->element>data){
                    temp=currentNode->lchild;
                }
            }
            return NULL;
        }

        
};

int main(){
    BinarySearchTree obj;
    obj.insert(10);
    obj.insert(20);
    obj.insert(8);
    obj.insert(15);
    BSTNode *a;
    a=obj.search(8);
    cout<<a->element;
    return 0;
}