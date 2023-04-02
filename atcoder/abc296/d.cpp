#include<bits/stdc++.h>

using namespace std;
using ll = unsigned long long int;

ll N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 흠.. 어떻게 푸는 걸까나
    // 아주 간단한 수학일 것 같긴한데
    // X는 M보다는 크거나 같아야 하고.
    // 1 ~ N 사이에 존재하는 두 수 a,b 로 표현할 수 있어야 한다.
    cin >> N >> M;

    // 아주 풀이가 틀렸어
    // 이분탐색은 아닌듯
    // 근데 10^12 니까 대충 반띵하면 10^6
    // O(nlogn) 풀이는 가능 할지도

    ll ans = ULLONG_MAX;
    ll lo, hi;
    lo = 1;
    hi = N;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (N - mid + floor(M / mid) > 0)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    if(ans == ULLONG_MAX) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}