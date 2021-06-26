#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  int n;
  cin >> n;
  vector<vector<int>> pref_freq(201, vector<int>(n + 1)), occur(201);
  for(int i = 1; i <= n; i++) {
    int a_i;
    cin >> a_i;
    occur[a_i].push_back(i);
    for(int j = 1; j <= 200; j++) {
      pref_freq[j][i] = pref_freq[j][i - 1], pref_freq[j][i] += a_i == j;
    }
  }
 
  int ans = 1;
  for(int i = 1; i <= 200; i++) {
    for(int l = 0, r = occur[i].size() - 1, cnt = 2; l < r; l++, r--, cnt += 2) {
      for(int j = 1; j <= 200; j++) {
        ans = max(ans, cnt + pref_freq[j][occur[i][r] - 1] - pref_freq[j][occur[i][l]]);
      }
    }
  }
 
  cout << ans << '\n';
}
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) {
    solve_tc();
  }
 
  return 0;
}