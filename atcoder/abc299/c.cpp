#include<bits/stdc++.h>

using namespace std;

int n;
int level = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    string x;
    cin >> x;

    int ans = -1;
    bool hype = false;
    for(int i = 0; i < n; i++) {
        if(x[i] == '-') {
            hype = true;
            ans = max(ans, level);
            level = 0;
        } else {
            level++;
        }
    }
    if(hype) ans = max(ans, level);
    if(ans == 0) cout << -1;
    else cout << ans << endl;


    return 0;
}