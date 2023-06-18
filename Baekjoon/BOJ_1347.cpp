#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    string s;
    
    cin >> n >> s;
    
    int dRow[4] = {1,0,-1,0};
    int dCol[4] = {0,-1,0,1};
    int d = 0;
    
    int board[100][100];
    int r = 49, c = 49;
    
    memset(board, 0, sizeof(board));
    board[r][c] = 1;
    
    for(int i=0; i<n; i++) {
        switch(s[i]) {
            
            case 'R': 
                d = (d + 1) % 4; 
                break;
                
            case 'L': 
                d = (d - 1 + 4) % 4; 
                break;
                
            case 'F': 
                r += dRow[d]; 
                c += dCol[d];
                board[r][c] = 1;
                break;
        }
    }
    
    int sRow = 99, eRow = 0, sCol = 99, eCol = 0;
    
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            if(board[i][j] == 1) {
                sRow = min(sRow, i);
                eRow = max(eRow, i);
                sCol = min(sCol, j);
                eCol = max(eCol, j);
            }
        }
    }
    
    for(int i=sRow; i<=eRow; i++) {
        for(int j=sCol; j<=eCol; j++) {
            cout << (board[i][j] == 1 ? '.' : '#');
        }
        cout << endl;
    }
}