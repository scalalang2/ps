#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n;
set<string> se;
set<string> cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        string reverse;
        cin >> s;
        for (int j = s.size() - 1; j >= 0; j--){
            reverse += s[j];
        }

        if(se.find(s) == se.end() && se.find(reverse) == se.end()) {
            se.insert(s);
            se.insert(reverse);
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}