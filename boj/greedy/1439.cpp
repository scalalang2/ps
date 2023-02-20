#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    char last = ' ';
    int o = 0;
    int z = 0;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == last) continue;
        else {
            if(s[i] == '0') {
                z++;
                last = '0';
            } else {
                o++;
                last = '1';
            }
        }
    }

    cout << min(o, z) << endl;

    return 0;
}