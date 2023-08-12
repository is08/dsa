#include<iostream>
using namespace std;

float square_root(int n, int p) {
    int s = 0, e = n, mid;
    float ans;

    // finding the integer part
    while(s <= e) {
        mid = (s + e) / 2;

        if((mid*mid) == n) {
            return mid;
        }
        else if((mid * mid) < n) {
            ans = mid;
            s = (mid + 1);
        }
        else {
            e = (mid - 1);
        }
    }

    // finding the decimal part
    int divisor = 10;
    while(p--) {
        float temp2;
        for(int i = 0; i < 10; i++) {
            float temp = (ans + ((float)i / divisor));

            if((temp * temp) <= n) {
                temp2 = temp;
            }
        }
        divisor *= 10;
        ans = temp2;
    }

    return ans;
}

int main() {
    cout << square_root(10, 5);

    return 0;
}
