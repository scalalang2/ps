#include<bits/stdc++.h>

using namespace std;

#define MAX 10001
#define el '\n';
using p = pair<int, int>;

const int INF = 1 << 31 - 1;
int dp[MAX][101];
int n, t;
p coins[101];

int f(int x, int idx) {
    if(x == 0) return dp[x][idx] = 1;
    if(idx > n) return dp[x][idx] = 0; // 동전을 다 사용해도 안되는 경우에는 0을 리턴한다.
    if(dp[x][idx] != -1) return dp[x][idx];

    int ans = 0;

    // 동전을 모두 이용해서 x원을 만들 수 있는 경우의 수를 구한다.
    for(int i = 0; i <= coins[idx].second; i++) {
        if(x - (coins[idx].first * i) < 0) break;
        ans += f(x - (coins[idx].first * i), idx + 1);
    }
    return dp[x][idx] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 2차원 배열의 값을 초기화 하는 방법 꼭 기억하자
    memset(&dp[0][0], -1, sizeof(dp));

    cin >> t;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> coins[i].first >> coins[i].second;
    }

    cout << f(t, 1) << el;

    return 0;
}            