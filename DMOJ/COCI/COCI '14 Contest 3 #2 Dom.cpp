#include <bits/stdc++.h>
using namespace std;

const int M1 = -1e9;

vector<int> adj;
vector<bool> visited;

int solve(int channel) {
  if(adj[channel] == 0) return 0;
  if(visited[channel]) return M1;
  visited[channel] = true;
  return 1 + solve(adj[channel]);
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  
  int N, M, P;
  cin >> N >> M >> P;
  adj.resize(M + 1);
  for(int i = 0; i < N; i++) {
    int a_i, b_i;
    cin >> a_i >> b_i;
    if(adj[b_i] == 0) adj[b_i] = a_i;
  }

  visited.resize(M + 1);
  int answer = solve(P);
  cout << ((answer < 0) ? -1 : answer) << '\n';
 
  return 0;
}