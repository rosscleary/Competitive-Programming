#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<vector<int>> adj(N + 1);
  vector<bool> is_end_page(N + 1);
  for(int i = 1; i <= N; i++) {
    int M_i;
    cin >> M_i;
    if(!M_i) {
      is_end_page[i] = true;
    }
    while(M_i--) {
      int M_i_j;
      cin >> M_i_j;
      adj[i].push_back(M_i_j);
    }
  }

  queue<int> q;
  vector<bool> vis(N + 1);
  vector<int> dist(N + 1);
  q.push(1), vis[1] = true;
  int vis_count = 0, shortest_path = 1e4 + 5;
  while(!q.empty()) {
    int curr = q.front(); 
    q.pop(), vis_count++;
    if(is_end_page[curr]) {
      shortest_path = min(shortest_path, dist[curr]);
    }
    for(int i = 0; i < adj[curr].size(); i++) {
      if(!vis[adj[curr][i]]) {
        q.push(adj[curr][i]), vis[adj[curr][i]] = true;
        dist[adj[curr][i]] = dist[curr] + 1;
      }
    }
  }
  cout << (vis_count == N ? 'Y' : 'N') << '\n' << shortest_path + 1 << '\n';

  return 0;
}