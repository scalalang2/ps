#include<bits/stdc++.h>

using namespace std;

using ll = long long;

ll N, M;
vector<ll> B;
vector<ll> C;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    B.resize(N);
    C.resize(M);
    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> C[i];
    }

    sort(B.begin(), B.end());

    vector<ll> ans;
    for(int i = 0; i < M; i++) {
        ll lo = 0;
        ll hi = 1e9;
        ll cost = 0;
        while(lo < hi) {
            ll mid = (lo + hi) / 2;
            int idx = lower_bound(B.begin(), B.end(), mid) - B.begin();
            ll c = mid * (B.size() - idx);
            if(c <= cost) {
                cost = c;
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        ans.push_back(cost);
    }
    for(int i = 0; i < M; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}