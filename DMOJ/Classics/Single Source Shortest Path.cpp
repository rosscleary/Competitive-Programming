#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> adj(N + 1);
  while(M--) {
    int u_i, v_i, w_i;
    cin >> u_i >> v_i >> w_i;
    adj[u_i].push_back({v_i, w_i});
    adj[v_i].push_back({u_i, w_i});
  }

  set<pair<int, int>> pq;
  vector<int> dist(N + 1, INT_MAX);
  pq.insert({0, 1});
  dist[1] = 0;
  while(!pq.empty()) {
    int curr = pq.begin()->second;
    pq.erase(pq.begin());
    for(int i = 0; i < adj[curr].size(); i++) {
      int next = adj[curr][i].first, weight = adj[curr][i].second;
      if(dist[next] > dist[curr] + weight) {
        dist[next] = dist[curr] + weight;
        pq.insert({dist[next], next});
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    if(dist[i] != INT_MAX) {
      cout << dist[i] << '\n';
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}