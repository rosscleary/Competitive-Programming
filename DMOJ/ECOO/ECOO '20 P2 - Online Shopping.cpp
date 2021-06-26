#include <bits/stdc++.h>
using namespace std;

int T;

map<string, vector<int>> item_prices;

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> T;

  while(T--) {
    item_prices.clear();
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
      int M; cin >> M;
      for(int j = 0; j < M; j++) {
        string S; int P, Q; cin >> S >> P >> Q;
        for(int k = 0; k < Q; k++) item_prices[S].push_back(P);
      }
    }

    int K, answer = 0;
    cin >> K;
    for(int i = 0; i < K; i++) {
      string S; int D; cin >> S >> D;
      sort(item_prices[S].begin(), item_prices[S].end());
      for(int j = 0; j < D; j++) answer += item_prices[S][j];
    }

    cout << answer << '\n';
  }

  return 0;
}