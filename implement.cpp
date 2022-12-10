
// Add two large numbers using Stack

#include <iostream>
#include "Stack.hpp"
#include <string>
using namespace std ;

class AddTwoNums{

    private:
        string A;
        string B;
        Stack<int> stk1 ;
        Stack<int> stk2 ;
        

    public: 
        AddTwoNums(string A , string B){
           this->A=A;
           this->B=B;  
            Add();  
        }

    void Add(){
        Stack<int> sum;
        for(int i =0 ; i<A.length() ; i++){
            int num= (int)A[i] ;
            stk1.push(num-48);  
        }

        for(int i =0 ; i<B.length() ; i++){
            int num= (int)A[i] ; 
            stk2.push(num-48);  

        }

        int carry=0;        
        while((!stk1.isEmpty()) and (!stk2.isEmpty())){    
            int a = (stk1.topEl()+stk2.topEl()+carry);
            // if(a>10){
                sum.push(a%10);
                carry=a/10 ;
            // }
            // else{
            //     sum.push(a);
            // }
            stk1.pop();
            stk2.pop();
        }

        while(!stk1.isEmpty()){
            sum.push(stk1.topEl()+carry);
            carry=stk1.topEl()/10;
            stk1.pop();
        }

        while(!stk2.isEmpty()){
            sum.push(stk2.topEl()+carry);
            carry=stk2.topEl()/10;
            stk2.pop();
        }

        

        cout<<"Sum of Numbers is : ";
        displayStack(sum);
    }

    void displayStack(Stack<int>& A){
        while(!A.isEmpty()){
            cout<<A.topEl();
            A.pop();
        }
    }

} ;

int main(){

    string num1, num2 ;
    cout<<"Enter Num 1 : " ;
    cin >>num1;
    cout<<"Enter Num 2 : " ;
    cin >>num2;
    
    AddTwoNums obj(num1,num2);
    
    return 0 ;

}