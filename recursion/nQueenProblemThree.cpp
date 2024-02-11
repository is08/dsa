#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<string> board) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool possibleToPlace(vector<string> board, int i, int j, int n) {
    for(int x = 0; x < i; x++) {
        if(board[x][j] == 'Q') {
            return false;
        }
    }
    int tempI = i, tempJ = j;

    while(tempI >= 0 && tempJ >= 0) {
        if(board[tempI][tempJ] == 'Q') {
            return false;
        }
        tempI--;
        tempJ--;
    }

    tempI = i, tempJ = j;
    while(tempI < n && tempJ < n) {
        if(board[tempI][tempJ] == 'Q') {
            return false;
        }
        tempI++;
        tempJ++;
    }

    tempI = i, tempJ = j;
    while(tempI >= 0 && tempJ < n) {
        if(board[tempI][tempJ] == 'Q') {
            return false;
        }
        tempI--;
        tempJ++;
    }

    tempI = i, tempJ = j;
    while(tempI < n && tempJ >= 0) {
        if(board[tempI][tempJ] == 'Q') {
            return false;
        }
        tempI++;
        tempJ--;
    }

    return true;
}

bool solveNQueen(vector<string> &board, int i, int n, int &count) {
    if(i == n) {
        count++;
    }

    for(int j = 0; j < n; j++) {
        if(possibleToPlace(board, i, j, n)) {
            board[i][j] = 'Q';
            bool possibleToSolveSubset = solveNQueen(board, (i + 1), n, count);

            if(possibleToSolveSubset) {
                return true;
            }
            board[i][j] = '.';
        }
    }
    return false;
}


int nQueen(int n){
    int count = 0;
    vector<string> board;
    for(int i = 0; i < n; i++) {
        string row(n, '.');
        board.push_back(row);
    }

    solveNQueen(board, 0, n, count);

    return count;
}

int main() {
    cout << nQueen(4)<< endl;
}
