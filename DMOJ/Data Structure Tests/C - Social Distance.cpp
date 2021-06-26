#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  int n, k;
  cin >> n >> k;
  vector<int> filled_indices;
  filled_indices.push_back(-1);
  for(int i = 0; i < n; i++) {
    char s_i;
    cin >> s_i;
    if(s_i == '1') {
      filled_indices.push_back(i);
    }
  }
  filled_indices.push_back(n);
 
  if(filled_indices.size() == 2) {
    cout << 1 + (n - 1) / (k + 1) << '\n';
    return;
  }
 
  int ans = 0;
  for(int i = 1; i < filled_indices.size(); i++) {
    if(i == 1 || i == filled_indices.size() - 1) {
      ans += max(0, (filled_indices[i] - filled_indices[i - 1] - 1) / (k + 1));
    } else {
      ans += max(0, (filled_indices[i] - filled_indices[i - 1] - 1 - k) / (k + 1));
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