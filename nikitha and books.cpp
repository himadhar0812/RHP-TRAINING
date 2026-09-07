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

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long prev = 0;
        bool ok = true;

        for (int i = 0; i < n - 1; i++) {
            long long need = prev + 1;

            if (a[i] < need) {
                ok = false;
                break;
            }

            long long extra = a[i] - need;
            a[i + 1] += extra;
            prev = need;
        }

        if (ok && a[n - 1] >= prev + 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
