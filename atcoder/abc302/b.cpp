#include<bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;

const int maxn = 101;

char c[5] = {'s' ,'n', 'u', 'k', 'e'};
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

char table[maxn][maxn];
bool visited[maxn][maxn];
int h, w;
vector<pi> ans;

bool inrange(int x, int y) {
    return x >= 1 && x <= w && y >= 1 && y <= h;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> h >> w;
    for(int i = 1; i <= h; i++) {
        string x;
        cin >> x;
        for(int j = 1; j <= w; j++) {
            table[i][j] = x[j - 1];
        }
    }

    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            if(table[i][j] != 's') continue;
            for(int k = 0; k < 8; k++) {
                vector<pi> ans;
                ans.push_back({i, j});
                for(int pos = 1; pos <= 4; pos++) {
                    int nx = j + dx[k] * pos;
                    int ny = i + dy[k] * pos;
                    if (inrange(nx, ny) && table[ny][nx] == c[pos]) {
                        ans.push_back({ny, nx});
                    }
                }
                if (ans.size() == 5)
                {
                    for (auto x : ans)
                    {
                        cout << x.first << " " << x.second << endl;
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}