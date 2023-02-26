#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string x;
    cin >> x;

    int ans = 0;
    for(int i = 0; i < x.length(); i++) {
        if(x[i] - 'A' >= 0 && x[i] - 'A' < 26) {
            ans = i;
            break;
        }
    }

    cout << ans+1 << endl;

    return 0;
}