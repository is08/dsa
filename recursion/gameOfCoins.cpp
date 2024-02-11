#include<iostream>
#include<vector>
using namespace std;

void calculateMaxValue(int n, vector<int> v, bool myChance, int &ans) {
    if(n == 0) {
        return;
    }

    if(v[0] >= v[v.size() - 1]) {
        if(myChance) {
            ans += v[0];
        }
        vector<int> newVector = {v.begin() + 1, v.end()};
        calculateMaxValue((n-1), newVector, !myChance, ans);
    }
    else {
        if(myChance) {
            ans += v[v.size() - 1];
        }
        vector<int> newVector = {v.begin(), v.end() - 1};
        calculateMaxValue((n-1), newVector, !myChance, ans);
    }
}

int maxValue(int n, vector<int> v){
    int ans = 0;
    calculateMaxValue(n, v, true, ans);

    return ans;
}

int main() {
    vector<int> v{5, 3, 6, 10, 7};
    int n = 5;
    cout << maxValue(n, v) << endl;

    return 0;
}
