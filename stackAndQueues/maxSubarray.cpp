#include<iostream>
#include<deque>
#include<vector>
using namespace std;

void maxSubarray(vector<int> arr, int k) {
    deque<int> Q(k);

    for(int i = 0; i < k; i++) {
        while(!Q.empty() && arr[Q.back()] < arr[i]) {
            Q.pop_back();
        }

        Q.push_back(i);
    }
    cout << arr[Q.front()] << " ";

    for(int i = k; i < arr.size(); i++) {
        while(!Q.empty() && Q.front() <= (i - k)) {
            Q.pop_front();
        }

        while(!Q.empty() && arr[Q.back()] <= arr[i]) {
            Q.pop_back();
        }

        Q.push_back(i);

        cout << arr[Q.front()] << " ";
    }
}


int main() {
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;

    maxSubarray(arr, k);
}
