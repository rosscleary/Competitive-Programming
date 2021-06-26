#include <bits/stdc++.h>
using namespace std;
 
int t = 1;
int grid[9][9];
 
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
 
  cin >> t;
 
  while(t--) {
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
        char value;
        cin >> value;
        grid[i][j] = value - '0';
      }
    }
 
    int row = 0, col = 0;
    for(int i = 0; i < 3; i++) {
      if(grid[row][col] == 9) grid[row][col] = 1;
      else grid[row][col]++;
      row++;
      col += 3;
    }
    row = 3, col = 1;
    for(int i = 0; i < 3; i++) {
      if(grid[row][col] == 9) grid[row][col] = 1;
      else grid[row][col]++;
      row++;
      col += 3;
    }
    row = 6, col = 2;
    for(int i = 0; i < 3; i++) {
      if(grid[row][col] == 9) grid[row][col] = 1;
      else grid[row][col]++;
      row++;
      col += 3;
    }
 
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
        cout << grid[i][j];
      }
      cout << "\n";
    }
  }
 
  return 0;
}