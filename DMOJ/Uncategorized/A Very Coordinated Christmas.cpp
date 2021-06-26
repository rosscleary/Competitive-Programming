#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<char>> grid;

bool valid(pair<int, int> i) {
  if(i.first >= 0 && i.first < N && i.second >= 0 && i.second < M && grid[i.first][i.second] != '#') {
    return true;
  }
  return false;
}

vector<vector<int>> bfs(pair<int, int> start) {
  queue<pair<int, int>> q;
  vector<vector<bool>> seen(N, vector<bool>(M));
  vector<vector<int>> dist(N, vector<int>(M));
  q.push(start);
  seen[start.first][start.second] = true;
  while(!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    if(valid({curr.first + 1, curr.second}) && !seen[curr.first + 1][curr.second]) {
      q.push({curr.first + 1, curr.second});
      seen[curr.first + 1][curr.second] = true;
      dist[curr.first + 1][curr.second] = dist[curr.first][curr.second] + 1;
    }
    if(valid({curr.first - 1, curr.second}) && !seen[curr.first - 1][curr.second]) {
      q.push({curr.first - 1, curr.second});
      seen[curr.first - 1][curr.second] = true;
      dist[curr.first - 1][curr.second] = dist[curr.first][curr.second] + 1;
    }
    if(valid({curr.first, curr.second + 1}) && !seen[curr.first][curr.second + 1]) {
      q.push({curr.first, curr.second + 1});
      seen[curr.first][curr.second + 1] = true;
      dist[curr.first][curr.second + 1] = dist[curr.first][curr.second] + 1;
    }
    if(valid({curr.first, curr.second - 1}) && !seen[curr.first][curr.second - 1]) {
      q.push({curr.first, curr.second - 1});
      seen[curr.first][curr.second - 1] = true;
      dist[curr.first][curr.second - 1] = dist[curr.first][curr.second] + 1;
    }
  }

  return dist;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> N >> M;
  pair<int, int> point_1, point_2, point_3;
  grid.resize(N, vector<char>(M));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> grid[i][j];
      if(grid[i][j] == 'O') {
        point_1 = {i, j};
      }
      if(grid[i][j] == 'P') {
        point_2 = {i, j};
      }
      if(grid[i][j] == 'X') {
        point_3 = {i, j};
      }
    }
  }

  vector<vector<int>> dist_1 = bfs(point_1);
  vector<vector<int>> dist_2 = bfs(point_2);
  if(dist_1[point_2.first][point_2.second] == 0 || dist_2[point_3.first][point_3.second] == 0) {
    cout << "-1\n";
    return 0;
  }
  int ans = dist_1[point_2.first][point_2.second] + dist_2[point_3.first][point_3.second];
  cout << ans << '\n';

  return 0;
}