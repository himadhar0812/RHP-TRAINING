#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<long long> X(N), P(N);
    for (int i = 0; i < N; i++) cin >> X[i];
    for (int i = 0; i < N; i++) cin >> P[i];
    vector<long long> prefix(N + 1, 0);
    for (int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + P[i];
    }
    int Q;
    cin >> Q;
    while (Q--) {
        long long L, R;
        cin >> L >> R;
        int l = lower_bound(X.begin(), X.end(), L) - X.begin();
        int r = upper_bound(X.begin(), X.end(), R) - X.begin();
        cout << prefix[r] - prefix[l] << '\n';
    }
    return 0;
}
