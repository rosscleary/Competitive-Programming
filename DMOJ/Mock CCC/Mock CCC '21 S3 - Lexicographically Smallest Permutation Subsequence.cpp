#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, K;
  cin >> N >> K;
  vector<int> seq(N), lasts(K + 1);
  vector<vector<int>> value_i(K + 1);
  for(int i = 0; i < N; i++) {
    cin >> seq[i];
    lasts[seq[i]] = i;
    value_i[seq[i]].push_back(i);
  }

  vector<bool> taken(K + 1);
  int i = 0, j = 0;
  set<pair<int, int>> choices;
  choices.insert({seq[0], 0});
  for(int choice = 1; choice <= K; choice++) {
    while(i < N - 1) {
      if(!taken[seq[i]] && lasts[seq[i]] == i) {
        break;
      }
      i++;
      if(!taken[seq[i]]) {
        choices.insert({seq[i], i});
      }
    }
    auto take = choices.begin();
    taken[take->first] = true;
    cout << take->first;
    if(choice != K) {
      cout << ' ';
    }
    for(; j <= take->second; j++) {
      if(choices.count({seq[j], j})) {
        choices.erase(choices.find({seq[j], j}));
      }
    }
    for(auto k: value_i[take->first]) {
      if(choices.count({take->first, k})) {
        choices.erase(choices.find({take->first, k}));
      }
    }
  }
  cout << '\n';

  return 0;
}