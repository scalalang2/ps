#include <bits/stdc++.h>
using namespace std;

vector<string> arr;

struct comp {
    inline bool operator()(const string a, const string b) {
        if (a.size() == b.size())
            return a < b;
        else
            return a.size() < b.size();
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--) {
        string txt;
        cin >> txt;
        arr.push_back(txt);
    }

    sort(arr.begin(), arr.end(), comp());

    for(int i = 0; i < arr.size(); i++) {
        if(i > 0) {
            if(arr[i-1] == arr[i]) 
                continue;
        }
        cout << arr[i] << endl;
    }
    return 0;
}