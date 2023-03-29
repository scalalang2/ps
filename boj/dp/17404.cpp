#include<bits/stdc++.h>

using namespace std;
const int maxn = 1001;

int n;
int ans = 1000 * 1000 + 1;
int cost[maxn][maxn];
int dp[3][maxn];

/**
 * DP 테이블에서 첫 번째 집을 특정 색으로 칠한 다음에 모든 경우의 수를 구한다
 * 첫번째 집의 빨간색 물감의 비용이 26이라면
 * 아래처럼 첫번째 집 색상을 고정시켜놓고 구하는 방식이다.
 * 
 * [26, max, max]
 * [-, -, -]
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++)
            cin >> cost[i][j];
    }

    for(int k = 0; k <= 2; k++) {
        for(int i = 0; i <= 2; i++) {
            if(i == k) dp[i][0] = cost[0][i];
            else dp[i][0] = 1000 * 1000 + 1;
        }

        for(int i = 1; i < n; i++) {
            dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + cost[i][0];
            dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + cost[i][1];
            dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + cost[i][2];
        }

        for(int i = 0; i <= 2; i++) {
            // 마지막 집을 칠하는 색이 k면 첫번째 집과 동일하기 때문에 패스한다
            if(i == k) continue;
            ans = min(ans, dp[i][n - 1]);
        }
    }

    cout << ans << endl;

    return 0;
}