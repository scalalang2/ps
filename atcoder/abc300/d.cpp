#include<bits/stdc++.h>

using namespace std;
using ll = long long;
ll N;

const int mxn = 1000001;
ll seive[mxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 2; i < mxn; i++) {
        if(seive[i] == 0) {
            for(int j = i + i; j < mxn; j += i)
                seive[j] = 1;
        }
    }

    vector<ll> primes;
    for(int i = 2; i < mxn; i++) {
        if(seive[i] == 0)
            primes.push_back(i);
    }

    ll ans = 0;

    vector<ll> pp(primes.size());
    for (int i = 0; i < primes.size(); i++){
        pp[i] = primes[i] * primes[i];
    }

    for (int i = 0; i < primes.size()-2; i++)
    {
        for (int j = i+1; j < primes.size()-1; j++)
        {
            ll a = primes[i];
            ll b = primes[j];
            if(a * a * a * a * a > N) break;
            if(a * a * b * b * b > N) break;

            auto p = lower_bound(pp.begin() + j + 1, pp.end(), N / a / a / b);
            int idx = p - (pp.begin() + j + 1);
            ans += idx;
        }
    }

    cout << ans << endl;

    return 0;
}