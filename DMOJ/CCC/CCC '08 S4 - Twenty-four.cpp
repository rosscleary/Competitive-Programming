#include <bits/stdc++.h>
using namespace std;

vector<int> cards(4);

vector<int> possible_values(int l, int r) {
  if(l == r) {
    return {cards[l]};
  }

  vector<int> ans;
  for(int i = l; i < r; i++) {
    vector<int> values_1 = possible_values(l, i), values_2 = possible_values(i + 1, r);
    for(auto j: values_1) {
      for(auto k: values_2) {
        ans.push_back(j + k);
        ans.push_back(j - k);
        ans.push_back(j * k);
        if(k != 0 && j % k == 0) {
          ans.push_back(j / k);
        }
      }
    }
  }

  return ans;
}

void solve_tc() {
  for(int i = 0; i < 4; i++) {
    cin >> cards[i];
  }

  int ans = -52;
  do {
    vector<int> all_values = possible_values(0, 3);
    for(auto i: all_values) {
      if(i <= 24) {
        ans = max(ans, i);
      }
    }
  } while(next_permutation(cards.begin(), cards.end()));

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  while(N--) {
    solve_tc();
  }

  return 0;
}