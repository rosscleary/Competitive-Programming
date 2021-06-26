#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int K;
  cin >> K;

  K++;
  vector<int> ans;
  int type = 1;
  for(int div = 2; div <= 1e5; div++) {
    while(K % div == 0) {
      for(int add = 0; add < div - 1; add++) {
        ans.push_back(type);
      }
      K /= div, type++;
    }
  }

  if(K != 1 || ans.size() > 1e5) {
    cout << "Sad Chris\n";
    return 0;
  }

  cout << ans.size() << '\n';
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if(i != ans.size() - 1) {
      cout << ' ';
    }
  }
  cout << '\n';

  return 0;
}