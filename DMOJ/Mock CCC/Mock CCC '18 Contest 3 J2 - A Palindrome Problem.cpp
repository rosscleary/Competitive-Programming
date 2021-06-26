#include <bits/stdc++.h>
using namespace std;

bool palindrome(string str) {
  string reverse = "";
  for(int i = str.length() - 1; i >= 0; i--) reverse += str[i];
  if(str == reverse) return true;
  return false;
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  
  string str;
  cin >> str;

  for(int length = 1; length < str.length(); length++) {
    string part_1 = str.substr(0, length), part_2 = str.substr(length, str.length() - length);
    if(palindrome(part_1) && palindrome(part_2)) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
 
  return 0;
}