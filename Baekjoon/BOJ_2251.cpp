#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int bottleSize[3];

array<int, 3> pour(array<int, 3> bottle, int from, int to) {
    int water = min(bottleSize[to] - bottle[to], bottle[from]);
    
    bottle[from] -= water;
    bottle[to] += water;
    
    array<int, 3> ret(bottle);
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    set<array<int, 3>> bottle;
    queue<array<int, 3>> Q;
    
    for(int i=0; i<3; i++) {
        cin >> bottleSize[i];
    }
    
    
    bottle.insert({0,0,bottleSize[2]});
    Q.push({0,0,bottleSize[2]});
    
    set<int> ans;
    ans.insert(bottleSize[2]);
    
    while(!Q.empty()) {
        array<int, 3> curr = Q.front();
        Q.pop();
        
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(i == j) continue;
                
                array<int, 3> r = pour(curr, i, j);
                
                if(bottle.find(r) == bottle.end()) {
                    if(r[0] == 0) {
                        ans.insert(r[2]);
                    }
                    
                    bottle.insert(r);
                    Q.push(r);
                }
            }
        }
    }
    
    for(auto it : ans) {
        cout << it << " ";
    }
}