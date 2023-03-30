#include <bits/stdc++.h>

using namespace std;

bool CheckRowSuccess(vector<string> &board, int col) {
    bool ret = true;
    char c = board[0][col];
    
    for(int i=1; i<3; i++) {
        if(c != board[i][col]) {
            ret = false;
        }
    }
    return ret;
}

bool CheckColSuccess(vector<string> &board, int row) {
    bool ret = true;
    char c = board[row][0];
    
    for(int i=1; i<3; i++) {
        if(c != board[row][i]) {
            ret = false;
        }
    }
    return ret;
}

bool CheckCrossSuccess(vector<string> &board) {
    bool ret = false;
    char c = board[1][1];
    
    if(board[0][0] == c && board[2][2] == c) {
        ret = true;
    } else if(board[0][2] == c && board[2][0] == c) {
        ret = true;
    }
    
    return ret;
}

int solution(vector<string> board) {
    int answer = 1;
    int diff = 0;
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == 'O') diff++;
            else if(board[i][j] == 'X') diff--;
        }
    }
    
    if(diff != 0 && diff != 1) {
        answer = 0;
    } else {
        map<char, bool> win;

        win['O'] = win['X'] = false;

        for(int i=0; i<3; i++) {
            if(CheckColSuccess(board, i)) {
                win[board[i][0]] = true;
            }

            if(CheckRowSuccess(board, i)) {
                win[board[0][i]] = true;
            }
        }

        if(CheckCrossSuccess(board)) {
            win[board[1][1]] = true;
        }

        if(win['O'] && diff != 1) {
            answer = 0;
        } else if(win['X'] && diff != 0) {
            answer = 0;
        }
    }
    
    return answer;
}