#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int find_lower_bound(int elem, vector<int> a2) {
    int s = 0, e = a2.size() - 1, mid;

    while(s <= e) {
        mid = (s + e) / 2;

        if(a2[mid] >= elem) {
            e = (mid - 1);
        }
        else {
            s = (mid + 1);
        }
    }

    return a2[mid];
}

void min_pair(vector<int> a1, vector<int> a2) {
    sort(a2.begin(), a2.end());
    int curr_min = 10e8, elem_left, elem_right, temp_elem_left, temp_elem_right;

    for(int i = 0; i < a1.size(); i++) {
        temp_elem_left = a1[i];
        temp_elem_right = find_lower_bound(a1[i], a2);

        if(abs(temp_elem_left - temp_elem_right) < curr_min) {
            elem_left = temp_elem_left;
            elem_right = temp_elem_right;

            curr_min = abs(temp_elem_left - temp_elem_right);
        }
    }
    cout << elem_left << " " << elem_right << endl;
}


int main() {
    vector<int> a1 = {-1, 5, 10, 20, 3, 132, 150};
    vector<int> a2 = {26, 134, 135, 15, 17};
    min_pair(a1, a2);

    return 0;
}
