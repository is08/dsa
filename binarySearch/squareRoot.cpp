#include<iostream>
using namespace std;

float square_root(int n, int p) {
    int s = 0, e = n, mid;
    float ans;

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

    int divisor = 10;
    while(p--) {
        float temp;

        for(int i = 0; i < 10; i++) {
            temp = (ans + (float)i / divisor);

            if((temp * temp) <= n) {
                ans = temp;
            }
        }
        divisor *= 10;
        cout << "ans " << ans << endl;
    }

    return ans;
}

int main() {
    cout << square_root(10, 4);

    return 0;
}
