#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
const int maxn = 200001;

ll n, m, d;
vector<ll> cands_for_A;
vector<ll> cands_for_B;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> d;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        cands_for_A.push_back(x);
    } 

    for (int i = 0; i < m; i++){
        ll x;
        cin >> x;
        cands_for_B.push_back(x);
    }
    sort(cands_for_A.begin(), cands_for_A.end());
    sort(cands_for_B.begin(), cands_for_B.end());

    // A - B <= D
    // 최대값으로 가려면 어떻게 해야돼?
    // B가 A와 동일한 값이어야 해
    ll ans = -1;
    for(int i = 0; i < n; i++) {
        ll A = cands_for_A[i];
        auto it = lower_bound(cands_for_B.begin(), cands_for_B.end(), A) - cands_for_B.begin();
        ll B = cands_for_B[it];

        // cout << A << " " << B << " " << it << endl;

        if(abs(A - B) <= d) {
            ans = max(ans, A + B);
        }
    }

    cout << ans << endl;

    return 0;
}