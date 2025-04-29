#include <iostream>
#include <stack>
#include <iostream>
using namespace std;

void error(string msg, char c){
    cout<<"Error - "<<c<<msg<<endl;
}


bool is_balanced(string s){
    stack<char> bal;
    for (auto c: s){
        if(c=='(' || c== '<'||c=='{' || c=='['){
            //[push it onto stack]
            bal.push(c);
        }
        else if (c==')' || c== '>'||c=='}' || c==']'){
            //CHECK IF THE ELEMENT MATCHES ITS OTHER OPENING ONE IF IT DOES THEN POP ELSE FALSE
            
            //get elem then pop it
            //check if the elem before is its closing one if not false
            
            char top = bal.top();
            bal.pop();
            if (!((top =='(' && c ==')') || (top=='<'&& c=='>')|| (top=='{' && c =='}') || (top=='[' && c ==']'))){
                return false;
            }

        }
    
    }
    return bal.empty();
}
void test_is_balanced(){
    cout<<"<()> should return True this returned "<<is_balanced("<()>")<<endl;
    cout<<"<() should return False this returned "<<is_balanced("<()")<<endl;
}
