#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int mu[1000000];

void SetMu() {
    mu[1] = 1;
    
    for(int i=1; i<=1000000; i++) {
        for(int j=2*i; j<=1000000; j+= i) {
            mu[j] -= mu[i];
        }
    }
}

long long SquareFree(long long n) { // n이하의 정수 중 square free한 정수의 개수
    long long ret = 0;
    
    for(long long i=1; i * i <= n; i++) {
        ret += mu[i] * (n / (i*i));
    }
    
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	SetMu();
	
	int K;
	
	cin >> K;
	
	long long left = K, right = 2 * K, ans;
	
	while(left <= right) {
	    long long mid = (left+right) / 2;
	    
	    if(SquareFree(mid) >= K) {
	        right = mid - 1;
	        ans = mid;
	    } else {
	        left = mid + 1;
	    }
	}
	
	cout << ans << endl;
	
	return 0;
}