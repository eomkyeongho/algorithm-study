#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

struct SegTree {
    int n;
    vector<long long> tree;
    
    SegTree(const vector<long long> &arr) {
        n = arr.size();
        tree.resize(n*4, 0);
    }
    
    void add(int left, int right, int leftNode, int rightNode, int node, int k) {
        if(leftNode > right || rightNode < left) return;
        if(left <= leftNode && rightNode <= right) {
            tree[node] = tree[node] + k;
            return;
        }
        
        int mid = (leftNode + rightNode) / 2;
        add(left,right,leftNode,mid,node*2,k);
        add(left,right,mid+1,rightNode,node*2+1,k);
        
        return;
    }
    
    long long query(int index, int leftNode, int rightNode, int node) {
        if(index < leftNode || rightNode < index) return 0;
        if(leftNode == rightNode && leftNode == index) return tree[node];
        
        int mid = (leftNode + rightNode) / 2;
        
        return tree[node] + query(index,leftNode,mid,node*2) + query(index,mid+1,rightNode,node*2+1);
    }
    
    void add(int left, int right, int k) {
        add(left,right,0,n-1,1,k);
    }
    
    long long query(int index) {
        return query(index, 0, n-1, 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N;
    
    cin >> N;
    
    vector<long long> arr(N);
    
    for(int i=0; i<N; i++) cin >> arr[i];
    
    SegTree st(arr);
    
    int M;
    
    cin >> M;
    
    for(int i=0; i<M; i++) {
        int op;
        cin >> op;
        
        if(op == 1) {
            int a, b, k;
            cin >> a >> b >> k;
            st.add(a-1,b-1,k);
        } 
        else {
            int index;
            cin >> index;
            cout << arr[index-1] + st.query(index-1) << endl;
        }
    }

    return 0;
}