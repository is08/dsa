#include<iostream>
#include <string>
using namespace std;

void generateBrackets(string output, int n, int open, int close, int currPos) {
    if(currPos == (2*n)) {
        cout << output << endl;
        return;
    }

    if(open < n) {
        generateBrackets(output + '(', n, (open + 1), close, (currPos + 1));
    }
    if(close < open) {
        generateBrackets(output + ')', n, open, (close + 1), (currPos + 1));
    }
}

int main() {
    string output = "";
    int n = 4;

    generateBrackets(output, n, 0, 0, 0);

    return 0;
}
