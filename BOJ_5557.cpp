#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int N;
int num[100];
long long cache[100][21];

long long solve(int n, int k) {
    if(n == 0) {
        return num[n] == k ? 1 : 0;
    }
    
    if(k < 0 || k > 20) return 0;
    
    long long &ret = cache[n][k];
    
    if(ret != -1) return ret;
    
    ret = solve(n-1, k-num[n]) + solve(n-1, k+num[n]);
    
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	memset(cache,-1,sizeof(cache));
	
    cin >> N;
    
    for(int i=0; i<N; i++) {
        cin >> num[i];
    }
    
    cout << solve(N-2, num[N-1]) << endl;
	
	return 0;
}