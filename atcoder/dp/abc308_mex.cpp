#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int mex(int x, int y, int z) {
    for(int i = 0; i < 3; i++) {
        if(x != i and y != i and z != i) return i;
    }
    return 3;
}

/**
 * N개의 시퀀스와 M,E,X로 구성된 N개의 문자열이 주어짐
 * S[i],S[j],S[k]를 이어붙이면 MEX되는 경우의 모든 mex(i,j,k)를 구해아고 합해야한다.
 * 
 * 문자열의 크기는 2*10^5개
 * mex = minimum exclusive (non-negative integer)
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    string s;
    cin >> s;

    vector cnt_l(n+1, vector<int>(3));
    vector cnt_r(n+1, vector<int>(3));

    for(int i = 0; i < n; i++) {
        cnt_l[i+1] = cnt_l[i];
        if(s[i] == 'M') ++cnt_l[i+1][arr[i]];
    }

    for(int i = n-1; i >= 0; i--) {
        cnt_r[i] = cnt_r[i+1];
        if(s[i] == 'X') ++cnt_r[i][arr[i]];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'E') continue;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                ans += (ll) cnt_l[i][j] * cnt_r[i + 1][k] * mex(j, arr[i], k);
            }
        }
    }
    cout << ans << endl;


    return 0;
}