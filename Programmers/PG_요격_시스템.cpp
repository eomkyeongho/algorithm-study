#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end());
    
    for(int i=0; i<targets.size(); i++) {
        targets[i][0] *= 2;
        targets[i][1] *= 2;
    }
    
    for(int i=0; i<targets.size(); i++) {
        int e = targets[i][1];
        
        while(i + 1 < targets.size()) {
            if(targets[i+1][0] < e) {
                i++;
                e = min(e, targets[i][1]);
            } else {
                break;
            }
        }
        answer++;
    }
    
    return answer;
}