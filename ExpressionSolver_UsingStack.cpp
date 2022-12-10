// Expression Solver
// only "+" , "-", "*" , "/" operators .


// Aryan Pratap Singh Arya 
// 21513

#include <iostream>
#include <string>
#include "Stack.hpp"

class ExpressionSolver{

    private:
        string A;
        Stack <char> operatorStk ;
        Stack <double> numStack ;
        string postfixExpression;
        int count=0;

    public:

        ExpressionSolver(string A){
            this->A= A;
            convertToPostfix(); 
            evaluate();
        }

        void convertToPostfix(){
            
            for(int i =0 ; i<A.length() ; i++){
                int x = (int)A[i] ;
                
                if(x<48){
                    if(operatorStk.isEmpty()){
                        operatorStk.push(x);
                    }
                    else{
                        
                        if(checkPrecedence(x)){
                            operatorStk.push(x);
                            // break ;
                        }
                        else{
                            postfixExpression+=char(operatorStk.topEl());
                            operatorStk.pop();
                            checkPrecedence(x);
                            // operatorStk.push(x) ;
                            
                        }
                    }
                }

                else{
                    postfixExpression += A[i];
                }
            }
            while(!operatorStk.isEmpty()){
                postfixExpression+=char(operatorStk.topEl());
                operatorStk.pop();
            }
            cout<<"Postfix expression is : "<<postfixExpression<<endl;
            
        }

         /*         * = 42
                    + = 43
                    - = 45
                    / = 47            */

        bool checkPrecedence(int x){
            
            if (operatorStk.topEl()==x){
                return false;
            }
            
            else if ((operatorStk.topEl() == '*' or operatorStk.topEl() == '/') and (x== '+' or x=='-' )){
                return false;
            }

            else if ((operatorStk.topEl() == '+' or operatorStk.topEl() == '-') and (x== '*' or x=='/' )){
                return true;
            }

            else if (((operatorStk.topEl() == '+' ) and (x== '-')) or ((operatorStk.topEl() == '-' ) and (x== '+'))) {
                return false;
            }

            else if (((operatorStk.topEl() == '/' ) and (x== '*')) or ((operatorStk.topEl() == '*' ) and (x== '/'))) {
                return false;
            }
        
            return false ;
        }

        void evaluate(){
            for(int i=0 ; i<postfixExpression.length() ; i++){

                double z = (double)postfixExpression[i];
                
                if(z>48){
                    numStack.push(z-48);
                }
                else{
                    double num1= numStack.topEl();
                    numStack.pop();
                    double num2= numStack.topEl();
                    numStack.pop();
                    double num3 ;
                    int var=z;
                    switch (var)
                    {
                    case 43:
                        num3= num2+num1 ;
                        break;
                    case 42:
                        num3= num2*num1 ;
                        break;
                    case 47:
                        num3= num2/num1 ;
                        break;
                    case 45:
                        num3= num2-num1 ;
                        break;    
                }
                numStack.push(num3);
            }

        }
         cout<<"Evaluataion of expression is : " << numStack.topEl()<< endl;
        }


};

int main(){

    string A;
    cout<<"Enter an Expression : "  ;
    cin >> A ;

    ExpressionSolver obj(A) ;


    return 0 ;
}