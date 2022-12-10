// parenthesis validity checker

#include <iostream>
#include "Stack.hpp"
using namespace std;


bool parenthesis_validity_check(string A){
    Stack <char>obj;
    for(int i=0  ; i <A.length() ; i++){
        if (A[i]=='(' || A[i]=='['|| A[i]=='{' ){
            obj.push(A[i]) ;
        }

        else if(A[i]==')' || A[i]==']'|| A[i]=='}'){
            if((obj.topEl()=='(' and A[i]==')') || (obj.topEl()=='[' and A[i]==']') || (obj.topEl()=='{' and A[i]=='}') ){
                obj.pop();
            }
            else{
                return false ;
            }
        }
    }

    if(obj.isEmpty()){
        return true;
    }
    else{
        return true;
    }
}

int main(){
    cout<<"Enter an Expression : " ;
    string expression ;
    cin>> expression ;
    if(parenthesis_validity_check(expression)){
        cout<<"Expression is valid "<<endl ;
    }
    else{
        cout<<"Invalid Expression" ;
    }
    
}