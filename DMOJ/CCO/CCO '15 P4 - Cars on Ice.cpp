#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  vector<vector<char>> grid(N, vector<char>(M));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> grid[i][j];
    }
  }

  map<pair<int, int>, vector<pair<int, int>>> adj;
  vector<vector<int>> in_degree(N, vector<int>(M));

  for(int i = 0; i < N; i++) {
    string cars;
    vector<int> car_locs;
    for(int j = 0; j < M; j++) {
      if(grid[i][j] != '.') {
        cars += grid[i][j];
        car_locs.push_back(j);
      }
    }
    int first = cars.find('E'), last = cars.find_last_of('W');
    if(first != -1) {
      for(int j = first; j < cars.length() - 1; j++) {
        adj[{i, car_locs[j]}].push_back({i, car_locs[j + 1]});
        in_degree[i][car_locs[j + 1]]++;
      }
    }
    if(last != -1) {
      for(int j = last; j > 0; j--) {
        adj[{i, car_locs[j]}].push_back({i, car_locs[j - 1]});
        in_degree[i][car_locs[j - 1]]++;
      }
    }
  }
  for(int i = 0; i < M; i++) {
    string cars;
    vector<int> car_locs;
    for(int j = 0; j < N; j++) {
      if(grid[j][i] != '.') {
        cars += grid[j][i];
        car_locs.push_back(j);
      }
    }
    int first = cars.find('S'), last = cars.find_last_of('N');
    if(first != -1) {
      for(int j = first; j < cars.length() - 1; j++) {
        adj[{car_locs[j], i}].push_back({car_locs[j + 1], i});
        in_degree[car_locs[j + 1]][i]++;
      }
    }
    if(last != -1) {
      for(int j = last; j > 0; j--) {
        adj[{car_locs[j], i}].push_back({car_locs[j - 1], i});
        in_degree[car_locs[j - 1]][i]++;
      }
    }
  }

  queue<pair<int, int>> q;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(grid[i][j] != '.' && in_degree[i][j] == 0) {
        q.push({i, j});
      }
    }
  }
  vector<pair<int, int>> ans;
  while(!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    ans.push_back(curr);
    for(pair<int, int> i: adj[curr]) {
      if(--in_degree[i.first][i.second] == 0) {
        q.push(i);
      }
    }
  }

  for(int i = ans.size() - 1; i >= 0; i--) {
    cout << '(' << ans[i].first << ',' << ans[i].second << ")\n";
  }

  return 0;
}