#include <bits/stdc++.h>
using namespace std;
 
const string alph("abcdefghijklmnopqrstuvwxyz");
 
int t;
int n, a, b;
string s;
 
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
 
  cin >> t;
 
  while(t--) {
    cin >> n >> a >> b;
 
    s = "";
    int letter_counter = 0;
    while(true) {
      if(letter_counter >= n) break;
      for(int i = 0; i < b - 1; i++) {
        if(letter_counter >= n) break;
        s += alph[i];
        letter_counter++;
      }
      for(int i = 0; i < a - b + 1; i++) {
        if(letter_counter >= n) break;
        s += alph[b - 1];
        letter_counter++;
      }
    }
 
    cout << s << "\n";
  }
 
  return 0;
}