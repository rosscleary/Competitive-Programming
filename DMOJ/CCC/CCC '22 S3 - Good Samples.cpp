#include <bits/stdc++.h>
using namespace std;

#define int long long

int first_amount(int amount) {
  return (amount * (amount + 1)) / 2;
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M, K;
  cin >> N >> M >> K;

  if(K < N) {
    cout << "-1\n";
    return 0;
  }

  int last_range = 0;
  int last = 0;
  vector<int> ans;
  while(N) {
    if(last + N - 1 > K) {
      ans.push_back(last - (K - N));
      for(int i = 0; i < N - 1; i++) {
        ans.push_back(last - (K - N));
      }
      K = 0;
      break;
    } else if(last + 1 > M || max(last_range, last + 1) + N - 1 > K) {
      ans.push_back(1);
      K -= last;
      N--;
      last_range = last;
      last = 1;
    } else {
      last++;
      ans.push_back(last);
      K -= max(last_range, last);
      N--;
    }
  }

  if(K != 0) {
    cout << "-1\n";
    return 0;
  }

  for(auto i: ans) {
    cout << i << ' ';
  }
  cout << '\n';
  
  return 0;
}