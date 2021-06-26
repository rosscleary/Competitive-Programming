#include <bits/stdc++.h>
using namespace std;

const string alph_lower("abcdefghijklmnopqrstuvwxyz"), alph_upper("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

string S;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  getline(cin, S);

  int comma = S.find(",");
  string start("");
  if(comma + 2 != S.length()) start = S.substr(comma + 2, S.length() - comma - 3);
  string end("");
  if(S[0] != ',') end = S.substr(0, comma);
  if(start != "" && alph_lower.find(start[0]) != -1) start[0] = alph_upper[alph_lower.find(start[0])];
  if(start != "" && end != "" && alph_upper.find(end[0]) != -1) end[0] = alph_lower[alph_upper.find(end[0])];
  if(start != "" && end != "") start += " ";

  cout << start + end + S[S.length() - 1] << "\n";

  return 0;
}