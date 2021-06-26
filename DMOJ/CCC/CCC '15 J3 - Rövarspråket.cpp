#include <bits/stdc++.h>
using namespace std;

const string vowels = "uoiea", alph = "abcdefghijklmnopqrstuvwxyz";

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  string str;
  cin >> str;

  string ans = "";
  for(char i: str) {
    if(vowels.find(i) != -1) {
      ans += i;
    } else {
      ans += i;
      int best_dist = 26;
      char best_char;
      for(char j: vowels) {
        if(abs(int(alph.find(i) - alph.find(j))) <= best_dist) {
          best_dist = abs(int(alph.find(i) - alph.find(j)));
          best_char = j;
        }
      }
      ans += best_char;
      if(i == 'z') {
        ans += i;
        continue;
      }
      for(int j = alph.find(i) + 1; j < 26; j++) {
        if(vowels.find(alph[j]) == -1) {
          ans += alph[j];
          break;
        }
      }
    }
  }

  cout << ans << '\n';

  return 0;
}