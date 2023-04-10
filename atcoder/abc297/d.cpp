#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll A, B;
    cin >> A >> B;

    ll ans = 0;
    if(B > A) {
        ll tmp = A;
        A = B;
        B = tmp;
    }

    while(B != 0 && A != B) {
        ll tmp = B;
        ll tmpA = A;
        A = B;
        B = tmpA % tmp;
        ans++;
    }

    cout << ans << endl;


    return 0;
}