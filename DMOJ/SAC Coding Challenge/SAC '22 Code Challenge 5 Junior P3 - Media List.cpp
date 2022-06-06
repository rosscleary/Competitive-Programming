#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> has_word[400001];

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, Q;
  cin >> N >> Q;

  while(Q--) {
    int type;
    cin >> type;
    int media;
    cin >> media;
    string word;
    cin >> word;
    if(type == 1) {
      cout << has_word[media][word] << '\n';
    } else {
      has_word[media][word] = true;
    }
  }

  return 0;
}