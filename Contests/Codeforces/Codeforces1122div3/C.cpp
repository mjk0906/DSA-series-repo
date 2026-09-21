#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;

        cin >> n;
        cin >> s;

        // If the first character is 1,
        // the final sorted string must be all 1s.
        if (s[0] == '1') {
            int zeros = 0;

            for (char c : s) {
                if (c == '0')
                    zeros++;
            }

            cout << zeros << '\n';
            continue;
        }

        // s[0] == 0
        int zeros = 0;

        for (char c : s) {
            if (c == '0')
                zeros++;
        }

        int ones = 0;
        int ans = n;

        for (int i = 0; i < n; i++) {

            if (s[i] == '1') {
                ones++;
            } else {
                zeros--;
            }

            // positions [0..i] -> 0
            // positions [i+1..n-1] -> 1
            ans = min(ans, ones + zeros);
        }

        cout << ans << '\n';
    }

    return 0;
} 