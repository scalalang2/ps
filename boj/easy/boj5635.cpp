#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

struct student {
    string name;
    int d, m, y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<student> arr;

    while(n--) {
        string x;
        int d, m, y;
        cin >> x >> d >> m >> y;
        student s = {x, d, m, y};
        arr.push_back(s);
    }


    auto f = [](student a, student b) {
        if(a.y == b.y) {
            if(a.m == b.m) {
                return a.d < b.d;
            } else {
                return a.m < b.m;
            }
        }
        return a.y < b.y;
    };
    sort(begin(arr), end(arr), f);

    cout << arr.back().name << "\n" << arr.front().name;

    return 0;
}