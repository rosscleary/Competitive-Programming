#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, T;
  cin >> N >> T;
  vector<vector<pair<int, int>>> adj(N + 1);
  while(T--) {
    int x, y, C;
    cin >> x >> y >> C;
    adj[x].push_back(make_pair(y, C));
    adj[y].push_back(make_pair(x, C));
  }
  int K;
  cin >> K;
  vector<int> city_costs(N + 1, -1);
  while(K--) {
    int z, P_z;
    cin >> z >> P_z;
    city_costs[z] = P_z;
  }
  int D;
  cin >> D;

  vector<int> dist(N + 1);
  for(int i = 1; i <= N; i++) {
    dist[i] = INT_MAX;
  }
  set<pair<int, int>> pq;
  dist[D] = 0;
  pq.insert(make_pair(0, D));

  while(!pq.empty()) {
    int curr = pq.begin()->second;
    pq.erase(pq.begin());
    for(int i = 0; i < adj[curr].size(); i++) {
      pair<int, int> curr_check = adj[curr][i];
      if(dist[curr] + curr_check.second < dist[curr_check.first]) {
        dist[curr_check.first] = dist[curr] + curr_check.second;
        pq.insert(make_pair(dist[curr_check.first], curr_check.first));
      }
    }
  }

  int ans = INT_MAX;
  for(int i = 1; i <= N; i++) {
    if(city_costs[i] != -1) {
      ans = min(ans, city_costs[i] + dist[i]);
    }
  }

  cout << ans << '\n';

  return 0;
}