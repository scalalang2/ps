#include<bits/stdc++.h>

using namespace std;

using ll = long long;

struct segtree {
    int size;
    vector<ll> tree;

    segtree(int n) {
        int sz = 1;
        while(sz < n) sz <<= 1;
        size = sz * 2;
        tree.resize(size, INT_MAX);
    }

    void build(vector<ll> &arr) {
        for(int i = 0; i < arr.size(); i++) tree[i+size/2] = arr[i];
        for(int i = size/2-1; i > 0; i--) tree[i] = min(tree[i*2], tree[i*2+1]);
    }

    void update(int idx, ll val) {
        idx += size/2;
        tree[idx] = val;
        while(idx > 1) {
            idx /= 2;
            tree[idx] = min(tree[idx*2], tree[idx*2+1]);
        }
    }

    ll query(int pos, int low, int high, int L, int R) {
        if(high < L || R < low) return INT_MAX;
        if(low <= L && R <= high) return tree[pos];
        int mid = (L + R) / 2;
        return min(query(pos*2, low, high, L, mid), query(pos*2+1, low, high, mid+1, R));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    segtree sg = segtree(n);
    sg.build(arr);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << sg.query(1, a, b, 1, sg.size/2) << endl;
    }

    return 0;
}