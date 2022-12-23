#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    vector<int> total;
    set<int> s;
    
    for(int e : elements) {
        if(total.empty()) {
            total.push_back(e);
        } else {
            total.push_back(total.back() + e);
        }
    }
        
    for(int i=0; i<elements.size(); i++) {
        for(int j=0; j < elements.size(); j++) {
            int sum;
            if(i+j >= elements.size()) {
                sum = total[(i+j)%elements.size()] + total[elements.size()-1] - total[j-1];
            } else {
                sum = total[(i+j)] - total[j] + elements[j];
            }
            s.insert(sum);
        }
    }
    
    answer = s.size();
    
    return answer;
}