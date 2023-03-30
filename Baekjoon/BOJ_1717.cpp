#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

struct UnionFind {
	vector<int> parent;
	vector<int> rank;
	
	UnionFind(int n) {
		parent.resize(n+1,-1);
		rank.resize(n+1,0);
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
	
	for(int i=0; i<m; i++) {
		int op, a, b;
		cin >> op >> a >> b;
		if(op == 0) {
			uf.merge(a,b);
		} else {
			if(uf.getRoot(a) == uf.getRoot(b)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}