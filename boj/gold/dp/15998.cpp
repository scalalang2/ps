#include<bits/stdc++.h>

using namespace std;
using ll = long long ;
#define MAX 1000001
int n;
ll dp[MAX] = {0};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i < MAX; i++) {
        dp[i] += dp[i-1] % 1000000009;
        dp[i] += dp[i-2] % 1000000009;
        dp[i] += dp[i-3] % 1000000009;
    }
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cout << dp[t] % 1000000009 << endl;
    }

    return 0;
}