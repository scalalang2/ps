#include<bits/stdc++.h>

using namespace std;

bool match(string s, string t) {
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '?' || s[i] == t[i])
            continue;
        else
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s,t;
    cin >> s >> t;

    string ans = "~";
    for(int i = s.size() - t.size(); i >= 0; i--) {
        if(match(s.substr(i, t.size()), t)) {
            string temp = "";
            for(int j = 0; j < s.size(); j++){
                if(j >= i && j < i + t.size())
                    temp += t[j - i];
                else if(s[j] == '?')
                    temp += 'a';
                else
                    temp += s[j];
            }
            ans = min(ans, temp);
        }
    }

    if(ans == "~") cout << "UNRESTORABLE" << endl;
    else cout << ans << endl;

    return 0;
}