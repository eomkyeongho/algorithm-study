#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    sort(weights.begin(), weights.end());
    for(int i=0; i<weights.size(); i++) {
        weights[i] *= 24;    
    }
    
    double torque[4] = {1, 3/2.0, 4/3.0, 2};
    
    for(int i=0; i<weights.size(); i++) {
        int w = weights[i];
        for(int j=0; j<4; j++) {
            int s = (int)(lower_bound(weights.begin() + i + 1, weights.end(), w*torque[j]) - weights.begin());
            if(s < weights.size() && weights[s] == w*torque[j]) {
                int e = (int)(upper_bound(weights.begin() + i, weights.end(), w*torque[j]) - weights.begin());
                answer += e - s;
            }
        }
    }
    
    return answer;
}