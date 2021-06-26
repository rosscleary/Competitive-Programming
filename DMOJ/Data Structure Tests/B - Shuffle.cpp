#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  int n, x, m;
  cin >> n >> x >> m;
 
  int left = x, right = x;
  while(m--) {
    int l_i, r_i;
    cin >> l_i >> r_i;
    if(l_i <= left && r_i >= left) left = l_i;
    if(r_i >= right && l_i <= right) right = r_i;
  }
 
  cout << right - left + 1 << '\n';
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve_tc();
 
  return 0;
}