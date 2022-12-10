// Sorting

// Aryan Pratap Singh Arya
// 21513 

#include <iostream>
#define display true;
using namespace std;

template <class T>
class Sort{

    private:

        void swap(T  &A , T  &B){
            T  temp;
            temp= A ;
            A=B;
            B=temp;
        }
    
    public:
        
        T  * BubbleSort(T  *arr , size_t n){
            int compareCount=0;
            
            for(int i=0 ; i<n-1 ; i++){
                bool flag = false;
                for(int j=0 ; j<n-i-1 ; j++){
                    compareCount++;
                    if(arr[j]>arr[j+1]){
                        swap(arr[j], arr[j+1]);
                        flag=true;
                    }
                }
                if(!flag){
                    break;
                }
            }
            cout<<"Total Number of Comparisons done in Bubble Sort: " << compareCount;
            return arr;
        }

        T  * SelectionSort(T  *arr , size_t n){
            int compareCount=0 ;
            for(int i=0 ; i<n-1 ; i++){               
                for(int j=i+1 ; j<n ; j++){
                    compareCount++;
                    if(arr[i]>=arr[j]){
                        swap(arr[i],arr[j]);
                    }
                }
            }
            cout<<"Total Number of Comparisons done in Selection Sort : " << compareCount<<endl ;
            return arr;
        }

        T  * InsertionSort(T  *arr , size_t n){
            int compareCount=0;

            for(int i=1 ; i<n ; i++){
                for(int j=i ; j>0 ; j--){
                    compareCount++;
                    if(arr[j]<arr[j-1]){
                        swap(arr[j],arr[j-1]);
                    }
                }
            }
            cout<<"Total Number of Comparisons done in Insertion Sort : " << compareCount<<endl ;
            return arr; 
        }

        void arryDisplay(T * arr, size_t n){
            for (int i=0 ; i<n ; i++){
                cout << arr[i]<<" " ;
            }
            cout << endl ;
        }


};

int main(){
    size_t length ;
    int *array;

    cout<<"Enter no. of elements in the list to be sorted : " ;
    cin>>length ;

    array=new int[length];

    cout<<"Enter the elements in the array : " ;
    for(int i=0 ; i<length ; i++){
        cin>>array[i];
    }

    Sort <int> obj ; 

    int choice;

    while(true){
        cout<<"\nEnter the operation You wanna perform : " <<endl <<
            "1. BubbleSort. "<<endl <<
            "2. InsertionSort. " <<endl <<
            "3. SelectionSort. " <<endl<<
            "4. Exit. "<<endl ;
        cin>>choice;
        
        switch (choice)
        {
        case 1:
            obj.BubbleSort(array,length);
            cout <<"\nArray after sorting is : " ;
            obj.arryDisplay(array, length) ;
            break ;
            
        case 2 :
            obj.InsertionSort(array,length);
            cout <<"Array after sorting is : " ;
            obj.arryDisplay(array, length);
            break ;

        case 3:
            obj.SelectionSort(array,length);
            cout <<"Array after sorting is : " ; 
            obj.arryDisplay(array, length) ;
            break;    
        } 

        if(choice==4){
            break;
        }
    }
    return 0 ;
}