#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, R;
    
    cin >> N >> M >> R;
    
    vector<int> ans(N + 1, 0);
    vector<vector<int>> adj(N + 1);
    
    for(int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=1; i<=N;i ++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    queue<int> Q;
    vector<bool> visited(N+1, false);
    int seq = 0;
    
    Q.push(R);
    visited[R] = true;
    
    while(!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        ans[curr] = ++seq;
        
        for(int next : adj[curr]) {
            if(!visited[next]) {
                Q.push(next);
                visited[next] = true;
            }
        }
    }
    
    for(int i=1; i<=N; i++) {
        cout << ans[i] << endl;
    }
}