#include<iostream>
#include<vector>
using namespace std;

int minJump(vector<int> arr, int n, vector<int> dp, int i = 0) {
    if(i == (n - 1)) {
        return 0;
    }
    if(i >= n) {
        return 10e8;
    }

    if(dp[i] != -1) {
        return dp[i];
    }

    int jumpMax = arr[i], minJmp = 10e8;

    for(int j = 1; j <= jumpMax; j++) {
        if((i + j) < n) {
            int jump = minJump(arr, n, dp, (i + j));
            minJmp = min(minJmp, jump);
        }
    }

    dp[i] = (minJmp + 1);
    return (minJmp + 1);
}

int main() {
    vector<int> arr{3, 4, 2, 1, 2, 3, 7, 1, 1, 3};
    int n = arr.size();
    vector<int> dp(n, -1);

    cout << "min jump needed is " << minJump(arr, n, dp, 0) << endl;

    return 0;
}
