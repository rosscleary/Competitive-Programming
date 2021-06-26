#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> times(N);
  for(int i = 0; i < N; i++) {
    int M_i, S_i;
    cin >> M_i >> S_i;
    times[i] = M_i * 60 + S_i;
  }

  int X, Y;
  cin >> X >> Y;
  int time_left = X * 60 + Y;
  sort(times.begin(), times.end());
  int ans = 0;
  for(int i = 0; i < N; i++) {
    if(times[i] > time_left) {
      break;
    }
    time_left -= times[i];
    ans++;
  }

  cout << ans << '\n';

  return 0;
}