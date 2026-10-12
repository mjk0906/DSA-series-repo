#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        stack<int> st;
        vector<bool> printed(n + 1, false);

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '1') {
                st.push(i);
            }
            else if (s[i - 1] == '2') {
                if (!st.empty()) {
                    printed[st.top()] = true;
                    st.pop();
                } else {
                    printed[i] = true;   // fix: memory empty -> print document i
                }
            }
            else {
                printed[i] = true;
            }
        }

        int k = 0;
        for (int i = 1; i <= n; i++)
            if (!printed[i]) k++;

        cout << k << '\n';          // fix: print count first
        for (int i = 1; i <= n; i++)
            if (!printed[i]) cout << i << " ";
        cout << '\n';
    }
    return 0;
}
