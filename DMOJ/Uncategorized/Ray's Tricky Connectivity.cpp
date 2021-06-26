#include <bits/stdc++.h>
using namespace std;

const int M1 = 4e5 + 1;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M, Q;
  cin >> N >> M >> Q;
  vector<vector<pair<int, int>>> adj(N + 1);
  while(M--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back({b, 0});
  }
  vector<pair<int, int>> queries;
  for(int i = 1; i <= Q; i++) {
    char type;
    cin >> type;
    if(type == '?') {
      int x;
      cin >> x;
      queries.push_back({x, i});
    } else {
      int x, y;
      cin >> x >> y;
      adj[x].push_back({y, i});
    }
  }

  set<pair<int, int>> q;
  vector<int> dist(N + 1);
  q.insert({0, 1});
  for(int i = 1; i <= N; i++) {
    dist[i] = M1;
  }
  dist[1] = 0;
  while(!q.empty()) {
    auto curr = q.begin()->second;
    q.erase(q.begin());
    for(auto i: adj[curr]) {
      if(max(dist[curr], i.second) < dist[i.first]) {
        dist[i.first] = max(dist[curr], i.second);
        q.insert({dist[i.first], i.first});
      }
    }
  }

  for(auto i: queries) {
    if(dist[i.first] < i.second) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << '\n';
  }

  return 0;
}