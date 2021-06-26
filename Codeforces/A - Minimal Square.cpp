#include <bits/stdc++.h>
using namespace std;
 
void solve() {
  int a, b;
  cin >> a >> b;
  int answer = pow(max(max(a, b), 2 * min(a, b)), 2);
  cout << answer << '\n';
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve();
 
  return 0;
}