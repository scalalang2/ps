#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int chk[2501];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fill(chk, chk + 2501, 0);

    string el;
    string match;
    getline(cin, el);
    getline(cin, match);

    for(int i = 0; i < el.length(); i++) {
        bool found = true;
        if(chk[i] == 1) continue;

        for(int j = 0; j < match.length(); j++) {
            if(el[i + j] != match[j]) {
                found = false;
            }
        }

        if(found) {
            ans++;
            for(int j = 0; j < match.length(); j++) {
                chk[i + j] = 1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}