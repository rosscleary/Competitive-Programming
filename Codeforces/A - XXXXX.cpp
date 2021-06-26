#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  int whole_sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    whole_sum += a[i];
  }
 
  if(whole_sum % x != 0) {
    cout << n << '\n';
    return;
  }
  int best_pref = n;
  for(int i = 0; i < n; i++) {
    if(a[i] % x != 0) {
      best_pref = i;
      break;
    }
  }
  int best_suff = -1;
  for(int i = n - 1; i >= 0; i--) {
    if(a[i] % x != 0) {
      best_suff = i;
      break;
    }
  }
 
  int ans = max(n - best_pref - 1, best_suff);
  if(!ans) cout << "-1\n";
  else cout << ans << '\n';
} 
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve_tc();
 
  return 0;
}