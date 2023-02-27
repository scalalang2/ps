#include<bits/stdc++.h>

using namespace std;

int dp[101][21];
int l[21];
int g[21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dp, 0, sizeof(dp));

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> l[i];
    for(int i = 1; i <= n; i++) cin >> g[i];


    // 이거 그냥 knapsack 이잖어..?
    for(int i = 0; i < 101; i++) {
        for(int j = 1; j <= n; j++) {
            if(i - l[j] > 0) {
                dp[i][j] = max(dp[i][j-1], dp[i-l[j]][j-1] + g[j]);
            } else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    
    cout << dp[100][n] << endl;

    return 0;
}