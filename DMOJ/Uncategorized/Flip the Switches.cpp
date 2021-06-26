#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<char> switches(N);
  for(int i = 0; i < N; i++) {
    cin >> switches[i];
  }

  int ans = 0;
  for(int i = N - 1; i >=0; i--) {
    int switch_state = switches[i] -'0';
    if(ans % 2 == 1) {
      switch_state = !switch_state;
    }
    if(switch_state == 1) {
      ans++;
    }
  }

  cout << ans << '\n';

  return 0;
}