#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1 << 30;

int N;
ll dp[5001] = {-1};

ll f(int n) {
    if(n == 0) return 0;
    if(n < 0) return INF;

    if(dp[n] != INF) return dp[n];
    ll a = f(n-3)+1;
    ll b = f(n-5)+1;
    dp[n] = min(dp[n], a);
    dp[n] = min(dp[n], b);
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill(dp, dp+5001, INF);

    cin >> N;
    if (f(N) == INF) cout << -1;
    else cout << f(N);

    return 0;
}