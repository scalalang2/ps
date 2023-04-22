#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n, q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;

    vector<set<int>> boxes(n+1);
    vector<map<int, int>> cnt(n+1);
    map<int, set<int>> MM;

    while(q--) {
        int a, b, c;
        cin >> a;
        if(a == 1) {
            cin >> b >> c;
        } else {
            cin >> b;
        }

        if(a == 1) {
            boxes[c].insert(b);
            cnt[c][b]++;
            MM[b].insert(c);
        } else if(a == 2) {
            set<int>::iterator it = boxes[b].begin();
            while(it != boxes[b].end()) {
                for(int i = 0; i < cnt[b][*it]; i++) {
                    cout << *it << " ";
                }
                it++;
            }
            cout << endl;
        } else {
            set<int>::iterator it = MM[b].begin();
            while(it != MM[b].end()) {
                cout << *it << " ";
                it++;
            }
            cout << endl;
        }
    }

    return 0;
}