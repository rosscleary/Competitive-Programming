#include <bits/stdc++.h>
using namespace std;
 
string N;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> N;
 
  if(N.find('7') != -1) cout << "Yes\n";
  else cout << "No\n";
 
  return 0;
}