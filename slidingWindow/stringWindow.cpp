#include<iostream>
#include<map>
#include<string.h>
using namespace std;

string stringWindow(string s, string p){
    int windowStart = 0, windowEnd = 0, cnt = 0;
    int lengthOfWindow = 10e8, finalWindowStart = 0;

    map<char, int> patternFreq;
    map<char, int> windowFreq;

    //making a frequency map of pattern
    for(int i = 0; i < p.size(); i++){
        if(patternFreq.find(p[i]) != patternFreq.end()){
            patternFreq[p[i]]++;
        }
        else{
            patternFreq.insert(make_pair(p[i], 1));
        }
    }

    //sliding window algorithm
    //expanding the window
    for(int i = 0; i < s.size(); i++){
        if(windowFreq.find(s[i]) != windowFreq.end()){
            windowFreq[s[i]]++;
        }
        else{
            windowFreq.insert(make_pair(s[i], 1));
        }

        //counting how many characters & freq is matched
        if(patternFreq.find(s[i]) != patternFreq.end() && patternFreq[s[i]] >= windowFreq[s[i]]){
            cnt++;
        }

        //check if all characters of pattern are found in the window
        if(cnt == p.size()){

            //we can contract from left to remove unwanted char (not present, or higher freq than required)
            while(patternFreq.find(s[windowStart]) == patternFreq.end() || windowFreq[s[windowStart]] > patternFreq[s[windowStart]]){
                windowFreq[s[windowStart]]--;
                windowStart++;
            }

            if(lengthOfWindow > (i - windowStart)){
                lengthOfWindow = (i - windowStart);
                finalWindowStart = windowStart;
            }

        }

    }
    return s.substr(finalWindowStart, lengthOfWindow + 1);
}

int main(){
    string s, p;
    cin >> s >> p;

    cout << stringWindow(s, p);

    return 0;
}
