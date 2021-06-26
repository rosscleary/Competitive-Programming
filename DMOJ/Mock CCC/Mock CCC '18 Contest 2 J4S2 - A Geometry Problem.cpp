#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  vector<int> rects;
  set<pair<int, int>> rect_list;
  for(int i = 0; i < 3; i++) {
    int l, w;
    cin >> l >> w;
    rects.push_back(l), rects.push_back(w);
    rect_list.insert({l, w}), rect_list.insert({w, l});
  } 

  sort(rects.begin(), rects.end());
  do {
    for(int i = 0; i < 5; i += 2) {
      if(!rect_list.count({rects[i], rects[i + 1]})) {
        continue;
      }
    }
    if(rects[0] == rects[3] + rects[4] && rects[2] == rects[5] && rects[0] == rects[1] + rects[2]) {
      cout << "YES\n";
      return 0;
    }
  } while(next_permutation(rects.begin(), rects.end()));

  cout << "NO\n";

  return 0;
}