#include<bits/stdc++.h>

using namespace std;

int s = 100;
int n, m, ans;
map<int, bool> deny;

void dfs(int cnt, int cur) {
    if(cur != 0) ans = min(ans, abs(cur - n) + cnt);
    if(cnt == 6) return;
    for(int i = 0; i <= 9; i++) {
        if(deny[i]) continue;
        dfs(cnt + 1, cur + i * pow(10, cnt));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ans = 500001;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        deny[x] = true;
    }
    dfs(0, 0);
    ans = min(ans, abs(n - s));
    if(!deny[0]) ans = min(ans, 1 + n);
    cout << ans;

    return 0;
}