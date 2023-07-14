#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n, a, b, c;
const int mxn = 2001;
int table[mxn][mxn] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    while(n--) {
        cin >> a >> b >> c;
        table[a][b] = max(table[a][b], c);
    }

    int ans = 0;
    for(int i = 1; i < mxn; i++) {
        for(int j = 1; j < mxn; j++) {
            table[i][j] = max(table[i][j], max(table[i-1][j]-1, table[i][j-1]-1));
        }
    }

    for(int i = 1; i < mxn; i++) {
        for(int j = 1; j < mxn; j++) {
            if(table[i][j] > 0) {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}