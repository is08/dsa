#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMaxMinDistance(vector<int> nests, int numOfBirds, int numOfNests) {
    int ans, s = 0, e = (nests[nests.size() - 1] - nests[0]), mid;

    while(s <= e) {
        mid = (s + e) / 2;

        int found = 1, curr = 0;

        for(int i = 1; i < nests.size(); i++) {
            if((nests[i] - nests[curr]) >= mid) {
                curr = i;
                found++;
            }
        }

        if(found >= numOfBirds) {
            ans = mid;
            s = (mid + 1);
        }
        else{
            e = (mid - 1);
        }
    }

    return ans;
}

int main() {
    vector<int> nests = {1, 2, 4, 8, 9};
    sort(nests.begin(), nests.end());
    int numOfNests = 5;
    int numOfBirds = 3;

    cout << findMaxMinDistance(nests, numOfBirds, numOfNests) << endl;
    return 0;
}
