#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct PP {
    ll x;
    ll y;
};

PP p1,p2,p3;

ll ccw(PP a, PP b, PP c)
{
    ll ret = a.x * b.y + b.x * c.y + c.x * a.y;
    ret -= (a.y * b.x + b.y * c.x + c.y * a.x);
    if(ret > 0) return 1;
    else if(ret < 0) return -1;
    else return 0; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;

    cout << ccw(p1, p2, p3) << endl;
    return 0;
}