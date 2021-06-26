#include <bits/stdc++.h>
using namespace std;

const string vowels = "aeiou";

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, C, V;
  cin >> N >> C >> V;
  string word;
  cin >> word;

  string vowel_invalid = "", cons_invalid = "";
  for(auto i: word) {
    if(i == 'y') {
      vowel_invalid += 'a';
    } else {
      vowel_invalid += i;
    }
  }
  for(auto i: word) {
    if(i == 'y') {
      cons_invalid += 'b';
    } else {
      cons_invalid += i;
    }
  }

  int run = 0;
  for(auto i: vowel_invalid) {
    if(vowels.find(i) != -1) {
      run++;
    } else {
      run = 0;
    }
    if(run > V) {
      cout << "NO\n";
      return 0;
    }
  }
  run = 0;
  for(auto i: cons_invalid) {
    if(vowels.find(i) == -1) {
      run++;
    } else {
      run = 0;
    }
    if(run > C) {
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";

  return 0;
}