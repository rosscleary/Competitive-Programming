#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M1 = 1e9 + 7;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  string S;
  cin >> S;

  map<char, int> freq;
  for(auto i: S) {
    freq[i]++;
  }

  int ans = 1;
  for(auto i: freq) {
    ans *= (i.second + 1), ans %= M1;
  }

  cout << ans << '\n';

  return 0;
}