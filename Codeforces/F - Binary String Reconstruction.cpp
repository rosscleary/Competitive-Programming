#include <bits/stdc++.h>
using namespace std;
 
void solve() {
  int n_0, n_1, n_2;
  cin >> n_0 >> n_1 >> n_2;
 
  if(n_1 == 0) {
    if(n_0 == 0) {
      for(int i = 0; i < n_2 + 1; i++) cout << '1';
    } else {
      for(int i = 0; i < n_0 + 1; i++) cout << '0';
    }
  } else {
    for(int i = 0; i < n_2 + 1; i++) cout << '1';
    for(int i = 0; i < n_0 + 1; i++) cout << '0';
    for(int i = 0; i < n_1 - 1; i++) cout << ((i % 2 == 0) ? '1' : '0');
  }
 
  cout << '\n';
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve();
 
  return 0;
}