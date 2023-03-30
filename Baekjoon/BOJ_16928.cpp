#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int N, M;
	
	cin >> N >> M;
	
	vector<int> board(101, -1);
	
	for(int i=0; i<N + M; i++) {
	    int start, end;
	    
	    cin >> start >> end;
	    
	    board[start] = end;
	}
	
	vector<int> level(101,-1);
	
	queue<int> Q;
	
	Q.push(1);
	level[1] = 0;
	
	while(!Q.empty()) {
	    int curr = Q.front();
	    Q.pop();
	    
	    if(curr == 100) {
	        cout << level[curr] << endl;
	        
	        return 0;
	    }
	    
	    for(int i=1; i<=6; i++) {
	        int next = curr + i;
	        
	        if(next > 100) break;
	        
	        if(board[next] != -1) {
	            next = board[next];
	        }
	        
	        if(level[next] == -1) {
	            Q.push(next);
	            level[next] = level[curr] + 1;
	        }
	    }
	}
	
	return 0;
}