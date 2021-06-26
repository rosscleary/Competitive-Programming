#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> a(N);
  unordered_map<int, int> freq;
  for(int i = 0; i < N; i++) {
    cin >> a[i];
    freq[a[i]]++;
  }

  unordered_map<int, int> prod_freq;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(i == j) {
        continue;
      }
      prod_freq[a[i] * a[j]]++;
    }
  }

  int ans = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(i == j) {
        continue;
      }
      if(a[i] == a[j]) {
        ans += prod_freq[a[i] * a[j]] - 2 * (freq[a[i]] - 2) - 2 * (freq[a[j]] - 2) - 2;
      } else {
        ans += prod_freq[a[i] * a[j]] - 2 * (freq[a[i]] - 1) - 2 * (freq[a[j]] - 1) - 2;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}