#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int n, m, k;
int visited[1001];
vector<vector<pair<int, int>>> adj;

vector<int> dijkstra(int start);

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin >> n >> m >> k;
	
	adj.resize(n+1);
	
	for(int i=0; i<m; i++) {
	    int a, b, c;
	    cin >> a >> b >> c;
	    
	    adj[a].push_back({c, b}); 
	}
	
	memset(visited,0,sizeof(visited));
	
	vector<int> k_minDist = dijkstra(1);
	
	for(int i=1; i<=n; i++) {
	    cout << k_minDist[i] << endl;
	}
	
	return 0;
}

vector<int> dijkstra(int start) {
    vector<int> k_minDist(n+1, -1);
    vector<priority_queue<int>> minDist(n+1);
    
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    
    while(!pq.empty()) {
        int hereDist = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        visited[here]++;
        
        if(visited[here] == k) {
            k_minDist[here] = hereDist;
        }
        
        for(pair<int, int> next : adj[here]) {
            int thereDist = hereDist + next.first;
            int there = next.second;
            
            if(visited[there] < k) {
                if(minDist[there].size() == k) {
                    int maxDist = minDist[there].top();
                    
                    if(maxDist < thereDist) {
                        continue;
                    } else {
                        minDist[there].pop();
                    }
                }
                minDist[there].push(thereDist);
                pq.push({-thereDist, there});
            }
        }
    }
    
    return k_minDist;
}