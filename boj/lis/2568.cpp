#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // LIS를 배열 자체를 구하고
    // 거기에 속하지 않은 애들을 제거한다

    // record[i] = 각 수가 LIS배열의 어느 인덱스에 들어가는지 기록한다.
    // 가장 큰값에서 부터 뒤로 가면서 마킹한다.
    int n; cin >> n;
    vector<pi> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    // 첫 번째 전봇대 기준으로 정렬한다.
    sort(arr.begin(), arr.end(), [](const pi& a, const pi& b) {
        return a.first < b.first;
    });

    // 그리고 여기서 LIS를 구하는 거지
    vector<int> record(n+1, 0);
    vector<int> lis(n+1, 0);
    vector<bool> vis(n+1, false);
    lis[0] = arr[0].second;
    record[0] = 0;

    int len = 1;
    for(int i = 1; i < n; i++) {
        auto b = lis.begin(), e = lis.begin() + len;
        auto it = lower_bound(b, e, arr[i].second);

        if(it == lis.begin() + len) {
            record[i] = len;
            lis[len++] = arr[i].second;
        } else {
            record[i] = it - lis.begin();
            *it = arr[i].second;
        }
    }
    
    int ans = len;
    for(int i = n-1; i >= 0; i--) {
        if(record[i] == len-1) {
            vis[i] = true;
            len--;
        }
    }

    cout << n - ans << '\n';
    for(int i = 0; i < n; i++) {
        if(!vis[i]) cout << arr[i].first << '\n';
    }
    
    return 0;
}