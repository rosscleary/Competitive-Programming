#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int R, C;
  cin >> R >> C;
  int start_x, start_y, end_x, end_y;
  cin >> start_x >> start_y >> end_x >> end_y;
  vector<vector<char>> grid(R, vector<char>(C));
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      cin >> grid[i][j];
    }
  }

  queue<pair<int, int>> q;
  vector<vector<int>> dist(R, vector<int>(C));
  vector<vector<int>> vis(R, vector<int>(C));
  q.push({start_x, start_y});
  vis[start_x][start_y] = true;
  while(!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    if(curr.first != 0) {
      if(!vis[curr.first - 1][curr.second] && grid[curr.first - 1][curr.second] == 'O') {
        dist[curr.first - 1][curr.second] = dist[curr.first][curr.second] + 1;
        vis[curr.first - 1][curr.second] = true;
        q.push({curr.first - 1, curr.second});
      }
    }
    if(curr.first != R - 1) {
      if(!vis[curr.first + 1][curr.second] && grid[curr.first + 1][curr.second] == 'O') {
        dist[curr.first + 1][curr.second] = dist[curr.first][curr.second] + 1;
        vis[curr.first + 1][curr.second] = true;
        q.push({curr.first + 1, curr.second});
      }
    }
    if(curr.second != 0) {
      if(!vis[curr.first][curr.second - 1] && grid[curr.first][curr.second - 1] == 'O') {
        dist[curr.first][curr.second - 1] = dist[curr.first][curr.second] + 1;
        vis[curr.first][curr.second - 1] = true;
        q.push({curr.first, curr.second - 1});
      }
    }
    if(curr.second != C - 1) {
      if(!vis[curr.first][curr.second + 1] && grid[curr.first][curr.second + 1] == 'O') {
        dist[curr.first][curr.second + 1] = dist[curr.first][curr.second] + 1;
        vis[curr.first][curr.second + 1] = true;
        q.push({curr.first, curr.second + 1});
      }
    }
  }

  int T;
  cin >> T;
  int ans = 0;
  while(T--) {
    int x, y;
    cin >> x >> y;
    if(vis[x][y]) {
      ans = max(ans, dist[end_x][end_y] - dist[x][y]);
    }
  }

  cout << ans << '\n';

  return 0;
}