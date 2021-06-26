#include <bits/stdc++.h>
using namespace std;

const int M1 = 41;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> heights(N);
  for(int i = 0; i < N; i++) {
    cin >> heights[i];
  }

  int ans = 0;
  for(int i = 0; i < N; i++) {
    ans += heights[i] <= M1 && (i == 0 || heights[i - 1] <= M1) && (i == N - 1 || heights[i + 1] <= M1);
  }

  cout << ans << '\n';

  return 0;
}