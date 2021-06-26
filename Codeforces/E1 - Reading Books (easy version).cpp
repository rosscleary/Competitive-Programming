#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int n, k;
  cin >> n >> k;
  vector<int> alice, bob, both;
  for(int i = 0; i < n; i++) {
    int t_i, a_i, b_i;
    cin >> t_i >> a_i >> b_i;
    if(a_i && b_i) {
      both.push_back(t_i);
    } else if(a_i) {
      alice.push_back(t_i);
    } else if(b_i) {
      bob.push_back(t_i);
    }
  }
 
  if(min(alice.size(), bob.size()) + both.size() < k) {
    cout << -1 << '\n';
    return 0;
  }
 
  sort(alice.begin(), alice.end()), sort(bob.begin(), bob.end()), sort(both.begin(), both.end());
  int individual_i = 0, both_i = 0;
  int ans = 0;
  for(int take = 1; take <= k; take++) {
    int M1 = 2e9;
    int option_1 = M1, option_2 = M1;
    if(individual_i < min(alice.size(), bob.size())) {
      option_1 = alice[individual_i] + bob[individual_i];
    }
    if(both_i < both.size()) {
      option_2 = both[both_i];
    }
    if(option_1 < option_2) {
      ans += option_1, individual_i++;
    } else {
      ans += option_2, both_i++;
    }
  }
 
  cout << ans << '\n';
 
  return 0;
}