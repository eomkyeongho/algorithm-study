#include <bits/stdc++.h>

using namespace std;

bool comp(vector<int> a, vector<int> b) {
    if(a.back() != b.back()) {
        return (a.back() < b.back());
    } else {
        return (a[0] > b[0]);
    }
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    for(int i=0; i<data.size(); i++) {
        int num = data[i][col-1];
        data[i].erase(data[i].begin() + col - 1);
        data[i].push_back(num);
    }
    
    sort(data.begin(), data.end(), comp);
    
    for(int i=row_begin-1; i<row_end; i++) {
        int num = 0;
        for(int n : data[i]) {
            num += n % (i+1);
        }
        answer ^= num;
    }
    
    return answer;
}