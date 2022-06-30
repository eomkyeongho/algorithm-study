#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int cache[2001][2001];
int arr[2001];

bool solve(int a, int b);

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	memset(cache,-1,sizeof(cache));
	
	int N;
	
	cin >> N;
	
	for(int i=1; i<=N; i++) cin >> arr[i];
	
	int M;
	
	cin >> M;
	
	for(int i=0; i<M; i++) {
	    int S, E;
	    
	    cin >> S >> E;
	    
	    cout << solve(S,E) << endl;
	}
		
	return 0;
}

bool solve(int a, int b) {
    if(a == b) return true;
    if(b == a + 1) return arr[a] == arr[b];
    
    int &ret = cache[a][b];
    
    if(ret != -1) return ret;
    
    ret = (solve(a+1,b-1) && arr[a] == arr[b]);
    
    return ret;
}