#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  string alph, S;
  cin >> alph >> S;

  set<string> ans;
  for(int i = 0; i < S.size(); i++) {
    for(auto j: alph) {
      string new_S = S;
      new_S[i] = j;
      ans.insert(new_S);
    }
  }
  for(int i = 0; i < S.size(); i++) {
    string new_S = S;
    new_S.erase(i, 1);
    ans.insert(new_S);
  }
  for(int i = 0; i <= S.size(); i++) {
    for(auto j: alph) {
      string new_S = S;
      string j_add = "";
      j_add += j;
      new_S.insert(i, j_add);
      ans.insert(new_S);
    }
  }

  for(auto i: ans) {
    if(i != S) {
      cout << i << '\n';
    }
  }

  return 0;
}