#include <bits/stdc++.h>

using namespace std;

int dRow[4] = {0,0,1,-1};
int dCol[4] = {1,-1,0,0};

int N, M;

bool isOut(int row, int col) {
    return (row < 0 || row >= N || col < 0 || col >= M);
}

array<int, 2> move(vector<string> &board, int row, int col, int d) {
    int currRow = row;
    int currCol = col;
    
    while(1) {
        int nextRow = currRow + dRow[d];
        int nextCol = currCol + dCol[d];
        
        if(!isOut(nextRow, nextCol) && board[nextRow][nextCol] != 'D') {
            currRow = nextRow;
            currCol = nextCol;
        } else {
            break;
        }
    }
    
    return {currRow, currCol};
}

int solution(vector<string> board) {
    int answer = -1;
    
    N = board.size();
    M = board[0].length();
    int level[N][M];
    
    memset(level, -1, sizeof(level));
    
    queue<array<int, 2>> Q;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(board[i][j] == 'R') {
                Q.push({i,j});
                level[i][j] = 0;
                break;
            }
        }
    }
    
    while(!Q.empty()) {
        int row = Q.front()[0];
        int col = Q.front()[1];
        Q.pop();
        
        if(board[row][col] == 'G') {
            answer = level[row][col];
            break;
        }
        
        for(int i=0; i<4; i++) {
            array<int, 2> next = move(board, row, col, i);
            
            if(level[next[0]][next[1]] == -1) {
                level[next[0]][next[1]] = level[row][col] + 1;
                Q.push({next[0], next[1]});
            }
        }
    }
    
    return answer;
}