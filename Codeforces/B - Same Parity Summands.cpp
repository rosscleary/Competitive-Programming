#include <bits/stdc++.h>
using namespace std;
 
void solve() {
  int n, k; cin >> n >> k;
 
  int even_option = n - (2 * (k - 1)), odd_option = n - (k - 1);
  if(even_option > 0 && even_option % 2 == 0) {
    cout << "YES\n";
    for(int i = 0; i < k - 1; i++) cout << "2 ";
    cout << even_option << '\n';
    return;
  }
  if(odd_option > 0 && odd_option % 2 == 1) {
    cout << "YES\n";
    for(int i = 0; i < k - 1; i++) cout << "1 ";
    cout << odd_option << '\n';
    return;
  }
  cout << "NO\n";
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve();
 
  return 0;
}