#include <iostream>
#include <stack>
using namespace std;

void error(string msg, char c);
bool is_balanced(string s){
    stack<char> bal;
    for (auto s: c){
        if(c=='(' || c== '<'||c=='{' || c=='['){
            //[push it onto stack]
            bal.push(c);
        }
        else if (c==')' || c== '>'||c=='}' || c==']'){
            //CHECK IF THE ELEMENT MATCHES ITS OTHER OPENING ONE IF IT DOES THEN POP ELSE FALSE
            char top = bal.top();
            //get elem then pop it
            //check if the elem before is its closing one if not false
            bal.pop();
            if (top =='(' &&)

        }

    }
}
void test_is_balanced();
