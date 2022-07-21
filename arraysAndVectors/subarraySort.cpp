#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*pair<int, int> subarraySort(vector<int> a){
    vector<int> temp = a;
    sort(temp.begin(), temp.end());


    int i = 0, startingIndex, endingIndex;

    while(a[i] == temp[i]){
        i++;
    }
    startingIndex = i;

    i = a.size() - 1;

    while(a[i] == temp[i]){
        i--;
    }
    endingIndex = i;

    pair<int, int> res(startingIndex, endingIndex);

    return res;
}*/

pair<int, int> subarraySort(vector<int> a){
    int largest = -10e8, smallest = 10e8;

    if(a[0] > a[1]){
        largest = max(largest, a[0]);
        smallest = min(smallest, a[0]);
    }

    for(int i = 1; i < a.size() - 1; i++){
        if(a[i] < a[i - 1] || a[i] > a[i + 1]){
            largest = max(largest, a[i]);
            smallest = min(smallest, a[i]);
        }
    }

    if(a[a.size() - 1] < a[a.size() - 1]){
        largest = max(largest, a[a.size() - 1]);
        smallest = min(smallest, a[a.size() - 1]);
    }

    int smallestIndex, largestIndex, i = 0;

    while(smallest > a[i]){
        i++;
    }

    smallestIndex = i;

    i = a.size() - 1;

    while(largest < a[i]){
        i--;
    }

    largestIndex = i;

    pair<int, int> res(smallestIndex, largestIndex);

    return res;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    auto p = subarraySort(arr);

    cout << p.first << " and " << p.second << "\n";

    return 0;
}
