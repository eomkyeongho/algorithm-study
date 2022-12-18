#include <bits/stdc++.h>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    priority_queue<int> pq;
    
    for(int e : enemy) {
        if(n >= e) {
            n = n - e;
            pq.push(e);
            answer++;
        } else { 
            if(k == 0) break;

            if(!pq.empty() && e < pq.top()){
                n = n + pq.top() - e;
                pq.pop();
                pq.push(e);
            }
        
            k = k - 1;
            answer++;
        }
    }
    
    return answer;
}