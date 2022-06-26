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
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			int con;
			cin >> con;
			if(con == 1) uf.merge(i,j);
		}
	}
	
	vector<int> route(M);
	
	for(int i=0; i<M; i++) {
		cin >> route[i];
	}
	
	for(int i=0; i<M; i++) {
		if(uf.getRoot(route[0]) != uf.getRoot(route[i])) {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
	return 0;
		
	return 0;
}