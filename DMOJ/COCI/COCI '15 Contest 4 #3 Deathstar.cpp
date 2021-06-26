#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> a(N);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      int m_i_j;
      cin >> m_i_j;
      if(i != j) {
        a[i] |= m_i_j, a[j] |= m_i_j;
      }
    }
  }

  for(auto i: a) {
    cout << i << ' ';
  }
  cout << '\n';

  return 0;
}