#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//we have to traverse through the array and find all the subarrays where sum is equal to k
//using sliding window
//is it possible to do this using 2 pointer approach, we need sorting for that
//when to expand? when to contract?
//hashmap? how?

int cntSubarrays(vector<int> arr,int k){
    int cnt = 0, sum = 0;
    int windowStart = 0;

    unordered_map<int, int> prevSum;

   for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++){

        sum += arr[windowEnd];

        if(sum == k){
            cnt++;
        }

        if (prevSum.find(sum - k) != prevSum.end()){
            cnt += (prevSum[sum - k]);
        }

        prevSum[sum]++;
   }

    return cnt;
}

int main(){
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;

    cout << cntSubarrays(arr, k) << endl;

    return 0;
}
