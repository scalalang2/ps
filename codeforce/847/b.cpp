#include<bits/stdc++.h>

using namespace std;

int a[51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, s, r;
        cin >> n >> s >> r;
        int largest = s - r;
        for(int i = 0; i < n; i++) {
            a[i] = largest;
        }

        int sum = largest * n;
        int rotated_index = 0;
        while(sum > s) {
            a[rotated_index] -= 1;
            sum--;
            rotated_index++;
            if (rotated_index == n-1)
                rotated_index = 0;
        }

        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}