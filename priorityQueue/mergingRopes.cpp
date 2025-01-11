#include<iostream>
#include <queue>
using namespace std;

int join_ropes(int ropes[], int n) {
    priority_queue<int, vector<int>, greater<int>> pq(ropes, ropes + n);
    int ans = 0;

    while(pq.size() > 1) {
        int firstElem = pq.top();
        pq.pop();

        int secondElem = pq.top();
        pq.pop();

        int sum = firstElem + secondElem;

        ans += sum;
        pq.push(sum);
    }

    return ans;
}

int main() {
    int ropes[] = {2, 3, 4, 6};
    int n = 4;

    cout << join_ropes(ropes, n) << endl;

    return 0;
}
