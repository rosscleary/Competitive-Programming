#include <bits/stdc++.h>
using namespace std;

void solve_tc() {
  int N, C;
  long long T;
  cin >> N >> C >> T;
  vector<int> G(N);
  for(int i = 0; i < N; i++) {
    cin >> G[i];
  }

  int start_value = G[0];
  sort(G.begin(), G.end());
  int start_channel;
  for(int i = 0; i < N; i++) {
    if(G[i] == start_value) {
      start_channel = i;
      break;
    }
  }

  int channel = start_channel;
  long long min_time = 0;
  while(true) {
    min_time += T;
    int next_channel = channel + 1;
    for(; next_channel < N; next_channel++) {
      if(G[next_channel] - G[channel] > C) {
        break;
      }
    }
    next_channel--;
    if(G[channel] == G[next_channel]) {
      break;
    }
    channel = next_channel;
  }

  cout << G[channel] << ' ' << min_time - T << '\n';
}

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int D;
  cin >> D;

  while(D--) {
    solve_tc();
  }

  return 0;
}