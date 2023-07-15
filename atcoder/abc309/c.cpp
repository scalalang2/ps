#include<bits/stdc++.h>

using namespace std;
using ll = long long;

using pi = pair<int, int>;
int n, k, a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    vector<pi> arr;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end(), [](pi a, pi b) {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });
    ll total = 0;
    for(int i = 0; i < n; i++) total += arr[i].second;
    if(total <= k) {
        cout << 1 << endl;
        return 0;
    }

    for(int i = 0; i < n; i++) {
        // 첫째 날을 패스한다면? 다음날 부터 가능
        total -= arr[i].second;
        if(total <= k) {
            cout << arr[i].first+1 << endl;
            return 0;
        }
    }

    cout << arr[n-1].first+1 << endl;
    return 0;
}