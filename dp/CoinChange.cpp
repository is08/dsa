#include<iostream>
#include<vector>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms, vector<int>& dp) {
    if(n == 0) {
        return 0;
    }
    if(dp[n] != -1) {
        return dp[n];
    }

    int minVal = 10e8;

    for(int i = 0; i < denoms.size(); i++) {
        int temp = (n - denoms[i]);

        if(temp >= 0) {
            minVal = min(minVal, minNumberOfCoinsForChange(temp, denoms, dp));
        }
    }

    dp[n] = (minVal + 1);
    return (minVal + 1);
}

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
    vector<int> dp((n + 1), -1);

    return minNumberOfCoinsForChange(n, denoms, dp);
}

int main() {
    vector<int> denoms = {1, 3, 7, 10};
    int n = 3;

    cout << minNumberOfCoinsForChange(n, denoms);
}
