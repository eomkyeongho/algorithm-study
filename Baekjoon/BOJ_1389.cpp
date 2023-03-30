#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
bool visited[101]; 

int bfs(int start) {
    memset(visited,false,sizeof(visited));
    
    queue<pair<int, int>> Q;
    
    Q.push(make_pair(start , 0));
    
    int ret = 0;
    
    while(!Q.empty()) {
        int curr = Q.front().first;
        int dist = Q.front().second;
        Q.pop();
        
        if(visited[curr]) continue;
        
        visited[curr] = true;
        ret = ret + dist;
        
        for(int next : adj[curr]) {
            Q.push(make_pair(next, dist+1));
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int N, M; 
    
    cin >> N >> M;
    
    adj.resize(N+1);
    
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int ans, kevinMin;
    kevinMin = INT_MAX;
    
    for(int i=1; i<=N; i++) {
        int kevin = bfs(i);
        
        if(kevinMin > kevin) {
            kevinMin = kevin;
            ans = i;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}