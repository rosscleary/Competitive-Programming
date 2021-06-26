#include <bits/stdc++.h>
using namespace std;
 
void solve() {
  int n;
  cin >> n;
 
  if(n < 4) {
    cout << "-1\n";
    return;
  }
  for(int out = n - !(n % 2); out > 0; out -= 2) cout << out << ' ';
  cout << "4 2 ";
  for(int out = 6; out <= n; out += 2) cout << out << ' ';
  cout << '\n';
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve();
 
  return 0;
}