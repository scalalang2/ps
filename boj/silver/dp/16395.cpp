#include<bits/stdc++.h>

using namespace std;

int dp[31][31];

int fn(int n, int r) {
    if(r == 1 || n == 1 || r == n) {
        return 1;
    }

    if(dp[n][r] != -1) return dp[n][r];

    return dp[n][r] = fn(n-1, r-1) + fn(n-1, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    int n, r;
    cin >> n >> r;
    
    cout << fn(n, r) << endl;


    return 0;
}