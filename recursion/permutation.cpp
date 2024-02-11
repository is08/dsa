#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void findSortedPermutations(string s, int l, int r, set<string>& ans) {
    if(l == r) {
        cout << s << endl;
        ans.insert(s);
    }

    for(int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        findSortedPermutations(s, (l + 1), r, ans);
        swap(s[l], s[i]);
    }
}

int main() {
    set<string> ans;
    findSortedPermutations("acaa", 0, 3, ans);

    cout << ans.size() << endl;

    return 0;
}
