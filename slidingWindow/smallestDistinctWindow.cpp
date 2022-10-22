#include<string>
#include<map>
#include<iostream>
using namespace std;

string smallestWindow(string str){
    map<char, int> distinct;
    map<char, int> window;

    int lengthOfWindow = 10e8, startingIndex = 0, cnt = 0, finalStartingIndex = 0;

    for(int i = 0; i < str.size(); i++){
        if(distinct.find(str[i]) == distinct.end()){
            distinct.insert(make_pair(str[i], 1));
        }
    }

    for(int i = 0; i < str.size(); i++){
        if(window.find(str[i]) == window.end()){
            window.insert(make_pair(str[i], 1));
            cnt++;
        }
        else{
            window[str[i]]++;
        }

        if(cnt == distinct.size()){

            while(window[str[startingIndex]] > 1){
                window[str[startingIndex]]--;
                startingIndex++;
            }

            if(lengthOfWindow > (i - startingIndex + 1)){
                lengthOfWindow = (i - startingIndex + 1);
                finalStartingIndex = startingIndex;
            }
        }


    }

    return str.substr(finalStartingIndex, lengthOfWindow);

}

int main(){
    string str = "aabcbcdbcaaad";
    cout << smallestWindow(str) << endl;

    return 0;
}
