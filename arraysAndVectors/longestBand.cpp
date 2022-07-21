#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int longestChain(vector<int> arr){
    int longestBand = 0;
    unordered_set<int> arr2;

    for(int i = 0; i < arr.size(); i++){
        arr2.insert(arr[i]);
    }

    for(int i = 0; i < arr.size(); i++){
        if(arr2.find(arr[i] - 1) == arr2.end()){
            int tempElement = arr[i], tempLongestBand = 1;

            while(arr2.find(++tempElement) != arr2.end()){
                tempLongestBand++;
            }

            longestBand = max(longestBand, tempLongestBand);
        }
    }

    return longestBand;
}

int main(){

    vector<int> arr{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    cout << longestChain(arr) << "\n";

    return 0;
}
