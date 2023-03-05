#include <bits/stdc++.h>

using namespace std;

int N, M;
bool visited[100][100];
int dRow[4] = {0,0,-1,1};
int dCol[4] = {1,-1,0,0};

bool isOut(int row, int col) {
    return (row < 0 || row >= N || col < 0 || col >= M);
}

int dfs(vector<string> &maps, int row, int col) {
    visited[row][col] = true;
    
    int ret = maps[row][col] - '0';
    
    for(int i=0; i<4; i++) {
        int nextRow = row + dRow[i];
        int nextCol = col + dCol[i];
        
        if(isOut(nextRow, nextCol)) {
            continue;
        }
        
        if(visited[nextRow][nextCol]) {
            continue;
        }
        
        if(maps[nextRow][nextCol] == 'X') {
            continue;
        }
        
        ret += dfs(maps, nextRow, nextCol);
    }
        
    return ret;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    N = maps.size();
    M = maps[0].length();
    
    memset(visited, false, sizeof(visited));
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            
            if(visited[i][j]) {
                continue;
            }
            
            if(maps[i][j] == 'X') {
                continue;
            }
            
            answer.push_back(dfs(maps, i, j));
        }
    }
    
    if(answer.size() == 0) {
        answer.push_back(-1);
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}