#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<sstream>
#include<algorithm>
using namespace std;

string simplifyPath(string path) {
    istringstream iss(path);
    vector<string> tokens;
    stack<string> directory;
    string token, ans = "";

    while(getline(iss, token, '/')) {
        if(token == "." || token == "") {
            continue;
        }
        tokens.push_back(token);
    }

    for(string token: tokens) {
        if(token == "..") {
            if(!directory.empty()) {
                directory.pop();
            }
        }
        else {
            directory.push(token);
        }
    }

    while(!directory.empty()) {
        ans.append("/");
        ans.append(directory.top());
        directory.pop();
    }
    if(path[0] == '.') {
        ans.append("..");
    }

    reverse(ans.begin(), ans.end());

    if(ans == "") {
        ans.append("/");
    }

    return ans;
}


int main() {
    string path = "/a/./b/../../c/";
    cout << simplifyPath(path) << endl;

    return 0;
}
