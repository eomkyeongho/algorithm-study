#include <bits/stdc++.h>

using namespace std;

int N, M;

bool isOut(int row, int col) {
    return (row < 0 || row >= N || col < 0 || col >= M);
}

int bfs(vector<string> &maps, array<int, 2> s, array<int, 2> e) {
    int level[N][M];
    memset(level, -1, sizeof(level));
    
    int dRow[4] = {0,0,1,-1};
    int dCol[4] = {1,-1,0,0};
    
    queue<array<int, 2>> Q;
    
    Q.push({s[0],s[1]});
    level[s[0]][s[1]] = 0;
    
    while(!Q.empty()) {
        int row = Q.front()[0];
        int col = Q.front()[1];
        Q.pop();
        
        if(row == e[0] && col == e[1]) {
            break;
        }
        
        for(int i=0; i<4; i++) {
            int nextRow = row + dRow[i];
            int nextCol = col + dCol[i];
            
            if(isOut(nextRow, nextCol)) {
                continue;
            }
            
            if(level[nextRow][nextCol] != -1) {
                continue;
            }
            
            if(maps[nextRow][nextCol] == 'X') {
                continue;
            }
            
            level[nextRow][nextCol] = level[row][col] + 1;
            Q.push({nextRow, nextCol});
        }
    }
    
    return level[e[0]][e[1]];
}

int solution(vector<string> maps) {
    int answer = 0;
    
    N = maps.size();
    M = maps[0].length();
    
    array<int, 2> S, L, E;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(maps[i][j] == 'L') {
                L[0] = i;
                L[1] = j;
            } else if(maps[i][j] == 'E') {
                E[0] = i;
                E[1] = j;
            } else if(maps[i][j] == 'S') {
                S[0] = i;
                S[1] = j;
            }
        }
    }
    
    int dist1 = bfs(maps, {S[0], S[1]},{L[0], L[1]});
    int dist2 = bfs(maps, {L[0], L[1]},{E[0], E[1]});
    
    if(dist1 == -1 || dist2 == -1) {
        return -1;
    }
    
    answer = dist1 + dist2;
    
    return answer;
}