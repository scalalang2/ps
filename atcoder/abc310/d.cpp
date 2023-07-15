#include <bits/stdc++.h>
#define pii pair<ll, ll>
typedef long long ll;
using namespace std;

const int MAX = 12;
pii P[100];
int N, T, M, ans, C[MAX];

void DFS(int cur, int tn)
{
    if (cur == N + 1)
    {
        if (tn != T)
            return;
        int ok = 1;
        for (int j = 0; j < M; ++j)
        {
            auto [a, b] = P[j];
            if (C[a] == C[b])
                return;
        }
        ans++;
        return;
    }
    for (int j = 1; j <= tn; ++j)
    {
        C[cur] = j;
        DFS(cur + 1, tn);
    }
    C[cur] = tn + 1;
    DFS(cur + 1, tn + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> T >> M;
    for (int i = 0; i < M; ++i)
        cin >> P[i].first >> P[i].second;
    DFS(1, 0);
    cout << ans;
    return 0;
}