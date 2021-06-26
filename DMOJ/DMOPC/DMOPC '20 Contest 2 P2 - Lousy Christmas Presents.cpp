#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e6 + 1;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  vector<int> c(N);
  for(int i = 0; i < N; i++) {
    cin >> c[i];
  }
  vector<int> a(M), b(M);
  for(int i = 0; i < M; i++) {
    cin >> a[i] >> b[i];
  }

  vector<int> first_i(M1, -1), last_i(M1, -1);
  for(int i = 0; i < N; i++) {
    if(first_i[c[i]] == -1) {
      first_i[c[i]] = i;
    }
  }
  for(int i = N - 1; i >= 0; i--) {
    if(last_i[c[i]] == -1) {
      last_i[c[i]] = i;
    }
  }

  int L = 0;
  for(int i = 0; i < M; i++) {
    if(first_i[a[i]] != -1 && last_i[b[i]] != -1) {
      L = max(L, last_i[b[i]] - first_i[a[i]] + 1);
    }
  }

  cout << L << '\n';

  return 0;
}