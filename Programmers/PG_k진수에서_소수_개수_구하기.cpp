#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s) {
    int index = 0;
    vector<string> ret;
    
    while(1) {
        while(index < s.length() && s[index] == '0') {
            index++;
        }

        if(index >= s.length()) {
            break;
        }
        
        string r;
        
        while(index < s.length() && s[index] != '0'){
            r.push_back(s[index++]);
        }
        ret.push_back(r);
    }
    
    return ret;
}

int solution(int n, int k) {
    int answer = 0;
    
    string numK;
    while(n >= k) {
        numK.push_back(n%k + '0');
        n/=k;
    }
    numK.push_back(n + '0');
    reverse(numK.begin(), numK.end());
    
    vector<string> numList = split(numK);
    
    for(string s : numList) {
        long long num = stoll(s);
        
        if(num == 1) continue;
        
        answer++;
        
        for(long long i=2; i*i<=num; i++) {
            if(num % i == 0) {
                answer--;
                break;
            }
        }
    }
    
    return answer;
}