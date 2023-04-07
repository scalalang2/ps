#include<bits/stdc++.h>

using namespace std;

// 최대값 세그먼트 트리를 만든 다음에
// 구간 [L, R]에 대해서 value보다 작은 수의 개수를 구한다.
// 그 개수를 모두 더하면 정답임
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(v[i] > v[j]) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}