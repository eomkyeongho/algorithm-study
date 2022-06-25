#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

struct UnionFind {
	vector<int> parent;
	vector<int> rank;
	
	UnionFind(int n) {
		parent.resize(n,-1);
		rank.resize(n,0);
	}
	
	int getRoot(int n) {
		if(parent[n] == -1) return n;
		else return getRoot(parent[n]);
	}
	
	void merge(int n, int m) {
		int r1 = getRoot(n);
		int r2 = getRoot(m);

		if(r1 == r2) return;
		
		if(rank[r1] < rank[r2]) swap(r1, r2);
		
		parent[r2] = r1;
		
		if(rank[r1] == rank[r2]) rank[r1]++;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N, M;
	
	cin >> N >> M;
	
	UnionFind uf(N+1);
	
	vector<pair<int, pair<int, int>>> cost(M);
	
	for(int i=0; i<M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		cost[i] = make_pair(c, make_pair(a, b));
	}
	
	sort(cost.begin(), cost.end());
	
	int ans = 0;
	
	for(auto it : cost) {
		int a = it.second.first;
		int b = it.second.second;
		
		if(uf.getRoot(a) != uf.getRoot(b)) {
			uf.merge(a, b);
			ans = ans + it.first;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}