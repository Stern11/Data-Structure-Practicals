
// Add two large numbers using Stack

#include <iostream>
#include "Stack.hpp"
#include <string>
using namespace std ;

class AddTwoNums{

    private:
        string A;
        string B;
        Stack stk1 ;
        Stack stk2 ;
        Stack sum;

    public: 
        AddTwoNums(string A , string B){
            this->A=A;
            this->B=B;  
            getNumFromstring(A,stk1);
            getNumFromstring(B,stk2); 
            addition();
            displayStack(sum);  
        }

        void getNumFromstring(string A , Stack& stk){
            for(int i =0 ; i<A.length() ; i++){
              //  int num= (int)A[i] ;
               // stk.push(num-48);   
               stk.push(A[i]-'0');
            }
        }

        void addition(){
            int carry=0;        
            while((!stk1.isEmpty()) and (!stk2.isEmpty())){    
                int a = (stk1.topEl()+stk2.topEl()+carry);
                sum.push(a%10);
                carry=a/10 ;
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

            if(carry>0){
                sum.push(carry);
            }         
        }

        void displayStack(Stack& A){
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