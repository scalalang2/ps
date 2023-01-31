#include<bits/stdc++.h>

using namespace std;

#define MAX 100001

int n;
int arr[MAX];
int dp[MAX][2];

const int FORWARD = 0;
const int BACKWARD = 1;
const int INF = MAX * 1000 + 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < 2; j++) {
            dp[i][j] = INF;
        }
    }

    // 생각 자체가 글러먹었었네
    // 앞에서의 연속합과 뒤에서의 연속합을 따로 구해서 모든 구간에 대해서 f(i-1) + f(i+1) 의 최댓값을 구한다.
    dp[0][FORWARD] = arr[0];
    for(int i = 1; i < n; i++) {
        dp[i][FORWARD] = max(arr[i], dp[i-1][FORWARD] + arr[i]);
    }

    dp[n-1][BACKWARD] = arr[n-1];
    for(int i = n-2; i >= 0; i--) {
        dp[i][BACKWARD] = max(arr[i], dp[i+1][BACKWARD] + arr[i]);
    }

    int ans = INF * -1;
    for(int i = 0; i < n; i++) {
        ans = max(max(ans, dp[i][FORWARD]), dp[i][BACKWARD]);
    }
    for(int i = 1; i < n-1; i++) {
        ans = max(ans, dp[i-1][FORWARD] + dp[i+1][BACKWARD]);
    }
    cout << ans << endl;

    return 0;
}