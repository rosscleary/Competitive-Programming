#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M, K;
  cin >> N >> M >> K;
  unordered_map<int, vector<pair<int, int>>> answers;
  unordered_map<int, int> prof;
  while(K--) {
    int A, B, C;
    cin >> A >> B >> C;
    answers[B].push_back({C, K}), prof[K] = A;
  }

  for(int i = 1; i <= N; i++) {
    sort(answers[i].begin(), answers[i].end());
    if(answers[i].size() == 0) {
      cout << -1;
    } else {
      cout << prof[answers[i][answers[i].size() - 1].second];
    }
    if(i != N) {
      cout << ' ';
    }
  }
  cout << '\n';

  return 0;
}