#include<iostream>
#include<vector>
using namespace std;

int getMinCost(vector<int> stones, vector<int>& dp, int n, int currPos, int currCost) {
    if(currPos > (n - 1)) {
        return 10e8;
    }
    if(currPos == (n - 1)) {
        return currCost;
    }
    int minCost = 10e8;

    for(int i = 1; i <= 2; i++) {
        if((currPos + i) <= (n - 1)) {
            int tempCurrCost = currCost + abs(stones[currPos] - stones[currPos + i]);
            int tempCost = getMinCost(stones, dp, n, (currPos + i), tempCurrCost);
            minCost = min(tempCost, minCost);
        }
    }

    return minCost;
}

int getMinCost(vector<int> stones) {
    int n = stones.size();
    int currPos = 0;
    int currCost = 0;
    vector<int> dp(n, -1);

    return getMinCost(stones, dp, n, currPos, currCost);
}

int main() {
    vector<int> stones{30, 10, 60, 10, 60, 50};
    cout << getMinCost(stones) << endl;
    return 0;
}
