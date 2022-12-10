// Binary Search 

// Aryan Pratap Singh Arya
// 21513

#include <iostream>
using namespace std;

class Search{
    public :
        int binarySearch(int * arr , int start, int end, int numberToSearch){
            int n = (start+end)/2;

            if(start==end){ //base condition 
                return -1 ;
            }
            else{

                if(numberToSearch==arr[n]){
                    return n;
                }

                else if(numberToSearch<arr[n]){
                    end=n;
                    return binarySearch(arr,start, end , numberToSearch);
                }

                else if(numberToSearch>arr[n]){
                    start=n+1;
                    return binarySearch(arr, start , end , numberToSearch);
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

    cout<<"Enter the elements in the array (Sorted) : " ;
    for(int i=0 ; i<size ; i++ ){
        cin >> array[i];
    }

    cout<<"\nEnter the element you want to search in the array : " ; 
    cin>>numberToSearch;
    Search obj;

    cout<<endl << numberToSearch << " found at index " << 
    obj.binarySearch(array, 0, size , numberToSearch) <<" in the array."<<endl ;

    cout<<"\n\nNOTE : -1 indicates element you want to search is not present in the array."<<endl ;


    return 0;
}