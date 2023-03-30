#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
int cost[10001];
bool visited[10001];

int dfs(int curr) {
    visited[curr] = true;
    
    int ret = cost[curr];
    
    for(int next : adj[curr]) {
        if(!visited[next]) {
            ret = min(ret, dfs(next));
        }
    }
    
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	memset(visited,false,sizeof(visited));
	
	int N, M, K;
	
	cin >> N >> M >> K;
	
	adj.resize(N+1);
	
	for(int i=1; i<=N; i++) {
	    cin >> cost[i];
	}
	
	for(int i=0; i<M; i++) {
	    int v, w;
	    cin >> v >> w;
	    
	    adj[v].push_back(w);
	    adj[w].push_back(v);
	}
	
	int need = 0;
	
	for(int i=1; i<=N; i++) {
	    if(!visited[i]) {
	        need += dfs(i);
	    }
	}
	
	if(need > K) cout << "Oh no" << endl;
	else cout << need << endl;
		
	return 0;
}