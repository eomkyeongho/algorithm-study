#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int N;
	
	cin >> N;
	
	int tri[500][500];
	int route[500][500];
	
	for(int i=0; i<N; i++) {
	    for(int j=0; j<=i; j++) {
	        cin >> tri[i][j];
	    }
	}
	
	route[0][0] = tri[0][0];
	
	for(int i=1; i<N; i++) {
	    for(int j=0; j<=i; j++) {
	        if(j == 0) {
	            route[i][j] = route[i-1][j] + tri[i][j];
	            continue;
	        }
	        if(j == i) {
	            route[i][j] = route[i-1][j-1] + tri[i][j];
	            continue;
	        }
	        route[i][j] = max(route[i-1][j], route[i-1][j-1]) + tri[i][j];
	    }
	}
	
	int ans = 0;
	
	for(int i=0; i<N; i++) {
	    ans = max(ans, route[N-1][i]);
	}
	
	cout << ans << endl;
	
	return 0;
}