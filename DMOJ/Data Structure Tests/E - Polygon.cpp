#include <bits/stdc++.h>
using namespace std;
 
void solve() {
  int n;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) cin >> grid[i][j];
  }
 
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(grid[i][j] == '1') {
        if(!(i == n - 1 || j == n - 1 || grid[i][j + 1] == '1' || grid[i + 1][j] == '1')) {
          cout << "NO\n";
          return;
        }
      }
    }
  }
  cout << "YES\n";
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve();
 
  return 0;
}