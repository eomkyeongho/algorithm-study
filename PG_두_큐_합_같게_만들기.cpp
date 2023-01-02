#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long s1 = 0, s2 = 0;
    queue<int> q1, q2;
    
    for(int n : queue1) {
        s1 += n;
        q1.push(n);
    }
    
    for(int n : queue2) {
        s2 += n;
        q2.push(n);
    }
    
    if((s1 + s2) % 2 != 0) return -1;
    
    long long mid = (s1 + s2) / 2;
    int limit = 2*(queue1.size() + queue2.size());
    
    while(answer <= limit) {
        if(s1 > mid) {
            q2.push(q1.front());
            s1 -= q1.front();
            s2 += q1.front();
            q1.pop();
            answer++;
        } else if(s2 > mid) {
            q1.push(q2.front());
            s2 -= q2.front();
            s1 += q2.front();
            q2.pop();
            answer++;
        } else {
            break;
        }
    }
    
    answer = (answer <= limit) ? answer : -1;
    
    return answer;
}