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
	
	int n, m;
	
	cin >> n >> m;
	
	UnionFind uf(n);
	
	int ans = 0;
	
	for(int i=0; i<m; i++) {
	    int a, b;
	    cin >> a >> b;
	    
	    
	    if(uf.getRoot(a) == uf.getRoot(b)) {
	        ans = i+1;
	        break;
	    }
	    
	    uf.merge(a,b);
	}
	
	cout << ans << endl;
		
	return 0;
}