#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<vector<int>> adj(1e3 + 1);
  for(int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  int X, Y;
  cin >> X >> Y;

  queue<int> q;
  vector<bool> vis(1e3 + 1);
  q.push(X);
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    for(auto i : adj[curr]) {
      if(!vis[i]) {
        q.push(i), vis[i] = true;
        if(i == Y) {
          cout << "Tangled\n";
          return 0;
        }
      }
    }
  }
  
  cout << "Not Tangled\n";

  return 0;
}