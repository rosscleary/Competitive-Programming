#include <bits/stdc++.h>
using namespace std;

bool palindrome(string str) {
  for(int i = 0; i < str.size(); i++) {
    if(str[i] != str[str.size() - i - 1]) {
      return false;
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;

  int ans;
  for(int l = (M + N) / 2, r = (M + N) / 2 + ((M - N) & 1); l >= N; l--, r++) {
    if(palindrome(to_string(r))) {
      ans = r;
      break; 
    }
    if(palindrome(to_string(l))) {
      ans = l;
      break;
    }
  }

  cout << ans << '\n';

  return 0;
}