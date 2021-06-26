#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;

int N, Q;
int row_states[maxN + 1], col_states[maxN + 1];
map<pair<int, int>, int> cell_count;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> Q;

  while(Q--) {
    int type, i, j; cin >> type >> i >> j;
    if(type == 1) {
      row_states[i]++;
      col_states[j]++;
      cell_count[make_pair(i, j)]++;
    } else {
      if((row_states[i] + col_states[j] - cell_count[make_pair(i, j)]) % 2 == 0) cout << "0\n";
      else cout << "1\n";
    }
  }

  return 0;
}