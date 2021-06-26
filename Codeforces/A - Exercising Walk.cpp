#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
int t;
int a, b, c, d;
int x, y, x_1, y_1, x_2, y_2;
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> t;
 
  while(t--) {
    cin >> a >> b >> c >> d;
    cin >> x >> y >> x_1 >> y_1 >> x_2 >> y_2;
 
    if ((x == x_1 && x == x_2 && (a != 0 || b != 0)) || (y == y_1 && y == y_2 && (c!= 0 || d !=0))) {
      cout << "NO\n";
      continue;
    }
 
    bool left_right = false, up_down = false;
 
    if (a == b) {
      left_right = true;
    }
    if (a > b && a - b <= x - x_1) {
      left_right = true;
    }
    if (b > a && b - a <= x_2 - x) {
      left_right = true;
    }
 
    if (c == d) {
      up_down = true;
    }
    if (c > d && c - d <= y - y_1) {
      up_down = true;
    } 
    if (d > c && d - c <= y_2 - y) {
      up_down = true;
    }
 
    if (left_right && up_down) cout << "YES\n";
    else cout << "NO\n";
  }
 
  return 0;
}