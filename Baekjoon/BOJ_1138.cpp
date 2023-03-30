#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int N;
int tall[11];

void solve(vector<int> person, vector<bool> used);

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    cin >> N;
    
    for(int i=1; i<=N; i++) {
        cin >> tall[i];
    }

    vector<int> person;
    vector<bool> used(11,false);

    solve(person, used);
}

void solve(vector<int> person, vector<bool> used){
    if(person.size() == N) {
        for(int p : person) {
            cout << p << " ";
        }
        return;
    }
    
    for(int i=1; i<=N; i++) {
        if(used[i]) continue;
        
        int cnt = 0;
        
        for(int p : person) {
            if(p > i) cnt++;
        }
        
        if(cnt == tall[i]) {
            person.push_back(i);
            used[i] = true;
            solve(person, used);
            person.pop_back();
            used[i] = false;
        }
    }
}