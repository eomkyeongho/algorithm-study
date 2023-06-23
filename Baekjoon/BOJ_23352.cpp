#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int N, M;
int ansDist = 0, ans = 0;
int board[50][50];

bool isOut(int row, int col) {
    return (row < 0 || row >= N || col < 0 || col >= M);
}

void bfs(int row, int col) {
    queue<array<int, 2>> Q;
    int level[N][M];
    
    memset(level, -1, sizeof(level));
    
    Q.push({row, col});
    level[row][col] = 0;
    
    int dRow[4] = {0,0,-1,1};
    int dCol[4] = {1,-1,0,0};
    
    while(!Q.empty()) {
        int currRow = Q.front()[0];
        int currCol = Q.front()[1];
        Q.pop();
        
        if(level[currRow][currCol] > 0 && level[currRow][currCol] == ansDist) {
            ans = max(ans, board[row][col] + board[currRow][currCol]);
        } else if(level[currRow][currCol] > ansDist) {
            ans = board[row][col] + board[currRow][currCol];
            ansDist = level[currRow][currCol];
        }
        
        for(int i=0; i<4; i++) {
            int nextRow = currRow + dRow[i];
            int nextCol = currCol + dCol[i];
            
            if(isOut(nextRow, nextCol)) {
                continue;
            }
            
            if(board[nextRow][nextCol] == 0) {
                continue;
            }
            
            if(level[nextRow][nextCol] == -1) {
                level[nextRow][nextCol] = level[currRow][currCol] + 1;
                Q.push({nextRow, nextCol});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(board[i][j] != 0) {
                bfs(i,j);
            }
        }
    }
    
    cout << ans << endl;
}