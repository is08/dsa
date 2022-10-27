#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> maxInWindow(vector<int> input,int k){

    int startingIndex = 0;
    vector<int> ans;

    while(startingIndex <= (input.size() - k)){
        auto tempMax = max_element(input.begin() + startingIndex, input.begin() + startingIndex + k);
        ans.push_back(*tempMax);

        startingIndex++;
    }

    return ans;
}

int main(){
    vector<int> input = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;

    vector<int> ans = maxInWindow(input, k);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
