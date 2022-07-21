#include<vector>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;


pair<int,int> minDifference(vector<int> a,vector<int> b){
    pair<int, int> res;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int indexA = 0, indexB = 0, elemA = a[0], elemB = b[0], minDiff = INT_MAX, tempDiff;

    while(indexA < a.size() && indexB < b.size()){

        tempDiff = abs(a[indexA] - b[indexB]);

        if(tempDiff < minDiff){
            minDiff = tempDiff;
            elemA = a[indexA];
            elemB = b[indexB];
        }

        if(a[indexA] < b[indexB]){
            indexA++;
        }
        else{
            indexB++;
        }
    }

    while(++indexA < a.size()){
        tempDiff = abs(a[indexA] - b[indexB]);

        if(tempDiff < minDiff){
            minDiff = tempDiff;
            elemA = a[indexA];
            elemB = b[indexB];
        }
    }

    while(++indexB < b.size()){
        tempDiff = abs(a[indexA] - b[indexB]);

        if(tempDiff < minDiff){
            minDiff = tempDiff;
            elemA = a[indexA];
            elemB = b[indexB];
        }
    }

    res.first = elemA;
    res.second = elemB;

    return res;
}

int main(){
    vector<int> a = {23, 5, 10, 17, 30};
    vector<int> b = {26, 134, 135, 14, 19};

    auto ans = minDifference(a, b);

    cout << ans.first << " " << ans.second << "\n";

    return 0;
}
