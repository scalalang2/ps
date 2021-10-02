#include <bits/stdc++.h>
using namespace std;

struct P {
    int x;
    int y;
    int cost;
};

struct comp {
    inline bool operator()(const P &p1, const P &p2){
        return p1.cost < p2.cost;
    }
};

vector<P> a;
int cost[1001][1001];
int p[1001];
int n, m;

int find(int node) {
    if(p[node] == node)
         return node;
    else {
        p[node] = find(p[node]);
        return p[node];
    }
}

void merge(int a, int b) {
    int a1 = find(a);
    int b1 = find(b);
    // 서로 다르다고 한다면 b1의 부모를 a1으로 설정한다.
    if(a1 != b1) p[b1] = a1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        p[i] = i;
    }
    
    while(m--) {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int temp;
            cin >> temp;
            cost[i][j] = temp;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j || i == 1 || j == 1) continue;
            P p = {i,j,cost[i][j]};
            a.push_back(p);
        }
    }

    sort(a.begin(), a.end(), comp());
    vector<pair<int, int> > ans;
    int cost = 0;
    int k = 0;

    for(int i = 0; i < a.size(); i++) {
        int x = find(a[i].x);
        int y = find(a[i].y);
        if(x == y) {
            continue;
        }
        merge(a[i].x, a[i].y);
        ans.push_back(make_pair(a[i].x, a[i].y));
        cost += a[i].cost;
        k++;
    }

    cout << cost << ' ' << k << '\n';
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}