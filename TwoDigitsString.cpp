#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string a, b;
        cin >> a >> b;

        vector<int> pa(a.size() + 1, 0), pb(b.size() + 1, 0);

        for (int i = 0; i < (int)a.size(); i++)
            pa[i + 1] = (pa[i] + (a[i] - '0')) % 10;

        for (int i = 0; i < (int)b.size(); i++)
            pb[i + 1] = (pb[i] + (b[i] - '0')) % 10;

        // Total sums modulo 10 must be equal.
        if (pa.back() != pb.back()) {
            cout << -1 << "\n";
            continue;
        }

        int n = pa.size(), m = pb.size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (pa[i] == pb[j])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }

        cout << dp[n - 1][m - 1] << "\n";
    }

    return 0;
}
