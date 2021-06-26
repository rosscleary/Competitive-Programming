#include <bits/stdc++.h>
using namespace std;

const string vowels("aeiou");
const string alph("abcdefghijklmnopqrstuvwxyz");
map<string, string> poem_structs{
  {"aaaa", "perfect"},
  {"aabb", "even"},
  {"abab", "cross"},
  {"abba", "shell"}
};

void solve_tc() {
  vector<string> ends(4);
  for(int i = 0; i < 4; i++) {
    string line;
    getline(cin, line);
    for(int i = 0; i < line.length(); i++) {
      if(line[i] != ' ') {
        line[i] = tolower(line[i]);
      }
    }
    int last_space = line.rfind(' ');
    string last_word = line.substr(last_space + 1, line.length() - last_space - 1);
    int last_vowel = 0;
    for(char i: vowels) {
      if(last_word.find(i) != -1) {
        last_vowel = max(last_vowel, int(last_word.rfind(i)));
      }
    }
    ends[i] = last_word.substr(last_vowel, last_word.length() - last_vowel);
  }

  // int alph_i = 0;
  // map<string, char> end_form;
  // string poem_struct;
  // for(int i = 0; i < 4; i++) {
  //   if(end_form.count(ends[i])) {
  //     poem_struct += end_form[ends[i]];
  //   } else {
  //     poem_struct += alph[alph_i];
  //     end_form[ends[i]] = alph[alph_i];
  //     alph_i++;
  //   }
  // }

  // if(poem_structs.count(poem_struct)) {
  //   cout << poem_structs[poem_struct] << '\n';
  // } else {
  //   cout << "free\n";
  // }

  if(ends[0] == ends[1] && ends[1] == ends[2] && ends[2] == ends[3]) {
    cout << "perfect\n";
  } else if(ends[0] == ends[1] && ends[2] == ends[3]) {
    cout << "even\n";
  } else if(ends[0] == ends[2] && ends[1] == ends[3]) {
    cout << "cross\n";
  } else if(ends[0] == ends[3] && ends[1] == ends[2]) {
    cout << "shell\n";
  } else {
    cout << "free\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  cin.ignore();
  while(N--) {
    solve_tc();
  }

  return 0;
}