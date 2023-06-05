#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<string> name;
    vector<int> age;

    for(int i = 0 ; i < n; i++) {
        string n;
        int a;
        cin >> n >> a;
        name.push_back(n);
        age.push_back(a);
    }

    int min_idx = 0;
    int min_age = 1e9+5;
    for(int i = 0; i < n; i++) {
        if(age[i] < min_age) {
            min_age = age[i];
            min_idx = i;
        }
    }

    for(int i = min_idx; i < n; i++) {
        cout << name[i] << endl;
    }

    for(int i = 0; i < min_idx; i++) {
        cout << name[i] << endl;
    }

    return 0;
}