#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  set<int> dist;
  for(int i = 0; i < N; i++) {
    int L_i;
    cin >> L_i;
    dist.insert(L_i);
  }

  cout << (dist.size() == N ? "YES" : "NO") << '\n';

  return 0;
}