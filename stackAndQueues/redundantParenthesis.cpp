#include<iostream>
#include<stack>
using namespace std;

bool checkRedundant(string str) {
    stack<char> st;
    bool isOperatorFound = false;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == ')') {
            isOperatorFound = false;

            while(!st.empty() && st.top() != '(') {
                char top = st.top();

                if(top == '+' || top == '-' || top == '/' || top == '*') {
                    isOperatorFound = true;
                }

                st.pop();
            }

            char top = st.top();
            st.pop();

            if(!isOperatorFound) {
                return true;
            }
        }
        else {
            st.push(str[i]);
        }
    }

    return false;
}

int main() {
    string str = "((a+b))";

    if(checkRedundant(str)) {
        cout << "Contains redundant parenthesis" << endl;
    }
    else {
        cout << "Does not contains redundant parenthesis" << endl;
    }
}
