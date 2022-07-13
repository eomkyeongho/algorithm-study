#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int dRow[6] = {0,0,0,0,1,-1};
int dCol[6] = {1,-1,0,0,0,0};
int dD[6] = {0,0,1,-1,0,0};

int board[100][100][100];
int N, M, H;

bool isOut(int d, int row, int col);

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	queue<array<int,3>> Q;
	
	cin >> M >> N >> H;
	
	for(int i=0; i<H; i++) {
	    for(int j=0; j<N; j++) {
	        for(int k=0; k<M; k++) {
	            cin >> board[i][j][k];
	            if(board[i][j][k] == 1) {
	                Q.push({i,j,k});
	            }
	        }
	    }
	}
	
	while(!Q.empty()) {
	    int d = Q.front()[0];
	    int row = Q.front()[1];
	    int col = Q.front()[2];
	    Q.pop();
	    
	    for(int i=0; i<6; i++) {
	        int nextD = d + dD[i];
	        int nextRow = row + dRow[i];
	        int nextCol = col + dCol[i];
	        
	        if(!isOut(nextD,nextRow,nextCol) && board[nextD][nextRow][nextCol] == 0) {
	            Q.push({nextD, nextRow, nextCol});
	            board[nextD][nextRow][nextCol] = board[d][row][col] + 1;
	        } 
	    }
	}
	
	int ans = 0;
	
	for(int i=0; i<H; i++) {
	    for(int j=0; j<N; j++) {
	        for(int k=0; k<M; k++) {
	            if(board[i][j][k] == 0) {
	                cout << -1 << endl;
	                return 0;
	            }
	            ans = max(ans, board[i][j][k]);
	        }
	    }
	}
	
	cout << ans - 1 << endl;
	
	return 0;
}

bool isOut(int d, int row, int col){
    return (d < 0 || d >= H || row < 0 || row >= N || col < 0 || col >= M);
}