#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n, m;

struct product {
    int price;
    set<int> fns;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    vector<product> products;
    for(int i = 0; i < n; i++) {
        product p;
        cin >> p.price;
        int c;
        cin >> c;
        while(c--) {
            int x;
            cin >> x;
            p.fns.insert(x);
        }
        products.push_back(p);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            auto x = products[i];
            auto y = products[j];

            if(x.price <= y.price) {
                bool hasAll = true;
                for(auto c : y.fns) {
                    if(x.fns.find(c) == x.fns.end()) {
                        hasAll = false;
                    }
                }

                bool hasMore = false;
                for (auto c : x.fns){
                    if (y.fns.find(c) == y.fns.end()){
                        hasMore = true;
                    }
                }

                if(hasAll && x.price < y.price) {
                    cout << "Yes";
                    return 0;
                }

                if(hasAll && hasMore) {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}