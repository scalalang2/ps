#include<bits/stdc++.h>

using namespace std;

// 데이터를 (값, 인덱스)로 묶고
// 값에 대해서는 오름차순, 인덱스는 내림차순으로 정렬해서 LIS를 구한다.
// 약간 이 구현 방법이
// 인덱스를 살짝 1로 옆으로 옮겨서 편하게 계산할 수 있도록 한거네?
struct Segtree {
    vector<int> tree;
    int size;

    Segtree(int n) {
        int sz = 1;
        while (sz < n) sz <<= 1;
        size = 2*sz;
        tree.resize(size);
    }

    void update(int idx, int val) {
        idx += size/2;
        tree[idx] = val;
        while (idx > 1) {
            idx /= 2;
            tree[idx] = max(tree[2*idx], tree[2*idx+1]);
        }
    }

    int query(int L, int R, int node, int nodeL, int nodeR) {
        if (R < nodeL || nodeR < L) return 0;
        if (L <= nodeL && nodeR <= R) return tree[node];
        int mid = (nodeL + nodeR) / 2;
        return max(query(L, R, 2*node, nodeL, mid), query(L, R, 2*node+1, mid+1, nodeR));
    }
};

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> o(n);
    vector<pair<int, int>> v(n);

    for(int i = 0; i < n; i++) {
        cin >> o[i];
    }

    for(int i = 0; i < n; i++) {
        v[i].first = o[i];
        v[i].second = i;
    }

    sort(v.begin(), v.end(), compare());

    int ans = 0;
    int max_index = 0;

    Segtree seg(n);
    for(int i = 0; i < n; i++) {
        int idx = v[i].second + 1;
        int value = v[i].first;
        int ret = seg.query(1, idx, 1, 1, seg.size/2);
        if (ret+1 > ans) {
            ans = ret+1;
            max_index = idx;
        }
    seg.update(idx-1, ret+1);
    }

    vector<int> lis;
    int k = ans;
    for(int i = max_index; i > 0; i--) {
        if (seg.query(i, i, 1, 1, seg.size/2) == k) {
            lis.push_back(o[i-1]);
            k--;
        }
    }

    cout << ans << endl;
    for(int i = lis.size()-1; i >= 0; i--) {
        cout << lis[i] << " ";
    }


    return 0;
}