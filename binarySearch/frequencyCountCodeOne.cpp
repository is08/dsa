#include<iostream>
#include<vector>
using namespace std;

int lower_bound(vector<int> arr, int key) {
    int s = 0, e = arr.size() - 1, ans = -1, mid;

    while(s <= e) {
        mid = (s + e)/2;

        if(arr[mid] == key) {
            ans = mid;
            e = (mid - 1);
        }
        else if(arr[mid] > key) {
            e = (mid - 1);
        }
        else{
            s = (mid + 1);
        }
    }

    return ans;
}

int upper_bound(vector<int> arr, int key) {
    int s = 0, e = arr.size() - 1, ans = -1, mid;

    while(s <= e) {
        mid = (s + e) / 2;

        if(arr[mid] == key) {
            ans = mid;
            s = (mid + 1);
        }
        else if(arr[mid] > key) {
            e = (mid - 1);
        }
        else{
            s = (mid + 1);
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {0, 1, 1, 1, 1, 2, 2, 2, 3, 4, 4, 5, 10};

    cout << lower_bound(arr, 2) << " " << upper_bound(arr, 2) << endl;
    cout << upper_bound(arr, 2) - lower_bound(arr, 2) + 1 << endl;

    return 0;
}
