#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// nCr = n-1Cm-1 + n-1Cm
// a 3개, z 2개 라면 
// a 3개 z 2개를 쓰는 경우의 수 = a2개 z1개를 쓰는 경우의 수 + a2개 z2개를 쓰는 경우의 수
//
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll dp[201][101];
    ll n, m, k;
    cin >> n >> m >> k;

    dp[0][0] = 1;
    for (int i = 1; i <= n + m; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j < i && j <= m; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

            // 계산하면 long long 범위를 넘어간다
            if (dp[i][j] > 1000000000)
                dp[i][j] = 1000000000;
        }
        if (i <= m)
            dp[i][i] = 1;
    }

    k--;
    if (dp[n + m][m] <= k) {
        puts("-1");
        return 0;
    }

    for (int i = m + n - 1; i >= 0; i--) {
        if (i >= m && dp[i][m] > k)
            putchar('a');
        else {
            putchar('z');
            k -= dp[i][m];
            m--;
        }
    }
    putchar('\n');
}