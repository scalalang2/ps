#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int n;
int arr[101];
ll dp[21][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    dp[arr[0]][0] = 1;
    for(int i = 1; i < n; i++) {
        for(int k = 0; k <= 20; k++) {
            if(dp[k][i-1] == 0) continue;
            if(k + arr[i] <= 20) dp[k + arr[i]][i] += dp[k][i-1];
            if(k - arr[i] >= 0) dp[k - arr[i]][i] += dp[k][i-1];
        }
    }

    cout << dp[arr[n-1]][n-2] << endl;

    return 0;
}