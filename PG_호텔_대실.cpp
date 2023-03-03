#include <bits/stdc++.h>

using namespace std;

int TimeToInt(string t) {
    int ret = 0;
    
    ret += stoi(t.substr(0,2)) * 60;
    ret += stoi(t.substr(3,2));
    
    return ret;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<array<int, 2>> bookTime;
    
    for(vector<string> bt : book_time) {
        bookTime.push_back({TimeToInt(bt[0]), TimeToInt(bt[1]) + 10});
    }
    sort(bookTime.begin(), bookTime.end());
    
    priority_queue<array<int, 2>> pq;
    
    for(array<int, 2> bt : bookTime) {
        int start = bt[0];
        int end = bt[1];
        
        while(!pq.empty() && start >= -pq.top()[0]) {
            pq.pop();
        }
        
        pq.push({-end, -start});
        answer = max(answer, (int)pq.size());
    }
    
    return answer;
}