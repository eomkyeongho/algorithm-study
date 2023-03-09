#include <bits/stdc++.h>

using namespace std;

priority_queue<array<int, 2>> pq;

void solve(vector<vector<int>> &users, vector<int> &emoticons, vector<int> &sale) {
    if(emoticons.size() == sale.size()) {
        int join = 0;
        int revenue = 0;

        for(vector<int> user : users) {
            int total = 0;

            for(int i=0; i<emoticons.size(); i++) {
                if(user[0] > sale[i]) continue;

                total += (emoticons[i]/100) * (100 - sale[i]);
            }

            if(total >= user[1]) {
                join++;
            } else {
                revenue += total;
            }
        }

        pq.push({join, revenue});
        
        return;
    }
    
    for(int i=10; i<=40; i+=10) {
        sale.push_back(i);
        solve(users,emoticons,sale);
        sale.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<int> sale;
    
    solve(users, emoticons, sale);
    
    answer.push_back(pq.top()[0]);
    answer.push_back(pq.top()[1]);
    
    return answer;
}