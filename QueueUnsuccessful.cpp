// Queue Implementation

#include <iostream>
using namespace std ;

#define show true 
#define len 5 

template <class T> 
class Queue{

    private :
        int front ;
        int back ;
        bool flag ;
        
        T *arr; 

    public : 
        Queue(){
            front=0;
            back=0;
            flag= false ;
            arr = new T [len];     
        }

        int enqueue(T x){
            cout<<isFull()<<" ";
            if(!isFull()){
                arr[back++]=x;
                return 0;
            }

            else if (flag){
                back=-1;
                arr[back]=x;
                flag=false;
                return 0;
            }

            else{
                cout << "Queue is filled" ;
                exit(-1);
            }
        }

        void dequeue(){
            if(isFull()){
                flag=true;
            }

            if(front == (len-1) && flag){
                front=0 ;
            }

            if(!isEmpty()){
                front++;
            }

        }

        T topEl(){
            if(!isEmpty()){
                return arr[front];
            }
            else{
                exit(-1);
            }
        }

        bool isEmpty(){
            
            if(front==(len-1) && back==-1){
                return true ;
            }
            else
                return false;
        }
        

        bool isFull(){
                    if( back==front-1 || front==len-1){
                        return true;
                    }
                    
                    
                else{
                    return false;
                }
                
        }
            


        

        void display(){
            for(int i=0 ; i<5 ; i++){
                cout << arr[i] <<" " ;
            } 
            cout<<endl ; 
        }


};

int main(){
    Queue <int> obj ;

    int x,y ;
    char ch ;
    cout<<"Note Size of array for Queue is : " << 5 <<endl ;

    while(true){
        cout <<"Enter your choice : " <<endl ;
        cout <<"1: Enqueue\n" <<
                "2: Dequeue\n" <<
                "3: TopElement\n" <<
                "4: Exit" <<endl ;

                if(show){
                    obj.display();
                }

        cin>> x ;

            switch (x){
                case 1:
                    cout<<"Enter element to enter into queue : " ;
                    cin>>y ;
                    obj.enqueue(y);
                    break;
                
                case 2:
                    obj.dequeue();
                    break;
                
                case 3:
                    cout<<"Top Elemnt of Queue is : " << obj.topEl()<<endl;
                    break;

                case 4:
                    break;
            }

            if(x==4){
                break;
            } 
    }
    return 0 ;
}
