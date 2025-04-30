#include <iostream>
#include <stack>
#include <iostream>
using namespace std;

void error(string msg, char c){
    cout<<"Error - "<<c<<msg<<endl;
}


bool is_balanced(string s){
    stack<char> bal;
    //can i use .length would that not be better
    for (auto c:s){ //change to string.length
        if(c=='(' || c== '<'||c=='{' || c=='['){
            //[push it onto stack]
            bal.push(c);
        }
        else if (c==')' || c== '>'||c=='}' || c==']'){
            // <[]> once get to ']' check topofstack to see if its closing version if is pop then continu else false
            //CHECK IF THE ELEMENT MATCHES ITS OTHER OPENING ONE IF IT DOES THEN POP ELSE FALSE
            //get elem then pop it
            //check if the elem before is its closing one if not false
            if (bal.empty()){
                // ']' this input would be cov by empty
                return false;
            }
            char top_of_stack = bal.top();
            bal.pop();
            if (!((top_of_stack =='(' && c ==')') || (top_of_stack=='<'&& c=='>')|| (top_of_stack=='{' && c =='}') || (top_of_stack=='[' && c ==']'))){
                return false;
            }
            else{
                return false;
            }
        }
        else{
            //else return false
            return false;
        }
    }
    if (bal.empty()){
        return true;

    }
    return false;
}
void test_is_balanced(){
    cout<<"<()> should return True this returned "<<is_balanced("<()>")<<endl;
    cout<<"<() should return False this returned "<<is_balanced("<()")<<endl;
}
