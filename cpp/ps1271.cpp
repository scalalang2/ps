#include <iostream>
using namespace std;

typedef long long ll;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    if(m == 0) {
        cout << 0 << endl;
        cout << m << endl;
    } else {
        cout << n/m << endl;
        cout << n%m << endl;
    }

    return 0;
}