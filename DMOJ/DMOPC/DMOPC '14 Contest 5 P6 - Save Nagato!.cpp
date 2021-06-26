#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> adj;

int longest_path(int start) {
  queue<int> q;
  vector<bool> seen(N + 1);
  vector<int> dist(N + 1);
  q.push(start);
  seen[start] = true;
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    for(auto next: adj[curr]) {
      if(!seen[next]) {
        dist[next] = dist[curr] + 1;
        q.push(next);
        seen[next] = true;
      }
    }
  }

  int longest_path = 0, longest_i;
  for(int i = 1; i <= N; i++) {
    if(dist[i] > longest_path) {
      longest_path = dist[i];
      longest_i = i;
    }
  }

  return longest_i;
}

vector<int> bfs(int start) {
  queue<int> q;
  vector<bool> seen(N + 1);
  vector<int> dist(N + 1);
  q.push(start);
  seen[start] = true;
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    for(auto next: adj[curr]) {
      if(!seen[next]) {
        dist[next] = dist[curr] + 1;
        q.push(next);
        seen[next] = true;
      }
    }
  }

  return dist;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> N;
  adj.resize(N + 1);
  for(int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v), adj[v].push_back(u);
  }

  int end_1 = longest_path(1);
  int end_2 = longest_path(end_1);
  vector<int> dist_1 = bfs(end_1);
  vector<int> dist_2 = bfs(end_2);

  for(int i = 1; i <= N; i++) {
    cout << max(dist_1[i], dist_2[i]) + 1 << '\n';
  }

  return 0;
}