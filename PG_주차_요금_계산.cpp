#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s, char delimiter) {
    vector<string> ret;
    stringstream ss(s);
    string temp;
    
    while(getline(ss, temp, delimiter)) {
        ret.push_back(temp);
    }
    
    return ret;
}

int calculate(vector<int> &fees, int t) {
    int ret = fees[1];
    
    t -= fees[0];
    
    if(t > 0) {
        t += fees[2] - 1;
        ret += (t / fees[2])*fees[3];
    }
    
    return ret;
}

int timeToInt(string t) {
    return stoi(t.substr(0,2))*60 + stoi(t.substr(3));
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> park, cost;
    
    for(string record : records) {
        vector<string> r = split(record, ' ');
        int t = timeToInt(r[0]);
            
        if(r[2] == "IN") {
            park[r[1]] = t;
        } else {
            if(cost.find(r[1]) == cost.end()) {
                cost[r[1]] = 0;
            }
            cost[r[1]] += t - park[r[1]];
            park.erase(r[1]);
        }
    }
    
    for(auto it : park) {
        int t = 23 * 60 + 59;
        if(cost.find(it.first) == cost.end()) {
            cost[it.first] = 0;
        }
        cost[it.first] += t - it.second;
    }
    
    for(auto it : cost) {
        answer.push_back(calculate(fees, it.second));
    }
    
    return answer;
}