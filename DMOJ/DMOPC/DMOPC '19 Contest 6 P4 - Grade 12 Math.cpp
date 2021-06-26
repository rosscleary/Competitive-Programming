#include <bits/stdc++.h>
using namespace std;

int N;
vector<unordered_map<int, int>> bit;

void increment(int i, int j) {
  for(; i <= N; i += i & -i) {
    bit[i][j]++;
  } 
}

void decrement(int i, int j) {
  for(; i <= N; i += i & -i) {
    bit[i][j]--;
    if(bit[i][j] == 0) {
      bit[i].erase(j);
    }
  } 
}

int query(int i, int j) {
  int ans = 0;
  for(; i > 0; i -= i & -i) {
    ans += bit[i][j];
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int Q;
  cin >> N >> Q;

  vector<int> a(N + 1); 
  bit.resize(N + 1);
  for(int i = 1; i <= N; i++) {
    increment(i, 0);
  }

  while(Q--) {
    int type;
    cin >> type;
    if(type == 1) {
      int x;
      cin >> x;
      decrement(x, a[x]), increment(x, ++a[x]);
    } else if(type == 2) {
      int x;
      cin >> x;
      decrement(x, a[x]), increment(x, --a[x]);
    } else {
      int l, r, c;
      cin >> l >> r >> c;
      int ans = query(r, c) - query(l - 1, c);
      cout << ans << '\n';
    }
  }

  return 0;
}