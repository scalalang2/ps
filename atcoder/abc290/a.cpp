#include<bits/stdc++.h>

using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    vector<int> score;
    score.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> score[i];
    }

    int ans = 0;
    for(int i = 0 ; i <m;i++) {
        int s;
        cin >> s;
        ans += score[s-1];
    }

    cout << ans << endl;
    return 0;
}