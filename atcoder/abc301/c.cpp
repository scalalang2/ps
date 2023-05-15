#include<bits/stdc++.h>

using namespace std;

string S, T;

char pairs[] = {'a', 't', 'c', 'o', 'd', 'e', 'r'};

map<char, int> SM;
map<char, int> TM;
int atsign_S = 0;
int atsign_T = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> S >> T;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == '@') atsign_S++;
        else SM[S[i]]++;
    }

    for(int i = 0; i < T.size(); i++) {
        if(T[i] == '@') atsign_T++;
        else TM[T[i]]++;
    }

    for(char c = 'a'; c <= 'z'; c++) {
        bool flag = false;
        for(int k = 0; k < 7; k++) {
            if(c == pairs[k]) flag = true;
        }
        if(!flag) continue;

        if(SM[c] < TM[c]) {
            if(SM[c] + atsign_S >= TM[c]) {
                atsign_S -= TM[c] - SM[c];
                SM[c] += TM[c] - SM[c];
            }
        }

        if(SM[c] > TM[c]) {
            if(TM[c] + atsign_T >= SM[c]) {
                atsign_T -= SM[c] - TM[c];
                TM[c] += SM[c] - TM[c];
            }
        }
    }

    for(char c = 'a'; c <= 'z'; c++) {
        if(SM[c] != TM[c]) {
            cout << "No";
            return 0;
        }
    }

    if(atsign_S == atsign_T) cout << "Yes" << endl;
    else cout << "No";

    return 0;
}