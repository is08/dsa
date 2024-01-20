#include<iostream>
using namespace std;

void printBoard(int n, int board[][5]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


bool possibleToPlace(int board[][5], int i, int j, int n) {
    for(int x = 0; x < i; x++) {
        if(board[x][j] == 1) {
            return false;
        }
    }
    int tempI = i, tempJ = j;

    while(tempI >= 0 && tempJ >= 0) {
        if(board[tempI][tempJ] == 1) {
            return false;
        }
        tempI--;
        tempJ--;
    }

    tempI = i, tempJ = j;
    while(tempI < n && tempJ < n) {
        if(board[tempI][tempJ] == 1) {
            return false;
        }
        tempI++;
        tempJ++;
    }

    tempI = i, tempJ = j;
    while(tempI >= 0 && tempJ < n) {
        if(board[tempI][tempJ] == 1) {
            return false;
        }
        tempI--;
        tempJ++;
    }

    tempI = i, tempJ = j;
    while(tempI < n && tempJ >= 0) {
        if(board[tempI][tempJ] == 1) {
            return false;
        }
        tempI++;
        tempJ--;
    }

    return true;
}

bool solveNQueen(int n, int board[][5], int i = 0) {
    if(i == n) {
        printBoard(n, board);
        return true;
    }

    for(int j = 0; j < n; j++) {
        if(possibleToPlace(board, i, j, n)) {
            board[i][j] = 1;
            bool successInSubset = solveNQueen(n, board, (i + 1));
            if(successInSubset) {
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}

int main() {
    int n = 4;
    int board[5][5] = {0};

    solveNQueen(n, board);
}
