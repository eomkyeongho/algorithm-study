#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int T;
    
    cin >> T;
    
    while(T--) {
        int k;
        priority_queue<long long> minpq, maxpq;
        map<long long, int> m;
        
        cin >> k;
        
        for(int i=0; i<k; i++) {
            char cmd;
            long long n;
            
            cin >> cmd >> n;
            
            if(cmd == 'I') {
                minpq.push(-n);
                maxpq.push(n);
                if(m.find(n) == m.end()) {
                    m[n] = 1;
                } else {
                    m[n]++;
                }
            } else {
                if(n == 1){
                    while(!maxpq.empty() && m[maxpq.top()] == 0) {
                        maxpq.pop();
                    }
                    if(!maxpq.empty()) {
                        m[maxpq.top()]--;
                        maxpq.pop();
                    }
                } else {
                    while(!minpq.empty() && m[-minpq.top()] == 0) {
                        minpq.pop();
                    }
                    if(!minpq.empty()) {
                        m[-minpq.top()]--;
                        minpq.pop();
                    }
                }
            }
        }
        
        while(!maxpq.empty() && m[maxpq.top()] == 0) {
            maxpq.pop();
        }
        
        if(!maxpq.empty()) {
            cout << maxpq.top() << " ";
            while(!minpq.empty() && m[-minpq.top()] == 0) {
                minpq.pop();
            }
            cout << -minpq.top() << endl;
        } else {
            cout << "EMPTY\n";
        }
    }
}