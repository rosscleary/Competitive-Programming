#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  int n;
  cin >> n;
  string b;
  cin >> b;
 
  int last = -1;
  for(int i = 0; i < n; i++) {
    if(b[i] - '0' + 1 != last) {
      cout << 1;
      last = b[i] - '0' + 1;
    } else {
      cout << 0;
      last = b[i] - '0';
    }
  }
  cout << '\n';
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