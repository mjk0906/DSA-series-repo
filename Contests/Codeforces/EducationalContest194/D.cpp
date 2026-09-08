#include <iostream>
#include <string>
using namespace std;

int main() {
    int qrTNum;
    cin >> qrTNum;

    while (qrTNum--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        bool possible = true;
        int ans = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == '0' && s[i - 1] == '0') {
                possible = false;
                break;
            }

            if ((s[i] == '+' && s[i - 1] == '-') ||
                (s[i] == '-' && s[i - 1] == '+')) {
                ans = 2;
            }
        }

        if (!possible) {
            cout << -1 << '\n';
        } else {
            cout << ans << '\n';
        }
    }

    return 0;
}