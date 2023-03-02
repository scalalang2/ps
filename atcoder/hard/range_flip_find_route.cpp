#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<string> s;
int dp[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    s.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    // . 을 따라가는 길 + # 을 따라가는 길을 더하는게 최소값이다
    // 왜냐? #으로 바뀐 다음에는 내가 원하는 경로가 있으면 한 번에 뒤집을 수 있으니까
    // 예시)
    // ##..
    // .##.
    // ..## 
    // 위와 같이 되어있다면 한 번 flip 하는 걸로도 충분한데, 그 경우는 #으로만 길을 따라가는 경우이다.

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i + j == 0) dp[0][0] = (s[0][0] == '#');
            else {
                dp[i][j] = (int) 1e9;
                if(i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + (s[i-1][j] == '.' && s[i][j] == '#'));
                if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + (s[i][j-1] == '.' && s[i][j] == '#'));
            }
        }
    }

    cout << dp[n-1][m-1];

    return 0;
}