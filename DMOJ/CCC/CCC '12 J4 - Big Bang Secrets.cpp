#include <bits/stdc++.h>
using namespace std;

const string alph("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

int K; string str;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> K >> str;

  for(int i = 0; i < str.length(); i++) {
    int curr = alph.find(str[i]);
    int change = (3 * (i + 1)) + K;
    if(curr - change >= 0) str[i] = alph[curr - change];
    else str[i] = alph[26 - (change - curr)];
  }

  cout << str << "\n";

  return 0;
}