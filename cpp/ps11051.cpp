#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// nCr = n-1Cm-1 + n-1Cm
// a 3개, z 2개 라면
// a 3개 z 2개를 쓰는 경우의 수 = a2개 z1개를 쓰는 경우의 수 + a2개 z2개를 쓰는 경우의 수
//
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int dp[1001][1001];
    fill(&dp[0][0], &dp[1000][1001], 1);

    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j < i; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }

    cout << dp[n][k] << endl;
}