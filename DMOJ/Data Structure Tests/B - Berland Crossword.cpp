#include <bits/stdc++.h>
using namespace std;
 
int n, U, R, D, L;
 
bool possible(int check) {
  int U_cnt = U, R_cnt = R, D_cnt = D, L_cnt = L;
  if(check & 8) {
    U_cnt--, L_cnt--;
  }
  if(check & 4) {
    U_cnt--, R_cnt--;
  }
  if(check & 2) {
    R_cnt--, D_cnt--;
  }
  if(check & 1) {
    D_cnt--, L_cnt--;
  }
 
  if(U_cnt < 0 || R_cnt < 0 || D_cnt < 0 || L_cnt < 0) {
    return false;
  }
  if(U_cnt <= n - 2 && R_cnt <= n - 2 && D_cnt <= n - 2 && L_cnt <= n - 2) {
    return true;
  }
  return false;
}
 
void solve_tc() {
  cin >> n >> U >> R >> D >> L;
 
  for(int check = 0; check < 16; check++) {
    if(possible(check)) {
      cout << "YES\n";
      return;
    }
  }
 
  cout << "NO\n";
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