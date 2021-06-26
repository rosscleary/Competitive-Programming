#include <bits/stdc++.h>
using namespace std;
 
string a;
 
bool valid_b(string b) {
  int open = 0;
  for(auto i: b) {
    open += i == '(', open -= i == ')';
    if(open < 0) {
      return false;
    }
  }
  return !open;
}
 
string create_b(int check) {
  string b;
  for(auto i: a) {
    if(i == 'A') {
      if(check & 4) {
        b += '(';
      } else {
        b += ')';
      }
    } else if(i == 'B') {
      if(check & 2) {
        b += '(';
      } else {
        b += ')';
      }
    } else {
      if(check & 1) {
        b += '(';
      } else {
        b += ')';
      }
    }
  }
 
  return b;
}
 
void solve_tc() {
  cin >> a;
  for(int check = 0; check < 8; check++) {
    string b = create_b(check);
    if(valid_b(b)) {
      cout << "YES\n";
      return;
    }
  }
 
  cout << "NO\n";
}
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) {
    solve_tc();
  }
 
  return 0;
}