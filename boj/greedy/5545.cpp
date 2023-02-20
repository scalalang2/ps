#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, A, B, C;
ll arr[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> A >> B >> C;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);

    ll price = A;
    ll D = C;

    for(int i = N-1; i >= 0; i--) {
        if(D * (price+B) <= price * (D + arr[i])) {
            price += B;
            D += arr[i];
        } else break; 
    }

    cout << D / price << endl;

    return 0;
}