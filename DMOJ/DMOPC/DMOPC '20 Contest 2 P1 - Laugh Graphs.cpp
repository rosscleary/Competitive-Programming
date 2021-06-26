#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e3 + 5;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  string moves;
  cin >> moves;

  vector<vector<char>> grid(2 * M1, vector<char>(N));
  for(int i = 0; i < grid.size(); i++) {
    for(int j = 0; j < N; j++) {
      grid[i][j] = '.';
    }
  }

  int r = M1, c = 0;
  for(int i = 0; i < N; i++) {
    if(moves[i] == '^') {
      grid[r][c] = '/';
      r--, c++;
    } else if(moves[i] == '>') {
      grid[r][c] = '_';
      c++;
    } else {
      r++;
      grid[r][c] = '\\';
      c++;
    }
  }

  for(int i = 0; i < grid.size(); i++) {
    bool print = false;
    for(int j = 0; j < N; j++) {
      if(grid[i][j] != '.') {
        print = true;
        break;
      } 
    }
    if(!print) {
      continue;
    }
    for(int j = 0; j < N; j++) {
      cout << grid[i][j];
    }
    cout << '\n';
  }

  return 0;
}