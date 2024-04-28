#include<iostream>
#include<vector>
using namespace std;

/*
given = [10, 5, 2, 0, 7, 6, 4], using DFS

arr = [10, 5, 2, 0, 7, 6, 4]
left = [10, 5, 2, 0]
right = [7, 6, 4]

    arr = [10, 5, 2, 0]
    left = [10, 5]
    right = [2, 0]

        arr = [10, 5]
        left = [10]
        right = [5]
        merged = [5, 10]

        arr = [2, 0]
        left = [2]
        right = [0]
        merged = [0, 2]

    merged = [0, 2, 5, 10]

    arr = [7, 6, 4]
    left = [7, 6]
    right = [4]

        arr = [7, 6]
        left = [7]
        right = [6]
        merged = [6, 7]

        arr = [4]
        merged = [4]

    merged = [4, 6, 7]

merged = [0, 2, 4, 5, 6, 7, 10]
*/


vector<int> merge(vector<int> &arr, int s, int e){
    vector<int> temp;
    int mid = (s + e)/2;

    int i = s, j = (mid + 1);

    while(i <= mid && j <= e){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= e){
        temp.push_back(arr[j]);
        j++;
    }

    int k = 0;

    for(int i = s; i <= e; i++){
        arr[i] = temp[k];
        k++;
    }

    return arr;
}

void mergeSort(vector<int> &arr, int s, int e){
    if(s >= e){
        return ;
    }

    int mid = (s + e) / 2;

    cout << "call for LEFT mergeSort from " << arr[s] << " to " << arr[mid] << endl;
    mergeSort(arr, s, mid);
    cout << "call for RIGHT mergeSort from " << arr[mid + 1] << " to " << arr[e] << endl;
    mergeSort(arr, mid + 1, e);
    cout << "call for merge from " << arr[s] << " to " << arr[e] << endl;
    merge(arr, s, e);
}

int main(){
    vector<int> arr = {10, 5, 2, 0, 7, 6, 4};

    cout << "before sorting: " << endl;
    for(auto elem: arr){
        cout << elem << " ";
    }
    cout << endl << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "after sorting: " << endl;
    for(auto elem: arr){
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
