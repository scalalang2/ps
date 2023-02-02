#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int l;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(min(a,b));
    }

    sort(v.begin(), v.end(), less<double>());
    double acc = 0;
    int last = v[0];
    int ans = 1;
    cin >> l;
    l *= 2;                                                                                                                           
    for(int i = 1; i < n; i++) {
        if(i-2 > 0) last = v[i-2];
        acc += v[i] + last;
        if (acc >= l) break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}