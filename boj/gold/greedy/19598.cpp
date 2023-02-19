#include<bits/stdc++.h>

using namespace std;

int N;
using ll = long long;
using P = pair<ll, ll>;
const int MAXN = 100001;

bool compare(P a, P b) {
    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<ll, vector<ll>, greater<ll> > Q;
    vector<P> v;
    cin >> N;
    for(int i = 0; i < N; i++) {
        P pp;
        ll st;
        ll ed;
        cin >> st >> ed;
        pp.first = st;
        pp.second = ed;

        v.push_back(pp);
    }

    sort(v.begin(), v.end(), compare);

    int ans = 1;
    for(int i = 0; i < N; i++) {
        if(Q.empty()) {
            Q.push(v[i].second);
        } else {
            ll curr = Q.top();
            // cout << curr << " " << v[i].first << endl;
            Q.pop();
            if(curr > v[i].first) {
                ans++;
                Q.push(curr);
            }
            Q.push(v[i].second);
        }
    }

    cout << ans << endl;

    return 0;
}