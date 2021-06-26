#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e9;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> adj(N + 1);
  for(int i = 0; i < M; i++) {
    int A_i, B_i, W_i;
    cin >> A_i >> B_i >> W_i;
    adj[A_i].push_back({B_i, W_i}), adj[B_i].push_back({A_i, W_i});
  }

  set<pair<int, int>> q;
  vector<pair<int, int>> dist(N + 1);
  q.insert({0, 1});
  dist[1].second = M1;
  for(int i = 2; i <= N; i++) {
    dist[i] = {M1, M1};
  }
  while(!q.empty()) {
    auto curr = *q.begin();
    q.erase(q.begin());
    for(auto i: adj[curr.second]) {
      vector<int> opts = {dist[i.first].first, dist[i.first].second, curr.first + i.second};
      sort(opts.begin(), opts.end());
      if(opts[0] != dist[i.first].first && opts[0] != dist[i.first].second) {
        q.insert({opts[0], i.first});
      }
      if(opts[1] != dist[i.first].first && opts[1] != dist[i.first].second) {
        q.insert({opts[1], i.first});
      }
      dist[i.first] = {opts[0], opts[1]};
    }
  }

  cout << dist[N].second << '\n';

  return 0;
}