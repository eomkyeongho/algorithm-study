#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;

pair<vector<int>, vector<int>> dijkstra(int start);

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin >> n >> m;
	
	adj.resize(n+1);
	
	for(int i=0; i<m; i++) {
	    int a, b, cost;
	    
	    cin >> a >> b >> cost;
	    adj[a].push_back({cost,b});
	}
	
	int start, end;
	
	cin >> start >> end;
	
	pair<vector<int>, vector<int>> ans = dijkstra(start);
	vector<int> minDist = ans.first;
	vector<int> prev = ans.second;
	
	cout << minDist[end] << endl;
	
	stack<int> S;
	
	S.push(end);
	
	int v = prev[end];
	
	while(v != start) {
	    S.push(v);
	    v = prev[v];
	}
	
	S.push(start);
	
	cout << S.size() << endl;
	
	while(!S.empty()) {
	    cout << S.top() << " ";
	    S.pop();
	}
	
	
	return 0;
}

pair<vector<int>, vector<int>> dijkstra(int start){
    vector<int> minDist(n+1, INT_MAX);
    vector<int> prev(n+1, -1);
    
    priority_queue<pair<int, int>> pq;
    
    pq.push({0,start});
    
    while(!pq.empty()) {
        int hereDist = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if(hereDist > minDist[here]) continue;
        
        for(pair<int, int> next : adj[here]) {
            int thereDist = hereDist + next.first;
            int there = next.second;
            
            if(minDist[there] > thereDist) {
                prev[there] = here;
                minDist[there] = thereDist;
                pq.push({thereDist, there});
            }
        }
    }
    
    return { minDist, prev };
}