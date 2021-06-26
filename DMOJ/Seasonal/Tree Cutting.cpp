#include <bits/stdc++.h>
using namespace std;

const int M1 = 2e1 + 1, M2 = 1e3;

int R, C;
vector<vector<char>> grid(R, vector<char>(C));

set<pair<pair<int, int>, pair<int, int>>> q;
vector<vector<pair<int, int>>> dist;

bool tree(char i) {
  return i != '.' && i != 'X';
}

void update_next(pair<int, int> next, pair<int, int> curr) {
  int r = next.first, c = next.second;
  if(r >= 0 && r < R && c >= 0 && c < C) {
    bool next_tree = tree(grid[r][c]);
    int weight = next_tree ? grid[r][c] - '0' : 0;
    int curr_r = curr.first, curr_c = curr.second;
    if(dist[curr_r][curr_c].first + weight < dist[r][c].first) {
      dist[r][c].first = dist[curr_r][curr_c].first + weight, dist[r][c].second = dist[curr_r][curr_c].second + next_tree;
      q.insert({{dist[r][c]}, next});
    } else if(dist[curr_r][curr_c].first + weight == dist[r][c].first && dist[curr_r][curr_c].second + next_tree < dist[r][c].second) {
      dist[r][c].first = dist[curr_r][curr_c].first + weight, dist[r][c].second = dist[curr_r][curr_c].second + next_tree;
      q.insert({{dist[r][c]}, next});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> R >> C;
  grid.resize(R, vector<char>(C));
  int max_value = -1;
  pair<int, int> start;
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      cin >> grid[i][j];
      if(tree(grid[i][j])) {
        max_value = max(max_value, grid[i][j] - '0');
      }
      if(grid[i][j] == 'X') {
        start = {i, j};
      }
    }
  }

  pair<int, int> end;
  int min_dist = M1;
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      if(tree(grid[i][j]) && grid[i][j] - '0' == max_value && abs(i - start.first) + abs(j - start.second) < min_dist) {
        min_dist = abs(i - start.first) + abs(j - start.second);
        end = {i, j};
      }
    }
  }

  q.insert({{0, 0}, start});
  dist.resize(R, vector<pair<int, int>>(C));
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      dist[i][j] = {M2, M2};
    }
  }
  dist[start.first][start.second] = {0, 0};
  while(!q.empty()) {
    auto curr = q.begin()->second;
    q.erase(q.begin());
    update_next({curr.first - 1, curr.second}, curr), update_next({curr.first + 1, curr.second}, curr);
    update_next({curr.first, curr.second - 1}, curr), update_next({curr.first, curr.second + 1}, curr);
  }

  cout << dist[end.first][end.second].second - 1 << '\n';

  return 0;
}