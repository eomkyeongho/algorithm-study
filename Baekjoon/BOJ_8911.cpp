#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    
    cin >> T;
    
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    while(T--) {
        int currX, currY, minX, minY, maxX, maxY, d;
        currX = currY = minX = minY = maxX = maxY = d = 0;
        
        string route;
        
        cin >> route;
        
        for(char r : route) {
            switch(r) {
                case 'F' : 
                    currX += dx[d];
                    currY += dy[d];
                    break;
                case 'B' :
                    currX += dx[(d+2) % 4];
                    currY += dy[(d+2) % 4];
                    break;
                case 'R' :
                    d = (d + 1) % 4;
                    break;
                case 'L' :
                    d = (d - 1 + 4) % 4;
                    break;
            }
            minX = min(minX, currX);
            minY = min(minY, currY);
            maxX = max(maxX, currX);
            maxY = max(maxY, currY);
        }
        
        cout << (maxX - minX) * (maxY - minY) << endl;
    }
}