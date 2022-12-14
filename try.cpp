#include <iostream>
using namespace std;

class max_heap{
    public:
        int arrSize;
        int size=0;
        int *arr;

        max_heap(int n){
            this->arrSize=n;
            arr=new int(arrSize);
        }

        bool isEmpty(){
            return size==0;
        }

        bool isFull(){
            return size==arrSize-1;
        }

        int left(int i){
            return (2*i)+1;
        }

        int right(int i){
            return (2*i)+2;
        }

        int parent(int i){
            return (i-1)/2;
        }

        void insert(int value){
            if(isFull()){
               cout<<"heap is full";
               return; 
            }

            else{
                size++;
                arr[size-1]=value;
                int par=parent(size-1);
                int curr=size-1;
                while(true){
                    if(arr[par]<=arr[curr] && par!=0){
                        swap(arr[par],arr[curr]);
                        curr=par;
                        par=parent(par);  
                    }
                    else{
                        break;
                    }
                }
                return ;
            }
        }

        void display(){
            if (isEmpty())
            {
                cout << "Empty Heap" << endl;
                return;
            }
            for (int i = 0; i < size; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
};

int main(){
    // max_heap h(8);
    max_heap h(100);
    h.insert(4);
    h.insert(0);
    h.insert(1);
    h.insert(10);
    h.insert(5);
    h.display();
    return 0;
}