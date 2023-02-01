#include<bits/stdc++.h>

using namespace std;

#define MAX 21

int table[MAX][MAX] = {0,};
int dice[4][4] = {0,};
/**
 * 1,1 윗면, 0,1 위, 0,2 아래, 0,3 바텀
 * 1,0 좌측, 1,2 우측
*/

const int EAST = 1;
const int WEST = 2;
const int NORTH = 3;
const int SOUTH = 4;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void roll(int dir) {
    int tmp;
    switch(dir) {
        case EAST: 
            tmp = dice[1][1];
            dice[1][1] = dice[1][0];
            dice[1][0] = dice[0][3];
            dice[0][3] = dice[1][2];
            dice[1][2] = tmp;
        break;
        case WEST:
            tmp = dice[1][1];
            dice[1][1] = dice[1][2];
            dice[1][2] = dice[0][3];
            dice[0][3] = dice[1][0];
            dice[1][0] = tmp;
        break;
        case NORTH:
            tmp = dice[1][1];
            dice[1][1] = dice[0][2];
            dice[0][2] = dice[0][3];
            dice[0][3] = dice[0][1];
            dice[0][1] = tmp;
        break;
        case SOUTH:
            tmp = dice[1][1];
            dice[1][1] = dice[0][1];
            dice[0][1] = dice[0][3];
            dice[0][3] = dice[0][2];
            dice[0][2] = tmp;
        break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, y, x, k;
    cin >> n >> m >> y >> x >> k;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }

    while(k--) {
        int d;
        cin >> d;
        int nx = x + dx[d-1];
        int ny = y + dy[d-1];
        if(!(nx >= 0 && nx < m && ny >= 0 && ny < n)) {
            continue;
        }

        roll(d);
        if(table[ny][nx] != 0) {
            dice[0][3] = table[ny][nx];
            table[ny][nx] = 0;
        } else {
            table[ny][nx] = dice[0][3];
        }
        x = nx;
        y = ny;
        cout << dice[1][1] << endl;
    }

    return 0;
}