#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M1 = 2e3 + 1, p = 53, m = 104395303;

string text;
vector<int> ppow;
vector<int> pref_hash;

int hsh(int i, int j) {
  return ((pref_hash[j] - pref_hash[i - 1] + m) * ppow[text.size() - j]) % m;
}

void solve() {
  cin >> text;
  text = ' ' + text;

  pref_hash.resize(text.length());
  for(int i = 1; i < text.length(); i++) {
    pref_hash[i] = (pref_hash[i - 1] + (text[i] - 'A' + 1) * ppow[i]) % m;
  }

  vector<int> dp(text.length() + 1);
  int ans = 0;
  for(int i = text.length() - 1; i > 0; i--) {
    for(int l = 2; i + l - 1 < text.size(); l += 2) {
        if(hsh(i, i + l / 2 - 1) == hsh(i + l / 2, i + l - 1)) {
          dp[i] = max(dp[i], l + dp[i + l]);
        }
    }
    ans = max(ans, dp[i]);
  }

  cout << ans << '\n';
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  ppow.resize(M1);
  ppow[1] = 1;
  for(int i = 2; i < M1; i++) {
    ppow[i] = (p * ppow[i - 1]) % m;
  }

  int test_case = 10;
  while(test_case--) {
    solve();
  }

  return 0;
}