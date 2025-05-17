#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n = 4, k = 3;
    vector<int> dp((n + 1), -1);
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        int times = 1, sum = 0;

        while(((i - times) >= 0) && times <= k) {
            sum += dp[i - times];
            times++;
        }

        dp[i] = sum;
    }

    cout << "number of ways is " << dp[n] << endl;

    return 0;
}
