#include <bits/stdc++.h>
using namespace std;

void solve_tc() {
  int N;
  cin >> N;
  vector<vector<int>> adj(N + 1);
  for(int i = 1; i <= N; i++) {
    int box_key;
    cin >> box_key;
    adj[box_key].push_back(i);
    adj[i].push_back(box_key);
  }

  queue<int> q;
  vector<bool> seen(N + 1);
  int ans = 0;
  for(int i = 1; i <= N; i++) {
    if(!seen[i]) {
      q.push(i);
      seen[i] = true;
      while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int i = 0; i < adj[curr].size(); i++) {
          if(!seen[adj[curr][i]]) {
            q.push(adj[curr][i]);
            seen[adj[curr][i]] = true;
          }
        }
      }
      ans++;
    }
  }

  cout << ans << ' ';
}

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int tc = 2;
  while(tc--) {
    solve_tc();
  }
  cout << '\n';

  return 0;
}