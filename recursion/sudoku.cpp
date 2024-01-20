#include<iostream>
using namespace std;

bool possibleToPlace(int mat[][9], int num, int i, int j, int n) {
    //row
    for(int k = 0; k < n; k++) {
        if(mat[i][k] == num) {
            return false;
        }
    }

    //col
    for(int k = 0; k < n; k++) {
        if(mat[k][j] == num) {
            return false;
        }
    }

    //grid
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
            if(mat[l][m] == num) {
                return false;
            }
        }
    }

    return true;
}

void printSudoku(int mat[][9], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

bool solveSudoku(int mat[][9], int i, int j, int n) {
    if(j == n) {
        j = 0;
        i = (i + 1);
    }
    if (i == n) {
        printSudoku(mat, n);
        return true;
    }

    if(mat[i][j] == 0) {
        for(int num = 1; num <= 9; num++) {
            if(possibleToPlace(mat, num, i, j, n)) {
                mat[i][j] = num;
                //cout << "possible to place num " << num << " at " << i << " and " << j << endl;
                //printSudoku(mat, n);
                bool isSubsetSolveable = solveSudoku(mat, i, (j+1), n);
                if(isSubsetSolveable) {
                    return true;
                }
            }
        }
        mat[i][j] = 0;
        return false;
    }
    else {
        return solveSudoku(mat, i, (j+1), n);
    }
}

int main() {
    int n = 9;
    int mat[9][9] = {
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

    //printSudoku(mat, n);
    if(!solveSudoku(mat, 0, 0, n)) {
        cout << "no solution exists!!" << endl;
    }
}
