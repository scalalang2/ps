#include<bits/stdc++.h>

using namespace std;

int n;
const int SK = 1;
const int CY = 2;
int dp[1001];

bool f(int p, int s) {
    if(s == 2) return p == SK;
    if(s == 1 || s == 3) return p == CY;

    if(dp[s] != -1) return dp[s];
    int next = p == SK ? CY : SK;
    if(s - 1 > 0) dp[s] = f(next, s - 1);
    if(s - 3 > 0) dp[s] = dp[s] && f(next, s - 3);
    return dp[s];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    cin >> n;
    cout << (f(SK, n) ? "SK" : "CY");

    return 0;
}