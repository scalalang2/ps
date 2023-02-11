#include<bits/stdc++.h>

using namespace std;
using pp = pair<int, int>;

const int MAXN = 10;
const int MAX_STAIRS = 100001;
int N, M, X;

bool traps[MAX_STAIRS] = {false};
bool visited[MAX_STAIRS] = {false};
int steps[MAXN] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> steps[i];

    cin >> M;
    for(int i = 0; i < M; i++) {
        int t;
        cin >> t;
        traps[t] = true;
    }
    cin >> X;

    queue<int> Q;
    Q.push(0);

    while(!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        if(curr == X) {
            cout << "Yes" << endl;
            return 0;
        }
        
        for(int i = 0; i < N; i++) {
            int nxt = curr + steps[i];
            if(nxt >= MAX_STAIRS) continue;
            if(traps[nxt] || visited[nxt] || nxt > X) continue;
            visited[nxt] = true;
            Q.push(nxt);
        }
    }

    cout << "No" << endl;
    return 0;
}