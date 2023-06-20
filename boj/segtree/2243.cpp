#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

const int maxn = 1e7 + 1;
int n;
map<int, int> M; // 좌표 압축 수행
map<int, int> MM;

struct segtree {
    int size;
    vector<int> tree;

    segtree(int n) {
        int sz = 1;
        while(sz < n) sz <<= 1;
        size = sz * 2;
        tree.resize(size, 0);
    }

    void update(int idx, int val) {
        idx += size / 2;
        tree[idx] += val;
        while(idx > 1) {
            idx /= 2;
            tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
        }
    }

    int get(int idx) {
        idx += size / 2;
        return tree[idx];
    }

    // 구간에 포함되는 걸 모조리 계산하는게 아니라
    // 이렇게 이분 탐색처럼 구할 수도 있음
    int query(int node, int L, int R, int k) {
        if(L == R) return L;
        int mid = (L + R) / 2;
        
        if(tree[node * 2] >= k) return query(node * 2, L, mid, k);
        else return query(node * 2 + 1, mid + 1, R, k - tree[node * 2]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    int a, b, c;

    vector<tuple<int, int, int>> queries;
    vector<int> coord;

    for(int i = 0; i < n; i++) {
        cin >> a;
        if(a == 1) {
            cin >> b;
            queries.push_back({1, b, 0});
        } else {
            cin >> b >> c;
            queries.push_back({2, b, c});
            coord.push_back(b);
        }
    }

    sort(coord.begin(), coord.end());
    int cnt = 1;
    for(auto x : coord) {
        if(M.count(x) == 0) {
            M[x] = cnt;
            MM[cnt++] = x;
        } 
    }
    segtree st(cnt);
    for(int i = 0; i < n; i++) {
        tie(a, b, c) = queries[i];
        if(a == 1) {
            int idx = st.query(1, 1, st.size/2, b)-1;
            cout << MM[idx] << '\n';
            st.update(idx, -1);
        } else {
            int nb = M[b];
            st.update(nb, c);
        }
    }

    return 0;
}