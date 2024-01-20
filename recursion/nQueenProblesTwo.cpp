#include<iostream>
#include<vector>
using namespace std;

void printBoard(vector<string> board) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isPossibleToPlace(vector<string> board, int i, int j, int n) {
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
    while(tempI < n && tempJ >= 0) {
        if(board[tempI][tempJ] == 'Q') {
            return false;
        }
        tempI++;
        tempJ--;
    }

    tempI = i, tempJ = j;
    while(tempI >= 0 && tempJ < n) {
        if(board[tempI][tempJ] == 'Q') {
            return false;
        }
        tempI--;
        tempJ++;
    }

    return true;
}

bool solveNQueens(vector<vector<string>> ans, vector<string> &board, int n, int i = 0) {
    if(i == n) {
        printBoard(board);
        cout << endl;
        ans.push_back(board);
    }

    for(int j = 0; j < n; j++) {
        if(isPossibleToPlace(board, i, j, n)) {
            board[i][j] = 'Q';
            bool isSucessfullInSubset = solveNQueens(ans, board, n, (i + 1));
            if(isSucessfullInSubset) {
                return true;
            }
            board[i][j] = '.';
        }
    }

    return false;
}


vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board;

    for(int i = 0; i < n; i++) {
        string row(n, '.');
        board.push_back(row);
    }

    solveNQueens(ans, board, n);

    return ans;
}

int main() {
    vector<vector<string>> ans = solveNQueens(4);
}
