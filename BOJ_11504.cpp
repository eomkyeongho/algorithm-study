#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int N;
	
	cin >> N;
	
	int A[N], B[N], inc[N], dec[N];
	
	for(int i=0; i<N; i++) {
	    cin >> A[i];
	    B[N-i-1] = A[i];
	}
	
	for(int i=0; i<N; i++) {
	    inc[i] = dec[i] = 1;
	    for(int j=0; j<i; j++) {
	        if(A[i] > A[j]) inc[i] = max(inc[i], inc[j] + 1);
	        if(B[i] > B[j]) dec[i] = max(dec[i], dec[j] + 1);
	    }
	}
	
	int ans = 0;
	
	for(int i=0; i<N; i++) {
	    ans = max(ans, inc[i] + dec[N-i-1] - 1);
	}
	
	cout << ans << endl;
		
	return 0;
}