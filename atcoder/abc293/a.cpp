#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    string ans;

    cin >> s;
    for(int i = 0; i < s.length(); i += 2) {
        ans += s[i+1];
        ans += s[i];
    }

    cout << ans << endl;

    return 0;
}