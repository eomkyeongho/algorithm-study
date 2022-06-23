#include <bits/stdc++.h>

using namespace std;

class UnionFind {
public:
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
	
	void unionTwo(int n, int m) {
		if(isSameSet(n, m)) return;
		
		int r1 = getRoot(n);
		int r2 = getRoot(m);
		
		if(rank[r1] > rank[r2]) {
			parent[r2] = r1;
		} else {
			parent[r1] = r2;
			if(rank[r1] == rank[r2]) rank[r2]++;
		}
	}
	
	bool isSameSet(int n, int m) {
		return getRoot(n) == getRoot(m) ? true : false; 
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
			uf.unionTwo(a,b);
		} else {
			if(uf.isSameSet(a,b)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}