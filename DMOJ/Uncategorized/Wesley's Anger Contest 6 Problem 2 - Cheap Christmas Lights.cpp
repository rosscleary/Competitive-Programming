#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  vector<int> a(N + 1), b(M + 1);
  int odd_cnt = 0, even_cnt = 0;
  for(int i = 1; i <= N; i++) {
    cin >> a[i];
    odd_cnt += (a[i] % 2 == 1), even_cnt += (a[i] % 2 == 0);
  }
  for(int i = 1; i <= M; i++) {
    cin >> b[i];
  }
  if(odd_cnt == 0) {
    cout << "0\n";
    return 0;
  }
  for(int i = 1; i <= M + N; i++) {
    if(i <= M) {
      a[b[i]] = !a[b[i]];
      if(a[b[i]] % 2 == 0) {
        even_cnt++, odd_cnt--;
      } else {
        odd_cnt++, even_cnt--;
      }
    }
    if(odd_cnt <= i) {
      cout << i << '\n';
      return 0;
    }
  }

  return 0;
}