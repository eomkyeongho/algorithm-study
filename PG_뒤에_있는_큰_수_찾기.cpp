#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    priority_queue<array<int, 2>> pq;
    
    for(int i=0; i<numbers.size(); i++){
        while(!pq.empty() && -pq.top()[0] < numbers[i]) {
            answer[pq.top()[1]] = numbers[i];
            pq.pop();
        }
        pq.push({-numbers[i], i});
    }
    
    while(!pq.empty()) {
        answer[pq.top()[1]] = -1;
        pq.pop();
    }
    
    return answer;
}