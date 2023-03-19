#include <bits/stdc++.h>

using namespace std;

long long solution(int k, int d) {
    long long answer = d/k * 2 + 1;
    
    for(int i=k; i<d; i+=k) {
        long long yy = (long long)d*d - (long long)i*i;
        
        answer += (long long)sqrt(yy)/k;
    }
    
    return answer;
}