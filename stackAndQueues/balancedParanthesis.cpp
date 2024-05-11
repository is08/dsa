#include<iostream>
#include<stack>
using namespace std;

bool isBalancedParanthesis(string s) {
    stack<char> st;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            st.push(s[i]);
        }
        else if(s[i] == ')') {
            st.pop();
        }
    }

    return st.empty();
}


int main() {
    string s = "(((a+b)*x-d))";
    cout << isBalancedParanthesis(s) << endl;

    return 0;
}
