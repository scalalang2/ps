#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<ll, ll>;

int n;
ll d;
vector<pi> points;
vector<bool> infected;

ll dist(pi a, pi b) {
    return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}

void spread(int idx) {
    for(int i = 0; i < points.size(); i++) {
        if(i == idx) continue;
        if(!infected[i] && dist(points[idx], points[i]) <= d*d) {
            infected[i] = true;
            spread(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> d;
    for(int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    infected = vector<bool>(n, false);
    infected[0] = true;

    spread(0);

    for(int i = 0; i < n; i++) {
        if(infected[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }


    return 0;
}