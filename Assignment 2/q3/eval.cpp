
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

#include <iostream>

using namespace std;

int main () {
    
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token
    t = S.getnext();
    
    
    while(t.tt != eof||!opstack.isEmpty()){

        if(t.tt == integer){
            numstack.push(t);
            t = S.getnext();
        }
        
        else if(t.tt == lptok){
            opstack.push(t);
            t = S.getnext();
        }

        else if(t.tt == rptok){

            if(opstack.peek().tt == lptok){
                opstack.pop();
                t = S.getnext();
            }

            else{
                Token ans;
                int num1 = numstack.pop().val;
                int num2 = numstack.pop().val;
                Token op = opstack.pop();

                if(op.tt == mitok){
                    ans.val = num2-num1;
                }

                else if(op.tt == pltok){
                    ans.val = num1+num2;
                }

                else if(op.tt == asttok){
                    ans.val = num1*num2; 
                }

                else if(op.tt == slashtok){
                    ans.val = num2/num1;
                }

                numstack.push(ans);
            }
        }
        else if(t.tt == pltok ||t.tt == mitok||t.tt == eof){
            
            if(!opstack.isEmpty() && (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == asttok|| opstack.peek().tt == slashtok)){
                Token ans;
                int num1 = numstack.pop().val;
                int num2 = numstack.pop().val;
                Token op = opstack.pop();

                if(op.tt == mitok){
                    ans.val = num2-num1;
                }

                else if(op.tt == pltok){
                    ans.val = num1+num2;
                }

                else if(op.tt == asttok){
                    ans.val = num1*num2; 
                }

                else if(op.tt == slashtok){
                    ans.val = num2/num1;
                }

                numstack.push(ans);
            }
            else{
                opstack.push(t);
                t = S.getnext();
            }
        }

        else if(t.tt == asttok ||t.tt == slashtok){
           
            if(!opstack.isEmpty()&& (opstack.peek().tt == asttok || opstack.peek().tt == slashtok)){
                Token ans;
                int num1 = numstack.pop().val;
                int num2 = numstack.pop().val;
                Token op = opstack.pop();
                
                if(op.tt == asttok){
                    ans.val = num1*num2; 
                }

                else if(op.tt == slashtok){
                    ans.val = num2/num1;
                }

                numstack.push(ans);
            }

            else{
                opstack.push(t);
                t = S.getnext();
            }
        }
    }
    return 0;
}

