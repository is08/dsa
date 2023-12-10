#include<iostream>
using namespace std;

string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void printKeyPadOutput(string input, string output, int i = 0) {
    if(i == input.size()) {
        cout << output << endl;
    }

    int currAlphabet = (((int) input[i]) - 48);
    string currMapping = keypad[currAlphabet];

    for(int j = 0; j < currMapping.size(); j++) {
        printKeyPadOutput(input, output + currMapping[j], (i + 1));
    }
}

int main() {
    string input = "9433";
    printKeyPadOutput(input, "");

    return 0;
}
