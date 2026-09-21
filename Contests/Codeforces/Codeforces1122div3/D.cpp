#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        unordered_set<long long> s;

        for (long long i = 1; i <= n; i++) {
            long long a;
            cin >> a;

            s.insert(a - i);
        }

        int ans = 0;

        for (long long x : s) {

            // x is the beginning of a consecutive sequence
            if (!s.count(x - 1)) {

                long long cur = x;
                int len = 1;

                while (s.count(cur + 1)) {
                    cur++;
                    len++;
                }

                ans = max(ans, len);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}