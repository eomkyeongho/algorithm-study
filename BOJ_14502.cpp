#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int dfs(int row, int col);
void solve(array<int, 3> wall);
bool isOut(int row, int col);

int dRow[4] = {0,0,1,-1};
int dCol[4] = {1,-1,0,0};
vector<pair<int, int>> virus;
int board[8][8];
bool visited[8][8];
int N, M;
int ans;
int safe;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin >> N >> M;
	
	for(int i=0; i<N; i++) {
	    for(int j=0; j<M; j++) {
	        cin >> board[i][j];
	        
	        if(board[i][j] == 0) safe++;
	        if(board[i][j] == 2) virus.push_back(make_pair(i,j));
	    }
	}
	
	for(int i=1; i<=N*M; i++) {
	    for(int j=i+1; j<=N*M; j++) {
	        for(int k=j+1; k<=N*M; k++) {
	            solve({i, j, k});
	        }
	    }
	}
	
	cout << ans << endl;
		
	return 0;
}

int dfs(int row, int col) {
    int ret = 1;
    
    visited[row][col] = true;
    
    for(int i=0; i<4; i++) {
        int nextRow = row + dRow[i];
        int nextCol = col + dCol[i];
        
        if(!isOut(nextRow, nextCol) && !visited[nextRow][nextCol] && board[nextRow][nextCol] == 0) {
            ret = ret + dfs(nextRow, nextCol);
        }
    }
    
    return ret;
}

void solve(array<int, 3> wall) {
    int row[3], col[3];
    
    for(int i=0; i<3; i++) {
        row[i] = (wall[i]-1) / M;
        col[i] = (wall[i]-1) % M;
        
        if(board[row[i]][col[i]] != 0) return;
    }
    
    for(int i=0; i<3; i++) {
        board[row[i]][col[i]] = 1;
    }
    
    memset(visited,false,sizeof(visited));
    
    int v = 0;
    
    for(pair<int, int> p : virus) {
        v = v + dfs(p.first, p.second) - 1;
    }
    
    ans = max(ans, safe - v - 3);
    
    for(int i=0; i<3; i++) {
        board[row[i]][col[i]] = 0;
    }
}

bool isOut(int row, int col) {
    return (row < 0 || row >= N || col < 0 || col >= M);
}