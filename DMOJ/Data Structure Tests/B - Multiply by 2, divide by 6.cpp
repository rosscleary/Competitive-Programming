#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  int n;
  cin >> n;
 
  int two_pow_cnt = 0, three_pow_cnt = 0;
  while(n > 1) {
    if(n % 2 != 0 && n % 3 != 0) {
      cout << -1 << '\n';
      return;
    }
    if(n % 2 == 0) {
      n /= 2;
      two_pow_cnt++;
    } else {
      n /= 3;
      three_pow_cnt++;
    }
  }
 
  if(two_pow_cnt > three_pow_cnt) {
    cout << -1 << '\n';
    return;
  }
  cout << three_pow_cnt + (three_pow_cnt - two_pow_cnt) << '\n';
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