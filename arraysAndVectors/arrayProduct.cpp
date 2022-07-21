#include<vector>
#include<iostream>
using namespace std;

vector<int> productArray(vector<int> arr){

    int n = arr.size();
    vector<int> output(n,1);

    vector<int> lr(n), rl(n);
    lr[0] = 1, rl[n - 1] = 1;

    for(int i = 1; i < n; i++){
        lr[i] = lr[i - 1] * arr[i - 1];
    }

    for(int i = (n - 2); i >= 0; i--){
        rl[i] = rl[i + 1] * arr[i + 1];
    }

    for(int i = 0; i < n; i++){
        output[i] = lr[i] * rl[i];
    }

    return output;
}


int main(){
    vector<int> arr = {1, 2, 4, 6};

    vector<int> res = productArray(arr);

    for(int elem: res){
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
