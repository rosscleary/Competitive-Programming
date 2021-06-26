#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve_tc() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  if(n & 1) {
    cout << "1\n";
    return;
  }
 
  sort(x.begin(), x.end()), sort(y.begin(), y.end());
  cout << (x[n / 2] - x[n / 2 - 1] + 1) * (y[n / 2] - y[n / 2 - 1] + 1) << '\n';
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