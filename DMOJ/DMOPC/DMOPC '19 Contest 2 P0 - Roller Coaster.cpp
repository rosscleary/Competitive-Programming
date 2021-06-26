#include <bits/stdc++.h>
using namespace std;

int N, H_min, H_max;
int answer = 0;

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N >> H_min >> H_max;
  for(int i = 0; i < N; i++) {
    int h_i; cin >> h_i;
    answer += h_i >= H_min && h_i <= H_max;
  }

  cout << answer << '\n';

  return 0;
}