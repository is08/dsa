#include<iostream>
#include<vector>
using namespace std;

void printSudoku(vector<vector<int>> input) {
    for(int i = 0; i < input.size(); i++) {
        for(int j = 0; j < input[i].size(); j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
}

bool possibleToPlace(vector<vector<int>> problem, int num, int i, int j, int n) {
    // col
    for(int x = 0; x < n; x++) {
        if(problem[x][j] == num) {
            return false;
        }
    }

    // row
    for(int y = 0; y < n; y++) {
        if(problem[i][y] == num) {
            return false;
        }
    }

    // grid
    int lowerI = -1, higherI = -1, lowerJ = -1, higherJ = -1;
    if(j >= 0 && j <= 2) {
        if(i >= 0 && i <= 2) {
            lowerI = 0;
            higherI = 2;
            lowerJ = 0;
            higherJ = 2;
        }
        else if(i >= 3 && i <= 5) {
            lowerI = 3;
            higherI = 5;
            lowerJ = 0;
            higherJ = 2;
        }
        else if(i >= 6 && i <= 8) {
            lowerI = 6;
            higherI = 8;
            lowerJ = 0;
            higherJ = 2;
        }
    }
    else if(j >= 3 && j <= 5) {
        if(i >= 0 && i <= 2) {
            lowerI = 0;
            higherI = 2;
            lowerJ = 3;
            higherJ = 5;
        }
        else if(i >= 3 && i <= 5) {
            lowerI = 3;
            higherI = 5;
            lowerJ = 3;
            higherJ = 5;
        }
        else if(i >= 6 && i <= 8) {
            lowerI = 6;
            higherI = 8;
            lowerJ = 3;
            higherJ = 5;
        }
    }
    else if(j >= 6 && j <= 8) {
        if(i >= 0 && i <= 2) {
            lowerI = 0;
            higherI = 2;
            lowerJ = 6;
            higherJ = 8;
        }
        else if(i >= 3 && i <= 5) {
            lowerI = 3;
            higherI = 5;
            lowerJ = 6;
            higherJ = 8;
        }
        else if(i >= 6 && i <= 8) {
            lowerI = 6;
            higherI = 8;
            lowerJ = 6;
            higherJ = 8;
        }
    }

    for(int l = lowerI; l <= higherI; l++) {
        for(int m = lowerJ; m <= higherJ; m++) {
            if(problem[l][m] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(vector<vector<int>> &problem, int i, int j, int n) {
    if(j == n) {
        j = 0;
        i = (i + 1);
    }
    if(i == n) {
        return true;
    }

    if(problem[i][j] == 0) {
        for(int num = 1; num <= 9; num++) {
            if(possibleToPlace(problem, num, i, j, n)) {
                problem[i][j] = num;
                bool isSubsetSolveable = solveSudoku(problem, i, (j + 1), n);
                if(isSubsetSolveable) {
                    return true;
                }
            }
        }
        problem[i][j] = 0;
        return false;
    }
    else{
        solveSudoku(problem, i, (j + 1), n);
    }
}

vector<vector<int>> solveSudoku(vector<vector<int>> problem){
    solveSudoku(problem, 0, 0, 9);
    return problem;
}

int main() {
    vector<vector<int>> problem =
    {
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
    };

    solveSudoku(problem);

    return 0;
}
