#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(a < b) swap(a,b);
    if(b == 0) return a;
    
    return gcd(b, a%b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int gcd_A = 0;
    int gcd_B = 0;
    
    for(int a : arrayA) {
        gcd_A = gcd(a, gcd_A);
    }
    
    for(int b : arrayB) {
        gcd_B = gcd(b, gcd_B);
    }
    
    for(int a : arrayA) {
        if(gcd_B == 0) break;
        if(a % gcd_B == 0) {
            gcd_B = 0;
        }
    }
    
    for(int b : arrayB) {
        if(gcd_A == 0) break;
        if(b % gcd_A == 0) {
            gcd_A = 0;
        }
    }
    
    answer = max(gcd_A, gcd_B);
    
    return answer;
}