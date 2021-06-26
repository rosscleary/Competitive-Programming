#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e2 + 5;

int N; string sub_words[M1]; string replace_word;

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) cin >> sub_words[i];
  cin >> replace_word;

  int best_length = 0;
  for(int i = 0; i < N; i++) {
    if(sub_words[i].length() <= replace_word.length()) best_length = max(best_length, int(sub_words[i].length()));
  }
  for(int i = 0; i < N; i++) {
    if(sub_words[i].length() == best_length) {
      cout << sub_words[i] << '\n';
      return 0;
    }
  }

  return 0;
}