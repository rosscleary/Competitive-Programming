#include <bits/stdc++.h>
using namespace std;

string combination;

void rec(string remaining, string permutation) {
  if(remaining.length() == 0) {
    cout << permutation << "\n";
    return;
  } 

  for(int i = 0; i < remaining.length(); i++) {
    char add_letter = remaining[i];
    string next_remaining = remaining;
    next_remaining.erase(i, 1);
    rec(next_remaining, permutation + add_letter);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int test_case = 5;
  while(test_case--) {
    cin >> combination;
    rec(combination, "");
  }

  return 0;
}