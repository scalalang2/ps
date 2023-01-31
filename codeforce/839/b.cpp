#include<bits/stdc++.h>

using namespace std;

int t;
int matrix[2][2];

void transform(int matrix[2][2]) {
    int a,b,c,d;
    a = matrix[0][0];
    b = matrix[0][1];
    c = matrix[1][0];
    d = matrix[1][1];
    matrix[0][0] = c;
    matrix[0][1] = a;
    matrix[1][1] = b;
    matrix[1][0] = d;
}

bool good(int matrix[2][2]) {
    return matrix[0][0] < matrix[0][1] && matrix[1][0] < matrix[1][1] &&
        matrix[0][0] < matrix[1][0] && matrix[0][1] < matrix[1][1];
}

void p(int matrix[2][2]) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j< 2; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for(int k = 0; k < t; k++) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                cin >> matrix[i][j];
            }
        }
        
        int tries = 4;
        while(tries--) {
            if(good(matrix)) {
                cout << "YES" << endl;
                break;
            }
            transform(matrix);
        }

        if(!good(matrix)) cout << "NO" << endl;
    }

    return 0;
}