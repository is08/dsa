#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> solve(vector<int> arr, int target){
    vector<pair<int, int>> ans;

    for(int i = 0; i < arr.size(); i++){
        int j = (i + 1), tempSum = arr[i];

        while(tempSum < target){
            tempSum += arr[j];
            j++;
        }

        if(tempSum == target){
            pair<int, int> temp = {i, (j - 1)};
            ans.push_back(temp);
        }
    }


    return ans;
}

int main(){
    vector<int> arr = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 2};
    int target = 8;

    auto ans = solve(arr, target);

    for(auto elem: ans){
        cout << elem.first << " " << elem.second << endl;
    }

    return 0;
}
