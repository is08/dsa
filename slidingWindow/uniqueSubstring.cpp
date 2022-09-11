#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

//return substring of maximum length with unique characters
string uniqueSubstring(string s){
    int i = 0, j = 0, startingIndex = -1, currWindowLength = 0, maxWindowLength = -1;
    unordered_map<char, int> m;

    while(j < s.size()){
        if(m.find(s[j]) != m.end() && m[s[j]] >= i){
            i = m[s[j]] + 1;
            currWindowLength = (j - i);
        }

        m[s[j]] = j;
        currWindowLength++;
        j++;

        if(currWindowLength > maxWindowLength){
            maxWindowLength = currWindowLength;
            startingIndex = i;
        }
    }

    return s.substr(startingIndex, maxWindowLength);
}

int main(){
    string s = "abcabed";
    cout << uniqueSubstring(s) << '\n';

    return 0;
}
