#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve_tc() {
  int n;
  cin >> n;
  vector<int> h(n);
  for(int i = 0; i < n; i++) {
    cin >> h[i];
  }
 
  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += h[i];
    if(sum < i * (i + 1) / 2) {
      cout << "NO\n";
      return;
    }
  }
 
  cout << "YES\n";
}
 
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) {
    solve_tc();
  }
 
  return 0;
}