#include<iostream>
#include<vector>
using namespace std;


int highest_mountain(vector<int> arr){
    int n = arr.size();
    int lengthOfMountain = -1e8;

    for(int i = 1; i < (n - 1); i++){
        if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]){
            int tempLength = 1, j = i;

            while(arr[j - 1] < arr[j]){
                j--;
                tempLength++;
            }

            j = i;

            while(arr[j + 1] < arr[j]){
                j++;
                tempLength++;
            }

            lengthOfMountain = max(lengthOfMountain, tempLength);
        }
    }

    return lengthOfMountain;
}

int main(){

    vector<int> arr{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};

    int length = highest_mountain(arr);

    cout << length << "\n";

    return 0;
}
