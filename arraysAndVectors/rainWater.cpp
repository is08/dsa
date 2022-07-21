#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int trappedWater(vector<int> heights){
    int tempMax = -1;

    if(heights.size() <= 2){
        return 0;
    }

    /*
    alternate code

    vector<int> lr(heights.size(), 0), rl(heights.size(), 0);
    lr[0] = heights[0];
    rl[heights.size() - 1] = heights[heights.size() - 1];

    for(int i = 1; i < heights.size() ; i++){
        lr[i] = max(lr[i - 1], heights[i]);
        rl[i] = max(rl[n - i], heights[n - i - 1]);
    }
    */

    vector<int> LR, RL;

    for(int i = 0; i < heights.size(); i++){
        tempMax = max(tempMax, heights[i]);
        LR.push_back(tempMax);
    }

    tempMax = -1;

    for(int i = heights.size() - 1; i >= 0; i--){
        tempMax = max(tempMax, heights[i]);
        RL.push_back(tempMax);
    }

    reverse(RL.begin(), RL.end());

    int water = 0;

    for(int i = 0; i < heights.size(); i++){
        water += min(LR[i], RL[i]) - heights[i];
    }

    return water;
}


int main(){
    vector<int> water = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trappedWater(water) << "\n";

    return 0;
}
