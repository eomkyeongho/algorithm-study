#include <bits/stdc++.h>

using namespace std;

map<string, int> ten_days;

bool check_discount(vector<string> want, vector<int> number) {
    for(int i=0; i<want.size(); i++) {
        if(ten_days[want[i]] != number[i]) {
            return false;
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for(int i=0; i<discount.size(); i++) {
        if(ten_days.find(discount[i]) == ten_days.end()) {
            ten_days[discount[i]] = 1;
        } else {
            ten_days[discount[i]]++;
        }
        
        if(i >= 10) {
            ten_days[discount[i-10]]--;
        }
        
        if(check_discount(want,number)) {
            answer++;
        }
    }
    
    return answer;
}