#include<bits/stdc++.h>

using namespace std;

// 아하 아니 쒸부랄 것
// N이 10밖에 안되니까
// O(NK) 도 충분히 쌉가능이구나
using ll = long long;
set<ll> s;
int n, k;

// 알고리즘을 굳이 분류하자면 그리디 알고리즘 인데
// [v[i], 2v[i], 3v[i], ..., Kv[i]] 까지 있을때 
// 나보다 크면서 작은 다음수를 찾는다.

// 0, 20, 40, 60, 80, 100 배열이 있으면
// 맨 처음 작은 0을 찾아서 더하고, 그 다음에 작은 20을 찾아서 더하고
// 그 다음에 작은 수는 25니까 25+25 해서 50을 저장하고

// 근데 증명은 어떻게 하는거지?
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    vector<int> arr(n);
    sort(arr.begin(), arr.end());
    s.insert(0);

    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) {
        ll last = 0;
        for(int j = 0; j < k; j++) {
            set<ll>::iterator it = s.lower_bound(last);
            if(it == s.end()) break;
            last = *it;
            s.insert(last + arr[i]);
            last++;
        }
    }

    set<ll>::iterator it = s.begin();
    for(int i = 0; i < k; i++) it++;
    cout << *it << endl;

    return 0;
}