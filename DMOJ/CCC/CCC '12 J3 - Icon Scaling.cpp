#include <bits/stdc++.h>
using namespace std;

const vector<vector<char>> orig_grid {
  {'*', 'x', '*'},
  {' ', 'x', 'x'},
  {'*', ' ', '*'}
};

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int k;
  cin >> k;
  for(int i = 0; i < k * 3; i++) {
    for(int j = 0; j < k * 3; j++) {
      int orig_row = i / k, orig_col = j / k;
      cout << orig_grid[orig_row][orig_col];
    }
    cout << '\n';
  }

  return 0;
}