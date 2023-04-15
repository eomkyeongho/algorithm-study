#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    
    cin >> N >> M;
    
    map<int, array<int, 2>> album;
    
    for(int i=0; i<M; i++) {
        int student;
        
        cin >> student;
        
        if(album.find(student) != album.end()) {
            album[student][0]++;
        } else {
            if(album.size() == N) {
                priority_queue<array<int, 3>> pq;
                
                for(auto it : album) {
                    pq.push({-it.second[0], -it.second[1], it.first});
                }
                
                album.erase(pq.top()[2]);
            }
            
            album[student][0] = 1;
            album[student][1] = i;
        }
    }
    
    for(auto it : album) {
        cout << it.first << " ";
    }
}