#include<iostream>
using namespace std;

long long int calcPowerModule(int a, int b, int p, long long int currVal = 1) {
    if(b == 0) {
        return currVal;
    }

    currVal = ((currVal % p) * (a % p)) % p;

    calcPowerModule(a, (b-1), p, currVal);
}

long long int powerModulo(int a, int b){
    return calcPowerModule(a, b, 1000000007);
}

int main() {
    cout << powerModulo(5, 100000) << endl;
    return 0;
}
