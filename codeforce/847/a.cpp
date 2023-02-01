#include<bits/stdc++.h>

using namespace std;

int main()
{
    string pi = "3141592653589793238462643383279";

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        string input;
        cin >> input;
        int i = 0;
        for(; i < input.size(); i++) {
            if(input[i] != pi[i]) {
                break;
            }
        }
        cout << i << endl;
    }

    return 0;
}