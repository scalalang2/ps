#include<bits/stdc++.h>

using namespace std;

int n, a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    a = 100;
    b = 100;
    while(n--) {
        int x,y;
        cin >> x >> y;
        if(x == y) continue;
        if(x > y) b -= x;
        else a -= y;
    }
    cout << a << endl;
    cout << b << endl;
    return 0;
}