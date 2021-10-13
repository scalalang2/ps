#include <bits/stdc++.h>
using namespace std;

int chk[26];
int len = 0;

void f(int c, string acc) {
    if(c == len) {
        cout << acc << '\n';
        return;
    }
 
    for(int i = 0; i < 26; i++) {
        if(chk[i] == 0) continue;
        chk[i]--;
        char ch = 'a' + i;
        f(c + 1, acc + ch);
        chk[i]++;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--) {
        fill(chk, chk + 26, 0);

        string t;
        cin >> t;
        len = t.size();
        for(int i = 0; i < t.size(); i++)
            chk[t[i] - 'a']++;

        f(0, "");
    }
}