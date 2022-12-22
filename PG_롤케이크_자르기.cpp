#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    int top1[10000+1] = {0,};
    int top2[10000+1] = {0,};
    int cnt1 = 0, cnt2 = 0;
    
    for(int t : topping) {
        if(top2[t] == 0) {
            cnt2++;
        }
        top2[t]++;
    }
    
    for(int t : topping) {
        if(top1[t] == 0) {
            cnt1++;
        }
        top1[t]++;
        top2[t]--;
        if(top2[t] == 0) {
            cnt2--;
        }
        if(cnt1 == cnt2) {
            answer++;
        }
    }
    
    return answer;
}