#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M1 = 1e9 + 9, M2 = 107;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  string A, B;
  cin >> A >> B;

  int hash_A = 0, hash_B = 0;
  int pow = 1;
  pair<int, int> ans = {-1, -1};
  for(int i = A.length() - 1, j = 0; i >= 0 && j < B.length(); i--, j++) {
    hash_A *= M2, hash_A += A[i] - 'a' + 1, hash_A %= M1;
    hash_B += ((B[j] - 'a' + 1) * pow) % M1, hash_B %= M1;
    pow *= M2, pow %= M1;
    if(hash_A == hash_B) {
      ans = {i, j};
    }
  }

  string ans_str;
  if(ans.first == -1) {
    ans_str = A + B;
  } else {
    ans_str = A + B;
    ans_str.erase(ans.first, ans.second + 1);
  }
  cout << ans_str << '\n';

  return 0;
}