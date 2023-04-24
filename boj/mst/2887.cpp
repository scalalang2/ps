#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int mxn = 100001;
int N;
int par[mxn];
int groups[mxn];

struct edge {
    int u, v;
    ll w;
};
vector<edge> edges;

struct point {
    int node;
    ll x, y, z;
};

int find(int x) {
    if(par[x] == x) return par[x];
    return par[x] = find(par[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    groups[x] += groups[y];
    if(x < y) swap(x, y);
    par[x] = y;
}

// N개의 수가 있을 때
// 임의의 두 수의 차이의 절댓값 |X-Y|은 정렬 때린다음에 인접한 두 수의 차이가 가장 작은 걸 찾으면 된다.
// 왜 그러냐면 두 수의 차이가 가장 작은게 정렬된 상태에서만 찾을 수 있기 때문이지
// [-5,-4,0,7] 의 배열이 있으면 -5와 0을 매칭하는 건 의미가 없지 왜냐면 더 가까운 수인 -4가 있으니까
// 직관적으로 이해가 되는 내용이라서 그냥 머릿속에 넣어두면 될듯
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i = 0; i < mxn; i++) par[i] = i;
    memset(groups, 1, sizeof(groups));

    // 크루스칼 알고리즘을 쓸건데
    // 결국 핵심은 선택해야 하는 간선의 개수를 최소로 만드는 것이 핵심 이구료?
    // 그라믄 X, Y, Z 좌표를 따로보고 따로 정렬을 하는게 좋을듯
    cin >> N;
    vector<point> ps(N);
    for(int i = 0; i < N; i++) {
        cin >> ps[i].x >> ps[i].y >> ps[i].z;
        ps[i].node = i+1;
    }

    // X 좌표를 기준으로 정렬
    sort(ps.begin(), ps.end(), [](point a, point b) {
        return a.x < b.x;
    });
    for(int i = 1; i < N; i++) {
        edges.push_back({ps[i-1].node, ps[i].node, abs(ps[i-1].x - ps[i].x)});
    }

    // Y 좌표를 기준으로 정렬
    sort(ps.begin(), ps.end(), [](point a, point b) {
        return a.y < b.y;
    });
    for(int i = 1; i < N; i++) {
        edges.push_back({ps[i-1].node, ps[i].node, abs(ps[i-1].y - ps[i].y)});
    }

    // Z 좌표를 기준으로 정렬
    sort(ps.begin(), ps.end(), [](point a, point b) {
        return a.z < b.z;
    });
    for(int i = 1; i < N; i++) {
        edges.push_back({ps[i-1].node, ps[i].node, abs(ps[i-1].z - ps[i].z)});
    }

    // 간선을 가중치 기준으로 정렬
    sort(edges.begin(), edges.end(), [](edge a, edge b) {
        return a.w < b.w;
    });

    ll ans = 0;
    for(auto e : edges) {
        if(find(e.u) == find(e.v)) continue;
        merge(e.u, e.v);
        if(groups[e.u] == N || groups[e.v] == N) break;
        ans += e.w;
    }
    cout << ans << endl;

    return 0;
}