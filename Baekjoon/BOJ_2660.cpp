#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int N;
vector<vector<int>> adj;

int bfs(int start) {
    vector<int> level(N + 1, -1);
    int score = 0;
    
    queue<int> Q;
    Q.push(start);
    level[start] = 0;
    
    while(!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        
        score = max(score, level[curr]);
        
        for(int next : adj[curr]) {
            if(level[next] == -1) {
                level[next] = level[curr] + 1;
                Q.push(next);
            }
        }
    }
    
    return score;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    adj.resize(N+1);
    
    while(true) {
        int u, v;
        
        cin >> u >> v;
        
        if(u == -1 && v == -1) {
            break;
        }
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<vector<int>> ans(N+1);
    
    for(int i=1; i<=N; i++) {
        int score = bfs(i);
        
        ans[score].push_back(i);
    }
    
    for(int i=1; i<=N; i++) {
        if(ans[i].size() == 0) {
            continue;
        }
        
        cout << i << " " << ans[i].size() << endl;
        for(int n : ans[i]) {
            cout << n << " ";
        }
        
        break;
    }
}