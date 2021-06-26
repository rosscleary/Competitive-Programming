#include <bits/stdc++.h>
using namespace std;
 
bool prime(int num) {
  if(num == 2) {
    return true;
  }
 
  for(int div = 2; div * div <= num; div++) {
    if(num % div == 0) {
      return false;
    }
  }
 
  return true;
}
 
void solve_tc() {
  int d;
  cin >> d;
 
  int pick;
  for(pick = 1 + d; !prime(pick); pick++) {
 
  }
  int ans = pick;
  for(pick += d; !prime(pick); pick++) {
 
  }
  ans *= pick;
  
  cout << ans << '\n';
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