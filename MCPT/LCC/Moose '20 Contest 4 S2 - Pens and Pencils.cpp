#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);

  int N, P, Q;
  cin >> N >> P >> Q;
  
  vector<int> ans;
  int i;
  for(i = 1; i <= N && P; i += 2, P--, Q--) {
    ans.push_back(i);
  }

  for(i--; i <= N && Q; i++, Q--) {
    ans.push_back(i);
  }

  if(P != 0 || Q != 0) {
    cout << "Impossible\n";
    return 0;
  }
  for(auto i: ans) {
    cout << i << ' ' << i << '\n';
  }
	
  return 0;
}