#include <bits/stdc++.h>
using namespace std;

int r, c;
vector<vector<char>> grid;
int m;
vector<char> moves(m);

void update_orient(int &orient) {
  if(orient < 0) {
    orient = 3;
  } else if(orient > 3) {
    orient = 0;
  }
}

void solve(int i, int row, int col, int orient) {
  if(row < 0 || row >= r || col < 0 || col >= c || grid[row][col] == 'X') {
    return;
  }
  if(i == m) {
    grid[row][col] = '*';
    return;
  }

  if(moves[i] == 'F') {
    if(orient == 0) {
      row--;
    } else if(orient == 1) {
      col++;
    } else if(orient == 2) {
      row++;
    } else {
      col--;
    }
  } else if(moves[i] == 'L') {
    orient--, update_orient(orient);
  } else {
    orient++, update_orient(orient);
  }

  solve(i + 1, row, col, orient);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> r >> c;
  grid.resize(r, vector<char>(c));
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> grid[i][j];
    }
  }

  cin >> m;
  moves.resize(m);
  for(int i = 0; i < m; i++) {
    cin >> moves[i];
  }

  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      for(int k = 0; k < 4; k++) {
        solve(0, i, j, k);
      }
    }
  }

  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cout << grid[i][j];
    }
    cout << '\n';
  }

  return 0;
}