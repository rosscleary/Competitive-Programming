#include <bits/stdc++.h>
using namespace std;
 
void solve() {
  int a_1, b_1, a_2, b_2;
  cin >> a_1 >> b_1 >> a_2 >> b_2;
  if(a_1 == a_2 && b_1 + b_2 == a_1) cout << "Yes\n";
  else if(a_1 == b_2 && a_2 + b_1 == a_1) cout << "Yes\n";
  else if(b_1 == a_2 && a_1 + b_2 == b_1) cout << "Yes\n";
  else if(b_1 == b_2 && a_1 + a_2 == b_1) cout << "Yes\n";
  else cout << "No\n";
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve();
 
  return 0;
}