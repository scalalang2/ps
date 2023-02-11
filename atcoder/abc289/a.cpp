#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;

    string ans = "";
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '0') ans += "1";
        else ans += "0";
    }

    cout << ans << endl;

    return 0;
}