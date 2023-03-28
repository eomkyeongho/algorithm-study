#include <bits/stdc++.h>

using namespace std;

vector<int> result(11);
int gap = 0;

void solve(int n, vector<int> &info, vector<int> &lion) {
    if(lion.size() == info.size()) {
        if(n > 0) {
            lion[10] += n;
        }
        
        int g = 0;
        for(int i=0; i<=10; i++) {
            if(info[i] >= lion[i] && info[i] > 0) {
                g -= 10 - i;
            } else if(lion[i] > info[i] && lion[i] > 0){
                g += 10 - i;
            }
        }
        if(g >= gap) {
            bool flag = true;
            
            if(g == gap) {
                for(int i=10; i>=0; i--) {
                    if(result[i] == lion[i]) {
                        continue;
                    } else {
                        if(result[i] > lion[i]) {
                            flag = false;
                        }
                        break;
                    }
                }
            }
            
            if(flag) {
                for(int i=0; i<=10; i++) {
                    result[i] = lion[i];
                }
                gap = g;
            }
        }
        return;
    }
    
    int size = lion.size();
    
    if(info[size] < n) {
        lion.push_back(info[size]+1);
        solve(n - info[size] - 1, info, lion);
        lion.pop_back();
    }
    lion.push_back(0);
    solve(n, info, lion);
    lion.pop_back();
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> lion;
    
    solve(n, info, lion);
    
    if(gap > 0) {
        answer = result;
    } else {
        answer.push_back(-1);
    }
    
    return answer;
}