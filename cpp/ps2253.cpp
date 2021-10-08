#include <bits/stdc++.h>
using namespace std;

int dp[10001][200];
int chk[10001];
int n, m;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    memset(chk, 1, sizeof(chk));
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        chk[temp] = -1;
    }

    dp[1][0] = 0;
    dp[2][1] = 1;

    for (int i = 3; i <= n; i++) {
        if (chk[i] == -1)
            continue;
        for (int j = 1; j <= sqrt(2*n); j++) {
            if (i-j >= 1 && chk[i - j] != -1 && dp[i - j][j] != -1){
                dp[i][j] = dp[i - j][j] + 1;
            }
            if (i - j >= 1 && chk[i - j] != -1 && dp[i - j][j - 1] != -1) {
                if (dp[i][j] != -1)
                    dp[i][j] = min(dp[i][j], dp[i - j][j - 1] + 1);
                else
                    dp[i][j] = dp[i - j][j - 1] + 1;
            }

            if (i - j >= 1 &&  chk[i - j] != -1 && dp[i - j][j + 1] != -1) {
                if (dp[i][j] != -1)
                    dp[i][j] = min(dp[i][j], dp[i - j][j + 1] + 1);
                else
                    dp[i][j] = dp[i - j][j + 1] + 1;
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i <= sqrt(2*n); i++)
    {
        if (dp[n][i] != -1)
        {
            ans = min(ans, dp[n][i]);
        }
    }

    if (ans == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}