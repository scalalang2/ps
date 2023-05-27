#include<bits/stdc++.h>

using namespace std;
using ll = long long;
ll A, B;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> A >> B;
    if(B >= A) {
        cout << 1;
    } else {
        ll ans = A / B;
        if(A % B != 0) ans++;
        cout << ans;
    }
    return 0;
}