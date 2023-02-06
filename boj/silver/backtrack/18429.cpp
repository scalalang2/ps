#include<bits/stdc++.h>

using namespace std;

int n, k, ans;
int kits[8];
bool checked[8] = {false};

void search(int cnt, int acc) {
    if(acc < 500) return;
    if(cnt == n) {
        ans++;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(checked[i]) continue;
        checked[i] = true;
        search(cnt + 1, acc + kits[i] - k);
        checked[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ans = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> kits[i];

    search(0, 500);
    cout << ans << endl;

    return 0;
}