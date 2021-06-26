#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double

#define fast_inputandoutput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

// ---------- END OF TEMPLATE ---------- //

const int M1 = 1.5e3 + 5;

int N, H, grid[M1][M1];
queue<pair<int, int>> q; bool visited[M1][M1];

void process_next(int row, int col, int next_row, int next_col) {
  if(next_row >= 0 && next_row < N && next_col >= 0 && next_col < N && !visited[next_row][next_col]) {
    if(abs(grid[row][col] - grid[next_row][next_col]) <= H) {
      q.push(make_pair(next_row, next_col));
      visited[next_row][next_col] = true;
    }
  }
}

int32_t main() { fast_inputandoutput

  cin >> N >> H;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) cin >> grid[i][j];
  }

  q.push(make_pair(0, 0));
  visited[0][0] = true;
  while(!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    if(curr.first == N - 1 && curr.second == N - 1) {
      cout << "yes" << endl;
      return 0;
    }
    process_next(curr.first, curr.second, curr.first + 1, curr.second);
    process_next(curr.first, curr.second, curr.first - 1, curr.second);
    process_next(curr.first, curr.second, curr.first, curr.second + 1);
    process_next(curr.first, curr.second, curr.first, curr.second - 1);
  }
  cout << "no" << endl;

  return 0;
}