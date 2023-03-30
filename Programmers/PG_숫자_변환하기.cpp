#include <bits/stdc++.h>

using namespace std;

int solution(int x, int y, int n) {
    int answer = -1;
    
    queue<array<int, 2>> Q;
    
    vector<bool> visited(1000000+1, false);
    
    Q.push({x, 0});
    
    while(!Q.empty()) {
        int curr = Q.front()[0];
        int level = Q.front()[1];
        Q.pop();
        
        if(curr > y) {
            continue;
        }
        
        if(visited[curr]) {
            continue;
        }
        
        if(curr == y) {
            answer = level;
            break;
        }
        
        visited[curr] = true;
        
        Q.push({curr+n, level+1});
        Q.push({curr*2, level+1});
        Q.push({curr*3, level+1});
    }
    
    return answer;
}