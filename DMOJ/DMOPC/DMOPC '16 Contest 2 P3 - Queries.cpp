#include <bits/stdc++.h>
using namespace std;

int T;
int N, M; vector<pair<int, int>> queries;

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> T;

  while(T--) {
    cin >> N >> M;
    queries.clear(); queries.resize(M);
    for(int i = 0; i < M; i++) cin >> queries[i].first >> queries[i].second;

    bool possible = false;
    for(int a_amount = 0; a_amount <= N; a_amount++) {
      bool valid_string = true;
      for(int i = 0; i < M; i++) {
        if(queries[i].first > a_amount || queries[i].second > N - a_amount) {
          valid_string = false;
          break;
        }
      }
      if(valid_string) {
        possible = true;
        for(int i = 0; i < a_amount; i++) cout << 'a';
        for(int i = 0; i < N - a_amount; i++) cout << 'b';
        cout << '\n';
        break;
      }
    }
    if(!possible) cout << "-1\n";
  }

  return 0;
}