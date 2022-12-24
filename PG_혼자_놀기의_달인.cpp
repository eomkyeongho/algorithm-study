#include <bits/stdc++.h>

using namespace std;

bool visited[100+1];

int dfs(int curr, vector<int> cards) {
    int ret = 1;
    
    visited[curr] = true;
    
    if(!visited[cards[curr-1]]) {
        ret = ret + dfs(cards[curr-1], cards);
    }
    
    return ret;
}

int solution(vector<int> cards) {
    int answer = 0;
    vector<int> numbers;
    
    memset(visited,false,sizeof(visited));
    
    for(int c : cards) {
        if(!visited[c]) {
            numbers.push_back(dfs(c, cards));
        }
    }
    
    sort(numbers.begin(), numbers.end(), greater<int>());
    
    if(numbers.size()==1) {
        answer = 0;
    } else {
        answer = numbers[0]*numbers[1];
    }
    
    return answer;
}