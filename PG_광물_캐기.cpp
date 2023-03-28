#include <bits/stdc++.h>

using namespace std;

int cost[3][3] = {{1,1,1}, {5,1,1}, {25,5,1}};

int solve(vector<int> &picks, vector<string> &minerals, int n) {
    if(n >= minerals.size()) {
        return 0;
    }
    
    int ret = 0;
    
    for(int i=0; i<3; i++) {
        if(picks[i] == 0) continue;
        
        if(ret == 0) ret = INT_MAX;
        
        int c = 0;
        
        for(int j=0; j<5; j++) {
            if(n+j >= minerals.size()) break;
                
            int m;
            
            if(minerals[n+j] == "diamond") {
                m = 0;
            } else if(minerals[n+j] == "iron") {
                m = 1;
            } else {
                m = 2;
            }
            
            c += cost[i][m];
        }
        
        picks[i] -= 1;
        ret = min(c + solve(picks, minerals, n+5), ret);
        picks[i] += 1;
    }
    
    return ret;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    answer = solve(picks, minerals, 0);
        
    return answer;
}