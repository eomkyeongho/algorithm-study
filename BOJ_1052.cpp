#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int N, K;
    
    cin >> N >> K;
    
    int a = 1;
    
    while(a * 2 <= N) a = a * 2;
    
    priority_queue<int> pq;
    
    while(a > 0) {
        if(N >= a) {
            pq.push(-a);
            N = N - a;
        }
        a = a/2;
    }
    
    int ans = 0;
    
    while(pq.size() > K) {
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();
        ans = ans + b - a;
        pq.push(-2*b);
    }
    
    cout << ans << endl;
    
    return 0;
}