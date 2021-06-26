#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> row_blocks;

set<tuple<int, int, int>> vis;

bool dfs(int row, int start, int end) {
  vis.insert({row, start, end});
  if(row == N && end == M) {
    return true;
  }

  vector<int> next;
  if(row != N) {
    next = row_blocks[row + 1];
    for(int i = 0; i < next.size() - 1; i++) {
      if(next[i] == next[i + 1] - 1 || end < next[i] + 1 || start > next[i + 1] - 1) {
        continue;
      }
      if(!vis.count({row + 1, next[i] + 1, next[i + 1] - 1}) && dfs(row + 1, next[i] + 1, next[i + 1] - 1)) {
        return true;
      }
    }
  }
  if(row != 1) {
    next = row_blocks[row - 1];
    for(int i = 0; i < next.size() - 1; i++) {
      if(next[i] == next[i + 1] - 1 || end < next[i] + 1 || start > next[i + 1] - 1) {
        continue;
      }
      if(!vis.count({row - 1, next[i] + 1, next[i + 1] - 1}) && dfs(row - 1, next[i] + 1, next[i + 1] - 1)) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int K;
  cin >> N >> M >> K;
  row_blocks.resize(N + 1);
  for(int i = 1; i <= N; i++) {
    row_blocks[i].push_back(0), row_blocks[i].push_back(M + 1);
  }
  while(K--) {
    int r_i, c_i;
    cin >> r_i >> c_i;
    row_blocks[r_i].push_back(c_i);
  }
  for(int i = 1; i <= N; i++) {
    sort(row_blocks[i].begin(), row_blocks[i].end());
  }

  bool ans = dfs(1, row_blocks[1][0] + 1, row_blocks[1][1] - 1);
  cout << (ans ? "YES" : "NO") << '\n';

  return 0;
}