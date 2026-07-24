#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> freq(200001, 0);
    int mx = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        freq[x]++;
        mx = max(mx, x);
    }
    vector<int> cnt(mx + 2, 0);
    for (int i = mx; i >= 1; i--) {
        cnt[i] = cnt[i + 1] + freq[i];
    }
    int carry = 0;
    string ans = "";
    for (int i = 1; i <= mx; i++) {
        int cur = cnt[i] + carry;
        ans.push_back(char('0' + (cur % 10)));
        carry = cur / 10;
    }
  while (carry) {
        ans.push_back(char('0' + (carry % 10)));
        carry /= 10;
    }
    while (ans.size() > 1 && ans.back() == '0')
        ans.pop_back();
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}
