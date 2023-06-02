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

    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int len = 1;
    vector<int> lis(arr.size(), 0);

    // lis[0]은 항상 길이 1짜리 LIS를 가진다.
    lis[0] = arr[0];

    /*
    1. 만약 A[i]가 모든 후보군 중에서 가장 작은 값이라면 LIS 길이 1 짜리 배열을 새로만든다.
    2. 만약, A[i]가 후보군 중에서 가장 큰 값이라면, 가장 큰 액티브 리스트 뒤에다가 A[i]를 추가한다.
    3. 만약 A[i]가 사이에 껴있다면, LIS배열의 마지막 원소가 A[i]보다 작으면서 가장 긴 길이를 가진 배열을 찾아서 A[i]를 붙이고
            동일한 길이의 다른 배열을 모두 지운다
    */
    for(int i = 1; i < arr.size(); i++) {
        auto b = lis.begin(), e = lis.begin() + len;
        auto it = lower_bound(b, e, arr[i]);

        if(it == lis.begin() + len) {
            lis[len++] = arr[i];
        } else {
            *it = arr[i];
        }
    }

    cout << n - len;

    return 0;
}