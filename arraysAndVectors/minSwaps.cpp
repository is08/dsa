#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minSwaps(vector<int> arr){          //arr = {5, 4, 3, 2, 1}
    int totalSwaps = 0, n = arr.size();
    pair<int, int> ap[n];

    for(int i = 0; i < n; i++){         //{5, 4, 3, 2, 1}
        ap[i].first = arr[i];             //{0, 1, 2, 3, 4}   <- old indices
        ap[i].second = i;
    }

    sort(ap, ap + n);                   //{1, 2, 3, 4, 5}
                                        //{4, 3, 2, 1, 0}    <- old indices, changed because we sorted according to value
                                        //{0, 1, 2, 3, 4}
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++){
        if(visited[i] == true || ap[i].second == i){
            continue;
        }

        int tempCycle = 0, curr = i;

        while(visited[curr] == false){
            visited[curr] = true;
            curr = ap[curr].second;
            tempCycle++;
        }

        totalSwaps += (tempCycle - 1);
    }


    return totalSwaps;
}

int main(){
    vector<int> arr = {5, 4, 3, 2, 1};

    cout << minSwaps(arr) << "\n";

    return 0;
}
