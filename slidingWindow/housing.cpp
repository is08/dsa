#include<iostream>
#include<vector>
using namespace std;

/*vector<pair<int, int>> solve(vector<int> arr, int target){
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
}*/

vector<pair<int, int>> slidingWindow(vector<int> arr, int target){
    int i = 0, j = 0, currSum = arr[0];
    vector<pair<int, int>> res;

    while(j < (arr.size() - 1)){
        //cout << "currSum is " << currSum << '\n';
        if(currSum < target){
            j++;
            currSum += arr[j];
        }
        else if(currSum > target){
            currSum -= arr[i];
            i++;
        }
        else{
            pair<int, int> tempPair = {i, j};

            res.push_back(tempPair);

            j++;
            currSum += arr[j];
        }
    }
    return res;
}

int main(){
    vector<int> arr = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 2};
    int target = 8;

    auto ans = slidingWindow(arr, target);

    for(auto elem: ans){
        cout << elem.first << " " << elem.second << endl;
    }

    return 0;
}
