#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e9;

int N;
vector<vector<pair<int, int>>> adj;

vector<int> bfs(int start) {
  queue<int> q;
  vector<bool> vis(N + 1);
  vector<int> dist(N + 1);
  q.push(start), vis[start] = true;
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    for(pair<int, int> i: adj[curr]) {
      if(!vis[i.first]) {
        q.push(i.first), vis[i.first] = true, dist[i.first] = dist[curr] + i.second;
      }
    }
  }

  return dist;
}

pair<int, int> longest(vector<int> dist) {
  int longest_value = 0, longest_i;
  for(int i = 1; i <= N; i++) {
    if(dist[i] > longest_value) {
      longest_value = dist[i], longest_i = i;
    }
  }

  return {longest_value, longest_i};
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> N;
  adj.resize(N + 1);
  for(int i = 0; i < N - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w}), adj[v].push_back({u, w});
  }

  int end_1 = longest(bfs(1)).second;
  pair<int, int> diameter = longest(bfs(end_1));
  cout << diameter.first << '\n';

  int end_2 = diameter.second;
  vector<int> bfs_1 = bfs(end_1), bfs_2 = bfs(end_2);
  int radius = M1;
  for(int i = 1; i <= N; i++) {
    radius = min(radius, max(bfs_1[i], bfs_2[i]));
  }
  cout << radius << '\n';

  return 0;
}