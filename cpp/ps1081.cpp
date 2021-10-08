#include <iostream>
using namespace std;

typedef long long ll;

ll arr[10] = {0,};
// ll B[10] = {0,};

void calc(ll n, ll t) {
    while (n > 0) {
        arr[n % 10] += t;
        n /= 10;
    }
}

ll f(ll A, ll B) {
    ll st = A;
    ll ed = B;
    ll temp = 1;
    while (st <= ed) {
        while(st % 10 != 0 && st <= ed){
            calc(st, temp);
            st++;
        }
        if(st > ed) break;
        while(ed % 10 != 9 && st <= ed) {
            calc(ed, temp);
            ed--;
        }
        st /= 10;
        ed /= 10;
        for(int i = 0; i < 10; i++) 
            arr[i] += (ed - st + 1) * temp;
        
        temp *= 10;
    }

    ll ret = 0;
    for(int i = 0 ; i < 10; i++)
        ret += i * arr[i];
        
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll l, u;
    cin >> l >> u;

    cout << f(l, u) << endl;

    return 0;
}