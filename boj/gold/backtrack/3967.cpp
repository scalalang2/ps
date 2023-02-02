#include<bits/stdc++.h>

using namespace std;

using pp = pair<int, int>;

// magic star
const int ROW = 5;
const int COL = 9;
int table[ROW][COL];

pp coords[12] = {
    {0, 4}, 
    {1, 1}, {1, 3},{1, 5}, {1, 7}, 
    {2, 2}, {2, 6}, 
    {3, 1}, {3, 3}, {3, 5}, {3, 7}, 
    {4, 4}
};

vector<int> get_fields(int r, int c) {
    vector<int> ret;
    if(r == 0 && c == 4) ret.insert(ret.end(), {0,1});
    if(r == 1 && c == 1) ret.insert(ret.end(), {2,3});
    if(r == 1 && c == 3) ret.insert(ret.end(), {2,0});
    if(r == 1 && c == 5) ret.insert(ret.end(), {2,1});
    if(r == 1 && c == 7) ret.insert(ret.end(), {2,5});
    if(r == 2 && c == 2) ret.insert(ret.end(), {0,3});
    if(r == 2 && c == 6) ret.insert(ret.end(), {1,5});
    if(r == 3 && c == 1) ret.insert(ret.end(), {0,4});
    if(r == 3 && c == 3) ret.insert(ret.end(), {3,4});
    if(r == 3 && c == 5) ret.insert(ret.end(), {5,4});
    if(r == 3 && c == 7) ret.insert(ret.end(), {1,4});
    if(r == 4 && c == 4) ret.insert(ret.end(), {3,5});
    return ret;
}

int acc[6] = {0,};
int nfields[6] = {0,};
bool checked[13] = {false,};
set<int> filled;
set<int> unfill;

void search(int idx, int k) {
    if(k == unfill.size()) {
        for(int i = 0; i < 6; i++) {
            if(acc[i] != 26) return;
        }
        for(int i = 0; i < ROW; i++) {
            for(int j = 0; j < COL; j++) {
                if(table[i][j] == -1) cout << '.';
                else cout << (char)(table[i][j] + 'A' - 1);
                // else cout << table[i][j];
            }
            cout << endl;
        }
        exit(0);
    }

    int y = coords[idx].first;
    int x = coords[idx].second;

    if(table[y][x] != -2) {
        search(idx + 1, k);
        return;
    }

    for(int num = 1; num <= 12; num++) {
        if(checked[num]) continue;
        vector<int> fields = get_fields(y, x);
        for(auto f : fields) {
            acc[f] += num;
            nfields[f]++;
        }
        table[y][x] = num;
        bool gonext = true;
        for(auto f : fields) {
            if((acc[f] != 26 && nfields[f] == 4) || acc[f] > 26) {
                gonext = false;
                break;
            }
        }
        checked[num] = true;
        if(gonext) search(idx+1,k + 1);
        checked[num] = false;
        table[y][x] = -2;
        for(auto f : fields) {
            acc[f] -= num;
            nfields[f]--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i = 0; i < ROW; i++) {
        string line;
        cin >> line;
        for(int j = 0; j < COL; j++) {
            char c;
            c = line[j];
            
            if(c == '.') table[i][j] = -1;
            else if(c == 'x') table[i][j] = -2;
            else {
                table[i][j] = c - 'A' + 1;
                filled.insert(table[i][j]);

                checked[table[i][j]] = true;
                vector<int> fields = get_fields(i, j);
                for(auto f : fields) {
                    acc[f] += table[i][j];
                    nfields[f]++;
                }
            }
        }
    }

    for(int i = 1; i <= 12; i++) {
        if(filled.find(i) == filled.end()) unfill.insert(i);
    }

    search(0, 0);

    return 0;
}