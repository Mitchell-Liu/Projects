
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

#include <iostream>

using namespace std;


int main () {
    
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token
    cout<<"1"<<endl;
    t = S.getnext();
    
    while(t.tt != eof){
        
        if(t.tt == integer){
            cout<<"2"<<endl;
            numstack.push(t);
            t = S.getnext();
        }
        else if(t.tt == lptok){
            cout<<"3"<<endl;
            opstack.push(t);
            t = S.getnext();
        }
        else if(t.tt == rptok){
            cout<<"4"<<endl;
            if(opstack.peek().tt == lptok){
                cout<<"4.1"<<endl;
                opstack.pop();
                t = S.getnext();
            }
            else{
                cout<<"4.2"<<endl;
                Token ans;
                int num1 = numstack.pop().val;
                int num2 = numstack.pop().val;
                Token op = opstack.pop();
                cout<<"num1 = "<<num1<<"num2 = "<<num2<<"op = "<<op<<endl;
                if(op.tt == mitok){
                    cout<<"4.2.1"<<endl;
                    ans.val = num1-num2;
                }
                else if(op.tt == pltok){
                    cout<<"4.2.2"<<endl;
                    ans.val = num1+num2;
                }
                else if(op.tt == asttok){
                    cout<<"4.2.3"<<endl;
                    ans.val = num1*num2; 
                }
                else if(op.tt == slashtok){
                    cout<<"4.2.4"<<endl;
                    ans.val = num1/num2;
                }
                numstack.push(ans);
                // opstack.pop();
            }
        }
        else if(t.tt == pltok ||t.tt == mitok||t.tt == eof){
            cout<<"5"<<endl;
            if(!opstack.isEmpty() && (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == asttok|| opstack.peek().tt == slashtok)){
                cout<<"5.1"<<endl;
                Token ans;
                int num1 = numstack.pop().val;
                int num2 = numstack.pop().val;
                Token op = opstack.pop();
                cout<<"num1 = "<<num1<<" num2 = "<<num2<<" op = "<<op<<endl;
                if(op.tt == mitok){
                    cout<<"5.1.1"<<endl;
                    ans.val = num1-num2;
                }
                else if(op.tt == pltok){
                    cout<<"5.1.2"<<endl;
                    ans.val = num1+num2;
                }
                else if(op.tt == asttok){
                    cout<<"5.2.3"<<endl;
                    ans.val = num1*num2; 
                }
                else if(op.tt == slashtok){
                    cout<<"5.2.4"<<endl;
                    ans.val = num1/num2;
                }
                cout<<"5.1.3"<<endl;
                numstack.push(ans);
                cout<<"ans= "<<ans.val<<endl;
            }
            else{
                cout<<"5.2"<<endl;
                opstack.push(t);
                t = S.getnext();
            }
        }
        else if(t.tt == asttok ||t.tt == slashtok){
            cout<<"6"<<endl;
            if(!opstack.isEmpty()&& (opstack.peek().tt == asttok || opstack.peek().tt == slashtok)){
                cout<<"6.1"<<endl;
                Token ans;
                int num1 = numstack.pop().val;
                int num2 = numstack.pop().val;
                Token op = opstack.pop();
                cout<<"Pain"<<endl;
                if(op.tt == asttok){
                    cout<<"6.1.1"<<endl;
                    ans.val = num1*num2; 
                }
                else if(op.tt == slashtok){
                    cout<<"6.1.2"<<endl;
                    ans.val = num1/num2;
                }
                cout<<"6.1.3"<<endl;
                numstack.push(ans);
            }
            else{
                cout<<"6.2"<<endl;
                opstack.push(t);
            }
        }
       
        cout<<"result = "<<numstack.peek().val<<endl;
    }

    // cout<<numstack.peek().val<<endl;
    // pretty printer coding demo.  please remove before coding
    while (t.tt != eof) {
        if (t.tt == integer || t.tt == lptok || t.tt == rptok) {
            cout << t;
        } else if (t.tt == pltok || t.tt == mitok || 
                   t.tt == asttok || t.tt == slashtok) {
            cout << ' ' << t << ' ';
        }

        t = S.getnext();
    }

    cout << endl;
    // end pretty printer

    return 0;
}

