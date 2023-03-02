#include<bits/stdc++.h>

using namespace std;

const int MOD = 10000;

int x[100];
int n, m;
int dp[101][4][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int res = 0;
    cin >> n >> m;

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        x[a] = b;
    }

    if (x[1]) {
        dp[1][x[1]][1] = 1;
    } else {
        for (int i = 1; i <= 3; i++) dp[1][i][1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        // 고정된 날짜라면
        if (x[i]) {
            for (int j = 1; j <= 3; j++) {
                // 동일한 날짜에 먹는 파스타
                if (x[i] == j) {
                    // 일단 연속으로 잡수고
                    dp[i][j][2] += dp[i - 1][j][1] % MOD;
                } else{
                    for (int k = 1; k < 3; k++) {
                        dp[i][x[i]][1] += dp[i - 1][j][k] % MOD;
                    }
                }
            }
        } else {
            for (int j = 1; j <= 3; j++) {
                for (int l = 1; l <= 3; l++) {
                    if (j == l) {
                        dp[i][j][2] += dp[i - 1][j][1] % MOD;
                    } else {
                        for (int k = 1; k < 3; k++) {
                            dp[i][j][1] += dp[i - 1][l][k] % MOD;
                        }
                    }
                }
            }
        }
    }


    // 이거 완전 규칙성 찾기 노가다 문제네
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j < 3; j++)
            res += dp[n][i][j];

    cout << res % MOD << endl;
}