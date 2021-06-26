#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> adj_start(N + 1);
  vector<vector<pair<int, int>>> adj_end(N + 1);
  while(M--) {
    int a, b, k;
    cin >> a >> b >> k;
    adj_start[a].push_back({b, k});
    adj_end[b].push_back({a, k});
  }

  set<pair<int, int>> pq_1;
  vector<int> dist_start(N + 1, LONG_LONG_MAX);
  pq_1.insert({0, 1});
  dist_start[1] = 0;
  while(!pq_1.empty()) {
    int curr = pq_1.begin()->second;
    pq_1.erase(pq_1.begin());
    for(int i = 0; i < adj_start[curr].size(); i++) {
      int next = adj_start[curr][i].first, edge_dist = adj_start[curr][i].second;
      if(dist_start[next] > dist_start[curr] + edge_dist) {
        dist_start[next] = dist_start[curr] + edge_dist;
        pq_1.insert({dist_start[next], next});
      }
    }
  }

  set<pair<int, int>> pq_2;
  vector<int> dist_end(N + 1, LONG_LONG_MAX);
  pq_2.insert({0, N});
  dist_end[N] = 0;
  while(!pq_2.empty()) {
    int curr = pq_2.begin()->second;
    pq_2.erase(pq_2.begin());
    for(int i = 0; i < adj_end[curr].size(); i++) {
      int next = adj_end[curr][i].first, edge_dist = adj_end[curr][i].second;
      if(dist_end[next] > dist_end[curr] + edge_dist) {
        dist_end[next] = dist_end[curr] + edge_dist;
        pq_2.insert({dist_end[next], next});
      }
    }
  }

  int D;
  cin >> D;
  int ans = LONG_LONG_MAX;
  if(dist_start[N] != LONG_LONG_MAX) {
    ans = dist_start[N];
  }
  while(D--) {
    int a, b, g;
    cin >> a >> b >> g;
    if(dist_start[a] != LONG_LONG_MAX && dist_end[b] != LONG_LONG_MAX) {
      ans = min(ans, dist_start[a] + dist_end[b] + g);
    }
  }

  if(ans == LONG_LONG_MAX) {
    cout << "-1\n";
  } else {
    cout << ans << '\n';
  }

  return 0;
}