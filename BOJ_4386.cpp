#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int parent[100];
int level[100];

int FindRoot(int n) {
    return (parent[n] == -1 ? n : FindRoot(parent[n]));
}

void Merge(int a, int b) {
    if(level[a] > level[b]) {
        parent[b] = a;
    } else {
        parent[a] = b;
        if(level[a] == level[b]) {
            level[b]++;
        }
    }
}

double Dist(array<double, 2> a, array<double, 2> b) {
    return sqrt((a[0] - b[0])*(a[0] - b[0]) + (a[1] - b[1])*(a[1] - b[1]));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    memset(parent, -1, sizeof(parent));
    
    int n;
    
    cin >> n;
    
    vector<array<double, 2>> star(n);
    
    for(int i=0; i<n; i++) {
        cin >> star[i][0] >> star[i][1];
    }
    
    priority_queue<pair<double, array<int, 2>>> pq;
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            pq.push({-Dist(star[i], star[j]), {i, j}});
        }
    }
    
    double ans = 0;
    
    while(n > 1) {
        double d = -pq.top().first;
        int a = pq.top().second[0];
        int b = pq.top().second[1];
        pq.pop();
        
        int ra = FindRoot(a);
        int rb = FindRoot(b);
        if(ra != rb) {
            Merge(ra,rb);
            ans += d;
            n--;
        }
    }

    cout << ans << endl;
}