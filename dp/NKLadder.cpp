#include<iostream>
#include<vector>
using namespace std;

int solveNKLadder(int n, int k, vector<int>& dp) {
    if(n == 0) {
        return 1;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    int sum = 0;
    for(int i = 1; i <= k; i++) {
        if((n - i) < 0) {
            break;
        }

        sum += solveNKLadder((n - i), k, dp);
    }

    dp[n] = sum;
    return sum;
}

int main() {
    int n = 4, k = 3;
    vector<int> dp((n + 1), -1);

    cout << "number of ways is " << solveNKLadder(n, k, dp) << endl;

    return 0;
}
