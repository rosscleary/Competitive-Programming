#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, K;
  cin >> N >> K;
  vector<pair<int, int>> M_V(N);
  for(int i = 0; i < N; i++) cin >> M_V[i].second >> M_V[i].first;
  multiset<int> C;
  for(int i = 0; i < K; i++) {
    int C_i;
    cin >> C_i;
    C.insert(C_i);
  }

  sort(M_V.begin(), M_V.end());
  ll answer = 0;
  for(int i = N - 1; i >= 0 && !C.empty(); i--) {
    if(C.lower_bound(M_V[i].second) != C.end()) {
      answer += M_V[i].first;
      C.erase(C.lower_bound(M_V[i].second));
    }
  }
  cout << answer << '\n';

  return 0;
}