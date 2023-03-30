#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int N;
	
	cin >> N;
	
	priority_queue<int> pq;
	
	for(int i=0; i<N; i++) {
	    int card;
	    cin >> card;
	    pq.push(-card);
	}
	
	long long ans = 0;
	
	while(!pq.empty()) {
	    int a = -pq.top();
	    pq.pop();
	    
	    if(pq.empty()) break;
	    
	    int b = -pq.top();
	    pq.pop();
	    
	    ans = ans + a + b;
	    
	    pq.push(-a-b);
	}
	
	cout << ans << endl;
		
	return 0;
}