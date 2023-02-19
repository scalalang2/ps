#include<bits/stdc++.h>

using namespace std;

int n, k;
string a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    cin >> a;

    string ans = "";
    int kk = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 'o' && kk < k) {
            ans += "o";
            kk++;
        } else {
            ans += "x";
        }
    }

    cout << ans << endl;

    return 0;
}