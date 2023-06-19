#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n, k, q;
multiset<int> X, Y;
ll ans;

// 이 문제에서 새로 배운것
// set은 그 자체로 ordered이기 때문에 자료구조의 이런 특성도 잘 활용해야 한다.

void balance() {
    while(X.size() < k) {
        auto iy = Y.end(); iy--;
        X.insert((*iy));
        ans += (*iy);

        // 주의 : 값을 지우는 거면 multiset에 있는 모든 값을 지우는데
        // iy 라는 iterator를 입력으로 주면 multiset 중에서 단 하나만 지운다
        // 결국 핵심은 가장 큰값과 가장 작은 값을 유지하는 것
        // 편의를 위해 multiset을 썻지만 핵심은 큰 것과 작은 것을 유지하는 거라 PQ로도 가능할 듯
        Y.erase(iy);
    }
    if(X.empty() || Y.empty()) return;
    while(1) {
        auto ix = X.begin();
        // 질문, 값이 없으면 이건 어떻게 되는거지..?
        // 그런 경우는 없지 항상 값을 교환하기 때문에
        auto iy = Y.end(); iy--;
        int ex = (*ix);
        int ey = (*iy);
        // 정답에 포함된 값중 가장 작은 값이 
        // 미포함된 가장 큰거보다 크면 no more
        if(ex >= ey) break;
        ans += (ey - ex);
        X.erase(ix);
        Y.erase(iy);

        // 서로 값 교환하기
        X.insert(ey);
        Y.insert(ex);
    }
}

void add(int v) {
    Y.insert(v);
    balance();
}

void erase(int v) {
    auto ix = X.find(v);
    if(ix!=X.end()) {
        ans -= v;
        X.erase(ix);
    } else {
        Y.erase(Y.find(v));
    }
    balance();
}

// 음 사실 A of index 라는 건 별로 필요가 없구나
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k >> q;
    for(int i=0;i<k;i++){ X.insert(0); }
    for(int i=k;i<n;i++){ Y.insert(0); }
    vector<int> a(n, 0);
    
    ans = 0;

    while(q--) {
        int x, y;
        cin >> x >> y;
        x--;
        add(y);
        erase(a[x]);
        a[x] = y;
        cout << ans << '\n';
    }



    return 0;
} 