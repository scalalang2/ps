#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 52;
const int MAX_CARD = 14;

int n;
int cards[MAX_CARD];
int ans[MAX_N];

bool search(int k, int acc) {
    if(k == n) return true;
    for(int i = 1; i <= 13; i++) {
        if(cards[i] == 0 || acc % i != 0) continue;
        cards[i]--;
        ans[k] = i;
        if(search(k + 1, acc - i)) return true;
        cards[i]++;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while(1) {
        memset(cards, 0, sizeof(cards));
        cin >> n;
        if(n == 0) break;

        int acc = 0;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cards[x]++;
            acc += x;
        }

        if(search(0, acc)) {
            for(int i = n-1; i >= 0; i--) {
                cout << ans[i] << " ";
            }
            cout << endl; 
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}