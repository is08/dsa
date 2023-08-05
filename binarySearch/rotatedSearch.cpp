#include<iostream>
#include<vector>
using namespace std;

int rotated_search(vector<int> arr, int key) {
    int s = 0, e = (arr.size() - 1), mid;

    while(s <= e) {
        mid = (s + e) / 2;

        if(arr[mid] == key) {
            return mid;
        }
        else if(arr[s] <= arr[mid]) {
            if(arr[s] <= key && key <= arr[mid - 1]) {
                e = (mid - 1);
            }
            else if(arr[mid + 1] <= key && key <= arr[e]) {
                s = (mid + 1);
            }
        }
        else if(arr[mid] <= arr[e]) {
            if(arr[s] <= key && key <= arr[mid - 1]) {
                cout << "left" << endl;
                e = (mid - 1);
            }
            else if(arr[mid + 1] <= key && key <= arr[e]) {
                s = (mid + 1);
            }
        }
    }
    return -1;
}


int main() {
    vector<int> arr = {5, 6, 7, 1, 2, 3, 4};
    cout << rotated_search(arr, 1);

    return 0;
}
