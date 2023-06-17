#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int N;
bool isClosed[100];
vector<array<int, 4>> windows;

bool isCovered(array<int, 2> b, array<int, 4> w) {
    return (w[0] <= b[0] && b[0] <= w[2] && w[1] <= b[1] && b[1] <= w[3]);
}

int solve(int n) {
    if(isClosed[n]) return 0;
    
    isClosed[n] = true;
    
    int ret = 1;
    
    for(int i=n+1; i<N; i++) {
        if(!isClosed[i]) {
            if(isCovered({windows[n][0],windows[n][3]}, windows[i])) {
                ret += solve(i);
            }
        }
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for(int i=0; i<N; i++) {
        int R1, S1, R2, S2;
        cin >> R1 >> S1 >> R2 >> S2;
        windows.push_back({R1, S1, R2, S2});
    }
    
    cout << solve(0) << endl;
}