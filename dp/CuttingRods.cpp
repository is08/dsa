#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> prices, int n, vector<int>& dp) {
    if(n <= 0) {
        return 0;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    int maxProf = -10e8;
    for(int i = 0; i < n; i++) {
        int cutLength = (i + 1);
        int tempProf = prices[i] + maxProfit(prices, (n - cutLength), dp);

        maxProf = max(maxProf, tempProf);
    }

    dp[n] = maxProf;
    return maxProf;
}

int maxProfit(vector<int> prices, int n) {
    vector<int> dp(n + 1, -1);

    return maxProfit(prices, n, dp);
}

int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = prices.size();

    cout << "maxProfit " << maxProfit(prices, n)<< endl;

    return 0;
}
