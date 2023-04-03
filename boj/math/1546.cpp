#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int max = *max_element(v.begin(), v.end());
    double sum = 0;
    for(int i = 0; i < n; i++) sum += double(v[i])/double(max) * double(100);

    printf("%.5f", sum / double(n));

    return 0;
}