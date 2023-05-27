#include<bits/stdc++.h>

using namespace std;

int h, w;
vector<vector<int>> A;
vector<vector<int>> B;

void input(vector<vector<int>> &arr) {
    arr.resize(h);
    for(int i = 0; i < h; i++) {
        string x;
        cin >> x;
        arr[i].resize(w);
        for(int j = 0; j < w; j++) {
            if(x[j] == '#') arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
}

bool good() {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) { 
            if(A[i][j] != B[i][j]) return false;
        }
    }

    return true;
}

void shift_to_bottom() {
    vector<vector<int>> tmp(h);
    for(int i = 1; i < h; i++) {
        tmp[i].resize(w);
        for(int j = 0; j < w; j++)  {
            tmp[i][j] = A[i-1][j];
        }
    }
    tmp[0].resize(w);
    for(int i = 0; i < w; i++) tmp[0][i] = A[h-1][i];
    A = tmp;
}

void shift_to_left() {
    vector<vector<int>> tmp(h);
    for(int i = 0; i < h; i++) {
        tmp[i].resize(w);
        for(int j = 1; j < w; j++) {
            tmp[i][j] = A[i][j-1];
        }
    }
    for(int i = 0; i < h; i++) tmp[i][0] = A[i][w-1];
    A = tmp;
}

void print() {
    cout << "A ==" << endl;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) cout << A[i][j] << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> h >> w;
    input(A);
    input(B);

    if (good()) {
        cout << "Yes";
        return 0;
    }

    for(int i = 0; i <= h; i++) {
        shift_to_bottom();
        for(int j = 0; j <= w; j++) {
            shift_to_left();
            if(good()) {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";

    return 0;
}