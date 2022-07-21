#include<vector>
#include<iostream>
using namespace std;

int maxSubarraySum(vector<int> arr){
    int n = arr.size();
    int i = 0, startingIndex = 0, sum = 0, maxSum = -10e8;

    while(arr[i] < 0){
        i++;
    }

    if(i == n){
        return 0;
    }

    startingIndex = i;

    for(int j = startingIndex; j < n; j++){

        sum += arr[j];
        maxSum = max(maxSum, sum);

        if(sum < 0){
            sum = 0;
        }

    }

    return maxSum;

}

int main(){

    vector<int> arr = {10, 2, -20, -1, 2, 3, 4, -2, 6, -8, 3};

    cout << maxSubarraySum(arr) << "\n";

    return 0;
}
