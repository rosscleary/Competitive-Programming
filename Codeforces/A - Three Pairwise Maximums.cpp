#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  int x, y, z;
  cin >> x >> y >> z;
 
  int largest = max(max(x, y), z);
 
  if((x == largest) + (y == largest) + (z == largest) == 1) {
    cout << "NO\n";
    return;
  }
 
  int a, b, c;
  if(x == largest && y == largest) {
    a = largest, b = z, c = z;
  } else if(x == largest && z == largest) {
    b = largest, a = y, c = y;
  } else {
    c = largest, a = x, b = x;
  }
 
  cout << "YES\n";
  cout << a << ' ' << b << ' ' << c << '\n';
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