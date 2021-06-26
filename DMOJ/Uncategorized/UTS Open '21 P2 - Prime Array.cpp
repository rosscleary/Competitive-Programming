#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int K;
  cin >> K;

  if(K == 0) {
    cout << 1 << '\n' << 2 << '\n';
    return 0;
  }

 int prime_cnt = 0;
  vector<int> ans;
  for(int i = 1; prime_cnt < K; i++) {
    prime_cnt += i, ans.push_back(1);
  }

  int add = prime_cnt - K;
  int i = 0;
  while(add > 0) {
    for(int add_len = 100; add_len >= 1; add_len--) {
      int remove = add_len * (add_len + 1) / 2;
      if(remove <= add) {
        add -= remove;
        for(int cnt = 0; cnt < add_len; cnt++, i++) {
          ans[i] = 2;
        }
        i++;
      }
    }
  }

  cout << ans.size() << '\n';
  for(auto i: ans) {
    cout << i << ' ';
  }
  cout << '\n';

  return 0;
}