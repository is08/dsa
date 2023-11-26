#include<iostream>
#include<vector>
using namespace std;

int countSubsets(vector<int> arr, int n, int i, int X) {
    if(n == i) {
        if(X == 0) {
            return 1;
        }
        return 0;
    }

    int excludeCurrentElem = countSubsets(arr, n, (i + 1), X);
    int includeCurrentElem = countSubsets(arr, n, (i + 1), (X-arr[i]));

    return includeCurrentElem + excludeCurrentElem;
}


int main() {
    vector<int> arr{1, 2, 3, 4, 5};
    int X = 10;

    cout << countSubsets(arr, arr.size(), 0, X);

    return 0;
}
