#include<bits/stdc++.h>

using namespace std;

int N, Q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> players;
    cin >> N >> Q;
    players.resize(N+1);

    for(int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        if(a == 1) {
            players[b]++;
        } else if(a == 2) {
            players[b] += 2;
        } else {
            if(players[b] >= 2) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}