#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int N;

int solve(vector<int> board) {
    if(board.size() == N) return 1;
    
    vector<bool> next(N, true);
    
    for(int i=0; i<board.size(); i++) {
        next[board[i]] = false;
        int dist = board.size() - i;
        int next1 = board[i] + dist;
        int next2 = board[i] - dist;
        if(0 <= next1 && next1 < N) next[next1] = false;
        if(0 <= next2 && next2 < N) next[next2] = false;
    }
    
    int ret = 0;
    
    for(int i=0; i<N; i++) {
        if(next[i]) {
            board.push_back(i);
            ret = ret + solve(board);
            board.pop_back();
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    cin >> N;
    
    vector<int> v;
    
    int ret = solve(v);
    
    cout << ret << endl;
    
    return 0;
}