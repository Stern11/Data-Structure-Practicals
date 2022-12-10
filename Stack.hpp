// Stack Implementation

// Aryan Pratap Singh Arya 
// 21513

#define MAX 50
#include <iostream>
using namespace std ;

template<class T>
class Stack{

    private:
        int arr[MAX];
        

    public:

        int tos=-1;
        int push(T x){

                if(!isFull()){
                    tos++;
                    arr[tos]=x;
                    return 0;
                }
                else{
                    exit(-1);
                }
        }

        int pop(){
            if(!isEmpty()){
                tos--;
                return 0;
            }
            else{
                exit(-1);
            }
        }

        T topEl(){
            if(!isEmpty()){
                return arr[tos];
            }
            else{
                return 0;
            }
        }

        bool isEmpty(){
            if(tos==-1){
                return true;
            }
            else{
                return false;
            }
        }

        bool isFull(){
            if(tos==MAX-1){
                return true;
            }
            else{
                return false;
            }
        }  
};

// int main(){

//     int choice ;
//     Stack obj;
//     char ch ;

//     while (true){
//         cout<<"1) Push an Element."<< endl 
//         <<"2) Pop an Element."<<endl
//         <<"3) Print Top element of the Stack." << endl ; 
        
//         cout<<"Enter Your Choice : " ;
//         cin>> choice ;
//         switch (choice)
//         {
//         case 1:
//             int x;
//             cout<<"Enter the element to push: " ;
//             cin >> x ; 
//             obj.push(x);      
//             break;
            
//         case 2:
//             obj.pop();
//             break;

//         case 3:
//             cout <<"top Element of Stack is : " << obj.topEl() <<endl;
//             break ;
//     }
//         cout<<"\nEnter Y to continue : " ;
//         cin >> ch ;
//         if (ch=='Y' || ch=='y'){
//             continue ;
//         }
//         else {
//             break ;
//         }
//     }    
//     return 0;
// }
    



