#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

map<array<int, 3>, int> cache;

int w(int a, int b, int c) {
    if(cache.find({a,b,c}) != cache.end()) return cache[{a,b,c}];
    
    if(a <= 0 || b <= 0 || c <= 0) return cache[{a,b,c}] = 1;
    
    if(a > 20 || b > 20 || c > 20) return cache[{a,b,c}] = w(20, 20, 20);
    
    if(a < b && b < c) return cache[{a,b,c}] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    
    return cache[{a,b,c}] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int a, b, c;
	
	while(true) {
	    cin >> a >> b >> c;
	    if(a == -1 && b == -1 && c == -1) break;
	    
	    cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a,b,c) << endl;
	}
		
	return 0;
}