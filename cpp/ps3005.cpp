#include <bits/stdc++.h>

using namespace std;

string text[21];
vector<string> tmp;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> text[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            string txt;
            if(i == 0 || text[i-1][j] == '#') {
                for(int k = i; k < n; k++) {
                    if (text[k][j] == '#') break;
                    txt += text[k][j];
                }
            }

            string txt2;
            if(j == 0 || text[i][j-1] == '#') {
                for (int kk = j; kk < m; kk++){
                    if (text[i][kk] == '#') break;
                    txt2 += text[i][kk];
                }
            }

            if (txt.size() >= 2) tmp.push_back(txt);
            if (txt2.size() >= 2) tmp.push_back(txt2);
        }
    }

    sort(tmp.begin(), tmp.end());

    cout << tmp[0] << endl;

    return 0;
}