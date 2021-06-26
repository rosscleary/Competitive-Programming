#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  string b;
  cin >> b;
 
  string a;
  a += b[0];
  for(int i = 1; i < b.length(); i += 2) {
    a += b[i];
  }
 
  cout << a << '\n';
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