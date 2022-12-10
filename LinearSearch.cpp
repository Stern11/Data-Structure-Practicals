//Linear Search

// Aryan Pratap Singh Arya
//21513

#include <iostream>
using namespace std; 

class Search{
    private:
        int* array;
        int index ;

    public :
        int linearSearch(int *arr , size_t n , int numberToSearch){
            
            for(int i=0 ; i<n ; i++){
                if(arr[i]==numberToSearch){
                    return i ;
                    break;
                }
            }
            return -1 ;
        }      

};

int main(){

    int size ; int *array ;int numberToSearch;
    cout<<"Enter length of your array : " ;
    cin>> size ;
    array= new int [size];

    cout<<"Enter the elements in the array : " ;
    for(int i=0 ; i<size ; i++ ){
        cin >> array[i];
    }

    cout<<"\nEnter the element you want to search in the array : " ; 
    cin>>numberToSearch;
    Search obj;

    cout<<endl << numberToSearch << " found at index " << 
    obj.linearSearch(array, size ,numberToSearch) <<" in the array."<<endl ;

    cout<<"\n\nNOTE : -1 indicates element you want to search is not present in the array."<<endl ;

    return 0 ;
}