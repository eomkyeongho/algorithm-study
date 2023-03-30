#include <bits/stdc++.h>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int index = 0;
    
    while(index < section.size()) {
        int start = section[index];
            
        while(index + 1 < section.size() && start + m > section[index + 1]) {
            index++;
        }
        
        index++;
        answer++;
    }
    
    return answer;
}