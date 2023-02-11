#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<unordered_map>

using namespace std;

typedef struct {
    int row;
    int col;
} Cell;

int r,c;

void floodFill(vector<string>& board, int row, int col) {
    if(board[row][col] != '.') {
        return;
    }
    
    board[row][col] = '+';

    if(row > 0) {
        floodFill(board, row-1, col);
    }
    if(row < r-1) {
        floodFill(board, row+1, col);
    }

    if(col > 0) {
        floodFill(board,  row, col-1);
    }
    if(col < c-1) {
        floodFill(board, row,  col+1);
    }

}

int main() {
    cin >> r >> c;
    vector<string> board;
    for(int i = 0 ; i < r; i++) {
        string s;
        cin >> s;
        board.push_back(s);
    }
    int count = 0;
    for(int i = 0; i < r; i++) {
        for(int j =0; j < c; j++) {
            if(board[i][j] == '.') {
                floodFill(board,i,j);
                
                count ++;
            }
        }
    }
    
    cout << count << endl;
    // for(int i = 0; i < r; i++) {
    //     for(int j =0; j < c; j++) {
    //         cout << board[i][j];
    //     }
    //     cout << endl;
    // }

}
