#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;

struct P {
    ll cost;
    ll origin;
    ll cnt;
};

struct Cmp {
    // a가 b보다 이후에 나와야 하는 조건을 설정한다.
    bool operator()(const P &a, const P &b) {
        return a.cost < b.cost;
    }
};

priority_queue<P, vector<P>, Cmp> pq;

ll powll(ll x, ll c) {
    ll ret = 1;
    for(int i = 0; i < c; i++) {
        ret *= x;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int cost;
        cin >> cost;
        pq.push({cost, cost, 0});
    }

    ll ans = 0;
    while(m--) {
        P curr = pq.top();
        pq.pop();

        if(curr.cost == 0) {
            cout << 0 << endl;
            return 0;
        }

        pq.push({curr.origin / powll(2, curr.cnt + 1), curr.origin, curr.cnt + 1});
    }

    while(!pq.empty()) {
        ans += pq.top().cost;
        pq.pop();
    }

    cout << ans << endl;

    return 0;
}