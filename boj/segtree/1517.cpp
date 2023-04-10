#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;

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
        tree[idx] = val;
        while(idx > 1) {
            idx /= 2;
            tree[idx] = tree[idx*2] + tree[idx*2 + 1];
        }
    }

    // low, high 가 쿼리 구간
    // 구간은 고정 시키고 전체 범위만 좁혀가는 식으로 쿼리를 작성해야 한다.
    // L, R 이 전체 범위
    int query(int pos, int low, int high, int L, int R) {
        if(high < L || R < low) return 0;
        if(low <= L && R <= high) return tree[pos];
        int mid = (L + R) / 2;
        return query(pos*2, low, high, L, mid) + query(pos*2 + 1, low, high, mid+1, R);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i] = {x, i};
    }

    segtree s = segtree(n);
    long long ans = 0;

    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        s.update(i, 1);
    }

    // 작은 애 부터 튀어나오고
    // 작은 녀석 앞에 있는 녀석들 중 큰 숫자가 몇개나 있는지 세기
    for(int i = 0; i < n; i++) {
        pair<int, int> pp = v[i];
        ans += s.query(1, 1, pp.second+1, 1, s.size/2)-1;
        s.update(pp.second, 0);
    }

    cout << ans << endl;

    return 0;
}