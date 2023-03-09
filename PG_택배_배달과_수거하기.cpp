#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    stack<int> d, p;
    
    for(int i=0; i<n; i++) {
        d.push(deliveries[i]);
        p.push(pickups[i]);
    }
    
    while(!d.empty() && d.top() == 0) {
        d.pop();
    }
    while(!p.empty() && p.top() == 0) {
        p.pop();
    }
    
    while(!d.empty() || !p.empty()) {
        answer += 2 * max(d.size(), p.size());

        int box = cap;
        
        while(!d.empty() && box >= 0) {
            box -= d.top();
            d.pop();
            if(box < 0) {
                d.push(-box);
            }
        }

        box = cap;
        
        while(!p.empty() && box >= 0) {
            box -= p.top();
            p.pop();
            if(box < 0) {
                p.push(-box);
            }
        }
    }
    
    return answer;
}