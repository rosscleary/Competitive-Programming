#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, W, D;
  cin >> N >> W >> D;
  vector<vector<int>> adj(N + 1);
  while(W--) {
    int A_i, B_i;
    cin >> A_i >> B_i;
    adj[B_i].push_back(A_i);
  }

  queue<int> q;
  vector<int> dist(N + 1, 1e9);
  dist[N] = 0, q.push(N);
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    for(auto i: adj[curr]) {
      if(dist[i] == 1e9) {
        dist[i] = dist[curr] + 1, q.push(i);
      }
    }
  }

  vector<int> S(N + 1);
  multiset<int> options;
  for(int i = 1; i <= N; i++) {
    cin >> S[i];
    options.insert(i - 1 + dist[S[i]]);
  }

  while(D--) {
    int X_i, Y_i;
    cin >> X_i >> Y_i;
    options.erase(options.find(X_i - 1 + dist[S[X_i]])), options.erase(options.find(Y_i - 1 + dist[S[Y_i]]));
    swap(S[X_i], S[Y_i]);
    options.insert(X_i - 1 + dist[S[X_i]]), options.insert(Y_i - 1 + dist[S[Y_i]]);
    cout << *options.begin() << '\n';
  }

  return 0;
}